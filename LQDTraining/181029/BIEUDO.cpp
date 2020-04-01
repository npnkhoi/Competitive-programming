#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long oo = 1e18;

int n, a[N], b[N];
long long res = oo;

long long calc(int height) {
	long long s=0;
  for (int i = 1; i <= n; ++i) {
      s += a[i];
  }
  l[1]=1;
  for (int i=2;i<=n;i++) l[i]=min(l[i-1]+1,a[i]);
  r[n]=1;
  for (int i=n-1;i>=1;i--) r[i]=min(r[i+1]+1,a[i]);
  res=0;
  for (int i=1;i<=n;i++) res=max(res,min(l[i],r[i]));
  printf("%lld\n",s-res*res);
}

int main() {
	freopen("BIEUDO.inp", "r", stdin);
	freopen("BIEUDO.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);

	for (int i = 1; i <= 100; ++ i) cerr << calc(x);
}