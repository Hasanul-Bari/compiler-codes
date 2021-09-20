#include<bits/stdc++.h>

using namespace std;

int main()
{
    fstream fin;

    fin.open("input.txt");

    if(fin.fail())
    {
        cout<<"Failed to open file 'input.txt'"<<endl;
        return -1;
    }

    string s;
    int lines=0;

    while(fin)
    {
        getline(fin,s);
        cout<<s<<endl;
        lines++;
    }

    cout<<"number of lines in 'input.txt' file is : "<<lines<<endl;

    return 0;


}

