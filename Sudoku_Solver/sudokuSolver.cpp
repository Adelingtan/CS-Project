//
//  sudokuSolver.cpp
//
//
//  Created by Addy Tan on 8/20/16.
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
int const N=9;
vector<int> possi;
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

//check whether any assigned number in the specified 3*3 box matches the given number.
bool checkBox(int sudoku[N][N], int RRow, int CCol, int num){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
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
    if(!checkRow(sudoku, row, num) &&!checkColumn(sudoku, col, num) &&!checkBox(sudoku, row - row%3 , col - col%3, num)){
        possi.push_back(num);
    }
    
    return possi;
}
//find out all possible numbers in an empty slot.
void solveIt(int sudoku[N][N],int row, int col){
    if(sudoku[row][col]==empty){
        for(int num=1; num<=9;num++){  //loop though numbers
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
        for (int num = 1; num <= 9; num++){
            if (!checkRow(sudoku, row, num) &&!checkColumn(sudoku, col, num) &&!checkBox(sudoku, row - row%3 , col - col%3, num)){
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
    printf("╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
    for (int row = 0; row < N; row++){
        if(row%3!=0){
            printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        }else if(row!=0){
            printf("╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        }
        printf("║");
        for (int col = 0; col < N; col++){
            if(sudoku[row][col]!=0){
                printf("%2d", sudoku[row][col]);
            }else{
                printf("  ");
            }
            if(col%3!=2){
                printf(" │");
            }else{
                printf(" ║");
            }
        }
        
        printf("\n");
    }
    printf("╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
}
void printPossibleGrid(int sudoku[N][N]){
    printf("╔══════════════╤══════════════╤══════════════╦══════════════╤══════════════╤══════════════╦══════════════╤══════════════╤═════════════╗\n");
    for(int row=0;row<N;row++){
        if(row%3!=0){
            printf("╟──────────────┼──────────────┼──────────────╫──────────────┼──────────────┼──────────────╫──────────────┼──────────────┼─────────────╢\n");
        }else if(row!=0){
            printf("╠══════════════╪══════════════╪══════════════╬══════════════╪══════════════╪══════════════╬══════════════╪══════════════╪═════════════╣\n");
            
        }
        printf("║");
        for( int col=0;col<N;col++){
            solveIt(sudoku,row,col);
            
            for(int j=0;j<7-possi.size();j++){
                cout<<" ";
            }
            for(int i=0;i<possi.size();i++){
                cout<<possi[i];
                if(i!=possi.size()-1){
                    cout<<",";
                }
            }
            for(int j=0;j<7-possi.size();j++){
                cout<<" ";
            }
            
            possi.clear();
            
            if(col%3!=2){
                printf(" │");
            }else if(col<8){
                printf(" ║");
            }
        }
        printf("║");
        cout<<endl;
        
    }
    printf("╚══════════════╧══════════════╧══════════════╩══════════════╧══════════════╧══════════════╩══════════════╧══════════════╧═════════════╝\n");
    
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
    int sudoku[N][N] = {{0, 0, 0, 6, 0, 0, 4, 0, 0},
        {7, 0, 0, 0, 0, 3, 6, 0, 0},
        {0, 0, 0, 0, 9, 1, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 1, 8, 0, 0, 0, 3},
        {0, 0, 0, 3, 0, 6, 0, 4, 5},
        {0, 4, 0, 2, 0, 0, 0, 6, 0},
        {9, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 1, 0, 0}};
    cout<<"Unsolved Sudoku Board:"<<endl;
    printSudoku(sudoku);
    cout<<'\n';
    cout<<"Possible values:"<<endl;
    printPossibleGrid(sudoku);
    clock_t begin = clock();
    cout<<"\nSolving the soduku..."<<endl;
    if (SolveSudoku(sudoku) == true){
        cout<<"Tada!! Sudoku Solved:"<<endl;
        printSudoku(sudoku);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout<< "Time taken to solve the game: "<<elapsed_secs<<" seconds.\n";
    }else{
        printf("Booooo! No solution! Try another Sudoku.");
    }
    string filename="/Users/addytan/Desktop/";
    string filename_ed;
    cout << "\nEnter file path (/Users/addytan/Desktop/sudoku.txt): "<<endl;
    cin >> filename_ed;
    filename=filename+filename_ed;
    ifstream in_stream;
    ofstream out_stream;
    int arr[81];
    int index=0;
    ifstream infile(filename_ed);
    char chars;
    if (infile.is_open()) {
        while (!infile.eof()) {
            while(infile.get(chars)){
                if(isdigit(chars)){
                    arr[index]=int(chars)-48;
                    index++;
                }
            }
        }
    }
    in_stream.close();
    Sudokucreator(sudoku_two,arr);
    cout<<"Unsolved Sudoku Board:"<<endl;
    printSudoku(sudoku_two);
    cout<<'\n';
    cout<<"Possible values:"<<endl;
    printPossibleGrid(sudoku_two);
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

