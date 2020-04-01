#include <bits/stdc++.h>
using namespace std;

struct item {
    int key, prior;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;

pitem Treap = NULL;

void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}

int getRes(int b, int y) {
	pitem tLeft, tRight;
	split(Treap, b, tLeft, tRight);
	if (tRight == NULL || tRight -> prior < y) {
		merge(Treap, tLeft, tRight);
		return -1;
	}
	pitem idx = tRight;
	int res = idx -> key;
	while (idx -> l != NULL) {
		idx = idx -> l;
		if (idx -> prior >= y) {
			res = idx -> key;
		} else break;
	}
	merge(Treap, tLeft, tRight);
	return res;
}

void show(pitem t) {
	if (t == NULL) return;
	cerr << t << " " << t -> key << " " << t -> prior << " " << t -> l << " " << t -> r <<  "\n";
	show(t -> l);
	show(t -> r);
}

void init(pitem &t, int key, int prior) {
	t = new item;
	t -> key = key;
	t -> prior = prior;
	t -> l = t -> r = NULL;
}

int n, m;
char type;
int x, y, a, b;

int main() {
	scanf("%d%d", &n, &m);
	while (m --) {
		scanf(" %c", &type);
		if (type == 'M') {
			// cerr << "insert\n";
			scanf("%d%d", &x, &a);
			// item tmp(a, -x);
			// insert(Treap, &tmp);
			pitem tmp;
			init(tmp, a, -x);
			insert(Treap, tmp);
			// cerr << "output Treap\n";
			// show(Treap);
		} else {
			// cerr << "question\n";
			scanf("%d%d", &y, &b);
			printf("%d\n", getRes(b - 1, -y));
			// cerr << "output Treap\n";
			// show(Treap);
		}
	}	
}