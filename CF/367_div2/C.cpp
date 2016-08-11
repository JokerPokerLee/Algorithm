#include <bits/stdc++.h>

#define INF 1e15

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n;
	cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}
	string pres, prer;
	long long f1, f2;
	f1 = f2 = 0;
	pres = prer = "";
	for (int i = 0; i < n; i++) {
		string nows, nowr;
		cin >> nows;
		nowr = nows;
		reverse(nowr.begin(), nowr.end());
		long long g1, g2;
		g1 = g2 = INF;
		if (pres <= nows) {
			g1 = min(g1, f1);
		}
		if (prer <= nows) {
			g1 = min(g1, f2);
		}
		if (pres <= nowr) {
			g2 = min(g2, f1 + v[i]);
		}
		if (prer <= nowr) {
			g2 = min(g2, f2 + v[i]);
		}
		pres = nows;
		prer = nowr;
		f1 = g1;
		f2 = g2;
	}
	if (min(f1, f2) == INF)
		cout << "-1" << endl;
	else
		cout << min(f1, f2) << endl;
	return 0;
}