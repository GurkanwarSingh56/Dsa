/*Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int degreeOfArray(vector<int>& nums) {
       unordered_map<int,int>first;
       unordered_map<int,int>last;
       unordered_map<int,int>freq;
       int result=nums.size();
       for (int i = 0; i < nums.size(); i++)
       {
        if (first.find(nums[i])==first.end())
        {
           first[nums[i]]=i;
           
        }
        last[nums[i]]=i;
        freq[nums[i]]++;
       }
       int degree =0;
       for (auto &i:freq)
       {
       degree=max(i.second,degree);
       }
       for (auto &num:freq)
       {
        if (num.second==degree)
        {
           result=min(result,last[num.first]-first[num.first]+1);
        }
        
       }
       return result;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {1,2,2,3,1};

        if(s1.degreeOfArray(nums)==2)
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {1,2,2,3,1,4,2};

        if(s1.degreeOfArray(nums)==6)
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