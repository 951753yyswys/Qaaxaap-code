#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Group 
{
    int l,r;
    int type;
    int value;
    Group(int l,int r,int type,int value):l(l),r(r),type(type),value(value){}
    bool operator<(const Group& other) const{return l<other.l;}
};
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int> W(N+1);
    for(int i=1;i<=N;i++) cin>>W[i];
    set<Group> groups;
    groups.insert(Group(1,N,1,0));
    int Q;
    cin>>Q;
    for(int q=0;q<Q;q++) 
    {
        int op;
        cin>>op;
        if(op==1||op==2) 
        {
            int v;
            cin>>v;
            auto it=groups.upper_bound(Group(v,0,0,0));
            if(it==groups.begin()) continue;
            it--;
            Group g=*it;
            int vnow;
            if(g.type==1) 
            {
                if(op==1) vnow=g.value;
                else vnow=g.value+W[v];
            } 
            else 
            {
                if(op==1) vnow=g.value-W[v];
                else vnow=g.value;
            }
            vector<Group> tmov;
            vector<Group> tadd;
            auto it2=groups.begin();
            while(it2!=groups.end()&&it2->l<=v) 
            {
                if(it2->r<=v) tmov.push_back(*it2);
                else 
                {
                    Group left=*it2;
                    Group right=*it2;
                    left.r=v;
                    right.l=v+1;
                    tmov.push_back(*it2);
                    tadd.push_back(right);
                }
                it2++;
            }
            for(const Group& gr:tmov) groups.erase(gr);
            for(const Group& gr:tadd) groups.insert(gr);
            groups.insert(Group(1,v,op,vnow));
        } 
        else if(op==3) 
        {
            int x;
            cin>>x;
            int count=0;
            for(const Group& g:groups) 
            {
                if(g.type==1) 
                {
                    if(g.value<=x) 
                    {
                        int need=x-g.value;
                        int left=g.l,right=g.r;
                        int pos=g.r+1;
                        while(left<=right) 
                        {
                            int mid=(left+right)/2;
                            if(W[mid]>need) 
                            {
                                pos=mid;
                                right=mid-1;
                            } 
                            else left=mid+1;
                        }
                        count+=(g.r-pos+1);
                    }
                } 
                else 
                {
                    if(x<g.value) 
                    {
                        int need=g.value- x;
                        int left=g.l,right=g.r;
                        int pos=g.r+1;
                        while(left<=right) 
                        {
                            int mid=(left+right)/2;
                            if(W[mid]>=need) 
                            {
                                pos=mid;
                                right=mid-1;
                            } 
                            else left=mid+1;
                        }
                        count+=(g.r-pos+1);
                    }
                }
            }
            cout<<count<<'\n';
        }
    }
    return 0;
}