#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;

void pour(int& ca, int& ma, int& cb, int& mb){
	int val = min(ma, cb-mb);
	ma -= val;
	mb += val;
}

int main() {
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	
	int c1, c2, c3;
	int u1, u2, u3;

  	scanf("%d %d", &c1, &u1);
  	scanf("%d %d", &c2, &u2);
  	scanf("%d %d", &c3, &u3);

	for(int i = 0; i < 33; ++i){
		pour(c1, u1, c2, u2);
		pour(c2, u2, c3, u3);
		pour(c3, u3, c1, u1);
	}

	pour(c1, u1, c2, u2);

	cout << u1 << endl;
	cout << u2 << endl;
	cout << u3 << endl;
	
	return 0;
}