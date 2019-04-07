#include <bits/stdc++.h>

using namespace std;

struct Interval {
	int l, h;
	int s, t;
	Interval(int l, int h, int s, int t) : l(l), h(h), s(s), t(t) {}
	void print() {
		printf("%d %d %d %d\n", l, h, s, t);
	}
};

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n, b, f;
		cin >> n >> b >> f;
		vector<Interval> v;
		v.push_back(Interval(0, n - 1, 0, n - b - 1));
		while (true) {
			// construct query
			string str = "";
			for (int i = 0; i < v.size(); i++) {
				// v[i].print();
				int d = v[i].h - v[i].l + 1;
				int m = (v[i].h + v[i].l) / 2;
				str += string(m - v[i].l + 1, '0');
				str += string(v[i].h - m, '1');
			}
			cout << str << endl << flush;
			cin >> str;
			vector<Interval> nv;
			for (int i = 0; i < v.size(); i++) {
				int db = v[i].h - v[i].l + 1;
				int da = v[i].t - v[i].s + 1;
				if (da == 0 || db == da) {
					nv.push_back(v[i]);
					continue;
				}
				int m = (v[i].h + v[i].l) / 2;
				int fb = v[i].s;
				while (fb <= v[i].t && str[fb] == '0') fb++;
				nv.push_back(Interval(v[i].l, m, v[i].s, fb - 1));
				nv.push_back(Interval(m + 1, v[i].h, fb, v[i].t));
			}
			v = nv;
			int bb = 0;
			for (int i = 0; f && i < v.size(); i++) {
				if (v[i].t < v[i].s) {
					bb += v[i].h - v[i].l + 1;
				}
			}
			if (bb == b) {
				break;
			}
		}
		vector<int> bb;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].s > v[i].t) {
				for (int j = v[i].l; j <= v[i].h; j++) {
					bb.push_back(j);
				}
			}
		}
		for (int i = 0; i < bb.size(); i++) {
			cout << bb[i] << " \n"[i == bb.size() - 1];
		}
		string res;
		cin >> res;
	}
	return 0;
}