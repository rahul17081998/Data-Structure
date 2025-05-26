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