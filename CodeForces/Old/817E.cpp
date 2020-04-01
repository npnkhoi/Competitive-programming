#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)

using namespace std;
const int N = 28;
struct node
{
    int info;
    node *left, *right;
};
int q,x,p,l,res;
node *T;
void DuyetTruoc(node *T)
{
    if (T == NULL) return;
    //cout << "DT" << endl;
    printf("%d ",T->info);
    DuyetTruoc(T->left);
    DuyetTruoc(T->right);
}
void Push(int i, node *&T)
{
    //cout << "Push " << i << endl;
    if (T == NULL)
    {
        T = new node();
        T-> info = 0;
        T-> left = NULL;
        T-> right = NULL;
    }
    T->info ++;
    if (i) (x&(1<<(i-1))) ? Push(i-1,T->right) : Push(i-1,T->left);
}
void Pop(int i, node *&T)
{
    T->info --;
    if (i) (x&(1<<(i-1))) ? Pop(i-1,T->right) : Pop(i-1,T->left);
}
void Traverse(int i, node* T)
{
    if (T==NULL) return;
    if (i==0) {res+=T->info; return;}
    if (l&(1<<(i-1))) { if (p&(1<<(i-1))) Traverse(i-1,T->left); else Traverse(i-1,T->right);}
    else
    {
        if (T->right!=NULL) if (p&(1<<(i-1))) res+=T->left->info;else res+=T->right->info;
        if (p&(1<<(i-1))) Traverse(i-1,T->right); else Traverse(i-1,T->left);
    }
}
void join()
{
    scanf("%d",&x);
    Push(N,T);
}
void leave()
{
    scanf("%d",&x);
    Pop(N,T);
}
void check()
{
    scanf("%d%d",&p,&l);
    res=0;
    Traverse(N,T);
    printf("%d\n",res);
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&q); T = NULL ;
    while (q--)
    {
        int cmd;
        scanf("%d",&cmd);
        if (cmd==1) join();
        else if (cmd==2) leave();
        else check();
        //DuyetTruoc(T); cout << endl;
    }
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
