//The code below is the solution to the question given in the link below.
//https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&count=25&page=1&search=&sort_entity=order&sort_order=ASC

#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

//1. Unoptimised uproach:
//The code below shows error due to taking too long to run


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    //Below is the code that can be copied and pasted in the link above:
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //No need to check further if the next element is larger than the element in the first arra as both are ordered
            if (arr1[i]<arr2[j])
            {
                break;
            }

            //Comparing the first element of 1st array to every element in another array
            
            if (arr1[i] == arr2[j])
            {
                ans.push_back(arr2[j]);
                //changing the element which is already used in the intersection
                arr2[j] = -132423252;
                break;
            }
            
        }
        
    }
    return ans;
}


//2. Optimised uproach: 


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    //Here the below code creates a dual pointer and iterates through both samultaneously without using a nested loop
    vector<int> ans;
    int i = 0, j = 0;
    while(i < n && j < m){
        if (arr1[i] == arr2[j])
        {
           ans.push_back(arr2[j]);
           i++;
           j++;

        }
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        if (arr1[i] > arr2[j]) {
            j++;
        }
    }

    return ans;
}