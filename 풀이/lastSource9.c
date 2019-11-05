#include <stdio.h>
long long int flog2(long long int i) {
	long long int r = 0;
	while (i >>= 1) {
		++r;
	}
	++r;

	return r;
}

long long int powmod(long long int a, long long int e, long long int n) {
	int result = 1;
	while (e > 0) {
		result *= a;
		result %= n;
		e--;
	}
	
	return result;
}

int main()
{
	long long int n, h;
	scanf("%lld %lld", &n, &h);
	   
	long long int h_min = flog2(h) + 1;
	long long int h_max = n;

	
	//if h is Bigger than Maximum or Lesser than Minimum
   if (h < h_min || h > h_max)
   {
      printf("0");
      return 0;
   }
   if (h == h_max)
   {
      //When Maximum, 2^(n-1)
      printf("%d", powmod(2, n-1, 1000000007));
      return 0;
   }
   if (h == h_min)
   {
      //When Minimum, 2^(h_min - 1)
      printf("%d", 1 << (h_min - 1));
      return 0;
   }
   return 1;
}