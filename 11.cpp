#include<bits/stdc++.h>

using namespace std;

int main()
{
    char fileName [100];
    cout<<"Enter the name of the file(with extension) to be read : ";
    cin>>fileName;

    FILE *f1;

    f1=fopen(fileName,"r");

    if(f1==NULL)
    {
        cout<<"Failed to open file 'input.txt'"<<endl;
        return -1;
    }
    else
    {
        cout<<fileName<<" file opened successfully"<<endl;
    }

    char s[200];
    int lineNumber=1;

    while(fgets(s,200,f1)!=NULL)
    {
        cout<<lineNumber<<"   "<<s;
        lineNumber++;
    }

    fclose(f1);




    return 0;


}

