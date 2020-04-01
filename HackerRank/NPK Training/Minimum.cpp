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
const int N = 1e6 + 5;
int n, k, a[N], l[N], r[N], ans[N];
stack<int> st;
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        while (!st.empty() && a[st.top()] >= a[i]) {
            if (a[st.top()] > a[i]) r[st.top()] = i;
            else r[st.top()] = -i;
            st.pop();
        }
        if (st.empty()) l[i] = 0;
        else l[i] = st.top();
        st.push(i);
    }
    for (int i = n; i >= 1; i--) {
        if (r[i] == 0) r[i] = n+1;
        else if (r[i] < 0) r[i] = r[-r[i]];
        if (r[i] - l[i] - 1 >= k) ans[max(l[i] + 1, i - k + 1)] = a[i];
    }
    //for (int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << endl;
    int tmp;
    for (int i = 1; i <= n - k + 1; i++) {
        if (ans[i] > 0) tmp = ans[i];
        printf("%d\n", tmp);
    }
    return 0;
}
/** Happy Coding ^^ */

