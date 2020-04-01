#include <bits/stdc++.h>
using namespace std;
 
vector<int> euler(1000003, -1), primes;
 
//Generate primes and also calculate the euler number
void genprime()
{
 	for(int i = 2;i<=1000002;i++)
 	{
 		if(euler[i]==-1)
 		{
 			primes.push_back(i);
 			euler[i] = i-1;
 			for(int j = 2*i; j<=1000002; j+=i)
 			{
 				if(euler[j]==-1)euler[j] = j;
 				euler[j] = (euler[j]/i)*(i-1);
 			}
 		}
 	}
}
 
//Calculates x raised to the power of p % m
int powll(int x, int p, int m = 1ll<<62)
{
 	if(p==0)return 1;
 	if(p==1)return x%m;
 	int ans = powll(x, p/2, m);
 	ans = ((ans%m)*(ans%m))%m;
 	if(p&1)ans=(ans*x%m)%m;
 	return ans%m;
}
 
int inverse(int x, int m)
{
 	if(x==1)return 1;
 	return powll(x, euler[m]-1, m)%m;
}
 
//finds (n!)_p
int ff(int n, int p, int q)
{
 	int x = 1, y = powll(p, q);
 	for(int i = 2; i<=n;i++)
 		if(i%p)
 			x = (x*i)%y;
 	return x%y;
}
 
//Generalized Lucas Theorem calculates nCm mod p^q
int f(int n, int m, int p, int q)
{
 	int r = n-m, x = powll(p, q);
 	int e0 = 0, eq = 0;
 	int mul = (p==2&&q>=3)? 1: -1;
 	int cr = r, cm = m, carry = 0, cnt = 0;
 	while(cr||cm||carry)
 	{
 		cnt++;
 		int rr = cr%p, rm = cm%p;
 		if(rr + rm + carry >= p)
 		{
 			e0++;
 			if(cnt>=q)eq++;
 		}
 		carry = (carry+rr+rm)/p;
 		cr/=p;
 		cm/=p;
 	}
 	mul = powll(p, e0)*powll(mul, eq);
 	int ret = (mul % x + x) % x;
 	int temp = 1;
 	for(int i = 0;;i++)//This is THE line that calculates the formula
 	{
 		ret = ((ret*ff((n/temp)%x, p, q)%x)%x*(inverse(ff((m/temp)%x, p, q), x)%x*inverse(ff((r/temp)%x, p, q), x)%x)%x)%x;
 
 		if(temp>n/p && temp>m/p && temp>r/p)
			break;
 		temp = temp*p;
 	}
 	return (ret%x+x)%x;
}

long long lucas(int n, int r, int m) {
	int temp = m;
 
 		// nCr % m = ??
 		vector<int> num, rem;
 		for(int i = 0; primes[i]<=m; i++)
 		{
 			if(m%primes[i]==0)
 			{
 				int p = primes[i], q = 0;
 				while(m%p==0)
 				q++, m/=p;
 				num.push_back(powll(p, q));
 				rem.push_back(f(n, r, p, q));
 			}
 		}
 		m = temp;
 		int ans = 0;
 
 		//Chinese Remainder Theorem
 		temp = 0;
 		for(int i = 0;i<num.size(); i++)
 			ans = (ans+rem[i]*(temp = m/num[i])*inverse(temp, num[i]))%m;
 		return ans;

}
 
int main()
{
 	genprime();
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int n, r, m;

 		cin>>n>>r>>m;
 	}
 
 return 0;