using namespace std;
#include <stdio.h>
const int N = 1e5 + 50;
int n, a[N];
int cnt;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	cnt = 0;	
	for (int i = 1; i < n; i++)
	if (cnt == 0 && a[i]>a[i+1]) cnt ++;
	else if (cnt == 1 && a[i]<=a[i+1]) cnt ++;
	else if (cnt == 2 && a[i]>a[i+1]) 
	{printf("no"); return 0; }
	printf("yes");	
}