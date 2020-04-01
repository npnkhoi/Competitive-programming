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
int a[15];
int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);

    int k, res;
    string str;

    scanf("%d", &k);
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        int x = str[i] - '0';
        a[x]++;
        k -= x;
    }

    res = 0;

    for (int i = 0; i <= 9 && k > 0; i++) {
        int t = (9-i) * a[i];
        if (k < t) {
            res += (k + 8 - i) / (9-i);
            break;
        } else k -= t, res += a[i];
    }

    printf("%d", res);

    return 0;
}
/**/
