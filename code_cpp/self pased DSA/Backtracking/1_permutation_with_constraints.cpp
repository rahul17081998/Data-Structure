// Generate all permutations of a string that follow given constraints
#include<iostream>
using namespace std;
// Naive approch
// recursive approach
// it will generate all possible permutation of a string 
// and then check which one is valis
void permute(string str, int l, int r)
{
    // check if current permutation is valid then print it
    if(l==r)
    {
        if(str.find("AB") == string::npos){
            cout<<str<<" ";
            return;
        }
    }
    else{
        for(int i=l; i<=r; i++)
        {
            swap(str[l], str[i]);
            permute(str, l+1, r);
            swap(str[l], str[i]);
        }
    }
}
// Backtracking approach
bool isSafe(string str, int i, int l, int r)
{
    if(l!=0 && str[l-1]=='A' && str[i]=='B')
        return false;
    if((r==l+1 && str[i]=='A' && str[l]=='B') ||
       (r==l+1 && l==i && str[r]=='B' && str[l]=='A'))
        return false;

    return true;
}
void premute_bc(string str, int l, int r)
{
    if(l==r){
        cout<<str<<" ";
        return;
    }

    else{
        for(int i=l; i<=r; i++)
        {
            if(isSafe(str, i, l, r))
            {
                swap(str[l], str[i]);
                premute_bc(str, l+1, r);
                swap(str[l], str[i]);

            }
        }
    }
}
int main(){
    string str = "ABC";
    permute(str, 0, str.length()-1);
    cout<<endl;
    premute_bc(str, 0, str.length()-1);
    return 0;
}