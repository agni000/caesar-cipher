#include "conversiontable.hpp"

class Cipher {
//attributes
private:
    ConversionTable *m_table;
    string m_input;
    string m_output;

//methods
public:
    Cipher() {
        m_table = new ConversionTable();
    }
    ~Cipher(){
        delete m_table;
    };

    CreateTable(int key);
    PrintTable();
    SetInput(string str);
    string GetOutput() {return m_output;}
    Encrypt();
    Decrypt();
};
