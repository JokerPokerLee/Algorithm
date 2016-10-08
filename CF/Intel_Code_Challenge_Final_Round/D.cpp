#include <bits/stdc++.h>

using namespace std;

int pre[100100];
int f[100100];

int main() {
	freopen("1.in", "r", stdin);
	int m;
	cin >> m;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		pre[i] = -m;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		bool flag = true;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] <= i) {
				pre[j] = j;
			} else {
				if (j > 0) {
					pre[j] = pre[j - 1];
				}
			}
			if (j >= m - 1 && j - pre[j] >= m) {
				flag = false;
			}
		}
		// cout << flag << endl;
		// for (int j = 0; j < s.size(); j++) {
		// 	printf("%d%c", pre[j], " \n"[j == s.size() - 1]);
		// }
		// if (i == 'b') return 0;
		if (flag) {
			queue<int> q;
			int last = -1;
			for (int j = 0; j < s.size(); j++) {
				while (q.size() && j - q.front() > m) {
					q.pop();
				}
				if (q.size() == 0) {
					q.push(last);
				}
				// cout << q.front() << "--" << endl;
				if (s[j] < i) {
					if (q.front() == -1) {
						f[j] = 0;
					} else {
						f[j] = f[q.front()];
					}
					last = j;
				} else
				if (s[j] == i) {
					if (j - last < m) {
						f[j] = ((last == -1) ? 0 : f[last]) + 1;
					} else {
						if (q.front() == -1) {
							f[j] = 1;
						} else {
							f[j] = f[q.front()] + 1;
						}
					}
					while (q.size() && q.back() != -1 && f[q.back()] >= f[j]) {
						q.pop();
					}
					q.push(j);
				}
				// cout << f[j] << endl;
			}
			string ans;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] < i) {
					ans += s[j];
				}
			}
			if (q.front() == -1) {
				cout << (char)i << endl;
				return 0;
			}
			int cnt = f[q.front()];
			for (int j = 0; j < f[q.front()]; j++) {
				ans += (char)(i);
			}
			sort(ans.begin(), ans.end());
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}