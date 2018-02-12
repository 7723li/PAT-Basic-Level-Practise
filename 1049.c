// 数列的片段和
#include <stdio.h> 

int main() 
{    
    int N, i;
    scanf("%d", &N);

    double a[N];
    double sum = 0;

    for (i=0; i<N; i++) {
        scanf("%lf", &a[i]);
        sum += (long long int)(N - i) * (i + 1) * a[i];
    }   
    printf("%.2f\n", sum);
    
    return 0;
}
