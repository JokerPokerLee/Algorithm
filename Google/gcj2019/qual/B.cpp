#include <bits/stdc++.h>

using namespace std;

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n;
		cin >> n;
		cout << "Case #" << tt << ": ";
		string path;
		cin >> path;
		for (int i = 0; i < path.size(); i++) {
			cout << (path[i] == 'S' ? 'E' : 'S');
		}
		cout << endl;
	}
	return 0;
}