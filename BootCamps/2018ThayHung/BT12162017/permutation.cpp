#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define task "permutation"

long long gt[25], a[25], y;
vector<int> v;
int n;

void init() {
    gt[0] = 1;
    for (int i = 1; i <= 20; i++) gt[i] = gt[i-1] * i;
}
void solve1() {
    for (int i = 1; i <= n; i++) v.push_back(i);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        res += gt[n - i] * pos;
        //cerr << pos << "\n";
        v.erase(v.begin() + pos);
        //for (int i = 0; i < v.size(); i++) cerr << v[i] << " "; cerr << "\n";
    }
    printf("%lld\n", 1 + res);
}
void solve2() {
    v.clear();
    for (int i = 1; i <= n; i++) v.push_back(i);
    for (int i = n; i >= 1; i--) {
        int tmp;
        for (int j = 0; j < i; j++)
        if (gt[i-1] * j < y) tmp = j;
        y -= gt[i-1] * tmp;
        //cerr << tmp << "\n";
        printf("%d ", v[tmp]);
        v.erase(v.begin() + tmp);
    }
}
int main() {
    init();
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    long long val;
    while (scanf("%lld", &val) != EOF) {
        a[++n] = val;
    }
    y = a[n]; n --;
    solve1();
    solve2();
}
