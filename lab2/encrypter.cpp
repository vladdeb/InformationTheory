#include "encrypter.h"
#include <sstream>

Encrypter::Encrypter(QFile& src, QFile& dest, std::string initialState, std::vector<bool> p)
    : _src(src)
    , _dest(dest)
    , _lsfr(LSFR(initialState, p)){

}

void Encrypter::Encrypt(std::string& result, int preview) {
    result = "";
    //extern char buf[CHUNK_SIZE + 1];
    int retval;
    std::stringstream ss1, ss2;
    while((retval = _src.read(buf, CHUNK_SIZE)) > 0) {
        for(int i = 0; i < retval; ++i) {
            _lsfr.EncryptByte(buf[i]);
        }
        if(result == "") {
            ss2.write(buf, std::min(retval, preview));
            result = ss2.str();
        }
        _dest.write(buf, retval);
    }
}
