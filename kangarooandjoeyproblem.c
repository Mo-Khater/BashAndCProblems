#include <stdio.h>
#include<string.h>
#include<ctype.h>
int isjkp(char* s1,char*s2)
{
   if(strlen(s1)==strlen(s2))
    {
        return 0;
    }
    char*kangaroo,*joey;
    if(strlen(s1)>strlen(s2))
    {
        kangaroo=s1;
        joey=s2;
    }
    else
    {
        kangaroo=s2;
        joey=s1;
    }
    int i=0;
    int j=0;
    while (i<strlen(kangaroo)&&j<strlen(joey))
    {
        if(tolower(kangaroo[i])==tolower(joey[j]))
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j==strlen(joey))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
int main(int argc,char*args[])
{
    printf("%d\n",isjkp(args[1],args  [2]));
}