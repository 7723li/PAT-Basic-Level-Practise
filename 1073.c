// 多选题常见计分法
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool in(char* l, char c){
	for(int i=0; l[i] != '\0'; i++)
		if(c == l[i]) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int N, M; // 学生人数和多选题的个数
	scanf("%d %d", &N, &M);

	int i, j = 0, k;
	int choice, len[M], err[M][5];
	double score[M];
	char answers[M][5+1];
	for(i=0; i<M; i++){
		scanf("%lf %d %d", &score[i], &choice, &len[i]);
		while(getchar() != '\n'){
			if(j == len[i]) break;
			else answers[i][j++] = getchar();
		}
		answers[i][j] = '\0'; j = 0; 
		for(k=0; k<5; k++) err[i][k] = 0;
	}

	double sum = 0.0;
	int l, m, n, max = 0;
	int flag = 0, mark;
	char list[1000], submit[5+1];
	for(i=0; i<N; i++){
		gets(list); flag = 0; sum = 0;
		for(j=0; list[j] != '\0'; j++){
			if(flag == M) break; mark = 0;

			if(list[j] == '(' || list[j] == ' ') continue;
			else if( isdigit(list[j]) ){
				k = 0; l = list[j] - '0';
			}
			else if(list[j] == ')') {
				submit[k] = '\0';
				if(strcmp(submit, answers[flag]) == 0)
					sum += score[flag];
				else{
					for(m=0; m<l; m++){
						if(in(answers[flag], submit[m])){
							if(l < len[flag]){
								mark = 1;
								break;
							}
						}
						else{
							mark = 0;
							err[flag][submit[m] - 'a']++;
							if(err[flag][submit[m] - 'a'] > max)
								max = err[flag][submit[m] - 'a'];
						}
					}
					for(m=0; m<len[flag]; m++){
						if(!in(submit, answers[flag][m])){
							err[flag][answers[flag][m] - 'a']++;
							if(err[flag][answers[flag][m] - 'a']>max)
								max = err[flag][answers[flag][m] - 'a'];
						}
					}
					if(mark == 1){
						sum += score[flag] / 2;
					}
				}
				flag++;
			}
			else
				submit[k++] = list[j];
		}
		printf("%.1lf\n", sum);
	}

	if(max > 0){
		for(i=0; i<M; i++){
			for(j=0; j<5;j++){
				if(err[i][j] == max){
					printf("%d %d-%c\n", max, i+1, 'a'+j);
				}
			}
		}
	}
	else	printf("Too simple\n");
	
	return 0;
}
