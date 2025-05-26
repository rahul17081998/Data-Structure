class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        // start from last index and fixed the largest element and go left
        int n = arr.size();
        vector<int> ans;
        int pos=n-1;
        
        while(pos>0){
            // check if element is at right position
            if(arr[pos]==pos+1){
                pos--;
            }
            else{ // element is not at position
                // search the element
                int ele = pos+1;
                int elePos;
                for(int i=0; i<pos; i++){
                    if(arr[i]==ele){
                        elePos = i;
                        break;
                    }
                }
                if(elePos!=0) {
                    ans.push_back(elePos+1);
                    // reverse the array from 0 to element position
                    reverse(arr.begin(), arr.begin()+elePos+1);
                }
                // now reverse the array from 0 to pos
                reverse(arr.begin(), arr.begin()+pos+1);
                ans.push_back(pos+1);
                pos--;
            }
            cout<<endl;
        }
        return ans;
    }
};