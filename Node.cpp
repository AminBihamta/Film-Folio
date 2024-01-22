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
    int movieRating;

public:
    Node *next;

    Node() : next(nullptr) {}

    Node(string _movieTitle, int _movieLengthMinutes, int _movieReleaseYear, string _movieGenre, int _movieRating)
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
    void setRating(int _rating) { movieRating = _rating; }

    string getTitle() const { return movieTitle; }
    int getLength() const { return movieLengthMinutes; }
    int getReleaseYear() const { return movieReleaseYear; }
    string getGenre() const { return movieGenre; }
    int getRating() const { return movieRating; }
};

void swapNodes(Node *node1, Node *node2)
{
    // Swap movieTitle
    string tempTitle = node1->getTitle();
    node1->setTitle(node2->getTitle());
    node2->setTitle(tempTitle);

    // Swap movieLengthMinutes
    int tempLength = node1->getLength();
    node1->setLength(node2->getLength());
    node2->setLength(tempLength);

    // Swap movieReleaseYear
    int tempReleaseYear = node1->getReleaseYear();
    node1->setReleaseYear(node2->getReleaseYear());
    node2->setReleaseYear(tempReleaseYear);

    // Swap movieGenre
    string tempGenre = node1->getGenre();
    node1->setGenre(node2->getGenre());
    node2->setGenre(tempGenre);

    // Swap movieRating
    int tempRating = node1->getRating();
    node1->setRating(node2->getRating());
    node2->setRating(tempRating);
}