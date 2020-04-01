#include <iostream>
using namespace std;

int w;
int main() {
    cin >> w;
    if ((w > 2) && (w % 2 == 0))
        cout << "YES";
    else cout << "NO";
}
