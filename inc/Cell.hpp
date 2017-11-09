//
// Cell.hpp for  in /home/kopiz/Workplace/MATHS/304pacman/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Nov  9 15:38:22 2017 Tom Jeammet
// Last update Thu Nov  9 15:53:07 2017 Tom Jeammet
//

#ifndef __CELL_HPP__
# define __CELL_HPP__

# include "Position.hpp"

class					Cell
{
private:
  Position				_pos;
  char					_letter;
  
  public:
  //Ctor
  Cell();
  //Dtor
  ~Cell();
  //Member
  
  //Getter
  Position				getPos(void);
  char					getLetter(void);
  //Setter
  void					setPos(Position);
  void					setLetter(char);
};

#endif /* ! __CELL_HPP__ */
