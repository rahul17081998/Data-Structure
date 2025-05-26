// 1-Team-formation
// Sol link1: https://github.com/naz-mul94/company-Based-question/blob/master/mathworks/2020/teamFormation.cpp
// Sol link1: https://github.com/marioyc/Online-Judge-Solutions/blob/master/hackerrank/101aug14/team-formation.cpp


/*
** any suggestion highly appreciated
** feel free to modify.
*/

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

long long int teamFromation(vector<int> score, int noMember, int m)
{
    long long int ans=0;
    int n=score.size();
    priority_queue<pair<int, int> > memberScore;
    for(int i=0;i<m;i++)memberScore.push(make_pair(score[i], i));
    for(int i=n-m;i<n;i++)memberScore.push(make_pair(score[i], i));    
    int low=m-1;
    int high=n-m;
    while(high>low && noMember)
    {
        pair<int, int> temp=memberScore.top();
        memberScore.pop();
        ans+=temp.first;
        noMember--;
        if(temp.second<=low)
        {
            low++;
            if(low < high)
                memberScore.push(make_pair(score[low], low));
        }
        else if(temp.second>=high)
        {
            high--;
            if(high>low)memberScore.push(make_pair(score[high], high));
        }
    } 
    while(!memberScore.empty() && noMember)
    {
        ans+=memberScore.top().first;
        memberScore.pop();
        noMember--;
    }   
    return ans;
}


int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        int noSore,noMember, m;
        cin>>noSore>>noMember>>m;
        vector<int> score(noSore);
        for(int i=0;i<noSore;i++)
            cin>>score[i];
        cout<<teamFromation(score, noMember, m)<<endl;
    }
}


// 2-distinct-pairs
// link gfg: https://www.geeksforgeeks.org/count-distinct-pairs-with-given-sum/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

//write your function here
int cntDisPairs(vector<int> arr, int target)
{
    unordered_set<int> set, seen;
    // int count=0;
    // for(int i=0; i<arr.size(); i++)
    // {
    //     if(st.find(target-arr[i])!=st.end() && seen.find(arr[i])==seen.end()){
    //         seen.insert(arr[i]);
    //         seen.insert(target-arr[i]);
    //         count++;
    //     }
    //     st.insert(arr[i]);
    // }
    // return count;
    int count = 0;
     
    for(int num : arr) {
        if(set.find(target-num) != set.end() && seen.find(num) == seen.end() ) {
            count++;
            seen.insert(num);
            seen.insert(target-num);
        }
        set.insert(num);
    }
    return count;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(45);
    arr.push_back(46);
    arr.push_back(46);
    int target = 47;
    cout << cntDisPairs(arr, target);
    return 0;
}
/*
Input: nums = [1, 1, 2, 45, 46, 46], target = 47
Output: 2
Explanation:
1 + 46 = 47
2 + 45 = 47
*/

// 3-Tom-Jerry-in-a-Maze
// https://leetcode.com/discuss/interview-question/1561552/Mathworks-OA-Tom-and-Jerry-in-a-Maze#:~:text=Tom%20can%20move%20in%20all,x%2Dcoordinate%20for%20Jerry's%20location.
// https://www.careercup.com/question?id=5749266532270080

#include <iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct point
{
    long long x,y,searched=0;
};

struct ans
{
	int index=0;
	int steps=0;
}a;

struct ans fun(vector<point> v,struct ans a,int start,int k)
{

