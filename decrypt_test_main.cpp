#include "file_processor.h"
#include <iostream>

int main() {
    processFile(
        "text_file/encrypted.txt",
        "text_file/decrypted.txt",
        3
    );
    return 0;
}