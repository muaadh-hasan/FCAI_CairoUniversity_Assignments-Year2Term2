#include "BigDecimalInt.h"


BigDecimalInt::BigDecimalInt()
{
    num="";
    sign='+';
}

BigDecimalInt::BigDecimalInt(string n)
{
    while(!ok(n)) //Input validation
    {
        cout<<"Invalid input, Enter a valid num: ";
        cin>>n;
    }
    string temp;
    if(n[0]=='-')
    {
        sign='-';
        temp=n.substr(1);
    }
    else
    {
        sign='+';
        temp=n;
    }
    if(temp.find_first_not_of('0')==string::npos) //if the number only consists of zeroes
        {
            sign='+';
            num="0";
        }
    else
        num=temp.substr(temp.find_first_not_of('0')); //only the substring to omit leading zeroes
}

BigDecimalInt& BigDecimalInt::operator=(const BigDecimalInt& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    num=rhs.num;
    sign=rhs.sign;
    return *this;
}


BigDecimalInt BigDecimalInt::operator+(BigDecimalInt &rhs)
{
    if(sign==rhs.sign) //same signs, just add the values with the same sign
        {
            BigDecimalInt temp; //carries the result
            temp.sign=sign;
            int carry=0;
            if(biggerMagnitude(num,rhs.num)==1) //manual sum, digit by digit with putting carry into consideration
            {
                temp.num=num;
                for(int i=rhs.num.size()-1,j=temp.num.size()-1;i>=0;i--,j--)
                {
                    carry+=(rhs.num[i]-'0')+(temp.num[j]-'0');
                    temp.num[j]=(carry%10)+'0';
                    carry/=10;
                    if(i==0) //if the small number finished, continue adding the longer one (like the merge sort)
                    {
                        j--;
                        while(carry!=0 && j>=0)
                        {
                            carry+=(temp.num[j]-'0');
                            temp.num[j]=(carry%10)+'0';
                            carry/=10;
                            j--;
                        }
                    }
                }
                if(carry==1) //add last carry if there is
                    temp.num="1"+temp.num;
            }
            else
            {
                temp.num=rhs.num;
                for(int i=num.size()-1,j=temp.num.size()-1;i>=0;i--,j--)
                {
                    carry+=(num[i]-'0')+(temp.num[j]-'0');
                    temp.num[j]=(carry%10)+'0';
                    carry/=10;
                    if(i==0) //if the small number finished, continue adding the longer one (like the merge sort)
                    {
                        j--;
                        while(carry!=0 && j>=0)
                        {
                            carry+=(temp.num[j]-'0');
                            temp.num[j]=(carry%10)+'0';
                            carry/=10;
                            j--;
                        }
                    }
                }
                if(carry==1) //add last carry if there is
                    temp.num="1"+temp.num;

            }
            return temp;
        }
        // +ve + -ve is equal to +ve - +ve
    else if(sign=='+' && rhs.sign=='-')
        {
            BigDecimalInt temp=rhs;
            temp.sign='+';
            return *this-temp;
        }
    else
        {
            BigDecimalInt temp=*this;
            temp.sign='+';
            return rhs-temp;
        }
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt &rhs)
{
    if (rhs.num=="0")
        return *this;
    if(sign=='+' && rhs.sign=='+') //ready to start subtracting, using adding complement method
    {
        BigDecimalInt temp=rhs;
        temp.num=ten_complement(temp.num,num.size());
        temp.sign='+'; //now we are adding two +ve numbers
        BigDecimalInt res=*this+temp;
        if(res.num.size()>max(num.size(),rhs.num.size()))
            res.num=res.num.substr(1); //discard overflow
        else //no overflow
        {
            res.sign='-';
            res.num=ten_complement(res.num,res.num.size());
        }
        res.num=res.num.substr(res.num.find_first_not_of('0')); //omit any leading zeroes
        return res;
    }
    else if(rhs.sign=='-') // - -ve is equal to +ve
    {
        BigDecimalInt temp=rhs;
        temp.sign='+';
        return *this+temp;
    }
    else if(sign=='-' && rhs.sign=='+')
    {
        BigDecimalInt temp=rhs;
        temp.sign='-';
        return *this+temp;
    }

}


bool BigDecimalInt::ok(const string &n) //check for input validation
{
    for(int i=0;i<n.size();i++)
    {
        if(i==0)
        {
            if(isdigit(n[i])|| n[i]=='-') //checks if the first character is either number or -ve sign
                continue;
            else
                return false;
        }
        else
        {
            if(!isdigit(n[i]))
                return false;
        }
    }
    return true;
}
int BigDecimalInt::biggerMagnitude(const string &first, const string& second) //finds the bigger absolute of the two numbers (regardless the sign)
{
    if(first.size()>second.size())
        return 1;
    else if (first.size()<second.size())
        return 2;
    else
    {
        for(int i=0; i<first.size();i++)
        {
            if(first[i]>second[i])
                return 1;
            else if (first[i]<second[i])
                return 2;
            else
                continue;
        }
        return 1; //they're both equal so anything is fine
    }
}
string BigDecimalInt::ten_complement(string& s,int siz) //the ten's complement to a number stored in (siz) digits
{
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='0')
            continue;
        else
        {
            s[i]=10-(s[i]-'0')+'0';
            i--;
            for(i;i>=0;i--)
                s[i]=9-(s[i]-'0')+'0';
        }
    }
    while(s.size()<siz)
        s="9"+s;
    return s;
}

BigDecimalInt::~BigDecimalInt(void)
{
}
