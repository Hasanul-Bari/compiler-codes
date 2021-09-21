#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("input.txt");
    fout.open("output.txt");

    if(fin.fail())
    {
        cout<<"Failed to open file 'input.txt'"<<endl;
        return -1;
    }



    string s;
    int deletion=0;

    bool isSingleLineCmnt=false;
    bool isMultiLineCmnt=false;




    while(getline(fin,s))
    {

        int n=s.length();

        isSingleLineCmnt=false;


        for(int i=0; i<n; i++)
        {
            if(isSingleLineCmnt)
            {
                continue;
            }

            if(isMultiLineCmnt)
            {
                if(i-1>=0 && s[i-1]=='*' && s[i]=='/')
                {
                    isMultiLineCmnt=false;
                }

                continue;
            }


            if(i+1<n && s[i]=='/' && s[i+1]=='/')
            {
                isSingleLineCmnt=true;
                deletion++;
            }

            else if(i+1<n && s[i]=='/' && s[i+1]=='*')
            {
                isMultiLineCmnt=true;
                deletion++;
            }
            else
            {
                fout<<s[i];
            }
        }
        fout<<endl;





    }
    fin.close();

    cout<<"Read from 'input.txt' : success"<<endl;
    cout<<"Delete existing comments : success"<<endl;
    cout<<"write to 'output.txt' (without comment) : success"<<endl<<endl;

    cout<<"Number of Deletion : "<<deletion<<endl;



    return 0;


}



