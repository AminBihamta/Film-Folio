#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Node
{
private:
    string movieTitle;
    int movieLengthMinuets;
    int movieReleaseYear;
    string movieGenre;
    float movieRating;

public:
    Node *next;

    Node(){}; // TODO:

    Node(string _movieTitle, int _movieLengthMinuets, int _movieReleaseYear, string _movieGenre, float _movieRating)
    {
        movieTitle = _movieTitle;
        movieLengthMinuets = _movieLengthMinuets;
        movieReleaseYear = _movieReleaseYear;
        movieGenre = _movieGenre;
        movieRating = _movieRating;
        next = nullptr;
    }
    void setTitle(string _title) { movieTitle = _title; }
    void setLength(int _length) { movieLengthMinuets = _length; }
    void setReleaseYear(int _releaseYear) { movieReleaseYear = _releaseYear; }
    void setGenre(string _genre) { movieGenre = _genre; }
    void setRating(float _rating) { movieRating = _rating; }

    string getTitle() const { return movieTitle; }
    int getLength() const { return movieLengthMinuets; }
    int getReleaseYear() const { return movieReleaseYear; }
    string getGenre() const { return movieGenre; }
    int getRating() const { return movieRating; }
};