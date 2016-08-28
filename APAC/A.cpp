#include <bits/stdc++.h>

#define MP make_pair

using namespace std;

string ans;

string mul(string s1, string s2) {
	string res = s1 + s2;
	for (int i = 0; i < res.size(); i++) {
		res[i] = '0';
	}
	int y;
	for (int i = 0; i < s1.size(); i++) {
		y = 0;
		for (int j = 0; j < s2.size(); j++) {
			int x = (res[i + j] - '0') + (s1[i] - '0') * (s2[j] - '0') + y;
			res[i + j] = x % 10 + '0';
			y = x / 10;
		}
		if (y) {
			res[i + s2.size()] += y;
		}
	}
	if (y) {
		res[s1.size() + s2.size()] = y + '0';
	} else {
		res = res.substr(0, res.size() - 1);
	}
	return res;
}

void dfs(int x) {
	if (x == 0) {
		ans = string("1");
		return;
	}
	dfs(x / 2);
	ans = mul(ans, ans);
	if (x & 1) {
		ans = mul(ans, string("2"));
	}
}

void solve(int x) {
	dfs(x);
	ans[0]--;
}

int main() {
	// freopen("A-small-attempt2.in", "r", stdin);
	// freopen("A-small-attempt2.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int i = 1; i <= ttt; i++) {
		int x, y;
		cin >> x >> y;
		int z = min(x, y);
		printf("Case #%d: ", i);
		// solve(z);
		long long aa = 1LL * z * (z + 1) / 2;
		// reverse(ans.begin(), ans.end());
		cout << aa << endl;
	}
	return 0;
}