using namespace std;
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

int val(string str) {
    int s = 0;
    for (int i = 0; i < str.size(); i++)
    s = 10*s + str[i] - '0';
    return s;
}
char str[1123456];
vector<string> a, ans[1123456];
stack<int> task;
int main() {
    scanf("%s", &str);
    for (char *p = strtok(str, ","); p; p = strtok(NULL, ",")) a.push_back(p);

    int n = 0, cur = 0;
    for (int i = 0; i < a.size(); i++) {
        if ('0' <= a[i][0] && a[i][0] <= '9') {
            cur ++;
            n = max(n, cur);
            task.push(val(a[i]));
        }
        else {
            while (!task.empty() && task.top() == 0)
                task.pop(), cur--;
            ans[cur].push_back(a[i]);
            if (!task.empty())task.top() --;
        }
    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ans[i].size(); j++) printf("%s ",ans[i][j].c_str());
        cout << "\n";
    }
}
