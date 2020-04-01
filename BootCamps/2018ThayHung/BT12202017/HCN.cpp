#include<bits/stdc++.h>
#define	MAX	1005
using namespace   std;

void Nhap_mang(int a[][1005], int M, int N)
{
	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cin >> a[i][j];
		}
	}
}

int a[MAX][MAX];
int   main()
{
    freopen("HCN.inp", "r", stdin);
    freopen("HCN.out", "w", stdout);
	int M, N;
	cin >> M >> N;
	Nhap_mang(a, M, N);
	int x, y, u, v;
	cin >> x >> y >> u >> v;
	int tong = 0;
	for(int i = x; i <= u; i++)
	{
		for(int j = y; j <= v; j++)
		{
			tong += a[i][j];
		}
	}
	cout << tong;
	return 0;
 }

