// 图像过滤
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int M, N, A, B, G;
	int temp;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &G);

	if(A > B){
		temp = A;
		A = B;
		B = temp;
	}

	int i, j;
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &temp);
			if(temp >= A && temp <= B)
				if(j < N-1)
					printf("%03d ", G);
				else
					printf("%03d", G);
			else
				if(j < N-1)
					printf("%03d ", temp);
				else
					printf("%03d", temp);
		}
		printf("\n");
	}
	
	return 0;
}

// 输入样例：
// 3 5 100 150 0
// 3 189 254 101 119
// 150 233 151 99 100
// 88 123 149 0 255
// 输出样例：
// 003 189 254 000 000
// 000 233 151 099 000
// 088 000 000 000 255
