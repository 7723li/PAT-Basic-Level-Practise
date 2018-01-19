// 划拳
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int nums, i, j, point;
	int play[4] = {0};
	int drinks[2] = {0};

	scanf("%d", &nums);
	for(i=0; i<nums; i++){
		for(j=0; j<4; j++){// 甲喊 甲划 乙喊 乙划
			scanf("%d", &play[j]);
		}
		point = play[0] + play[2];
		if(play[1] == play[3]) continue;
		else if(play[1] == point){
			drinks[1]++;
		}
		else if(play[3] == point){
			drinks[0]++;
		}
	}
	printf("%d %d\n", drinks[0], drinks[1]);
	
	return 0;
}

// 5
// 8 10 9 12
// 5 10 5 10
// 3 8 5 12
// 12 18 1 13
// 4 16 12 15
