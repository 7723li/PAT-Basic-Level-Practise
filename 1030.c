// 完美数列
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int temp;
	int i, j;
	int lenth, p, *list;

	scanf("%d %d", &lenth, &p);
	list = (int*) malloc (sizeof(int) * lenth);

	for(i=0; i<lenth; i++) scanf("%d", &list[i]);

	for(i=0; i<lenth-1; i++){ // 冒泡排序
		for(j=i+1; j<lenth; j++){
			if(list[i] > list[j]){
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
		// for(int k=0; k<lenth; k++){
		// 	printf("%d ", list[k]);
		// }
		// printf("\n");
	}

	i = 0;
	while(true){
		if(list[lenth-1] <= list[i++] * p) break;
	}
	printf("%d\n", lenth - i + 1);

	// for(int k=0; k<lenth; k++){
	// 		printf("%d ", list[k]);
	// 	}
	// printf("\n");

	free(list);
	return 0;
}

// 10 8
// 10 9 8 7 6 5 4 3 2 1
// 10 8
// 2 3 20 4 5 1 6 7 8 9
