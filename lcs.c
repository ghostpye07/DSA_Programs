#include <stdio.h>
#include <string.h>

int main()
{
    int j;
    char str1[50], str2[50];
    scanf("%s %s", str1, str2);
    
    int len1, len2;
    len1=strlen(str1) + 1;
    len2=strlen(str2) + 1;
    
    int lcs[len1][len2];
    
    for (int i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            if(i==0 || j==0)
            {
                lcs[i][j]=0;
            }
            else
            {
                if(str1[i-1]==str2[j-1])
                {
                    lcs[i][j]= 1+lcs[i-1][j-1];
                }
                else if(lcs[i-1][j]>lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i-1][j];
                }
                else
                {
                    lcs[i][j]=lcs[i][j-1];
                }
            }
        }
    }
    
    if (len1<len2 && (len1-1==lcs[len1-1][j-1]))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
    return 0;
}