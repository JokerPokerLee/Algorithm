#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n;
	cin >> n;
	int pos = -1;
	string *s = new string[n];
	for (int i = 0; i < n; i++) {
		s[i];
		cin >> s[i];
		if (pos == -1 && s[i].find("OO") != string::npos) {
			pos = i;
			int k = s[i].find("OO");
			s[i][k] = s[i][k + 1] = '+';
		}
	}
	if (pos == -1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << s[i] << endl;
	return 0;
}