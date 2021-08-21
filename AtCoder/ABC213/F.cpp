#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    cin >> n >> s;
    vector<int> pi = prefix_function(s);
    
    long long tmp = 0;
    int cnt = 0;

    for (int i = n-1; i >= 0; --i) {
        tmp += cnt - a[i];

        a[i - pi[i] - 1] = pi[i];
        b[i - pi[i] - 1] ++;
    }
}