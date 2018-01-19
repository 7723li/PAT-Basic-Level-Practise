// 快速排序
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int nums, i, j, flag = 1;
	int *list, *success, k = 0;

	scanf("%d", &nums);
	list = (int*) malloc (sizeof(int) * nums);
	success = (int*) malloc (sizeof(int) * nums);

	for(i=0; i<nums; i++){
		scanf("%d", &list[i]);
	}

	for(i=0; i<nums; i++){
		flag = 1;
		if(flag){
			for(j=i+1; j<nums; j++){
				if(list[i] > list[j]){
					flag = 0;
					break;
				}
			}
		}
		if(flag){
			for(j=i-1;j>=0;j--){
				if(list[i] < list[j]){
					flag=0;
					break;
				}
			}
		}
		if(flag){
			success[k++] = list[i];
		}
	}

	printf("%d\n", k);
	for(i=0; i<k-1; i++){
		printf("%d ", success[i]);
	}
	printf("%d\n", success[k-1]);
	
	return 0;
}

// 5
// 1 3 2 4 5
