#include "utils.hpp"

class Ising {
private:
  uint64_t N;
  uint64_t MSR;
  u_int64_t EPOCHS;
  std::vector<bool> S;
  std::vector<bool> S0;
  std::vector<bool> Pt;
  uint64_t W;
public:
  Ising(uint64_t n, uint64_t w);
  ~Ising() {};
  void run(void);
  void print(uint64_t epoch);
  void measure(uint64_t epoch);
};
