/*
Date: 25/08/2022
A Bitset is a data structure that compactly stores bits.

Implement the Bitset class:

Bitset(int size) Initializes the Bitset with size bits, all of which are 0.
void fix(int idx) Updates the value of the bit at the index idx to 1. If the value was already 1, no change occurs.
void unfix(int idx) Updates the value of the bit at the index idx to 0. If the value was already 0, no change occurs.
void flip() Flips the values of each bit in the Bitset. In other words, all bits with value 0 will now have value 1 and vice versa.
boolean all() Checks if the value of each bit in the Bitset is 1. Returns true if it satisfies the condition, false otherwise.
boolean one() Checks if there is at least one bit in the Bitset with value 1. 
Returns true if it satisfies the condition, false otherwise.
int count() Returns the total number of bits in the Bitset which have value 1.
String toString() Returns the current composition of the Bitset. Note that in the resultant string, 
the character at the ith index should coincide with the value at the ith bit of the Bitset.

*/


// one more method was using set but that was giving TLE 
#include<bits/stdc++.h>
using namespace std;

class Bitset {
private:
    string s, flipp; // create 2 string method
    int siz=0;
    int ones=0;
public:
    Bitset(int size) {
        siz=size;
        s = string(size, '0'); // original string
        flipp = string(size, '1'); // fliped string
    }
    
    void fix(int idx) {
        // check prevoiuldy s[idx] was '0'
        if(s[idx]=='0') ones++;
        s[idx]='1';
        flipp[idx]='0';
    }
    
    void unfix(int idx) {
        // check prevoiuldy s[idx] was '0'
        if(s[idx]=='1') ones--;
        s[idx]='0';
        flipp[idx]='1';
    }
    
    void flip() {
        ones = siz-ones;
        s.swap(flipp); // swap flip with s
    }
    
    bool all() {
        return siz==ones;
    }
    
    bool one() {
        return ones>0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

int main(){
    
    int size=5;
    int idx=3;
    Bitset* obj = new Bitset(size);
    obj->fix(idx);
    obj->unfix(idx);
    obj->flip();
    bool param_4 = obj->all();
    bool param_5 = obj->one();
    int param_6 = obj->count();
    string param_7 = obj->toString();
    return 0;
}