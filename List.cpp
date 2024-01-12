#include <iostream>
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
    List() : head(nullptr) {}

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
            createMovie(movieNode);
        }
        fileInput.close();
        return 1;
    }
    void sort_Alphabetical() {} // TODO:
    void sort_Rating() {}       // TODO:
    void sort_Length()          // TODO:
    {
    }
    void sort_ReleaseYear()
    {
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

        updateTextFile();
    }
    void createMovie(Node *_movie)
    {
        if (head == nullptr)
        {
            head = _movie;
        }
        else
        {
            Node *current = head;
            while (head->next)
            {
                current = current->next;
            }
            current->next = _movie;
        }
        updateTextFile();
    }
    void readMovie(string _movieTitle)
    {

        Node *current = head;
        bool found = false;

        while (current != nullptr)
        {
            if (current->getTitle() == _movieTitle)
            {
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

    } // This function returns a movie node
    int updateMovie(string _movieTitle)
    {
        Node *current = head;
        bool found = false;

        while (current != nullptr)
        {
            if (current->getTitle() == _movieTitle)
            {
                cout << "Current details:" << endl;
                cout << "Title: " << current->getTitle() << endl;
                cout << "Length: " << current->getLength() << " minutes" << endl;
                cout << "Release Year: " << current->getReleaseYear() << endl;
                cout << "Genre: " << current->getGenre() << endl;
                cout << "Rating: " << current->getRating() << endl;

                cout << "Enter new details:" << endl;
                cout << "Title: ";
                getline(cin, _movieTitle);
                current->setTitle(_movieTitle);

                int _movieLengthMinutes;
                cout << "Length (in minutes): ";
                cin >> _movieLengthMinutes;
                current->setLength(_movieLengthMinutes);

                int _movieReleaseYear;
                cout << "Release Year: ";
                cin >> _movieReleaseYear;
                current->setReleaseYear(_movieReleaseYear);

                cin.ignore();
                string _movieGenre;
                cout << "Genre: ";
                getline(cin, _movieGenre);
                current->setGenre(_movieGenre);

                float _movieRating;
                cout << "Rating: ";
                cin >> _movieRating;
                current->setRating(_movieRating);

                cout << "Movie updated successfully!" << endl;
                updateTextFile();
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "Movie not found!" << endl;
            return -1;
        }

        return 1;
    }
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
            updateTextFile();
            return 1; // Successfully Deleted
        }
        return -1; // Unsuccessful deletion
    }
    void readAllMovies()
    {
        Node *current = head;
        while (current)
        {
            cout << "Title:" << current->getTitle() << endl;
            cout << "Length: " << current->getLength() << endl;
            cout << "Release Year: " << current->getReleaseYear() << endl;
            cout << "Genre: " << current->getGenre() << endl;
            cout << "Rating: " << current->getRating() << "/10" << endl;
            current = current->next;
        }
    }
    void updateTextFile()
    {
        fstream outFile("movieDatabase.txt, ios::out");
        Node *current = head;
        while (current)
        {
            outFile << current->getTitle() << endl;
            outFile << current->getLength() << endl;
            outFile << current->getReleaseYear() << endl;
            outFile << current->getGenre() << endl;
            outFile << current->getRating() << endl;
            current = current->next;
        }
        outFile.close();
    }

    ~List()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
