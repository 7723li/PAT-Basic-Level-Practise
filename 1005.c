#include <stdio.h>
#include <string.h>

int can(int a,int b){
	if(a % 2 == 0){
		a /= 2;
		if(a == b){
			return 1;
		}
	}else{
		a = (a*3+1)/2;
		if(a == b){
			return 1;
		}
	}
}

int main(){
	int length,x,i;
	int input[101];// 输入数组
	int l[101];// 中间数组
	int flag=0;
	scanf("%d",&length);
	for(i=0;i<length;i++){
		scanf("%d",&x);
		input[i]=x;
	}

	// void *memset(void *s,int c,size_t n)
	memset(l,0x00,sizeof(l));// 将已开辟内存空间s的首n个字节的值设为值c

	for(i=0;i<length;i++){
		x = input[i];
		if(l[x] == 1){// 若中间数组的第x位为1，说明x已被之前某数覆盖
			continue;// 则跳过x
		}
		while(x != 1 && x != 0){
			if(x % 2 == 0){
				x /= 2;
			}else{
				x = (x*3+1)/2;
			}
			if(x <= 100){
				// 比如x=3时，中间数组的第5,8,4,2,1位都为1
				l[x] = 1;// x被input[i]覆盖,中间数组的第[x]位存进1
			}
		}
	}
	// 比如题中,经历过上面的遍历后，中间数组的
	// 第1 2 3 4 5 8 10 11 13 17 20 26 40位为1
	for(i=0;i<length;i++){
		if(l[input[i]]==0){
			flag++;// 计算输入数组中不被覆盖的数字数
		}
	}
	for(i=length-1;i>=0;i--){
		if (l[input[i]] != 1){
			printf("%d ", input[i]);
		}
	}
	return 0;
}
