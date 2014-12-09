#include <iostream>
using namespace std;

const int ROW = 6, COLUMN = 7;
int changePlayer(int player);
void updateBoard(int board[][COLUMN], int column, int player);
bool checkMove(int board[][COLUMN], int column);
bool checkWin(int board[][COLUMN], int column);
bool checkVerticalWin(int board[][COLUMN], int column);
bool checkHorizontalWin(int board[][COLUMN], int column);
bool checkDiagonalWin(int board[][COLUMN], int column);

int main()
{
    int board[ROW][COLUMN] = {0};
    int player = 1, column = 0;
    bool playerOneWin = false, playerTwoWin = false;
    
    cout << "WELCOME TO CONNECT 4" << endl;
    cout << "A CONSOLE GAME BY BRETT WILSON\n" << endl;
    
    cout << "Creating Board...\n" << endl;
    cout << " 0   1   2   3   4   5   6\n" << endl;
    
    //Generates the board.
    for (int y = 0; y < 6; y++)
    {
        cout << " ";
        for (int x = 0; x < 7; x++)
        {
            cout << board[y][x] << " | ";
        }
        cout << endl;
    }
    cout << endl;

    while (playerOneWin != true && playerTwoWin != true)
    {
        cout << "Player " << player << ", please select a column: ";
        cin >> column;
        cout << endl;
        
        if(checkMove(board, column))
        {
            updateBoard(board, column, player);
            
            if(checkWin(board, column) == true)
            {
                cout << "Player " << player << " has won the game!" << endl;
                if(player == 1)
                    playerOneWin = true;
                else
                    playerTwoWin = true;
            }
            player = changePlayer(player);
        }
        else
        {
            cout << "Invalid selection:" << endl;
        }
    }
	system("PAUSE");
	cin.ignore();
    return 0;
}

//Row = 6   Column = 7
void updateBoard(int board[][COLUMN], int column, int player)
{
    //Finds where to place the coin
    for (int i = 5; i >= 0; i--)
    {
        if (board[i][column] == 0)
        {
            board[i][column] = player;
            break;
        }
    }
    
    cout << " 0   1   2   3   4   5   6\n" << endl;
	
    //Prints out the new board
    for (int y = 0; y < ROW; y++)
    {
        cout << " ";
        for (int x = 0; x < COLUMN; x++)
        {
            cout << board[y][x] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

int changePlayer(int player)
{
    if (player == 1)
    {
            player = 2;
    }
    else 
    {
        player = 1;
    }
    return player;
}

bool checkMove(int board[][COLUMN], int column)
{
    bool isValid = true;
    
    if(column > 6 || column < 0)
        isValid = false;
        
    if (board[0][column] == 1 || board[0][column] == 2)
        isValid = false;
        
    return isValid;
}  

bool checkWin(int board[][COLUMN], int column)
{
    if(checkVerticalWin(board, column))
        return true;
        
    if(checkHorizontalWin(board, column))
        return true;

    if(checkDiagonalWin(board, column))
        return true;    
    
    return false;
}

bool checkVerticalWin(int board[][COLUMN], int column)
{
    int row = 0, 
        connectCount = 0,
        player = 0;
    
    while(board[row][column] == 0)
    {
        row++;
    }
    player = board[row][column];
    
    for(int rowChecker = 0; rowChecker < 6; rowChecker++)
    {
        if(board[rowChecker][column] != player)
            connectCount = 0;
        
        if(board[rowChecker][column] == player)
        {
            connectCount++;
        }
        
        if(connectCount == 4)
        {
            cout << "Vertical Win" << endl;
            return true;
        }
        
    }
    
    return false;
}

bool checkHorizontalWin(int board[][COLUMN], int column)
{
    int row = 0, 
        connectCount = 0,
        player = 0;
    
    while(board[row][column] == 0)
    {
        row++;
    }
    player = board[row][column];
    
    for(int columnChecker = 0; columnChecker < 7; columnChecker++)
    {
        if(board[row][columnChecker] != player)
            connectCount = 0;
        
        if(board[row][columnChecker] == player)
        {
            connectCount++;
        }
        
        if(connectCount == 4)
        {
            cout << "Horizontal Win" << endl;
            return true;
        }
        
    }
    
    return false;
}

bool checkDiagonalWin(int board[][COLUMN], int column)
{
    int row = 0, 
        columnChecker = 0,
        rowChecker = 0,
        connectCount = 0,
        player = 0;
    
    while(board[row][column] == 0)
    {
        row++;
    }
    
    player = board[row][column];
    
    while(columnChecker > 0 && rowChecker < 5)
    {
        columnChecker--;
        rowChecker++;
    }
    
    //Checks bottom left to top right.
    while(columnChecker <= 6 && rowChecker >= 0)
    {
        if(board[rowChecker][columnChecker] != player)
            connectCount = 0;
        
        if(board[rowChecker][columnChecker] == player)
        {
            connectCount++;
        }
        
        if(connectCount == 4)
        {
            return true;
        }
        rowChecker--;
        columnChecker++;
    }

    columnChecker = column;
    rowChecker = row;
    connectCount = 0;
    
    while(columnChecker < 6 && rowChecker < 5)
    {
        columnChecker++;
        rowChecker++;
    }
    
    //Checks bottom right to top left
    while(columnChecker >= 0 && rowChecker >= 0)
    {
        if(board[rowChecker][columnChecker] != player)
            connectCount = 0;
        
        if(board[rowChecker][columnChecker] == player)
        {
            connectCount++;
        }
        if(connectCount == 4)
        {
            return true;
        }
        rowChecker--;
        columnChecker--;
    }
    
    return false;
}