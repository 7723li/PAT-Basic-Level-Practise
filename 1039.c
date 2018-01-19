// 到底买不买
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 1000

int main(int argc, char const *argv[])
{
	char provide[MaxSize], need[MaxSize];
	int numsP[122+1] = {0}, numsN[122+1] = {0}; // 'z' ascii 122
	int* kinds, flag = 1;
	int i, lack = 0; // 剩余, 缺乏

	scanf("%s", provide); 
	scanf("%s", need);

	kinds = (int*) malloc (sizeof(int) * strlen(need));

	for(i=0; provide[i] != '\0'; i++) numsP[ (int)provide[i] ]++;
	for(i=0; need[i] != '\0'; i++) numsN[ (int)need[i] ]++;

	for(i=48; i<122+1; i++){ // '0' ~ 'z'
		if(numsN[i] != 0){
			if(numsP[i] < numsN[i]){
				lack += (numsN[i] - numsP[i]);
				flag = 0;
			}
		}
	}

	if(flag) printf("Yes %d\n", strlen(provide) - strlen(need));
	else printf("No %d\n", lack);
	
	return 0;
}

// 输入样例1：
// ppRYYGrrYBR2258
// YrR8RrY
// 输出样例1：
// Yes 8
// 输入样例2：
// ppRYYGrrYB225
// YrR8RrY
// 输出样例2：
// No 2
