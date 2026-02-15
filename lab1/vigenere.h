#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

std::wstring vigenereEncrypt(std::wstring source, std::wstring key);
std::wstring vigenereDecrypt(std::wstring source, std::wstring key);

#endif // VIGENERE_H
