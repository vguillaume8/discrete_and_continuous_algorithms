#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> movie_lengths {
  5,
  8,
  10,
  7,
  9,
  12
};

//------------------------------------------------------------------------------

/**
 * @brief We take advantage of the fact that a set has constant lookup
 * time. We essentially iterate through each movie length and calculate
 * a second_movie time that would satisfy our exit condition
 * (flight_legnth - first_movie = second_movie). We search our list of movies_seen
 * to see if a second_movie is in there that satisfies our condition. If so, we exit,
 * otherwise we add the first_movie to the set, and proceed to the next movie.
 * O(n) time, and O(n)O(n) space. Note while optimizing runtime we added a bit of space cost.
 * @param movie_lengths list of all the movie lengths
 * @param flight_length Length of the flight
 * @return
 */
bool can_watch(std::vector<int>& movies, int flight_length) {
  std::unordered_set<int> movies_seen;
  int second_movie;

  // For each movie in the set
  for (int first_movie : movies) {

    // Find movie length with appropriate remaining runtime
    second_movie = flight_length - first_movie;

    // If there is a second movie time in the set, return true
    if (movies_seen.find(second_movie) != movies_seen.end()) {
      return true;
    }

    // Insert the appropriate time into the set
    movies_seen.insert(first_movie);
  }

  return false;
}

//------------------------------------------------------------------------------

/**
 * @brief Brute force solution, Builds a matrix (dont have to store it) by attempting each
 * combination breaking at the first one that satisfies the exit condition
 * @param movie_lengths list of all the movie lengths
 * @param flight_length Length of the flight
 * @return
 */
bool can_watch_brute_force(std::vector<int>& movie_lengths, int flight_length) {
  int length = movie_lengths.size();

  for (int i = 0; movie_lengths[i]; i++) {
    for (int j = 0; movie_lengths[j]; j++) {

      if (movie_lengths[i] + movie_lengths[j] == flight_length) {
        return true;
      }
    }
  }

  return false;
}

//------------------------------------------------------------------------------

int main() {
  int flight_length = 21;

  std::cout << can_watch_brute_force(movie_lengths, flight_length) << std::endl;


  return 0;
}
