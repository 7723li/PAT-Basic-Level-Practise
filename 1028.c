// 人口普查
#include <stdio.h>
#include <stdlib.h>

const int today[] = {2014,9,6};

bool reasonable(int y,int m,int d){
	if((today[0] - y > 200) || // 超过200岁
		(y == (today[0] - 200) && m < today[1]) ||
		(y == (today[0] - 200) && m == today[1] && d < today[2]))
		return false;

	if(y > today[0] || // 未出生
		(y == today[0] && m > today[1]) ||
		(y == today[0] && m == today[1] && d > today[2]) ) 
		return false;

	return true;
}

int main(int argc, char const *argv[]){
	int i,;
	int y,m,d;
	int temp,test[2] = {-1};// 前为最老，后为最小
	int old_year = 2014, old_month = 9,old_day = 6;
	int num, effective=0; // 总人数，有效人数
	char (*name)[5+1];

	scanf("%d", &num);

	name = (char(*)[5+1])malloc(sizeof(char*)*num);

	for(i=0; i<num; i++){
		scanf("%s %d/%d/%d",name[i],&y,&m,&d);
		if(reasonable(y,m,d)){
			effective++;
			if(y < old_year ||
				(y == old_year && m < old_month) || 
				(y == old_year && m == old_month && d < old_day)){
				old_year = y;
				old_month = m;
				old_day = d;
				temp = test[0];
				test[0] = i;
				test[1] = temp;
			}
		}
	}

	printf("%d %s %s\n", 
		effective, name[test[0]], name[test[1]]);
	
	free(name);
	return 0;
}

// 5
// John 2001/05/12
// Tom 1814/09/06
// Ann 2121/01/30
// James 1814/09/05
// Steve 1967/11/20
