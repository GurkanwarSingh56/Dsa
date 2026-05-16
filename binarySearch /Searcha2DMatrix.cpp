/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows - 1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            
            if(target >= matrix[mid][0] &&
               target <= matrix[mid][cols - 1]) {

                int startColumn = 0;
                int endColumn = cols - 1;

                while(startColumn <= endColumn) {

                    int midColumn =
                        startColumn +
                        (endColumn - startColumn) / 2;

                    if(target == matrix[mid][midColumn]) {
                        return true;
                    }

                    else if(target >
                            matrix[mid][midColumn]) {

                        startColumn = midColumn + 1;
                    }

                    else {

                        endColumn = midColumn - 1;
                    }
                }

                return false;
            }

            else if(target > matrix[mid][cols - 1]) {

                start = mid + 1;
            }

            else {

                end = mid - 1;
            }
        }

        return false;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target1 = 3;
    cout << "Test Case 1: " << sol.searchMatrix(matrix1, target1) << " (Expected: true)" << endl;

    vector<vector<int>> matrix2 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target2 = 13;
    cout << "Test Case 2: " << sol.searchMatrix(matrix2, target2) << " (Expected: false)" << endl;

    return 0;
}