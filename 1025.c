#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node List;
struct Node
{
	int Self;
	int Data;
	int Next;
};

int main(int argc, char const *argv[])
{
	int SttAdd, NodeNums, RevLine;// 起始地址，结点数，反转界线
	int i,j,k;
	List temp; // 临时结点

	scanf("%d %d %d",&SttAdd,&NodeNums,&RevLine);

	List* Nodes=(List*)malloc(sizeof(struct Node)*NodeNums);// 结构数组

	for(i=0; i<NodeNums; i++){ // 输入各个结点
		scanf("%d %d %d", &Nodes[i].Self,&Nodes[i].Data,&Nodes[i].Next);
	}

	for(i=0; i<NodeNums; i++){ // 寻找头结点,并将其放置到数组第一位
		if(Nodes[i].Self == SttAdd){
			temp = Nodes[0];
			Nodes[0] = Nodes[i];
			Nodes[i] = temp;
			break;
		}
	}

	for(i=0; i<NodeNums; i++){ // 排序
		for(j=i+1; j<NodeNums; j++){
			if(Nodes[j].Self == Nodes[i].Next){
				temp = Nodes[i+1];
				Nodes[i+1] = Nodes[j];
				Nodes[j] = temp;
			}
		}
	}

	int RevTims = NodeNums / RevLine; // 反转次数 = 需反转段数
	for(i = 0; i < RevTims; i++){ // 反转
		for(j = i*RevLine; j < i*RevLine + RevLine/2; j++){
			temp = Nodes[j];
			Nodes[j] = Nodes[RevLine*(2*i+1) - j -1];
			Nodes[RevLine*(2*i+1) - j -1] = temp;
		}
	}

	for(i = 0; i< NodeNums-1; i++){ // 改正地址
		Nodes[i].Next = Nodes[i+1].Self;
	}
	Nodes[NodeNums-1].Next = -1;

	// printf("\n");
	for(i=0; i<NodeNums; i++){ // 打印
		if(Nodes[i].Next != -1)
			printf("%05d %d %05d\n", Nodes[i].Self,Nodes[i].Data,Nodes[i].Next);
		else
			printf("%05d %d %d\n", Nodes[i].Self,Nodes[i].Data,Nodes[i].Next);
	}
	
	return 0;
}

// 00100 6 3
// 00000 4 99999
// 00100 1 12309
// 68237 6 -1
// 33218 3 00000
// 99999 5 68237
// 12309 2 33218
