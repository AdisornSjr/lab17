#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if(i%M==M-1) cout << endl;
        else cout << " ";
    }
}

void randData(double *a,int N,int M){
    for(int i = 0; i < N*M; i++){
        a[i] = (rand()%101)/100.00;
    }
}

void findRowSum(const double *a,double *b,int N,int M){
	double x=0;
	int j=0;
	for(int i = 0;i<M*N;i++){
		x = x + *(a+i);  
		if(i%M==M-1){
			b[j] = x;
			x = 0;
			j++;
		}
		
		
	}
}

void findColSum(const double *a,double *b,int N,int M){
    for(int i = 0;i<N*M;i++){
        *(b+i%M) = 0;
    }
    for(int j=0;j<N*M;j++){
        *(b+j%M) += *(a+j);
    }
}

