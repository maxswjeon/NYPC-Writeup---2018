#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    
    for(int i = 0; i < count; ++i) {
        int temp;
        scanf("%d", &temp);
        printf("%c ", temp);
    }

    return 0;
}