#pragma once

#include "Map.h"

/**
 * This class represents a single individual in the US States environment
 */
class Individual
{
private:
  const Map* map; // a pointer to the map
  int fitness; // fitness is cached and only updated on request whenever necessary
  std::vector<int> genom;
  /**
   * Updates the fitness value based on the genom and the map.
   */
  void updateFitness();

public:
  /**
   * Default ctor. Creates a (valid) random individual.
   * @param map The US states map.
   */
  Individual(const Map& map);

  /**
   * Reproduces a child randomly from two individuals (see textbook).
   * @param x The first parent.
   * @param y The second parent.
   * @return The child created from the two individuals.
   */
  static Individual reproduce(const Individual& x, const Individual& y);

  /**
   * Returns the current fitness value of the individual.
   * @return The current fitness value.
   */
  int getFitness() const;

  /**
   * Randomly mutates the individual.
   */
  void mutate();

  /**
   * Checks whether the individual represents a valid goal state.
   * @return Whether the individual represents a valid goal state.
   */
  bool isGoal() const;

  /**
   * Prints out the individual to the console.
   */
  void print() const;
};