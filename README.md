# Branch 1: Input Validation

This branch is responsible for the user input and validation layer of the XOR-based text file encryption/decryption project.

## Purpose

The goal of this branch is to handle all user-side inputs before the file processing stage begins. It collects the required values, validates them, and prepares the output filename for the next stage of the program.

## Scope of Branch 1

This branch includes the following responsibilities:

- Getting the operation mode from the user
- Getting the input filename from the user
- Getting the XOR key from the user
- Validating all user inputs
- Generating the output filename based on the selected mode

This branch does **not** perform file reading, file writing, or XOR processing. Those tasks belong to the second branch.

## Implemented Functions

### `getMode()`
This function asks the user to enter the mode of operation.

Accepted inputs:
- `encrypt`
- `decrypt`
- `e`
- `d`

Behavior:
- Converts the input to lowercase
- Re-prompts the user until a valid mode is entered
- Returns either `"encrypt"` or `"decrypt"`

---

### `getInputFilename()`
This function asks the user for the input filename.

Validation rules:
- The filename cannot be empty
- The filename must include a dot (`.`)
- There must be a valid name before the dot
- There must be a valid extension after the dot

Accepted example:
- `notes.txt`

Rejected examples:
- ``
- `.txt`
- `notes`
- `notes.`

---

### `getKey()`
This function asks the user to enter the XOR key.

Validation rules:
- The input must be an integer
- The value must be between `0` and `255`

Accepted examples:
- `0`
- `25`
- `255`

Rejected examples:
- `-1`
- `256`
- `abc`
- `12.5`

---

### `generateOutputFilename(const std::string& inputFilename, const std::string& mode)`
This function creates the output filename based on the selected mode.

Behavior:
- If mode is `encrypt`, it appends `_encrypted` before the file extension
- If mode is `decrypt`, it appends `_decrypted` before the file extension
- If the input name already ends with `_encrypted`, that suffix is removed before adding `_decrypted`

Examples:
- `notes.txt` + `encrypt` → `notes_encrypted.txt`
- `notes_encrypted.txt` + `decrypt` → `notes_decrypted.txt`

## Files in This Branch

- `input_validation.h`
- `input_validation.cpp`

## Expected Integration with Branch 2

Branch 2 will handle:
- Opening the input file
- Reading the file character by character
- Applying XOR to each character
- Writing the result to the output file

After merge, the general program flow is expected to be:

1. Get mode
2. Get input filename
3. Get XOR key
4. Generate output filename
5. Pass these values to the file processing layer
6. Perform encryption/decryption
7. Print success or error message

## Current Status

Branch 1 is complete for the input-validation stage and is ready for integration with the XOR file-processing branch.

## Notes

- This branch focuses only on validation and program setup
- No cryptographic transformation is done here
- All invalid user inputs are handled by repeated prompting