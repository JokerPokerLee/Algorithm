#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class ReconstructNumber {
public:
	string smallest(string s) {
		int n = s.size();
		vector<vector<int>> f(n + 1), p(n + 1);
		for (int i = 0; i <= n; i++) {
			f[i] = vector<int>(10);
			p[i] = vector<int>(10);
		}
		for (int i = 0; i < 10; i++) {
			f[0][i] = 1;
			p[0][i] = -1;
		}
		reverse(s.begin(), s.end());
		int l, r;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				switch (s[i - 1]) {
					case '=':
						l = j, r = j + 1;
						break;
					case '<':
						l = j + 1, r = 10;
						break;
					case '>':
						l = 0, r = j;
						break;
					case '!':
						l = 0, r = 10;
						break;
				}
				for (int k = l; k < r; k++) {
					if (!(s[i - 1] == '!' && k == j) && f[i - 1][k]) {
						f[i][j] = 1;
						p[i][j] = k;
						break;
					}
				}
			}
		}
		string res = "";
		for (int i = 1; i < 10; i++) {
			if (f[n][i]) {
				int now = n, dig = i;
				while (now >= 0) {
					res += (char)('0' + dig);
					dig = p[now][dig];
					now -= 1;
				}
				break;
			}
		}
		return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	ReconstructNumber *obj;
	string answer;
	obj = new ReconstructNumber();
	clock_t startTime = clock();
	answer = obj->smallest(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = ">=!<";
	p1 = "10012";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "====!====";
	p1 = "1111100000";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "";
	p1 = "1";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
	p1 = "";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "><<>><=<=>=>";
	p1 = "1012101122110";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
