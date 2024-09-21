#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0, j = 0, k = 0;
        vector<int> arr;
        while (i < m && j < n)
        {
            if (nums1[i] > nums2[j])
            {
                arr[k++] = nums2[j++];
            }

            else
            {
                arr[k++] = nums2[j++];
            }
        }

        while (i > m)
        {
            arr[k++] = nums2[j++];
        }

        while (j > n)
        {
            arr[k++] = nums2[i++];
        }
        for (int i = 0; i <= arr.size(); i++)
        {
            nums1[i] = arr[i];
        }
    }
};