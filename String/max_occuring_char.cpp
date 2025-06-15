#include <bits/stdc++.h>
using namespace std;

char solve(string &s) {
    int n = s.size();
    int arr[26] = {0}; // Array to count occurrences of each character

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        int number = 0;

        if (ch >= 'a' && ch <= 'z') {
            number = ch - 'a'; // Convert lowercase letter to index
        } else if (ch >= 'A' && ch <= 'Z') {
            number = ch - 'A'; // Convert uppercase letter to index
        } else {
            continue; // Ignore non-alphabet characters
        }

        arr[number]++; // Increment the count for the character
    }

    // for (int i = 0; i < 26; i++) {
    //     cout << char(i + 'a') << ": " << arr[i] << " ";
    // }
    // cout << endl;

    int max_count = -1;
    char ans = 'a';

    for (int i = 0; i < 26; i++) {
        if (arr[i] > max_count) {
            max_count = arr[i];
            ans = 'a' + i; // Get the character from index
        }
    }

    return ans; // Return the character directly
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    char result = solve(s);
    cout << "Most frequent character: " << result << endl;

    return 0;
}
