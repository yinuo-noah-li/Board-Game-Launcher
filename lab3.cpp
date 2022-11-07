//lab3.cpp
//name: Noah Li
//email: l.yinuo@wustl.edu
//wustl ID: 502851
//source file that defines the main, usage message and game functions

#include "lab3.h"
using namespace std;

//constructor of the TicTacToeGame class
TicTacToeGame::TicTacToeGame()
{
  //initialize the current player
  cur_player = 'X';
  moves = 0;
  quit = false;
  //initialize the board with 5x5 empty squares
  for (int i = 0; i <= dim; ++i)
  {
    vector<char> v;
    for (int j = 0; j <= dim; ++j)
    {
      v.push_back(' ');
    }
    board.push_back(v);
  }
  // for (int i = start; i <= dim; ++i)
  // {
  //   for (int j = start; j <= dim; ++j)
  //   {
  //     board[i][j] = ' ';
  //   }
  // }
}

//overload the insertion operator to print the current state of the game board
ostream & operator<< (ostream & cout, const TicTacToeGame & tictactoegame)
{
  //y with descending order
  for (int i = dim; i >= 0; --i)
  {
    //x with ascending order
    for (int j = 0; j <= dim; ++j)
    {
      if (j == 0 && i > 0)
      { //print out the vertical labels
        cout << i - 1;
      }
      else if (i == 0 && j > 0)
      { //print out the vertical labels
        cout << j - 1;
      }
      else if (i == 0 && j == 0)
      { //lower left empty corner
        cout << ' ';
      }
      else 
      {
        cout << tictactoegame.board[i][j];
      }
    }
    cout << endl;
  }
  return cout;
}

//return true if there are 3-Xs/Os 
bool TicTacToeGame::done()
{
  //check bottom left to upper right
  if (board[one][one] != ' ' && board[two][two] != ' ' && board[three][three] != ' ')
  {
    if (board[one][one] == board[two][two] && board[two][two] == board[three][three])
    {
      return true;
    }  
  }
  //check upper left to bottom right
  if (board[one][three] != ' ' && board[two][two] != ' ' && board[three][one] != ' ')
  {
    if (board[one][three] == board[two][two] && board[two][two] == board[three][one])
    {
      return true;
    }
  }
  //check columns
  for (unsigned int i = one; i <= three; ++i)
  {
    if (board[one][i] != ' ' && board[two][i] != ' ' && board[three][i] != ' ')
    {
      if (board[one][i] == board[two][i] && board[two][i] == board[three][i])
      {
        return true;
      }
    }
  }

  //check rows
  for (unsigned int i = one; i <= three; ++i)
  {
    if (board[i][one] != ' ' && board[i][two] != ' ' && board[i][three] != ' ')
    {
      if (board[i][one] == board[i][two] && board[i][two] == board[i][three])
      {
        return true;
      }
    }
  }

  return false;
}

//place X/O at every empty square and check if done() is true
bool TicTacToeGame::canwin(char player, unsigned int & x, unsigned int & y)
{
  for (int i = one; i <= three; ++i)
  {
    for (int j = one; j <= three; ++j)
    {
      if (board[i][j] == ' ')
      {
        board[i][j] = player;
        if (done())
        {
          x = j  - 1;
          y = i - 1;
          return true;
        }
        board[i][j] = ' ';
      }
    }
  }

  return false;
}

//return true if is a draw
bool TicTacToeGame::draw()
{
  //if there is move remained or a 3-Xs/Os
  if (done() || moves < num_sqrs)
  {
    return false;
  } else //it is draw
  {
    return true;
  }
}

//repeatedly prompt the user until either "quit" or a valid coordinate is entered
int TicTacToeGame::prompt(unsigned int & x, unsigned int & y)
{
  bool valid = false; //variable used to track the validity of the input
  while (valid == false)
  {
    cout << "Enter a valid coordinate 'x,y' or 'quit' to exit the game" << endl;
    string input;
    cin >> input;
    if (input == "quit")
    {
      quit = true;
      valid = true;
    } else
    {
      // replace the comma with a space character
      for (unsigned int i = 0; i < input.size(); ++i)
      {
        if (input[i] == ',')
        {
          input[i] = ' ';
        }
      }
      //create a string stream object to wrap the input
      istringstream iss(input);
      //extract two values from the stream to the parameters
      if (iss >> x >> y)
      {
        //the coordinate is valid if it is empty
        if (board[y + 1][x + 1] == ' ')
        {
          //the coordinate is valid if it is within the inner board
          if (x > 0 && y > 0 && x <= 3 && y <= 3)
          {
            valid = true;
          }
        }
      }
    }
  }

  return success;
}

