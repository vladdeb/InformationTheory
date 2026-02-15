#include "vigenere.h"

static std::wstring alphabet = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

std::wstring vigenereEncrypt(std::wstring source, std::wstring key) {
    std::wstring newkey = key + source;
    std::wstring res = L"";
    for(int i = 0; i < source.size(); ++i) {
        int p1 = alphabet.find(source[i]);
        int p2 = alphabet.find(newkey[i]);
        res += alphabet[(p1 + p2) % alphabet.size()];
    }
    return res;
}
std::wstring vigenereDecrypt(std::wstring source, std::wstring key) {
    std::wstring res = L"";
    for(int i = 0; i < source.size(); ++i) {
        int p1 = alphabet.find(source[i]);
        int p2;
        if(i >= key.size()) {
            p2 = alphabet.find(res[i - key.size()]);
        }
        else {
            p2 = alphabet.find(key[i]);
        }
        res += alphabet[(p1 + alphabet.size() - p2) % alphabet.size()];
    }
    return res;
}
