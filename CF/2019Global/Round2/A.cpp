#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	scanf("%d", &n);
	vector<int> c;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		c.push_back(x);
	}
	int ans;
	for (int i = 0; i < n; i++) {
		if (c[i] != c.back()) {
			ans = n - i - 1;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (c[i] != c[0]) {
			ans = max(ans, i);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}