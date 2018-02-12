// 组合数的和
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int nums, *list;
	scanf("%d", &nums);
	list = (int*) malloc (sizeof(int) * nums);

	int i, sum = 0;
	for(i=0; i<nums; i++){
		scanf("%d", &list[i]);
		sum += list[i];
		sum += list[i] * 10;
	}

	printf("%d\n", sum * (nums - 1));
	
	return 0;
}
