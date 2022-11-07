//lab3.h
//name: Noah Li
//email: l.yinuo@wustl.edu
//wustl ID: 502851
//header file that declares functions, enumerations and class that are used in the source files of the program

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//declare a global variable for auto-play check
static bool auto_play = false;

//declare an enumerations for different array indices relevant to the program
enum ProgramIndices
{
  program_name,
  game_name,
  game_mode,
  exp_num_args = 2,
  num_args_auto
};

//declare an enumeration for the different success and failure values of the program
enum ProgramStatus
{
  success,
  wrong_num_args,
  no_game,
  no_winner,
  quit,
  unavailable_mode
};

//declare an enumeration for the different indices relevant to the game
enum GameIndices
{
  zero,
  start,
  one,
  two,
  three,
  dim,
  num_sqrs = 9
};

//declare a class for the TicTacToe game
class TicTacToeGame {
  //declare insertion operator as a friend so that it can access the private member variables
  friend std::ostream & operator<< (std::ostream & cout, const TicTacToeGame & game);
  public:
    TicTacToeGame(); //declare the constructor of the class
    bool done();
    bool canwin(char player, unsigned int & x, unsigned int & y);
    bool draw();
    int prompt(unsigned int & x, unsigned int & y); //pass-by-ref because we don't want to pass by a copy of x and y
    int turn();
    int turn_helper(unsigned int & x, unsigned int & y); //helper method that hides repeated implemetation details
    int play();
    int auto_player(unsigned int & x, unsigned int & y); //determines the move for auto player to win
  private:
    // char board[dim + 1][dim + 1]; //an extra row and column are added for board labels
    std::vector<std::vector<char> > board;
    // char ** board;
    int moves;
    char cur_player;
    bool quit; //used to check if the users quit
    std::vector<int> x_hist, o_hist; //records sequentially the historical coordinate inputs from player X and O
};

//declare an insertion operator
std::ostream & operator<< (std::ostream & cout, const TicTacToeGame & game);

//declare a usage message function
int usageMessage(char * programName);