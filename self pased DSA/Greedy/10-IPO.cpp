/*Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
The answer is guaranteed to fit in a 32-bit signed integer.

*/


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       
        // method 3 : using 2 priority queue
     
        // using min heap priority queue
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> proj;
        int n = capital.size();

        for(int i=0; i<n; i++){
            proj.push({capital[i], profits[i]});

        }

        // sort the proj array a/c to capital values
        // sort(proj.begin(), proj.end());  //------------
        // ------- insted of using array(proj) we can use priority queue(min heap)
        priority_queue<int> profit; // sort the profit whose cap is less then current cap(w)
        int j=0; // pointing 1st cap

        for(int i=0; i<k; i++){
           
            while(!proj.empty() && proj.top().first <= w){
                profit.push(proj.top().second);
                proj.pop();
            }

            if(profit.empty()==true) break;
            // take top element from priority queue, that will be maximum
            w = w + profit.top();
            profit.pop();
        }
        return w;
        
        /**************************************************************************/
        
        /*
        // Method 2
        // TC = O(K*logn), SC = O(N)
        vector<pair<int,int>> proj;
        int n = capital.size();

        for(int i=0; i<n; i++){
            proj.push_back({capital[i], profits[i]});
        }

        // sort the proj array a/c to capital values
        sort(proj.begin(), proj.end());
        priority_queue<int> profit; // sort the profit whose cap is less then current cap(w)
        int j=0; // pointing 1st cap

        for(int i=0; i<k; i++){
            // check which the cap whose current value is less then w, push those into priority queue
            while(j<n && proj[j].first <= w){
                profit.push(proj[j].second);
                j++;
            }

            if(profit.empty()==true) break;
            // take top element from priority queue, that will be maximum
            w = w + profit.top();
            profit.pop();
        }
        return w;
        */

        /**************************************************************************/
       

        /*
        // method 1
        // BruteForce approach, TC = O(n*k), SC = O(1)
        int m = min(k, (int)profits.size());
        while(m--){
            // find the maximum profit under w capital
            int maxCap=-1, index=-1;
            bool f=false; // it indicate no capital you have found which is smaller than or equal to w
            for(int i=0; i<profits.size(); i++){
                if(w >= capital[i]){
                    // maxCap = max(maxCap, profits[i]);
                    f=true;
                    if(maxCap<profits[i]){
                        maxCap = profits[i];
                        index=i;
                    }
                }
            }
            if(maxCap!=-1)
                w += maxCap;
            if(f==true)
               capital[index]=INT_MAX;
        }
        return w;
        */
    }
};