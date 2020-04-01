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
const int N = 1e5 + 5;
int a[N], cnt[N];
void doi(int i) {
    if (cnt[i] >= 2 || cnt[i+1] >= 2) return;
    else {
        swap(a[i], a[i+1]);
        swap(cnt[i], cnt[i+1]);
        ++ cnt[i]; ++ cnt[i+1];
    }
}
int main() {
    freopen("DEXTERITY.inp", "r", stdin);
    freopen("DEXTERITY.out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n == 1) printf("1\n");
    else if (n == 2) printf("2 1\n");
    else {
        FOR(i, 1, n) scanf("%d", &a[i]);
        FOR(i, 1, n-2) {
            if (a[i] < a[i+2] && a[i+1] < a[i+2] && cnt[i] < 2 &&  cnt[i+1] < 2 && cnt[i+2] == 0) {
                doi(i+1); doi(i);
            } else if (a[i+1] > a[i]) doi(i);
        }
        if (a[n-1] < a[n]) doi(n-1);
        FOR(i, 1, n) printf("%d ", a[i]);
    }
    return 0;
}
/** Happy Coding ^^ */

