// 11049 (DP)
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 2000000000
int dp[505][505];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	pair<int, int> matrix[505];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> matrix[i].first >> matrix[i].second;
	}
	for (int l = 1; l <= N; l++) {
		for (int i = 1; i + l <= N; i++) {
			int j = i + l;
			dp[i][j] = INF;
			for (int mid = i; mid < j; mid++) {
				int s = matrix[i].first * matrix[mid].second * matrix[j].second;
				dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + s);
			}
		}
	}
	cout << dp[1][N];
}
