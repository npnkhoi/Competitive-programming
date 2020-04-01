#include <cstdio>
#include <utility>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define fi first
#define se second
#define task "peach"

const int N = 1e5 + 5;

int n;
long long res, A, B;
pair<long long, long long> a[N];
stack<long long> st;
priority_queue<long long> heap;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d %lld %lld", &n, &A, &B);
    for (int i = 1; i <= n; ++i) scanf("%lld %lld", &a[i].fi, &a[i].se);
    a[++n] = make_pair(B-1, 0);
    sort(a+1, a+n+1);
    long long pre = A - 1;
    for (int i = 1; i <= n; ++i)
    if (a[i].fi < A) heap.push(a[i].se);
    else {
        st.push(a[i].se);
        if ((A <= a[i].fi && a[i].fi < B) && (i == n || a[i].fi != a[i+1].fi)) {
            for (int j = 1; (j < a[i].fi - pre) && !heap.empty(); j++)
                res += heap.top(), heap.pop();
            while (!st.empty())
                heap.push(st.top()), st.pop();
            res += heap.top(); heap.pop();
            pre = a[i].fi;
        }
    }
    printf("%lld", res);
    return 0;
}
