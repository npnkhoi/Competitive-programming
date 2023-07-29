#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX = 1000;
int board[MAX][MAX];
int correctBoard[MAX][MAX];

signed main() {
    freopen("test.inp", "r", stdin);
    int n; cin >> n;
    vector<int> H(n);
    for(int i = 0; i < n; i++)
        cin >> H[i];

    vector<int> L(n), R(n);
    for(int i = 0; i < n; i++) {
        while(!dq.empty() && H[dq.back()] >= H[j]) {
            dq.pop_back();
        }

        if(dq.empty()) L[j] = 0;
        else L[j] = dq.back() + 1;
        dq.push_back(j);


        dq.clear();
        for(int j = highestTrash; j >= 0; j--) {
            while(!dq.empty() && H[dq.back()] >= H[j]) {
                dq.pop_back();
            }

            if(dq.empty()) R[j] = highestTrash;
            else R[j] = dq.back() - 1;
            dq.push_back(j);
        }
    }

    }

    int maxRectangle = 0;
    for(int i = 1; i <= highestTrash; i++) {
        for(int j = 1; j <= highestTrash; j++) {
            if(board[i][j] == 1) H[j] = H[j] + 1;
            else H[j] = 0;
        }

        deque<int> dq;
        for(int j = 1; j <= highestTrash; j++) {
            while(!dq.empty() && H[dq.back()] >= H[j]) {
                dq.pop_back();
            }

            if(dq.empty()) L[j] = 0;
            else L[j] = dq.back() + 1;
            dq.push_back(j);
        }

        dq.clear();
        for(int j = highestTrash; j >= 0; j--) {
            while(!dq.empty() && H[dq.back()] >= H[j]) {
                dq.pop_back();
            }

            if(dq.empty()) R[j] = highestTrash;
            else R[j] = dq.back() - 1;
            dq.push_back(j);
        }

        for(int j = 1; j <= highestTrash; j++) {
            maxRectangle = max(maxRectangle, (R[j] - L[j] + 1) * H[j]);
        }
    }

    cout << maxRectangle;
    return 0;
}
