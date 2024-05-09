#include <stdio.h>
#include <stdlib.h>


void decimalToBinary(int decimal) {
    printf("Binary: %d\n", decimal);
}


void decimalToOctal(int decimal) {
    printf("Octal: %o\n", decimal);
}


void decimalToHexadecimal(int decimal) {
    printf("Hexadecimal: %X\n", decimal);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s -getHex <decimal>\n", argv[0]);
        return 1;
    }

    int decimal = atoi(argv[2]);

    if (strcmp(argv[1], "-getHex") == 0) {
        decimalToBinary(decimal);
        decimalToOctal(decimal);
        decimalToHexadecimal(decimal);
    } else {
        printf("Invalid option. Use -getHex.\n");
        return 1;
    }

    return 0;
}