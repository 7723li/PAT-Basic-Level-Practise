// 结绳
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return *(double*)a - *(double*)b;
}

int main(int argc, char const *argv[])
{
	int nums, i;
	scanf("%d", &nums);

	double list[nums];
	for(i=0; i<nums; i++)
		scanf("%lf", &list[i]);
	qsort(list, nums, sizeof(list[0]), cmp);

	double sum = 0.0;
	for(i=0; i<nums; i++){
		if(i == 0)
			sum += list[i] / 2;
		else if(i == 1)
			sum += list[i] / 2;
		else{
			sum /= 2;
			sum += list[i] / 2;
		}
	}

	printf("%d\n", (int)sum);
	
	return 0;
}

// 输入样例：
// 8
// 10 15 12 3 4 13 1 15
// 输出样例：
// 14
