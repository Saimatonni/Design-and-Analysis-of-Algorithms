#include<bits/stdc++.h>
using namespace std;


/*---------------------------------------------------------method 1-----------------------------------------&/
/* with out using heap*/
#define V 5

/* a funtion to find the vertice with minimum key value before included in bst*/
int  minikey(long int key[],bool mst[])
{
    int min=INT_MAX,minidx;
    for(int i=0;i<V;i++){
        if(mst[i]==false && key[i]<min){
            min=key[i];
            minidx=i;
      }
    }
    return minidx;
}

/*function to print the mst stored in parent[]*/
void printmst(long int parent[], long int graph[V][V]){
    cout<<"Edge  \tweight\n";
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
    }
}
/*funrtion to construct and print MST for a graph represented using adj matsrix representation*/
void prim(long int graph[V][V]){
    long int parent[V];
    long int key[V];
    bool mst[V];
    //inlization key value as false
    for(int i=0;i<V;i++){
        key[i]=INT_MAX,mst[i]=false;
    }
    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<V-1;i++){
        int u=minikey(key,mst);
        mst[u]=true;
        //update key value and index of vertices which are not yet included in mst*/
        for(int v=0;v<V;v++){
            if(graph[u][v] && mst[v]==false && graph[u][v]<key[v]){
                parent[v] = u;
                key[v]=graph[u][v];
            }
        }
    }
    printmst(parent,graph);
}

void primalgo_withoutheap(){
    clock_t start, end;
    start = clock();
    freopen("prim_input2.txt","r",stdin);
    
    freopen("prim_output.txt","w",stdout);
    cout<<"output for prim algo without heap"<<endl;
    long int graph[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
           cin>>graph[i][j];
        }
    }
    
    prim(graph);
   
    end = clock();
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;

}
/* time complexity for this method is  O(V2)*/

/*-----------------------------------------------------------------------end of method 1------------------------------------------------------*/








/*-------------------------------------------------------------------------method 2----------------------------------------------------------*/
//using priority_queue

# define INF 0x3f3f3f3f
typedef pair<int,int>ipair;
class graph{
    int ver;
    list< pair<int,int>>*adj;
    public:
      graph(int ver);
      void addEdge(int u,int v,int w);
      void Printmst();
};
graph::graph(int v){
    this->ver=v;
    adj=new list<ipair> [v];
}
void graph::addEdge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void graph::Printmst(){
    priority_queue<ipair, vector<ipair>, greater<ipair>>pq;
    int src=0;
    vector<int> key(ver,INF);
    vector<int> parent(ver,-1);
    vector<bool> inmst(ver,false);
    /*inserting source itself in priority queue and initialize
    its key as 0*/
    pq.push(make_pair(0,src));
    key[src]=0;
   /* looping till priority queue becomes empty*/
   while(!pq.empty()){
    /* the first vertex in pair is the minimum key*/
    int u=pq.top().second;
    pq.pop();
    /*Different key values for same vertex may exist in the priority queue.
          The one with the least key value is always processed first.
          Therefore, ignore the rest.*/
      if(inmst[u]==true){
        continue;
      }
      inmst[u]=true; //include vertex in mst
      list< pair<int,int>>::iterator i;
      for(i=adj[u].begin();i!=adj[u].end();++i){
        /*get vertex label and weight of current adjacent of u*/
        int v =(*i).first;
        int weight=(*i).second;
        if(inmst[v]==false && key[v]>weight){
            key[v]=weight;
            pq.push(make_pair(key[v],v));
            parent[v]=u;
        }
      }
   }
   cout<<"Edges\n";
    for(int i=1;i<ver;i++){
        cout<<parent[i]<<" - "<<i<<" \n";
    }
}
void primalgo_priority_queue(){
    clock_t start, end;
     start = clock();
    freopen("prim_input.txt","r",stdin);
    freopen("prim_output.txt","w",stdout);
    cout<<"output for prim algo using priority queue"<<endl;
    long int ver,e;
    cin>>ver>>e;
    graph g(ver);
    for(int i=0;i<e;i++){
       long int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x,y,w);

    }
 
      // Function call
    g.Printmst();
     end = clock();
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}
/*time complexity for this algo  O(E Log V))*/
/*-------------------------------------------------------------------------end of method 2---------------------------------------*/







