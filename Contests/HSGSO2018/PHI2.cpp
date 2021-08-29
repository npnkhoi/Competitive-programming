#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

int phi(int n) {
    cerr << n << " ";
    int res = 1;
    for (int p = 2; p <= sqrt(n); p++) {
        if (n % p == 0) {
            int tmp = 1;
            while (n % p == 0) {
                n /= p;
                tmp *= p;
            }
            res *= tmp / p * (p-1);
            //cerr << p << " " << tmp << "\n";
        }
    }
    if (n > 1) res *= n-1;
    cerr << res << "\n";
    return res;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    long long n;
    cin >> n;
    int res = 0;
    for (int i = n; i <= 4*n*n; i++) if (phi(i) == n) res ++;
    cout << res;
}
