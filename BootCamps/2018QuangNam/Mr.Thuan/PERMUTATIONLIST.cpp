// Thinnk carefully ... Are you ready?

#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define ll long long
using namespace std;

void show_arr(int a[], int n)
{
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}
//==================<< END OF TEMPLATE >>========================
ll gt[16];
int n,k;
vector<int> d;
int main()
{

    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) d.push_back(i);
    gt[0]=1;
    for (int i=1;i<=15;i++) gt[i]=gt[i-1]*i;
    //=============================
    if (n<13&&k>gt[n]) printf("-1");
    else while (n)
    {
        n--;
        //printf("n=%d\n",n);
        if (n>12)
        {
            printf("%d ",d[0]);
            d.erase(d.begin());
        }
        else
        {
            int i=1;
            while (i*gt[n]<k)
            {
                i++;
                //cout<<i<<endl;
            }
            printf("%d ",d[i-1]);
            k-=(i-1)*gt[n];
            d.erase(d.begin()+(i-1));
        }
    }
    return 0;
}

// Accepted in one hit, or be a silly dog :))
