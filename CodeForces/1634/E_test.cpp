/*
Tester
- Input: test.inp
- Code: NAME, NAME_bf
- Output: , test.out , test.ans
- RAND_MAX is around 2^31 - 1
*/

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
using namespace std;

const string NAME = "E";
const int NUM_TEST = 1;

long long Rand(long long l, long long r) {
    assert(l <= r);
    return l + 1LL * rand() * rand() % (r - l + 1);
}

void gen()
{
    ofstream inp("test.inp");
    // Write your input here (inp << ...)
    int n = 1e4;
    int a[n], b[n];
    FOR(i, 0, n-1) {
        int x = Rand(1, 1e9);
        a[i] = b[i] = x;
    }
    random_shuffle(a, a+n);
    random_shuffle(b, b+n);

    inp << "1\n";
    inp << 2 * n << '\n';
    FOR(i, 0, n-1) {
        inp << a[i] << ' ' << b[i] << ' ';
    } 
    inp.close();
}

int main()
{
    srand(time(NULL));

    FOR(i, 1, NUM_TEST)
    {
        gen();
        
        time_t tic, toc;
        time(&tic);
        system(("./" + NAME).c_str());
        time(&toc);
        
        // system(("./" + NAME + "_bf").c_str());
        // if (system("diff test.out test.ans"))
        // {
        //     cerr << "ERORR FOUND!!\n";
        //     return 0;
        // }
        cerr << "Done test " << i << " in " << toc - tic << " (s)\n";
    } 
    cerr << "PASS\n";
}