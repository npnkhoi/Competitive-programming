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

int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n, num;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        if (num%2) {
            printf("First");
            return 0;
        }
    }
    printf("Second");
    return 0;
}
/** Happy Coding ^^ */
