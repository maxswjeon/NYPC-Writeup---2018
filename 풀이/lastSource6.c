#include <stdio.h>

int main() {
int count;
double x = 0;
double y = 0;

scanf("%d",&count);
for (int i =0; i < count; ++i) {
int temp_x, temp_y;
scanf("%d %d", &temp_x, &temp_y);
x += temp_x;
y += temp_y;
}

x = x / (double)count;
y = y / (double)count;

printf("%lf %lf", x, y);

return 0;
}