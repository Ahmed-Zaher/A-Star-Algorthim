#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

#include "point.h"
#include "astar.h"

int main() {
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(5);
	AStar G;
	int q, s, t;
	cout << "Enter number of queries: ";
	cin >> q;
	cout << "Enter queries in the form \"source destination\"\n";
	for (int i = 0; i < q; ++i) {
		cin >> s >> t;
		int T = clock();
		cout << "Shortest path distance: " << G.Query(s, t) << '\n';
		cout << "Time: " << 1.0 * (clock() - T) / CLOCKS_PER_SEC << "s\n";
	}
	cout << "Press Enter to terminate...";
	cin.ignore();
	string term;
	getline(cin,term);
	return 0;
}
