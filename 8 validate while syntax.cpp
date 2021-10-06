#include<bits/stdc++.h>
using namespace std;

string rel_op[6]= { "==", "!=", ">=", "<=", ">", "<" };
string am_op[5]= { "+", "-", "*", "/", "%" };


bool isValidIdentifier(string id)
{

    if( !(isalpha(id[0]) || id[0]=='_') )
    {
        return false;
    }

    for(int i=1; i<id.length(); i++)
    {

        if( !(isalpha(id[i]) || isdigit(id[i]) || id[i]=='_') )
        {
            return false;
        }
    }

    return true;


}

bool isValidNumber(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if( !isdigit(s[i]) )
        {
            return false;
        }
    }

    return true;
}

bool isAllWhitespace(string s)
{
    for(char c: s)
    {
        if(!isspace(c))
        {
            return false;
        }
    }
    return true;
}


bool isSingleWord(string s)
{
    stringstream str(s);
    string word;
    bool isFound=false;

    while(str>>word)
    {
        if(isFound)
        {
            return false;
        }
        isFound=true;
    }

    return isFound;
}

string getSingleWord(string s)
{
    stringstream str(s);
    string word;
    str>>word;
    return word;
}





bool findWhile(string s)
{
    //cout<<isSingleWord(s)<<" -- "<<getSingleWord(s)<<endl;
    if(isSingleWord(s)  && getSingleWord(s)=="while")
        return true;
    else
        return false;
}


bool isValidCondition(string s)
{
    //cout<<"Inside Condition"<<endl;
    //cout<<s<<endl;



    for(int i=0; i<6; i++)
    {
        //cout<<rel_op[i]<<endl;

        if(s.find(rel_op[i]) < s.length())
        {
            int pos=s.find(rel_op[i]);

            string opd1=s.substr(0,pos);
            string opd2;
            if(i<4)
                opd2=s.substr(pos+2);
            else
                opd2=s.substr(pos+1);


            //cout<<opd1<<" ** "<<opd2<<endl;
            //cout<<isSingleWord(opd1)<<" -- "<<getSingleWord(opd1)<<endl;
            if( !(isSingleWord(opd1) && (isValidIdentifier(getSingleWord(opd1)) || isValidNumber(getSingleWord(opd1)))  ) )
            {
                return false;
            }

            if( !(isSingleWord(opd2) && (isValidIdentifier(getSingleWord(opd2)) || isValidNumber(getSingleWord(opd2))) ) )
            {
                return false;
            }


            return true;
        }
    }

    return false;

}

bool isValidStatement(string s)
{
    //cout<<"Inside statement"<<endl;
    //cout<<s<<endl;

    if(s.find("=") < s.length())
    {
        int pos=s.find("=");

        string res=s.substr(0,pos);
        s=s.substr(pos+1);
        //cout<<res<<" "<<s<<endl;
        if( !(isSingleWord(res) && isValidIdentifier(getSingleWord(res)) )  )
        {
            return false;
        }

        for(int i=0; i<5; i++)
        {
            if(s.find(am_op[i]) < s.length())
            {
                int pos=s.find(am_op[i]);

                string opd1=s.substr(0,pos);
                string opd2=s.substr(pos+1);

                if( !(isSingleWord(opd1) && (isValidIdentifier(getSingleWord(opd1)) || isValidNumber(getSingleWord(opd1)))  ) )
                {
                    return false;
                }

                if( !(isSingleWord(opd2) && (isValidIdentifier(getSingleWord(opd2)) || isValidNumber(getSingleWord(opd2))) ) )
                {
                    return false;
                }


                return true;
            }
        }

        return false;

    }
    else
    {
        return false;
    }

}


bool isValid(string text)
{
    //cout<<text<<endl;

    int pos;
    string left,right;

    //while part
    if(text.find("(")<text.length())
    {
        pos=text.find("(");
        left=text.substr(0,pos);
        right=text.substr(pos+1);

        if(!findWhile(left))
        {
            return false;
        }

    }
    else
    {
        return false;
    }



    // condition part
    if(right.find(")")<right.length())
    {
        pos=right.find(")");
        left=right.substr(0,pos);
        right=right.substr(pos+1);

        if(!isValidCondition(left))
        {
            return false;
        }
    }
    else
    {
        return false;
    }





    //begin part
    if(right.find("begin")<right.length())
    {
        pos=right.find("begin");
        left=right.substr(0,pos);
        right=right.substr(pos+5);

        if(right[0]!=' ')
        {
            return false;
        }
        if( !isAllWhitespace(left) )
        {
            return false;
        }

    }
    else
    {
        return false;
    }


    //statements part


    while(right.find(";")<right.length())
    {
        pos=right.find(";");
        left=right.substr(0,pos);
        right=right.substr(pos+1);

        if(!isValidStatement(left))
        {
            return false;
        }

    }



    //end part
    if(right.find("end")<right.length())
    {
        pos=right.find("end");
        left=right.substr(0,pos);
        right=right.substr(pos+3);

        if( !(isAllWhitespace(left) && isAllWhitespace(right)) )
        {
            return false;
        }
    }
    else
    {
        return false;
    }



    return true;

}


int main()
{
    string fileName;
    cout<<"Enter name of the input text file : ";
    cin>>fileName;

    ifstream fin;
    fin.open(fileName);

    if(fin.fail())
    {
        cout<<"Failed to open "<<fileName<<" file"<<endl;
        return -1;
    }
    else
    {
        cout<<fileName<<" opened successfully"<<endl;
    }

    string line,text;

    while(getline(fin,line))
    {
        text=text+line+" ";
    }

    if(isValid(text))
    {
        cout<<"Input is valid"<<endl;
    }
    else
    {
        cout<<"Input is invalid"<<endl;
    }





    //cout<<isValid(text)<<endl;


}
