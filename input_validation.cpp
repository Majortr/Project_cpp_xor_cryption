#include "input_validation.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string toLowerCase(string text) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }

    return text;
}

string getMode(){
    string mode;

    while(true){

        cout << "Enter mode (encrypt/decrypt or e/d): ";
        getline(cin, mode);

        mode = toLowerCase(mode);

        if(mode == "encrypt" || mode == "e"){
            return "encrypt";

        }else if(mode == "decrypt" || mode == "d"){
            return "decrypt";

        }else{
            cout << "Invalid mode. Please enter encrypt/decrypt or e/d." << endl;
        }
    }
}

string getInputFilename(){
    string inputFilename;

    while(true){

        cout << "Enter input filename (example: notes.txt): " << endl;
        getline(cin, inputFilename);

        if(inputFilename.empty()) {
            cout << "Filename cannot be empty. Please try again." << endl;
            continue;
        }

        size_t dotPosition = inputFilename.find_last_of('.');

        if(dotPosition == string::npos) {
            cout << "Invalid filename. Please include file extension, example: notes.txt." << endl;
            continue;
        }

        if(dotPosition == 0) {
            cout << "Invalid filename. Filename must have a name before the extension." << endl;
            continue;
        }

        if(dotPosition == inputFilename.length() - 1) {
            cout << "Invalid filename. Please include file extension after the dot." << endl;
            continue;
        }

        return inputFilename;
    }
}

int getKey(){
    string input;
    int key;

    while(true){

        cout << "Enter XOR key (0-255): ";
        getline(cin, input);

        stringstream ss(input);

        if(ss >> key && ss.eof()){
            if(key >= 0 && key <= 255){
                return key;
            }

            cout << "Invalid key. Key must be between 0 and 255." << endl;

        } else {

            cout << "Invalid input. Key must be an integer." << endl;

        }

    }
}

string generateOutputFilename(const string& inputFilename, const string& mode){

    size_t dotPosition = inputFilename.find_last_of('.');

    string name = inputFilename.substr(0, dotPosition);
    string extension = inputFilename.substr(dotPosition);

    string encryptedSuffix = "_encrypted";

    if (mode == "encrypt") {
    return name + "_encrypted" + extension;
    }
    else if (mode == "decrypt") {

        if (name.length() >= encryptedSuffix.length()) {
            string ending = name.substr(name.length() - encryptedSuffix.length());

            if (ending == encryptedSuffix) {
                name = name.substr(0, name.length() - encryptedSuffix.length());
            }
        }

        return name + "_decrypted" + extension;

    }

    return "";
}