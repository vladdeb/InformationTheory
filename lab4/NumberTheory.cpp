#include "NumberTheory.h"
#include <random>
#include <cmath>
#include <numeric>

std::uint64_t bpow(std::uint64_t a, std::uint64_t x, std::uint64_t mod) {
    if(x == 0) return 1;
    if(x & 1) return (a * bpow(a, x - 1, mod)) % mod;
    std::uint64_t y = bpow(a, x / 2, mod);
    return (y * y) % mod;
}

bool isPrime(std::uint64_t p) {
    if(p % 2 == 0) {
        return p == 2;
    }
    int d = 3;
    while(d * d <= p && p % d != 0) {
        d += 2;
    }
    return (p > 1) && (d * d > p);
}

std::uint64_t inverse(std::uint64_t d, std::uint64_t mod) {
    std::int64_t a = mod, b = d % mod;
    std::int64_t x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    while(b > 0) {
        std::int64_t r = a % b, q = a / b;
        std::int64_t x2 = x0 - q * x1;
        std::int64_t y2 = y0 - q * y1;
        x0 = x1, x1 = x2, y0 = y1, y1 = y2, a = b, b = r;
    }
    return y0 % mod;
}
