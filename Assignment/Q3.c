#include <stdio.h>


unsigned int setBit(unsigned int x, int n) {
    return x | (1u << n);
}


unsigned int resetBit(unsigned int x, int n) {
    return x & ~(1u << n);
}


unsigned int flipBit(unsigned int x, int n) {
    return x ^ (1u << n);
}


unsigned int setKthBit(unsigned int x, int k) {
    return x | (1u << (k - 1));
}


unsigned int resetKthBit(unsigned int x, int k) {
    return x & ~(1u << (k - 1));
}


unsigned int flipKthBit(unsigned int x, int k) {
    return x ^ (1u << (k - 1));
}


void displayBinary(unsigned int x) {
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

int main() {
    unsigned int num = 10; 

    printf("Original number: %u\n", num);
    printf("Binary representation: ");
    displayBinary(num);

   
    int nth_bit_to_set = 2;
    printf("\nSetting %dth bit:\n", nth_bit_to_set);
    num = setBit(num, nth_bit_to_set);
    printf("Result: %u\n", num);
    printf("Binary representation: ");
    displayBinary(num);

   
    int nth_bit_to_reset = 3;
    printf("\nResetting %dth bit:\n", nth_bit_to_reset);
    num = resetBit(num, nth_bit_to_reset);
    printf("Result: %u\n", num);
    printf("Binary representation: ");
    displayBinary(num);

    
    int nth_bit_to_flip = 1;
    printf("\nFlipping %dth bit:\n", nth_bit_to_flip);
    num = flipBit(num, nth_bit_to_flip);
    printf("Result: %u\n", num);
    printf("Binary representation: ");
    displayBinary(num);

    
    int kth_bit_to_set = 4;
    printf("\nSetting %dth bit:\n", kth_bit_to_set);
    num = setKthBit(num, kth_bit_to_set);
    printf("Result: %u\n", num);
    printf("Binary representation: ");
    displayBinary(num);

    
    int kth_bit_to_reset = 5;
    printf("\nResetting %dth bit:\n", kth_bit_to_reset);
    num = resetKthBit(num, kth_bit_to_reset);
    printf("Result: %u\n", num);
    printf("Binary representation: ");
    displayBinary(num);

    
    int kth_bit_to_flip = 6;
    printf("\nFlipping %dth bit:\n", kth_bit_to_flip);
    num = flipKthBit(num, kth_bit_to_flip);
    printf("Result: %u\n", num);
    printf("Binary representation: ");
    displayBinary(num);

    return 0;
}