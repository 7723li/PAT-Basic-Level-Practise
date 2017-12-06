#include <stdio.h>

int main(){
	int mid;
	int i,j;
	int a,b;
	int l[100];
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++){
		scanf("%d",&l[i]);
	}
	for(i=0;i<b;i++){
		mid = l[a-1];
		for(j=a-2;j>=0;j--){
			l[j+1] = l[j];
		}
		l[0]=mid;
	}
	for(i=0;i<a;i++){
		if(i != a-1){
			printf("%d ", l[i]);
			continue;
		}
		printf("%d", l[i]);
	}
}
