#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <omp.h>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

const int MAX_RECURSION = 988;

#include <random>
#include <string>

#include <string>
#include <random>
#include <limits>

class Distribution {
protected:
  std::mt19937_64 rng;
private:
  uint64_t seed;
public:
  std::string name;
  double mean, median, mode, variance, skewness, kurtosis, entropy;
  Distribution(std::string name, uint64_t seed) : name(name), seed(seed),
                                                  rng(seed) {rng.seed(seed);}
  virtual ~Distribution() = default;
  virtual double PMF(double x) const = 0;
  virtual double CDF(double x) const = 0;
  virtual double eval(std::mt19937_64 rng);
};

class Degenerate : public Distribution {
public:
  double a;
  Degenerate(std::string name, uint64_t seed, double a)
    : Distribution(name, seed), a(a) {
    // Initialize statistical properties
    mean = a;
    median = a;
    mode = a;
    variance = 0.0;
    skewness = std::numeric_limits<double>::quiet_NaN(); // Undefined
    kurtosis = std::numeric_limits<double>::quiet_NaN(); // Undefined
    entropy = 0.0;
  }
  double PMF(double x) const override {return (x == a) ? 1.0 : 0.0;}
  double CDF(double x) const override {return (x >= a) ? 1.0 : 0.0;}
  double operator()() override {return a;}
};

class Uniform : public Distribution {
public:
  double a, b;
  Uniform(std::string name, uint64_t seed, const double& a, const double& b)
    : Distribution(name, seed), a(a), b(b) {}
  double eval(std::mt19937_64 rng) {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
  }
};

const double PI=3.14159264;
std::vector<double> Normal2D(const double& mu, const double& sigma,
                             const std::vector<double>& u) {
  double r = sqrt(-2. * log(u[0]));
  std::vector<double> z(u.size(), sigma * r);
  z[0] = z[0] * cos(2. * PI * u[1]) + mu;
  z[1] = z[1] * sin(2. * PI * u[1]) + mu;
  return z;
}
std::vector<double> Normal2D(std::mt19937_64& rng, const double& mu,
                             const double& sigma) {
  std::vector<double> u(2, Uniform(rng));
  return Normal2D(mu, sigma, u);
}
std::vector<double> Normal2D(std::mt19937_64& rng) {
  return Normal2D(rng, 0., 1.);
}
bool Bernoulli(std::mt19937& rng, const double& p) {return Uniform(rng) < p;}
bool Bernoulli(std::mt19937& rng) {return Bernoulli(rng, 0.5);}
double Binomial(std::mt19937& rng, const int& n, const double& p) {
  int X = 0; // Number of successes
  for (int i = 0; i < n; ++i) X += Bernoulli(rng, p);
  return (double)X / n; // Return the fraction of successes
}
double Binomial(std::mt19937& rng, const int& n) {
  return Binomial(rng, n, 0.5);
}
int Rad(std::mt19937& rng) {return Bernoulli(rng) * 2 - 1;}

class Universe;

class RandWalker {
private:
  std::mt19937 rng;  // Individual RNG for thread safety

public:
  int id, value;
  bool persist;
  std::set<int> neighbors;
  Universe* universe;
  unsigned int seed;
  RandWalker(int id, int value, std::set<int> neighbors, Universe* universe)
      : id(id), value(value), neighbors(neighbors), universe(universe),
        persist(true), seed(rand()) {rng.seed(seed);}
  void live();
};

class IsingSpin {
private:
  std::mt19937 rng;  // Individual RNG for thread safety

public:
  int id, value;
  bool persist;
  std::set<int> neighbors;
  Universe* universe;
  unsigned int seed;
  IsingSpin(int id, int value, std::set<int> neighbors, Universe* universe)
      : id(id), value(value), neighbors(neighbors), universe(universe),
        persist(true), seed(rand()) {rng.seed(seed);}
  int h();
  int p() {return persist ? 1 : 0;}
  void live();
};

class Universe {
public:
  std::string name;
  std::vector<IsingSpin> particles;
  std::vector<int> particles0;
  std::vector<int> dims;
  std::vector<std::vector<int>> XYZVT;
  int verbose;
  double temperature;
  Universe(std::string name, double temperature, const std::vector<int>& dims,
           const std::vector<std::set<int>>& adjacency_list)
      : name(name), temperature(temperature), dims(dims) {
    for (int i = 0; i < adjacency_list.size(); ++i) {
      // Initialize spins with ±1
      particles.emplace_back(i, (rand() % 2) * 2 - 1, adjacency_list[i], this);
    }
    particles0.reserve(particles.size());
    for (const auto& p : particles) particles0.emplace_back(p.value);
  }
  const double BOLTZMANN=1.;
  double BoltzmannFactor(const double& Delta) {
    return (temperature > 0.) ? exp(Delta / (BOLTZMANN * temperature)) : (double)(Delta <= 0);
  }
  double WalkerFactor() {return 0.5;}
  IsingSpin& getParticle(int idx) {return particles[idx];}
  int Observables(int T, int const& verbose) {
    int H = 0, M = 0, AC = 0, P = 0;
    for (size_t i = 0; i < particles.size(); ++i) {
      auto& p = particles[i];
      H -= p.value * p.h();
      M += p.value;
      if (p.value == particles0[i]) AC++;
      P += p.p();
    }
    M = abs(M);
    if (verbose) {
      std::cout << "T:";
      printf("%05i", T);
      std::cout << "|";
      std::vector<int> p_dims(dims.size());
      if (verbose > 1) for (const auto& p : particles) {
        if (p_dims[0] % dims[0] == 0) std::cout << std::endl;
        p_dims[0]++;
        if (p_dims.size() >= 2 && p_dims[1] % dims[1] == 0) {
          p_dims[1]++;
        }
        printf("%c[%dm", 0x1B, (p.value > 0) ? 32 : 33);
        printf("%+2i", p.value);
        std::cout << "\033[00m";
      }
      std::cout << "|H:" << H << ", M:" << M << ", AC:" << AC << ", P:" << P;
      std::cout << std::endl;
    }
    return H == -2 * dims.size() * particles.size() || M == particles.size();
  }

