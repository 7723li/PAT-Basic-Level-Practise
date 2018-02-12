// 爱丁顿数
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[])
{
	int days;
	scanf("%d", &days);

	int list[days], i;
	for(i=0; i<days; i++) scanf("%d", &list[i]);
	qsort(list,days,sizeof(list[0]),cmp);

	// for(i=0; i<days; i++) printf("%d\n", list[i]);
	for(i=0; i<days; i++){
		if(list[i] > days-i){
			break;
		}
	}
	
	printf("%d\n", days-i);
	
	return 0;
}

// 10
// 6 7 6 9 3 10 8 2 7 8
