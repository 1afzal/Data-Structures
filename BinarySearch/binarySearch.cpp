#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<int>arr , int x){
  int n = arr.size();
  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = (low + high)/2;
    if(arr[mid] == x){
      return mid;
    }
    else if(x > arr[mid]){
      low = mid + 1;
    }
    else{
      high = mid -1;
    }
  }
  
  return -1;
}
int main(){
  vector<int>arr{10,20,30,40,50,60};
  int res = binSearch(arr, 100);
  if(res == -1){
    cout<<"answer not found"<<endl;
  }
  else{
  cout<<"answer at index =: "<<res<<endl;
  }

  return 0;
}