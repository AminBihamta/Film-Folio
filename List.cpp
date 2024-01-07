#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Node.cpp"
using namespace std;

class List
{
private:
    Node *head;

public:
    List() {}
    int readTextFile()
    {
        fstream fileInput("movieDatabase.txt", ios::in);

        string _movieTitle;
        int _movieLengthMinuets;
        int _movieReleaseYear;
        string _movieGenre;
        float _movieRating;
        string tempInput;

        while (!fileInput.eof())
        {
            getline(fileInput, _movieTitle);
            getline(fileInput, tempInput);
            _movieLengthMinuets = stoi(tempInput);
            getline(fileInput, tempInput);
            _movieReleaseYear = stoi(tempInput);
            getline(fileInput, _movieGenre);
            getline(fileInput, tempInput);
            _movieRating = stof(tempInput);

            Node *movieNode = new Node(_movieTitle, _movieLengthMinuets, _movieReleaseYear, _movieGenre, _movieRating);
            addMovie(movieNode);
        }
    }
    void sort_Alphabetical()
    {
        if (head == nullptr)
        {
            // Handle empty list case
            return;
        }

        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            while (next != nullptr)
            {
                if (current->movieTitle > next->movieTitle)
                {
                    // Swap movie data
                    swap(current->movieTitle, next->movieTitle);
                    swap(current->movieLengthMinuets, next->movieLengthMinuets);
                    swap(current->movieReleaseYear, next->movieReleaseYear);
                    swap(current->movieGenre, next->movieGenre);
                    swap(current->movieRating, next->movieRating);
                }
                next = next->next;
            }
            current = current->next;
        }
    }
    void sort_Rating() {}
    void sort_Length()
    {
        // Implement sorting based on movieLengthMinuets in ascending order
        if (head == nullptr)
        {
            return;
        }

        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            while (next != nullptr)
            {
                if (current->movieLengthMinuets > next->movieLengthMinuets)
                {
                    swap(current->movieTitle, next->movieTitle);
                    swap(current->movieLengthMinuets, next->movieLengthMinuets);
                    swap(current->movieReleaseYear, next->movieReleaseYear);
                    swap(current->movieGenre, next->movieGenre);
                    swap(current->movieRating, next->movieRating);
                }
                next = next->next;
            }
            current = current->next;
        }
    }
    void sort_ReleaseYear()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            while (next != nullptr)
            {
                if (current->movieReleaseYear > next->movieReleaseYear)
                {
                    swap(current->movieTitle, next->movieTitle);
                    swap(current->movieLengthMinuets, next->movieLengthMinuets);
                    swap(current->movieReleaseYear, next->movieReleaseYear);
                    swap(current->movieGenre, next->movieGenre);
                    swap(current->movieRating, next->movieRating);
                }
                next = next->next;
            }
            current = current->next;
        }
    }
    void sort_Genre()
    {
        Node *current = head;

        while (current != nullptr)
        {
            Node *minGenre = current;
            Node *temp = current->next;

            while (temp != nullptr)
            {
                // Compare genre strings to find the minimum
                if (temp->getGenre() < minGenre->getGenre())
                {
                    minGenre = temp;
                }
                temp = temp->next;
            }

            // Swap only the genre information, not entire nodes
            string tempGenre = current->getGenre();
            current->setGenre(minGenre->getGenre());
            minGenre->setGenre(tempGenre);

            current = current->next;
        }
    }
    void addMovie(Node *_movie) {}
    Node readMovie(string _movieTitle)
    {

        Node *current = head;
        bool found = false;

        while (current != nullptr)
        {
            if (current->getTitle() == _movieTitle)
            {
                cout << "Movie found:" << endl;
                cout << "Title: " << current->getTitle() << endl;
                cout << "Length: " << current->getLength() << " minutes" << endl;
                cout << "Release Year: " << current->getReleaseYear() << endl;
                cout << "Genre: " << current->getGenre() << endl;
                cout << "Rating: " << current->getRating() << endl;
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "Movie not found!" << endl;
        }

    }                                     // This function returns a movie node
    int updateMovie(string _movieName) {} // This function returns -1 if update was unsuccessful
    int deleteMovie(string _movieTitle)
    {

        Node *current = head;
        Node *previous = nullptr;

        while (current && current->getTitle() != _movieTitle)
        {
            previous = current;
            current = current->next;
        }

        if (current)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
            return 1; // Successfully Deleted
        }
        return -1;

    } // Should return -1 if deletion is unsuccessful
    void readAllMovies() {}
    void updateTextFile() {} // TODO:
    ~List() {}               // TODO:
};
