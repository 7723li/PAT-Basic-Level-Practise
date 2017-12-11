#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char w[7][10]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

	char a[60],b[60],c[60],d[60];
	scanf("%s %s %s %s",a,b,c,d);

	int week=0,pos1=0;
	for(int i=0;i<60;i++){
		pos1++;
		if(a[i]>='A' && a[i]<='Z' && (b[i] == a[i])){
			week=b[i]-'A';
			break;
		}
	}

	int time=0,type=0;
	for(int i=pos1+1;i<60;i++){
		if(a[i]>='A' && a[i]<='Z' && (b[i] == a[i])){
			time=b[i]-'A';
			type=1;
			break;
		}
		else if(a[i]>='a' && a[i]<='z' && (b[i] == a[i])){
			time=b[i]-'a';
			type = 1;
			break;
		}
		else if(a[i]>='0' && a[i]<='9' && (b[i] == a[i])){
			time=b[i]-'0';
			break;
		}
	}

	int pos=0;
	for(int i=0;i<60;i++){
		if (((c[i]>='a' && c[i]<='z') || (c[i]>='A' && c[i]<='Z')) && 
			((d[i]>='a' && d[i]<='z') || (d[i]>='A' && d[i]<='Z')) &&
			(c[i] == d[i])){
			break;
		}
		pos++;
	}

	if(type) time+=10;

	if(pos<10){
		printf("%s %d:0%d\n", w[week],time,pos);
	}else{
		printf("%s %d:%d\n", w[week],time,pos);
	}

	return 0;
}
