#include <stack>
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
string str;
stack<int> st1;
stack<ll> st2;


int main() {
    getline(cin, str);
    ll tmp = 0;
    for (int i = 0; i < str.size(); )
        if (str[i] == 'S') {
            st1.push(1);
            i += 4;
        } else if (str[i] == 'D') {
            st1.push(2);
            i += 4;
        } else if (str[i] == 'M' && str[i+1] == 'A') {
            st1.push(3);
            i += 4;
        } else if (str[i] == 'M' && str[i+1] == 'I') {
            st1.push(4);
            i += 4;
        } else if (str[i] == 'G') {
            st1.push(5);
            i += 4;
        } else if (isdigit(str[i])) {
            tmp = tmp * 10 + str[i] - '0';
            i++;
        } else if (str[i] == ',') {
            st2.push(tmp);
            tmp = 0;
            i++;
        } else if (str[i] == ')') {
            ll tmp0 = st2.top(); st2.pop();
            int Operator = st1.top(); st1.pop();
            if (Operator == 1) tmp = tmp0 + tmp;
            else if (Operator == 2) tmp = tmp0 - tmp;
            else if (Operator == 3) tmp = max(tmp0, tmp);
            else if (Operator == 4) tmp = min(tmp0, tmp);
            else tmp = __gcd(tmp0, tmp);
            i++;
        }
    printf("%lld\n", tmp);
}
