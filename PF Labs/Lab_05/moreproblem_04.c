#include <stdio.h>
// program that uses bitwise operators to perform 
// encryption and decryption of a character.
int main() {
    char ch, encrypted, decrypted;
    int key;

    // raed character to encrypt
    printf("Enter a character: ");
    scanf("%c", &ch);

    // read the encryption key (integer)
    printf("Enter an encryption key (integer): ");
    scanf("%d", &key);

    // perform encryption using XOR
    encrypted = ch ^ key;
    printf("\nEncrypted character: %c (ASCII: %d)", encrypted, encrypted);

    // perform decryption using XOR (same key)
    decrypted = encrypted ^ key;
    printf("\nDecrypted character: %c", decrypted);

    return 0;
}