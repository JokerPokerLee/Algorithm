#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

double sqr(double x) {
	return x * x;
}

int main() {
	freopen("1.in", "r", stdin);
	// freopen("progress_pie.txt", "r", stdin);
	// freopen("progress_pie.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int c;
		double p, x, y;
		cin >> p >> x >> y;
		double px = x - 50, py = y - 50;
		double len = sqrt(sqr(px) + sqr(py));
		if (len > 50) {
			c = 0;
		} else {
			double d = atan2(px, py);
			if (d < 0) {
				d += 2 * PI;
			}
			// cout << d << endl;
			// cout << (2.0 * p * PI / 100) << endl;
			if (d < 2.0 * p * PI / 100) {
				c = 1;
			} else {
				c = 0;
			}
		}
		cout << "Case #" << tt << ": " << (c ? "black" : "white") << endl;
	}
	return 0;
}