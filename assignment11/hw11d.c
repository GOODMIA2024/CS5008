// name: <your name here>
// email: <your email here>

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    int i, j;
    long long int d[20] = {1, 2};
    for (i = 3; i <= n; i++) {
        d[i] = 3 * d[i-2] + 2 * d[i-1];
        for (j = 0; j <= i-3; j += 2) {
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