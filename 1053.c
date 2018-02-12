// 住房空置率
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, j;
	int N, D;
	int K = 0, temp = 0, flag = 0;
	double days = 0.0;
	double sum, e, res[2] = {0.0};

	scanf("%lf %lf %d", &sum, &e, &D);

	N = (int)sum;
	if(sum - N >= 0.5) N += 1;

	for(i=0; i<N; i++){
		scanf("%d", &K);
		temp = 0;
		flag = 0;

		for(j=0; j<K; j++){
			scanf("%lf", &days);
			if(days < e){
				temp++;
			}
			if(temp && K / temp == 1){
				flag = 1;
			}
		}

		if(flag){
			if(K > D) res[1] += 100.0;
			else res[0] += 100.0;
		}
	}

	printf("%.1lf%c %.1lf%c\n", res[0]/sum, '%', res[1]/sum, '%');
	
	return 0;
}

// 输入样例：
// 5 0.5 10
// 6 0.3 0.4 0.5 0.2 0.8 0.6
// 10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
// 5 0.4 0.3 0.5 0.1 0.7
// 11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
// 11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1
// 输出样例：
// 40.0% 20.0%
