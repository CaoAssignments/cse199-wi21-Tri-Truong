/* brute force, it would also be convenient if the students know how to use
 * c++ built-in functions like atoll and c_str() */
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

int main() {
	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);
	
	long long x, y;

	cin >> x >> y;

	int res = 0;

	for(int len = 3; len <= 17; ++len){
		for(int d0 = 0; d0 < 10; d0++){
			string curr(len, '0' + d0);
			for(int d1 = 0; d1 < 10; ++d1){
				if(d0 == d1) continue;

				for(int i = 0; i < len; ++i){
					curr[i] = '0'+ d1;

					long long num = atoll(curr.c_str());
					if(curr[0] != '0' && num >= x && num <= y){
						++res;
					}

					curr[i] = '0' + d0;
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}