/*
* @Author: ReJiKai
* @Date:   2018-11-21 22:01:52
* @Last Modified by:   admin
* @Last Modified time: 2018-11-21 22:58:23
*/
#include <bits/stdc++.h>
using namespace std;

long long n, k, m, a[1000100], s[4];


// long long cal(int i, int j){
// 	if(i > j) return 0;
// 	if(i == j) return mul[i];
// 	if(dp[i][j] != -1) return dp[i][j];
// 	long long res = cal(i, j - 1), tmp = 0;
// 	for(int pos = 1; pos)
// }

int main(){
	scanf("%lld%lld%lld", &n, &k, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) s[1] += a[i];
	for(int i = 1; i <= n; i++) s[2] += a[i] * (s[1] - a[i]); s[2] /= 2;
	for(int i = 1; i <= n; i++) s[3] += a[i] * (s[2] - a[i] * (s[1] - a[i])); s[3] /= 3;
	for(int i = 1; i <= n; i++) s[4] += a[i] * (s[3] - a[i] * (s[2] - a[i] * (s[1] - a[i]))); s[4] /= 4;
	printf("%lld\n", s[4]);
}