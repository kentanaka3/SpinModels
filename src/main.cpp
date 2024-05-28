#include "ising.hpp"

int main(void) {
  uint64_t N = 1 << 5;
  uint64_t W = 1 << 0;
  u_int64_t R = 1 << 2;
  setUp(N * N);
  for (uint64_t i = 0; i < R; i++) {
    std::cout << "Run " << i << std::endl;
    Ising ising(N, W);
    ising.run();
  }
  std::cout << "Simulation Complete" << std::endl;
  return 0;
}