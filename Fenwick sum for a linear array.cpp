#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

vector<int> tree;
int n = 0, k = 0;

int sum2(int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		res += tree[r];
	return res;
}

void add(int i, int x) {
	for (; i < n; i = (i | (i+1)))
		tree[i] += x;
}

int sum(int l, int r) {
	return sum2(r) - sum2(l-1);
}

void input() {
    freopen("fenwick.in", "r", stdin);
    cin >> n >> k;
	tree.assign(n, 0);
}

void output() {
    freopen("fenwick.out", "w", stdout);
    for(int i = 0; i < k; i++)
    {
        int ind = 0, x = 0;
        string type;
        cin >> type >> ind >> x;
        x--;
        cout << type <<" ";
        if (type == "ADD")
            add(ind, x);
        if (type == "GET")
            cout << sum(ind, x) << endl;
    }
}

int main() {
   input();
   output();
   return 0;
}
