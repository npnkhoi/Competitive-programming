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
const int N = 2e5 + 5;
const int sh = 1e5 + 1;
vector<int> v[N];
char s[N];
int a[N], r[N];

int main() {
    freopen("SUBP.inp", "r", stdin);
    freopen("SUBP.out", "w", stdout);
    scanf("%s", s+1);
    int n = strlen(s+1);
    v[sh].push_back(0);
    FOR(i, 1, n) {
        if (s[i] == '(') a[i] = a[i-1] + 1;
        else  a[i] = a[i-1] - 1;
        v[sh+a[i]].push_back(i);
    }

    stack<int> st;
    FORD(i, n, 0) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) r[i] = n+1;
        else r[i] = st.top();
        st.push(i);
    }

    int res = 0;
    FOR(i, 0, n) {
        int tmp = sh + a[i];
        if (v[tmp].size() < 2) continue;
        /// phan tu lon nhat trong v[a[i]] thuoc khoang (i, r[i])
        int pos = upper_bound(v[tmp].begin(), v[tmp].end(), r[i] - 1) - v[tmp].begin() - 1;
        if (pos >= 0 && v[tmp][pos] != i) res =  max(res, v[tmp][pos] - i);
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
