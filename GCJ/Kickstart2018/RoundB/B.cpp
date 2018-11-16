#include <bits/stdc++.h>

#define MAXN 1000000000000000000
#define min(a,b) (a)<(b)?(a):(b)

#define MP make_pair

using namespace std;

typedef unsigned long long ll;

const int FMASK = (1 << 16) - 1;

ll f[110][70000];
int cnt[70000];

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("B-small-practice.in", "r", stdin);
	// freopen("B-small-practice.out", "w", stdout);
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice2.out", "w", stdout);
	for (int i = 0; i <= FMASK; i++)
		for (int j = i; j; cnt[i]++, j -= j & -j);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		memset(f, 0, sizeof(f));
		int n, k;
		ll p;
		cin >> n >> k >> p;
		vector<pair<pair<int ,int>, int>> inv;
		while (k--) {
			int x, y, z;
			cin >> x >> y >> z;
			inv.push_back(MP(MP(n - y + 1, n - x + 1), z));
		}
		sort(inv.begin(), inv.end());
		// cout << endl;
		// for (int i = 0; i < inv.size(); i++) {
		// 	printf("(%3d %3d): %d\n", inv[i].first.first, inv[i].first.second, inv[i].second);
		// }
		for (int i = 0; i <= FMASK; i++) {
			f[0][i] = i & 1 ^ 1;
		}
		int ptr = 0;
		for (int i = 1; i <= n; i++) {
			while (ptr < inv.size() && inv[ptr].first.first < i) ptr++;
			for (int mask = 0; mask <= FMASK; mask++) {
				bool sat = true;
				for (int j = ptr; sat && j < inv.size() && inv[j].first.first == i; j++) {
					int len = inv[j].first.second - inv[j].first.first + 1;
					if (cnt[mask & ((1 << len) - 1)] != inv[j].second) {
						sat = false;
						break;
					}
				}
				if (!sat) continue;
				// if (inv[ptr].second == 13 && i == inv[ptr].first.first) {
				// 	cout << mask << endl;
				// }
				int pmask = mask & (FMASK >> 1);
				f[i][mask] = min(f[i - 1][pmask << 1] + f[i - 1][(pmask << 1) + 1], MAXN);
			}
			// for (int j = 0; j < 16; j++) {
			// 	cout << f[i][j] << " ";
			// }
			// cout << endl;
		}
		int pre = 0;
		for (int i = n; i >= 1; i--) {
			pre <<= 1;
			int cur = pre & FMASK;
			if (f[i][cur] >= p) {
				cout << '0';
			} else {
				cout << '1';
				p -= f[i][cur];
				cur ^= 1;
			}
			pre = cur;
		}
		cout << endl;
	}
	return 0;
}