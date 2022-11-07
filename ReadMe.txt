========================================================================
Lab 3: Program Documendation
========================================================================

Author: Noah Li

Gameboard Illustration
========================================================================

5 4
4 3   X O X
3 2   O X O
2 1   X O X   <---- coordinate index
1 0
0   0 1 2 3 4 <---- board index
  0 1 2 3 4 5 <---- actual index

The 2-D char array that represents the board has a size of 6x6, with an extra row
and an extra column for labels. The array stores y-coordinate in the first bracket
and x-coordinate in the second bracket because the y-coordinate corresponds to the
row number and the x-coordinate corresponds to the column number.

For example, board[i + 1][j + 1] is equivalent to (j, i) in the coordinate system.

Errors and Warnings
========================================================================
There were no significant errors when I was running and testing the program.
The only minor one I encountered was the "linker command failed" issue due
to a compilation error. It was later fixed by using the correct command for
compiling source files. There was also a small coding error that led to the
game to end even when there is no winning piece and there are moves reamining
due to the incorrect placement of x and y coordinates in the 2-D array.

There was one warning I had, which says that "conversion from 'time_t' to
'unsigned int', possible loss of data"

I also adaded the non-standard preprocessor directive "#pragma once" to protect
header files from multiple inclusions. It is well supported across compilers
and has greater performance and portability than "include guards".

Test Cases
========================================================================
IMPORTANT: The program was coded and tested primarily in the local environment on Mac,
in which clang++ is used as the compiler and "a.out is used in the command prompt.
The program was also tested in Windows environmnet, with similar results except that
the program name became "Lab3.exe" instead of "a.out".

[Test Case 1]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe                               Too many or few command line arguments!
                                                                                Usage: Lab3.exe [TicTacToe]
C:\Users\l.yinuo\source\repos\Lab3\Debug>echo %errorlevel%                      1     

(if the users just run the program but do not include any other argument, a usage messgae will be displayed)

[Test Case 2]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe Gomoku                        No game found!
C:\Users\l.yinuo\source\repos\Lab3\Debug>echo %errorlevel%                      2

(when users try to open a game that is not TicTacToe, value no_game would be returned)

[Test Case 3]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe lab3.cpp                      No game found!
C:\Users\l.yinuo\source\repos\lab3\Debug>echo %errorlevel%                      2

(the program cannot open files such as .cpp, .h and so on)

[Test Case 4]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe TicTacToe Gomoku              Too many or few command line arguments!
                                                                                Usage: Lab3.exe [TicTacToe]
C:\Users\l.yinuo\source\repos\Lab3\Debug>echo %errorlevel%                      1

(the program cannot parse multiple files, meaning there should only be 2 commadn line arguments)

[Test Case 5]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,1
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
2,2
                                                                                4     
                                                                                3     
                                                                                2  O   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
3,3
                                                                                4     
                                                                                3   X 
                                                                                2  O   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 3,3;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,2
                                                                                4     
                                                                                3   X 
                                                                                2 OO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 1,2;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game  
3,2
                                                                                4     
                                                                                3   X 
                                                                                2 OOX   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 3,3; 3,2;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game                                                                                                          
3,1
                                                                                4     
                                                                                3   X 
                                                                                2 OOX   
                                                                                1 X O    
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 1,2; 3,1;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,3
                                                                                4     
                                                                                3 X X 
                                                                                2 OOX   
                                                                                1 X O    
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 3,3; 3,2; 1,3;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
2,3
                                                                                4     
                                                                                3 XOX 
                                                                                2 OOX   
                                                                                1 X O    
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 1,2; 3,1; 2,3;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
2,1
                                                                                4     
                                                                                3 XOX 
                                                                                2 OOX   
                                                                                1 XXO    
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 3,3; 3,2; 1,3; 2,1;

                                                                                9 turn(s) were played and no winning moves remained                                                                                                                                                                                                                                              
C:\Users\l.yinuo\source\repos\Lab3\Debug>echo %errorlevel%                      3

(there is no winning piece and there are moves remained, no_winner is returned)


[Test Case 6]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab2\Debug>Lab2.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234
quit                                                                            
                                                                                0 turn(s) were played and Player X has quit the game     
C:\Users\l.yinuo\source\repos\Lab3\Debug>echo %errorlevel%                      4
(when user quits the game, quit is returned and a message is printed out indicating who quits and the number of turns played)

[Test Case 7]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab2\Debug>Lab2.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game                                                                                 
2,2
                                                                                4     
                                                                                3  
                                                                                2  X  
                                                                                1     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 2,2

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
quit                                                                            
                                                                                1 turn(s) were played and Player O has quit the game     
C:\Users\l.yinuo\source\repos\Lab3\Debug>echo %errorlevel%                      4

(when user quits the game, quit is returned and a message is printed out indicating who quits and the number of turns played)

[Test Case 8]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab2\Debug>Lab2.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game                                                                                 
1, 2
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game

(the program treats input with extra space as invalid coordinate)

[Test Case 9]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab2\Debug>Lab2.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game                                                                                 
1 2
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game

(the program treats input with no comma as invalid coordinate)

[Test Case 10]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab2\Debug>Lab2.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game                                                                                 
3,4
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game

(the program treats input that contains values exceeding the inner board dimension as invalid coordinate)

[Test Case 11]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab2\Debug>Lab2.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game                                                                                 
1,0
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game

(the program treats input that contains values smaller than the inner board dimension as invalid coordinate)

[Test Case 12]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab2\Debug>Lab2.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game                                                                                 
one one
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game

