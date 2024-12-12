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

    void CreateTable(int key);
    void PrintTable();
    void SetInput(string str);
    void string GetOutput() {return m_output;}
    void Encrypt();
    void Decrypt();
};
