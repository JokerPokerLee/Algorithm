#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	if (a.size() < 4) {
		if (a.size() == 3 && a[1] - a[0] != a[2] - a[1]) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}