// 计算谱半径
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int nums;
	scanf("%d", &nums);

	int i;
	double a, b, temp;
	double res = 0.0;
	for(i=0; i<nums; i++){
		scanf("%lf %lf", &a, &b);
		temp = sqrt(a*a + b*b);
		if(temp > res) res = temp;
	}

	printf("%.2lf\n", res);
	
	return 0;
}
