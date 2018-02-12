// 开学寄语
#include <stdio.h>

int in(int* list, int num, int len){
	for(int i=0; i<len; i++)
		if(num == list[i]) return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);

	int i, abd[M];
	for(i=0; i<M; i++)
		scanf("%d", &abd[i]);

	char name[4+1];
	int j, k, nums, temp;
	int per = 0, sum = 0, stu = 0, tngs[10];
	for(i=0; i<N; i++){
		scanf("%s %d", name, &nums); per = 0;
		for(j=0; j<nums; j++){
			scanf("%d", &temp);
			if(in(abd, temp, M)){
				sum++;
				tngs[per++] = temp;
				if(per == 1)
					stu++;
			}
		}
		if(per > 0){
			printf("%s: ", name);
			for(k=0; k < per-1; k++)
				printf("%04d ", tngs[k]);
			printf("%04d\n", tngs[k]);
		}
	}

	printf("%d %d\n", stu, sum);
	
	return 0;
}

// 输入样例：
// 4 2
// 2333 6666
// CYLL 3 1234 2345 3456
// U 4 9966 6666 8888 6666
// GG 2 2333 7777
// JJ 3 0012 6666 2333
// 输出样例：
// U: 6666 6666
// GG: 2333
// JJ: 6666 2333
// 3 5
