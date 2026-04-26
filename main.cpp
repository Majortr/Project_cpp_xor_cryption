#include "file_processor.h"
#include <iostream>

int main() {
    std::string inputFile = "text_file/simple.txt";
    std::string encryptedFile = "text_file/encrypted.txt";
    std::string decryptedFile = "text_file/decrypted.txt";
    uint8_t key = 3;

    FileProcessResult encryptResult = processFile(inputFile, encryptedFile, key);

    if (encryptResult != FileProcessResult::Success) {
        std::cout << "Encryption test failed\n";
        return 1;
    }

    std::cout << "Encryption test passed\n";

    FileProcessResult decryptResult = processFile(encryptedFile, decryptedFile, key);

    if (decryptResult != FileProcessResult::Success) {
        std::cout << "Decryption test failed\n";
        return 1;
    }

    std::cout << "Decryption test passed\n";
    return 0;
}