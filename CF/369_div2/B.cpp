#include <bits/stdc++.h>

using namespace std;

long long a[550][550];

int main() {
	freopen("1.in", "r", stdin);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	long long tot = -1;
	int px, py;
	for (int i = 0; i < n; i++) {
		long long tmp = 0;
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (tmp != -1) {
				if (a[i][j] == 0) {
					tmp = -1;
					px = i;
					py = j;
				} else {
					tmp += a[i][j];
				}
			}
		}
		if (tot == -1 && tmp != -1)
			tot = tmp;
	}
	long long tmp = 0;
	for (int i = 0; i < n; i++)
		tmp += a[px][i];
	a[px][py] = tot - tmp;
	if (a[px][py] < 1) {
		cout << "-1" << endl;
		return 0;
	}
	bool flag = true;
	for (int i = 0; i < n; i++) {
		long long tmp = 0;
		for (int j = 0; j < n; j++) {
			tmp += a[i][j];
		}
		if (tmp != tot) {
			flag = false;
		}
		tmp = 0;
		for (int j = 0; j < n; j++) {
			tmp += a[j][i];
		}
		if (tmp != tot) {
			flag = false;
		}
	}
	tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += a[i][i];
	}
	if (tmp != tot) {
		flag = false;
	}
	tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += a[i][n - i - 1];
	}
	if (tmp != tot) {
		flag = false;
	}
	if (flag)
		cout << a[px][py] << endl;
	else
		cout << "-1" << endl;
	return 0;
}