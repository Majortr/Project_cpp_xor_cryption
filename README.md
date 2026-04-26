# Project 5: Text-Based File Encryption/Decryption Tool

## Project Description

This project is a C++ text-based file encryption/decryption tool developed in Visual Studio Code.

The program uses the **Bitwise XOR Cipher** algorithm to encrypt or decrypt the contents of a text file. It reads the file character by character, applies XOR using a numeric key, and writes the result into a new file.

Because XOR is reversible, the same key can be used to decrypt the encrypted file and recover the original content.

---

## Features

- User selects **encrypt** or **decrypt** mode
- User enters an **input filename**
- User enters a **numeric XOR key**
- Program validates all user inputs
- File is processed **character by character**
- Output is written to a **new file**
- Encryption/decryption is fully reversible with the same key
- Error handling for file opening, reading, and writing

---

## Technologies Used

- **Language:** C++
- **IDE/Editor:** Visual Studio Code
- **Compiler:** g++ / clang++ / MSVC (`cl`)
- **Version Control:** Git & GitHub

---

## Project Structure

- `main.cpp`  
  Main program flow and integration of all modules

- `input_validation.h`  
  Function declarations for user input and validation

- `input_validation.cpp`  
  User input collection and validation logic

- `file_processor.h`  
  File processing result enum and processing function declaration

- `file_processor.cpp`  
  File reading/writing and XOR processing workflow

- `xor_engine.h`  
  XOR function declaration

- `xor_engine.cpp`  
  XOR function implementation

---

## How the Program Works

The program follows this flow:

1. Ask the user for the mode (`encrypt` or `decrypt`)
2. Ask the user for the input filename
3. Ask the user for the XOR key
4. Generate the output filename automatically
5. Open the input file
6. Read the file character by character
7. Apply XOR using the given key
8. Write the processed content to the output file
9. Print success or error messages

---

## Input Validation

The program validates:

### Mode
Accepted inputs:
- `encrypt`
- `decrypt`
- `e`
- `d`

### Filename
Rules:
- cannot be empty
- must include a valid file extension
- must have a name before the dot
- must have an extension after the dot

### XOR Key
Rules:
- must be an integer
- must be between `0` and `255`

---

## Output Filename Logic

The program automatically creates a new output filename.

Examples:

- `notes.txt` + encrypt → `notes_encrypted.txt`
- `notes_encrypted.txt` + decrypt → `notes_decrypted.txt`

This prevents overwriting the original file.

---

## XOR Logic

The project uses the **Bitwise XOR Cipher**.

### Encryption:
original byte XOR key = encrypted byte

### Decryption:
encrypted byte XOR key = original byte

This makes XOR suitable for both encryption and decryption using the same key.

---

## File Processing Details

- Files are processed **character by character**
- XOR is applied to every character
- Input and output files are handled carefully to preserve reversibility
- Appropriate result codes are returned for:
  - input file open error
  - output file open error
  - read error
  - write error

---

## How to Compile and Run

### g++ (MacOS)
```bash
g++ main.cpp input_validation.cpp file_processor.cpp xor_engine.cpp -o project_cpp_cryption
./project_cpp_cryption

### cl (Windows)
```bash
cl /EHsc main.cpp file_processor.cpp xor_engine.cpp input_validation.cpp /Fe:project_cpp_cryption.exe
.\project_cpp_cryption.exe