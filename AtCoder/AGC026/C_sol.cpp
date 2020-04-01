#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll gcd(ll x,ll y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll A,B,C,D;
		scanf("%lld %lld %lld %lld",&A,&B,&C,&D);
		if(A<B) puts("No");
		else
		{
			A%=B;
			ll g=gcd(B,D);
			if(A%g+D<B) puts("No");
			else
			{
				if(A%g==0)
				{
					if(C<B-g) puts("No");
					else puts("Yes");
				}
				else
				{
					ll lim=A+(B-A)/g*g;
					if(C<lim) puts("No");
					else puts("Yes");
				}
			}
		}
	}
	return 0;
}
