#include <iostream> // I'm including iostream for input and output operations
#include <string>   // I'm including string to use the string class
#include <vector>   // I'm including vector to use the vector container

using namespace std;

// This function is tasked with finding the longest common substring between two input strings
string findLongestCommonSubstring(const string& firstString, const string& secondString) {
    // I'm determining the lengths of the two input strings
    int lengthFirstString = firstString.length();
    int lengthSecondString = secondString.length();

    // I'm initializing a 2D vector (dpTable) to store the lengths of longest common suffixes of substrings
    // dpTable[i][j] will contain the length of the longest common suffix for substrings ending at firstString[0...i-1] and secondString[0...j-1]
    vector<vector<int>> dpTable(lengthFirstString + 1, vector<int>(lengthSecondString + 1, 0));

    int maxCommonLength = 0;  // This variable will keep track of the maximum length of any common substring found
    int endIndexInFirstString = 0; // This variable will store the ending index of the longest common substring in firstString

    // I start iterating over each character in the first and second strings using a nested loop
    for (int row = 1; row <= lengthFirstString; ++row) {
        for (int col = 1; col <= lengthSecondString; ++col) {
            // I'm checking if the characters from both strings match at the current position
            if (firstString[row - 1] == secondString[col - 1]) {
                // Since the characters match, I'm incrementing the value from the diagonal cell in the dpTable
                // This means the common substring extends by 1 character
                dpTable[row][col] = dpTable[row - 1][col - 1] + 1;

                // I update maxCommonLength if the current common substring length surpasses the previous maximum
                if (dpTable[row][col] > maxCommonLength) {
                    maxCommonLength = dpTable[row][col];
                    endIndexInFirstString = row;  // I'm updating the ending index to the current row
                }
            } else {
                // Since there's no match, I'm resetting the current position in the dpTable to 0
                dpTable[row][col] = 0;
            }
        }
    }

    // I'm displaying the filled dynamic programming table (dpTable)
    cout << "Dynamic Programming Table:" << endl;
    for (const auto& dpRow : dpTable) {
        for (int cellValue : dpRow) {
            cout << cellValue << " ";  // I'm printing each value in the dpTable
        }
        cout << endl;  // I'm printing a newline after each row for better readability
    }

    // Now, I'm extracting the longest common substring from firstString using maxCommonLength and endIndexInFirstString
    // I'm slicing the firstString using these values to obtain the substring
    string longestCommonSubstring = firstString.substr(endIndexInFirstString - maxCommonLength, maxCommonLength);
    return longestCommonSubstring; // Finally, I'm returning the longest common substring
}

int main() {
    string firstInputString, secondInputString; // Here, I'm declaring variables to store the user-provided input strings

    // I'm prompting the user to input the two strings
    cout << "Enter the first string: ";
    cin >> firstInputString; // I'm storing the first input string
    cout << "Enter the second string: ";
    cin >> secondInputString; // I'm storing the second input string

    // I'm calling the function to find and display the longest common substring
    string commonSubstring = findLongestCommonSubstring(firstInputString, secondInputString); // The function executes

    // I'm outputting the longest common substring and its length
    cout << "Longest Common Substring: " << commonSubstring << endl;
    cout << "Length: " << commonSubstring.length() << endl;

    return 0; // The program ends here
}
