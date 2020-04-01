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
const int maxN = 1e6 + 2;
bool era[maxN + 2];
int n, x;
void sieve() {
    era[0] = era[1] = 1;
    for (int i = 2; i <= maxN; i++) if (era[i] == 0)
    for (ll j = 1LL * i * i; j <= maxN; j += 1LL * i) era[j] = 1;
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    sieve();
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (era[x] == 0 || era[x-1] == 0 || era[x+1] == 0) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
/** Happy Coding ^^ */

