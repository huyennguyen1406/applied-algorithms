#include <stdio.h>

int n, m;
int x[100];
int f = 0;

void Try(int k) {
    if (k == n) {
        x[k] = m -f;
        if (x[k] > 0) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", x[i]);
            }
            printf("\n");
        }
        return;
    }

    int m0 = m - f - (n - k);
    for (int v = 1; v <= m0; ++v) {
        x[k] = v;
        f += v;
        Try(k + 1);
        f -= v;
    }
}

int main() {
    printf("Enter number children n:");
    scanf("%d", &n);
    printf("Enter number candies m: ");
    scanf("%d", &m);

    if (n > m)
    {
        printf("Khong the chia keo vo so keo it hon so tre em.\n");
        return 0;
    }
    Try(1);
    return 0;
}