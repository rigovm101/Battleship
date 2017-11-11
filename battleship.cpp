//battleship.cpp
//Rigoberto Valadez Mena
//A01154892
//10/25/17
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace std;
/*
 Processing Function
 This function will translate the input from the user to the position within the array.
 Parameters: The character with the column, an emtpy integer with the columns and and integer with the row.
 Return: Nothing
 */
void translateCoordinates(char &cColumn, int &iColumn, int &iRow){
    //Switch Statement to translate the cColumn to an integer.
    switch (cColumn){
        case 'A':
            iColumn = 1;
            break;
        case 'B':
            iColumn = 2;
            break;
        case 'C':
            iColumn = 3;
            break;
        case 'D':
            iColumn = 4;
            break;
        case 'E':
            iColumn = 5;
            break;
        case 'F':
            iColumn = 6;
            break;
        case 'G':
            iColumn = 7;
            break;
        case 'H':
            iColumn = 8;
            break;
        case 'I':
            iColumn = 9;
            break;
        case 'J':
            iColumn = 10;
            break;
        default:
            break;
    }
    //If the user entered the row 0
    if (iRow == 0) {
        //It will change to the position 10 within the array
        iRow = 10;
    }
}
/*
 Output Function
 This function will print the grid to the user.
 Parameters: The array with the grid.
 Return: Nothing
 */
void printGrid(char cArrGrid[11][11]){
    //Loop to go through the array
    for(int iCounter = 0; iCounter < 11; iCounter++){
        for(int iSecondCounter = 0; iSecondCounter < 11; iSecondCounter++){
            switch (cArrGrid[iCounter][iSecondCounter]) {
                case '.':
                    cout << cArrGrid[iCounter][iSecondCounter] << "  ";
                    break;
                    
                default:
                    cout << cArrGrid[iCounter][iSecondCounter] << "  ";
                    break;
            }
        }
        cout << endl;
        cout << endl;
    }
    //Moves to the next line
    cout << endl;
}
/*
 Input Function
 This function will be used when we want the user to enter the coordinates.
 Parameters: A char with the column and an integer with the row
 Return: Nothing
 */
void getCoordinates(char &cColumn, int &iRow){
    //Asks the user to enter a column
    cout << "Please enter a Column in uppercase letters:" << endl;
    //Reads the column
    cin >> cColumn;
    //Asks the user to enter a row
    cout << "Please enter a Row with a number:" << endl;
    //Reads the row
    cin >> iRow;
}
/*
 Processing Function
 This function will begin the game, allowing the user to enter his ships.
 Parameters: The array of the user.
 Return: Nothing
 */
