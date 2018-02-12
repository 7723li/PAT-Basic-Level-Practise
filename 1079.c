// 延迟的回文数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 2000

void reverse(char* temp, char* tempRev, char* res){
	int i, val, pos = 0, len = strlen(temp);
	for(i = 0; temp[i] != '\0'; i++){
		tempRev[i] = temp[len - 1 - i];
		val = (temp[i] - '0') + (tempRev[i] - '0');
		if(val >= 10){
			if(pos == 0){
				res[pos++] = '1';
				res[pos++] = val % 10 + '0';
			}
			else{
				if(res[pos - 1] == '9'){
					res[pos - 1] = '1';
					res[pos++] = '0';
					res[pos++] = val % 10 + '0';
				}
				else{
					res[pos - 1]++;
					res[pos++] = val % 10 + '0';
				}
			}
		}
		else res[pos++] = val + '0';
	}

	tempRev[len] = '\0'; res[pos] = '\0';
}

int isPalindromic(char* res){
	int i, len = strlen(res);
	if(len == 1) return 1;
	for(i = 0; i < len / 2; i++)
		if(res[i] != res[len - 1 - i])
			return 0;

	return 1;
}

int main(int argc, char const *argv[])
{
	int len = 0, time = 0, flag;
	char temp[MaxSize], tempRev[MaxSize], res[MaxSize];
	char input;

	while(1){
		scanf("%c", &input);
		if(input == '\n') break;
		if(len == 0 && input == '0') continue;
		temp[len++] = input;
	}
	if(len == 0) temp[len++] = '0';
	temp[len] = '\0';

	while(1){
		if(time == 10){
			printf("Not found in %d iterations.\n", time);
			break;
		}

		flag = 1;
		reverse(temp, tempRev, res);

		printf("%s + %s = %s\n", temp, tempRev, res);

		if(isPalindromic(res)){
			printf("%s is a palindromic number.\n", res);
			break;
		}
		else{
			strcpy(temp, res);
			time++;
		}
	}
	
	return 0;
}
