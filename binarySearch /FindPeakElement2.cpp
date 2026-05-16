/*A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.
 
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:

    int maxElement(vector<vector<int>>& mat, int n) {

        int maxRow = 0;

        for(int i = 1; i < mat.size(); i++) {

            if(mat[i][n] > mat[maxRow][n]) {
                maxRow = i;
            }
        }

        return maxRow;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int start = 0;
        int end = mat[0].size() - 1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            int maxRow = maxElement(mat, mid);

            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;

            int right =
                (mid + 1 < mat[0].size())
                ? mat[maxRow][mid + 1]
                : -1;

            
            if(mat[maxRow][mid] > left &&
               mat[maxRow][mid] > right) {

                return {maxRow, mid};
            }

            
            else if(mat[maxRow][mid] < right) {

                start = mid + 1;
            }

            
            else {

                end = mid - 1;
            }
        }

        return {-1, -1};
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    vector<int> result = sol.findPeakGrid(mat);
    cout << "Peak element found at: [" << result[0] << ", " << result[1] << "]" << endl;

    mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    result = sol.findPeakGrid(mat);
    cout << "Peak element found at: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}