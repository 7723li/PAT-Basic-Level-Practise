// 统计同成绩学生
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100000

int main(int argc, char const *argv[])
{
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
