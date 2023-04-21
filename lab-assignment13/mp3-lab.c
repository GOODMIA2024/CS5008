// name: Minjia Tao
// email: tao.mi@northeastern.edu

#include <stdio.h>
#include <string.h>

int compression(char arr[], int n, char res[]){
    int i, count, len;
    char current_char;
    len = 0;
    i = 0;
    while (i < n) {
        current_char = arr[i];
        count = 1;
        while (i + 1 < n && arr[i + 1] == current_char) {
            count++;
            i++;
        }
        if (count == 1) {
            res[len++] = current_char;
        }
        else {
            len += sprintf(&res[len], "%c%d", current_char, count);
        }
        i++;
    }
    res[len] = '\0';
    return len;
}
 
int main()
{
    char a[]= "aaaaaaabbbbbbbcddddh";//"aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    return 0;
}
