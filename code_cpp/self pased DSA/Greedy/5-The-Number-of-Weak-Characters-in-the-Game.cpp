#include<bits/stdc++.h>
using namespace std;

// /*
//write your function here
// Approach:
// we need both attack and defence of the player should be less than the other player then only we can say the later person is weaker
// so we need to see two parameter(defence and attack) to give our answer
// we can do a thing lets sort the array on one parameter and then we will see how will we handle the other one
// if the array is sorted on one parameter we only need to worry about other. As the array is sorted the greater index cant be weaker than then smaller index i.e if i > j i cant be weaker than j (as the array is sorted)
// so lets iterate from back and store the maximum element we encounter(as if we found a larger element(value of second parameter) on right it will be weaker as the second element is less and first one was already less because of sorting so both strenght and defence is weak)
// when ever we encounter this we increased our answer by one

// /*

class Solution {
public:
    // /*
    // // method 1: Naive O(N^2)
    // unordered_set<int>st;
    // int solve(vector<vector<int>>& arr)
    // {
        
    //     int ans=0;
    //     for(int i=0; i<arr.size(); i++)
    //     {
    //         int a1 = arr[i][0];
    //         int d1 = arr[i][1];
    //         if(st.find(i)!=st.end()) continue;
            
    //         for(int j=0; j<arr.size(); j++)
    //         {
    //             if(i==j) continue;
    //             int a2 = arr[j][0];
    //             int d2 = arr[j][1];
    //             if(a1 > a2 && d1 > d2)
    //             {
    //                 st.insert(j);
    //             }
                    
    //         }
    //         // ans = max(ans, count);
            
    //     }
    //     ans = st.size();
    //     return ans;
    // }
    // */
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0] < b[0]) 
            return true;
        else if(a[0]==b[0])
        {
            if(a[1]>b[1]) 
                return true;
            else return false;
        }
        // if(a[0] > b[0])
        return false;
    }
    
    
    // Method 2: O(NlogN)
    int solve2(vector<vector<int> >& arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        int count=0;
        int mini = INT_MIN;
        
        for(int i=arr.size()-1; i>=0; i--)
        {
            if(mini > arr[i][1])
                count++;
            else{
                mini = arr[i][1];
            }
        }
        return count;
    }
    
    
    int numberOfWeakCharacters(vector<vector<int> >& properties) {
        return solve2(properties);
    }
};

int main(){
    vector<vector<int> > properties;
    vector<int> level;

    level.push_back(1);
    level.push_back(5);
    properties.push_back(level);
    level.clear();
    level.push_back(10);
    level.push_back(4);
    properties.push_back(level);
    level.clear();
    level.push_back(4);
    level.push_back(3);
    properties.push_back(level);
    level.clear();
    
    Solution ob;
    cout<<ob.numberOfWeakCharacters(properties)<<endl;
    return 0;
}
/*
Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.

*/