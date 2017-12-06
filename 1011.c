#include <stdio.h>
char bool_list[2][10]={"false","true"};

int main(int argc, char const *argv[])
{
	bool a;
	int i,num;
	int j=1;
	scanf("%d",&num);
	int num_list[num*3];
	for(i=0; i<num*3; i+=3){
		scanf("%d %d %d",&num_list[i],&num_list[i+1],&num_list[i+2]);
	}
	for(i=0; i<num*3; i+=3){
		a = (num_list[i]+num_list[i+1]>num_list[i+2]);
		printf("Case #%d: %s\n",j ,bool_list[(int)a]);
		j++;
	}

	return 0;
}
