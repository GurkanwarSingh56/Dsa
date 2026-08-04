#include <iostream>
#include <vector>
#include <unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(),nums.end());
    int count=0;
    for(auto &num:s){
    if (s.find(num-1)==s.end())
    {
       int currentFirst=num;
       int currentcount=1;
       while(s.find(currentFirst+1)!=s.end()){
        currentFirst++;
       currentcount++;
       
       }
       count=max(count,currentcount);
    }
    }
     return count;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

        if(s1.longestConsecutive(nums)==9)
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {100,4,200,1,3,2};

        if(s1.longestConsecutive(nums)==4)
            cout << "test case 2 passed\n";
        else
            cout << "test case 2 failed\n";
    }
};

int main() {
    test ti;
    ti.test1();
    ti.test2();

    return 0;
}