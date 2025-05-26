#include<bits/stdc++.h>
using namespace std;

void ASCIISentence(string str)
{
    int converter;
    for (int i = 0; i < str.length(); i++)
    {
        converter = str[i];
        cout<<converter;
    }
    
}

int main(){
    string str = "GeeksforGeeks";
    cout << "ASCII Sentence:" << endl;
    ASCIISentence(str);
    return 0;
}