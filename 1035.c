// 插入与归并
#include <stdio.h>
#include <stdlib.h>

int *list1, *list2;
int nums;

bool same(const int* a,const int* b){
	for(int i=0; i<nums; i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
}

void print(const int* a){
	for(int i=0; i<nums-1; i++)
		printf("%d ", a[i]);
	printf("%d\n",a[nums-1]);
}

void Insert(int*c, int possm, int posbi){ // small,big
	int temp = c[possm], i;
	for(i=possm; i>posbi; i--){
		c[i] = c[i-1];
	}
	c[posbi] = temp;
}

void Insertion(int* c, int* flag, int* pos){
	int  i ,j;
		for(i = *pos; i<nums; i++){
		for(j=0; j<i; j++){
			if(c[i] < c[j]){
				Insert(c, i, j);//将i位置的值插入到j中
				break;
			}
		}
		if(! (*flag)){
			if(same(c,list2)){
				*flag = 1;
				*pos = i+1;
				return;
			}
		}
		else return;
		
	}
}

void Merge(int* c,int pos){
	int i, j, k;
	int temp;
	int range = nums / pos * pos;
	for(i=0; i<range; i += pos){
		for(j=i; j<i+pos; j++){
			for(k=i; k<j; k++){
				if(c[j] < c[k]){
					temp = c[j];
					c[j] = c[k];
					c[k] = temp;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int i;
	int *temp, flag = 0, pos = 1;

	scanf("%d", &nums);
	list1 = (int*) malloc (sizeof(int) * nums);
	list2 = (int*) malloc (sizeof(int) * nums);
	temp = (int*) malloc (sizeof(int) * nums);

	for(i=0; i<nums; i++) scanf("%d", &list1[i]);
	for(i=0; i<nums; i++) scanf("%d", &list2[i]);
	
	for(int i=0; i<nums; i++) temp[i] = list1[i];
	Insertion(temp, &flag, &pos);// 为0时判断，为1时发生一次插入
	if(flag){
		Insertion(temp, &flag, &pos);
		printf("Insertion Sort\n");
		print(temp);
	}
	
	else{
		pos = 2;
		while(true){
			Merge(list1,pos);
			// print(list1);
			if( same(list1, list2) ) break;
			if(nums / pos == 1) pos = nums;
			else pos *= 2;
		}
		if(nums / pos == 1) pos = nums;
		else pos *= 2;
		Merge(list1,pos);
		printf("Merge Sort\n");
		print(list1);
	}

	free(temp); free(list1); free(list2);
	return 0;
}

// 输入样例1：
// 10
// 3 1 2 8 7 5 9 4 6 0
// 1 2 3 7 8 5 9 4 6 0
// 输出样例1：
// Insertion Sort
// 1 2 3 5 7 8 9 4 6 0
// 输入样例2：
// 10
// 3 1 2 8 7 5 9 4 0 6
// 1 3 2 8 5 7 4 9 0 6
// 输出样例2：
// Merge Sort
// 1 2 3 8 4 5 7 9 0 6
