#include<bits/stdc++.h>
using namespace std;


/*........................................................method 1(Recusrion).................................*/
bool SubsetSum_method1(int set[], int n, int sum)
{
    
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (set[n - 1] > sum)
    {
        return SubsetSum_method1(set, n - 1, sum);
    }
  
    return SubsetSum_method1(set, n - 1, sum) || SubsetSum_method1(set, n - 1, sum - set[n - 1]);
}
void printing_method1(){
     clock_t start, end;
     start = clock();
    freopen("subset_sum_input.txt","r",stdin);
    freopen("subset_sum_output.txt","w",stdout);
    cout<<"Subset Sum algorithom using Recusrion\n"<<endl;
    int n,sum;
    cin>>n>>sum;
    int set[n];
    for(int i=0;i<n;i++){
        cin>>set[i];
    }
 
      // Function call
      if (SubsetSum_method1(set, n, sum) == true)
      {
         cout <<"found a subset with given sum";
      }
    else
    {
        cout <<"No subset with given sum found";
    }
      end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*..........................................................................................end of method 1........................*/







/*...............................................................method 2(bottom-up).......................................*/
bool SubsetSum_method2(int set[], int n, int sum)
{
    
    bool subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        subset[i][0] = true;
    }
    for (int i = 1; i <= sum; i++)
    {
        subset[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
            {
                subset[i][j] = subset[i - 1][j];
            }
            if (j >= set[i - 1])
            {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }
    }
  
    return subset[n][sum];
}
void printing_method2(){
     clock_t start, end;
     start = clock();
    freopen("subset_sum_input.txt","r",stdin);
    freopen("subset_sum_output.txt","w",stdout);
    cout<<"Subset Sum algorithom using bottom-up\n"<<endl;
    int n,sum;
    cin>>n>>sum;
    int set[n];
    for(int i=0;i<n;i++){
        cin>>set[i];
    }
 
      // Function call
      if (SubsetSum_method2(set, n, sum) == true)
      {
         cout <<"found a subset with given sum";
      }
    else
    {
        cout <<"No subset with given sum found";
    }
      end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.*/
/*..........................................end of method 2...............................*/










/*..................................................method 3(memoization)............................*/
int tab[2000][2000];
int subsetSum_method3(int a[], int n, int sum)
{
    if (sum == 0){
        return 1;
    }
          
    if (n <= 0)
    {
        return 0;
    }

    if (tab[n - 1][sum] != -1)
    {
        return tab[n - 1][sum];
    }
    
    
    if (a[n - 1] > sum)
    {
        return tab[n - 1][sum] = subsetSum_method3(a, n - 1, sum);
    }
    else
    {
         
        return tab[n - 1][sum] = subsetSum_method3(a, n - 1, sum) ||  subsetSum_method3(a, n - 1, sum - a[n - 1]);
    }
}
  

void printing_method3(){
     clock_t start, end;
     start = clock();
    freopen("subset_sum_input.txt","r",stdin);
    freopen("subset_sum_output.txt","w",stdout);
    cout<<"Subset Sum algorithom using Memoization\n"<<endl;
    memset(tab, -1, sizeof(tab));
    int n,sum;
    cin>>n>>sum;
    int set[n];
    for(int i=0;i<n;i++){
        cin>>set[i];
    }
 
      // Function call
      if (subsetSum_method3(set, n, sum) == true)
      {
         cout <<"found a subset with given sum";
      }
    else
    {
        cout <<"No subset with given sum found";
    }
      end = clock();

  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl; 
}
/*O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.*/
/*..........................................end of method 3...............................*/




int main(){
    int n;
    cout<<"Enter 1: Subset Sum algorithom using Recursion\n"<<endl;
    cout<<"Enter 2: Subset Sum algorithom using bottom-up\n"<<endl;
    cout<<"Enter 3: Subset Sum algorithom using Memoization\n"<<endl;
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