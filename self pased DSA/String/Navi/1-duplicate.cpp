#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//write your function here
int numDuplicate(vector<string> name, vector<int> price, vector<int> weight)
{
    unordered_map<string, vector<pair<int,int> > > mp;
    int count=0;
    for(int i=0; i<name.size(); i++){
        // check name is present or not
        pair<int,int> p=make_pair(price[i], weight[i]);
        // temp.make_pair(price[i]);
        // temp.push_back(weight[i]);
        if(mp.find(name[i])!=mp.end()){
            // then check two other(price and weight) is present or not
            bool flag=false;
            vector<pair<int,int> > v = mp[name[i]];
            for(auto pairP:v){
                if(pairP == p){
                    count++;
                    flag=true;
                    break;
                }
            }
            // for(auto v: mp[name[i]]){
            //     if(v==temp){
            //         count++;
            //         flag=true;
            //         break;
            //     }
            // }
            if(flag==false){
                v.push_back(p);
            }

        }
        else{
            mp[name[i]].push_back(p);
        }
    }
    return count;
}

int main(){
    vector<string> name;
    vector<int> price;
    vector<int> weight;

    name.push_back("ball");
    name.push_back("bat");
    name.push_back("glove");
    name.push_back("glove");
    name.push_back("glove");

    price.push_back(2);
    price.push_back(3);
    price.push_back(1);
    price.push_back(2);
    price.push_back(1);

    weight.push_back(2);
    weight.push_back(5);
    weight.push_back(1);
    weight.push_back(1);
    weight.push_back(1);

    cout<<numDuplicate(name, price, weight)<<endl;
    return 0;
}