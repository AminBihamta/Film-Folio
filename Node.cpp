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
    int movieLengthMinutes;
    int movieReleaseYear;
    string movieGenre;
    float movieRating;

public:
    Node *next;

    Node() : next(nullptr) {}

    Node(string _movieTitle, int _movieLengthMinutes, int _movieReleaseYear, string _movieGenre, float _movieRating)
    {
        movieTitle = _movieTitle;
        movieLengthMinutes = _movieLengthMinutes;
        movieReleaseYear = _movieReleaseYear;
        movieGenre = _movieGenre;
        movieRating = _movieRating;
        next = nullptr;
    }
    void setTitle(string _title) { movieTitle = _title; }
    void setLength(int _length) { movieLengthMinutes = _length; }
    void setReleaseYear(int _releaseYear) { movieReleaseYear = _releaseYear; }
    void setGenre(string _genre) { movieGenre = _genre; }
    void setRating(float _rating) { movieRating = _rating; }

    string getTitle() const { return movieTitle; }
    int getLength() const { return movieLengthMinutes; }
    int getReleaseYear() const { return movieReleaseYear; }
    string getGenre() const { return movieGenre; }
    int getRating() const { return movieRating; }
};