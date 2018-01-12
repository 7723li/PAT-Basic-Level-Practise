#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 10

bool IsDigit(char c){
	if( (int)c >= 48 && (int)c <= 57 ) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int weight[18] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int nums, i, j;
	int temp = 0, Z, flag = 1, fin;
	char ID[18];

	scanf("%d", &nums); fin = nums;

	for(i=0; i<nums; i++){
		temp = 0; flag = 1; fin = nums;
		scanf("%s", ID);
		for(j=0; j<17; j++){
			if(! IsDigit( ID[j] ) ){
				flag = 0; break;
			}
			else temp += (ID[j] -'0') * weight[j];
		}
		// printf("%d\n", temp);

		if(flag){ // 前十七位全是数字
			Z = temp % 11;
			if(Z > 1){
				if(ID[17] == 'X'){
					if(X != 12 - Z) fin--;
				}
				else if((ID[17] - '0') != 12 - Z) fin--;
			}
		}
		else{
			printf("%s\n", ID); continue;
		}

		if(fin < nums) printf("%s\n", ID); continue;
	}

	if(fin == nums) printf("All passed\n");
	
	return 0;
}

// 4
// 320124198808240056
// 12010X198901011234
// 110108196711301866
// 37070419881216001X
// 2
// 320124198808240056
// 110108196711301862
