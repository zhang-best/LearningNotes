# include <iostream>
# include <string>
using namespace std;
#include <vector>

int search(vector<int>& nums, int target) {
    int n = nums.size(), index = 0;
    while (nums[index] >= nums[0])
    {
        index++;
    }
    int left = 0, right = n - 1;
    if (index < n)
    {
        if (target<nums[index] || target>nums[index - 1]) return -1;
        if (target < nums[0]) {
            left = index;
            right = n - 1;
        }
        else {
            left = 0;
            right = index - 1;
        }
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;

}
void main()
{
    vector<int> nums = { 1 } ;
    int target = 0;
}