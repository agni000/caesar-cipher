#include "conversiontable.hpp"

ConversionTable::SetPair(char c1, char c2, int index) {
    m_chars[index] = make_pair(c1, c2);
}

char ConversionTable::GetFirst(int index) {
    return m_chars.at(index).first;
}

char ConversionTable::GetSecond(int index) {
    return m_chars.at(index).second;
}

ConversionTable::PrintPairs() {
    for (int i = 0; i < 256; i++) {
        cout << m_chars.at(i).first << " -> " << m_chars.at(i).second << endl;
    }
}
