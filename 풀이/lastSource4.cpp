#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

#define TEAM_RED 1
#define TEAM_BLUE 2

#define TYPE_ITEM 1
#define TYPE_SPEED 2

typedef struct {
	int team;
	long timestamp;
	int score;
}Record;

typedef struct {
	int type;
	Record records[8];
}TestCase;

int itemResult(TestCase);
int speedResult(TestCase);
int compareRecord(const void*, const void*);

int main() {
	TestCase cases[1000];

	int count;

	scanf("%d", &count);

	for (int i = 0; i < count; ++i) {
		memset(&cases[i], 0, sizeof(cases[i]));
		char temp[10] = { 0 };

		scanf("%s", temp);
		if (temp[0] == 'i') {
			cases[i].type = TYPE_ITEM;
		}
		else if (temp[0] == 's') {
			cases[i].type = TYPE_SPEED;
		}
		else {
			return -1;
		}

		for (int j = 0; j < 8; ++j) {
			memset(temp, 0, 10);
			scanf("%s", temp);

			if (temp[0] == 'b') {
				cases[i].records[j].team = TEAM_BLUE;
			}
			else if (temp[0] == 'r') {
				cases[i].records[j].team = TEAM_RED;
			}
			else {
				return -2;
			}

			memset(temp, 0, 10);
			scanf("%s", temp);

			//: and . to NULL terminate char
			temp[1] = 0;
			temp[4] = 0;

			cases[i].records[j].timestamp = atoi(temp) * 60 * 1000 + atoi(temp + 2) * 1000 + atoi(temp + 5) * 10;
		}

		int result;
		if (cases[i].type == TYPE_SPEED) {
			result = speedResult(cases[i]);
		}
		else {
			result = itemResult(cases[i]);
		}

		printf(result == TEAM_RED ? "red" : "blue");
	}

}

int itemResult(TestCase test) {
	qsort(test.records, 8, sizeof(Record), compareRecord);
	return test.records[0].team;
}

int speedResult(TestCase test) {
	qsort(test.records, 8, sizeof(Record), compareRecord);

	long ftime = test.records[0].timestamp;

	test.records[0].score = 10;
	test.records[1].score = 8;
	test.records[2].score = 6;
	test.records[3].score = 5;
	test.records[4].score = 4;
	test.records[5].score = 3;
	test.records[6].score = 2;
	test.records[7].score = 1;
	
	for (int i = 1; i < 8; ++i) {
		if (test.records[i].timestamp - ftime > 10 * 1000) {
			test.records[i].score = 0;
		}
	}

	int blueScore = 0;
	int redScore = 0;

	for (int i = 0; i < 8; ++i) {
		if (test.records[i].team == TEAM_RED) {
			redScore += test.records[i].score;
		}
		else {
			blueScore += test.records[i].score;
		}
	}

	if (redScore == blueScore)
	{
		return test.records[0].team;
	}

	return redScore > blueScore ? TEAM_RED : TEAM_BLUE;

}

int compareRecord(const void* r1, const void* r2) {
	long a = ((Record*)r1)->timestamp;
	long b = ((Record*)r2)->timestamp;
	return a == b ? 0 : a > b ? 1 : -1;
}

int compareInt(void* a1, void* a2) {
	int a = *(int*)a1;
	int b = *(int*)a2;
	return a == b ? 0 : a> b ? 1 : -1;
}