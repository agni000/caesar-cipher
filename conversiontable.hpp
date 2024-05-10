#ifndef CONVERSIONTAB_HPP
#define CONVERSIONTAB_HPP

#include <iostream>
#include <vector>

using namespace std;

class ConversionTable {
//attributes
private:
    vector <pair <char, char> > m_chars;

//methods
public:
    //constructor and destructor
    ConversionTable(): m_chars(256) {
        for (size_t i = 0; i < m_chars.size(); i++) {
            m_chars.at(i).first = i;
            m_chars.at(i).second = i + 2;
        }
    };
    ~ConversionTable() {};

    //getters and setters
    SetPair(char c1, char c2, int index);
    char GetSecond(int index);
    char GetFirst(int index);
    PrintPairs();

};

#endif
