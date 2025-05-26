#include<bits/stdc++.h>
using namespace std;

// given root of two tree check wether both tree's are idential(same) or not
bool isSame(Node *r, Node *s)
{
    if(r==NULL && s==NULL) return true;
    if(r==NULL || s==NULL) return false;
    return r->data==s->data && isSame(r->left, s->left) && isSame(r->right, s->right);
}

int main(){
    
    return 0;
}