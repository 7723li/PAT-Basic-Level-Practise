// 宇宙无敌加法器
#include <stdio.h>
#include <string.h>

#define MaxSize 20

int main(int argc, char const *argv[])
{
	char input[MaxSize];
	scanf("%s", input);

	char a[MaxSize], b[MaxSize];
	scanf("%s %s", a, b);
	int lenA = strlen(a), lenB = strlen(b), len = strlen(input);

	int i;

	for(i=0; i<len; i++) 
		a[len - 1 - i] = a[lenA - 1 - i];
	for(i=0; i < len - lenA; i++) 
		a[i] = '0';
	a[len] = '\0';

	for(i=0; i<len; i++) 
		b[len - 1 - i] = b[lenB - 1 - i];
	for(i=0; i < len - lenB; i++) 
		b[i] = '0';
	b[len] = '\0';

	int flag = 0, l, k;
	char res[MaxSize];
	for(i=len - 1; i >= 0; i--){
		if(input[i] == '0') l = 10;
		else l = input[i] - '0';

		k = (a[i] - '0') + (b[i] - '0') + flag;

		if(k / l == 0) flag = 0;
		else flag = 1;

		k -= flag * l;
		res[i] = k + '0';
	}
	res[len] = '\0';

	for(i=0; i<len; i++)
		if(res[i] != '0')
			break;

	if(i == len) printf("0");
	else{
		for(i; i<len; i++)
			printf("%c", res[i]);
	}
	printf("\n");

	return 0;
}

// 输入样例：
// 30527
// 06203
// 415
// 输出样例：
// 7201
