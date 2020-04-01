using namespace std;
#include <stdio.h>
#include <map>

typedef pair<double, double> pd;
struct point {
    double X, Y;
};
map<pd, int> data;

int main() {
    bool res = 1;
    point a, b;

    for (int i = 1; i <= 3; i++) {
        scanf("%f %f", &a.X, &a.Y);
        scanf("%f %f", &b.X, &b.Y);
        if (a.X == b.X && a.Y == b.Y) res = 0;

        pd tmp = make_pair(a.X, a.Y);
        if (data.find(tmp) == data.end()) data[tmp] = 1;
        else if (data[tmp] == 2) res = 0;
        else data[tmp]++;
    }

    if (res && data.size() == 3) printf("It's a Triangle\n");
    else printf("It's not a triangle\n");

}
