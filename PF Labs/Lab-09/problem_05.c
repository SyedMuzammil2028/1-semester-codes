#include <stdio.h>
#include <string.h>
#define NUM_WORDS 5
#define MAX_LENGTH 20
// Function to check if a word is a palindrome
int isPalindrome(char word[]){
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++){
        if (word[i] != word[length - i - 1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    char words[NUM_WORDS][MAX_LENGTH];
  
    printf("Enter %d words (maximum %d characters each):\n", NUM_WORDS, MAX_LENGTH - 1);
    for (int i = 0; i < NUM_WORDS; i++){
        printf("Word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    printf("\nResults:\n");
    for (int i = 0; i < NUM_WORDS; i++){
        if (isPalindrome(words[i])){
            printf("%s: Palindrome\n", words[i]);
        }
        else{
            printf("%s: Not Palindrome\n", words[i]);
        }
    }
    return 0;}
