#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector <int> temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        int leftEnd=(n-1)/2;
        int rightEnd=n-1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=temp[leftEnd];
                leftEnd--;
            }
            else{
                nums[i]=temp[rightEnd];
                rightEnd--;
            }
        }
       
    }
};
class Test
{
public:
    void test1()
    {
        Solution s1;
        vector<int> nums = {1, 5, 1, 1, 6, 4};

        s1.wiggleSort(nums);

        if (nums == vector<int>{1, 6, 1, 5, 1, 4})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
    }

    void test2()
    {
        Solution s1;
        vector<int> nums = {1, 3, 2, 2, 3, 1};

        s1.wiggleSort(nums);

        if (nums == vector<int>{2, 3, 1, 3, 1, 2})
            cout << "Test case 2 passed\n";
        else
            cout << "Test case 2 failed\n";
    }
};

int main()
{
    Test t;
    t.test1();
    t.test2();

    return 0;
}