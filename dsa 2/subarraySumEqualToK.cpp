/* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Sum
{
public:
    int subarr(vector<int> nums, int k)
    {
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum == k)
            {
                count++;
                sum = 0;
            }

            for (int j = 0; j < i; j++)
            {
                sum += nums[j];
            }
        }
        return count;
    }
};
class test

{
public:
    
};

