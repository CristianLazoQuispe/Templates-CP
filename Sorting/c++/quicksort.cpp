#include<bits/stdc++.h>

using namespace std;




void print(int* arr,int n){
    string result ="";
	for (int i=0;i<n;i++) {
        if (i!=(n-1)) result+= (to_string(arr[i])+" ");
        else result+=to_string(arr[i]);        
    }
    std::cout<<result<< std::endl;
}


int make_partition(int arr[],int inicio, int fin) {

	int pivot = arr[inicio];
	int aux = fin-1;
	
	for(int i=fin-1;i>inicio;i--){
		if (pivot<arr[i]){
			swap(arr[aux], arr[i]);
			aux-=1;			
		}
	}

	swap(arr[inicio], arr[aux]);
	return aux;
}

void quicksort(int arr[],int start, int end){
    
    if(start<end){
        int pivot = make_partition(arr,start,end);
        quicksort(arr,start,pivot);
        quicksort(arr,pivot+1,end);
    }

}

int main(){

	int arr[] = {2,1,4,3,6,5,9,1,0};
    int n = 9;
	print(arr,n);
    quicksort(arr,0,n);
	print(arr,n);
}

