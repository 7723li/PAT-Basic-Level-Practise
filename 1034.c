// 有理数四则运算
#include <stdlib.h>
#include <stdio.h>

void reduction(int* x,int* y){ // 约分
	int a = *x, b = *y;
	if(b % a == 0){
		*x /= a; *
	}
}

void print(int x,int y){
	int a = x, b = y;
	reduction(&a,&b);
	if(a % b == 0){
		if(a / b >= 0) printf("%d", a / b);
		else printf("(%d)", a/b);
	}
	else if(a / b != 0){
		printf("%d %d/%d", a/b, a-(a/b)*b, b);
	}
	else{
		printf("%d/%d", a,b);
	}
}

void count(int a,int b,int c,int d,char mark){
	int left, right;
	if(c % d == 0 && c / d == 0 && mark == '/'){
		printf("Inf");
		return;
	}
	else{
		switch(mark){
			case '+' : 
				left = a * d + b * c;
				right = b * d;
				break;
			case '-' : 
				left = a * d - b * c;
				right = b * d;
				break;
			case '*' : 
				left = a * c;
				right = b * d;
				break;
			case '/' :
				left = a * d;
				right = b * c;
				break;
		}
		print(left,right);
	}
	return;
}

int main(int argc, char const *argv[])
{
	int a,b,c,d;
	int i;
	char marks[] = {'+','-','*','/'};
	scanf("%d/%d %d/%d", &a,&b,&c,&d);

	for(i=0; i<sizeof(marks)/sizeof(marks[0]); i++){
		print(a,b);
		printf(" %c ", marks[i]);
		print(c,d);
		printf(" = ");
		count(a,b,c,d,marks[i]);
		printf("\n");
	}
	
	return 0;
}
