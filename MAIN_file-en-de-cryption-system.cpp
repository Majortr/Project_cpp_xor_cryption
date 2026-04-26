#include "input_validation.h"
#include "file_processor.h"
#include <iostream>
#include <cstdint>

int main() {
    std::string mode = getMode();
    std::string inputFilename = getInputFilename();
    int key = getKey();

    std::string outputFilename = generateOutputFilename(inputFilename, mode);

    FileProcessResult result = processFile(
        inputFilename,
        outputFilename,
        static_cast<uint8_t>(key)
    );

    if (result == FileProcessResult::Success) {
        std::cout << "Process completed successfully.\n";
        std::cout << "Mode: " << mode << "\n";
        std::cout << "Input file: " << inputFilename << "\n";
        std::cout << "Output file: " << outputFilename << "\n";
    }
    else if (result == FileProcessResult::InputFileOpenError) {
        std::cout << "Error: Input file could not be opened.\n";
    }
    else if (result == FileProcessResult::OutputFileOpenError) {
        std::cout << "Error: Output file could not be created or opened.\n";
    }
    else if (result == FileProcessResult::WriteError) {
        std::cout << "Error: Failed while writing to the output file.\n";
    }
    else if (result == FileProcessResult::ReadError) {
        std::cout << "Error: Failed while reading the input file.\n";
    }
    else {
        std::cout << "Error: Unknown file processing error.\n";
    }

    return 0;
}
