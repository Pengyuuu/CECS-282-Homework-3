#include <iostream>
#include <array>
#include "tictactoe.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int row, col, turn, moves;
    
    bool empty;
    
    char status;
    
    array<array<char, 3>, 3> board = {0};
    
    turn = 1;
    
    moves = 0;
    
    while (status == 0 && moves < 9){
        
        PrintBoard(board);
        
        if (turn == 1) { cout << "X's turn: ";}
        
        else { cout << "O's turn: ";}
            
        GetMove(row, col);
                
        empty = MoveIsValid(board, row, col);
            
        while (!empty){
            
            if ((row < 0 || row > 2) || (col < 0 || col > 2)){
                
                cout << "Please choose a valid move: ";
                
                GetMove(row, col);
                    
                empty = MoveIsValid(board, row, col);
            }
            
            else {
                
                cout << "That space is already taken!: " << endl;
                    
                GetMove(row, col);
                    
                empty = MoveIsValid(board, row, col);
            }
        }
            
        board[row][col] = turn;
            
        status = CheckWinner(board);
        
        if (turn > 0){ turn -= 2;}
        else { turn = 1;}
    }
}
