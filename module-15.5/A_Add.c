#include <stdio.h>

void printSum(int x, int y) { printf("%d", x + y); }

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    printSum(x, y);

    return 0;
}