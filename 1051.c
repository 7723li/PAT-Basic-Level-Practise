// 复数乘法
// http://blog.csdn.net/duandianR/article/details/70846638
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
	double R1, P1, R2, P2;
	
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	double _Complex a = R1 * (cos(P1) + I * sin(P1));
	double _Complex b = R2 * (cos(P2) + I * sin(P2));
	double _Complex res = a * b;

	if(cimag(res) < 0)
		printf("%.2f-%.2fi\n", creal(res) , -cimag(res));
	else
		printf("%.2f+%.2fi\n", creal(res) , cimag(res));
	
	return 0;
}

// 输入样例：
// 2.3 3.5 5.2 0.4
// 输出样例：
// -8.68-8.23i
