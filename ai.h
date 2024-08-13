/*
 * Designed by Paulo Luz, all rights reserved
 *
 * This is an original work and cannot be redistributed
 * without my explicit authorization
 *
 *
 *
 *
 * Implementation of a k Nearest Neighboor (kNN) algorithm
 * to simulate an AI that learns and plays Tic Tac Toe
*/


#ifndef AI_H
#define AI_H

#include <vector>

class AI
{
public:
    AI(const std::vector< std::vector<int> > &);                 //A data base must be given at initialization
    int getNextMove(const std::vector<int>, int);                /*returns the next move given the current state
                                                                   and the current player*/

private:
    void setDataBase(const std::vector< std::vector<int> > &);   /*Gets the data base from an external source and
                                                                   copies it by ref to this->dataBase to avoid
                                                                   double memory usage*/
    const std::vector< std::vector<int> > *dataBase;
    static const int MAX_KNN=9;                                  //Evaluates the next move using at most 4 NN
    float getNNScore(const std::vector<int>, int);
    bool isStatePossible(std::vector<int>, std::vector<int>);    /*returns true if first state is possible from
                                                                   the second (actual) */
    int getDistance(std::vector<int>, std::vector<int>);         /*Returns distance (#of different positions) between
                                                                   two states*/

    void sortKNNVector(std::vector< std::vector<int> >&);        /*Sorts the vector with the kNN from closest to
                                                                   farthest distance*/

};

#endif // AI_H