	v[start].searched=1;
	if(k==0) return a;
	else
	{
	double diff_x, diff_y;
    int i=0;
    while(v[i].searched ==1 && i<v.size()-1){i++;}

    diff_x = abs(v[start].x - v[i].x);
    diff_y = abs(v[start].y - v[i].y);

    int best = i;
    double best_dist = sqrt(pow(diff_x,2)+ pow(diff_y,2));
    double hold_dist;

    for(int j=i+1; j<(int)v.size()-1; ++j)
    {
    	if(v[j].searched !=1)
    	{
       		  diff_x = abs(v[start].x - v[j].x);
    		  diff_y = abs(v[start].y - v[j].y);

        hold_dist=sqrt(pow(diff_x,2)+pow(diff_y,2));

        if(hold_dist < best_dist)
        {
            best_dist = hold_dist;
            best = j;
        }
    	}

    }

	v[best].searched=1;


	diff_x=abs(v[best].x- v[start].x);
	diff_y=abs(v[best].y- v[start].y);

	a.steps=a.steps+std::max(diff_x,diff_y);
	a.index=best;
	k=k-1;
    return fun(v,a,best,k);
    }
}


int main() {
	// your code goes here
	vector<point> v;
	int k;
	cin>>k;
	point p;
	for(int i=0;i<=k+1;i++)
	{
		if(i==0) {p.x=0;p.y=0;}
		else{cin >> p.x ;
		cin >> p.y;}
		v.push_back(p);
	}

	ans a;
	a=fun(v,a,0,k);

	// steps to reach to jerry
	double diff_x, diff_y;
	diff_x=abs(v[a.index].x-v[k+1].x);
	diff_y=abs(v[a.index].y-v[k+1].y);

	a.steps=a.steps+max(diff_x,diff_y);

	cout << a.steps;
	return 0;
}

// 4-Reduced-Fraction-Sums
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
/*You are required to complete this function*/
void addFraction(int num1, int den1, int num2,int den2)
{
//Your code here
    int nx = num1*den2 + num2*den1;
    int dx = den1*den2;
    int gcf = gcd(nx,dx);
    // cout<<endl;
    // cout<<nx/gcf<<"/"<<dx/gcf<<endl;
    string ans = "";
    ans = to_string(nx/gcf) + "/" + to_string(dx/gcf);
    cout<<ans<<endl;
 }

void solve1(string s){
    int num1, den1,num2,den2;
    vector<int> v;
    int i=0;
    int n = s.length();


    string sn="";
    int start=0;
    while(i<n)
    {
       
        if(s[i]!='/' || s[i]!='+')
            sn = sn + s[i];
        else if(s[i]=='+' || s[i]=='/'){
            cout<<sn<<" ";
            sn="";
        }
        
        if(s[i]=='/' || s[i]=='+'){
        
        // cout<<s.substr(start, i-start)<<" ";
        string st = s.substr(start, i-start);
        int a = stoi(st);
        v.push_back(a);
        start=i+1;
        }
        i++;
        
    }
    // cout<<s.substr(start, i-start)<<" ";
    string st = s.substr(start, i-start);
    int a = stoi(st);
    v.push_back(a);
    addFraction(v[0], v[1], v[2], v[3]);
}

void fun(vector<string> num)
{
    for(int i=0; i<num.size(); i++){
        solve1(num[i]);
        cout<<endl;
    }
}
int main()
{
   



    string s1 = "722/148+360/176";
    vector<string> num;
    num.push_back("722/148+360/176");
    num.push_back("978/1212+183/183");
    num.push_back("358/472+301/417");
    num.push_back("780/309+684/988");
    num.push_back("258/840+854/686");
    fun(num);
    return 0;
}
// 722/148+360/176
// 978/1212+183/183
// 358/472+301/417
// 780/309+684/988
// 258/840+854/686
// } Driver Code Ends




 /*
 
2
384 887 778 916
794 336 387 493

o/p:
520915/406246
260737/82824
 */

// 5-Intelligent-substring
// https://leetcode.com/discuss/interview-question/830653/intelligent-substring-online-assessment-stuck-in-the-question-


#include <bits/stdc++.h>
using namespace std;

