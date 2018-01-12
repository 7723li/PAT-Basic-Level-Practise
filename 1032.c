#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int id, score;
	int nums, i;
	int max = 0, maxid = 0;
	int* list;

	scanf("%d", &nums);
	list = (int*) malloc (sizeof(int) * nums);
	for(i=0; i<nums; i++) list[i] = 0;

	for(i=0; i<nums; i++){
		scanf("%d %d", &id, &score);
		list[id] += score;
		if(list[id] > max){
			max = list[id];
			maxid = id;
		}
	}

	printf("%d %d\n", maxid,max);

	free(list);
	return 0;
}

// 6
// 3 65
// 2 80
// 1 100
// 2 70
// 3 40
// 3 0
