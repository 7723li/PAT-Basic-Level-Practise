// 单身狗
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100000

int main(int argc, char const *argv[])
{
	int N;
	int lovers[MaxSize] = {-1}, guests[MaxSize] = {0};
	scanf("%d", &N);

	int i, a, b;
	for(i=0; i<N; i++){
		scanf("%d %d", &a, &b);
		lovers[a] = b;
		lovers[b] = a;
	}

	int M, temp;
	scanf("%d", &M);
	for(i=0; i<M; i++){
		scanf("%d", &temp);
		guests[temp] = 1;
	}

	int sum = 0, res[MaxSize] = {0};
	for(i=0; i<MaxSize; i++){
		if(guests[i] == 1){ // 在客人名单上
			if(lovers[i] >= 0){ // 在恋人名单上
				if(guests[lovers[i]] == 1){ // 伴侣在客人名单上
					continue;
				}
				else{
					res[sum++] = i;
				}
			}
			else{
				res[sum++] = i;
			}
		}
	}

	printf("%d\n", sum);
	for(i=0; i<sum-1; i++)
		printf("%05d ", res[i]);
	printf("%05d\n", res[sum-1]);
	
	return 0;
}

// 输入样例：
// 3
// 11111 22222
// 33333 44444
// 55555 66666
// 7
// 55555 44444 10000 88888 22222 11111 23333
// 输出样例：
// 5
// 10000 23333 44444 55555 88888
