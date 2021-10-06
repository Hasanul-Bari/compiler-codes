/*
problem: Write a C/C++ program to identify whether a given input line is a comment or not.
*/


#include<iostream>
using namespace std;

int main()
{
    string line;
    cout<<"Enter a line : ";

    getline(cin,line);

    int lineLength=line.length();

    bool isComment=false;

    if(lineLength>=2 && line[0]=='/' && line[1]=='/')
    {
        isComment=true;
    }

    if(lineLength>=4 && line[0]=='/' && line[1]=='*' && line[lineLength-2]=='*' && line[lineLength-1]=='/')
    {
        isComment=true;
    }

    //cout<<isComment<<endl;

    if(isComment)
    {
        cout<<"Given input line is a comment"<<endl;
    }
    else
    {
        cout<<"Given input line is not a comment"<<endl;
    }



    return 0;
}
