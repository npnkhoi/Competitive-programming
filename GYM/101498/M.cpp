using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)

int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%", &tc);
    while (tc--) {
        set<int> data;
        scanf("%d", &n);
        m = n*(n-1)/2;
        REP(i, m) {
            scanf("%d", &a[i]);
            data.insert(a[i]);
        }
        sort(a, a+m);
        p[n] = a[m-1];
        REP(i, m) FOR(j, i+1, m-1) if (a[i] + a[j] == last)
        {   p[2] = a[i]; break; }


    }
    return 0;
}
/** Happy Coding ^^ */
