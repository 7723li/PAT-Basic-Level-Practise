// 最简分数
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 1000

int main(int argc, char const *argv[])
{
	double a1, b1, a2, b2, k;
	scanf("%lf/%lf %lf/%lf %lf", &a1, &b1, &a2, &b2, &k);

	int temp = (int)k;
	int i, j=0, list[MaxSize] = {0};

	if(temp < k) ++temp;
	for(i=2; i<temp; i++){
		if(temp % i == 0){
			list[j++] = i;
		}
	}

	double res1 = a1 / b1;
	double res2 = a2 / b2;

	int down = (res1 < res2 ? res1 : res2) * k;
	int up = (res1 > res2 ? res1 : res2) * k;

	if(res1 * k - down > 0) down++; // 下限向上取整

	int min = -1, max = -1, l, flag = 0;
	for(i=down; i<=up; i++){
		flag = 0;
		for(l=0; l<j; l++){
			if(i % list[l] == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			if(min == -1){
				min = i;
				printf("%d/%.0lf", min, k);
			}
			else{
				if(i > max){
					max = i;
				}
			}
		}
	}

	if(max > 0){
		printf(" %d/%.0lf", max,k);
	}
	printf("\n");
	
	return 0;
}

// 输入样例：
// 7/18 13/20 12
// 输出样例：
// 5/12 7/12

// 2/13 4/5 9
