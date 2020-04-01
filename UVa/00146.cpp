using namespace std;
#include <stdio.h>
#include <cstring>
#include <algorithm>
char str[60];
int main()
{
    while (1)
    {
        scanf("%s",&str);
        if (str[0]=='#') break;
        bool ok=0;
        for (int i=1;i<strlen(str);i++) ok|=(str[i]>str[i-1]);
        if (ok)
        {
            next_permutation(str,str+strlen(str));
            printf("%s\n",str);
        }
        else printf("No Successor\n");
    }
}


