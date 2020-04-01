#include <bits/stdc++.h>
using namespace std;

const double VAL = 2e9;
const int N = 1e5+8;

typedef pair <int, int> ii;
typedef pair <double, ii> di;
#define fi first
#define se second

int t,n,m, a[N];

bool comp(int a, int b)
{
	return a < b;
}

int main()
{
	scanf("%d", &t);

	while (t--) {
		priority_queue <di> pq;
		//double res = 0;

		scanf("%d%d", &n, &m);
		
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a+1, a+1+n, comp);

		for (int i = 2, x; i <= n; i++) {
			//res = max(res, (double) a[i] - a[i-1]);
			pq.push(di(a[i] - a[i-1], ii(a[i] - a[i-1], 1)));
		}

		for (int i = 1; i <= m; i++) {
			double val; //= pq.top().fi;
			int org = pq.top().se.fi,
				cnt = pq.top().se.se;
			pq.pop();

			++cnt;
			val = (double) org / cnt;
			pq.push(di(val, ii(org, cnt)));
			//res = max(res,val);
		}

		printf("%f\n", pq.top().fi);
	}

	return 0;
}