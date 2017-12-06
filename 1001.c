#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,step=0;
	do{
		scanf("%d",&n);
	}while(n<=0 || n>1000);

	while(1){
		if(n == 1){
			printf("%d\n", step);
			break;
		}
		if(n%2==0){
			n = n/2;
		}else{
			n = (3*n+1)/2;
			step += 1;
		}
		
	}
	
	return 0;
}
