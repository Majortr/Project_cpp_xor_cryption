#include "file_processor.h"
#include <iostream>

int main() {
    processFile(
        "test_files/encrypted.txt",
        "test_files/decrypted.txt",
        7
    );
    return 0;
}