#include <stdio.h>
// program to input the valid name and phone no
int main(){
    char name[100];
    char phone[20]; 
    
    // read the valid name
    printf("Enter name: ");
    scanf(" %[A-Za-z ]", name);  
    
    // read the valid phone no
    printf("Enter phone number: ");
    scanf(" %[+0-9 -]", phone);  

    // Output the valid inputs
    printf("\nName: %s\n", name);
    printf("Phone number: %s\n", phone);

    return 0;
}
