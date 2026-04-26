#include "file_processor.h"
#include "xor_engine.h"
#include <fstream>

/// Processes the input file by applying XOR encryption/decryption and writes the result to the output file
FileProcessResult processFile(const std::string& inputPath, const std::string& outputPath, uint8_t key) {
    std::ifstream inputFile(inputPath);
    // Check if the input file was opened successfully
    if (!inputFile) {
        return FileProcessResult::InputFileOpenError;
    }

    std::ofstream outputFile(outputPath);
    // Check if the output file was opened successfully
    if (!outputFile) {
        return FileProcessResult::OutputFileOpenError;
    }

    std::ifstream writeFile(outputPath);
    if (!writeFile) {
        return FileProcessResult::WriteError;
    }

    char currentChar;
    // Loop through each character in the input file
    while(inputFile.get(currentChar)) {
        uint8_t byteChar = static_cast<uint8_t>(currentChar); // Convert the character to uint8_t for XOR processing
        
        uint8_t processedChar = applyXOR(byteChar, key); // Apply XOR encryption/decryption using the provided key


        outputFile.put(static_cast<char>(processedChar)); // Write the processed character to the output file
    }

    if (!inputFile) {
        return FileProcessResult::ReadError; // Return read error if the input file cannot be read
    }

    return FileProcessResult::Success; // Return success if the file processing is completed without errors
}