// 1019. 数字黑洞 
#include <stdio.h>
#include <stdlib.h>

void sort(char* a,int length,int mod){
	int mid;
	for(int j=0;j<length;j++){
		for(int i=0;i<length-1;i++){
			mid = a[i];
			if(mod==0){
				if(mid>a[i+1]){// 有小到大排序
					a[i] = a[i+1];
					a[i+1] = mid;
				}
			}
			if(mod==1){
				if(mid<=a[i+1]){// 有大到小排序
					a[i] = a[i+1];
					a[i+1] = mid;
				}
			}
		}
	}
	return;
}

inline int Pow(int a,int b){
	int c=1;
	if(b==0 && a!=0) return 1;
	while(b){c *= a;b--;}
	return c;
}

inline void print(int a,int b){
	printf("%d - %04d = %04d\n", b,a,b-a);return;
}

int main(int argc, char const *argv[])
{
	char New[4];
	int a=0,b=0;
	while(true){
		scanf("%s",New);
		for(int i=0;i<4;i++){
			a += (New[i]-'0')*(int)Pow(10,3-i);
		}
		if(a>=1000 && a<10000)break;
		else a=0;
	}
	int length = sizeof(New)/sizeof(New[0]);

	while(true){
		a=0;b=0;
		sort(New,length,0);
		for(int i=0;i<4;i++){
			a += (New[i]-'0')*(int)Pow(10,3-i);
		}

		sort(New,length,1);
		for(int i=0;i<4;i++){
			b += (New[i]-'0')*(int)Pow(10,3-i);
		}

		if(a == b){print(a,b);break;}
		else if(b-a == 6174){print(a,b);break;}
		else print(a,b);

		for(int i=0;i<length;i++){
			if(i==0){
				New[i]=(b-a)/Pow(10,(length-1-i))+'0';
			}
			else{
				New[i]=(b-a)/Pow(10,(length-1-i))%10+'0';
			}
		}
	}

	return 0;
}
