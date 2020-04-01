using namespace std;
#include <bits/stdc++.h>

const int N = 310;
int n, m, res;
map<int, int> posRow, posCol;
int a[N][N], row[N], col[N], hang[N], cot[N];
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);

    int idx = 1;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++, idx++)
        hang[i] += idx,
        cot[j] += idx,
        row[i] += a[i][j],
        col[j] += a[i][j];

    for (int i = 1; i <= m; i++) posRow[row[i]] = i;
    for (int i = 1; i <= n; i++) posCol[col[i]] = i;

    for (int i = 1; i <= m; i++) if (row[i] != hang[i]) {
        res ++;

        if (posRow.find(hang[i]) == posRow.end()) {
            cout << "*";
            return 0;
        }
        int tmp = posRow[hang[i]];
        if (tmp == i) continue;
        posRow[row[i]] = tmp;
        posRow[hang[i]] = i;
        swap(row[i], row[tmp]);
    }

    for (int i = 1; i <= n; i++) if (col[i] != cot[i]) {
        res ++;

        if (posCol.find(cot[i]) == posCol.end()) {
            cout << "*";
            return 0;
        }

        int tmp = posCol[cot[i]];
        if (tmp == i) continue;
        posCol[col[i]] = tmp;
        posCol[cot[i]] = i;
        swap(col[i], col[tmp]);
    }
    cout << res;
}