/*------------------------------------------------------------------------ method 3 --------------------------------------------*/
//using  min-heap 

//struct to represent a node in adj list
struct adjnode{
    int des;
    int wgt;
    struct adjnode* next;
};

//structure to represent adj list
struct adjlist{
    struct adjnode* head;
};

//a struct to represent a graph
struct Graph{
    int v;
    struct adjlist* array;
};

//to create a new adj node
struct adjnode* newadjnode(int des, int wgt){
    struct adjnode* n = (struct adjnode*)malloc(sizeof(struct adjnode));
    n->des=des;
    n->wgt=wgt;
    n->next=NULL;
    return n;
}
//creating a graph of vertices v
struct Graph* creategraph(int v){
    struct Graph* g=(struct Graph*)malloc(sizeof(struct Graph));
    g->v=v;
    //array of adj list
    g->array=(struct adjlist*)malloc(v* sizeof(struct adjlist));
    /*initializing adj as empty by making head as null*/
    for(int i=0;i<v;i++){
        g->array[i].head=NULL;
    }
    return g;
}

void addedge(struct Graph* g,int src,int des,int wgt){
    /*adding edge from src to dest,new node is added to the adj of src. node is added at the beggining*/
    struct adjnode* n=newadjnode(des,wgt);
    n->next=g->array[src].head;
    g->array[src].head=n;

    /*as graph is undirected des to src also*/
    n=newadjnode(src,wgt);
    n->next=g->array[des].head;
    g->array[des].head=n;
}
//struct to present a min-heap node
struct minhnode{
    int v;
    int val;
};

//struct to present a min heap
struct minheap{
    int s;
    int capacity;
    int* pos;
    struct minhnode** array;
};

//create a min heap node
struct minhnode* newminhnode(int v,int val){
    struct minhnode* n=(struct minhnode*)malloc(sizeof(struct minhnode));
    n->v=v;
    n->val=val;
    return n;
}

struct minheap* createminheap(int capacity){
    struct minheap* h=(struct minheap*)malloc(sizeof(struct minheap));
    h->pos=(int*)malloc(capacity* sizeof(int));
    h->s=0;
    h->capacity=capacity;
    h->array=(struct minhnode**)malloc(capacity * sizeof(struct minhnode*));
    return h;
}
//swap node
void swaph(struct minhnode** a,minhnode**b){
    struct minhnode* t=*a;
    *a=*b;
    *b=t;
}
// A standard function to heapify at given idx
// This function also updates position of nodes when they
// are swapped. Position is needed for decreaseKey()
void min_heapify(struct minheap* h,int idx){
    int smallest,left,right;
    smallest=idx;
    left=2*idx+1;
    right=2*idx+2;
    if(left<h->s && h->array[left]->val < h->array[smallest]->val){
        smallest=left;
    }
    if(right<h->s && h->array[right]->val < h->array[smallest]->val){
        smallest=right;
    }
    if(smallest!=idx){
        //node swapp in min heap
       minhnode* smallnode=h->array[smallest];
       minhnode* idxn=h->array[idx];
       //swap pos
       h->pos[smallnode->v]=idx;
       h->pos[idxn->v]=smallest;
       swaph(&h->array[smallest],&h->array[idx]);
       min_heapify(h,smallest);
    }
}

int checkempty(struct minheap* h){
    return h->s=0;
}

struct minhnode* extractMin(struct minheap* h)
{
    if (checkempty(h)){
        return NULL;
    }
 
    // Store array[0] in the root node
    struct minhnode* root = h->array[0];
 
    // Replace root node with last node
    struct minhnode* lastn = h->array[h->s - 1];
    h->array[0] = lastn;
 
