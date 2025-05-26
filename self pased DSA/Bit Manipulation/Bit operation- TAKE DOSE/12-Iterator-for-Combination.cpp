/*
VVI
Design the CombinationIterator class:

CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
next() Returns the next combination of length combinationLength in lexicographical order.
hasNext() Returns true if and only if there exists a next combination.
 

Example 1:

Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
*/

// method 1:
class CombinationIterator {
    // BIT MASKING METHOD
    // TC = O(2^N *logN), SC = O(N)
    map<string,int> comb;
    map<string,int>:: iterator ptr;

public:
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.length();
        int mask = 1<<n;
        int len = combinationLength;
        // we are using bit masking to generate all the subsequence of a string 

        // we are not inculding empty string thatwhy we are starting from i=1
        for(int i=1; i<mask; i++){
            int curr=i;
            int j=0; // pointing characters string
            string s="";
            // generate string from curr value(after cinverting them in bits)
            while(curr){
                
                // whenever i find a bit 1, i will include that into string s
                if(curr&1){
                    s.push_back(characters[j]);
                }
                // do right shift
                curr = curr>>1;
                j++;
            }
            if(s.size()==len) 
                comb[s]++;
        }
        ptr = comb.begin();
    }
    
    string next() {
        auto temp = ptr; // we can use here priority queue
        ptr++;
        return temp->first;
    }
    
    bool hasNext() {
        return ptr!=comb.end()?true:false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// method 2:
class CombinationIterator {
    // BACKTRACKING METHOD
    // TC = O(2^N * logN), SC = O(N)
    vector<string> comb;
    int ptr;
    // generate all the subsequence
    void util(string s, int n, int pos, int len, string res){
        // check current string is of requires length
        if(len==0){
            comb.push_back(res);
            return;
        }

        if(pos>=n) // out of bound
            return;

        // include string in lexicographical order
        res += s[pos];
        util(s, n, pos+1, len-1, res); // Inclide current charecter
        res.pop_back(); // back track
        util(s, n, pos+1, len, res); // Exclude current charecter
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        util(characters, characters.length(), 0, combinationLength, "");
        ptr=0;
    }
    
    string next() {
        return comb[ptr++];
    }
    
    bool hasNext() {
       return ptr<comb.size()?true:false;
    }
};
