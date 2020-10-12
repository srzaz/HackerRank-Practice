 
#include <bits/stdc++.h>

using namespace std;

 vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> m;
       vector<int> numbers;
       for(int i = 0; i < nums.size(); i++){
           m[nums[i]] = i;
       }

       for(int i = 0; i < nums.size(); i++){
           int complement = target - nums[i];
           if(m[complement] && m[complement]!=i){
                numbers.push_back(m[complement]);
                numbers.push_back(i);
                return numbers;
           }
       }
       return numbers;
    }