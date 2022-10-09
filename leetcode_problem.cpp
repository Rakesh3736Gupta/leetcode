

220. Contains Duplicate III
Hard

/*
You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.

 

Example 1:

Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0   */
//********************************************************//
 bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
          //bool ans=true;
        
             vector<pair<int,int>>v(nums.size());
             for(int i=0;i<nums.size();i++)
               {
                     // v.push_back({nums[i],i});
                    v[i].first=nums[i];
                    v[i].second=i;
               }       
             
             sort(v.begin(),v.end());
             for(int i=0;i<nums.size();i++)
             {
                 for(int j=i+1;j<nums.size();j++)
                 {
                   if(abs(v[i].first-v[j].first)<=valueDiff)
                    {
                        if(abs(v[i].second-v[j].second)<=indexDiff)
                             return true;
                     }
                      else
                         break;
                 }
             }
          
             return false;

    }
  

//22222222222222222222222222222222222222222//   
 
 28. Find the Index of the First Occurrence in a String
Medium

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.  */
 
 /******************************************/
  #include<bits/stdc++.h>
    int strStr(string haystack, string needle) {
        int a;
        int i;
        int len = needle.length();
        for( i=0; i<haystack.length() ;i++){
            string ans=haystack.substr(i , len);
            if(needle==ans){
                a=i;
             break ;
            }
            
        }
        if(a==i){
            return i;
        }
        else{
            return -1;
        }
    }


    ////************3333333333333333333333333333333333333//
/*

153. Find Minimum in Rotated Sorted Array
Medium

8652

434

Add to List

Share
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.  */


     #include<bits/stdc++.h>
    int findMin(vector<int>& nums) {
       int a;
        
        map<int,int>mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        for(auto &pr : mp){
            a= pr.first;
            break;
        }
    return a;
    }

/*********************************/

/*
81. Search in Rotated Sorted Array II
Medium

5193

787

Add to List

Share
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 */
//**************************
  bool search(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
       for(int i=0;i<v.size();i++)
       {
           if(v[i].first==target)
           return true;
       }
       return false;
    }  
    

/*********************************/
41. First Missing Positive
Hard

11905

1467

Add to List

Share
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 
/**********************************/
 int firstMissingPositive(vector<int>& nums) {
         int count=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0&&nums[i]==count)
            count++;
        }
        return count;
    }

//***************************************

287. Find the Duplicate Number
Medium

16712

2239

Add to List

Share
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


//************************
int findDuplicate(vector<int>& nums) 
    {
//         sort(nums.begin() , nums.end());
//         int a;
//         vector<pair<int,int>> v;
//         for(int i=0 ; i<nums.size() ; i++){
//            v.push_back({nums[i] , i});
//         } 
//         for(int i=0 ; i<v.size() ; i++){
//           if(v[i].first==v[i+1].first) {
             
//               a=v[i].first;
//               break;
//           } 
//         }
//        return a; 




//second method
        int mx=INT_MIN;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int a;
        for(auto &ans:m)
        {
            mx=max(mx,ans.second);
            if(mx==ans.second)
            {
                a=ans.first;
            }
        }
        return a;
    }


    //**************************************
    33. Search in Rotated Sorted Array
Medium

17911

1073

Add to List

Share
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

/*******************************************//
  int search(vector<int>& nums, int target) {
         vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
       for(int i=0;i<v.size();i++)
       {
           if(v[i].first==target)
           return v[i].second;
       }
       return -1;
      }
    /****************************/

41. First Missing Positive
Hard

11905

1467

Add to List

Share
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


//***********************************

      int firstMissingPositive(vector<int>& nums) {
         int count=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0&&nums[i]==count)
            count++;
        }
        return count;
    }




    //****************************

34. Find First and Last Position of Element in Sorted Array
Medium

14187

347

Add to List

Share
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109



    //***************************
     #include<bits/stdc++.h>
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<pair<int,int>>v;
          vector<int>v1;
        vector<int>ans;
        for(int i= 0; i<nums.size() ; i++){
            v.push_back({nums[i],i});
        }
        for(int i=0 ; i<v.size() ; i++){
            if(v[i].first==target){
                v1.push_back(v[i].second);
            }
        }
        if(v1.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            ans.push_back(v1[0]);
            ans.push_back(v1[v1.size()-1]);
        }
        return ans;
    }