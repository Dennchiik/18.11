#include <cstdio>
#include <cctype>

void encryptFile(const char* inputFile, const char* outputFile, int shift) {
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");

    if (input == nullptr || output == nullptr) {
        perror("Error opening files");
        return;
    }

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (isalpha(ch)) {
            char shifted = ch + shift;
            if ((isupper(ch) && shifted > 'Z') || (islower(ch) && shifted > 'z')) {
                shifted -= 26; 
            }
            fputc(shifted, output);
        }
        else {
            fputc(ch, output); 
        }
    }

    fclose(input);
    fclose(output);
}

int main() {
    const char* inputFile = "input.txt"; 
    const char* outputFile = "output.txt"; 
    int shift = 3; 

    encryptFile(inputFile, outputFile, shift);

    printf("Encryption complete!\n");
    return 0;
}

