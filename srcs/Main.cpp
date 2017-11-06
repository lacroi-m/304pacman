//
// Main.cpp for  in /mnt/c/Users/ze/Desktop/gitshit/304pacman
// 
// Made by DESKTOP-FQFT07H
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 10:00:19 2017 DESKTOP-FQFT07H
// Last update Mon Nov  6 11:24:20 2017 DESKTOP-FQFT07H
//

#include "Main.hpp"

int					launch(std::fstream &makefile, std::string file, int ac)
{
  std::vector<std::string>		lines;
  std::string				tmp;
  Parser				parser;

  while (std::getline(makefile, tmp))
    lines.push_back(tmp);
  parser.parse(lines);
  if (ac == 2)
    {
      createMatrix(parser, parser.getFiles());
      std::cout << std::endl;
      printRelations(parser.getFiles(), parser.getDepends(), parser.getExe());
    }
  else
    {
      if (!is_in_files(parser.getFiles(), file))
	return (84);
      else
	{
	  printCompiles(parser, file);
	  if (file.compare(parser.getExe()) == 0)
	    std::cout << std::endl;
	  else
	    print_exeLine(parser.getDepends(), parser.getExe());
	}
    }
  return (0);
}

int					checks(int ac, char **av)
{
  std::vector<std::string>		lines;
  std::fstream				makefile;
  std::fstream				test;
  int					ret;

  if (ac < 2)
    throw (Err("Usage:\n\t./303make Makefile [file]"));
  makefile.open(av[1]);
  if (makefile.fail())
    throw (Err("Error: no such file"));
  if (ac != 2 && ac != 3)
    throw (Err("Usage:\n\t./303make Makefile [file]"));
  else
    {
      if (ac == 2)
	launch(makefile, "", ac);
      if (ac == 3)
	{
	  test.open(av[2]);
	  if ((ret = launch(makefile, av[2], ac)) == 84)
	    return (ret);
	}
    }
  return (0);
}

int					main(int ac, char **av)
{
  int					ret;
  
    try
      {
	if ((ret = checks(ac, av)) == 84)
	  return (84);
      }
    catch (Err &err)
      {
	err.print_msg();
	return (84);
      }
    return (0);
}
