#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isPass(char str[]);

int main()
{
    int n;
    scanf("%d",&n);
    char str[101];
    while(n--)
    {
        scanf("%s",str);
        if( isPass(str) )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

int isPass(char str[])
{
    int positionP = 0,positionT = 0;
    int countP = 0,countA = 0,countT = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == 'P')
        {
            positionP = i;
            countP++;
        }
        else if(str[i] == 'A')
        {
        }
        else if(str[i] == 'T')
        {
            positionT = i;
            countT++;
        }
        else
            return FALSE;
    }
    if( (positionP * (positionT - positionP - 1)) != (strlen(str) - positionT - 1 )
                            || (positionT - positionP) < 2
                            || countT != 1
                            || countP != 1
                            )
            return FALSE; 
    return TRUE;
}
