# GeneticAlgorithm
This is a Genetic algorithm to solve a coloring problem map, in this case used to solve the four coloring map for the political map of the South-Eastern states of the US.

First we initialize a population of a given size. Each population is consists of individuals with a genom tha gives a solution. A fitness function determines how good the genon of each individual is. We randomly select from the list of genoms (that have different probabilities of being selected by their fitness value) the two parents that we are going to cross. we randomly slect a point to cress-validate them and apply a probability to mutate. Finally, iterating over this procedure a decided number of times, we would obtain an individual with the wanted fitness function. That individual would give us the solution, so the combination of colors that each state should have, in order to solve the four coloring problem. 

This code works for any given map, which is initialized in main, and must include each state, and all the boarders, which are the constraints.The number of colors allowed are given in the random generator of a color for the genom.

main.cpp - initialized the map and performs the genetic algorithm
Map.cpp - includes the border class and the map class
Population.cpp - a population of individuals 
Individual.cpp - each individual
