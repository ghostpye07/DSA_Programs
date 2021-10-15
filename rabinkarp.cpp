#include <iostream>
#include <string.h>
using namespace std;
 
#define d 256

void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1;
 
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
 
    for (i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {  
            bool flag = true;
 
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                {
                  flag = false;
                  break;
                }     
            }
    
            if (j == M)
                cout<<"Pattern found at index "<< i<<endl;
        }
 
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if (t < 0)
            	t = (t + q);
        }
    }
}
 
int main()
{
    char txt[100];
    char pat[100];
    int q=101;
	
	cout<<"Enter string: ";
	cin.getline(txt,100);  
	cout<<"Enter pattern to be searched: "; 
    cin.getline(pat,100);
    
    search(pat, txt, q);
    return 0;
}
