using namespace std;
#include <stdio.h>
#include <bitset>
//#include <bits/stdc++.h>
const int ult = 1e6;
bitset<ult+10> _time;
int n,m,l,r,k;
int main()
{
    //freopen("11926.inp","r",stdin);
    //freopen("11926.out","w",stdout);
    while (1)
    {
        scanf("%d%d",&m,&n);
        if (m==0&&n==0) break;
        //printf("%d %d\n",m,n);
        bool _halt = 0; _time.reset();
        while (m--)
        {
            scanf("%d%d",&l,&r);
            for (int i=l+1;i<=r&&(!_halt);i++)
            if (_time[i])
            {
                printf("CONFLICT\n",i);
                _halt = 1;
            } else _time[i]=1;
        }
        while (n--)
        {
            scanf("%d%d%d", &l, &r, &k);
            while (r<=ult&&(!_halt))
            {
                for (int i=l+1;i<=r&&(!_halt);i++)
                if (_time[i])
                {
                    printf("CONFLICT\n",i);
                    _halt = 1;
                } else _time[i]=1;
                l+=k; r+=k;
            }
        }
        if (!_halt) printf("NO CONFLICT\n");
    }
}
