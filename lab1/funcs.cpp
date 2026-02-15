#include "funcs.h"

static std::wstring alphabetCap = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
static std::wstring alphabet = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";


std::wstring prepareText(std::wstring s) {
    for(int i = 0; i < s.size(); ++i) {
        int p;
        if((p = alphabet.find(s[i])) != -1) {
            s[i] = alphabetCap[p];
        }
    }
    return s;
}

std::wstring prepareKey(std::wstring s) {
    std::wstring k = L"";
    for(int i = 0; i < s.size(); ++i) {
        int p;
        if((p = alphabet.find(s[i])) != std::wstring::npos) {
            s[i] = alphabetCap[p];
        }
        if(alphabetCap.find(s[i]) != std::wstring::npos) {
            k += s[i];
        }
    }
    return k;
}
