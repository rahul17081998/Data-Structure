/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
*/

class Solution {
public:
    int findComplement(int num) {
        int complementNo=0, power=0, mask=1;
        while(num>0){
            // when you find a bit is 0 just complement it its will become 1 then add its corrosponding value
            if((num & mask)==0){
                // complementNo += pow(2,power); // or 2nd way is shown below
                complementNo += 1<<power;
            }
            num = num >>1; // right shift
            power++;
        }
        return complementNo;
    }
};