//determine the turns
int TicTacToeGame::turn()
{
  unsigned int x, y; //variables to store the user inputs
  cout << endl;
  cout << "Player " << cur_player << "'s Turn" << endl;
  cout << "===============" << endl;


  if (auto_play) //enter the PVE mode
  {
    if (cur_player == 'X')
    { //pass a reference of x, y so that the values of unsigned int x, y actually change
      prompt(x, y);
    } else
    { //set current player O as the auto player
      auto_player(x, y);
    }

    if (!quit)
    {
      turn_helper(x, y);
    }
  } else //normal PVP mode
  {
    prompt(x, y);
    if (!quit)
    {
      turn_helper(x, y);
    }
  }

  return success;
}

//helper method that places the piece on the board that will be printed out
int TicTacToeGame::turn_helper(unsigned int & x, unsigned int & y)
{
  //place a piece at the designated coordinate on the board
  board[y + 1][x + 1] = cur_player;
  cout << endl;
  cout << *this; //print out the board
  cout << endl;

  //print out the sequence of historical inputs
  cout << "Player " << cur_player << ": ";
  if (cur_player == 'X')
  {
    x_hist.push_back(x);
    x_hist.push_back(y);
    for(unsigned int i = 0; i < x_hist.size() - 1; i = i + 2)
    {
      cout << x_hist[i] << "," << x_hist[i + 1] << "; ";
    }
    cur_player = 'O';
  } else
  {
    o_hist.push_back(x);
    o_hist.push_back(y);
    for(unsigned int i = 0; i < o_hist.size() - 1; i = i + 2)
    {
      cout << o_hist[i] << "," << o_hist[i + 1] << "; ";
    }
    cur_player = 'X';
  }
  cout << endl;
  ++moves; //increment the move

  return success;
}

//call turn() repeatedly until the game is done, then print out thet result
int TicTacToeGame::play()
{
  cout << *this; //print out the initial state of the board
  
  while (!done() && !draw() && !quit)
  { //keep calling turn until one of the conditions fails
    turn();
  }

  if (quit)
  {
    cout << endl;
    cout << moves << " turn(s) were played and Player " << cur_player << " has quit the game" << endl;
    return quit;
  }
  else if (draw())
  {
    cout << endl;
    cout << moves << " turn(s) were played and no winning moves remained" << endl;
    return no_winner;
  }  
  else
  {
    if (cur_player == 'X')
    {
      cout << endl;
      cout << "Player O won the game!" << endl;
    } else if (cur_player == 'O')
    {
      cout << endl;
      cout << "Player X won the game!" << endl;
    }
  }

  return success;
}

//determines the move for auto player O to win the game
int TicTacToeGame::auto_player(unsigned int & x, unsigned int & y)
{
  bool valid = false; //used to track the validity of auto-generate inputs

  //check if player O can win first
  if (canwin(cur_player, x, y))
  {
  } else if (canwin('X', x, y)) //if O cannot, check X
  {
    cout << "Player O chose to defend" << endl;
  } else
  {
    //if both can't, generate a random move for O
    while (valid == false)
    {
      srand((unsigned int)time(NULL));
      x = rand() % 3 + 1;
      y = rand() % 3 + 1;
      //the input is valid if the coordinate is empty
      if (board[y + 1][x + 1] == ' ')
      {
        valid = true;
      }
    }
  }
  return success;
}

//display a usage message when there are too many or few command line arguments
int usageMessage(char * argv)
{
	cout << "Too many or few command line arguments!" << endl;
	cout << "Usage: " << argv << " [TicTacToe]" << "(auto_player)" << endl;
	return wrong_num_args;
}

//main function of the program, which uses the new TicTacToe class created to play the game
int main(int argc, char * argv[])
{
  if (argc != exp_num_args && argc != num_args_auto)
	{
    return usageMessage(argv[program_name]); 
	} else
  {
    string game = argv[game_name];
    if (game != "TicTacToe")
    {
      cout << "Game not found!" << endl;
      return no_game;
    }
    if (argc == num_args_auto)
    {
      string mode = argv[game_mode];
      if (mode != "auto_player")
      {
        cout << "Game mode is not available!" << endl;
        return unavailable_mode;
      } else
      {
        auto_play = true;
      }
    }
  }

  //create a new TicTacToeGame object
  TicTacToeGame tictactoegame;
  
  cout << "Wecome to the TicTacToe Game" << endl;
  cout << "============================" << endl;

  //create a variable to store the status of the game
  int status = tictactoegame.play();

  return status;
}