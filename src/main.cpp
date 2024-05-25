#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <omp.h>
#include <cmath>

std::random_device rndm;
std::mt19937_64 gen(rndm());
std::uniform_real_distribution<> unf_dist(0., 1.);

double BASE = 1.1;

class Ising {
private:
  uint64_t N;
  u_int64_t EPOCHS;
  std::vector<bool> S;
  std::vector<bool> P;
  std::vector<bool> AC;
  uint64_t W;
  int64_t M;
  uint64_t DW;
  uint64_t p;
  uint64_t ac;
public:
  Ising(uint64_t n, uint64_t w);
  ~Ising() {};
  void run(void);
  void print(uint64_t epoch);
  void measure(void);
};

Ising::Ising(uint64_t n, uint64_t w): N(n), S(n, false), P(n, true),
  AC(n, false), EPOCHS(n * n), W(w), M(0), DW(0), ac(0), p(0) {
  std::cout << "Number of Particles: " << N << std::endl;
  std::cout << "Number of Epochs: " << EPOCHS << std::endl;
  std::cout << "Number of Neighbors: " << W << std::endl;
  #pragma omp parallel for
  for (uint64_t i = 0; i < N; i++) S[i] = unf_dist(gen) > 0.5;
  #pragma omp parallel for
  for (uint64_t i = 0; i < N; i++) AC[i] = S[i];
}

void Ising::run(void) {
  uint64_t epoch = 0;
  measure();
  print(epoch);
  double T = 1.0;
  do {
    for (uint64_t i = 0; i < N; i++) {
      uint64_t x = unf_dist(gen) * (double)N;
      int64_t H = 0;
      // TODO: Remove if statement
      #pragma omp parallel for reduction(+:H)
      for (uint64_t j = 1; j < W; j++) H += S[(x + j) % N] ? 1 : -1;
      #pragma omp parallel for reduction(+:H)
      for (uint64_t j = 1; j < W; j++) H += S[(x - W + j + N) % N] ? 1 : -1;
      if (H*S[x] < 0 || (H == 0 && unf_dist(gen) > 0.5)) {
        S[x] = !(S[x]);
        P[x] = false;
      }
    }
    if (epoch == (int)pow(BASE, T)) {
      measure();
      print(epoch);
      // Update next measure point
      while ((int)pow(BASE, T) == (int)pow(BASE, T + 1)) T += 1.0;
      T += 1.0;
      if ((int)pow(BASE, T) > EPOCHS) epoch = EPOCHS;
    }
    epoch++;
  } while (epoch < EPOCHS);
}

void Ising::print(uint64_t epoch) {
  std::cout << "Epoch " << std::setfill('0') << std::setw(10) << epoch << ": ";
  for (uint64_t i = 0; i < N; i++) std::cout << S[i] << " ";
  std::cout << "; M = " << (double)M / (double)N \
            << ", DW = " << (double)DW / (double)N \
            << ", AC = " << (double)ac / (double)N \
            << ", P = " << (double)p / (double)N <<  std::endl;
}

void Ising::measure(void) {
  M = 0;
  DW = 0;
  ac = 0;
  p = 0;
  #pragma omp parallel for reduction(+:M)
  for (uint64_t i = 0; i < N; i++) M += S[i] ? 1 : -1;
  #pragma omp parallel for reduction(+:DW)
  for (uint64_t i = 0; i < N; i++) DW += S[i] != S[i + 1];
  #pragma omp parallel for reduction(+:ac)
  for (uint64_t i = 0; i < N; i++) ac += AC[i] != S[i];
  #pragma omp parallel for reduction(+:p)
  for (uint64_t i = 0; i < N; i++) p += P[i];
}

int main(void) {
  uint64_t N = 1 << 5;
  uint64_t W = 1 << 0;
  Ising ising(N, W);
  ising.run();
  return 0;
}