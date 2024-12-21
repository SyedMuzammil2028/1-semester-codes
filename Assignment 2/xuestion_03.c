#include <stdio.h>
#include <string.h>

void compressWord(char word[]) {
    char compressed[20];
    int index = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressed[index++] = word[i];
        }
    }
    compressed[index] = '\0';
    printf("\"%s\" ", compressed);
}

int main() {
    int n;
    printf("\nEnter no of words: ");
    scanf("%d", &n);
    char words[n][100];

    for (int i = 0; i < n; i++) {
        printf("Enter words %d: ", i + 1);
        scanf("%s", words[i]);
    }
    printf("\nCompressed words: ");
    for (int i = 0; i < n; i++) {
        compressWord(words[i]);
    }
    printf("\n");
    return 0;
}
