#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int h,m,s;
	int a,b;
	int res;
	while (scanf("%d %d",&a,&b)){
		if(a && b && b>a) break;
	}

	res = (b - a) / 100;
	if( (b - a) % 100 != 0){
		if((b - a) % 100 >= 50) res += 1;
	}

	h = res / 3600; res -= h*3600;
	m = res / 60; res -= m*60;
	s = res;

	printf("%02d:%02d:%02d\n", h,m,s);
	
	return 0;
}
