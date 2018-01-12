// 旧键盘
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MaxSize 80+1

bool IsNum(char c){
	if( (int)c >= 48 && (int)c <= 57 ) return true;
	return false;
}

bool IsLetter(char c){
	if( (int)c >= 65 && (int)c <= 90 || 
		(int)c >= 97 && (int)c <= 122 )
		return true;
	return false;
}

bool IsCap(char c){
	if( (int)c >= 65 && (int)c <= 90) return true;
	if( (int)c >= 97 && (int)c <= 122) return false;
}

int main(int argc, char const *argv[])
{
	int i, j = 0;
	char c;
	int letters[26+1] = {0};
	int nums[10+1] = {0};
	char normal[MaxSize], lack[MaxSize];
	// a z A Z 0 9 ( 97 122 65 90 48 57 )
	scanf("%s %s", normal, lack);

	for(i=0; i<strlen(normal); i++){
		if(normal[i] != lack[j]){
			c = normal[i];

			if(IsNum( c )){
				if(!nums[c - '0']){
					printf("%c", c);
					nums[c - '0'] = 1;
				}
			}

			else if(IsLetter( c )){
				if(IsCap( c )){
					if(!letters[c - 'A']){
						printf("%c", c);
						letters[c - 'A'] = 1;
					}
				}
				else{
					if(!letters[c -32 -'A']){
						printf("%c", c - 32);
						letters[c - 32 -'A'] = 1;
					}
				}
			}

			else continue;

		}

		else j++;;
	}
	printf("\n");
	
	return 0;
}

// 7_This_is_a_test
// _hs_s_a_es
