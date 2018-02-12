// 试密码
#include <stdio.h>
#include <string.h>

#define MaxSize 1000

int main(int argc, char const *argv[])
{
	char correct[MaxSize]; int times;
	gets(correct);

	int len = strlen(correct);
	times = correct[len - 1] - '0';
	correct[len - 2] = '\0';

	int i, Try = times, flag = 0;
	char input[MaxSize];

	for(i=0; i<times; i++){
		gets(input);
		if(flag == 0){
			if(strcmp(input, correct) != 0){
				Try--;
				printf("Wrong password: %s\n", input);
			}
			else{
				flag = 1; // 获取正确密码后不再进行比较
			}
		}
	}

	while(true){
		gets(input);
		if(strcmp(input, "#") == 0) break;
	}

	if(Try > 0) printf("Welcome in\n");
	else printf("Account locked\n");
	
	return 0;
}
