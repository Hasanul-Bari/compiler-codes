#include<bits/stdc++.h>
using namespace std;

int main()
{
    string fileName;
    cout<<"Enter the name of the file(with extension) to be read : ";
    cin>>fileName;

    ifstream fin;
    ofstream fout;

    fin.open(fileName);
    fout.open("output.txt");

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
    int deletion=0;

    bool isSingleLineCmnt=false, isMultiLineCmnt=false;




    while(getline(fin,line))
    {

        int length=line.length();

        isSingleLineCmnt=false;


        for(int i=0; i<length; i++)
        {
            if(isSingleLineCmnt)
            {
                continue;
            }

            if(isMultiLineCmnt)
            {
                if(i-1>=0 && line[i-1]=='*' && line[i]=='/')
                {
                    isMultiLineCmnt=false;
                }

                continue;
            }


            if(i+1<length && line[i]=='/' && line[i+1]=='/')
            {
                isSingleLineCmnt=true;
                deletion++;
            }

            else if(i+1<length && line[i]=='/' && line[i+1]=='*')
            {
                isMultiLineCmnt=true;
                deletion++;
            }
            else
            {
                fout<<line[i];
            }
        }
        fout<<endl;





    }
    fin.close();
    fout.close();


    cout<<"Delete existing comments : success"<<endl;
    cout<<"write to 'output.txt' (without comment) : success"<<endl<<endl;

    cout<<"Number of Comments Deletion : "<<deletion<<endl;



    return 0;


}



