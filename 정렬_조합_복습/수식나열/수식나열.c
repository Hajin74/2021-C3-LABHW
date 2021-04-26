#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int items[], int itemSize, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, item;
	int total = 0;

	if (k == 0) {
		total = 0;
		for (i = 0; i < bucketSize; i++) {
			if (bucket[i] == 0)
				printf("+%d", i + 1);
			else
				printf("-%d", i + 1);
			total += items[bucket[i]] * (i + 1);
		}
		printf(" = %d\n", total);

		return;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}
 
int main(void) {
	int items[] = { 1, -1 };
	int* bucket;
	int n;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);

	pick(items, 2, bucket, n, n);

	free(bucket);
}