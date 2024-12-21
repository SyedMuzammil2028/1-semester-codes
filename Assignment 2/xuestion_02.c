#include <stdio.h>

void frequency(char slogan[]) {
    int Frequency[256] = {0};  

    for (int i = 0; slogan[i] != '\0'; i++) {
        Frequency[(int)slogan[i]]++;
    }

    printf("Character frequency for \"%s\": {", slogan);
    
    int printed[256] = {0};  
    
    for (int i = 0; slogan[i] != '\0'; i++) {
        int ascii_value = (int)slogan[i];
        
       
        if (Frequency[ascii_value] != 0 && !printed[ascii_value]) {
            printf("'%c': %d, ", slogan[i], Frequency[ascii_value]);
            printed[ascii_value] = 1;  
        }
    }
    
    printf("}\n");
}

int main() {
    int sloganNO;
    printf("\nEnter no of slogan you want to enter: ");
    scanf("%d",&sloganNO);
    getchar();
    char slogan[sloganNO][100];
    
    for (int i = 0; i < sloganNO; i++) {
        printf("\nEnter slogan %d: ", i + 1);
        fgets(slogan[i], sizeof(slogan[i]), stdin);
    }

    for (int i = 0; i < sloganNO; i++) {
        frequency(slogan[i]);
    }
    return 0;
}
