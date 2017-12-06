#include <stdio.h>
#include <string.h>

int main(){
	int num,i;
	int a,b,c;// 个十百
	scanf("%d", &num);
	if(num>=100){
		a=num%10;
		b=num/10%10;
		c=num/100;
	}else if(num>=10 && num<100){
		c = 0;
		b = num/10;
		a = num%10;
	}else{
		c=0;b=0;
		a = num;
	}
	
	for(i=0;i<c;i++){
		printf("%s", "B");
	}
	for(i=0;i<b;i++){
		printf("%s", "S");
	}
	for(i=0;i<a;i++){
		printf("%d", i+1);
	}

	return 0;
}
