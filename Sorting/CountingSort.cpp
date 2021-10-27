#include<bits/stdc++.h> 
using namespace std; 

void countingSort(int arr[], int n, int k) 
{ 
    int count[k];
    for(int i=0;i<k;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[arr[i]]++;
        
    for(int i=1;i<k;i++)
        count[i]=count[i-1]+count[i];
    
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=output[i];
}

int main(void) 
{
	int a[10],k;
    cout << "Enter 10 elements of array: " << endl;
    for (int i=0; i<10; i++)
        cin >> a[i];
    cout << "Enter the range of input: ";
    cin >> k;
    cout << "Original Array is: ";
    for (int i=0; i<10; i++)
        cout << a[i] << " ";
	int n=sizeof(a)/sizeof(a[0]);
	cout <<"\nArray after sorting is: ";
	countingSort(a,n,k);
	for(int x: a)
	    cout<<x<<" ";
}

