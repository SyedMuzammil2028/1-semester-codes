#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char HexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);


int BinaryToDecimal(int number){
	int decimal=0,base=1,remainder;
	while(number>0){
		remainder=number%10;
		if(remainder!=0  && remainder!=1){
			printf("Enter a Valid binary number");
			return -1;
		}
		decimal+=remainder*base;
		base*=2;
		number/=10;
	}
	return decimal;
}
int DecimalToBinary(int number){
	int binary=0,remainder,count=0,a;
	if(number<0){
		printf("Enter positive numbers");
		return -1;
	}
	while(number!=0){
		remainder=number%2;
		a=pow(10,count);
        binary+=a*remainder;
        number/=2;
        count++;
	}
	return binary;
}
void DecimalToHexadecimal(int number){
	int remainder,i=0;
	char hexa[100];
    while (number!=0) {
        remainder=number%16;
        if (remainder<10) {
            hexa[i]=remainder+'0';
        } else {
            hexa[i]=remainder-10+'A';
        }
        i++;
        number/= 16;
    }
    for (i=i-1; i>=0; i--) {
        printf("%c",hexa[i]);
    }
}
void HexadecimalToDecimal(char HexNumber[]){
	    int decimal=0, i=0,len,digit;
	    len=strlen(HexNumber);

    for (i=0;i<len;i++) {
        if (HexNumber[i]>='0' && HexNumber[i]<='9') {
            digit=HexNumber[i]-'0';
        } else if (HexNumber[i]>='A' && HexNumber[i]<='F') {
            digit=HexNumber[i]-'A'+10;
        } else if (HexNumber[i]>='a'&& HexNumber[i]<='f') {
            digit=HexNumber[i]-'a'+10;
        } else {
            printf("Invalid hexadecimal digit: %c\n",HexNumber[i]);
        }
        decimal+=digit*pow(16,len-i-1);
    }
    printf("Decimal equivalent: %d\n", decimal);
}
void BinaryToHexadecimal(int number){
	int decimal=BinaryToDecimal(number);
	if(decimal!=-1){
	 	int remainder,i=0;
	    char hexa[100];
        while (decimal!=0) {
        remainder=decimal%16;
         if (remainder<10) {
            hexa[i]=remainder+'0';
         } else {
            hexa[i]=remainder-10+'A';
         }
        i++;
        decimal/= 16;
    }
    for (i=i-1; i>=0; i--) {
        printf("%c",hexa[i]);
    }
    }	
}
void HexadecimalToBinary(char HexNumber[]){
	    int decimal=0, i=0,len,digit;
	    len=strlen(HexNumber);

    for (i=0;i<len;i++) {
        if (HexNumber[i]>='0' && HexNumber[i]<='9') {
            digit=HexNumber[i]-'0';
        } else if (HexNumber[i]>='A' && HexNumber[i]<='F') {
            digit=HexNumber[i]-'A'+10;
        } else if (HexNumber[i]>='a'&& HexNumber[i]<='f') {
            digit=HexNumber[i]-'a'+10;
        } else {
            printf("Invalid hexadecimal digit: %c\n",HexNumber[i]);
        }
        decimal+=digit*pow(16,len-i-1);
    }
    int result=DecimalToBinary(decimal);	
    printf("%d",result);
}
int main()
{
 int choice,number;
 char HexaNumber[30];
    while(1){
 		printf("\nSelect the Conversion you want to perform:\n");
	 printf("1.Binary to decimal\n");
	 printf("2.Decimal to binary\n");
	 printf("3.Decimal to hexadecimal\n");
	 printf("4.Hexadecimal to decimal\n");
	 printf("5.Binary to hexadecimal\n");
	 printf("6.Hexadecimal to binary\n");
	 printf("7.Exit\n");
	 printf("Enter choice:");
	 scanf("%d",&choice);
	 
	 switch(choice)
	 {
	 	case 1:{
	 		printf("Enter a binay number:");
	 		scanf("%d",&number);
	 		int decimal=BinaryToDecimal(number);
	 		if(decimal!=-1){
	 			printf("Decimal equivavlent: %d",decimal);
			 }
			break;
	    }
	 	case 2:{
	 		printf("Enter a decimal number:");
	 		scanf("%d",&number);
	 		int binary=DecimalToBinary(number);
	 		if(binary!=-1){
	 			printf("Binary equivavlent: %d",binary);
			  }
			break;
		 }
	    case 3:{
	    	printf("Enter a decimal number:");
	 		scanf("%d",&number);
	 		DecimalToHexadecimal(number);
			break;
		}
		case 4:{
			printf("Enter a HexaDecimal Number:");
			scanf("%s",&HexaNumber);
			HexadecimalToDecimal(HexaNumber);
			break;
		}
		case 5:{
			printf("Enter a binary Number: ");
			scanf("%d",&number);
			BinaryToHexadecimal(number);
			break;
		}
		case 6:{
			printf("Enter a hexadecimal Number: ");
			scanf("%s",&HexaNumber);
			HexadecimalToBinary(HexaNumber);
			break;
		}
		default:
		printf("Invalid choice");
		case 7:{
			printf("Exiting The Progarm.");
			return 0;
		}			     
    }
    }
return 0;    
} 