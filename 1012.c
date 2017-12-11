#include <stdio.h>
#include <stdlib.h>

void printN(int flag_N){
	if(!flag_N) printf("%s ", "N");
	else printf("%s", "N");
}

int choose(int i){
	if(i % 10 == 0) return 1;
	else if(i % 5 == 1) return 2;
	else if(i % 5 == 2) return 3;
	else if(i % 5 == 3) return 4;
	else if(i % 5 == 4) return 5;
}

int main(int argc, char const *argv[])
{
	int a1=0,a2=0,a3=0,a5;
	double a4=0,l_a4=0;
	int flag=0;// 用于判断a2进行加还是减
	int max=0;// 用于取出a5的最大值
	int flag_N=0;
	int length;
	scanf("%d",&length);
	int list[length];
	for(int i=0;i<length;i++){
		scanf("%d",&list[i]);
	}
	for(int i=0;i<length;i++){
		switch(choose(list[i])){
			case 1:a1 += list[i];break;
			case 2:
				if(!flag){ a2 += list[i];flag=1; }
				else{ a2 -= list[i];flag=0; }
				break;
			case 3:a3 += 1;break;
			case 4:a4 += list[i];l_a4 += 1;break;
			case 5:
				if(list[i] > max){max = list[i];a5 = max;}
				break;
		}
	}

	if(a1){printf("%d ", a1);}else printN(flag_N);
	if(a2){printf("%d ", a2);}else printN(flag_N);
	if(a3){printf("%d ", a3);}else printN(flag_N);
	if(a4){printf("%.1f ", a4/l_a4);}else printN(flag_N);
	flag_N = 1;
	if(a5){printf("%d", a5);}else printN(flag_N);
	printf("\n");

	return 0;
}
