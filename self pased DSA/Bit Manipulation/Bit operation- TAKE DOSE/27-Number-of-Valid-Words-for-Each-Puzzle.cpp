/*
With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).
Return an array answer, where answer[i] is the number of words in the given word list words that is valid with respect to the puzzle puzzles[i].
 

Example 1:

Input: words = ["aaaa","asas","able","ability","actt","actor","access"], puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation: 
1 valid word for "aboveyz" : "aaaa" 
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There are no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
*/

class Solution {
public:

    int getBitMask(string str){
        int mask=0;
        for(auto c : str){
            int bitMaskOfc = (1<<(c-'a'));
            mask = mask | bitMaskOfc;
        }
        return mask;
    }

    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        // map to store the frequency of masks
        // let ab and ababbbb are two words. mask of both of them are same (i.e. 3)
        //  so freq of 3 will be 2 .i.e. mask_freq[3] = 2
        //  mask_freq[mask] = number of words with that mask
        unordered_map<int, int> mask_freq; 

        for(auto word: words){
            int wordMask = getBitMask(word);
            mask_freq[wordMask]++;
        }

        vector<int> ans;
        for(auto p: puzzles){
            int pMask = getBitMask(p); // mask of current puzzle
            int subMask=pMask;
            int first = (1<<(p[0]-'a')); // mask of first char of current puzzle 
            int count=0;

            // before entering the while loop condition 2(in question) is already satisfied because submask = mask
            while(subMask){
                // checking for the first condition given in question
                if(subMask & first){
                    count += mask_freq[subMask];
                }
                
                // this makes the last(from right) set bit 0 and all zero bits to the right 
                // of it becomes 1
                subMask = subMask-1;
                //if we use this submask in next iteration of loop, then second condition 
                // may not be satisfied
                // so we unset the bits that are set in submask but not in mask 
                // (simply by performing and operation)
                subMask = (subMask & pMask); // turn off only one bit into the submask
            }
            ans.push_back(count);
        }
        return ans;
    }
};

/*
class Solution {
public:

    int getBitMask(string str){
        int mask=0;
        for(auto c : str){
            int bitMaskOfc = (1<<(c-'a'));
            mask = mask | bitMaskOfc;
        }
        return mask;
    }

    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // char(int)--> bitMask corrosponding to each character
        unordered_map<int, vector<int>> bucket; 
        // optimize it

        for(auto puzzle: puzzles){
            int c = puzzle[0]-'a'; // first char of 
            vector<int> vec;
            bucket.insert({c, vec});
        } 

        for(string word: words){
            int temp = getBitMask(word);

            for(auto it:bucket){
                int i=it.first;
                if((temp&(1<<i))!=0){
                    bucket[i].push_back(temp);
                }
            }

        }

        vector<int> res;
        for(string p:puzzles){
            int pMask = getBitMask(p);
            int c = p[0]-'a'; // first character of puzzle word
            int count=0;
            // search for those words which have first char puzzle character
            for(int wordMask: bucket[c]){
                if((wordMask & pMask)==wordMask){
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
*/