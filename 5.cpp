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

    string line;
    int lineCount=0;

    while(getline(fin,line))
    {
        lineCount++;
    }
    fin.close();

    cout<<"number of lines in 'input.txt' file is : "<<lineCount<<endl;

    return 0;

}

