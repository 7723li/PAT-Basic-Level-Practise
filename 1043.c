// 输出PATest
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char target[] = "PATest";

#define MaxSize 10000
#define lenth strlen(target)

bool in(const char* l, const char c){
	int i;
	for(i=0; l[i] != '\0'; i++){
		if(c == l[i]) return true;
	}
	return false;
}

void set(const char* input,char* output){
	int i, j=0, k;
	char temp;
	for(i=0; input[i] != '\0'; i++){
		if( in(target, input[i]) ){
			output[j++] = input[i];
		}
	}
	output[j] = '\0';
}

void getNums(const char* c,int* nums){
	int i, j;
	for(i=0; c[i] != '\0'; i++){
		for(j=0; target[j] != '\0'; j++){
			if(c[i] == target[j]){
				nums[j]++;
				break;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	char input[MaxSize], *output;
	int i=0, j=0, nums[lenth], temp=0;

	for(i=0; i<lenth; i++) nums[i] = 0;

	scanf("%s", input);
	output = (char*) malloc (sizeof(char) * strlen(input));

	set(input, output);
	getNums(output, nums);

	while(true){
		if(temp == strlen(output)) break;
		for(i=0; i<lenth; i++){
			if(nums[i] > 0){
				printf("%c", target[i]);
				temp++;
				nums[i]--;
			}
		}
	}
	printf("\n");
	
	return 0;
}

// 输入样例：
// redlesPayBestPATTopTeePHPereatitAPPT
// 输出样例：
// PATestPATestPTetPTePePee
