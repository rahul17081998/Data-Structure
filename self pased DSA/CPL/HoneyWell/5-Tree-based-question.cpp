
// 5-Tree-based-question
// given edges in (parent,child) form. Return Lexicographically least Preorder traversal.

/*
5
5 6
5 4
4 8
4 9
6 7
*/

string getpre(int root,unordered_map<int,pair<int,int>> &g){
    string preorder="",c1,c2="";
    preorder+=to_string(root);
    if(g.find(root)==g.end()){
        return preorder;
    }
    c1=getpre(g[root].first,g);
    if(g[root].second!=-1){
        c2=getpre(g[root].second,g);
    }
    if(c1.compare(c2)<0){
        preorder+=c1;
        preorder+=c2;
    }
    else{
        preorder+=c2;
        preorder+=c1;        
    }
    return preorder;
}
void smallestPreorder(int a[][2],int n,unordered_set<int> &s){
    unordered_map<int,pair<int,int>> g;
    int p,c,root;
    for(int i=0;i<n;i++){
        p=a[i][0],c=a[i][1];
        if(g.find(p)==g.end()){
            g[p].first=c;
            g[p].second=-1;
        }
        else{
            g[p].second=c;
        }
        s.erase(c);
    }
    if(s.size()==1){
        root=*s.begin();
    }   
    else{
        cout<<s.size();
        return;
    }
    cout<<getpre(root,g);
}
int main() {
    int n,i=0;
    cin>>n;
    int tree[n][2];
    unordered_set<int> s;
    while(n--){
        cin>>tree[i][0]>>tree[i++][1];
        s.insert(tree[i-1][0]);
        s.insert(tree[i-1][1]);
    }
    smallestPreorder(tree,i,s);
}