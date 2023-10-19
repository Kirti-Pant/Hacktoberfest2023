int getpivot(vector<int>& arr,int n){
    int s=0;
    int e=n-1;
    int mid= s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid= s+(e-s)/2;
    }
    return s;
}
int binarysearch(vector<int>& arr, int k, int s, int e){
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            return mid;
        }
        else if (arr[mid]<k){
            s=mid+1;

        }else{
            e=mid-1;
        }
        mid= s+(e-s)/2;
    }
    return -1;
}
int searchinrotatedarray(vector<int>& arr, int n, int k)
{
  
    int pivot=getpivot(arr,n);
    if(k>= arr[pivot] && k<=arr[n-1]){
        return binarysearch(arr, k, pivot, n-1);
    }
    else{
        return binarysearch(arr,k, 0,pivot-1);
    }
}
