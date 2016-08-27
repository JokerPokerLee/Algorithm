#include <bits/stdc++.h>

#define MP make_pair
#define EPS 1e-8

using namespace std;



int main() {
	freopen("1.in", "r", stdin);
	int a00, a01, a10, a11;
	cin >> a00 >> a01 >> a10 >> a11;
	bool noZero = (a01 + a10 > 0);
	int x, y;
	if (a00 == 0) {
		x = noZero ? 1 : 0;
	} else {
		x = (int)sqrt(2.0 * a00) + 1;
	}
	if (x * (x - 1) != a00 * 2) {
		cout << "Impossible" << endl;
		return 0;
	}
	if (a11 == 0) {
		y = noZero ? 1 : 0;
	} else {
		y = (int)sqrt(2.0 * a11) + 1;
	}
	if (y * (y - 1) != a11 * 2) {
		cout << "Impossible" << endl;
		return 0;
	}
	if (a01 + a10 != x * y) {
		cout << "Impossible" << endl;
		return 0;
	}
	// cout << x << " " << y << endl;
	int h = x == 0 ? 0 : a01 / x;
	int k = a01 - x * h;
	int g = y - (h + (k > 0 ? 1 : 0));
	if (g < 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	// cout << g << " " << k << " " << h << endl;
	if (g * x + (k > 0 ? (x - k) : 0) != a10) {
		cout << "Impossible" << endl;
		return 0;
	}
	if (!x && !y) {
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i < g; i++) {
		cout << "1";
	}
	for (int i = 0; i < k; i++) {
		cout << "0";
	}
	if (k > 0) {
		cout << "1";
	}
	for (int i = 0; i < (x - k); i++) {
		cout << "0";
	}
	for (int i = 0; i < h; i++) {
		cout << "1";
	}
	cout << endl;
	return 0;
}