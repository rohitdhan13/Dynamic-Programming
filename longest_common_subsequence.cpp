#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int lcs(string a, string b){
	int m = a.length(), n = b.length(),i,j;
	int len[m+1][n+1];
	//len[i][j] stores the longest common subsequence between ith index of string a and jth index of string b
	for(i=0;i<=m;i++)
		len[i][0]=0;
	for(j=0;j<=n;j++)
		len[0][j]=0;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(a[i]==b[j])
				len[i][j] = 1+len[i-1][j-1];
			else
				len[i][j] = max(len[i-1][j],len[i][j-1]);
		}
	}
	return len[m][n];
}
int main(){
	string a = "AGGTAB";
	string b = "GXTXAYB";
	int l = lcs(a,b);
	cout << l <<endl;
	return 0;
}