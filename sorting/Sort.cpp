#include<iostream>
using namespace std;

//Quick  Sort
// Avg Time Complexity O(nlogn)
// Worst Time Complexity O(n^2)
void swap(int *a, int *b){
int temp=*a;
*a=*b;
*b=temp;
}

int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[low]; 
    int i = low - 1, j = high + 1; 
   
    while (true) 
    { 

        do
        { 
            i++; 
        } while (arr[i] < pivot); 

        do
        { 
            j--; 
        } while (arr[j] > pivot); 

        if (i >= j) 
            return j; 
   
        swap(arr[i], arr[j]); 
    } 
} 
  
swap(&a[i+1],&a[e]);
return i+1;
}

void quicksort(int a[], int low, int high){
if(low<high){
    int pi=partition(a,low,high);

    quicksort(a,low,pi-1);
    quicksort(a,pi+1,high);
}
}

//Insertion  Sort
//Time Complexity O(n^2)

void isort(int a[],int n){
    int j;
    for(int i=1;i<n;i++){
        int temp=a[i];
        j=i-1;
        while(a[j]>temp && j>=0){
            a[j+1]=a[j];
            j--;
        }
    a[j+1]=temp;
    }
}


//Selection  Sort
//Time Complexity O(n^2)
void ssort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
}

//Bubble  Sort
//Time Complexity O(n^2)

void bsort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[i],&a[j]);
            }
        }
    }
}

//Merge  Sort
// Worst Time Complexity O(nlogn)

void merge(int a[], int start, int mid,int end){
    int i=0,j=0,k=start;

    int lsize=mid-start+1;
    int rsize=end-mid;

    int left[lsize], right[rsize];

    for(int i=0;i<lsize;i++){
        left[i]=a[start+i];
    }

    for(int i=0;i<rsize;i++){
        right[i]=a[mid+1+i];
    }

    while(i<lsize && j<rsize){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
        }else{
            a[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<lsize){
        a[k]=left[i];
        i++;k++;
    }

    while(j<rsize){
        a[k]=right[j];
        j++;k++;
    }
}

void mergesort(int a[],int s, int e){
    if(s<e){
        int mid=s + (e-s)/2;
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);
        merge(a,s,mid,e);
    }
}


int main(){
    int n=0;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    cout<<"Quick Sort\n";
    quicksort(a,0,n-1);
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<'\n';
    }
    cout<<'\n';

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Merge Sort\n";
    mergesort(a,0,n-1);
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<'\n';
    }
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Bubble Sort\n";
    bsort(a,n);
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<'\n';
    }
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"Selection Sort\n";
    ssort(a,n);
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<'\n';
    }
    
     for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"Insertion Sort\n";
    isort(a,n);
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<'\n';
    }
return 0;
}
