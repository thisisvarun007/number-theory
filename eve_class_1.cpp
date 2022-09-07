#include<iostream>
using namespace std;
struct Matrix{
	int a[2][2];
}
Matrix mul(Matrix A,Matrix B){
	Matrix res;
	for (int row=0; row<2; row++){
		for (int col=0; col<2; col++){
			int sum=0;
			for (int i=0; i<2; i++){
				sum+=A.a[row][i]*B.a[i][col];
			}
			res.a[row][col]=sum;
		}
	}
	return res;
}
Matrix Identity(){
	Matrix id;
	id.a[0][0]=1,id.a[0][1]=0;
	id.a[1][0]=0,id.a[1][1]=1;
	return id;
}
Matrix Matrix_expo(Matrix A,int exp){
	if (exp==0) return Identity();
	Matrix ans=Matrix_expo(A,exp/2);
	if (exp%2==0){
		return mul(ans,ans);
	}
	else{
		return mul(A,mul(ans,ans));
	}
}
int main(){
	Matrix A;
	int pow;
	cout<<"Enter values of matrix 1 (2x2) :"<<endl;
	scanf("%d%d%d%d",&A.a[0][0],&A.a[0][1],&A.a[1][0],&A.a[1][1]);
	cout<<"Enter the Power :";
	cin>>p;
	Matrix C=mul(A,pow);
	cout<<C.a[0][0]<<" "<<C.a[0][1]<<endl;
	cout<<C.a[1][0]<<" "<<C.a[1][1]<<endl;
}