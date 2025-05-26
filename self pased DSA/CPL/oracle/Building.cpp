#include<bits/stdc++.h>
using namespace std;

int building_construction(vector<int> &arr)
{
    vector<int> height = arr;
    int n = height.size();
    for(int i=1; i<n-1; i++){
        {
            // find left max and right max
            int lIndex, leftMax=INT_MIN;
            int rIndex, rightMax=INT_MIN;
            // left index of maximum height
            for(int j=0; j<i; j++){
                if(leftMax< height[j]){
                    lIndex=j;
                    leftMax = height[j];
                }
            }
            // right index of maximum height
            for(int j=i+1; j<n; j++){
                if(rightMax < height[j]){
                    rIndex = j;
                    rightMax = height[j];
                }
            }
            // check 
            if( leftMax > height[i] &&  height[i] < rightMax)
            {
                if(leftMax < rightMax){
                    int diff = leftMax-height[i];
                    height[lIndex] = height[lIndex]-diff;
                }
                // else if(leftMax >= rightMax){
                else{
                    int diff = rightMax-height[i];
                    height[rIndex] = height[rIndex]-diff;
                }
                
            }
        }
    }

    int sum=0;
    for(int i=0; i<n; i++) sum += height[i];
    return sum;

}

int main(){

    vector<int> height;
    height.push_back(4);
    height.push_back(8);
    height.push_back(6);
    height.push_back(7);
    // height.push_back(5);

    cout<<building_construction(height)<<endl;
    return 0;
}