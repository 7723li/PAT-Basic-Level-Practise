// 火星数字
// http://bbs.csdn.net/topics/110193263
// https://zhidao.baidu.com/question/240273368.html
// https://www.cnblogs.com/linxr/archive/2011/12/28/2304350.html
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define unit 13 // 13进制
#define MaxSize 3 + 1 + 4 // 'tan tret'

int ZeroInt = 0;
char ZeroChar[] = "tret";
// 个位
int BitsInt[unit-1] = {0};
char BitsChar[unit-1][4] = {"jan", "feb", "mar", 
							"apr", "may", "jun", 
							"jly", "aug", "sep", 
							"oct", "nov", "dec"};
// 高位
int HighInt[unit-1] = {0};
char HighChar[unit-1][4] ={"tam", "hel", "maa", 
						   "huh", "tou", "kes", 
						   "hei", "elo", "syy", 
						   "lok", "mer", "jou"};

int judge(char c){
	if(isdigit(c)) return 0; // 数字
	else 
		if(isalpha(c)) return 1; // 英文
	return -1;
}

void EToM(char* c){
	int i, num = 0, pos = 1, lenth = strlen(c);
	int temp, remain;
	for(i=lenth-1; i>=0; i--){
		num +=( c[i] - '0' )* pos;
		pos *= 10;
	}
	if(num > 0){
		if(num > 13){
			if(num % 13){
				temp = num / 13;
				remain = num - temp * unit;
				printf("%s %s\n", HighChar[temp-1], BitsChar[remain -1]);
			}
			else{
				temp = num / 13;
				printf("%s\n", HighChar[temp-1]);
			}
		}
		else if(num == 13){
			printf("%s\n", HighChar[0]);
		}
		else{
			printf("%s\n", BitsChar[num-1]);
		}
	}
	else printf("%s\n", ZeroChar);
	return;
}

void MToE(char* c){
	int i, j = 0, pos = 0;
	char *temp, delims[] = " "; // 根据 " " 分割,str类型的split

	for(i=0; c[i] != '\0'; i++){
		if(c[i] == ' ') pos++; // 判断位数
	}

	temp = strtok(c, delims);
	while(temp){
		if(pos == 0){ // [0,12] 或 13整倍数
			if( strcmp(ZeroChar, temp) == 0 ){
				break;
			}
			else{
				for(i=0; i<unit-1; i++){
					if( strcmp(BitsChar[i], temp) == 0 ){
						j += (i+1); break;
					}
					else if( strcmp(HighChar[i], temp) == 0 ){
						j += (i+1) * 13; break;
					}
				}
			}
		}
		else{
			for(i=0; i<unit-1; i++){
				if( strcmp(HighChar[i], temp) == 0 ){
					j += (i+1) * 13;
					pos--;
					break;
				}
			}
		}
		temp = strtok(NULL, delims);
	}
	printf("%d\n", j);
}

int main(int argc, char const *argv[])
{
	int nums, i;
	char input[MaxSize];

	for(i=0; i<unit-1; i++){
		BitsInt[i] += i+1;
		HighInt[i] += BitsInt[i] * 13;
	}

	scanf("%d", &nums);
	// 在gets之前，做过scanf之类的，
	// scanf处理了数据，却把换行符留在那里没有处理
	// 所以gets得到的就只是一个空行了。
	// 可以用一个while循环，反复gets，直到读出的不是空字串
	for(i=0; i<nums; i++){
		gets(input);
		while (input[0] == 0){ // 判断字符串是否空
			gets(input); // [0, 169)
		}
		switch( judge(input[0]) ){
			case 0: EToM(input);break;
			case 1: MToE(input);break;
		}
	}

	return 0;
}

// 4
// 29
// 5
// elo nov
// tam
