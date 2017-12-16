// 1018. 锤子剪刀布
// printf("%d\n", RAND_MAX);// 32767
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char li[3] = {'C','J','B'};// 锤剪布

int randomInit(){
	static bool isInit = false;
	if(!isInit){
		srand(time(NULL));
		isInit = true;
	}
}

// 随机函数，仅用来测试随机出拳
int randomInteger(int low,int high){
	double d = rand() / (double(RAND_MAX) + 1);
	double s = d * (double(high) - low +1);
	// floor()转换d为小于其函数参数的最大整数
	return int(floor(low + s));
}

int Win(int a,int b){
	if(b-a==1 || (a==2 && b==0)) return 1;// a win
	if(a-b==1 || (b==2 && a==0)) return 2;// b win
	if(a==b) return 3;// peace
}

inline int CtoI(char a){
	if(a=='C'){return 0;}
	else if(a=='J'){return 1;}
	else if(a=='B'){return 2;}
	else return -1;
}

int Most(int* a){
	int b=0,c=0;
	for(int i=0;i<3;i++){
		if(a[i]>b){b = a[i];c=i;}
	}
	return c;
}

int main(int argc, char const *argv[])
{
	int N;// 双方交锋的次数
	int awin=0,bwim=0,peace=0;
	int amost[3];// a出得最多的手势
	int bmost[3];
	char outA[2],outB[2];// 双方出手

	for(int i=0;i<3;i++){amost[i]=0;}// 清0
	for(int i=0;i<3;i++){bmost[i]=0;}

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s %s",outA,outB);
		char a=outA[0],b=outB[0];// 甲乙出手
		int aSer=CtoI(a),bSer=CtoI(b);// 甲乙出手序号
		switch(Win(aSer,bSer)){
			case 1:awin++;amost[aSer]++;break;
			case 2:bwim++;bmost[bSer]++;break;
			case 3:peace++;break;
		}
	}

	for(int i=0;i<3;i++){printf("%d ", amost[i]);}
	printf("\n");
	for(int i=0;i<3;i++){printf("%d ", bmost[i]);}
	printf("\n");

	printf("%d %d %d\n", awin,peace,N-peace-awin);
	printf("%d %d %d\n", bwim,peace,N-peace-bwim);
	printf("%c %c\n", li[Most(amost)],li[Most(bmost)]);

	return 0;
}
