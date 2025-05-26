/*
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.
Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
*/

class Solution {
public:
    // TC = O(32*max(log(num1), log(num2))), SC =O(1)
    int minimizeXor(int num1, int num2) {

        int countBit1=0, countBit2=0;
        int temp1=num1, temp2=num2;

        // count the number of bits in num1 and num2
        while(temp1>0){
            if((temp1&1)==1){
                countBit1++;
            }
            temp1 = temp1>>1;
        } 

        
        while(temp2>0){
            if((temp2&1)==1){
                countBit2++;
            }
            temp2 = temp2>>1;
        } 
        // X has the same number of bits as num2
        if(countBit1 == countBit2) return num1;

        else if(countBit2 > countBit1){
            int X = num1; // all the bits have here
            int remainBits = countBit2 - countBit1;
            // we have to put these remaining bits when we get 0 from left to right in num1
            int j=0;
            while(num1>0 && remainBits){
                if((num1&1)==0){
                    // cout<<X<<endl;
                    X = X | (1<<j);
                    remainBits--;
                }
                // cout<<j<<endl;
                num1 = num1>>1;
                j++;
            }

            while(remainBits>0){
                X = X | (1<<j);
                j++;
                remainBits--;
            }
            return X;
        }
        else{ // countBit2 < countBit1, you have less bits than num1 bits
            int mask = pow(2,30);
            int X=num1;
            int excessBitsInX = countBit1-countBit2;
            int j=0;


            // cout<<num1<<" "<<excessBitsInX<<endl;
            while(num1>0 && excessBitsInX>0){
                // cout<<"l1 ";
                // subtract the bits 
                if((num1&1)==1){
                    X = X - (1<<j);
                    excessBitsInX--;
                }
                j++;
                num1=num1>>1;
            }
           
            
            return X;
        }
        return 1;
    }
};

