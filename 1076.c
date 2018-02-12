// Wifi密码
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int nums;
	scanf("%d", &nums);

	int i, j, pos = 0;
	char input[100], psw[200];

	for(i=0; i<nums; i++){
		gets(input);
		while(input[0] == 0)
			gets(input);
		for(j=0; input[j] != '\0'; j++){
			if(input[j] == 'T'){
				psw[pos++] = input[j-2] - 'A' + '1';
				break;
			}
		}
	}
	psw[pos] = '\0';

	printf("%s\n", psw);
	
	return 0;
}

// 8
// A-T B-F C-F D-F
// C-T B-F A-F D-F
// A-F D-F C-F B-T
// B-T A-F C-F D-F
// B-F D-T A-F C-F
// A-T C-F B-F D-F
// D-T B-F C-F A-F
// C-T A-F B-F D-F
