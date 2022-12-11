// 41, 14, 122, 98, 53, 124, 183, 65, 67
//                  head a 53
// cylinder: 0 -199
//now first come first serve
// 53-41 + 41-14 + 122-14 + 
//632
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

    int seek_time=0;
    for(int num : a)
    {   
        
        seek_time+=abs(head-num);
        head = num;
    }
    cout<<seek_time;

}