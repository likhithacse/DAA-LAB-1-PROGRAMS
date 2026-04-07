#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

// Function using Bitmask DP
int tsp(int mask, int pos) {
    // If all cities are visited, return cost to go back to start
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    // If already computed
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // Try visiting all unvisited cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    dist.resize(n, vector<int>(n));
    dp.resize(1 << n, vector<int>(n, -1));

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int result = tsp(1, 0); // Start from city 0

    cout << "Minimum travelling cost = " << result;

    return 0;
}