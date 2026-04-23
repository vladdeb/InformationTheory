#ifndef NUMBERTHEORY_H
#define NUMBERTHEORY_H
#include <cstdint>
#include <vector>
#include <set>
#include <string>

std::uint64_t bpow(std::uint64_t a, std::uint64_t x, std::uint64_t mod); // a^x mod mod
std::uint64_t randomCoprime(std::uint64_t n);
std::vector<std::pair<std::uint64_t, std::uint64_t>> factorize(std::uint64_t n);
std::set<std::uint64_t> getPrimaryRoots(std::uint64_t p);
bool isPrime(std::uint64_t p);

#endif // NUMBERTHEORY_H
