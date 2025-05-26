/*
Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
*/

class Solution {
public:
    // Note: Fixed width unsigned 32 bit integer: uint32_t. It means give me an unsigned int of exactly 32 bits.
    TC = O(logN)
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = pow(2,31); // 1000000...00 ----> 32 bit mask
        uint32_t val=0;
        int power=0;
        while(mask>0){
            if(mask&n){
                val += 1<<power;
            }
            power++;
            mask = mask>>1; // right shift maks by one bit
        }
        return val;
    }
};

