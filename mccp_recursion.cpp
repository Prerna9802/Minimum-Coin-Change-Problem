#include <bits/stdc++.h>
using namespace std;


int coinChangeHelper(vector < int > & coins, int start, int end, int amount) {

    //  Base Case
    if (start > end) {
        if (amount == 0) {
            return 0;
        }
        return -1;
    }


    // If amount is negative
    if (amount < 0) {
        return -1;
    }


    // Recursive calls
    int ans1 = coinChangeHelper(coins, start, end, amount - coins[start]);
    int ans2 = coinChangeHelper(coins, start + 1, end, amount);


    if (ans1 != -1 && ans2 != -1) {
        return min(ans1 + 1, ans2);
    }


    // If we cannot achieve that amount through recursive call 1
    if (ans1 == -1) {
        return ans2;
    }


    // If we cannot achieve that amount through recursive call 2
    if (ans2 == -1) {
        return (ans1 + 1);
    }


    return -1;
}


int coinChange(vector < int > & coins, int amount) {
    return coinChangeHelper(coins, 0, coins.size() - 1, amount);
}


int main() {
    int n;
    cin >> n;


    vector < int > coins;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        coins.push_back(elem);
    }


    int amount;
    cin >> amount;


    // Calling the function
    cout << coinChange(coins, amount);
    return 0;
}