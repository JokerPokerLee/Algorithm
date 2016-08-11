#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << upper_bound(a.begin(), a.end(), x) - a.begin() << endl;
	}
	return 0;
}