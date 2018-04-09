#include <bits/stdc++.h>

#define EPS 1e-7
#define OPT 0.6154797166

using namespace std;

const double pi = acos(-1.0);
const double q2 = sqrt(2.0);

int cmp(double x, double y) {
	if (x < y - EPS) {
		return -1;
	}
	if (x > y + EPS) {
		return 1;
	}
	return 0;
}

double sqr(double x) {
	return x * x;
}

double calc(double a) {
	double l = cos(a);
	double s = sin(a);
	double area = s + q2 * l;
	return area;
}

int main() {
	freopen("1.in", "r", stdin);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d:\n", tt);
		double tar;
		scanf("%lf", &tar);
		if (cmp(tar, q2) <= 0) {
			// case one, rotate alone x
			double l = 0.0, r = pi / 4.0;
			for (int i = 0; i < 50; i++) {
				double m = (l + r) / 2.0;
				double a = cos(m) + sin(m);
				if (cmp(a, tar) == 0) {
					l = r = m;
					break;
				}
				if (cmp(a, tar) < 0) {
					l = m;
				} else {
					r = m;
				}
			}
			double x1 = 0.5, y1 = 0.0, z1 = 0.0;
			printf("%.6f %.6f %.6f\n", 0.5, 0.0, 0.0);
			double x2 = 0, y2 = cos(l) / 2.0, z2 = sin(l) / 2.0;
			double x3 = 0.0, y3 = sin(l) / 2.0, z3 = -cos(l) / 2.0;
			// cout << sqrt(sqr(x1) + sqr(y1) + sqr(z1)) << endl;
			// cout << sqrt(sqr(x2) + sqr(y2) + sqr(z2)) << endl;
			// cout << sqrt(sqr(x3) + sqr(y3) + sqr(z3)) << endl;
			printf("%.6f %.6f %.6f\n", x1, y1, z1);
			printf("%.6f %.6f %.6f\n", x2, y2, z2);
			printf("%.6f %.6f %.6f\n", x3, y3, z3);
		} else {
			double l = pi / 4.0, r = OPT;
			for (int i = 0; i < 50; i++) {
				double m = (l + r) / 2.0;
				double a = calc(m);
				if (cmp(a, tar) == 0) {
					l = r = m;
					break;
				}
				if (cmp(a, tar) < 0) {
					l = m;
				} else {
					r = m;
				}
			}
			double x1 = cos(l) / 2.0, y1 = sin(l) / 2.0, z1 = 0.0;
			double x2 = -sin(l) * q2 / 4.0, y2 = cos(l) * q2 / 4.0, z2 = q2 / 4.0;
			double x3 = -sin(l) * q2 / 4.0, y3 = cos(l) * q2 / 4.0, z3 = -q2 / 4.0;
			// cout << sqrt(sqr(x1) + sqr(y1) + sqr(z1)) << endl;
			// cout << sqrt(sqr(x2) + sqr(y2) + sqr(z2)) << endl;
			// cout << sqrt(sqr(x3) + sqr(y3) + sqr(z3)) << endl;
			printf("%.6f %.6f %.6f\n", x1, y1, z1);
			printf("%.6f %.6f %.6f\n", x2, y2, z2);
			printf("%.6f %.6f %.6f\n", x3, y3, z3);
		}
	}
}