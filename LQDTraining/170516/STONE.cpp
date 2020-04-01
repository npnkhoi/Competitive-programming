#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
    //freopen("STONE.INP","r",stdin);
    //freopen("STONE.OUT","w",stdout);
    int l,k;
    scanf("%d",&k);
    for (int l=2;l<sqrt(k);l++)
    if (k%(l+1)==0) {printf("%d",l); return 0;}
    if ((k>4)&&!(k%2)) printf("%d",k/2-1);
        else printf("%d",k-1);
}
