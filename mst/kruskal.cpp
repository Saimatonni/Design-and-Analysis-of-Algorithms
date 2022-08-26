#include<bits/stdc++.h>
using namespace std;
/*-------------------------------------------------method 1----------------------------------------------------*/
//using path compression

/* a class of find union function*/
class disjoin{
    int* parent;
    int*rank;
  public:
    disjoin(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }

    }

    int find(int i){ 
        if(parent[i]==-1){
            return i;
        }

    return parent[i]=find(parent[i]);
    }
    int find_without_path_com(int i){ 
        if(parent[i]==-1){
            return i;
        }

    return find(parent[i]);
    }

    void Union(int x,int y){
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    void Union_without_path_com(int x,int y){
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2){
            parent[s2]=s1;
        }
    }

};

class graph{
    vector<vector<int> > el;
    long int V;

    public:
       graph(int V){
        this->V=V;
       }

       void addEdge(int x,int y,int w){
          el.push_back({w,x,y});
       }
       void kruskals(){
        sort(el.begin(),el.end());  /*Sorting of edges takes O(ELogE) time*/
        disjoin s(V);
        int ans=0;
        cout<<"Edge     \tweight\n";
        for(auto edge: el){
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            //check to not form a cycle
            if(s.find(x)!=s.find(y)){ /*find function take  O(LogV) time*/
                s.Union(x,y); /*union function take  O(LogV) time*/
                ans+=w;
                cout<<x<<" - "<<y<<" \t"<<w<<" \n";
            }
        }
        cout<<"Minimum spnning tree:  "<<ans;
       }
       /*overall complexity is O(ELogE + ELogV) time*/
};
void kruskalalgo_usingpathcom(){
   clock_t start, end;
     start = clock();
    freopen("kruskal_input.txt","r",stdin);
    freopen("kruskal_output.txt","w",stdout);
    cout<<"kruskal algorithom using path compression\n"<<endl;
   long int v,e;
    cin>>v>>e;
    graph g(v);
    for(int i=0;i<e;i++){
        long int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x,y,w);

    }
 
      // Function call
    g.kruskals();
     end = clock();
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*---------------------------------------------------------------------------end of method 1-----------------------------------------------*/







/*----------------------------------------------------------------------------method 2-----------------------------------------------------*/
 //without path compression

class graph2{
    vector<vector<int> > el;
    long int V;

    public:
       graph2(int V){
        this->V=V;
       }

       void addEdge(int x,int y,int w){
          el.push_back({w,x,y});
       }
       void kruskals(){
        sort(el.begin(),el.end());  /*Sorting of edges takes O(ELogE) time*/
        disjoin s(V);
        int ans=0;
        cout<<"Edge     \tweight\n";
        for(auto edge: el){
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            //check to not form a cycle
            if(s.find_without_path_com(x)!=s.find_without_path_com(y)){ /*find function take  O(LogV) time*/
                s.Union_without_path_com(x,y); /*union function take  O(LogV) time*/
                ans+=w;
                cout<<x<<" - "<<y<<" \t"<<w<<" \n";
            }
        }
        cout<<"Minimum spnning tree:  "<<ans;
       }
       /*overall complexity is O(ELogE + ELogV) time*/
};
void kruskalalgo_without_usingpathcom(){
   clock_t start, end;
     start = clock();
    freopen("kruskal_input.txt","r",stdin);
    freopen("kruskal_output.txt","w",stdout);
    cout<<"kruskal algorithom without using path compression\n"<<endl;
   long int v,e;
    cin>>v>>e;
    graph2 g(v);
    for(int i=0;i<e;i++){
        long int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x,y,w);

    }
 
      // Function call
    g.kruskals();
     end = clock();
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*----------------------------------------------------------------------------------end of method 2-------------------------------------------*/





int main(){
    int n;
    cout<<"Enter 1: kruskal algorithom using path compression\n"<<endl;
    cout<<"Enter 2: kruskal algorithom without using path compression\n"<<endl;
    cin>>n;
    if(n==1){
        kruskalalgo_usingpathcom();
    }
    else if(n==2){
        kruskalalgo_without_usingpathcom();
    }
    return 0;
}