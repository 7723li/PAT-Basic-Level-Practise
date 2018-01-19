// 统计同成绩学生
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100000

int main(int argc, char const *argv[])
{
<<<<<<< HEAD
	// 典型的空间换时间
	int N, temp, scores[MaxSize] = {0};
	int i;

	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &temp);
		scores[temp]++;
	}
		
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		scanf("%d", &temp);
		if(i < N-1) printf("%d ", scores[temp]);
		else printf("%d\n", scores[temp]);
	}
	
	return 0;
}

// 10
// 60 75 90 55 75 99 82 90 75 50
// 3 75 90 88
=======
  int N, temp, scores[MaxSize] = {0};
  int i;

  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf("%d", &temp);
    scores[temp]++;
  }
    
  scanf("%d", &N);
  for(i=0; i<N; i++) {
    scanf("%d", &temp);
    if(i < N-1) printf("%d ", scores[temp]);
    else printf("%d\n", scores[temp]);
  }
  
  return 0;
}
>>>>>>> 1495b7a6bbbe88818fd4a039a86bee5e77cf9f53
