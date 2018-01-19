// 有几个PAT
// 一般方法版
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	char target[] = "PAT";
	char input[100000];
	int lenth = strlen(target);
	int PATList[lenth] ;
	int i, j, k, l;
	int flag = 1, pos = 0, res = 0, temp = 1;
	int test = 1000000007;
	double start ,end;

	scanf("%s", input);
	for(i=0; i<lenth; i++) PATList[i] = 0;

	start = clock();
	for(i=0; input[i] != '\0'; i++){
		// 找 连续 头('P')
		// 找 连续 身('A')
		// 找 全部 尾('T')
		if(input[i] == target[pos]){
			PATList[pos]++;
			pos++;
			for(j=i+1; input[j] != '\0'; j++){

				if(input[j] == target[pos]){
					PATList[pos]++;
					if(input[j+1] != target[pos]){
						pos++;
					}
				}

				if(pos == lenth-1){
					for(l= j+1; input[l] != '\0'; l++){
						if(input[l] == target[pos]){
							PATList[pos]++;
						}
					}
					pos++;
				}

				if(pos == lenth){
					pos = 1;
					for(k=0; k<lenth; k++){
						temp *= PATList[k];
						if(k > 0){
							PATList[k] = 0;
						}
					}
					res += temp;
					temp = 1;
				}
			}
			pos = 0;
			temp = 1;
			PATList[pos] = 0;
		}
	}
	end = clock();
	printf("%.3f\n", (end - start) / CLK_TCK);

	printf("%d\n", res % test);
	
	return 0;
}

// 输入样例：
// APPAPT
// 输出样例：
// 2
// 
// PPATPPPPAAAATTTTPTPAATT
