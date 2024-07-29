#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonSubstring(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    if (m < n) {
        return longestCommonSubstring(Y, X);
    }

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                curr[j] = prev[j - 1] + 1;
                dp[i][j] = curr[j];
                if (curr[j] > maxLength) {
                    maxLength = curr[j];
                    endIndex = i - 1;
                }
            } else {
                curr[j] = 0;
                dp[i][j] = curr[j];
            }
        }
        swap(prev, curr);
    }

    cout << "DP Table:" << endl;
    cout << "  ";
    for (char ch : Y) {
        cout << ch << " ";
    }
    cout << endl;

    for (int i = 0; i <= m; ++i) {
        if (i > 0) cout << X[i - 1] << " ";
        else cout << "  ";
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    if (maxLength == 0) {
        return "";
    } else {
        return X.substr(endIndex - maxLength + 1, maxLength);
    }
}

int main() {
    string X, Y;

    cout << "Enter the first string: ";
    getline(cin, X);
    cout << "Enter the second string: ";
    getline(cin, Y);

    string result = longestCommonSubstring(X, Y);
    cout << "Longest Common Substring: " << result << endl;

    return 0;
}
