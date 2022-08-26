#include<bits/stdc++.h>
using namespace std;

class graph{
  public: 
     bool visit[10];
     map<int, list<int>> adjen;
     void addedge(int v, int w);
     void dfs(int v);
};

void graph::addedge(int a,int b){
    adjen[a].push_back(b);
}

void graph::dfs(int vert){
    visit[vert]=true;
    cout<<vert<<" ";
    list<int>::iterator i;
    for(i=adjen[vert].begin();i!=adjen[vert].end();++i){
        if(!visit[*i]){
            dfs(*i);
        }
    }
}

int main(){
    graph g;
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    g.dfs(2);
    return 0;
}