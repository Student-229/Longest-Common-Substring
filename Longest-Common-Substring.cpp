#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of the longest common substring
int longestCommonSubstring(const string &str1, const string &str2, vector<vector<int>> &lookupTable) {
    int maxLength = 0;  // Store the length of the longest common substring
    int endIndex = 0;   // To track where the longest common substring ends in str1
    
    // Loop through the 2D lookup table to calculate the longest common substring
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            // If characters match, extend the substring
            if (str1[i - 1] == str2[j - 1]) {
                lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1;  // Increase length
                if (lookupTable[i][j] > maxLength) {
                    maxLength = lookupTable[i][j];  // Update max length
                    endIndex = i;  // Update the end index of substring in str1
                }
            } else {
                lookupTable[i][j] = 0;  // Reset the cell if no match
            }
        }
    }
    return maxLength;  // Return the length of the longest common substring
}

// Function to get the longest common substring from str1
string getLongestCommonSubstring(const string &str1, int endIndex, int maxLength) {
    return str1.substr(endIndex - maxLength, maxLength);  // Extract the substring
}

int main() {
    // Input strings
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // Create a 2D lookup table
    vector<vector<int>> lookupTable(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    
    // Call the function to find the longest common substring length
    int maxLength = longestCommonSubstring(str1, str2, lookupTable);
    
    // Output the lookup table for visualization
    cout << "\nDynamic Programming Table (Lookup Table):\n";
    for (int i = 0; i <= str1.length(); i++) {
        for (int j = 0; j <= str2.length(); j++) {
            cout << lookupTable[i][j] << " ";
        }
        cout << endl;
    }
    
    // Output the longest common substring
    cout << "\nThe longest common substring is: " 
         << getLongestCommonSubstring(str1, str1.length(), maxLength) << endl;
    
    cout << "\nLength of the longest common substring: " << maxLength << endl;
    
    return 0;
}
