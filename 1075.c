// 链表元素分类
#include <stdio.h>
#include <stdlib.h>

typedef struct Node List;
struct Node
{
	int add;
	int val;
	int next;
};

int main(int argc, char const *argv[])
{
	int i, j;
	int SttAdd, nums, point;
	int posNeg = 0, posPoint, numsNeg = 0;
	List *l, *res;
	struct Node temp;

	scanf("%d %d %d", &SttAdd, &nums, &point);
	posPoint = nums - 1;
	l = (List*) malloc (sizeof(struct Node) * nums);
	res = (List*) malloc (sizeof(struct Node) * nums);

	for(i=0; i<nums; i++){
		scanf("%d %d %d", &l[i].add, &l[i].val, &l[i].next);
		if(l[i].val < 0)
			numsNeg++;
		if(l[i].add == SttAdd){ // 寻找头结点
			temp = l[i];
			l[i] = l[0];
			l[0] = temp;
		}
	}

	// 排序
	for(i=0; i<nums-1; i++){
		for(j=i+1; j<nums; j++){
			if(l[j].add == l[i].next){
				temp = l[i+1];
				l[i+1] = l[j];
				l[j] = temp;
				break;
			}
		}
	}

	// 分类
	for(i=0; i<nums; i++){
		if(l[i].val > point){
			if(posPoint == nums-1){
				res[posPoint--] = l[i];
			}
			else{
				temp = res[posPoint + 1];
				res[posPoint + 1] = l[i];
				res[posPoint--] = temp;
			}
		}
		else if(l[i].val < 0) res[posNeg++] = l[i];
		else res[numsNeg++] = l[i];
	}

	// printf("\n");
	for(i=0; i<nums-1; i++){
		printf("%05d %d %05d\n", res[i].add, res[i].val, res[i+1].add);
	}
	printf("%05d %d -1\n", res[i].add, res[i].val);
	
	return 0;
}

// 输入样例：
// 00100 9 10
// 23333 10 27777
// 00000 0 99999
// 00100 18 12309
// 68237 -6 23333
// 33218 -4 00000
// 48652 -2 -1
// 99999 5 68237
// 27777 11 48652
// 12309 7 33218
// 输出样例：
// 33218 -4 68237
// 68237 -6 48652
// 48652 -2 12309
// 12309 7 00000
// 00000 0 99999
// 99999 5 23333
// 23333 10 00100
// 00100 18 27777
// 27777 11 -1

