// 卖个萌
#include <stdio.h>

#define MaxSize 10 * 5
#define EmojiSize 5

void get(char l[10][4], int* nums){
	int j = 0, temp = 1;
	char c;
	while(1){
		c = getchar();
		if(c == '\n') return;
		if(c == '['){
			(*nums)++;
			temp = 1;
			j = 0;
		}
		else if(c == ']'){
			l[*(nums)-1][j] = '\0';
			temp = 0;
		}
		else if(temp){
			l[*(nums)-1][j++] = c;
		}
	}
} 

int main(int argc, char const *argv[])
{
	int i, j;
	int HandNums = 0, EyesNums = 0, MouthNums = 0;
	char a[10][4], b[10][4], c[10][4];

	get(a, &HandNums);
	get(b, &EyesNums);
	get(c, &MouthNums);

	int nums;
	scanf("%d", &nums);

	int emojis[EmojiSize], flag;
	for(i=0; i<nums; i++){
		flag = 1;
		for(j=0; j<EmojiSize; j++){
			scanf("%d", &emojis[j]);
			if(j == 0 || j == EmojiSize - 1){
				if(emojis[j] > HandNums || emojis[j] < 1) flag = 0;
			}
			else if(j == 1 || j == EmojiSize - 2){
				if(emojis[j] > EyesNums || emojis[j] < 1) flag = 0;
			}
			else if(j == 2){
				if(emojis[j] > MouthNums || emojis[j] < 1) flag = 0;
			}
		}
		if(flag){
			printf("%s(%s%s%s)%s\n", 
				a[emojis[0] - 1], b[emojis[1] - 1],
				c[emojis[2] - 1], 
				b[emojis[3] - 1], a[emojis[4] - 1]);
		}
		else printf("Are you kidding me? @\\/@\n");
	}
	
	return 0;
}

// [╮][╭][o][~\][/~]  [<][>]
//  [╯][╰][^][-][=][>][<][@][⊙]
// [Д][▽][_][ε][^]
// 4
// 1 1 2 2 2
// 6 8 1 5 5
// 3 3 4 3 3
// 2 10 3 9 3
