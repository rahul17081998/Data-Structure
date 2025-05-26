// Parcel wala

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

//write your function here
int solve(vector<int> parcel, int k){

    int n = parcel.size();
    int sum=0;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        // sum += parcel[i];
        st.insert(parcel[i]);
    }

    int rem = k-n;
    int i=1;
    while(rem!=0){

        if(st.find(i)==st.end()){
            // cout<<"yes"<<" ";
            sum= sum + i;
            rem--;
        }
        
        i++;
    }

    return sum;
}

int main(){
    vector<int> parcel;
    int k = 9;
    parcel.push_back(2);
    parcel.push_back(3);
    parcel.push_back(6);
    parcel.push_back(10);
    parcel.push_back(11);

    cout<< solve(parcel, k)<<endl;
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int>parcel={2,3,6,10,11};
//     int k=9;
//     sort(parcel.begin(),parcel.end());
//     long long int ans=0;
    
//     int n=parcel.size();
//    k=k-n;
//     int i=0;
//     long long int start=min(k,parcel[0]-1);
//     ans=ans+((start)*(start+1))/2;
//     k=k-start;
//    while(k>0)
//    {
//        if(i+1<n)
//        {
//            long long int x=parcel[i];
//            long long int y=min(parcel[i]+k,parcel[i+1]-1);
//            k=k-(y-x);
//            x=((x)*(x+1))/2;
//            y=((y)*(y+1))/2;
//            ans=ans+y-x;
//            i++;

//        }
//        else 
//        {
//            long long y=parcel[i]+k;
//            k=0;
//            long long x=parcel[i];
//            x=((x)*(x+1))/2;
//            y=((y)*(y+1))/2;
//            ans=ans+y-x;
//        }
//    }
//    cout<<ans<<endl;
// }

