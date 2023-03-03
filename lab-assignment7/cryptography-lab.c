//name: Minjia Tao
//email: tao.mi@northeastern.edu

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to encrypt the data*/
void encrypt(char text[], int key)
{
    // Add your code here
    // traverse through the text index by index
    for (int i = 0; text[i] != '\0'; i++) {
        char oldChar = text[i];
        char newChar;
        if (isupper(oldChar))
            newChar = (oldChar - 'A' + key) % 26 + 'A';
        else if (islower(oldChar)) 
            newChar = (oldChar - 'a' + key) % 26 + 'a';
        else
            newChar = oldChar;
        text[i] = newChar;
    }   
}

/*function to decrypt the data*/
void decrypt(char text[],int key)
{
    // Add your code here
    for (int i = 0; text[i] != '\0'; i++) {
        // 1. 有必要考虑防止原来的数据结构被破坏？
        // 2. consider invalid input?
        char oldChar = text[i];
        char newChar;
        if (isupper(oldChar))
            newChar = (oldChar - 'A' - key + 26) % 26 + 'A';
        else if (islower(oldChar)) 
            newChar = (oldChar - 'a' - key + 26) % 26 + 'a';
        else 
            newChar = oldChar;
        text[i] = newChar;
    }
}


/*----------- Main program---------------*/
int main()
{
    char text[20] ;
    int keyvalue=3;
    /*Input string */
    printf("Enter the message:  ");
    scanf("%s",text);
    printf("text input = %s\n",text);
    
    /*call function to encrypt the data*/
    encrypt(text,keyvalue);
    printf("Encrypted value = %s\n",text);
    
    /*call function to decrypt the data*/
    decrypt(text,keyvalue);
    printf("Decrypted value = %s\n",text);
    
    return 0;
}
// Khoury
// Hello