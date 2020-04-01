#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<long long> v;
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        long long val;
        scanf("%lld", &val);
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    if (i == 0 || v[i] != v[i-1]) printf("%lld ", v[i]);
}
