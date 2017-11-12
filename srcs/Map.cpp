//
// Map.cpp for  in /home/kopiz/Workplace/MATHS/304pacman/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Nov 10 12:27:55 2017 Tom Jeammet
// Last update Sun Nov 12 16:28:27 2017 Tom Jeammet
//

#include "Map.hpp"

//Ctor
Map::Map(std::vector<std::string> map_str)
{
  std::vector<std::string>::iterator            it;
  std::vector<std::vector<Cell> >		map;
  std::vector<Cell>                             line;
  std::string                                   tmp;
  std::string					first;
  Position                                      pos;
  Cell                                          cell;
  int                                           i;
  int                                           j;

  i = 0;
  map = getMap();
  setSizeX(map_str.size());
  first = *map_str.begin();
  setSizeY(first.size());
  setFounded(false);
  for (it = map_str.begin(); it != map_str.end(); it++)
    {
      j = 0;
      tmp = *it;
      line.clear();
      while (j < (int)tmp.size())
	{
	  pos.setX(i);
	  pos.setY(j);
	  cell.setLetter(tmp.at(j));
	  cell.setPos(pos);
	  line.push_back(cell);
	  j = j + 1;
	}
      map.push_back(line);
      i = i + 1;
    }
  setMap(map);
}

//Dtor
Map::~Map()
{

}

//Member
void                                            Map::printMap()
{
  std::vector<std::vector<Cell> >::iterator     it;
  std::vector<Cell>::iterator                   jt;
  std::vector<Cell>                             tab;
  Cell                                          cell;

  for (it = _map.begin(); it != _map.end(); it++)
    {
      tab = *it;
      for (jt = tab.begin(); jt != tab.end(); jt++)
	{
	  cell = *jt;
	  std::cout << cell.getLetter();
	}
      std::cout << std::endl;
    }
}

Position				Map::checkOnePos(Position pos, int nb, char space)
{
  Position				tmp;

  if (nb > 9)
    nb = 0;
  if (((pos.getX() < getSizeX()) && (pos.getY() < getSizeY())) &&
      (((pos.getX() >= 0) && (pos.getY() >= 0))))
    {
      if (_map.at(pos.getX()).at(pos.getY()).getLetter() == space)
	{
	  _map.at(pos.getX()).at(pos.getY()).setLetter(nb + 48);
	  tmp.setX(pos.getX());
	  tmp.setY(pos.getY());
	  return (tmp);
	}
      if (_map.at(pos.getX()).at(pos.getY()).getLetter() == 'P')
	setFounded(true);
      tmp.setX(- 1);
      tmp.setY(- 1);
      return (tmp);
    }
  else
    {
      tmp.setX(- 1);
      tmp.setY(- 1);
      return (tmp);
    }
}

void					Map::search(char space)
{
  Position				pos;
  Position				tmp;
  Position				tmp2;
  int					nb;
  int					i;

  i = 0;
  nb = 1;
  pos = findChar('F');
  while (!getFounded())
    {
      if (i == 0)
	tmp.setUp(pos);
      else if (i == 1)
	tmp.setRight(pos);
      else if (i == 2)
	tmp.setDown(pos);
      else if (i == 3)
	tmp.setLeft(pos);
      if (nb == 1)
	tmp2 = checkOnePos(tmp, nb, space);
      else
	tmp2 = checkOnePos(tmp, (int)(_map.at(pos.getX()).at(pos.getY()).getLetter() - 48) + 1, space);
      if ((tmp2.getX() != - 1) && (tmp2.getY() != - 1))
	toCheck.push_back(tmp2);
      i = i + 1;
      if (i == 4)
	{
	  nb = nb + 1;
	  i = 0;
	  pos = toCheck.at(0);
	  toCheck.erase(toCheck.begin());
	}
    }
}

/*
void					Map::search(char space)
{
  Position				pos;
  Position				tmp;
  Position				tmp2;
  int					nb;
  int					tmp_nb;
  int					tmp2_nb;
  int					i;

  i = 0;
  nb = 1;
  tmp_nb = 1;
  tmp2_nb = 1;
  pos = findChar('F');
  while (!getFounded())
    {
      if (i == 0)
	tmp.setUp(pos);
      else if (i == 1)
	tmp.setRight(pos);
      else if (i == 2)
	tmp.setDown(pos);
      else if (i == 3)
	tmp.setLeft(pos);
      tmp2 = checkOnePos(tmp, nb, space);
      if ((tmp2.getX() != - 1) && (tmp2.getY() != - 1))
	toCheck.push_back(tmp2);
      i = i + 1;
      if (i == 4)
	{
	  if (i == tmp_nb / tmp2_nb)
	    {
	      tmp2_nb = tmp2_nb + 2;
	      if (nb == 9)
		nb = 0;
	      else
		nb = nb + 1;
	    }
	  i = 0;
	  pos = toCheck.at(0);
	  toCheck.erase(toCheck.begin());
	}
      tmp_nb = tmp_nb + 1;
    }
}
*/

Position				Map::findChar(char c)
{
  std::vector<std::vector<Cell> >::iterator     it;
  std::vector<std::vector<Cell> >		map;
  std::vector<Cell>::iterator                   jt;
  std::vector<Cell>                             tab;
  Position                                      pos;
  Cell                                          cell;

  map = getMap();
  for (it = map.begin(); it != map.end(); it++)
    {
      tab = *it;
      for (jt = tab.begin(); jt != tab.end(); jt++)
	{
	  cell = *jt;
	  if (cell.getLetter() == c)
	    return (cell.getPos());
	}
    }
  pos.setX(- 1);
  pos.setY(- 1);
  return (pos);
}

//Getter
std::vector<std::vector<Cell> >		Map::getMap()
{
  return (_map);
}

std::vector<Position>			Map::getToCheck()
{
  return (toCheck);
}

int					Map::getSizeX()
{
  return (size_x);
}

int					Map::getSizeY()
{
  return (size_y);
}

bool					Map::getFounded()
{
  return (founded);
}

//Setter
void					Map::setMap(std::vector<std::vector<Cell> > map)
{
  _map = map;
}

void					Map::setToCheck(std::vector<Position> _toCheck)
{
  toCheck = _toCheck;
}

void					Map::setSizeX(int x)
{
  size_x = x;
}

void					Map::setSizeY(int y)
{
  size_y = y;
}

void					Map::setFounded(bool f)
{
  founded = f;
}
