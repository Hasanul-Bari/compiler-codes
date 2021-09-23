#include<bits/stdc++.h>

using namespace std;

int main()
{

    string fileName;
    cout<<"Enter the name of the file(with extension) to be read : ";
    cin>>fileName;

    ifstream fin;

    fin.open(fileName);

    if(fin.fail())
    {
        cout<<"Failed to open file "<<fileName<<endl;
        return -1;
    }
    else
    {
        cout<<fileName<<" file opened successfully"<<endl;
    }

    string line;
    int lineCount=0;

    while(getline(fin,line))
    {
        lineCount++;
    }
    fin.close();

    cout<<"number of lines in "<<fileName<<" file is : "<<lineCount<<endl;

    return 0;

}

