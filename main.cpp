// File: CS112_A2_T1_s1,s2_20230768
// Purpose: encryption and decryption using the XOR logical gate.
// Author: abdulrahman khaled alrashi / section 1,2.
// Emails: alarashiabdulrahman@gmail.com
// IDs: 20230768

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void Encryption(){
    string msg, key, enc_msg ;
    int key_index = 0 ;
    stringstream res ;
    cout << "enter the message: " ;
    getline(cin , msg) ; // Reads a line of input from the standard input (keyboard) and stores it in the "msg" variable.
    cout << "enter the key: " ;
    getline(cin , key) ;// Reads a line of input from the standard input and stores it in the "key" variable.

    for (int i = 0; i < msg.length(); i++) {// Loops through each character of the input message.

        int x = msg[i] ^ key[key_index] ; // Computes the bitwise XOR operation between the current character of the message and the corresponding character of the key.
        res << hex << setfill('0') << setw(2) << (int) x ; // Formats the result of the XOR operation as a two-digit hexadecimal number and appends it to the stringstream "res".
        key_index += 1 ;

        if (key_index >= key.length()) { // Checks if the key index has reached the end of the key string.
            key_index =0 ;
        }
    }
    res >> enc_msg ; //Reads the formatted hexadecimal representation of the encrypted text from the stringstream "res" and stores it in the "enc_msg" variable.
    cout << "the encryption is: " << enc_msg ;


}

void Decryption(){
    string msg, key, dec_msg, hextouni ;
    int key_index = 0 ;

    cout << "enter the message: " ;
    getline(cin, msg) ; // Reads a line of input from the standard input (keyboard) and stores it in the "msg" variable.
    cout << "enter the key: " ;
    getline(cin, key) ; // Reads a line of input from the standard input and stores it in the "key" variable.

    for (int i = 0; i < msg.length()-1 ; i+=2) { // Loops through each pair of characters in the hexadecimal message.
        string x = msg.substr(i,2) ; // Extracts a pair of characters from the hexadecimal message.
        int decimal = strtol(x.c_str(),NULL,16) ; // Converts the pair of characters from hexadecimal to decimal using strtol function.

        hextouni += (char) decimal ; // Appends the Unicode character corresponding to the decimal value to the "hextouni" string.
    }

    for (int i = 0; i < hextouni.length(); i++) { // Loops through each character of the Unicode representation of the hexadecimal message.
        int y = hextouni[i] ^ key[key_index] ; // Computes the bitwise XOR operation between the current character of the Unicode message and the corresponding character of the key.
        dec_msg += (char) y ; // Appends the decrypted character to the "dec_msg" string.
        key_index++ ;
        if(key_index>=key.length()) { // Checks if the key index has reached the end of the key string.
            key_index = 0 ;
        }
    }

    cout << "the decryption is: " << dec_msg ;


}

int main()
{
    while (true) {

        cout << "1. Encryption\n2. Decryption\n3. Exit\nChoose(1,2,3): "; // Presents a menu to the user with options for encryption and decryption.
        int choice;
        cin >> choice;
        cin.ignore();

        // See what the user want to do.
        if (choice == 1) {
            cout << endl << "---Encryption---" << endl;
            Encryption();
        } else if (choice == 2) {
            cout << endl << "---Decryption---" << endl;
            Decryption();
        }else if (choice == 3) {
            cout << "thank you for using my programme." ;
            break ;
        }else {
            cout << endl << "Wrong choice please try again " << endl;
            continue ;
        }

        return 0;
    }
}