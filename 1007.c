#include <stdio.h>

int is_prime_number(int num){
	int i = 3;
	if(num == 0 || num == 1 || num % 2 == 0){
		return 0;
	}
	if(num == 2){
		return 1;
	}
	else{
		for(;i<num;i += 2){
			if(num % i == 0){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int i,k=0,N;
	scanf("%d",&N);
	for(i=2;i<=N;i++){
		if(is_prime_number(i) && is_prime_number(i-2)){
			printf("%d,%d\n", i-2,i);
			k++;
		}
		else{
			continue;
		}
	}
	printf("%d\n",k);
}