  bool life(int T, const int& verbose) {
    if (T <= 0) return false;
    std::vector<int> order(particles.size());
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), std::default_random_engine(rand()));
    #pragma omp parallel for
    for (size_t i = 0; i < order.size(); ++i) particles[order[i]].live();
    return life(T - 1, verbose);
  }

  void run(const int& T, const std::vector<int>& measure, const int& verbose) {
    int S = 0;
    while (S < T) {
      life(measure[0], verbose);
      if (Observables(S, verbose)) {
        std::cout << "All spins aligned at step " << S << std::endl;
        break;
      }
      S += measure[0];
    }
  }
};

int IsingSpin::h() {
  int sum = 0;
  for (int n : neighbors) sum += universe->getParticle(n).value;
  return sum;
}

void IsingSpin::live() {
  // (2 * value) = (s_{mu} - s_{nu}) = 2 * Rad_i()
  // h() = Rad_j() + Rad_k()
  // 2 * (Rad_i()*Rad_j() + Rad()_i*Rad_k()), k != i != j != k, Rad() => State
  // 2 * (Rad_u() + Rad_v()), Rad_u() = AND(i, j),        Rad() => Interaction
  //                          Rad_v() = AND(i, k),
  // \Delta = SUM_i^n(Rad_i)
  int delta_E = 2 * value * h();


  // If temperature is 0, Glauber algorithm is equivalent to Metropolis algorithm
  // Glauber algorithm -> Softargmax (Boltzmann distribution)
  // try:
  // if (Bernoulli(rng, universe->WalkerFactor())) {
  if (Bernoulli(rng, universe->BoltzmannFactor(delta_E))) {
    persist = false;
    value = -value;
  }
}

void RandWalker::live() {value += Rad(rng);}

std::vector<std::set<int>> PBC3D(const int& M, const int& N, const int& L) {
  std::vector<std::set<int>> adjacency_list(M * N * L);
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < L; ++k) {
        int idx = i * N * L + j * L + k;
        int lt = ((i - 1 + M) % M) * N * L + j * L + k; // left
        if (lt != idx) adjacency_list[idx].insert(lt); // left
        int rt = ((i + 1) % M) * N * L + j * L + k; // right
        if (rt != idx) adjacency_list[idx].insert(rt); // right
        int tp = i * N * L + ((j - 1 + N) % N) * L + k; // top
        if (tp != idx) adjacency_list[idx].insert(tp); // top
        int bm = i * N * L + ((j + 1) % N) * L + k;     // bottom
        if (bm != idx) adjacency_list[idx].insert(bm); // bottom
        int ft = i * N * L + j * L + ((k - 1 + L) % L); // front
        if (ft != idx) adjacency_list[idx].insert(ft); // front
        int bk = i * N * L + j * L + ((k + 1) % L);     // back
        if (bk != idx) adjacency_list[idx].insert(bk); // back
      }
    }
  }
  return adjacency_list;
}
std::vector<std::set<int>> PBC3D(const int& M) {return PBC3D(M, M, M);}
std::vector<std::set<int>> PBC2D(const int& M, const int& N) {
  return PBC3D(M, N, 1);
}
std::vector<std::set<int>> PBC2D(const int& M) {return PBC2D(M, M);}
std::vector<std::set<int>> PBC1D(const int& N) {return PBC2D(N, 1);}
std::vector<std::set<int>> PBC(std::vector<int> dims) {
  if (dims.size() == 1) return PBC1D(dims[0]);
  else if (dims.size() == 2) return PBC2D(dims[0], dims[1]);
  else if (dims.size() == 3) return PBC3D(dims[0], dims[1], dims[2]);
  else {
    std::cerr << "Error: Invalid dimensions for PBC" << std::endl;
    return {};
  }
}

std::vector<std::set<int>> FCN(const int& N) {
  std::vector<std::set<int>> adjacency_list(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) if (i != j) adjacency_list[i].insert(j);
  }
  return adjacency_list;
}
std::vector<std::set<int>> FCN(const std::vector<int>& dims) {
  int N = 1;
  for (const auto& d : dims) N *= d;
  return FCN(N);;
}

int main() {
  int N = .4 * 10e3;
  omp_set_num_threads(omp_get_max_threads());
  srand(time(0));
  // try:
  // std::vector<int> dims = {N, N, N};
  std::vector<int> dims = {N};
  // try:
  auto adjacency_list = PBC(dims); // Periodic Boundary Conditions
  // auto adjacency_list = FCN(dims); // Fully Connected Network
  // try:
  // Universe myUniverse("Ising Model - Ring", 0., dims, adjacency_list); // Zero temperature
  Universe myUniverse("Ising Model - Ring", 1., dims, adjacency_list); // Non-sero temperature
  std::vector<int> M = {100}; // Measurements, working on becoming a lambda function generator function. Linear, quadratic, polinomial, exponential, or logarithmic measurements are some of the few I will be implementing as examples.
  myUniverse.run(N * N, M, 3);
  return 0;
}