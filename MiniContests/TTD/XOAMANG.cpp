using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e5 + 5;
set<int> data;
int a[N], cnt[N];
int n, k;
void push(int x) {
    ++ cnt[x];
    if (cnt[x] == 1) data.insert(x);
    else if (cnt[x] == 2) data.erase(x);
}
void pop(int x) {
    -- cnt[x];
    if (cnt[x] == 1) data.insert(x);
    else if (cnt[x] == 0) data.erase(x);
}
int main() {
    freopen("XOAMANG.inp", "r", stdin);
    freopen("XOAMANG.out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        push(a[i]);
        if (i > k) pop(a[i-k]);
        if (i >= k) {
            if (data.empty()) printf("Nothing\n");
            else printf("%d\n", *data.rbegin());
        }
    }
    return 0;
}
/** Happy Coding :D */
