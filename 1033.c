// 旧键盘打字
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define letters_lenth 26
#define nums_lenth 10
#define other_lenth 5
#define MaxLenth 100000

bool in(char c,char list[]){
	for(int i=0; list[i] != '\0';i++)
		if(c == list[i] || c == list[i] -32 )
			return true;
	return false;
}

void Delete(char c,char list[]){
	int i, j=0;
	for(i=0; list[i] != '\0'; i++){
		if(list[i] == c || c == list[i] -32) 
			continue;
		else list[j++] = list[i];
	}
	list[j] = '\0'; return;
}

void DeleteCap(char list[]){
	int i, j=0;
	for(int i=0; list[i] != '\0'; i++){
		if( (int)list[i] >= 65 && (int)list[i] <= 90 )
			continue;
		else list[j++] = list[i];
	}
	list[j] = '\0'; return;
}

int main(int argc, char const *argv[])
{
	char wrong[letters_lenth + nums_lenth + other_lenth];
	char input[MaxLenth];
	int i;

	scanf("%s", wrong);
	scanf("%s", input);

	// 删除正常字符串中无法输出的字符
	for(i=0; i<strlen(wrong); i++){
		if(in(wrong[i], input)) Delete(wrong[i], input);
		if(wrong[i] == '+') DeleteCap(input);
	}

	printf("%s\n", input);

	return 0;
}

// 7+IE.
// 7_This_is_a_test.
