#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    vector<int> v1;
    vector<int> v2;
    stack<int> s;
    int n,i;
    cin >>n;
    for(i=0;i<n;i++)
    {
        int k;
        cin >>k;
        v1.push_back(k);
        // s.push(k);
    }

    for(i=0;i<n;i++)
    {
        int k;
        cin >>k;
        v2.push_back(k);
    }
    int j=0;
    for(i=0;i<n;i++)
    {
        s.push(v1[i]);
        while(!s.empty() && s.top()==v2[j])
        {
            s.pop();
            j++;
        }
    }
    cout << s.empty();
}