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
	if (n % 2 && a[0] % 2 && a.back() % 2) {
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] % 2 && a[i - 1] % 2) {
				if (i % 2 == 0 && cnt) {
					cout << "YES" << endl;
					return 0;
				}
				if (i % 2) {
					cnt++;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}