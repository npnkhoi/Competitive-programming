#include <bits/stdc++.h>
using namespace std;

int testcase, n;
string str;

int diff(int left_idx, int right_idx, char ch) {
    int ret = 0;
    for (int i = left_idx; i <= right_idx; ++ i) {
        ret += (str[i] != ch);
        // printf("str[i]: %c, ch: %c\n", str[i], ch);
    }
    // printf("diff at %d - %d: %d\n", left_idx, right_idx, ret);
    return ret;
}

int min_move(int left_idx, int right_idx, char ch) {
    if (left_idx == right_idx) {
        return str[left_idx] != ch;
    }
    int mid = (left_idx + right_idx) / 2;

    int result = min(
        min_move(left_idx, mid, ch + 1) + diff(mid + 1, right_idx, ch),
        diff(left_idx, mid, ch) + min_move(mid + 1, right_idx, ch + 1)
    );
    // cerr << result << '\n';
    return result;
}

int main() {
    cin >> testcase;
    while (testcase --) {
        cin >> n >> str;
        cout << min_move(0, n - 1, 'a') << '\n';
    }
}