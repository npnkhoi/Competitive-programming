#include <bits/stdc++.h>

using namespace std;

int readint() {
	int x=0; char c;
	do { c=getchar(); } while (c<=32);
	while ('0'<=c && c<='9') {
		x=10*x+c-'0';
		c=getchar();
	}
	return x;
}

const int maxn=(int)1e5+5;
const int inf=(int)1e9+5;

int timer;
int a[maxn];
int b[maxn];
int tin[maxn];
int sub[maxn];
int dep[maxn];
vector<int> g[maxn];
vector<int> tr[8*maxn];
vector<int> fun[8*maxn];
int lg[maxn];

void dfs(int v,int pr) {
	tin[v]=++timer;
	sub[v]=1;
	for (auto to:g[v]) {
		if (to==pr) continue;
		dep[to]=dep[v]+1;
		dfs(to,v);
		sub[v]+=sub[to];
	}
}

void build(int x,int l,int r) {
	if (l==r) tr[x].push_back(b[l]);
	else {
		int mid=(l+r)/2;
		build(x+x,l,mid);
		build(x+x+1,mid+1,r);
		int a1=0,b1=(int)tr[x+x].size();
		int a2=0,b2=(int)tr[x+x+1].size();
		while (a1<b1 && a2<b2) {
			if (dep[tr[x+x][a1]]<dep[tr[x+x+1][a2]]) tr[x].push_back(tr[x+x][a1++]);
			else tr[x].push_back(tr[x+x+1][a2++]);
		}
		while (a1<b1) tr[x].push_back(tr[x+x][a1++]);
		while (a2<b2) tr[x].push_back(tr[x+x+1][a2++]);
	}
	for (int i=0;i<(int)tr[x].size();i++) {
		fun[x].push_back(a[tr[x][i]]);
		if (i) fun[x][i]=min(fun[x][i],fun[x][i-1]);
	}
}

int query(int x,int l,int r,int ql,int qr,int dlim) {
    if (l==ql && r==qr) {
		if (dep[tr[x][0]]>dlim) return inf;
		int p=0;
		for (int i=lg[(int)tr[x].size()];i>=0;i--) {
			if (p+(1<<i)>=(int)tr[x].size()) continue;
			if (dep[tr[x][p+(1<<i)]]<=dlim) p+=(1<<i);
		}
		return fun[x][p];
	} else {
		int mid=(l+r)/2;
		if (qr<=mid) return query(x+x,l,mid,ql,qr,dlim);
		else if (ql>mid) return query(x+x+1,mid+1,r,ql,qr,dlim);
		else return min(query(x+x,l,mid,ql,mid,dlim),query(x+x+1,mid+1,r,mid+1,qr,dlim));
	}
}

int main() {
	int n=readint(),root=readint();
	for (int i=1;i<=n;i++) a[i]=readint();
	for (int i=1;i<n;i++) {
		int x=readint(),y=readint();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(root,-1);
	for (int i=1;i<=n;i++) b[tin[i]]=i;
	lg[1]=1;
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	build(1,1,n);
	int m=readint();
	int ls=0;
	while (m--) {
		int p=readint(),q=readint();
		int x=((p+ls)%n)+1,k=(q+ls)%n;
		ls=query(1,1,n,tin[x],tin[x]+sub[x]-1,dep[x]+k);
		printf("%d\n",ls);
	}
	return 0;
}
