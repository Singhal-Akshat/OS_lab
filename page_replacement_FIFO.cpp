//FIFO
// 7,0,1,3,2,5,3,1,2,0,1,0 - pages in form of string
// frams = 3 ( inputeed by the user)
//psgr miss and page hit
//page miss -> the page we want to load into memory is not already present ten it is page miss
//page hit -> i it is already in the moemory then it is page hit
// we have to calculate page miss or hit
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<int> v;
    v.push_back(s[0]-'0');
    for(int i=1; i<s.size()-1;i++)
    {
        if(s[i]==',')
        {   
            v.push_back(s[i+1]-'0');
        }
    }

    int number_of_pages;
    cin>>number_of_pages;

    queue<int> q;
    unordered_set<int> st;
    // cout<<"set size = "<<s.size()<<endl;
    int hit=0, miss=0;
    for(int a: v)
    {   
        if(st.find(a)!=st.end())
        {   
            
            hit++;
        }
        else
        {   
            miss++;
            st.insert(a);
            q.push(a);
            if(st.size()>number_of_pages)
            {   
                int g = q.front();
                q.pop();
                st.erase(g);
            }
        }
    }
    cout<<"miss : "<<miss;

}