// 字符串压缩与解压
#include <stdio.h>
#include <ctype.h>

#define MaxSize 1000
#define MaxOutput 1024

void compress(char* l){ // 压缩
	int i, nums = 0;
	char temp = l[0];
	for(i = 0; l[i-1] != '\0'; i++){
		if(l[i] != temp){
			if(nums != 1)
				printf("%d%c", nums, temp);
			else
				printf("%c", temp);
			temp = l[i];
			nums = 1;
		}
		else
			nums++;
	}
	printf("\n"); return;
}

void decompression(char* l){ // 解压
	int i, j = 0, k, sum = 0;
	for(i=0; l[i] != '\0'; i++){
		if(isdigit(l[i])){
			if(j > 0)
				j *= 10;
			j += l[i] - '0';
		}
		else{
			if(j == 0) j = 1;
			for(k=0; k<j; k++){
				if(sum >= MaxOutput)
					break;
				sum++;
				printf("%c", l[i]);
			}
			j = 0;
		}
	}
	printf("\n"); return;
}

int main(int argc, char const *argv[])
{
	char com, input[MaxSize]; // command
	scanf("%c", &com);

	gets(input);
	while(input[0] == 0)
		gets(input);

	switch(com){
		case 'C': compress(input); break;
		case 'D': decompression(input); break;
	}
	
	return 0;
}

// 输入样例 1：
// C
// TTTTThhiiiis isssss a   tesssst CAaaa as
// 输出样例 1：
// 5T2h4is i5s a3 te4st CA3a as
// 输入样例 2：
// D
// 5T2h4is i5s a3 te4st CA3a as10Z
// 输出样例 2：
// TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
