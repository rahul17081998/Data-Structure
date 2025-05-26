/*
Given an integer array data representing the data, return whether it is a valid UTF-8 encoding (i.e. it translates to a sequence of valid UTF-8 encoded characters).

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For a 1-byte character, the first bit is a 0, followed by its Unicode code.
For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

*/


class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rembytes=0;
        for(int val: data){
            if(rembytes==0){
                // check last bit(8th) is zero or 10 or 110, or 1110 ..etc
                if(val >>7 == 0b0){ // 1st byte of 1 length char
                    rembytes = 0;
                }
                else if(val>>5 == 0b110){ // 1st byte of 2 length char
                    rembytes = 1;
                }
                else if(val>>4 == 0b1110){ // 1st byte of 3 length char
                    rembytes = 2;
                }
                else if(val>>3 == 0b11110){ // 1st byte of 4 length char
                    rembytes = 3;
                }
                else 
                    return false;
            }
            else{
                if(val>>6 ==0b10){
                    rembytes--;
                }
                else 
                    return false;
            }            
        }


        if(rembytes == 0) {
            return true;
        } else {
            return false;
        }


        
        return true;
    }
};