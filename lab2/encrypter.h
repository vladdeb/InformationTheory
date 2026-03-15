#ifndef ENCRYPTER_H
#define ENCRYPTER_H
#include <QFile>
#include "lsfr.h"
#include "buffer.h"

class Encrypter
{
private:
    QFile& _src;
    QFile& _dest;
public:
    LSFR _lsfr;
    Encrypter(QFile& src, QFile& dest, std::string initialState, std::vector<bool> p);
    void Encrypt(std::string& result, int preview);
};

#endif // ENCRYPTER_H
