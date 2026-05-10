#ifndef NUMBERTHEORY_H
#define NUMBERTHEORY_H
#include <cstdint>
#include <vector>
#include <set>
#include <string>

std::uint64_t bpow(std::uint64_t a, std::uint64_t x, std::uint64_t mod);
bool isPrime(std::uint64_t p);
std::uint64_t inverse(std::uint64_t d, std::uint64_t mod);

#endif // NUMBERTHEORY_H
