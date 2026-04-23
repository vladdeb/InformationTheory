#include "NumberTheory.h"
#include <QFile>
#include <stdexcept>
#include <QByteArray>
#include <QDataStream>
#include "elgamal.h"


#define CHUNK_SIZE 1024

std::vector<std::pair<std::uint64_t, std::uint64_t>> elgamal::encrypt(
    QString srcPath,
    QString destPath,
    std::uint64_t p,
    std::uint64_t g,
    std::uint64_t k,
    std::uint64_t x,
    std::uint64_t returnLen
    ) {
    auto y = bpow(g, x, p);
    std::vector<std::pair<std::uint64_t, std::uint64_t>> result = {};
    QFile in(srcPath);
    if(!in.open(QFile::ReadOnly)) {
        throw std::runtime_error("Can't open input file");
    }
    QFile out(destPath);

    if(!out.open(QFile::WriteOnly)) {
        in.close();
        throw std::runtime_error("Can't open output file");
    }

    QByteArray chunk(CHUNK_SIZE, 0);
    QDataStream ds(&out);
    while(!in.atEnd()) {
        chunk = in.read(CHUNK_SIZE);
        for(unsigned char m: chunk) {
            auto a = bpow(g, k, p);
            auto b = (bpow(y, k, p) * m) % p;
            if(result.size() < returnLen) {
                result.push_back({a, b});
            }
            ds << static_cast<std::uint32_t>(a) << static_cast<std::uint32_t>(b);
            k = randomCoprime(p - 1);
        }
    }
    in.close();
    out.close();
    return result;
}

std::vector<std::pair<std::uint64_t, std::uint64_t>> elgamal::decrypt(
    QString srcPath,
    QString destPath,
    std::uint64_t p,
    std::uint64_t g,
    std::uint64_t k,
    std::uint64_t x,
    std::uint64_t returnLen
    ) {
    std::vector<std::pair<std::uint64_t, std::uint64_t>> result = {};
    QFile in(srcPath);
    if(!in.open(QFile::ReadOnly)) {
        throw std::runtime_error("Can't open input file");
    }
    QFile out(destPath);

    if(!out.open(QFile::WriteOnly)) {
        in.close();
        throw std::runtime_error("Can't open output file");
    }


    QDataStream dsIn(&in);
    QDataStream dsOut(&out);
    while(!in.atEnd()) {
        std::uint32_t a32, b32;
        dsIn >> a32 >> b32;
        std::uint64_t a = static_cast<std::uint64_t>(a32);
        std::uint64_t b = static_cast<std::uint64_t>(b32);
        auto m = (bpow(a, p - 1 - x, p) * b) % p;
        if(result.size() < returnLen) {
            result.push_back({a, b});
        }
        if(m > 255) {
            in.close();
            out.close();
            throw std::runtime_error("Decryption error: m > 255. Check your inputs");
        }
        dsOut << static_cast<unsigned char>(m);
    }
    in.close();
    out.close();
    return result;
}
