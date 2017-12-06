#include <stdio.h>

struct student
{
	char name[20];
	char id[20];
	int score;
}temp,max,min;

int main(int argc, char const *argv[])
{
	int num;
	min.score=101;
	max.score=-1;
	scanf("%d",&num);
	while(num--){
		scanf("%s%s%d",temp.name,temp.id,&temp.score);
		if(temp.score>max.score){
			max = temp;
		}
		if(temp.score<min.score){
			min = temp;
		}
	}
	printf("%s %s\n", max.name,max.id);
	printf("%s %s\n", min.name,min.id);

	return 0;
}
