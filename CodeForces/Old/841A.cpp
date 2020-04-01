using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

int n, k;
int cnt[30];
int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        char ch;
        scanf(" %c", &ch);
        int t = ch - 'a';
        cnt[t] ++;
        if (cnt[t] > k) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
/** Happy Coding ^^ */
