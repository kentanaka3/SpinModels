#include "ising.hpp"

Ising::Ising(uint64_t n, uint64_t w): N(n), S(n, false), S0(n, false), W(w),
  Pt(n, true), EPOCHS(n * n) {
  std::cout << "Number of Particles: " << N << std::endl;
  std::cout << "Number of Epochs: " << EPOCHS << std::endl;
  std::cout << "Number of Neighbors: " << W << std::endl;
  #pragma omp parallel for
  for (uint64_t i = 0; i < N / 2; i++) {
    uint64_t x = (uint64_t)(unf_dist(gen) * (double)N);
    S[x] = true;
    S0[x] = true;
  }
}

void Ising::run(void) {
  uint64_t epoch = 0;
  measure(epoch);
  print(epoch);
  double T = 1.0;
  do {
    for (uint64_t i = 0; i < N; i++) {
      uint64_t x = (uint64_t)(unf_dist(gen) * (double)N);
      int64_t H = 0;
      // TODO: Remove if statement
      #pragma omp parallel for reduction(+:H)
      for (uint64_t j = 1; j <= W; j++) H += S[(x + j) % N] ? 1 : -1;
      #pragma omp parallel for reduction(+:H)
      for (uint64_t j = 0; j < W; j++) H += S[(x - W + j + N) % N] ? 1 : -1;
      if (H * S[x] < 0 || (H == 0 && unf_dist(gen) > 0.5)) {
        S[x] = !(S[x]);
        Pt[x] = false;
      }
    }
    if (epoch == (uint64_t)pow(BASE, T)) {
      measure(epoch);
      print(epoch);
      // Update next measure point
      while ((uint64_t)pow(BASE, T) == (uint64_t)pow(BASE, T + 1.0)) T += 1.0;
      T += 1.0;
      if ((int)pow(BASE, T) > EPOCHS) epoch = EPOCHS;
    }
    epoch++;
  } while (epoch < EPOCHS);
}

void Ising::print(uint64_t epoch) {
  std::cout << "Epoch " << std::setfill('0') << std::setw(10) << epoch << ": ";
  for (uint64_t i = 0; i < N; i++) std::cout << S[i] << " ";
  std::cout << std::endl;
}

void Ising::measure(uint64_t epoch) {
  int64_t m = 0;
  #pragma omp parallel for reduction(+:m)
  for (uint64_t i = 0; i < N; i++) m += S[i];
  uint64_t dw = 0;
  #pragma omp parallel for reduction(+:dw)
  for (uint64_t i = 0; i < N - 1; i++) dw += S[i] != S[i + 1];
  dw += S[N - 1] != S[0];
  double ac = 0.0;
  // #pragma omp parallel for reduction(+:ac)
  // for (uint64_t i = 0; i < N; i++) ac += S0[i] != S[i];
  uint64_t p = 0;
  #pragma omp parallel for reduction(+:p)
  for (uint64_t i = 0; i < N; i++) p += Pt[i];
  Magnetization[epoch] += m - N;
  DomainWalls[epoch] += dw;
  // AutoCorrelation[epoch] += ac / (double)N;
  Persistance[epoch] += p;
}