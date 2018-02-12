// 选择题
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 2000

void sorted(char* c){
	int i=2, lenth = strlen(c)-1;
	char temp;
	for(i; i<lenth; i+=2){
		if(c[i] > c[i+2]){
			temp = c[i];
			c[i] = c[i+2];
			c[i+2] = temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, m; // 学生人数和多选题的个数
	scanf("%d %d", &n, &m);

	//满分值,选项个数,正确选项个数
	int scores[m], choice;
	int i, j;
	char list[m][MaxSize];

	for(i=0; i<m; i++){
		scanf("%d %d ", &scores[i], &choice);
		while(true){
			gets(list[i]);
			if(list[i][0] != 0){
				if(list[i][0]-'0' >= choice){
					choice = list[i][0]-'0' + 1;
				}
				sorted(list[i]);
				break;
			}
			
		}
	}

	int wrong[m]; // 每题错的次数
	for(i=0; i<m; i++) wrong[i] = 0;

	int temp = 0, sum = 0, flag = 0;
	char answer[MaxSize];
	const char *split = "(";
	char *p;
	for(i=0; i<n; i++){
		temp = 0; sum = 0;
		gets(answer);
		p = strtok(answer,split);
		while(p != NULL){
			int lenth = strlen(p);
			if(p[lenth-1] == ' ')
				p[lenth-2] = '\0';
			else
				p[lenth-1] = '\0';
			// 全对
			if(!strcmp(p, list[temp++])){
				sum += scores[temp-1];
			}
			// 一个不对则不得分
			else{
				wrong[temp-1]++;
				if(wrong[temp-1] > flag){
					flag = wrong[temp-1];
				}
			}
			p = strtok(NULL,split);
		}

		printf("%d\n", sum);
	}

	if(flag == 0){
		printf("Too simple\n");
	}
	else{
		printf("%d ", flag);
		for(i=0; i<m; i++){
			if(wrong[i] == flag){
				printf("%d", i+1);
				if(i<m-1) printf(" ");
			}
		}
	}
	
	return 0;
}

// 3 4 
// 3 4 2 a c
// 2 5 1 b
// 5 3 2 b c
// 1 5 4 a b d e
// (2 a c) (2 b d) (2 a c) (3 a b e)
// (2 a c) (1 b) (2 a b) (4 a b d e)
// (2 b d) (1 e) (2 b c) (4 a b c d)
