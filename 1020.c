// 1020. 月饼 
#include <stdio.h>
#include <stdlib.h>

#define MaxKinds 1000
#define MaxNeeds 500

typedef struct Cake* MoCa;
struct Cake
{
	double Inventory;// 库存量
	double Price;// 总售价
	double avg;// 单价
};

int cmp(const void* a,const void* b){
	return ( (MoCa)b )->Price * ( (MoCa)a )->Inventory - 
		   ( (MoCa)a )->Price * ( (MoCa)b )->Inventory;
}

int main(int argc, char const *argv[])
{
	int N,D;// 种类数，需求数
	int i;double result;
	scanf("%d %d",&N,&D);
	MoCa a = (MoCa)malloc(sizeof(struct Cake)*N);

	for(i=0;i<N;i++) scanf("%lf",&a[i].Inventory);
	for(i=0;i<N;i++){
		scanf("%lf",&a[i].Price);
		a[i].avg=a[i].Price/a[i].Inventory;
	}

	// 18 15 10 		// 15 10 18
	// 75 72 45 		// 72 45 75
	// cmp(a[0],a[1]) --> 72*18 - 75*15 > 0 --> a[1]>a[0]
	// cmp(a[1],a[2]) --> 45*15 - 72*10 < 0 --> a[1]>a[2]
	// cmp(a[2],a[0]) --> 75*10 - 45*17 < 0 --> a[2]>a[0]
	// finally --> a[1] > a[2] > a[0]
	// 即相当于根据 单价 进行大小降序排列
	qsort(a,N,sizeof(struct Cake),cmp);

	i=0;result=0.0;
	while(D>0 && i<N){
		if(D >= a[i].Inventory){
			result += a[i].Price;
			D -= (int)a[i].Inventory;
		}
		else{
			result += a[i].avg*D;
			D = 0;
		}
		i++;
	}
	printf("%0.2lf\n", result);
	free(a);
	
	return 0;
}
