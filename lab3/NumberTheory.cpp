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

std::uint64_t randomCoprime(std::uint64_t n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, n - 1);
    for(;;){
        std::uint64_t x = distr(gen);
        if(std::gcd(x, n) == 1) return x;
    }
}


std::vector<std::pair<std::uint64_t, std::uint64_t>> factorize(std::uint64_t n) {
    std::vector<std::pair<std::uint64_t, std::uint64_t>> result(0);
    std::uint64_t d = 2;
    while(d * d <= n) {
        if(n % d == 0) {
            n /= d;
            result.push_back({d, 1});
            while(n % d == 0) {
                result.back().second++;
                n /= d;
            }
        }
        d++;
    }
    if(n > 1) result.push_back({n, 1});
    return result;
}

std::set<std::uint64_t> getPrimaryRoots(std::uint64_t p) {
    std::set<std::uint64_t> result = {};
    auto fact = factorize(p - 1);
    std::vector<std::uint64_t> powers = {};
    for(auto [d, _]: fact) {
        powers.push_back((p - 1) / d);
    }
    int g;
    for(g = 2; g < p; ++g) {
        bool f = 1;
        for(auto power: powers) {
            if(bpow(g, power, p) == 1) {
                f = 0;
                break;
            }
        }
        if(f) {
            for(int a = 1; a < p - 1; ++a) {
                if(std::gcd(a, p - 1) == 1) result.insert(bpow(g, a, p));
            }
            break;
        }
    }
    return result;
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
