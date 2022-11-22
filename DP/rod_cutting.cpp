#include<bits/stdc++.h>
using namespace std;


/*........................................................method 1(Recusrion).................................*/
int max(int a, int b) 
{
     return (a > b) ? a : b; 
}

int rod_cutting1(int price[], int index, int n){
    if(index ==0){
        return n* price[0];
    }
   
    int notcut = rod_cutting1(price,index-1,n);
    int cut = INT_MIN;
    int rod_length = index+1;

    if(rod_length <=n){
        cut = price[index] + rod_cutting1(price,index,n-rod_length);
    }
    return max(notcut,cut);
}

void printing_method1(){
     clock_t start, end;
     start = clock();
    freopen("rodCut_input.txt","r",stdin);
    freopen("rodCut_output.txt","w",stdout);
    cout<<"Rod Cutting algorithom using Recusrion\n"<<endl;
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
 
      // Function call
      cout<<rod_cutting1(price,n-1,n)<<endl;
     end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*The time complexity of this naive recursive solution is exponential (n^2).*/
/*..........................................................................................end of method 1........................*/







/*...............................................................method 2(bottom-up).......................................*/
int rod_cutting2(int price[], int n){
    int val[n+1];
    val[0]=0;
    int i,j;
    for(i=1;i<=n;i++){
    int max_val = INT_MIN;
      for(j=0;j<i;j++){
        max_val = max(max_val, price[j] + val[i-j-1]);
      }
      val[i] = max_val;
    }
    return val[n];
}
void printing_method2(){
     clock_t start, end;
     start = clock();
   freopen("rodCut_input.txt","r",stdin);
    freopen("rodCut_output.txt","w",stdout);
    cout<<"Rod Cutting algorithom using bottom-up\n"<<endl;
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
 
      // Function call
      cout<<rod_cutting2(price,n)<<endl;
     end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*The Time Complexity of the above implementation is O(n^2)*/

/*..........................................end of method 2...............................*/










/*..................................................method 3(memoization)............................*/
int rod_cutting3(int price[], int index, int n, vector<vector<int>>& dp){
    if(index==0){
        return n * price[0];
    }
    if(dp[index][n]!=-1){
        return dp[index][n];
    }
    int notCut = rod_cutting3(price, index-1,n,dp);
    int cut = INT_MIN;
    int rod_length = index +1;
    if(rod_length<=n){
        cut = price[index] + rod_cutting3(price,index,n-rod_length,dp);
    }
    return dp[index][n]=max(notCut,cut);
}

void printing_method3(){
     clock_t start, end;
     start = clock();
    freopen("rodCut_input.txt","r",stdin);
    freopen("rodCut_output.txt","w",stdout);
    cout<<"Rod Cutting algorithom using Memoization\n"<<endl;
    int n;
    cin>>n;
    int price[n];
    vector<vector<int> > dp(n,  vector<int>(n + 1, -1));
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
 
      // Function call
      cout<<rod_cutting3(price,n-1,n,dp)<<endl;
     end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*The Time Complexity of the above implementation is O(n^2)*/

/*..........................................end of method 3...............................*/




int main(){
    int n;
    cout<<"Enter 1: Rod cutting algorithom using Recursion\n"<<endl;
    cout<<"Enter 2: Rod cutting algorithom using bottom-up\n"<<endl;
    cout<<"Enter 3: Rod cutting algorithom using Memoization\n"<<endl;
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