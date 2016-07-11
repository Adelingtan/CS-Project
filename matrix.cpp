//
// matrix.cpp
//
//
//  Created by Addy Tan
//
//  This program takes two n*n matrices, and computes the product of two matrices

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    int n;
    cout << "A is an nxn matrix.\nn=";
    cin >> n;
    int matrix[n][n];
    int matrix_1[n][n];
    int count =0;
    while(count<2){
        cout << "Enter matrix number "<<count+1<<" :"<<endl;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout << "A[" << i+1 << "][" << j+1 << "]=";
                if (count==0) {
                    cin >> matrix[i][j];
                }else{
                    cin >> matrix_1[i][j];
                }
            }
        }
        cout << "The matrix you entered is:"<<endl;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if(count==0){
                    cout << matrix[i][j] << " ";
                }else{
                    cout << matrix_1[i][j]<<" ";
                }
            }
            if (i!=n-1){
                cout<<endl;
            }
        }
        printf("\n");
        count++;
        
    }
    int multiply_matrix[n][n];
    int sum=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                sum = sum + matrix[i][k]*matrix_1[k][j];
            }
            
            multiply_matrix[i][j] = sum;
            sum = 0;
        }
    }
    cout<<"Product of entered matrices is:"<<endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout<<multiply_matrix[i][j]<<" ";
        if (i!=n-1){
            cout<<endl;
        }
        
    }
    
    return 0;
}






