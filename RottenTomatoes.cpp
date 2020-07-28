#include<bits/stdc++.h>

#define R 100
#define C 100

using namespace std;

int getRotTime(int mat[R][C], int r, int c){
	int timer = 0;

	for(int X=r+c+1; X>=0; X--){
		for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	            if(mat[i][j] == 2){
	                if(i>0 && mat[i-1][j] == 1){
	                    mat[i-1][j] = 3;
	                }
	                if(j>0 && mat[i][j-1] == 1){
	                    mat[i][j-1] = 3;
	                }
	                if(i<r-1 && mat[i+1][j] == 1){
	                    mat[i+1][j] = 3;
	                }if(j<c-1 && mat[i][j+1] == 1){
	                    mat[i][j+1] = 3;
	                }

	            }
        	}
    	}
    	for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	        	if(mat[i][j] == 3)
	        		mat[i][j] = 2;
	        }
	    }
	    timer++;
	}

	for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(mat[i][j] == 1)
                timer = -1;
                break;
        }
    }
    return timer;
}

int main(){

	int T, r, c;
    cin>>T;
    while(T){
        cin>>r>>c;
        int mat[R][C];
        for(int i=0; i<r; i++){
            for(int j=0;j<c; j++){
                cin>>mat[i][j];
            }
        }
        
        cout<<getRotTime(mat, r, c)<<endl;
        T--;
    }
	return 0;
}