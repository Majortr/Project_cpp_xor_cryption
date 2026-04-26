#include "file_processor.h"
#include <iostream>

int key = 3;

int main() {

    std::string input = "test_files/simple.txt";
    std::string output = "test_files/encrypted.txt";
    FileProcessResult result = processFile(
    input,
    output,
    key
);

    

if (result == FileProcessResult::InputFileOpenError) {
    std::cout << "Missing input file test passed\n";
}
else {
    std::cout << "Missing input file test failed\n";
}

if (result == FileProcessResult::OutputFileOpenError) {
    std::cout << "Missing output folder test passed\n";
}
else {
    std::cout << "Missing output folder test failed\n";
}

if (result == FileProcessResult::Success) {
    std::cout << "Key 0 test process succeeded\n";
}
else {
    std::cout << "Key 0 test process failed\n";
}

}