#include <iostream>
#include "input_validation.h"

using namespace std;

int main() {
    cout << "Testing Branch 1: Input Validation" << endl;
    cout << "----------------------------------" << endl;

    string mode = getMode();
    string inputFilename = getInputFilename();
    int key = getKey();
    string outputFilename = generateOutputFilename(inputFilename, mode);

    cout << endl;
    cout << "Test Result" << endl;
    cout << "-----------" << endl;
    cout << "Mode: " << mode << endl;
    cout << "Input filename: " << inputFilename << endl;
    cout << "Key: " << key << endl;
    cout << "Output filename: " << outputFilename << endl;

    return 0;
}