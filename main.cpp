#include "cipher.hpp"
#include <string>
#include <limits>
#include <fstream>

//functions
int menu();
bool loadFile(string &filename, string &input);

int main() {

    int option = 0, key = 0;
    string input, output, filename;
    Cipher table;

    do {
        option = menu();

        switch(option) {
            case 1:
                cout << "Enter the key value: ";
                cin >> key;
                table.CreateTable(key);
                cout << "New table created!" << endl;
                break;
            case 2:
                cout << "Enter your text: ";
                getline(cin, input);
                table.SetInput(input);
                table.Encrypt();
                output = table.GetOutput();

                cout << endl << "Encrypted text: " << output << endl << endl;
                break;

            case 3:
                cout << "Enter the file name: ";
                cin >> filename;
                loadFile(filename, input);
                table.SetInput(input);
                table.Encrypt();
                output = table.GetOutput();
                cout << endl << "File text: " << input << endl << endl;
                cout << endl << "Encrypted file text: " << output << endl << endl;
                break;

            case 4:
                cout << "Enter your text: ";
                getline(cin, input);
                table.SetInput(input);
                table.Decrypt();
                output = table.GetOutput();

                cout << endl << "Decrypted text: " << output << endl << endl;
                break;

            case 5:
                cout << "Enter the file name: ";
                cin >> filename;
                loadFile(filename, input);
                table.SetInput(input);
                table.Decrypt();
                output = table.GetOutput();

                cout << endl << "File text: " << input << endl << endl;
                cout << endl << "Decrypted file text: " << output << endl << endl;
                break;

            case 6:
                table.PrintTable();
                break;

            case 7:
                break;

            default:
                cout <<"Error! Try again." << endl;
                break;
        }

    } while (option != 7);


    return 0;
}

int menu() {

    int option = 0;

    cout << "------------------------------" << endl;
    cout << "1. Create Table." << endl;
    cout << "2. Encrypt text." << endl;
    cout << "3. Encrypt file." << endl;
    cout << "4. Decrypt text." << endl;
    cout << "5. Decrypt file." << endl;
    cout << "6. Print table." << endl;
    cout << "7. Quit." << endl;
    cout << "------------------------------" << endl;
    cout << "?: ";
    cin >> option;
    getchar();

    while (option != 1 && option != 2 && option != 3 && option != 4 && option!= 5 && option!= 6 && option!= 7) {
        cout << "Error! Try again, my friend." << endl << "?: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> option;
        getchar();
    }

    return option;
}

bool loadFile(string &filename, string &input) {

    input.clear();

    ifstream fileInput(filename);
    string tmp;

    if (!fileInput.is_open()) {
        cout << "File not loaded! Try again." << endl;
        return false;
    }

    while (getline(fileInput, tmp)) {
        input += tmp;
    }

    fileInput.close();

    return true;
}


