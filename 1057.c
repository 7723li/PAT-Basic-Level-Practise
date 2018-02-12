// 数零壹
#include <stdlib.h>
#include <stdio.h>

#define MaxSize 100000

bool isletter(char c, int* num){
	int ascii = (int)c;
	if(ascii >= 65 && ascii <= 90){
		(*num) = ascii - 65 + 1;
		return true;
	}
	else if (ascii >= 97 && ascii <= 122){
		(*num) = ascii - 97 + 1;
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	char input[MaxSize];
	while(input[0] == 0) gets(input);

	int i, N = 0, num = 0;
	for(i=0; input[i] != '\0'; i++){
		if( isletter(input[i], &num) ) N += num;
	}

	int zero = 0, one = 0;
	while(N){
		if(N % 2) one++;
		else zero++;
		N /= 2;
	}

	printf("%d %d\n", zero, one);
	
	return 0;
}

// 输入样例：
// PAT (Basic)
// 输出样例：
// 3 4
