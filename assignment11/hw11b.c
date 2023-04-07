// name: Minjia Tao
// email: tao.mi@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    long long int d[100];
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i-1] + d[i-2] * 2;
    }
    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
