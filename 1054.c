// 求平均值 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MaxSize 1000

double trans(char *c, int *nums, int* flag, int *pos){
	int i, j, dots = 0; // dots 小数点
	double temp = 0.0, val = 0.0, dec = 0.0; // dec 小数

	if(c[0] == '-') i = 1;
	else i = 0;
	j = i;

	for(i; c[i] != '\0'; i++){
		if(c[i] == '.'){
			dots++;
			if(dots > 1 || i == j || c[i+1] == '\0'){
				(*flag) = 1;
				(*nums)--;
				return 0;
			}
		}
		else if(!isdigit(c[i])){ // 除小数点与数字以外的符号
			(*flag) = 1;
			(*nums)--;
			return 0;
		}
		else{
			if(val == 0) val += c[i] -'0';
			else{
				if(!dots){ // 未遇到小数点
					val *= 10;
					val += c[i] -'0';
					if(val > 1000 || val < -1000){
						(*flag) = 1;
						(*nums)--;
						return 0;
					}
				}
				else{
					if(dec == 0){
						dec += c[i] - '0';
						(*pos)++;
					}
					else{
						dec *= 10;
						dec += c[i] -'0';
						if(dec > 99){ // 两位小数,小数位最大为99
							(*flag) = 1;
							(*nums)--;
							return 0;
						}
						(*pos)++;
					}
				}
			}
		}
	}

	if(dec > 9) val += dec / 100;
	else val += dec / 10;
	if(j) val *= -1;
	(*flag) = 0;
	return val;
}

int main(int argc, char const *argv[])
{
	int nums, temp, i, flag = 0, pos = 0;
	scanf("%d", &nums);
	temp = nums;

	double sum = 0.0, val;
	char input[MaxSize];
	for(i=0; i<nums; i++){
		scanf("%s", input);
		val = trans(input, &temp, &flag, &pos);
		if(flag)
			printf("ERROR: %s is not a legal number\n", input);
		else sum += val;
	}

	if(temp == 1){
		printf("The average of %d number is ", temp);
		switch(pos){
			case 0: printf("%.0lf\n", sum); break;
			case 1: printf("%.1lf\n", sum); break;
			case 2: printf("%.2lf\n", sum); break;
		}
	}
	else if(temp > 1)
		printf("The average of %d numbers is %.2lf\n", temp, sum / temp);
	else
		printf("The average of %d numbers is Undefined\n", temp);
	
	return 0;
}
