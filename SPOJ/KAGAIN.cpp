#include <cstdio>
#include <stack>
using namespace std;
const int N = 3e4 + 5;
int a[N], l[N], r[N];
int tc, n;
stack<int> st;
int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        while (!st.empty()) st.pop();
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (st.empty()) l[i] = 0;
            else l[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n; i >= 1; i--) {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (st.empty()) r[i] = n+1;
            else r[i] = st.top();
            st.push(i);
        }

        int res = -1, L, R;
        for (int i = 1; i <= n; i++) {
            if (res < a[i] * (r[i] - l[i] - 1)) {
                res = a[i] * (r[i] - l[i] - 1);
                L = l[i] + 1;
                R = r[i] - 1;
            }
        }
        printf("%d %d %d\n", res, L, R);
    }
}
