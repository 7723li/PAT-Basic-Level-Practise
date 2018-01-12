#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 10000

int pow(int a,int b){
  int i = a,j = b;
  int k = 1;
  if(j == 0) return 1;
  while(j){ k *= i; j -= 1; }
  return k;
}

void print(char* c,int mark){
  int pos; // 记录'E'的位置
  int pre = 0,j;
  int length = strlen(c);
  int flag = 0; // 0为小数，1为整数
  for(pos=1;pos<length;pos++){
    if(c[pos] == 'E'){
      for(j=length-1;j>=pos+2;j--){
        pre += (c[j]-'0') * pow(10,length-1-j);
      }
      if(c[pos+1] == '-'){
        if(!mark) printf("-0.");
        else printf("0.");
        for(j = 1;j < pre; j++) printf("0");
        break;
      }
      if(c[pos+1] == '+'){ 
        flag = !flag; 
        if(!mark) printf("-"); 
      }
      break;
    }
    else continue;
  }
  // printf("\n%d,%d\n", pos,length);
  if(pos == length){
    if(mark) for(j = 1;j < length;j++) printf("%c", c[j]);
    else printf("%s", c);
    printf("\n");
    return;
  }
  printf("%c", c[1]);
  for(int i = 3;i < pos; i++) printf("%c", c[i]);
  if(flag){
    for(j = 1;j < pre; j++) printf("0");
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  char input[MaxSize];
  while (scanf("%s",input) != EOF){
    switch(input[0]){
      case '-':print(input,0); break;
      case '+':print(input,1); break;
    }
  }
    
  return 0;
}
