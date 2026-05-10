#ifndef SOLVE_H
#define SOLVE_H

#include <cstdint>
#include <QTextStream>
#include <QString>

std::int64_t H(const std::int64_t& H0, const std::int64_t& n, QTextStream& ds, bool ignoreSign);
std::int64_t getSign(QTextStream& ts);

#endif // SOLVE_H
