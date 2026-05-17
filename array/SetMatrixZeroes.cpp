/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
    int row= matrix.size();
    int col= matrix[0].size();
    vector <int> n(row,0);
    vector <int> m(col,0);
    for(int i=0;i<row;i++){
        for(int j=0; j<col;j++){
            if(matrix[i][j]==0){
                n[i]=-1;
                m[j]=-1;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0; j<col;j++){
            if(n[i]==-1 || m[j]==-1){
                matrix[i][j]=0;
            }
        }
    }
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(matrix);
    vector<vector<int>> expected = {{1,0,1},{0,0,0},{1,0,1}};
    if(matrix==expected){
        cout << "Test case passed!" << endl;
    } else {
        cout << "Test case failed!" << endl;
    }
    cout << endl;
    vector<vector<int>> matrix2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s.setZeroes(matrix2);
    vector<vector<int>> expected2 = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    if(matrix2==expected2){
        cout << "Test case passed!" << endl;
    } else {
        cout << "Test case failed!" << endl;
    }
    cout << endl;
    return 0;
}