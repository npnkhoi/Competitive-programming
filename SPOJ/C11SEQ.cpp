#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, l, r;
vector<long long> p;
long long s[N], ft[3*N], res;
map<long long, int> id;
void update(int p) {
    //printf("update %d (m=%d)\n", p, m);
    for (; p <= m; p += p&(-p)) {
        ft[p]++;
        //cout << p << endl;
    }
    //cout << "\n";
    //cout << "0\n";
}
long long rsq(int p) {
    //cout << "1";
    long long res = 0;
    for (; p > 0; p -= p&(-p)) res += ft[p];
    //cout << "0\n";
    return res;
}
long long rsq(int l, int r) {
    return rsq(r) - rsq(l-1);
}

int main() {
    scanf("%d %d %d", &n, &l, &r);
    p.push_back(0);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]);
        s[i] += s[i-1];
        p.push_back(s[i]);
        p.push_back(s[i]-l);
        p.push_back(s[i]-r);
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); i++)
    if (id.find(p[i]) == id.end()) {
        id[p[i]] = ++m;
        //printf("id[%lld] = %d\n", p[i], m);
    }
    //printf("map size: %d\n", m);
    update(id[0]);
    for (int i = 1; i <= n; i++) {
        res += rsq(id[s[i]-r], id[s[i]-l]);
        update(id[s[i]]);
        //printf("%d %d - %d\n", id[s[i]-r], id[s[i]-l], id[s[i]]);
        //for (int i = 1; i <= m; i++) printf("%lld ", ft[i]); cout << endl;
    }
    //cout << rsq(4) << endl;
    printf("%lld\n", res);

}
