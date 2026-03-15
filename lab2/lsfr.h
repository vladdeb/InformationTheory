#ifndef LSFR_H
#define LSFR_H
#include <string>
#include <vector>
#include <cstdint>

class LSFR
{
private:
    uint32_t _state;
    uint32_t _mask;
    int _n;
public:
    LSFR(std::string, std::vector<bool>);
    bool GetNextBit();
    void EncryptByte(char& src);
};

#endif // LSFR_H
