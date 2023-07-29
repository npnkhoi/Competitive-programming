#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
long long board[MAX][MAX], newBoard[MAX][MAX];
vector<long long> arr;
map<long long, int> ideal, actual;
int m, n;

void rotate() {
    // change board, m, n
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            newBoard[i][j] = board[m-1-j][i]; // double check!
        }
    }

    swap(m, n);
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int solve() {
    // cerr << "BOARD:\n";

    int idx = 0;
    for (int s = 0; s <= m + n - 2; s++) {
        for (int i = 0; i <= min(s, m-1); ++i) {
            int j = s - i;
            if (j > n - 1 || board[i][j] == -1) continue;

            // having cell (i, j)
            // printf("considering %d %d\n", i, j);
            ideal[arr[idx]] = s;
            idx ++;
            actual[board[i][j]] = s;
        }
    }
    int ret = 0;
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int val = board[i][j];
            if (val == -1) continue;
            ret += ideal[val] != actual[val];
        }
    }
    // printf("ret = %d\n", ret);
    return ret;
}


int main() {
    // freopen("test.inp", "r", stdin);

    cin >> m >> n; // m = rows!

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] != -1)
                arr.push_back(board[i][j]);
        }
    }

    sort(arr.begin(), arr.end());

    int res = solve();
    for (int i = 1; i <= 3; ++ i) {
        rotate();
        res = min(res, solve());
    }

    cout << res;

    return 0;
}
