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

int N;
int S[105], T[105], B[105];

int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	
	cin >> N;

	for(int i = 1; i <= N; ++i){
		cin >> S[i] >> T[i] >> B[i];
	}	

	int max_buckets = 0;

	for(int t = 1; t <= 1000; ++t){
		int buckets_at_t = 0;
		for(int i = 1; i <= N; ++i){
			if(S[i] <= t && t <= T[i]){
				buckets_at_t += B[i];
			}
		}
		max_buckets = max(max_buckets, buckets_at_t);
	}

	cout << max_buckets << endl; 

	return 0;
}