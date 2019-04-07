#include <bits/stdc++.h>

#define DEBUG

using namespace std;

int bx = 500;
int by = 500;
int occ[1010][1010];

int len, wid;

#ifdef DEBUG
	ofstream of("C.log");
#endif

inline bool input() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (x == 0) {
		return true;
	}
	occ[x][y] = 1;
	x -= bx;
	y -= by;
	#ifdef DEBUG
		of << "in:  " << x << ", " << y << "\n" << flush;
	#endif
	return false;
}

inline void output(int x, int y) {
	#ifdef DEBUG
		of << "out: " << x << ", " << y << "\n" << flush;
	#endif
	printf("%d %d\n", x + bx, y + by);
	fflush(stdout);
}

inline bool occed(int x, int y) {
	return occ[x + bx][y + by];
}

inline bool inside(int x, int y) {
	return (x > 1) && (x < len) && (y > 1) && (y < wid);
}

bool emp(int x, int y) {
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (!occed(x + i, y + j)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		memset(occ, 0, sizeof(occ));
		int a;
		scanf("%d", &a);
		len = 3, wid = 3;
		while (len * wid < a) {
			if (len > wid) {
				wid++;
			} else {
				len++;
			}
		}
		#ifdef DEBUG
			of << a << "\n" << flush;
			of << len << " " << wid << "\n" << flush;
		#endif
		int l, r, u, b;
		l = (len + 1) / 2;
		r = (len + 1) / 2;
		u = (wid + 1) / 2;
		b = (wid + 1) / 2;
		bool done = false;
		vector< pair<int, int> > pla;
		pla.push_back(make_pair(l, u));
		while (pla.size()) {
			for (int i = 0; i < pla.size(); i++) {
				int x = pla[i].first;
				int y = pla[i].second;
				if (occed(x, y)) {
					continue;
				}
				int nx, ny;
				while (!done && !occed(x, y)) {
					output(x, y);
					done = input();
				}
			}
			if (done) {
				break;
			}
			pla.clear();
			for (int i = l - 1; i <= r + 1; i++) {
				int j;
				j = u + 1;
				#ifdef DEBUG
					of << i << " " << j << "\n" << flush;
				#endif
				if (inside(i, j) && !occed(i, j)) {
					#ifdef DEBUG
						of << "1\n" << flush;
					#endif
					pla.push_back(make_pair(i, j));
				}
				j = b - 1;
				#ifdef DEBUG
					of << i << " " << j << "\n" << flush;
				#endif
				if (inside(i, j) && !occed(i, j)) {
					#ifdef DEBUG
						of << "2\n" << flush;
					#endif
					pla.push_back(make_pair(i, j));
				}
			}
			for (int j = b; j <= u; j++) {
				int i;
				i = l - 1;
				if (inside(i, j) && !occed(i, j)) {
					pla.push_back(make_pair(i, j));
				}
				i = r + 1;
				if (inside(i, j) && !occed(i, j)) {
					pla.push_back(make_pair(i, j));
				}
			}
			if (u < wid - 1) u++;
			if (b > 2) b--;
			if (l > 2) l--;
			if (r < len - 1) r++;
			#ifdef DEBUG
				of << l << " " << r << " " << b << " " << u << "\n" << flush;
			#endif
			#ifdef DEBUG
				of << "===== Update pla  =====\n" << flush;
				for (int i = 0; i < pla.size(); i++) {
					int x = pla[i].first;
					int y = pla[i].second;
					of << "pla: " << x << ", " << y << "\n" << flush;
				}
				of << "===== Update done =====\n" << flush;
			#endif
		}
		#ifdef DEBUG
			of << "inside done.\n" << flush;
		#endif
		if (done) {
			continue;
		}
		for (int i = l; i <= r; i++) {
			int j;
			j = u;
			while (!done && emp(i, j)) {
				output(i, j);
				done = input();
			}
			j = b;
			while (!done && emp(i, j)) {
				output(i, j);
				done = input();
			}
		}
		for (int j = b; j <= u; j++) {
			int i;
			i = l;
			while (!done && emp(i, j)) {
				output(i, j);
				done = input();
			}
			i = r;
			while (!done && emp(i, j)) {
				output(i, j);
				done = input();
			}
		}
	}
	return 0;
}