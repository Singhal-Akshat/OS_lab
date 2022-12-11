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
  int ind;
    int seek_time = 0;
    for(int i=0; i<n;i++)
    {
        int mn = INT_MAX;
        int temp;
        for(int j=0; j<a.size() ;j++ )
        {
            temp = abs(head-a[j]);
            if(temp<mn)
            {
               mn = temp;
                ind = j;
            }
        }

    // cout<<
    // cout<<a[vi.second]<<" "<<head<<endl;
    
        seek_time+= abs(head-a[ind]);
        // cout<<"Seek time "<<seek_time<<endl;
        head = a[ind];
        a[ind] = a[a.size()-1];
        a.pop_back();
    }

    cout<<seek_time;
}
