// a=b*q+r
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str[1000];// 被除数,商
	int n,m=0;// 除数,余数
	scanf("%s %d",&str,&n);
	int length = strlen(str);
	if(length == 1 && str[0]-'0'<n){
		printf("0 %d\n", str[0]-'0');
	}
	else{// 模拟普通除法,在纸上试试如56723/7就可理解
		for(int i=0;i<length;i++){
			if(i>0 && m==0 && str[i]-'0'<n){
				printf("%s", "0");
			}
			m = m*10+str[i]-'0';
			if(m/n>0){
				printf("%d", m/n);
				m=m%n;
			}
		}
		printf(" %d\n", m);
	}
	return 0;
}
