
#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    char str1[]="gfg";

    cout<<str1<<endl;
    cout<<"Size of String str1: -> "<<sizeof(str1)<<endl;
    char str2[]={'r','a','h','a','l','\0'};
    cout<<"Size of String str2: -> "<<sizeof(str2)<<endl;
    cout<<str2<<endl;
    
    // Function:-
    // Strlen(str)
    // strcmp(str)
    // strcpy(str)
    
    cout<<endl;


    // Example of strcmp(s1,s2)
    char s1[]="abd";
    char s2 []="acd";
    int res=strcmp(s1,s2);
    if(res>0)
        {cout<<"Greater";}
    else if(res==0)
        {cout<<"Same";}
    else
        {cout<<"Smaller";}
    cout<<endl;


    // Example of strcpy
    char str3[5];
    strcpy(str3,"geeks");
    cout<<"str3 : "<<str3<<endl<<endl;

    // C++ String
    string str4="geeksforgeeks";
    cout<<"\nlenght of str4: "<<str4.length()<<" \n";
    str4=str4+"xyz";
    cout<<str4<<" ";
    cout<<"Rahul : "<<str4.substr(1, 5)<<" ";
    cout<<"\nres: "<<str4.find("eek")<<" "<<endl ;

    // Alternative way of strcmp function
    char s_1[]="abd";
    char s_2 []="bcd";
    
    if(s_1>s_2)
        {cout<<"Greater";}
    else if(s_1==s_2)
        {cout<<"Same";}
    else
        {cout<<"Smaller";}
    cout<<endl;

    // Iterating through a string
    string str6="geeksforgeeksss";
    // sort(str6,str6+str6.length());
    for (int i = 0; i < str6.length(); i++)
    {
        cout<<str6[i];
    }
    cout<<endl;
    // OR other way to iterate through sting
    for(char x:str6)
    {
        cout<<x;
    }

    // Reading string from console
    string str5;
    cout<<"\nEnter your name: ";
    //cin>>str5; 
    getline(cin,str5); // Read string after space also
    cout<<"Your name is "<<str5<<endl;
    
    string x1 = "abd";
    string x2 = "sjd";
    string x3 = x1 + x2;
    cout<<"\nPrint concatinated string: "<<x3;
    */
    string s11 = "abxdl";
    int n = 5;
    int i=5;
    int j=4;
    string left = s11.substr(j, i-j+1);
    string right = s11.substr(i);
    string com = left + right;

    cout<<left<<endl;
    cout<<right<<endl;
    cout<<com<<endl;
     
    return 0;
}