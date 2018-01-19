// 在霍格沃茨找零钱
#include <stdio.h>
#include <stdlib.h>

// 17Knut -> 1Sickle, 19Sickle -> 1Galleon
int SickleToKnut = 19;
int GalleonToSickle = 17;
int GalleonToKnut = SickleToKnut * GalleonToSickle;

int main(int argc, char const *argv[])
{
 	int Knutp, Sicklep, Galleonp; // 应付
 	int Knuta, Sicklea, Galleona; // 实付
 	int p, a, change;

 	scanf("%d.%d.%d", &Galleonp, &Sicklep, &Knutp);
 	scanf("%d.%d.%d", &Galleona, &Sicklea, &Knuta);

 	p = Galleonp * GalleonToKnut + Sicklep * SickleToKnut + Knutp;
 	a = Galleona * GalleonToKnut + Sicklea * SickleToKnut + Knuta;
 	change = a - p;

 	if(change < 0){
 		change = -change;
 		printf("-%d.", change / GalleonToKnut);
 	}
 	else{
 		printf("%d.", change / GalleonToKnut);
 	}
 	change -= change / GalleonToKnut * GalleonToKnut;
 	printf("%d.", change / SickleToKnut);
 	change -= change / SickleToKnut * SickleToKnut;
 	printf("%d\n", change);
	
	return 0;
}

// 输入样例1：
// 10.16.27 14.1.28
// 输出样例1：
// 3.2.1
// 输入样例2：
// 14.1.28 10.16.27
// 输出样例2：
// -3.2.1
