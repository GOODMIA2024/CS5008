//Minjia Tao
//tao.mi@northeastern.edu
#include<stdio.h>
int main()
{
    int a,b,c, choice;
    
    printf("Enter your choice\n");
    printf(" 1.addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    if (!(choice >= 1 && choice <= 4)) { //注意这边if语句的写法
        printf("Invalid option\n");
    // Add your code here using switch
    } else {
        printf("Enter a and b values");
        scanf("%d %d", &a, &b);
        switch (choice) {
            case 1://变成integer在switch和case里面
                printf("Addition\n");
                c = a + b;
                printf("Sum=%d\n", c);
                break;

            case 2:
                printf("Subtraction\n");
                c = a - b;
                printf("Difference=%d\n", c);
                break;
                
            case 3:
                printf("Multiplication\n");
                c = a*b;
                printf("Product=%d\n", c);
                break;
        
            case 4:
                
                if (b == 0) { //要用括号而不是冒号，改了之后要重新编译
                    printf("divide by zero error\n");
                    break;
                }
                else {
                    c = a/b;
                    printf("Division\n");
                    printf("Quotient=%d\n",c);
                    break;
                }
        }
    }
        
    return 0;
}
