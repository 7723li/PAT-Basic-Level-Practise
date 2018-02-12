// 小赌怡情
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int T, K; // 赠送给玩家的筹码数,需要处理的游戏次数
	scanf("%d %d", &T, &K);

	int i;
	int n1, b, t, n2;
	for(i=0; i<K; i++){
		if(T <= 0){
			printf("Game Over.\n");
			break;
		}

		scanf("%d %d %d %d", &n1, &b, &t, &n2);

		if(t > T)
			printf("Not enough tokens.  Total = %d.\n", T);
		else{
			if(n2 < n1){
				if(b == 0){
					T += t;
					printf("Win %d!  Total = %d.\n", t, T);
				}
				else{
					T -= t;
					printf("Lose %d.  Total = %d.\n", t, T);
				}
			}
			else{
				if(b == 1){
					T += t;
					printf("Win %d!  Total = %d.\n", t, T);
				}
				else{
					T -= t;
					printf("Lose %d.  Total = %d.\n", t, T);
				}
			}
		}
	}
	
	return 0;
}
