#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char c[101];
	char pinyin[][9]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int a[10];
	int i,n=0,t=0;
	gets(c);//读入一串字符。这里实际上是数据，但是由于是char类型的，由ASCII码可以进行转换
	for(i=0;i<strlen(c);i++){
		n = n + c[i]-'0';//当成字符类型读入时转换成数字类型要减去0的ASCII码
	}
	while(n!=0){
		a[t]=n%10;
		n=n/10;
		t++;
	}
	printf("%s ", pinyin[a[t-1]]);
	for(i=t-2;i>=0;i--){
		printf("%s",pinyin[a[i]]);
	}
	return 0;
}
