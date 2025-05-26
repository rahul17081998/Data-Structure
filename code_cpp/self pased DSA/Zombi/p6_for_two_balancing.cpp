#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    unordered_set<int> pp, pm, mm, mp;
    void findS(vector<int> &ans, bool same_color, bool opposite_color, bool none)
    {
        if(same_color)
        {
            for(auto x: pp){
                ans.push_back(x);
                break;
            }
            for(auto x: mm){
                ans.push_back(x);
                break;
            }
            
        }

        
        if(opposite_color)
        {
            for(auto x: pm){
                ans.push_back(x);
                break;
            }
            for(auto x: mp){
                ans.push_back(x);
                break;
            }
            
        }

        if(none)
        {
            ans.push_back(0); // insert any one element    
        }


    }

    void balancing(int B1[], int B2[], vector<int> &ans, int n, int m)
    {
        int pp_count=0; // plus_plus count
        int mm_count=0; // minus_minus count
        int pm_count=0; // plus_minus count
        int mp_count=0; // minus_plus count

        // unordered_set<int> pp, pm, mm, mp;
        // calculate plus_plus, plus_minus, minus_minus and minus_plus counts
        for(int i=0; i<n; i++)
        {
            if(b1[i]==1 && b2[i]==1){
                pp_count++; // increate the count
                pp.insert(i); // store the index if you find plus_plus combination
            }
            if(b1[i]==-1 && b2[i]==-1){
                mm_count++; // increate the count
                mm.insert(i); // store the index if you find minus_minus combination
            }
            if(b1[i]==1 && b2[i]==-1){
                pm_count++; // increate the count
                pm.insert(i); // store the index if you find plus_minus combination
            }
            if(b1[i]==-1 && b2[i]==1){
                mp_count++; // increate the count
                mp.insert(i); // store the index if you find minus_plus combination
            } 
        }

        bool same_color=false; 
        bool opposite_color=false;
        bool none=false; 
        // case 1: check if plus_plus and minus_minus count is greater than zero
        if(pp_count > 0 && mm_count > 0){
            same_color=true; // means we have at least one plus_plus and one minus_minus ---> imbalance =0
            cout<<"Imbalance = 0\n";
        }
        
        // case 2: check if plus_minus and minus_plus count is greater than zero
        else if(pm_count > 0 && mp_count > 0){
            opposite_color=true; // means we have at least one plus_plus and one minus_minus ---> imbalance =0
            cout<<"Imbalance = 0\n";
        }

        // case3: check if both case failed --> means imbalance will atleast 2 taking one element from each balanceing
        else{
            none=true;
            cout<<"Imbalance = 2\n";
        }

        // Now print the solution set S
        findS(ans, same_color, opposite_color, none);

        cout<<"Print best set \n";
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";

    }    

};

int main(){
    /*
    int n; // Number of elements
    int m; // Number of bicolorings

    cin >> n >> m;
    
    int b1[n], b2[n];
    
    for(int i = 0;i<n;i++)
        cin >> b1[i];
    for(int i = 0;i<n;i++)
        cin >> b2[i];
    
    */
    int n=10;
    int m=2;
    int b1[]={+1, +1, -1, -1, +1, +1, -1, -1, +1, +1};
    int b2[]={+1, -1, +1, -1, +1, -1, +1, -1, +1, -1,};

    vector<int> ans;
    Solution ob;
    ob.balancing(b1, b2, ans, n, m); 

    return 0;
}   