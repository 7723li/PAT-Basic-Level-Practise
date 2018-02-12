// MOOC期终成绩
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 20 + 1

typedef struct stu Class;
struct stu
{
	char ID[MaxSize];
	double score;
};

typedef struct res Achievement;
struct res
{
	char ID[MaxSize];
	int Gpro, Gqizhong, Gqimo, G;
};

double find(char* l, Class c[],int len){
	int i;
	for(i=0; i<len; i++)
		if(strcmp(c[i].ID, l) == 0)
			return c[i].score;
	return -1;
}

int cmp(const void* a, const void* b){
	Achievement c = *(Achievement*)a;
	Achievement d = *(Achievement*)b;
	if(c.G != d.G)
		return d.G - c.G;
	else
		return strcmp(c.ID, d.ID);
}

int main(int argc, char const *argv[])
{
	// 做了在线编程作业 参加了期中考试 参加了期末考试的学生数 
	int P, M, N;
	scanf("%d %d %d", &P, &M, &N);

	int i, pos = 0;
	double tempInt;
	char tempChar[MaxSize];
	Class Gp[P], Gm[M], Gn[N];

	for(i=0; i<P; i++){
		scanf("%s %lf", &tempChar, &tempInt);
		if(tempInt >= 200){
			strcpy(Gp[pos].ID, tempChar);
			Gp[pos++].score = tempInt;
		}
	}

	for(i=0; i<M; i++)
		scanf("%s %lf", &Gm[i].ID, &Gm[i].score);

	for(i=0; i<N; i++)
		scanf("%s %lf", &Gn[i].ID, &Gn[i].score);

	double Gqizhong, Gqimo, G;
	int num = P > M ? P : M, val = 0;
		num = num > N ? num : N;
	Achievement res[num];
	for(i=0; i<pos; i++){
		Gqizhong = find(Gp[i].ID, Gm, M);
		Gqimo = find(Gp[i].ID, Gn, N);
		if(Gqizhong > Gqimo)
			G = Gqizhong * 0.4 + Gqimo * 0.6;
		else
			G = Gqimo;
		if(G >= 60){
			if(G - (int) G >= 0.5)
				G++;
			strcpy(res[val].ID, Gp[i].ID);
			res[val].Gpro = Gp[i].score;
			res[val].Gqizhong = Gqizhong;
			res[val].Gqimo = Gqimo;
			res[val++].G = G;
		}
	}

	qsort(res, val, sizeof(res[0]), cmp);
	for(i=0; i<val; i++){
		printf("%s %d %d %d %d\n", res[i].ID, 
			res[i].Gpro, res[i].Gqizhong,
			res[i].Gqimo, res[i].G);
	}
	
	return 0;
}
