#include "lsfr.h"

LSFR::LSFR(std::string initialState, std::vector<bool> p) : _n(p.size()) {
    _state = 0;
    _mask = 0;

    for(int i = 0; i < _n; ++i) {
        if(initialState[i] == '1') {
            _state |= (1U << (_n - i - 1));
        }
    }

    for(int i = 0; i < _n; ++i) {
        if(p[i]) {
            _mask |= (1U << i);
        }
    }
}

bool LSFR::GetNextBit() {
    bool result = (_state >> (_n - 1)) & 1;
    bool newBit = 0;
    for(int i = 0; i < _n; ++i) {
        if((_mask >> i) & 1) {
            newBit ^= (_state >> i) & 1;
        }
    }
    _state <<= 1;
    _state |= newBit;
    return result;
}

void LSFR::EncryptByte(char& src) {
    uint8_t resByte = 0;
    for(int i = 0; i < 8; ++i) {
        if (GetNextBit()) {
            resByte |= (1U << (7 - i));
        }
    }
    src ^= resByte;
}