class SpecialSubstring
{
public:
    int getSpecialSubstring(string str, string bitString, int k)
    {
        int len = str.length();
        if (!len)
            return 0;
        int maxSubstringLen = 0;
        int windowStart = 0;
        int cnt = 0;
        for (int windowEnd = 0; windowEnd < len; windowEnd++)
        {
            int pos = str[windowEnd] - 'a';
            if (bitString[pos] == '0')
                cnt++;
            while (cnt > k and windowStart <= windowEnd)
            {
                pos = str[windowStart] - 'a';
                if (bitString[pos] == '0')
                    cnt--;
                windowStart++;
            }
            maxSubstringLen = max(maxSubstringLen, windowEnd - windowStart + 1);
        }
        return maxSubstringLen;
    }
};
int main()
{
    SpecialSubstring specialSubstring;
    cout << specialSubstring.getSpecialSubstring("normal", "00000000000000000000000000", 1) << endl;
    cout << specialSubstring.getSpecialSubstring("giraffe", "01111001111111111011111111", 2) << endl;
    return 0;
}


// 6-Simple-queries
// https://www.geeksforgeeks.org/element-1st-array-count-elements-less-equal-2nd-array/
//{ Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array

// Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. For each element in arr1[] count elements less than or equal to it in array arr2[].


#include <bits/stdc++.h>
 
using namespace std;


// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
// elements less than or equal to it in 2nd array
int binarySearch(int target,int arr[],int l,int u)
    {
     int mid;
     while(l<=u)
     {
      mid=l+(u-l)/2;
      if(arr[mid]<=target)
       l=mid+1;
      else
       u=mid-1;
     }
     return l;
    }

class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
    //Your code goes here
        vector<int> v;
        sort(arr2,arr2+n);
        
        for(int i=0; i<m; i++)
        {
            
            v.push_back(binarySearch(arr1[i],arr2, 0, n-1));
        }
        return v;

    }
};

//{ Driver Code Starts.
int main()
{
   
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    
    return 0;

/*
6 6
1 2 3 4 7 9
0 1 2 1 1 4

o/p: 
4 5 5 6 6 6 
*/
}
// } Driver Code Ends


// 7-DIAMOND-MINE
// link: https://leetcode.com/problems/cherry-pickup/#:~:text=The%20total%20number%20of%20cherries,this%20is%20the%20maximum%20possible.


class Solution {
public:
    
    // Method 2: recursive + memoization
    
    int cp(int r1, int c1, int r2, int c2, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp)
    {
        int n = grid.size();
        // base case
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
            
        // if p1 and p2 reach destination
        if(r1==grid.size()-1 && c1==grid[0].size()-1)
        {
            return grid[r1][c1];
        }
        
         // if person 2 reached the bottom right, return what's in there (could be 1 or 0)
        if(r2==grid.size()-1 && c2==grid[0].size()-1)
        {
            return grid[r2][c2];
        }
            
        if(dp[r1][c1][r2][c2]!=0)
            return dp[r1][c1][r2][c2];
        
        int cherry=0;
        // collect cerry
        if(r1==r2 && c1==c2)
            cherry += grid[r1][c1];
        else
            cherry += grid[r1][c1] + grid[r2][c2];
        
        int f1=cp(r1, c1+1, r2, c2+1, grid, dp); // h, h
        int f2=cp(r1+1, c1, r2, c2+1, grid, dp); // v, h
        int f3=cp(r1+1, c1, r2+1, c2, grid, dp); // v, v
        int f4=cp(r1, c1+1, r2+1, c2, grid, dp); // h, v
        
        cherry += max({f1, f2, f3, f4});
        dp[r1][c1][r2][c2] = cherry;
        return cherry;
    }
    
    
    
