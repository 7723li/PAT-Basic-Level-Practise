#include <stdio.h>
#include <string.h>

char out(char *str);
int main1();

char inStr[80+1];
char outStrs[40+1][80+1];

int main()
{
	gets(inStr);
	int len = strlen(inStr);
	int wordNum = 0;
	int i, j = 0;
	for (i=0;i<len;i++)
	{
		if (inStr[i] == ' ')
		{
			j = 0;
			wordNum++;
			continue;
		}
		outStrs[wordNum][j++] = inStr[i];
	}
	for (i=wordNum;i>0;i--)
	{
		printf("%s ", outStrs[i]);
	}
	printf("%s\n", outStrs[0]);

	return 0;
}

char out(char *str)
{
    char *p=strchr(str,32);// chr(32)=' '，找到字符串的首个空格
    if(p==NULL)//只有一个元素
    {
        printf("%s",str);
    }
    else
    {
        out(p+1);// 指针向右移一位，即去掉最左的空格
        *p='\0';
        printf(" %s",str);
    }
return 0;
}

int main1(){
	char a[80];
	gets(a);
	out(a);
    return 0;
}

// 函数名称: strchr 
// 函数原型: char *strchr(char *str, char c); 
// 所属库: string.h 
// 函数功能: 查找一个字符c在另一个字符串str中首次出现的位置
// 也就是从str的左侧开始查找字符c首次出现的位置，
// 并返回从字符串中的这个位置起，一直到字符串结束的所有字符。
// 如果未能找到指定字符，那么函数将返回NULL。
