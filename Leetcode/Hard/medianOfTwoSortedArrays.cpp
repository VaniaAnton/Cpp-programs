#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double median = 0;
        vector<int> nums3;
        nums3.reserve(nums1.size() + nums2.size());
        nums3.insert(nums3.end(), nums1.begin(), nums1.end());
        nums3.insert(nums3.end(), nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        if (nums3.size() % 2 == 0)
        {
            median = (nums3[nums3.size() / 2] + nums3[(nums3.size() / 2) - 1]) / 2.0;
        }
        else
        {
            median = nums3[nums3.size() / 2];
        }
        return median;
    }
};