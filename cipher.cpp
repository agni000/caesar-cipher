#include "cipher.hpp"

void Cipher::CreateTable(int key) {
    char first, second;

    for (size_t i = 0; i < 256; i++) {

        first = i;
        second = i + key;

        m_table -> SetPair(first, second, i);
    }
}

void Cipher::PrintTable() {
    m_table -> PrintPairs();
}

void Cipher::SetInput(string str) {
    m_input = str;
}

void Cipher::Encrypt() {
    char tmp, c2;
    m_output.clear();

    for (size_t i = 0; i < m_input.size(); i++) {
        tmp = m_input.at(i);
        c2 = m_table -> GetSecond(tmp);
        m_output += c2;
    }
}

void Cipher::Decrypt() {
    char tmp;
    m_output.clear();

    for (size_t i = 0; i < m_input.size(); i++) {
        tmp = m_input.at(i);

        for(size_t j = 0; j < 256; j++) {
            if(tmp == m_table -> GetSecond(j)) {
                m_output += m_table -> GetFirst(j);
                break;
            }
        }
    }
}
