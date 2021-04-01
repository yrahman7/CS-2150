//Yumna Rahman, yr6by
//November 14, 2020

#ifndef MIDDLEEARTH_H
/** @def MIDDLEEARTH_H
 * If not previously defined, defines the header file for middle earth.
 */ 
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

/** @headerfile middleearth.h "middleearth.h"
 *
 */

class MiddleEarth {
/** @publicsection
 *
 */
public:
  /** @fn MiddleEarth(int xsize, int ysize, int num_cities, int seed)
   * @brief MiddleEarth constructor
   * @param xsize: width
   * @param ysize: height
   * @param num_cities: the number of cities
   * @param seed: a random seed
   */
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);

  /** @fn print()
   */
    void print();

  /** @fn printTable()
   */
    void printTable();

  /** @fn getDistance(string city1, string city2)
   * @param city1: starting city
   * @param city2: ending city
   */
    float getDistance(const string& city1, const string& city2);

  /** @fn getItinerary(unsigned int length)
   * @param length
   */
    vector<string> getItinerary(unsigned int length);
  
/** @privatesection
 *
 */
private:
  /** @var int num_city_names
   * @var int xsize
   * @var int ysize
   * @brief number of cities, width size, and height size
   */
    int num_city_names, xsize, ysize;

  /** @var unordered_map<string, float> xpos
   * @var unordered_map<string, float> ypos
   * @brief positions of x and y
   */
    unordered_map<string, float> xpos, ypos;

  /** @var vector<string> cities
   */
    vector<string> cities;

  /** @var unordered_map<string, unordered_map<string, float>> distances
   * @brief indices map
   */
    unordered_map<string, unordered_map<string, float>> distances;

    mt19937 gen; // Mersenne-Twister random number engine
};

#endif
