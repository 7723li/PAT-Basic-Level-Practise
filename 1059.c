// C语言竞赛
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10000

int main(int argc, char const *argv[])
{
	int nums, i, temp;
	int ranking[MaxSize] = {0}, checked[MaxSize]= {0};
	scanf("%d", &nums);

	for(i=0; i<nums; i++){
		scanf("%d", &temp);
		ranking[temp] = i+1;
	}

	int k;
	scanf("%d", &k);

	for(i=0; i<k; i++){
		scanf("%d", &temp);
		printf("%04d: ", temp);
		if(ranking[temp] == 0){
			printf("Are you kidding?\n");
		}
		else{
			if(checked[temp] == 0){
				checked[temp] = 1;
				if(ranking[temp] == 1){
					printf("Mystery Award\n");
				}
				else if(ranking[temp] % 2){
					printf("Minion\n");
				}
				else{
					printf("Chocolate\n");
				}
			}
			else{
				printf("Checked\n");
			}
		}
	}

	return 0;
}

// 6
// 1111
// 6666
// 8888
// 1234
// 5555
// 0001
// 6
// 8888
// 0001
// 1111
// 2222
// 8888
// 2222