void beginGame(char cArrGridPlayerShips[11][11], char cArrGridEnemyShips[11][11]){
    //Variable initialization
    char cColumn;
    //Variable initialization
    int iRow, iColumn, iDirection;
    
    srand(time(0));
    
    //Enemy Carrier Positioning
    for(int iCounter = 0; iCounter < 5; iCounter++){
        if(iCounter == 0){
            iDirection = rand() % 2 + 1;
        }
        if (iDirection == 1) {
            if(iCounter == 0){
                iColumn = rand() % 2 + 1;
                iRow = rand() % 6 + 1;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iColumn++;
        }
        else{
            if(iCounter == 0){
                iColumn = rand() % 6 + 1;
                iRow = rand() % 2 + 1;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iRow++;
        }
    }
    //Enemy Battleship Positioning
    for(int iCounter = 0; iCounter < 4; iCounter++){
        if(iCounter == 0){
            iDirection = rand() % 2 + 1;
        }
        if (iDirection == 1) {
            if(iCounter == 0){
                iColumn = 7;
                iRow = rand() % 6 + 1;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iColumn++;
        }
        else{
            if(iCounter == 0){
                iColumn = rand() % 4 + 7;
                iRow = rand() % 3 + 1;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iRow++;
        }
    }
    //Enemy Cruiser Positioning
    for(int iCounter = 0; iCounter < 3; iCounter++){
        if(iCounter == 0){
            iDirection = rand() % 2 + 1;
        }
        if (iDirection == 1) {
            if(iCounter == 0){
                iColumn = rand() % 2 + 1;
                iRow = rand() % 4 + 7;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iColumn++;
        }
        else{
            if(iCounter == 0){
                iColumn = rand() % 4 + 1;
                iRow = rand() % 2 + 7;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iRow++;
        }
    }
    //Enemy Submarine Positioning
    for(int iCounter = 0; iCounter < 3; iCounter++){
        if(iCounter == 0){
            iDirection = rand() % 2 + 1;
        }
        if (iDirection == 1) {
            if(iCounter == 0){
                iColumn = rand() % 2 + 7;
                iRow = rand() % 4 + 7;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iColumn++;
        }
        else{
            if(iCounter == 0){
                iColumn = rand() % 4 + 7;
                iRow = rand() % 2 + 7;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iRow++;
        }
    }
    //Enemy Destroyer Positioning
    for(int iCounter = 0; iCounter < 2; iCounter++){
        if(iCounter == 0){
            iDirection = rand() % 2 + 1;
        }
        if (iDirection == 1) {
            if(iCounter == 0){
                iColumn = 5;
                iRow = rand() % 4 + 7;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iColumn++;
        }
        else{
            if(iCounter == 0){
                iColumn = rand() % 2 + 7;
                iRow = rand() % 3 + 7;
            }
            cArrGridEnemyShips[iRow][iColumn] = 'Z';
            iRow++;
        }
    }
    
    printGrid(cArrGridEnemyShips);
    
    //Welcome message to the user
    cout << "Welcome to battleship, please enter the position of your ships" << endl;
    //Loop that repeats for for each space of the ships.
    for (int iCounter = 0; iCounter < 17; iCounter++){
        //Carrier positioning
        if(iCounter < 5){
            //Prints the current grid to the user.
            printGrid(cArrGridPlayerShips);
            //Asks the user to enter the position
            cout << "Please enter the position " << iCounter + 1 << " of your carrier:" << endl;
            //Gets the input from the user
            getCoordinates(cColumn, iRow);
            //Translates the input to be used by the program
            translateCoordinates(cColumn, iColumn, iRow);
            //Marks the position in the grid
            cArrGridPlayerShips[iRow][iColumn] = 'Z';
        }else if(iCounter < 9){
            printGrid(cArrGridPlayerShips);
            cout << "Please enter the position " << iCounter - 4 << " of your battleship:" << endl;
            getCoordinates(cColumn, iRow);
            translateCoordinates(cColumn, iColumn, iRow);
            cArrGridPlayerShips[iRow][iColumn] = 'Z';
        }else if(iCounter < 12){
            printGrid(cArrGridPlayerShips);
            cout << "Please enter the position " << iCounter - 8 << " of your cruiser:" << endl;
            getCoordinates(cColumn, iRow);
            translateCoordinates(cColumn, iColumn, iRow);
            cArrGridPlayerShips[iRow][iColumn] = 'Z';
        }else if(iCounter < 15){
            printGrid(cArrGridPlayerShips);
            cout << "Please enter the position " << iCounter - 11 << " of your submarine:" << endl;
            getCoordinates(cColumn, iRow);
            translateCoordinates(cColumn, iColumn, iRow);
            cArrGridPlayerShips[iRow][iColumn] = 'Z';
        }else if(iCounter < 17){
            printGrid(cArrGridPlayerShips);
            cout << "Please enter the position " << iCounter - 14 << " of your destroyer:" << endl;
            getCoordinates(cColumn, iRow);
            translateCoordinates(cColumn, iColumn, iRow);
            cArrGridPlayerShips[iRow][iColumn] = 'Z';
        }
        
    }
    printGrid(cArrGridPlayerShips);
}
/*
 Processing Function
 This function will run when it is the player's turn.
 Parameters: The grid where the player fires, a character column, an integer column and row,
 the grid where the enemy ships are, and the score of the player.
 Return: Nothing
 */
void playerTurn(char cArrGridFire[11][11], char &cColumn, int &iColumn, int &iRow, char cArrGridEnemyShips[11][11], int &iPlayerScore){
    
    //Prints the grid so the player can see
    printGrid(cArrGridFire);
    //Displays message to fire.
    cout << "Please enter the coordinates to fire: " << endl;
    //Input Function
    getCoordinates(cColumn,iRow);
    //Processing Function
    translateCoordinates(cColumn, iColumn, iRow);
    //Checks if it was a hit
    if(cArrGridEnemyShips[iRow][iColumn] != '.' and cArrGridEnemyShips[iRow][iColumn] != 'M'){
        //Changes the firing grid
        cArrGridFire[iRow][iColumn] = 'X';
        //Output Function
        printGrid(cArrGridFire);
        //Tells the player it was a hit
        cout << "It was a Hit!" << endl;
        //Adds one to the score
        iPlayerScore++;
        cout << endl;
    }
    //Else it was not a hit
    else{
        //Changes the firing grid
        cArrGridFire[iRow][iColumn] = 'M';
        //Output Function
        printGrid(cArrGridFire);
        //Tells the user he missed
        cout << "Nothing There!" << endl;
        cout << endl;
    }
}
/*
 Processing Function
 This function will be executed when it's the computers turn to fire.
 Parameters: The grid with the player's ships and the score of the computer
 Return: Nothing
 */
void computersTurn(char cArrGridPlayerShips[11][11], int &iComputerScore){
    
    int iRow, iColumn;
    bool bAlreadyUsed = true;
    
    
    while(bAlreadyUsed == true){
        iRow = rand() % 10 + 1;
        iColumn = rand() % 10 + 1;
        
        if (cArrGridPlayerShips[iRow][iColumn] == 'X' or cArrGridPlayerShips[iRow][iColumn] == 'M') {
            bAlreadyUsed = true;
        }else{
            bAlreadyUsed = false;
        }
    }
    
    if(cArrGridPlayerShips[iRow][iColumn] == 'Z'){
        cout << "The computer made a hit!" << endl;
        cArrGridPlayerShips[iRow][iColumn] = 'X';
        iComputerScore++;
        printGrid(cArrGridPlayerShips);
    }
    else{
        cout << "The computer missed!" << endl;
        cArrGridPlayerShips[iRow][iColumn] = 'M';
        printGrid(cArrGridPlayerShips);
    }
    cout << endl;
}


/*
 Processing Function
 This function will determine when either the computer or the player wins.
 Parameters: Two integers with the score.
 Return: Either true or false.
 */
bool checkForWinners(int iPlayerScore, int iComputerScore){
    //Checks if the player wins
    if(iPlayerScore == 17){
        //Tells the user he won
        cout << "You win!!" << endl;
        //Returns true
        return true;
    }
    //Checks if the computer won
    else if(iComputerScore == 17){
        //Tells the user the computer won
        cout << "The computer wins!" << endl;
        //Returns true
        return true;
    }
    //Else, nobody has won
    else{
        //Returns false
        return false;
    }
}
int main(){
    
    char cColumn;
    int iColumn, iRow, iPlayerScore = 0, iComputerScore = 0;
    bool bGameStatus = false;
    
    char cArrGridPlayerShips[11][11] = {{' ','A','B','C','D','E','F','G','H','I','J'},{'1','.','.','.','.','.','.','.','.','.','.'},{'2','.','.','.','.','.','.','.','.','.','.'},{'3','.','.','.','.','.','.','.','.','.','.'},{'4','.','.','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','.','.','.','.'},{'6','.','.','.','.','.','.','.','.','.','.'},{'7','.','.','.','.','.','.','.','.','.','.'},{'8','.','.','.','.','.','.','.','.','.','.'},{'9','.','.','.','.','.','.','.','.','.','.'},{'0','.','.','.','.','.','.','.','.','.','.'}};
    char cArrGridFire[11][11] = {{' ','A','B','C','D','E','F','G','H','I','J'},{'1','.','.','.','.','.','.','.','.','.','.'},{'2','.','.','.','.','.','.','.','.','.','.'},{'3','.','.','.','.','.','.','.','.','.','.'},{'4','.','.','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','.','.','.','.'},{'6','.','.','.','.','.','.','.','.','.','.'},{'7','.','.','.','.','.','.','.','.','.','.'},{'8','.','.','.','.','.','.','.','.','.','.'},{'9','.','.','.','.','.','.','.','.','.','.'},{'0','.','.','.','.','.','.','.','.','.','.'}};
    char cArrGridEnemyShips[11][11] = {{' ','A','B','C','D','E','F','G','H','I','J'},{'1','.','.','.','.','.','.','.','.','.','.'},{'2','.','.','.','.','.','.','.','.','.','.'},{'3','.','.','.','.','.','.','.','.','.','.'},{'4','.','.','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','.','.','.','.'},{'6','.','.','.','.','.','.','.','.','.','.'},{'7','.','.','.','.','.','.','.','.','.','.'},{'8','.','.','.','.','.','.','.','.','.','.'},{'9','.','.','.','.','.','.','.','.','.','.'},{'0','.','.','.','.','.','.','.','.','.','.'}};
    
    beginGame(cArrGridPlayerShips, cArrGridEnemyShips);
    
    while(bGameStatus != true){
        
        playerTurn(cArrGridFire, cColumn, iColumn, iRow, cArrGridEnemyShips, iPlayerScore);
        
        bGameStatus = checkForWinners(iPlayerScore, iComputerScore);
        
        computersTurn(cArrGridPlayerShips, iComputerScore);
        
        bGameStatus = checkForWinners(iPlayerScore, iComputerScore);
    }
    
    
    
    return 0;
}

