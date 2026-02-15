#include "ColumnCipher.h"
#include <vector>

static std::wstring alphabet = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

std::wstring ColumnCipher(std::wstring source, std::wstring key) {
    int cols = key.size();
    int rows = (source.size() + cols - 1) / cols;
    std::vector<int> pos(cols);
    int cur = 0;
    for(int i = 0; i < alphabet.size(); ++i) {
        for(int j = 0; j < cols; ++j) {
            if(key[j] == alphabet[i]) {
                pos[cur++] = j;
            }
        }
    }
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(cols, '\0'));
    std::wstring res = L"";
    cur = 0;
    for(int i = 0; i < rows && cur < source.size(); ++i) {
        for(int j = 0; j < cols && cur < source.size(); ++j) {
            table[i][j] = source[cur++];
        }
    }
    for(int i = 0; i < cols; ++i) {
        for(int j = 0; j < rows; ++j) {
            if(table[j][pos[i]] != '\0') {
                res += table[j][pos[i]];
            }
        }
    }
    return res;
}

std::wstring ColumnDecipher(std::wstring source, std::wstring key) {
    int cols = key.size();
    int rows = (source.size() + cols - 1) / cols;
    std::vector<int> pos(cols);
    int cur = 0;
    for(int i = 0; i < alphabet.size(); ++i) {
        for(int j = 0; j < cols; ++j) {
            if(key[j] == alphabet[i]) {
                pos[cur++] = j;
            }
        }
    }
    int rem = (source.size() + cols - 1) % cols + 1;
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(cols, '\0'));
    std::wstring res = L"";
    cur = 0;
    for(int i = 0; i < cols; ++i) {
        int r = rows;
        if(pos[i] >= rem) {
            r--;
        }
        for(int j = 0; j < r; ++j) {
            table[j][pos[i]] = source[cur++];
        }
    }
    cur = 0;
    for(int i = 0; i < rows && cur < source.size(); ++i) {
        for(int j = 0; j < cols && cur < source.size(); ++j) {
            res += table[i][j];
            cur++;
        }
    }
    return res;
}
