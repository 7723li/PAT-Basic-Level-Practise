// 编程团体赛
#include <stdio.h>
#include <stdlib.h>

#define MaxTeams 1000
#define MaxTeamates 10

int main(int argc, char const *argv[])
{
	int nums, i, temp, ord, point, max = 0;
	int scores[MaxTeams] = {0};

	scanf("%d", &nums);
	for(i=0; i<nums; i++){
		scanf("%d-%d %d", &ord, &temp, &point);
		scores[ord] += point;
	}

	for(i=0; i<MaxTeams; i++){
		if(scores[i] > max){
			max = scores[i];
			temp = i;
		}
	}

	printf("%d %d\n", temp, max);
	
	return 0;
}

// 6
// 3-10 99
// 11-5 87
// 102-1 0
// 102-3 100
// 11-9 89
// 3-2 61
