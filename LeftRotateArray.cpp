#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    int temp = nums[0];
    for (int i = 0; i < n; i++){
        nums[i-1] = nums[i];

    }
    nums[n-1] = temp;
    cout<<"Left rotated array: ";
    for (int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}