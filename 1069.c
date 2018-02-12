// 微博转发抽奖
#include <string.h>
#include <stdio.h>

#define MaxSize 20 + 1

int main(int argc, char const *argv[])
{
    int M, N, S;
    scanf("%d %d %d", &M, &N, &S);

    int i;
    char nick[M][MaxSize];
    for(i=0; i<M; i++)
        scanf("%s", nick[i]);

    int flag = 0, j = 0, k, list[M];
    char res[M][MaxSize];
    for(i=0; i<M; i++){
        int val = i + 1 - S;
        if(val >= 0){
            if (val % N == 0 || flag == 1){
                for(k=0; k<j; k++){
                    if(strcmp(nick[list[k]],nick[i])==0){
                        flag = 1;
                        break;
                    }
                    else flag = 0;
                }
                if(flag == 1){
                    continue;
                }
                else{
                    list[j++] = i;
                    flag = 0;
                    S += val % N;
                }    
            }
        }
    }

    if(j > 0)
        for(i=0; i<j; i++)
            printf("%s\n", nick[list[i]]);
    else
        printf("Keep going...\n");

    return 0;
}