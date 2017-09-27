#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	freopen("1.in", "r", stdin);
	int n, k;
	cin >> n >> k;
	int a = 0, b = 0;
	if (k > 0 && k < n) {
		a = 1;
	}
	if (1LL * k * 3 > n) {
		b = n - k;
	} else {
		b = k * 2;
	}
	cout << a << " " << b << endl;
	return 0;
}