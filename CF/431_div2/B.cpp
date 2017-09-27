#include <bits/stdc++.h>

using namespace std;

int cmp(double x, double y) {
	if (fabs(x - y) < 1e-6) {
		return 0;
	} else {
		return 1;
	}
}

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> y, l1, l2;
	vector< pair<double, int> > l;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		y.push_back(x);
		if (i) {
			double k = 1.0 * (y[i] - y[0]) / i;
			l.push_back(make_pair(k, i));
		}
	}
	sort(l.begin(), l.end());
	// for (int i = 0; i < l.size(); i++) {
	// 	printf("%.6f %d\n", l[i].first, l[i].second);
	// }
	for (int i = 0; i < l.size(); i++) {
		if (i < n - 1 && cmp(l[i].first, l[i + 1].first) == 0) {
			l2.push_back(0);
			l2.push_back(l[i].second);
			for (int j = 0; j < i; j++) {
				l1.push_back(l[j].second);
			}
			for (int j = i + 1; j < n; j++) {
				if (cmp(l[j].first, l[i].first) == 0) {
					l2.push_back(l[j].second);
				} else {
					for (int k = j; k < l.size(); k++) {
						l1.push_back(l[k].second);
					}
					break;
				}
			}
			break;
		}
	}
	// for (int i = 0; i < l1.size(); i++) {
	// 	printf("%d%c", l1[i], " \n"[i == l1.size() - 1]);
	// }
	// for (int i = 0; i < l2.size(); i++) {
	// 	printf("%d%c", l2[i], " \n"[i == l2.size() - 1]);
	// }
	if (l1.size() == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	double k1, k2;
	if (l1.size() == 0) {
		k2 = 1e10;
		l2.push_back(0);
		for (int i = 1; i < n; i++) {
			l1.push_back(i);
		}
		k1 = 1.0 * (y[l1[1]] - y[l1[0]]) / (l1[1] - l1[0]);
	} else {
		k1 = 1.0 * (y[l1[1]] - y[l1[0]]) / (l1[1] - l1[0]);
		k2 = 1.0 * (y[l2[1]] - y[l2[0]]) / (l2[1] - l2[0]);
	}
	for (int i = 2; i < l1.size(); i++) {
		if (cmp(1.0 * (y[l1[i]] - y[l1[0]]) / (l1[i] - l1[0]), k1) != 0) {
			cout << "No" << endl;
			return 0;
		}
		if (cmp(1.0 * (y[l1[i]] - y[l2[0]]) / (l1[i] - l2[0]), k2) == 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	if (l2.size() == 1 || cmp(k1, k2) == 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}