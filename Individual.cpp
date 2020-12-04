#include "Individual.h"
#include <string>

using namespace std;

Individual::Individual(const Map& map) : map(&map)
{
 
  int size=map.states.size();
  genom.resize(size);
  for(int i=0; i<size; i++){
    genom.at(i)=rand()%4;
  }
  updateFitness();
}

Individual Individual::reproduce(const Individual& x, const Individual& y)
{
  Individual child(*x.map);
  const int size=child.map->states.size();
  child.genom.resize(size);
  const int crossover = rand() % size;
  for(int i=0; i<size;i++){
    if(i<crossover){
      child.genom.at(i)=x.genom.at(i);
    }
    else{
       child.genom.at(i)=y.genom.at(i);
    }
  }
  child.updateFitness();
  return child;
}

bool Individual::isGoal() const
{
  if(fitness == map->borders.size()){
    return true;
  }
  return false;
}

int Individual::getFitness() const
{
  int fitness=0;
  int size= map->borders.size();
  for(int i=0; i<size; i++){
    int x=genom.at(map->borders.at(i).index1);
    int y=genom.at(map->borders.at(i).index2);
    if(x!=y){
      fitness++;
    }
  }
  return fitness;
}

void Individual::updateFitness()
{
  fitness=getFitness(); 
}

void Individual::mutate()
{
  const int size = map->states.size();
  const int position = rand() %size;
  genom[position]=rand()%4;
  updateFitness();
}

void Individual::print() const
{
  printf("Individual with genom: ");
  for(int i=0; i<genom.size(); i++){
      printf("%d", genom.at(i));
    }
  printf("\nFitness value: %d\n", fitness);
  const char* state=" ";
  for(int i=0; i<genom.size(); i++){
    state=map->states.at(i);
    printf("%s ->", state);
    switch (genom.at(i)){
    case 0:
      printf(" Black\n");
      break;
    case 1:
      printf(" Blue\n");
      break;
    case 2:
      printf(" Red\n");
      break;
    case 3:
      printf(" Green\n");
      break;
    default:
      break;
    }
  }
}