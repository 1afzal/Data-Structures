#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>&nums, int target){
        for(int i=0;i<nums.size();i++){
            for(int j=i + 1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    return {i , j};
                }
            }
        }
        return {};
    } 
};

int main(){
    vector<int> nums{10,20,30,40};
    int target = 30;

    Solution s;
    vector<int> ans{};
    ans = s.twoSum(nums,target);

    cout << "Indices of numbers that sum to " << target << ": ";
    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;

    cout << "Numbers at those indices: ";
    for(int i: ans){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}