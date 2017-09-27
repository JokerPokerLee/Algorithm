#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int in = false;
	int cnt = 0;
	int len = 0;
	int pre = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '_') {
			if (in) {
				if (i - pre) {
					cnt++;
				}
			} else {
				len = max(len, i - pre);
			}
			pre = i + 1;
	// cout << len << " " << cnt << endl;
		} else
		if (s[i] == '(') {
			len = max(len, i - pre);
			pre = i + 1;
			in = true;
	// cout << len << " " << cnt << endl;
		} else 
		if (s[i] == ')') {
			if (i - pre) {
				cnt++;
			}
			pre = i + 1;
			in = false;
	// cout << len << " " << cnt << endl;
		} else {

		}
	}
	len = max(len, (int)s.size() - pre);
	cout << len << " " << cnt << endl;
	return 0;
}