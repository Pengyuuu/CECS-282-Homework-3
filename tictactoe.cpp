#include <stdio.h>
#include <iostream>
#include "tictactoe.h"

using namespace std;

void PrintBoard(const std::array<std::array<char, 3>, 3> &board){
    
    for (int i = 0; i < 4; i++){
        
        int border = 0;
        
        for (int j = 0; j < 4; j++){
            
            if (i == 0 && j == 0){
                
                cout << "- ";
            }
            else if (i == 0){
          
                cout << border << " ";
                
                border++;
            }
            else if (j == 0){
                
                cout << i - 1 << " ";
                
            }
            else if (board[i - 1][j - 1] == 1){
                
                cout << "X ";
            }
            
            else if (board[i - 1][j - 1] == -1){
                
                cout << "O ";
            }
            
            else if (board[i - 1][j - 1] == 0){
                
                cout << ". ";
            }
        }
        
        cout << endl;
    }
}

void GetMove (int &row, int &col){
    
    char dummy = ',';
    cin >> row;
    cin >> dummy;
    cin >> col;
}

bool MoveIsValid(const std::array<std::array<char, 3>, 3> &board, int row, int col){
    
    if ((row < 0 || row > 2) || (col < 0 || col > 2)){
        
        return false;
    }
    if (board[row][col] == 0){
        
        return true;
    }
    else{
        
        return false;
    }
}

char CheckWinner(const std::array<array<char, 3>, 3> &board){
    
    if ((board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) || (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) || (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) || (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) || (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) || (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) || (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) || (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1)){
        
        cout << "X wins! " << endl;
        
        PrintBoard(board);
                
        return 1;
    }
    
    else if ((board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1) || (board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1) || (board[2][0] == -1 && board[2][1] == -1 && board[2][2] == -1) || (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1) || (board[0][2] == -1 && board[1][1] == -1 && board[2][0] == -1) || (board[0][0] == -1 && board[1][0] == -1 && board[2][0] == -1) || (board[0][1] == -1 && board[1][1] == -1 && board[2][1] == -1) || (board[0][2] == -1 && board[1][2] == -1 && board[2][2] == -1)){
        
        cout << "O wins! " << endl;
        
        PrintBoard(board);
        
        return -1;
    }
    
    return 0;
}
