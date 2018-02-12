// 互评成绩计算
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return (*(double*)a > *(double*)b) ? 1 : -1;
}

int main(int argc, char const *argv[])
{
	int nums;
	double FullMark;
	scanf("%d %lf", &nums, &FullMark);

	int i, j, pos, res;
	double temp, tcr, list[nums - 1], val;
	for(i=0; i<nums; i++){
		val = 0.0;
		scanf("%lf", &tcr);
		for(j=0; j<nums - 1; j++){
			scanf("%lf", &temp);
			if(temp >= 0.0 && temp <= FullMark)
				list[j] = temp;
			else list[j] = -1;
		}
		qsort(list, nums - 1, sizeof(list[0]), cmp);

		for(j=0; j<nums - 1; j++)
			if(list[j] != -1)
				break;

		j++; pos = j;
		for(j; j<nums-2; j++)
			val += list[j];
		val /= (nums - pos - 2);
		val = (val + tcr) / 2;

		res = (int)val;
		if(val - res >= 0.5)
			res++;

		printf("%d\n", res);
	}
	
	return 0;
}
