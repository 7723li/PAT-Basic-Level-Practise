#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int A,B,D;
	while(scanf("%d %d %d",&A,&B,&D) != EOF){
		if(A>0 && B>0 && D>1 && D<=10) break;
	}
	int sum = A + B;
	int temp = sum;
	int k = 0;
	while(temp){k++;temp /= D;}
	char* li = (char*)malloc(sizeof(char)*k);
	int l = k;
	while(sum){ li[--l] = sum % D; sum /= D; }
	for(int i=0;i<k;i++) printf("%d", li[i]);
	printf("\n");
	free(li);

	return 0;
}
