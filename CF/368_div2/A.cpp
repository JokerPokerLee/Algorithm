#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	bool flag = true;
	for (int i = 0; flag && i < n; i++)
		for (int j = 0; flag && j < m; j++) {
			string co;
			cin >> co;
			if (co[0] != 'G' && co[0] != 'W' && co[0] != 'B') {
				flag = false;
				break;
			}
		}
	cout << (flag ? "#Black&White" : "#Color") << endl;
	return 0;
}