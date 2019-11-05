#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
   
	if (a == b || a == 0) {
		a = 0;
	}
   
	while (b != 0) {
    	a %= b;
    	if (a == 0)
    	{
    		break;
		}
		b %= a;
	}
   
	if (a != 1)
	{
		printf("IM");
	}

	printf("POSSIBLE");
	return 0;
}