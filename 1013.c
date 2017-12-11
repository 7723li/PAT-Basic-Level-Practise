#include <stdlib.h>
#include <stdio.h>
#include <math.h>

inline bool prime(int num){
	if(num == 2){
		return true;
	}
	if(num % 2 == 0){
		return false;
	}
	for(int i=3;i<num;i+=2){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int num=0;
	int line=0;
	int M,N;
	int max = (int)pow(10,4);
	scanf("%d %d",&M,&N);
	for(int i=2;i<max;i++){
		if(prime(i)){
			num++;
			if(line>0 && line%10==0){
				printf("\n");
			}
			if(num >= M && num < N){
				line++;printf("%d ", i);
			}
			if(num == N){
				printf("%d",i);break;
			}
		}
	}
	printf("\n");

	return 0;
}
