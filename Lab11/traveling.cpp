/** @author Yumna Rahman
 * @date November 17, 2020
 * @brief file: traveling.cpp implements a brute-force solution to the traveling salesperson problem.
 * @details Inlab 11
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

/** @fn computeDistance(MiddleEarth &me, string start, vector<string> dests)
 * @brief calculates the distance between all the cities from the starting point
 * @param me: Middle Earth object
 * @param start: city that is the starting point
 * @param dests: all the cities that must be visited
 * @return float total distance to travel to all of the cities
 */
// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
  vector<string>::iterator visit = dests.begin();
  float fullDistance = me.getDistance(start, *visit);
  
  for (visit = dests.begin(); visit != dests.end(); visit++) {
    vector<string>::iterator visit2 = visit + 1;
    string visit2city;
    if (visit2 != dests.end()) {
      visit2city = *visit2;
    }
    else {
      visit2city = start;
    }
    fullDistance += me.getDistance(*visit, visit2city);
  }
  //add distance from the last city visited to start city
  return fullDistance;
}

/** @fn printRoute(const string& start, const vector<string>& dests)
 * @brief prints the route
 * @param start: city that is the starting point
 * @param dests: all the cities that must be visited
 */
// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
  for (int i = 0; i < dests.size(); i++) {
    cout << dests[i] << " -> ";
  }
  cout << start;
}

/** @brief main function that incorporates TSP implementation
 * @details 5 command-line parameter inputs
 * @param argc: a.out
 * @param argv: vector of command line arguments
 * @return returns 0 when done
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    //Find shortest distance
    string start = dests[0];
    vector<string> last = dests;
    float smallestDist = computeDistance(me, start, dests);
    float dist = 0.0;
    vector<string>::iterator begin = dests.begin() + 1;
    vector<string>::iterator end = dests.end();

    sort(begin, end);
    //Find combination of shortest distances
    while (next_permutation(begin, end)) {
      dist = computeDistance(me, start, dests);
      if (dist < smallestDist) {
	smallestDist = dist;
	last = dests;
      }
    }

    cout << "Minimum path has distance " << smallestDist << ": ";
    printRoute(start, last);
    cout << endl;
   
    return 0;
}