    // Update position of last node
    h->pos[root->v] = h->s - 1;
    h->pos[lastn->v] = 0;
 
    // Reduce heap size and heapify root
    --h->s;
    min_heapify(h, 0);
 
    return root;
}
/* Function to decrease key value of a given vertex v. This function uses pos[] of min heap to get the current index of node in min heap*/
void decreval(struct minheap* h, int v, int val)
{
    // Get the index of v in  heap array
    int i = h->pos[v];
 
    // Geting the node and updating its  value
    h->array[i]->val = val;
 
    /*traveling up while the complete tree is not hepified.*/
    while (i && h->array[i]->val < h->array[(i - 1) / 2]->val) {
        // Swaping this node with its parent
        h->pos[h->array[i]->v] = (i - 1) / 2;
        h->pos[h->array[(i - 1) / 2]->v] = i;
        swaph(&h->array[i], &h->array[(i - 1) / 2]);
        // move to parent index
         i = (i - 1) / 2;
    }
}
bool inminheap(struct minheap* h,int v){
    if(h->pos[v] < h->s){
        return true;
    }
    return false;
}
void printa(int a[],int n){
    cout<<"Edges\n";
    for(int i=1;i<n;i++){
        cout<<a[i]<<" - "<<i<<" \n";
    }
}

void hprimmst(struct Graph* g){
    int v = g->v;
    int parent[v];
    int key[v]; 
 
    // minHeap represents set E
    struct minheap* h = createminheap(v);
 
    /* Initializing min heap with all vertices.  value of
     all vertices (except 0th vertex) is initially infinite*/
    for (int i = 1; i < v; ++i) {
        parent[i] = -1;
        key[i] = INT_MAX;
        h->array[i] = newminhnode(i, key[i]);
        h->pos[i] = i;
    }
 
    // Making key value of 0th vertex as 0 so that it is extracted first
    key[0] = 0;
    h->array[0] = newminhnode(0, key[0]);
    h->pos[0] = 0;
 
    // Initially size of min heap is equal to V
    h->s= v;
 
    // In the following loop, min heap contains all nodes not yet added to MST.
    while (!checkempty(h)) {
        // Extract the vertex with minimum key value
        struct minhnode* mh  = extractMin(h);
        int u = mh->v; // Store the extracted vertex number
 
        /* Traverse through all adjacent vertices of u (the extracted vertex) and update their key values*/
        struct adjnode* p = g->array[u].head;
        while (p != NULL) {
            int v = p->des;
 
            /* If v is not yet included in MST and weight of u-v is less than key value of v, then update
             key value and parent of v*/
            if (inminheap(h, v) && p->wgt < key[v]) {
                key[v] = p->wgt;
                parent[v] = u;
                decreval(h, v, key[v]);
            }
            p = p->next;
        }
    }
 
    // print edges of MST
    printa(parent, v);
}
void primalgo_minheap(){
   clock_t start, end;
     start = clock();
    freopen("prim_input.txt","r",stdin);
    freopen("prim_output.txt","w",stdout);
    cout<<"output for prim algo using min heap"<<endl;
    long int v,e;
    cin>>v>>e;
    struct Graph* g = creategraph(v);
    for(int i=0;i<e;i++){
        long int x,y,w;
        cin>>x>>y>>w;
        addedge(g,x,y,w);

    }
 
      // Function call
    hprimmst(g);
     end = clock();
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*time complexity for this method is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV) (For a connected graph, V = O(E))*/

/*----------------------------------------------------------------------------------------------end of method 3------------------------------------------------------*/







int main(){
    int n;
    cout<<"Enter 1: prim algorithem implementation with out using heap\n"<<endl;
    cout<<"Enter 2: prim algorithem implementation using priority queue\n"<<endl;
    cout<<"Enter 3: prim algorithem implementation using min heap\n"<<endl;
     cin>>n;
    if(n==1){
        primalgo_withoutheap();
    }
    else if(n==2){
        primalgo_priority_queue();
    }
    else if(n==3){
        primalgo_minheap();
    }

}