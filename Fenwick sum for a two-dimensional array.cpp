#include <iostream>
#include <fstream>
#include <string>
using namespace std;
long long t[1001][1001];
int n = 0, k = 0;

long long sum2(int x, int y)
{
	long long res = 0;
	for(int i = x; i > 0; i = (i & (i + 1)) - 1)
		for(int j = y; j > 0; j = (j & (j + 1)) - 1)
			res += t[i][j];
	return res;
}

void add(int x, int y)
{
	for(int i = x; i <= n; i = (i | (i + 1)))
        for(int j = y; j <= n; j = (j | (j + 1)))
            t[i][j]++;
}

long long sum(int x1, int y1, int x2, int y2)
{
	return sum2(x2, y2) + sum2(x1 - 1, y1 - 1) -  sum2(x1 - 1, y2) - sum2(x2, y1 - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("fenwick.in", "r", stdin);
    freopen("fenwick.out", "w", stdout);
    cin >> n >> k;
	for(int i = 0; i < k; i++)
    {
        int ind = 0, x = 0, y = 0, x1 = 0, y1 = 0;
        string type;
        cin >> type >> x >> y;
        if (type == "ADD")
            add(x, y);
        if (type == "GET")
        {
            cin >> x1 >> y1;
            if (x1 < x) swap(x1, x);
            if (y1 < y) swap(y1, y);
            cout << sum(x,y,x1,y1) << endl;

        }
    }
}
