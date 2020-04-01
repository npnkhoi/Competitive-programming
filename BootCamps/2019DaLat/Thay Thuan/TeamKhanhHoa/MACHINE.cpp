#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int MAX_X = 3e6;

int n, maxLen[MAX_X + 5], res;
vector<int> head[MAX_X + 5];

// void in(int &num){bool neg=0;num=0;char c=getchar();if(c=='-'){neg=1,c=getchar();}for(;(c>47&&c<58);c=getchar()){num=num*10+c-48;}if(neg)num*=-1;} 
// void in(long long &num){bool neg=0;num=0;char c=getchar();if(c=='-'){neg=1,c=getchar();}for(;(c>47&&c<58);c=getchar()){num=num*10+c-48;}if(neg)num*=-1;} 
  
int main() {
	// freopen("Test8.inp", "r", stdin);
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	scanf("%d", &n);
	// in(n);
	// cin >> n;

	for (int i = 1; i <= n; ++ i) {
		int l, r;
		scanf("%d%d", &l, &r);
		// cin >> l >> r;
		// in(l); in(r);
		head[r].push_back(l);
	}
	for (int r = 1; r <= MAX_X; ++ r) {
		maxLen[r] = maxLen[r - 1];
		for (int l : head[r]) {
			// cerr << "l r: " << l << " " << r << "\n";
			// cerr << maxLen[r] << " " << maxLen[l-1] << "\n";
			maxLen[r] = max(maxLen[r], r - l);
			if (maxLen[l - 1] > 0) res = max(res, r - l + maxLen[l-1]);
		}	
		// if (r == 12) break;
	}
	if (res == 0) 
		printf("-1");
		// cout << -1;
	else 
		printf("%d", res);
		// cout << res;
}