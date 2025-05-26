#include<bits/stdc++.h>
using namespace std;

/*Problem Statement:
You are given an integer mass, which represents the original mass of a 
planet. You are further given an integer array asteroids, where 
asteroids[i] is the mass of the ith asteroid.
You can arrange for the planet to collide with the asteroids in any 
arbitrary order. If the mass of the planet is greater than or equal to 
the mass of the asteroid, the asteroid is destroyed and the planet gains 
the mass of the asteroid. Otherwise, the planet is destroyed.
Return true if all asteroids can be destroyed. Otherwise, return false.
*/
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        // sort the asteroid array
        sort(asteroids.begin(), asteroids.end());
        long long currMass = mass;
        
        for(int i=0; i<asteroids.size(); i++)
        {
            if(currMass >= asteroids[i]){
                currMass += asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};



int main(){
    // input
    int mass = 10;
    vector<int> asteroids;
    asteroids.push_back(3);
    asteroids.push_back(9);
    asteroids.push_back(19);
    asteroids.push_back(5);
    asteroids.push_back(21);

    Solution ob;
    cout<<ob.asteroidsDestroyed(mass, asteroids)<<endl;
    
    return 0;
}

/*
Input: mass = 10, asteroids = [3,9,19,5,21]
Output: true
*/