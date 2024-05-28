#ifndef UTILS_HPP
#define UTILS_HPP
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

std::vector<uint64_t> Magnetization;
std::vector<uint64_t> DomainWalls;
std::vector<double> AutoCorrelation;
std::vector<uint64_t> Persistance;

void setUp(const uint64_t& MSR) {
  std::cout << "Setting up" << std::endl;
  uint64_t msr = log((double)MSR + 1.0) / log(BASE);
  Magnetization = std::vector<uint64_t>(msr, 0);
  DomainWalls = std::vector<uint64_t>(msr, 0);
  AutoCorrelation = std::vector<double>(msr, 0.0);
  Persistance = std::vector<uint64_t>(msr, 0);
}

#endif