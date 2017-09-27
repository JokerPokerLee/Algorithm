#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main() {
	freopen("1.in", "r", stdin);
	mp["monday"] = 0;
	mp["tuesday"] = 1;
	mp["wednesday"] = 2;
	mp["thursday"] = 3;
	mp["friday"] = 4;
	mp["saturday"] = 5;
	mp["sunday"] = 6;
	string day1, day2;
	cin >> day1 >> day2;
	int k = (mp[day2] - mp[day1] + 7) % 7;
	if (k == 3 || k == 0 || k == 2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}