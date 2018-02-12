// 朋友数
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N, list[1000] = {0};
	scanf("%d", &N);

	int i, j, val = 0;
	int nums = 0, flag = 0, max = 0;
	char temp[6];
	for(i=0; i<N; i++){
		val = 0;
		scanf("%s", &temp);
		for(j=0; temp[j] != '\0'; j++){
			val += temp[j] - '0';
		}
		if(list[val] == 0){
			nums++;
			if(val > max){
				list[flag] = 0;
				flag = val+1;
				list[flag] = -1;
				max = val;
			}
			list[val] = 1;
		}
	}

	printf("%d\n", nums);
	for(i=0; i<1000; i++){
		if(list[i] > 0){
			if(list[i+1] == -1){
				printf("%d", i);
				break;
			}
			else printf("%d ", i);
		}
	}
	
	return 0;
}

// 8
// 123 899 51 998 27 33 36 12
