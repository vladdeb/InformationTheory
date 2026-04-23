#ifndef ELGAMAL_H
#define ELGAMAL_H
#include <vector>
#include <cstdint>
#include <QString>
namespace elgamal {
    std::vector<std::pair<std::uint64_t, std::uint64_t>> encrypt(
        QString srcPath,
        QString destPath,
        std::uint64_t p,
        std::uint64_t g,
        std::uint64_t k,
        std::uint64_t x,
        std::uint64_t returnLen
        );

    std::vector<std::pair<std::uint64_t, std::uint64_t>> decrypt(
        QString srcPath,
        QString destPath,
        std::uint64_t p,
        std::uint64_t g,
        std::uint64_t k,
        std::uint64_t x,
        std::uint64_t returnLen
        );
}

#endif // ELGAMAL_H
