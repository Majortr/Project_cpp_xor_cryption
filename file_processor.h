#pragma once

#include <string>
#include <cstdint>

enum class FileProcessResult {
    Success,
    InputFileOpenError,
    OutputFileOpenError,
    WriteError,
    ReadError
};

FileProcessResult processFile (const std::string& inputPath, const std::string& outputPath, uint8_t key);