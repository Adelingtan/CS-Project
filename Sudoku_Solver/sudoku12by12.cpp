//
//  sudoku12by12.cpp
//  
//
//  Created by Addy Tan on 8/26/16.
//
//

#include <stdio.h>
#include <vector>
#include <array>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


int const empty=0;
int const N=12;
vector<int> possi;
char twelveChar[ ]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D'};
//find empty spot, use pass by refrence to refrence the row and col number
bool findEmp(int sudoku[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++){
        for (col = 0; col < N; col++){
            if (sudoku[row][col] == empty){
                return true;
            }
        }
    }
    return false;
}

//check whether any assigned number in the specified row matches the given number.

bool checkRow(int sudoku[N][N], int row, int num){
    for (int col = 0; col < N; col++){
        if (sudoku[row][col] == num){
            return true;
        }
    }
    return false;
}

//check whether any assigned number in the specified column matches the given number.

bool checkColumn(int  sudoku[N][N], int col, int num){
    for (int row = 0; row < N; row++){
        if (sudoku[row][col] == num){
            return true;
        }
    }
    return false;
}

//check whether any assigned number in the specified 3*4 box matches the given number.
bool checkBox(int sudoku[N][N], int RRow, int CCol, int num){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 4; col++){
            if (sudoku[row+RRow][col+CCol] == num){
                return true;
            }
        }
    }
    return false;
}
//find out all possible numbers in an empty slot.
vector<int> possibleVal(int sudoku[N][N], int row, int col, int num){
    //int count(0);
    if(!checkRow(sudoku, row, num) &&!checkColumn(sudoku, col, num) &&!checkBox(sudoku, row - row%3 , col - col%4, num)){
        possi.push_back(num);
    }
    
    return possi;
}
//find out all possible numbers in an empty slot.
void solveIt(int sudoku[N][N],int row, int col){
    if(sudoku[row][col]==empty){
        for(int num=1; num<=12;num++){  //loop though numbers
            possibleVal(sudoku,row,col,num);
        }
        
    }else{
        possi.empty();
        possi.push_back(sudoku[row][col]);
    }
}
//check all the possible values in a specific empty slot
bool SolveSudoku(int sudoku[N][N]){
    int row, col;
    
    if (!findEmp(sudoku, row, col)){
        return true; // YAY
        
    }else{
        for (int num = 1; num <= 12; num++){
            if (!checkRow(sudoku, row, num) &&!checkColumn(sudoku, col, num) &&!checkBox(sudoku, row - row%3 , col - col%4, num)){
                sudoku[row][col] = num;
                if (SolveSudoku(sudoku)){
                    return true;
                }
            }
            sudoku[row][col] = empty;
        }
    }
    
    return false;
}
void printSudoku(int sudoku[N][N]){
    printf("╔═══╤═══╤═══╤═══╦═══╤═══╤═══╤═══╦═══╤═══╤═══╤═══╗\n");
    for (int row = 0; row < N; row++){
        if(row%3!=0){
            printf("╟───┼───┼───┼───╫───┼───┼───┼───╫───┼───┼───┼───╢\n");
        }else if(row!=0){
            printf("╠═══╪═══╪═══╪═══╬═══╪═══╪═══╪═══╬═══╪═══╪═══╪═══╣\n");
        }
        printf("║");
        for (int col = 0; col < N; col++){
            if(sudoku[row][col]!=0){
                cout<<" "<<twelveChar[sudoku[row][col]];
            }else{
                cout<<"  ";
            }
            if(col%4!=3){
                cout<<" │";
            }else{
                cout<<" ║";
            }
        }
        
        printf("\n");
    }
    printf("╚═══╧═══╧═══╧═══╩═══╧═══╧═══╧═══╩═══╧═══╧═══╧═══╝\n");
}
void printPossibleGrid(int sudoku[N][N]){
    printf("╔══════════════╤══════════════╤══════════════╤══════════════╦══════════════╤══════════════╤══════════════╤══════════════╦══════════════╤══════════════╤══════════════╤═════════════╗\n");
    for(int row=0;row<N;row++){
        if(row==N){
            cout<<endl;
        }
        for( int col=0;col<N;col++){
            solveIt(sudoku,row,col);
            
            for(int j=0;j<6-possi.size();j++){
                cout<<" ";
            }
            for(int i=0;i<possi.size();i++){
                cout<<possi[i];
                if(i!=possi.size()-1){
                    cout<<",";
                }
            }
            for(int j=0;j<6-possi.size();j++){
                cout<<" ";
            }
            
            possi.clear();
            
        }
        cout<<endl;
        
    }
    printf("╚══════════════╧══════════════╧══════════════╧══════════════╩══════════════╧══════════════╧══════════════╧══════════════╩══════════════╧══════════════╧══════════════╧═════════════╝\n");
    
}
void Sudokucreator(int sudoku[N][N],int number[]){
    string numbers;
    int i=0;
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){{
            sudoku[row][col]=number[i];
            i++;
        }
        }
    }
    
}

int main(){
    
    int sudoku_two[N][N];
    string filename="/Users/addytan/Desktop/";
    string filename_ed;
    cout << "\nEnter file path (/Users/addytan/Desktop/sudoku.txt): "<<endl;
    cin >> filename_ed;
    filename=filename+filename_ed;
    ifstream in_stream;
    ofstream out_stream;
    int arr[200];
    int index=0;
    ifstream infile(filename_ed);
    char chars;
    if (infile.is_open()) {
        while (!infile.eof()) {
            while(infile.get(chars)){
                for(int in=0;in<=12;in++){
                    if(chars==twelveChar[in]){
                        arr[index]=in;
                        index++;
                    }
                    
                }
            }
        }
    }
    in_stream.close();
    
    cout<<endl;
    Sudokucreator(sudoku_two,arr);
    cout<<"Unsolved Sudoku Board:"<<endl;
    printSudoku(sudoku_two);
    cout<<'\n';
    //cout<<"Possible values:"<<endl;
    // printPossibleGrid(sudoku_two);
    clock_t begin_again = clock();
    cout<<"\nSolving the soduku..."<<endl;
    if (SolveSudoku(sudoku_two) == true){
        cout<<"Tada!! Sudoku Solved:"<<endl;
        printSudoku(sudoku_two);
        clock_t end_again = clock();
        double elapsed_secs = double(end_again - begin_again) / CLOCKS_PER_SEC;
        cout<< "Time taken to solve the game: "<<elapsed_secs<<" seconds.\n";
    }else{
        printf("Booooo! No solution! Try another Sudoku.");
    }
    
    return 0;
}

