#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>arr, int x){
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = n;

  while(low <= high){
    int mid = (low + high)/2;

    if(arr[mid] >= x){
      ans = mid;
      high = mid - 1; 
    }
    else{
      low = mid + 1;
    }
  }
  return ans;
}
int main(){
  vector<int>arr{10,20,30,40,50};
  int x = 30;
  try{
  int res = lowerBound(arr, x);
  cout<<"LowerBound value of arr is: "<<res;
  }
  catch(exception& err){
    cout<<err.what();
  }
  return 0;
}