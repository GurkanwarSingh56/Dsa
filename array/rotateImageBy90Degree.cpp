#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1. Transpose the matrix
        for(int i = 0; i < matrix.size() - 1; i++){
            for(int j = i + 1; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 2. Reverse each row
        for(auto& row : matrix){
            reverse(row.begin(), row.end());
        }
    }
};

// Helper function to handle testing logic
void runTestCase(int testNumber, vector<vector<int>> input, const vector<vector<int>>& expected) {
    Solution solver;
    
    // Process the input matrix in-place
    solver.rotate(input);
    
    // Direct vector-to-vector comparison
    if (input == expected) {
        cout << "Test Case " << testNumber << ": PASSED" << endl;
    } else {
        cout << "Test Case " << testNumber << ": FAILED" << endl;
    }
}

int main() {
    // --- TEST CASE 1 (3x3 Matrix) ---
    vector<vector<int>> input1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> expected1 = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    runTestCase(1, input1, expected1);

    // --- TEST CASE 2 (4x4 Matrix) ---
    vector<vector<int>> input2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    vector<vector<int>> expected2 = {
        {15, 13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7, 10, 11}
    };
    runTestCase(2, input2, expected2);

    return 0;
}
