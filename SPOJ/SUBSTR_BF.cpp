using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define ll long long
#define ii pair<int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

int main() {
    freopen("substr.inp","r",stdin);
    freopen("substr.ans","w",stdout);
    string a, b;
    cin >> a;
    cin >> b;
    for (int i = 0; i + b.size() - 1 < a.size(); i++)
    {
        bool ok = 1;
        for (int j = 0; j < b.size(); j++) if (a[i+j] != b[j]) {
            ok = 0;
            break;
        }
        if (ok) printf("%d ", i+1);
    }
    return 0;
}
/**/
