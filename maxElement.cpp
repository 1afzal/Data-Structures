#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int largestElement(vector<int>&arr , int size){
        int max = arr[0];
        for(int i=1;i<size;i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }
};
int main(){
    vector<int> arr{10,20,30,40,50,60,70}; //largest here is 70.
    int size = arr.size();

    Solution s;
    int res = s.largestElement(arr,size);
    cout<<"Largest value is:"<<res<<endl;

    return 0;
}