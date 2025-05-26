
// problem link: https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=0
#include<iostream>
using namespace std;

bool isSuccessful(int mid, vector<int> &stalls, int k)
{
    int cowCount=1;
    int lastPos=stalls[0];
    for(int i=0; i<stalls.size(); i++)
    {
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
                return true;
            lastPos = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    // sort the stalls array
    sort(stalls.begin(), stalls.end());
    int s=0; // start
    int maxi=-1;

    for(int i=0; i<stalls.size(); i++) 
        maxi = max(maxi, stalls[i]);
    
    int end=maxi; // end
       
    int ans=-1;
    while(s<=end)
    {
        int mid = s + (end-s)/2;
        // check if we can get successfull mid
        if(isSuccessful(mid, stalls, k))
        {
            ans = mid;
            // we are successfully get mid so we want to more large value of mid value so we will shift start pointer just right of mid
            // and two cows and be more far away to each other
            s = mid +1;  
        }
        else{ // if mid is not successful, come closer to the cow
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    
    return 0;
}