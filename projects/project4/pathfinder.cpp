#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"
#include <vector>

struct State {int r; int c;};

int breadthFirst(Image<Pixel>);

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Read input image from file
  Image<Pixel> image = readFromFile(input_file);

  // TODO
  breadthFirst(image);

  // Write solution image to file
  writeToFile(image, output_file);
  
  
}

int breadthFirst(Image<Pixel> image)
{
  Queue<State, List<State>> frontier;
  std::vector<std::vector<bool>> explored(image.width(),std::vector<bool>(image.height(),0));
  State s;

  //set red pixel as start
  for (int i = 0; i < image.width(); i++)
  {
    for (int j = 0; j < image.height(); j++)
    {
      if(image(i,j) == RED)
        s = {i,j};
    }
  }
  
  frontier.enqueue(s);
  while(!frontier.isEmpty()){
    s = frontier.peekFront();
    
    frontier.dequeue();

    //are we at the end?
    if(s.r == 0 || s.r == image.width()-1 || s.c == 0 || s.c == image.height()-1 )
    {
      image(s.r,s.c) = GREEN;
      return EXIT_SUCCESS;
    }

    if(image(s.r+1,s.c) == WHITE && explored[s.r+1][s.c] != 1){
      State f = {s.r+1,s.c};
      frontier.enqueue(f);
      explored[s.r+1][s.c] == 1;
    }
    if(image(s.r-1,s.c) == WHITE && explored[s.r-1][s.c] != 1){
      State f = {s.r-1,s.c};
      frontier.enqueue(f);
      explored[s.r-1][s.c] == 1;
    }
    if(image(s.r,s.c+1) == WHITE && explored[s.r][s.c+1] != 1){
      State f = {s.r,s.c+1};
      frontier.enqueue(f);
      explored[s.r][s.c+1] == 1;
    }
    if(image(s.r,s.c-1) == WHITE && explored[s.r][s.c-1] != 1){
      State f = {s.r,s.c-1};
      frontier.enqueue(f);
      explored[s.r][s.c-1] == 1;
    }
  }
  return EXIT_FAILURE;
}


//2 data structures

// empty queue is failure

//create q
//set red point to poiunt
//check to see if at end
//check left, right, up, down

//have matrix that can set and check??