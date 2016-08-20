#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	long long x;
	cin >> x;

	if (x == 1 || x == 2) {
		cout << "-1" << endl;
		return 0;
	}

	if (x % 2 == 0) {
		long long tmp = 1;
		while ((x & 1) == 0) {
			tmp <<= 1;
			x >>= 1;
		}
		if (x == 1) {
			cout << tmp * 3 / 4 << " " << tmp * 5 / 4 << endl;
			return 0;
		}
		cout << tmp * (x * x + 1) / 2 << " " << tmp * (x * x - 1) / 2 << endl;
		return 0;
	}

	cout << (x * x + 1) / 2 << " " << (x * x - 1) / 2 << endl;

	return 0;
}