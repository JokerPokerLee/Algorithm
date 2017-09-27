#include <bits/stdc++.h>

using namespace std;

struct Point {
	int a, b, c, d, e;
	Point(int a, int b, int c, int d, int e) : a(a), b(b), c(c), d(d), e(e) {}
	Point operator - (Point p) {
		return Point(a - p.a, b - p.b, c - p.c, d - p.d, e - p.e);
	}
	int operator * (Point p) {
		return a * p.a + b * p.b + c * p.c + d * p.d + e * p.e;
	}
};

int main() {
	freopen("1.in", "r", stdin);
	int n;
	cin >> n;
	vector<Point> p;
	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		p.push_back(Point(a, b, c, d, e));
	}
	if (n > 40) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> good;
	for (int i = 0; i < n; i++) {
		bool chk = true;
		for (int j = 0; chk && j < n; j++) {
			for (int k = 0; chk && k < n; k++) {
				if (i != j && j != k && k != i) {
					if ((p[j] - p[i]) * (p[k] - p[i]) > 0) {
						chk = false;
						break;
					}
				}
			}
		}
		if (chk) {
			good.push_back(i + 1);
		}
	}
	cout << good.size() << endl;
	for (int i = 0; i < good.size(); i++) {
		printf("%d%c", good[i], " \n"[i == good.size() - 1]);
	}
	return 0;
}