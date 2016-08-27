#include <bits/stdc++.h>

#define MP make_pair
#define EPS 1e-8

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	string s;
	cin >> s;
	int l = 0;
	while (l < s.size() && s[l] == 'a') l++;
	if (l == s.size()) {
		s[s.size() - 1] = 'z';
		cout << s << endl;
		return 0;
	}
	int r = l;
	while (r < s.size() && s[r] != 'a') {
		s[r] = s[r] - 1;
		r++;
	}
	cout << s << endl;
	return 0;
}