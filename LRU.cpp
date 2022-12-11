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

deque<int> q(number_of_pages);
int count=0;
int page_faults=0;
deque<int>::iterator itr;
q.clear();
for(int i:v)
{

	// Insert it into set if not present
	// already which represents page fault
	itr = find(q.begin(),q.end(),i);
	if(itr == q.end())
	{

	++page_faults;

	// Check if the set can hold equal pages
	if(q.size() == number_of_pages)
	{
		q.erase(q.begin());
    }
	
	q.push_back(i);

	}
	else
	{
	// Remove the indexes page
	q.erase(itr);

	// insert the current page
	q.push_back(i);		
	}

}
cout<<page_faults;
}