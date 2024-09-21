// https://leetcode.com/problems/merge-sorted-array/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0, j = 0, k = 0;
        int arr[m + n];
        while (i < m && j < n)
        {
            if (nums1[i] > nums2[j])
            {
                arr[k++] = nums2[j++];
            }

            else
            {
                arr[k++] = nums1[i++];
            }
        }

        while (i < m)
        {
            arr[k++] = nums1[i++];
        }

        while (j < n)
        {
            arr[k++] = nums2[j++];
        }
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            nums1[i] = arr[i];
        }
    }
};