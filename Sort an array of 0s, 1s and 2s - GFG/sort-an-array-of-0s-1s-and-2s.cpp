//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int A[], int n)
    {
        // code here 
         int i = 0 ,  cz = 0 , co = 0 ,  ct = 0 ;  
    while ( i < n )  
    {  
        if ( A [ i ] == 0 )  
        {  
            cz = cz + 1 ;  
        }  
        else if ( A [ i ] == 1 )  
        {  
            co  = co + 1 ;  
        }  
        else  
        {  
            ct = ct + 2 ;  
        }  
        i = i + 1 ;  
    }  
    for  ( i = 0 ; i < cz ; i++ )  
    {  
        A [ i ] = 0 ;  
    }  
    for ( i = cz ; i < cz + co ; i++ )  
    {  
        A [ i ] = 1 ;  
    }  
    for ( i = cz + co ; i < n ; i++ )  
    {  
        A [ i ] = 2 ;  
    }  
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends