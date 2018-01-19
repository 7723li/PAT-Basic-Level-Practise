// 字符统计
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 1000

void lower(char* c){
	int i,j;
	for(i=0; c[i] != '\0'; i++){
		j = (int)c[i];
		if( j >= 65 && j <= 90 ){
			c[i] += 32;
		}
	}
}

void sorted(char* c){
	int i,j;
	char temp;
	for(i=0; c[i+1] != '\0'; i++){
		for(j=i+1; c[j] != '\0'; j++){
			if( (int)c[i] > (int)c[j] ){
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
}

void set(char* a,const char* c){
	int i,j=0;
	char temp='\0';
	for(i=0; c[i] != '\0'; i++){
		if(c[i] != temp){
			temp = c[i];
			a[j++] = c[i];
		}
	}
	a[j] = '\0';
}

int count(char* l,char c){
	int i, nums=0;
	for(i=0; l[i] != '\0'; i++){
		if(c == l[i]) nums++;
	}
	return nums;
}

int main(int argc, char const *argv[])
{
	int max = 0, i, nums;
	char index, maxChar;
	char* input= (char*) malloc (sizeof(char) * MaxSize);
	char* help = (char*) malloc (sizeof(char) * MaxSize);
	int maxInt = 0;

	gets(input);
	lower(input);
	sorted(input);
	set(help,input);

	for(i=0; help[i] != '\0'; i++){
		index = help[i];
		if(help[i] >= 'a' && help[i] <= 'z'){
			nums = count(input,help[i]);
			if(nums > maxInt){
				maxChar = help[i];
				maxInt = nums;
			}
		}
	}

	printf("%c %d\n", maxChar,maxInt);
	return 0;
}

// This is a simple TEST.There ARE numbers and other symbols 1&2&3...........
