#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int lis(int arr[], int n){
	int i,j;
	//cout << 1 <<endl;
	int max = INT_MIN;
	//cout << 2 <<endl;
	int l[n];
	for(i=0;i<n;i++)
		l[i] = 1;
	//cout << 3 <<endl;
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(arr[j]<arr[i] && l[i]<l[j]+1)
				l[i] = l[j] + 1;
		}
		if(l[i] > max)
			max = l[i];
	}
	return max;
}
int main(){
	int arr[] = {10,22,9,33,21,50,41,60,80};
	int n = sizeof(arr)/sizeof(arr[0]);
	int ans = lis(arr,n);
	cout << ans << endl;
	return 0;
}