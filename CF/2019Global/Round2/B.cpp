#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, h, x;
	scanf("%d %d", &n, &h);
	vector<int> b;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		b.push_back(x);
	}
	vector<int> c;
	int l = 1, r = n;
	while (l <= r) {
		int m = (l + r) / 2;
		c = vector<int>(b.begin(), b.begin() + m);
		sort(c.begin(), c.end());
		long long accu = 0;
		for (int i = m - 1; accu <= h && i >= 0; i -= 2) {
			accu += c[i];
		}
		// cout << m << " " << accu << endl;
		if (accu <= h) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << r << endl;
	return 0;
}