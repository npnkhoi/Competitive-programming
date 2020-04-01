using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

const int N = 1e6 + 10;
int prime[N];
void sieve() {
    memset(prime, -1, sizeof prime);
    for (int i = 2; i < N; i++) {
    //cout << i << endl;
    if (prime[i] == -1) {
        prime[i] = 1;
        for (long long j = 1LL*i*i; j < N; j += i) prime[j] = 0;
    } }
}
int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n;
    sieve();
    while (scanf("%d", &n)) {
        if (n == 0) break;
        for (int i = 2; i < N; i++) if (prime[i] && prime[n-i]) {
            printf("%d = %d + %d\n", n, i, n-i);
            break;
        }

    }
    return 0;
}
/**/
