using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
ll f[100];
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    f[0] = f[1] = 1;
    for (int i = 2; i <= 90; i++) {
        f[i] = f[i-1] + f[i-2];
        cout << f[i] << endl;
    }
    return 0;
}
/** Happy Coding ^^ */

