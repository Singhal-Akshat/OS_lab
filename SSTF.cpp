//closest first
//sorthest seek time first
//315
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
    int head;
    cin>>head;
    pair<int,int> vi;
    int seek_time = 0;
    for(int i=0; i<n;i++)
    {
        vi.first = INT_MAX;
        int temp;
        for(int j=0; j<a.size() ;j++ )
        {
            temp = abs(head-a[j]);
            if(temp<vi.first)
            {
                vi.first = temp;
                vi.second = j;
            }
        }

    // cout<<
    // cout<<a[vi.second]<<" "<<head<<endl;
    
        seek_time+= abs(head-a[vi.second]);
        // cout<<"Seek time "<<seek_time<<endl;
        head = a[vi.second];
        a[vi.second] = a[a.size()-1];
        a.pop_back();
    }

    cout<<seek_time;
}