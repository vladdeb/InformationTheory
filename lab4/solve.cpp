#include "solve.h"
#include <QByteArray>
#include <QDebug>

std::int64_t H(const std::int64_t& H0, const std::int64_t& n, QTextStream& ds, bool ignoreLast) {
    QString line;
    std::int64_t res = H0;
    ds.seek(0);
    while(!ds.atEnd()) {
        line = ds.readLine();
        qDebug() << line << Qt::endl;
        if(ignoreLast && ds.atEnd()) break;
        const QByteArray bytes = line.toLatin1();
        for(unsigned char byte: bytes) {
            qDebug() << byte << ' ';
            res = (res + byte) % n;
            res = (res * res) % n;
        }
        qDebug() << Qt::endl;
    }
    qDebug() << line << Qt::endl;
    return res;
}

std::int64_t getSign(QTextStream& ts) {
    QString signStr;
    while(!ts.atEnd()) {
        signStr = ts.readLine();
    }
    bool ok;
    std::int64_t sign = signStr.toLongLong(&ok);
    if (!ok) {
        throw std::runtime_error("Sign is must be number");
    }
    return sign;
}
