// 考试座位号
#include <stdlib.h>
#include <stdio.h>

#define lenth 14

int main(int argc, char const *argv[])
{
	int nums, i, j;
	int wait, temp;
	char aa[lenth+1];

	scanf("%d", &nums);
	char IDs[nums][lenth+1];
	int testIDs[nums],examIDs[nums];

	for(i=0; i<nums; i++){
		scanf("%s %d %d", IDs[i], &testIDs[i], &examIDs[i]);
	}

	scanf("%d", &temp);
	for(i=0; i<temp; i++){
		scanf("%d", &wait);
		for(j=0; j<nums; j++){
			if(testIDs[j] == wait){
				printf("%s %d\n", IDs[j], examIDs[j]);
			}
		}
	}

	return 0;
}

// 输入样例：
// 4
// 10120150912233 2 4
// 10120150912119 4 1
// 10120150912126 1 3
// 10120150912002 3 2
// 2
// 3 4
// 输出样例：
// 10120150912002 2
// 10120150912119 1
