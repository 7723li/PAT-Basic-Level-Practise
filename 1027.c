#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i,j,k,l=0,m;
	int num,use = 0;
	char s;

	scanf("%d %c", &num,&s);

	for(i=1; use <= num ;i+=2){
		if(i > 1) use += i*2;
		else use += i;
	}
	i -= 2; use -= i * 2; i -= 2;

	j = i;
	for(j; j>0; j-=2){
		for(m=0;m<l;m++){
			printf(" ");
		}
		for(k=0;k<j;k++){
			printf("%c", s);
		}
		l++;
		printf("\n");
	}

	l-=2;
	for(j = 3; j<=i; j+=2){
		for(m=0;m<l;m++){
			printf(" ");
		}
		for(k=0;k<j;k++){
			printf("%c", s);
		}
		l--;
		printf("\n");
	}

	printf("%d\n", num-use);
	
	return 0;
}
