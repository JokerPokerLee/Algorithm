#include <bits/stdc++.h>

using namespace std;

// int d[1010][1010];

// bool conflict(char c1, char c2) {
// 	if (c2 == 'R' || c2 == 'Y' || c2 == 'B') {
// 		swap(c1, c2);
// 	}
// 	if (c1 == c2) {
// 		return true;
// 	}
// 	if (c1 == 'R' && (c2 == 'O' || c2 == 'V')) {
// 		return true;
// 	}
// 	if (c1 == 'Y' && (c2 == 'O' || c2 == 'G')) {
// 		return true;
// 	}
// 	if (c1 == 'B' && (c2 == 'G' || c2 == 'V')) {
// 		return true;
// 	}
// 	return false;
// }

struct Unicorn{
	int co, op;
	char col1, col2;
	int tot, chain;
	bool first;
	Unicorn(int c, int o, char c1, char c2) {
		co = c, op = o;
		col1 = c1, col2 = c2;
		tot = co + op;
		chain = co - op;
		first = true;
	}
	string alone() {
		if (co == op) {
			string ans = "";
			for (int i = 0; i < co; i++) {
				ans += col1;
				ans += col2;
			}
			return ans;
		} else {
			return "IMPOSSIBLE";
		}
	}
	string getChain() {
		string ans = "";
		if (first) {
			for (int i = 0; i < op; i++) {
				ans += col1;
				ans += col2;
			}
			first = false;
		}
		ans += col1;
		return ans;
	}
};

bool cmp(Unicorn a, Unicorn b) {
	return a.tot > b.tot;
}

bool cmp1(Unicorn a, Unicorn b) {
	return a.chain > b.chain;
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	// freopen("B-small-attempt2.in", "r", stdin);
	// freopen("B-small-attempt2.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		int n, R, O, Y, G, B, V;
		scanf("%d %d %d %d %d %d %d", &n, &R, &O, &Y, &G, &B, &V);
		vector<Unicorn> unicorn;
		unicorn.push_back(Unicorn(R, G, 'R', 'G'));
		unicorn.push_back(Unicorn(Y, V, 'Y', 'V'));
		unicorn.push_back(Unicorn(B, O, 'B', 'O'));
		sort(unicorn.begin(), unicorn.end(), cmp);
		if (!unicorn[1].tot && !unicorn[2].tot) {
			cout << unicorn[0].alone() << endl;
			continue;
		}
		bool flag = false;
		for (int i = 0; i < 3; i++) {
			// cout << unicorn[i].co << " " << unicorn[i].op << endl;
			if (unicorn[i].co && unicorn[i].co <= unicorn[i].op) {
				printf("IMPOSSIBLE\n");
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}
		sort(unicorn.begin(), unicorn.end(), cmp1);
		if (unicorn[1].chain + unicorn[2].chain < unicorn[0].chain) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		vector<string> ans;
		for (int i = 0; i < unicorn[0].chain; i++) {
			ans.push_back(unicorn[0].getChain());
		}
		int now = 0;
		for (int i = 0; i < unicorn[1].chain; i++) {
			ans[now] += unicorn[1].getChain();
			now = (now + 1) % ans.size();
		}
		for (int i = 0; i < unicorn[2].chain; i++) {
			ans[now] += unicorn[2].getChain();
			now = (now + 1) % ans.size();
		}
		string arr = "";
		for (int i = 0; i < ans.size(); i++) {
			arr += ans[i];
		}
		cout << arr << endl;
		// vector<char> c;
		// for (int i = 0; i < R; i++) {
		// 	c.push_back('R');
		// }
		// for (int i = 0; i < R; i++) {
		// 	c.push_back('O');
		// }
		// for (int i = 0; i < R; i++) {
		// 	c.push_back('Y');
		// }
		// for (int i = 0; i < R; i++) {
		// 	c.push_back('G');
		// }
		// for (int i = 0; i < R; i++) {
		// 	c.push_back('B');
		// }
		// for (int i = 0; i < R; i++) {
		// 	c.push_back('V');
		// }
		// int n = R + O + Y + G + B + V;
		// memset(d, 0, sizeof(d));
		// for (int i = 0; i < n; i++) {
		// 	for (int j = i + 1; j < n; j++) {
		// 		if (!conflict(c[i], c[j])) {
		// 			d[i][j] = d[j][i] = 1;
		// 		}
		// 	}
		// }
	}
	return 0;
}