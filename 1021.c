// 1021. 个位数统计
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 1001

int main(int argc, char const *argv[])
{
	char N[MaxSize];
	int li[10];
	int k;
	scanf("%s",N);
	k = strlen(N);
	for(int i=0;i<10;i++) li[i] = 0;
	for(int i=0;i<k;i++) li[N[i] - '0']++;
	for(int i=0;i<10;i++){
		if(li[i] != 0){
			printf("%d:%d\n", i,li[i]);
		}
	}

	return 0;

	system("pause");
}

// 100311
