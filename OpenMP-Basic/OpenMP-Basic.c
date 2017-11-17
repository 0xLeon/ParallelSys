#include "stdafx.h"

#define SIZE	(1U << 30U)


int main() {
	unsigned int* nums = (unsigned int*) calloc(SIZE, sizeof(unsigned int));

	if (NULL == nums) {
		puts("Unable to allocate enough memory");
		return 1;
	}

	unsigned long long sum = 0;

	for (unsigned int i = 0; i < SIZE; ++i) {
		nums[i] = i;
	}

	omp_set_num_threads(4);

	long j;

	#pragma omp parallel for reduction(+:sum)
	for (j = 0; j < SIZE; j++) {
		sum = sum + nums[j];
	}

	printf("%llu\n", sum);

	return 0;
}
