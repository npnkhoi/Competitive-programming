using namespace std;

#include <iostream>
int a,b,c;
int main() {
    cin >> a >> b >> c;
    if (a+b+c == 2) {
        if (a == 0) cout << "A";
        else if (b == 0) cout << "B";
        else cout << "C";
    }
    else if (a+b+c == 1) {
        if (a == 1) cout << "A";
        else if (b == 1) cout << "B";
        else cout << "C";
    }
    else cout << "*";
}
