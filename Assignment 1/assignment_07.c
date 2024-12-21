#include <stdio.h>
#include <string.h>

int main() {
    char inputCode[8];  // 7 characters + null terminator

    // Input: Ask the user to enter the 7-segment binary code
    printf("Enter the 7-segment binary number (e.g., 1111110): ");
    scanf("%s", inputCode);

    // Process: Use if-else branching to match the input to predefined 7-segment codes

    if (strcmp(inputCode, "1111110") == 0) {
        printf("The lift is on floor: 0\n");
    } else if (strcmp(inputCode, "0110000") == 0) {
        printf("The lift is on floor: 1\n");
    } else if (strcmp(inputCode, "1101101") == 0) {
        printf("The lift is on floor: 2\n");
    } else if (strcmp(inputCode, "1111001") == 0) {
        printf("The lift is on floor: 3\n");
    } else if (strcmp(inputCode, "0110011") == 0) {
        printf("The lift is on floor: 4\n");
    } else if (strcmp(inputCode, "1011011") == 0) {
        printf("The lift is on floor: 5\n");
    } else if (strcmp(inputCode, "1011111") == 0) {
        printf("The lift is on floor: 6\n");
    } else if (strcmp(inputCode, "1110000") == 0) {
        printf("The lift is on floor: 7\n");
    } else if (strcmp(inputCode, "1111111") == 0) {
        printf("The lift is on floor: 8\n");
    } else if (strcmp(inputCode, "1111011") == 0) {
        printf("The lift is on floor: 9\n");
    } else {
        // If no valid match is found, output an error message
        printf("Invalid 7-segment input.\n");
    }

    return 0;
}
