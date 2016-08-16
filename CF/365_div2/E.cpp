#include <bits/stdc++.h>

#define N    1010
#define DIV  7000
#define cnt  first
#define sum  second
#define mp   make_pair

using namespace std;

typedef long long LL;
typedef pair<int , LL> PIL;

LL a[N], b[N];
PIL dp[N][DIV];

map<long long , int> p;

long long k, d[DIV];
int n, tot;

int main() {
	freopen("1.in", "r", stdin);
	cin >> n >> k;
	long long tmp = k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = __gcd(a[i], k);
		tmp /= __gcd(b[i], tmp);
	}
	if (tmp != 1) {
		cout << "-1" << endl;
		return 0;
	}
	if (k == 1) {
		cout << 1 << endl;
		cout << (int)(min_element(a + 1, a + n + 1) - a) << endl;
		return 0;
	}
	for (long long i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			d[tot++] = i;
			if (i * i != k) {
				d[tot++] = k / i;
			}
		}
	}
	sort(d, d + tot);
	for (int i = 0; i < tot; i++) {
		p[d[i]] = i;
	}
	for (int i = 1; i < tot; i++) {
		dp[0][i] = mp(n + 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < tot; j++) {
			long long y = p[d[j] / __gcd(d[j], b[i])];
			dp[i][j] = dp[i - 1][j];
			if (dp[i][j] > mp(dp[i - 1][y].cnt + 1, dp[i - 1][y].sum + a[i]))
				dp[i][j] = mp(dp[i - 1][y].cnt + 1, dp[i - 1][y].sum + a[i]);
		}
	}
	if (dp[n][p[k]].cnt == n + 1) {
		cout << "-1" << endl;
		return 0;
	}
	cout << dp[n][p[k]].cnt << endl;
	vector<int> idx;
	int ptr = n;
	long long val = k;
	while (ptr) {
		int x = p[val];
		if (dp[ptr][x] != dp[ptr - 1][x]) {
			idx.push_back(ptr);
			val /= __gcd(val, b[ptr]);
		}
		ptr--;
	}
	for (int i = 0; i < idx.size(); i++) {
		cout << idx[i] << " \n"[i == idx.size() - 1];
	}
	return 0;
}