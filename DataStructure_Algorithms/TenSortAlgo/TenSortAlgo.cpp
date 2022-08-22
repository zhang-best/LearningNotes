#include <iostream>
#include <vector>
using namespace std;
//冒泡排序：
void bubblesort(vector<int>& nums)
{
    for (int i = nums.size()-1; i >=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
        }
    }
}
//选择排序
void selectsort(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int minid = i;
        for (int j = i+1; j < nums.size(); j++)
        {
            if (nums[minid] > nums[j]) minid = j;
        }
        swap(nums[minid], nums[i]);
    }
}
//插入排序
void insertsort(vector<int>& nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int index = i - 1;
        while (index>=0&&nums[index] > key)
        {
            nums[index + 1]= nums[index];
            index--;
        }
        nums[index+1] = key;
    }
}
//希尔排序
void shellsort(vector<int>& nums)
{
    int h = 1;
    while (h < nums.size())
    {
        h = h * 3;
    }
    while (h > 0)
    {
        for (int i = h; i < nums.size(); i ++)
        {
            int key = nums[i];
            int index = i - h;
            while (index >= 0 && nums[index] > key)
            {
                nums[index + h] = nums[index];
                index--;
            }
            nums[index + h] = key;
        }
        h /= 3;
    }
}
//快速排序：非稳定；时间复杂度为nlogn，最坏为n^2；空间复杂度为logn，最坏为n
void quicksort(vector<int>& nums,int left,int right)
{
    if (left >= right) return;
    int base=nums[left], i=left, j=right;
    while (i < j)
    {
        while (i < j && nums[j] >= base) j--;//**********注意必须要先判断j--再让i++**********
        while (i < j && nums[i] <= base) i++;
        if (i < j) swap(nums[i], nums[j]);
    }
    nums[left] = nums[i];
    nums[i] = base;
    quicksort(nums, left, i - 1);
    quicksort(nums, i + 1, right);
}
//归并排序，稳定；时间复杂度为nlogn，空间复杂度为n,
void Merge(vector<int>& nums, int left, int mid, int right)
{
    int l = left, r = mid + 1;
    vector<int> tmp(right - left + 1);
    int index = 0;
    while (l <= mid && r <= right)
    {
        if (nums[l] <= nums[r])
        {
            tmp[index++] = nums[l++];
        }
        else
        {
            tmp[index++] = nums[r++];
        }
    }
    while (l <= mid) tmp[index++] = nums[l++];
    while (r <= right) tmp[index++] = nums[r++];
    index = 0;
    for (int i = left; i <= right; i++,index++)
    {
        nums[i] = tmp[index];
    }
}
void mergesort(vector<int>& nums, int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergesort(nums, left, mid);
    mergesort(nums, mid + 1, right);
    return Merge(nums, left, mid, right);
}
//堆排序
void adjust(vector<int>& nums, int len, int index)
{
    int left = 2 * index + 1, right = 2 * index + 2;
    int maxid = index;
    if (left<len&&nums[left] > nums[maxid]) maxid = left;
    if (right<len&&nums[right] > nums[maxid]) maxid = right;
    if (maxid != index)
    {
        swap(nums[index], nums[maxid]);
        adjust(nums, len, maxid);
    }
}
void heapsort(vector<int>& nums, int sz)
{
    for (int i = sz - 1; i >= 0; i--)
    {
        adjust(nums, sz, i);
    }
    for (int i = sz-1; i > 0; i--)
    {
        swap(nums[i], nums[0]);
        adjust(nums, i, 0);
    }
}


int main()
{
    vector<int> testnums = { 3,1,4,2,1,5,7,6 };
    shellsort(testnums);
    int index = 0;
    while (index < testnums.size())
    {
        cout << testnums[index]<<endl;
        index++;
    }
    return 0;
}
