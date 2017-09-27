#include <bits/stdc++.h>

#define EPS 1e-7

using namespace std;

double cmp(double x, double y) {
	if (x < y - EPS) {
		return -1;
	}
	if (x > y + EPS) {
		return 1;
	}
	return 0;
}

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
	Point operator + (Point p) {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (Point p) {
		return Point(x - p.x, y - p.y);
	}
	Point operator * (double k) {
		return Point(x * k, y * k);
	}
	Point operator / (double k) {
		return Point(x / k, y / k);
	}
	double operator * (Point p) {
		return x * p.y - y * p.x;
	}
	bool operator == (Point p) {
		if (cmp(x, p.x) == 0 && cmp(y, p.y) == 0) {
			return true;
		} else {
			return false;
		}
	}
	Point trans() {
		return Point(y, -x);
	}
	void print() {
		printf("%f %f\n", x, y);
	}
};

Point oo = Point(191884927, -999999119);

struct Line {
	Point p1, p2;
	Line(Point p1, Point p2) : p1(p1), p2(p2) {}
};

Point cross(Line l1, Line l2) {
	Point v1 = l2.p1 - l1.p1;
	Point v2 = l1.p2 - l1.p1;
	Point v3 = l2.p2 - l1.p1;
	double k1 = v1 * v2;
	double k2 = v2 * v3;
	double k = k1 + k2;
	if (cmp(k, 0) == 0) {
		return oo;
	}
	return l2.p1 + (l2.p2 - l2.p1) * (k1 / k);
}

double sqr(double x) {
	return x * x;
}

double dist(Point p1, Point p2) {
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

int main() {
	freopen("1.in", "r", stdin);
	double x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point a = Point(x1, y1);
	Point b = Point(x2, y2);
	Point c = Point(x3, y3);
	if (cmp(dist(a, b), dist(b, c)) == 0 && fabs((b - a) * (c - b)) > 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	// Point mab = (a + b) / 2;
	// Point mbc = (b + c) / 2;
	// // mab.print();
	// // mbc.print();
	// Point dir1 = mab + (a - mab).trans();
	// Point dir2 = mbc + (b - mbc).trans();
	// // dir1.print();
	// // dir2.print();
	// Point o = cross(Line(dir1, mab), Line(dir2, mbc));
	// // o.print();
	// if (o == oo) {
	// 	cout << "No" << endl;
	// 	return 0;
	// }
	// if (cmp(dist(o, mab), dist(o, mbc)) == 0 && cmp(dist(a, b), dist(b, c)) == 0) {
	// 	cout << "Yes" << endl;
	// } else {
	// 	cout << "No" << endl;
	// }
	return 0;
}