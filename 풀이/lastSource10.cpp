#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int _id;
	int stemina;
	int exp;
	double eff;
}JOB;

int compare(const void*, const void*);

int main()
{
	int stemina, count;
	JOB job[1000];
	
	long long int result = 0;
	
	
	scanf("%d", &stemina);
	scanf("%d", &count);
	for (int i = 0; i < count; ++i)
	{
		int temp_stemina, temp_exp;
		memset(&job[i], 0 , sizeof(JOB));
		scanf("%d %d", &temp_stemina, &temp_exp);
		job[i] = {
			i,
			temp_stemina,
			temp_exp,
			(double)temp_exp / (double)temp_stemina
		};
	}
	
	qsort(job, count, sizeof(JOB), compare);
	
	int last = 0;
	for (int i = count - 1; i >= 0; --i) {
		if (job[i].stemina > stemina) {
			break;
		}
		stemina -= job[i].stemina;
		result += job[i].exp;
		last = i;
	}
	
	printf("%d\n", result);
	printf("%d\n", count - last);
	
	for (int i = count - 1; i >= last; --i) {
		printf("%d ", job[i]._id + 1);
	}
	
}

int compare(const void* rhs, const void* lhs) {
	double a =(*(JOB*)rhs).eff;
	double b =(*(JOB*)lhs).eff;
	
	return a == b ? 0 : a> b ? 1 : -1;	
}