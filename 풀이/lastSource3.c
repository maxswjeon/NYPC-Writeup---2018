#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int a, b, n, swap = FALSE;
    
    scanf("%d %d", &a, &b);
    scanf("%d", &n);
    
    //Without Loss of Generality
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
        
        swap = TRUE;
    }
    
    int r = n % b;
    int q = 0;
    for (int i = 0; i < b; ++i) {
        if ((a * i) % b == r) {
            q = i;
            break;
        }
    }
    
    int x = q;
    int y = (n - a * q) / b;
    
    if (swap == TRUE) {
        printf("%d %d", y, x);
        return 0;
    }
    
    printf("%d %d", x, y);
}