    /*
    // Method 1:
    // Backtracking solution
    // time complecity = O(2^nn) * O(2^nn) = O(4^nn)
    // ccsf --> cherry collected so far
    int maxcc=0; // maximum cherry collection
    
    void helper(int row, int col, vector<vector<int>> &grid, int ccsf)
    {
        // boundry check and wall
        if(row<0 || row>=grid.size() || col<0 || col >= grid[0].size() || grid[row][col]==-1)
            return;
        
        if(row==0 && col==0){
            maxcc = max(maxcc, ccsf);
            return;
        }
            
        
        int cherries = grid[row][col];
        grid[row][col] = 0; // collect charray, remove cherry 
        helper(row, col-1, grid, ccsf + cherries); // left move
        helper(row-1, col, grid, ccsf + cherries); // up move
        grid[row][col] = cherries; // back tracking
    }
    
    void cp1(int row, int col, vector<vector<int>> &grid, int ccsf)
    {
        // boundry check and wall
        if(row<0 || row>=grid.size() || col<0 || col >= grid[0].size() || grid[row][col]==-1)
            return;
        
        if(row == grid.size()-1 && col == grid[0].size()-1)
            helper(row, col, grid, ccsf);
        
        int cherries = grid[row][col];
        grid[row][col]=0; // collect charray, remove cherry 
        cp1(row, col+1, grid, ccsf + cherries); // right move
        cp1(row+1, col, grid, ccsf + cherries); // down move
        grid[row][col] = cherries; // back tracking
    }
    */
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        // method 2
        int n = grid.size();
        // int dp[n+1][n+1][n+1][n+1]={0};
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0))));
        
        int ans = cp(0, 0, 0, 0, grid, dp);
        return max(0, ans);
        
        /*
        // Method 1:
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1) 
            return max(grid[n-1][m-1], 0);
        
        cp1(0, 0, grid, 0);
        return maxcc;*/
    }
};



// 8-game-winner
/*
https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/submissions/
Count "AAA" and "BBB" and compare them

You can only remove an A that is surrounded by two other A's.
So if you keep on removing valid A's, then the valid B's are not affected. Same goes for all valid B's.
You just count all the valid A's and valid B's. At each turn, Alice removes a valid A and the count of all valid A's (countA) decreases by one. Similarly after Bob's turn, countB decreases by one.
So if countA > countB, then a turn comes when Bob has no valid B's to remove. So he loses and Alice wins. You return TRUE.
Else if countA == countB, then at some point Alice has no valid A's to remove, So Bob wins and you return FALSE.
Else (countA < countB), then at some point Alice has no valid A's to remove. So Bob wins and you return FALSE.

In either case, if countA <= countB, then you return FALSE.
So just return countA > countB
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int a=0, b=0;
        for(int i=1; i<colors.length(); i++){
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]){
                if(colors[i]=='A')
                    a++;
                else
                    b++;
            }
        }
        return a>b;
    }
};

// 9-Weird-faculty
#include<bits/stdc++.h>
using namespace std;
void prt(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
//write your function here
int fun(vector<int> &v)
{
    int n = v.size();
    vector<int> left(n); 
    vector<int> right(n);

    int sum=0;
    for(int i=0; i<n; i++){
        if(v[i]==1){
            sum++;
            left[i]=sum;
        }
        else{
            sum--;
            left[i]=sum;
        }
    }
    sum=0;
    for(int i=n-1; i>=0; i--){
        if(v[i]==1){
            sum++;
            right[i]=sum;
        }
        else{
            sum--;
            right[i]=sum;
        }
    }

    // prt(left);
    // prt(right);

    for(int i=0; i<n; i++){
        if(left[i] > right[i])
            return i;
    }
    return -1;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);

    cout<<fun(v)<<endl;
    return 0;
}

// 10-Beautiful-Arrangement
// link: https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    int countArrangement(int n) {
        vector<int> vs;
        for(int i=0; i<n; i++) vs.push_back(i+1);
        return count(n, vs);
    }
    
    int count(int n, vector<int> &vs){
        
        if(n<=0) return 1;
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(vs[i]%n==0 || n%vs[i]==0){
                swap(vs[i], vs[n-1]);
                ans += count(n-1, vs);
                swap(vs[i], vs[n-1]);
            }
        }
        return ans;
    }
};