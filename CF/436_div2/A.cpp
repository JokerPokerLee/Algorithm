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
	int m = n / 2;
	if (a[0] == a[m - 1] && a[m] == a.back() && a[m - 1] != a[m]) {
		cout << "YES" << endl;
		cout << a[m - 1] << " " << a[m] << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}