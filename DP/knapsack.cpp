#include<bits/stdc++.h>
using namespace std;


/*........................................................method 1(Recusrion).................................*/
int max(int a, int b) 
{
     return (a > b) ? a : b; 
}

int knapsack1(int w,int wt[],int val[],int n){
    if(n==0||w==0){
        return 0;
    }
    /* if weight of n is > than W than it cannot be solution*/
    if(wt[n-1]>w){
        return knapsack1(w,wt,val,n-1);
    }
    else{
        return max(val[n-1]+knapsack1(w-wt[n-1],wt,val,n-1),knapsack1(w,wt,val,n-1));
    }
}

void printing_method1(){
     clock_t start, end;
     start = clock();
    freopen("knapsack_input.txt","r",stdin);
    freopen("knapsack_output.txt","w",stdout);
    cout<<"knapsack algorithom using Recusrion\n"<<endl;
    int n,w;
    cin>>n>>w;
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
 
      // Function call
      cout<<knapsack1(w,wt,val,n)<<endl;
     end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*The time complexity of this naive recursive solution is exponential (2^n).*/
/*..........................................................................................end of method 1........................*/







/*...............................................................method 2(bottom-up).......................................*/
int knapsack2(int W,int wt[],int val[],int n){
    int i,w;
    vector<vector<int>> k(n+1, vector<int>(W+1));
    for(i=0;i<=n;i++){
      for(w=0;w<=W;w++){
        if(i==0 || w==0){
            k[i][w]=0;
        }
        else if(wt[i-1]<=w){
            k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
        }
        else{
            k[i][w]=k[i-1][w];
        }
      }
    }
    return k[n][W];
}
void printing_method2(){
     clock_t start, end;
     start = clock();
    freopen("knapsack_input.txt","r",stdin);
    freopen("knapsack_output.txt","w",stdout);
    cout<<"knapsack algorithom using bottom-up\n"<<endl;
    int n,w;
    cin>>n>>w;
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
 
      // Function call
      cout<<knapsack2(w,wt,val,n)<<endl;
     end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/* time complexity of this method is O(N*W) where N is the
number of weight and W is capacity*/

/*..........................................end of method 2...............................*/










/*..................................................method 3(memoization)............................*/
int knapsackrec(int w,int wt[],int val[],int i,int **dp){
    if(i<0){
        return 0;
    }
    if(dp[i][w]!=-1){
        return dp[i][w];
    }
    if(wt[i]>w){
        dp[i][w]=knapsackrec(w,wt,val,i-1,dp);
        return dp[i][w];
    }
    else{
        dp[i][w] = max(val[i] + knapsackrec(w-wt[i],wt,val,i-1,dp),knapsackrec(w,wt,val,i-1,dp));
        return dp[i][w];
    }
}
int kanpsack3(int w,int wt[],int val[],int n){
    int **dp;
    dp= new int*[n];
    for(int i=0;i<n;i++){
        dp[i] = new int[w+1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<w+1;j++){
            dp[i][j]=-1;
        }
    }
    return knapsackrec(w,wt,val,n-1,dp);
}

void printing_method3(){
     clock_t start, end;
     start = clock();
    freopen("knapsack_input.txt","r",stdin);
    freopen("knapsack_output.txt","w",stdout);
    cout<<"knapsack algorithom using Memoization\n"<<endl;
    int n,w;
    cin>>n>>w;
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
 
      // Function call
      cout<<kanpsack3(w,wt,val,n)<<endl;
     end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/* time complexity of this method is O(N*W) where N is the
number of weight and W is capacity*/

/*..........................................end of method 3...............................*/




int main(){
    int n;
    cout<<"Enter 1: knapsack algorithom using Recursion\n"<<endl;
    cout<<"Enter 2: knapsack algorithom using bottom-up\n"<<endl;
    cout<<"Enter 3: knapsack algorithom using Memoization\n"<<endl;
    cin>>n;
    if(n==1){
        printing_method1();
    }
    else if(n==2){
        printing_method2();
    }
    else if(n==3){
        printing_method3();
    }
}