#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	freopen("1.in", "r", stdin);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n, k, x;
		cin >> n >> k;
		vector<int> pos;
		for (int i = 0; i < n; i++) {
			cin >> x;
			pos.push_back(x);
		}
		map<int, vector<int>> col;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (!col.count(x)) {
				col[x] = vector<int>();
			}
			col[x].push_back(pos[i]);
		}
		vector<ll> f[2];
		f[0] = vector<ll>(k + 1, -1);
		f[1] = vector<ll>(k + 1, -1);
		f[0][0] = f[1][0] = 0;
		for (auto &ptr: col) {
			vector<int> &p = ptr.second;
			// cout << ptr.first << ": ";
			// for (int i = 0; i < p.size(); i++) {
			// 	cout << p[i] << " \n"[i == p.size() - 1];
			// }
			sort(p.begin(), p.end());
			for (int i = k; i > 0; i--) {
				for (int j = 0; j < i && j < p.size(); j++) {
					ll c[2] = {-1, -1}, tmp;
					if (f[0][i - j - 1] != -1) {
						tmp = f[0][i - j - 1] + p[j] * 2;
						c[0] = c[0] == -1 ? tmp : min(c[0], tmp);
						tmp = f[0][i - j - 1] + p[j];
						c[1] = c[1] == -1 ? tmp : min(c[1], tmp);
					}
					if (f[1][i - j - 1] != -1) {
						tmp = f[1][i - j - 1] + p[j] * 2;
						c[1] = c[1] == -1 ? tmp : min(c[1], tmp);
					}
					// cout << i << ", " << j << ": " << c[0] << ", " << c[1] << endl;
					if (c[0] != -1) {
						f[0][i] = f[0][i] == -1 ? c[0] : min(c[0], f[0][i]);
					}
					if (c[1] != -1) {
						f[1][i] = f[1][i] == -1 ? c[1] : min(c[1], f[1][i]);
					}
				}
			}
			// for (int i = 0; i <= k; i++) {
			// 	cout << f[0][i] << " \n"[i == k];
			// }
			// for (int i = 0; i <= k; i++) {
			// 	cout << f[1][i] << " \n"[i == k];
			// }
		}
		cout << "Case #" << tt << ": " << f[1][k] << endl;
	}
	return 0;
}