using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;

    int x1 = 2*t1 + s*v1;
    int x2 = 2*t2 + s*v2;

    if (x1 < x2) printf("First");
    else if (x1 > x2) printf("Second");
    else printf("Friendship");
    return 0;
}
/**/

