<<<<<<< HEAD
 // 跟奥巴马一起编程
=======
// 跟奥巴马一起编程
>>>>>>> 1495b7a6bbbe88818fd4a039a86bee5e77cf9f53
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
<<<<<<< HEAD
	int column, line, i, j;
	char sharp;

	scanf("%d %c", &column, &sharp);

	if(column % 2){
		line = column / 2  + 1;
	}
	else{
		line = column / 2;
	}

	for(i=0; i<line; i++){

		if(i==0 || i==line-1){
			for(j=0; j<column; j++){
				printf("%c", sharp);
			}
		}

		else{
			for(j=0; j<column; j++){
				if(j==0 || j==column-1){
					printf("%c", sharp);
				}
				else{
					printf(" ");
				}
			}
		}
		if(i<line-1) printf("\n");
	}

	return 0;
=======
  int column, line, i, j;
  char sharp;

  scanf("%d %c", &column, &sharp);

  if(column % 2){
    line = column / 2  + 1;
  }
  else{
    line = column / 2;
  }

  for(i=0; i<line; i++){

    if(i==0 || i==line-1){
      for(j=0; j<column; j++){
        printf("%c", sharp);
      }
    }

    else{
      for(j=0; j<column; j++){
        if(j==0 || j==column-1){
          printf("%c", sharp);
        }
        else{
          printf(" ");
        }
      }
    }
    if(i<line-1) printf("\n");
  }

  return 0;
>>>>>>> 1495b7a6bbbe88818fd4a039a86bee5e77cf9f53
}

// 10 a
