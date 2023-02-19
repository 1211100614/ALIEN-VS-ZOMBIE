// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T11L
// Names: TIVAASHENY A/P ANANTHAN | HEMMA RAVINDRAN | YUVAN A/L GANESAN
// IDs: 1211100614 | 1211102066 | 1201103498
// Emails: 1211100614@student.mmu.edu.my | 1211102066@student.mmu.edu.my | 1201103498@student.mmu.edu.my
// Phones: 0196900596 | 0137008516 | 0143859251
// *********************************************************

#include "save_load.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

class Board
{
private:
    vector<vector<char>> board_size;
    int column, row;
  
public:
    Board(int board_Columns = 5, int board_Rows = 9);
    void init(int board_Columns, int board_Rows);
    void display() const;
};

class Alien 
{
public:
    int health;
    int attack;
    

    Alien() : health(250), attack(0),{}
};

class Zombie 
{
public:
    int health;
    int attack;
    int range;
   

    Zombie() : health(250), attack(5), range(2) {}
};



Board::Board(int board_Columns, int board_Rows)
{
    cout << endl;
    cout << "Board Settings" << endl;
    cout << "----------------" << endl;

    cout << "Enter rows => ";
    cin >> board_Rows;
    cout << "Enter columns => ";
    cin >> board_Columns;

    init(board_Columns, board_Rows);
}

void Board::init(int board_Columns, int board_Rows)
{
    row = board_Rows;
    column = board_Columns;

    ' '};
    int objectno = 10;
 char objects[] = {'h', 'p', 'r', '>', '<', '^', 'v', ' ', ' ',
    board_size.resize(row);
    for (int i = 0; i < row; ++i)
    {
        board_size[i].resize(column);
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            int objNo = rand() % objectno;
            board_size[i][j] = objects[objNo];
        }
    }

    // Place "A" alien in the middle
    int middle_row = row / 2;
    int middle_col = column / 2;
    board_size[middle_row][middle_col] = 'A';

    // Place zombies
    int zombie;
    cout << "Enter the number of zombies (1-9): ";
    cin >> zombie;
    while (zombie < 1 || zombie > 9)
    {
        cout << "Invalid input. Enter a number between 1 and 9: ";
        cin >> zombie;
    }

    int count = 0;
    while (count < zombie)
    {
        int row = rand() % board_Rows;
        int col = rand() % board_Columns;
        if (board_size[row][col] == ' ')
        {
            int zombie_num = count + 1;
            board_size[row][col] = '0' + zombie_num;
            count++;
        }
    }
}

void Board::display() const
{

    cout << setw(15);
    cout << " .: Alien vs Zombie :." << endl;

    for (int i = 0; i < row; ++i)
    {
        cout << "   ";
        for (int j = 0; j < column; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        cout << setw(2) << (row - i) << " ";

        for (int j = 0; j < column; ++j)
        {
            cout << "|" << board_size[i][j];
        }
        cout << "|" << endl;
    }

    cout << "   ";
    for (int j = 0; j < column; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    cout << "   ";
    for (int j = 0; j < column; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "   ";
    for (int j = 0; j < column; ++j)
    {
        cout << " " << (j + 1) % 10;
    }

    cout << endl;
    cout << endl;
}

void gameBoardDisplay()
{
    Board board;
    board.display();
}

void displayMenu()
{

    cout << "+----------------------------------------------------------+" << endl;
    cout << "|                        ALIEN VS ZOMBIE                   |" << endl;
    cout << "|==========================================================|" << endl;
    cout << "| Select:                                                  |" << endl;
    cout << "| 1 => Display default game settings                       |" << endl;
    cout << "| 2 => Display Help                                        |" << endl;
    cout << "|----------------------------------------------------------|" << endl;
    cout << "| 3 => Change default game settings and START the game.    |" << endl;
    cout << "| 4 => Save game                                           |" << endl;
    cout << "| 5 => Load a game                                         |" << endl;
    cout << "|----------------------------------------------------------|" << endl;
    cout << "| Q => Quit                                                |" << endl;
    cout << "+----------------------------------------------------------+" << endl;
    cout << endl;
}

void displayData(int rows, int columns, int zombies)
{
    cout << "BOARD ROWS = " << rows << endl;
    cout << "BOARD COLUMNS = " << columns << endl;
    cout << "ZOMBIE COUNT = " << zombies << endl;
    cout << endl;
}

void displayHelp()
{
    cout << "up = Move up" << endl;
    cout << "down = Move down" << endl;
    cout << "left = Move left" << endl;
    cout << "right = Move right" << endl;
    cout << "arrow = Change the direction of an arrow" << endl;
    cout << "help = Display these user commands" << endl;
    cout << "save = Save the game" << endl;
    cout << "load = Load the game" << endl;
    cout << "quit = Quit the game" << endl;
    cout << endl;

}
void Board::moveAlien()
{
    int alienRow = -1;
    int alienCol = -1;

    // Find the current position of the alien
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (board_size[i][j] == 'A')
            {
                alienRow = i;
                alienCol = j;
                break;
            }
        }
        if (alienRow != -1) break;
    }

    // Prompt the user for a move direction
    char direction;
    cout << "Enter move direction (up, down, left, right): ";
    cin >> direction;

    // Update the position of the alien based on the move direction
    switch (direction)
    {
        case 'up':
        case 'up':
            if (alienRow > 0) {
                board_size[alienRow][alienCol] = ' ';
                board_size[alienRow - 1][alienCol] = 'A';
            }
            break;
        case 'left':
        case 'left':
            if (alienCol > 0) {
                board_size[alienRow][alienCol] = ' ';
                board_size[alienRow][alienCol - 1] = 'A';
            }
            break;
        case 'down':
        case 'down':
            if (alienRow < row - 1) {
                board_size[alienRow][alienCol] = ' ';
                board_size[alienRow + 1][alienCol] = 'A';
            }
            break;
        case 'right':
        case 'right':
            if (alienCol < col - 1) {
                board_size[alienRow][alienCol] = ' ';
                board_size[alienRow][alienCol + 1] = 'A';
            }
            break;
        default:
            cout << "Invalid move direction." << endl;
            break;
    }
}

int main()
{
    int rows = 5;
    int columns = 9;
    int zombies = 1;

    char choice;
    bool done = false;
    displayMenu();
    do
    {
        cout << "Choice =>";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
        switch (choice)
        {
        case '1':
            displayData(rows, columns, zombies);
            break;
        case '2':
            displayHelp();      
            break;
        case '3':
            gameBoardDisplay();
            break;
        case '4':
        
            break;
        case '5':;
            break;
        case 'Q':
            done = true;
            break;
        default:
            cout << "Invalid selection, try again!" << endl;
            cout << endl;
            break;
        }

    } while (!done);
    cout << endl;
    cout << "THANKS FOR PLAYING!" << endl;
}