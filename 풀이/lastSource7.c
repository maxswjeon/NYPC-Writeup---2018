#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int users[2880] = {0};

int main()
{
	int count = 0;
	char temp[6] = { 0 };

	scanf("%d", &count);

	for (int i = 0; i < count; ++i) {
		memset(temp, 0, 6);
		scanf("%s", temp);

		temp[2] = 0;
		int start_h = atoi(temp);
		int start_m = atoi(temp + 3);
		int start_t = start_h * 60 + start_m;

		memset(temp, 0, 6);
		scanf("%s", temp);
		temp[2] = 0;
		int end_h = atoi(temp);
		int end_m = atoi(temp + 3);
		int end_t = end_h * 60 + end_m;

		for (int j = start_t * 2; j < end_t * 2; ++j)
		{
			users[j]++;
		}

	}

	int max_count = 0;
	int max_start = 0;
	int max_end = 0;
	int max_current = FALSE;

	for (int j = 0; j < 2880; ++j)
	{
		if (max_count < users[j])
		{
			max_count = users[j];
			max_start = j / 2;
			max_current = TRUE;
		}

		if (max_current == TRUE)
		{
			if (max_count != users[j])
			{
				max_end = j / 2;
				max_current = FALSE;
			}
		}
	}

	printf("%d\n%02d:%02d %02d:%02d", max_count, max_start / 60, max_start % 60, max_end / 60, max_end % 60);

}