using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 25e4 + 10;
const ll md = 65536;
ll num, mul, add;
int n, k;
bitset<N> pos;

int main() {
    //freopen("median.inp","r",stdin);
    //freopen("median.out","w",stdout);
    int TC;
    scanf("%d", &TC);
    FOR(tc, 1, TC) {
        priority_queue<li> hMax;    // Elements before the Median in current segment of length K
        priority_queue<li, vector<li>, greater<li> > hMin; // the rest (include the Median)
        pos.reset();

        scanf("%lld %lld %lld %d %d", &num, &mul, &add, &n, &k);
        int vt = (k+1) / 2;

        for (int i = 1; i <= k; i++){
            hMin.push(mp(num, i));
            num = (num*mul + add) % md;
        }

        for (int i = 1; i < vt; i++) {
            li tmp = hMin.top();
            hMin.pop();

            hMax.push(tmp);
            pos[tmp.se] = 1;
        }

        long long res = hMin.top().fi;
        //cout << res << endl;

        for (int i = k+1; i <= n; i++) {
            hMin.push(mp(num, i));
            num = (num*mul + add) % md;

            if (vt > 1) {
                if (pos[i-k] == 1) {
                    while (hMin.top().se <= i-k) hMin.pop();
                    li tmp = hMin.top(); hMin.pop();
                    hMax.push(tmp); pos[tmp.se] = 1;
                }

                while (1) {
                    while (!hMin.empty() && hMin.top().se <= i-k) hMin.pop();
                    while (!hMax.empty() && hMax.top().se <= i-k) hMax.pop();

                    if (hMin.top().fi < hMax.top().fi) {
                        pos[hMax.top().se] = 0;
                        hMin.push(hMax.top()); hMax.pop();
                        pos[hMin.top().se] = 1;
                        hMax.push(hMin.top()); hMin.pop();
                    }   else break;
                }
            }

            while (hMin.top().se <= i-k) hMin.pop();
            res += hMin.top().fi;
            //cout << res << endl;
        }
        printf("Case #%d: %lld\n", tc, res);
    }
    return 0;
}
/**/
