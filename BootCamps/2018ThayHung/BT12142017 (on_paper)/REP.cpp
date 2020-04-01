#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "rep"
const int N = 1e5 + 5;
struct pack{
    int val, pos, type;
};
bool cmp(pack a, pack b) {
    if  (a.val != b.val) return a.val < b.val;
    return a.type < b.type;
}
pack Pack(int val, int pos, int type) {
    pack tmp;
    tmp.val = val;
    tmp.pos = pos;
    tmp.type = type;
    return tmp;
}
vector<pack> v;
vector<int> ans;
set<int> myset;
set<int>::iterator it;
int n, cnt[N];
void addPoint(int u) {
    ans.push_back(u);
    for (it = myset.begin(); it != myset.end(); it++) {
        cnt[*it] ++;
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back(Pack(x, i, 0));
        v.push_back(Pack(y - 1, i, 1));
        v.push_back(Pack(y, i, 2));
    }
    sort(v.begin(), v.end(), cmp);
    REP(i, v.size()) {
        int u = v[i].pos;
        if (v[i].type == 0) {
            myset.insert(u);
        } else if (v[i].type == 1) {
            if (cnt[u] < 1) addPoint(v[i].val);
        } else {
            if (cnt[u] < 2) addPoint(v[i].val);
            myset.erase(u);
        }
    }
    printf("%d\n", (int)ans.size());
    REP(i, ans.size()) printf("%d ", ans[i]);
}
/** Happy Coding :D */
