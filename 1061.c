// 判断题
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int stus, titles;
	scanf("%d %d", &stus, &titles);

	int i;
	int scores[titles], correct[titles];
	for(i=0; i<titles; i++) scanf("%d", &scores[i]);
	for(i=0; i<titles; i++) scanf("%d", &correct[i]);

	int j, temp, sum;
	for(i=0; i<stus; i++){
		temp = 0; sum = 0;
		for(j=0; j<titles; j++){
			scanf("%d", &temp);
			if(temp == correct[j]){
				sum += scores[j];
			}
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