(the program treats string input as invalid coordinate)

[Test Case 13]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,1
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
2,2
                                                                                4     
                                                                                3     
                                                                                2  O   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,2
                                                                                4     
                                                                                3    
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
3,3
                                                                                4     
                                                                                3   O 
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 3,3;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game  
1,3
                                                                                4     
                                                                                3 X O 
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2; 1,3;
                                                                                
                                                                                Player X won the game!

(when there are 3-Xs in a column, X won the game)


[Test Case 14]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,1
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
2,2
                                                                                4     
                                                                                3     
                                                                                2  O   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,2
                                                                                4     
                                                                                3    
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
2,1
                                                                                4     
                                                                                3   
                                                                                2 XO   
                                                                                1 XO     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 2,1;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game  
3,3
                                                                                4     
                                                                                3   X
                                                                                2 XO   
                                                                                1 XO     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2; 3,3;
                                                                                
                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
2,3
                                                                                4     
                                                                                3  O 
                                                                                2 XO   
                                                                                1 XO     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 2,1; 2,3;                                                                              
                                                                                
                                                                                Player O won the game!

(when there are 3-Os in a column or row, O won the game)

[Test Case 15]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe TicTacToe                     Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,1
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
2,2
                                                                                4     
                                                                                3     
                                                                                2  O   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,2
                                                                                4     
                                                                                3    
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,3
                                                                                4     
                                                                                3 O  
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 1,3;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game  
3,3
                                                                                4     
                                                                                3 O X
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2; 3,3;

                                                                                Player O's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game 
3,1
                                                                                4     
                                                                                3 O X
                                                                                2 XO   
                                                                                1 X O   
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 1,3; 3,1

                                                                                Player O won the game!

(when there are 3-Os in diagonal, O won the game)


Extra Credit Portion:
========================================================================
The auto_player() method takes no parameters and determines the move for
the auto player O to try to win the game.

Design and Implementation
========================================================================
If the users choose to play against the computer, the global static boolean
variable "auto_play" will then be set to true. A different segment of the
program will be then activated, where, during a turn of O, a sound logical
move is generated automatically based on the three conditions:

  1. if the auto player can win, it should

  2. if the auto player can't win, but the human can, it should block.

  3. if either player only has one piece in any given row/column/diagonal,
     a random move is generate

However, when there are more than one possibility of X/O winning, O will
always chose the first coordinate that it checks. For instance:

  O
OX
X X

In this situation, there are 2 ways X can win the game:

  1. by taking (2, 1)
  
  2. by taking (1, 3)

The computer would always choose to take (2, 1) since the method canwin()
checks the bottom coordinate first. So the result would be:

  O
OX
XOX

The auto_play() method utilizes the method canwin(char player, unsigned int &
x, unsigned int & y) to determine if the given player can immediately win the
game by implementing a move.

The auto-generated coordinate inputs for the computer player O (x, y) are
passed through the following path:

turn() ---> empty int x, y are created ------
                                            |
                                            | x,y still empty
                                            ↓
                                       auto_player(x, y)
                                            |
      values determined based on conditions | 
                                            |  assigned inside canwin() and passed to auto_player(x, y)
                                            ----> canwin("O", x, y)---------------------------------------
                                            |                                                            | 
                                            |                                                            |---------> turn_helper(x, y)
                                            |                                                            |              values passed to helper method that prints out the board
                                            ----> rand() % 3 + 1 -----------------------------------------
                                               assigned randomly and stored in auto_player(x, y)

Test Cases
========================================================================
[Test Case 16]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe TicTacToe pve                 Game mode is not available
C:\Users\l.yinuo\source\repos\Lab3\Debug>echo %errorlevel%                      5

(when users enter a mode other than "auto_player", program status "unavailabel_mode" would be returned)

[Test Case 17]
Command line:                                                                   Output:
C:\Users\l.yinuo\source\repos\Lab3\Debug>Lab3.exe TicTacToe auto_player         Wecome to the TicTacToe Game
                                                                                ============================
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1     
                                                                                0     
                                                                                 01234

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,1
                                                                                4     
                                                                                3     
                                                                                2     
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1;

                                                                                Player O's Turn
                                                                                ===============
                                                                                4     
                                                                                3     
                                                                                2  O   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game
1,2
                                                                                4     
                                                                                3    
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2;

                                                                                Player O's Turn
                                                                                ===============
                                                                                4     
                                                                                3 O  
                                                                                2 XO   
                                                                                1 X     
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 1,3;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game  
3,1
                                                                                4     
                                                                                3 O 
                                                                                2 XO   
                                                                                1 X X    
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2; 3,1;

                                                                                Player O's Turn
                                                                                ===============
                                                                                4     
                                                                                3 O 
                                                                                2 XO   
                                                                                1 XOX   
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 1,3; 2,1;

                                                                                Player X's Turn
                                                                                ===============
                                                                                Enter a valid coordinate 'x,y' or 'quit' to exit the game  
3,3
                                                                                4     
                                                                                3 O X
                                                                                2 XO   
                                                                                1 XOX    
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player X: 1,1; 1,2; 3,1; 3,3

                                                                                Player O's Turn
                                                                                ===============
                                                                                4     
                                                                                3 OOX
                                                                                2 XO   
                                                                                1 XOX   
                                                                                0     
                                                                                 01234
                                                                                
                                                                                Player O: 2,2; 1,3; 2,1; 2,3
                 
                                                                                Player O won the game!

(as shown above, player O will defend whenever X is about to make a 3-Xs, and when there is available spot for O to make a 3-Os, O will take that spot)