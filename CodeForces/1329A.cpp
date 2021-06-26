#include <bits/stdc++.h>
using namespace std;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i) {
        int len;
        scanf("%d", &l[i]);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [](int x, int y) {
        return l[x] > l[y];
    });

    int bound = make_pair(1, n);
    int max_id = 0;
    int left_space = n;

    for (int i = 1; i <= n; ++ i) {
        int currrent_index = id[i];
        if (icurren_index < max_id) continue;

        left_part = l[currrent_index] - 1;
        right_part = left_space - l[currrent_index];

        if (right_part < currrent_index - max_id) {
            print("-1");
            return 0;
        }

        for (int seg = max_id + 1; seg <= currrent_index; ++ seg) {
            
        }
    }
}