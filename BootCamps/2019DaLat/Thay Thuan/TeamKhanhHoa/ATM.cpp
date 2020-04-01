#include <bits/stdc++.h> 
using namespace std; 
  
int t, c; 
long long w; 
  
long long pow(int x){ 
    long long res = 1; 
    for(int i = 0; i < x; i++){ 
        res *= 10; 
    } 
    return res; 
} 
  
int main(){ 
    cin >> t; 
    while(t--){ 
        cin >> w >> c; 
        if(w % 1000) cout << "0\n"; 
        else{ 
            long long res = 0, ways = 1; 
            w /= 1000; 
            int l = log(w) / log(10); 
            l = min(l, c); 
            long long base = pow(l); 
            while(w){ 
                // cout << base << endl; 
                long long cnt5 = w / (5 * base); 
                w %= 5 * base; 
                long long cnt3 = w / (3 * base); 
                w %= 3 * base; 
                long long cnt2 = w / (2 * base); 
                w %= 2 * base; 
                long long cnt1 = w / (base); 
                w %= base; 
                long long tmp = 1; 
                tmp += min(cnt5, cnt1) + min(cnt3, cnt1); 
                ways *= tmp; 
                // cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt5 << endl; 
                res += cnt5 + cnt3 + cnt2 + cnt1; 
                base /= 10; 
            } 
            cout << res << " " << ways << endl; 
        }  
    } 
}