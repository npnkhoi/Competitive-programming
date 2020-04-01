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
    map<char, int> data;
    char a, b;
    int n;

    data['^'] = 0;
    data['>'] = 1;
    data['v'] = 2;
    data['<'] = 3;
    cin >> a >> b;
    cin >> n;
    n %= 4;
    int res = 0;
    if ((data[a] + n)%4 == data[b]) res = -1;
    if ((data[a] + 4-n)%4 == data[b]) {
        if (res == 0) res = 1;
        else if (res == -1) res = 0;
    }
    if (res == -1) cout << "cw";
    else if (res == 1) cout << "ccw";
    else cout << "undefined";
    return 0;
}
/**/
