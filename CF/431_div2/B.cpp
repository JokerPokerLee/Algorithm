#include <bits/stdc++.h>

#define N 1010

using namespace std;

int y[N], n;

int cmp(double x, double y) {
	if (fabs(x - y) < 1e-10) {
		return 0;
	} else {
		return 1;
	}
}

bool check(int l, int r) {
	double k = 1.0 * (y[l] - y[r]) / (l - r);
	vector<int> out;
	for (int i = 0; i < n; i++) {
		if (i != l && i != r) {
			if (cmp(1.0 * (y[i] - y[l]) / (i - l), k)) {
				out.push_back(i);
			}
		}
	}
	if (out.size() == 0) {
		return false;
	}
	if (out.size() < 2) {
		return true;
	}
	double kk = 1.0 * (y[out[1]] - y[out[0]]) / (out[1] - out[0]);
	for (int i = 2; i < out.size(); i++) {
		if (cmp(1.0 * (y[out[i]] - y[out[0]]) / (out[i] - out[0]), kk)) {
			return false;
		}
	}
	if (cmp(k, kk)) {
		return false;
	} else {
		return true;
	}
}

int main() {
	freopen("1.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &y[i]);
	}
	if (check(0, 1) || check(0, 2) || check(1, 2)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}