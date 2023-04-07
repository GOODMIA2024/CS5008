// name: Minjia Tao
// email: tao.mi@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    int i, j;
    long long int d[20] = {1, 0, 3};
    for (i = 4; i <= n; i += 2) {
        d[i] = 3 * d[i-2];
        for (j = 0; j <= i-4; j += 2) {
            d[i] += 2 * d[j];
        }
    }
    return d[n];
}


int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}