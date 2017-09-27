#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	freopen("1.in", "r", stdin);
	int n;
	cin >> n;
	int a = n / 2;
	int b = n - a;
	while (gcd(a, b) > 1) {
		a--, b++;
	}
	cout << a << " " << b << endl;
	return 0;
}