using namespace std;
#include <stdio.h>
#include <vector>
#include <algorithm>

const int N = 110;
int f, r, a[N], b[N];
vector<float> v;

int main() {
    //freopen("test.out", "w", stdout);
    while (1) {
        scanf("%d", &f);
        if (f == 0) break;
        scanf("%d", &r);
        for (int i = 1; i <= f; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= r; i++) scanf("%d", &b[i]);
        v.clear();
        for (int i = 1; i <= f; i++)
        for (int j = 1; j <= r; j++) v.push_back(a[i] / (float) b[j]);
        sort(v.begin(), v.end());
        float res = 0;
        for (int i = 1; i < v.size(); i++) res = max(res, v[i]/v[i-1]);
        printf("%.2f\n", res);
    }
}
