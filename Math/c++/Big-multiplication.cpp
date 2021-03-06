#include <bits/stdc++.h>

using namespace std;

string multiply(string num1, string num2){
    string ans="";
    if (num1[0]=='-'){
        num1 = string(&num1[1],&num1[num1.length()]);
        if (num2[0]=='-'){ans="";num2 = string(&num2[1],&num2[num2.length()]);}
        else ans="-";
    }
    else{
        if (num2[0]=='-'){ans="-";num2 = string(&num2[1],&num2[num2.length()]);}
        else ans="";
    }

    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";

    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;

    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }

    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";
    string s = ans;
    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
}

int main(){

    string a,b;
    a= "-923124512512512";
    b = "98172319627461624";
    cout<<multiply(a,b)<<endl;
}