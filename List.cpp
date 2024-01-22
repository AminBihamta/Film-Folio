#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Node.cpp"
using namespace std;

// Helper function to swap entire nodes
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
        int _movieRating;
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
            _movieRating = stoi(tempInput);

            Node *movieNode = new Node(_movieTitle, _movieLengthMinuets, _movieReleaseYear, _movieGenre, _movieRating);
            if (head == nullptr)
            {
                head = movieNode;
            }
            else
            {
                Node *current = head;
                while (current->next)
                {
                    current = current->next;
                }
                current->next = movieNode;
            }
        }
        fileInput.close();
        return 1;
    }
    void sort_Alphabetical()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return; // Already sorted or empty list
        }

        Node *current = head;

        while (current != nullptr)
        {
            Node *minTitle = current;
            Node *temp = current->next;

            while (temp != nullptr)
            {
                // Compare title strings to find the minimum
                if (temp->getTitle() < minTitle->getTitle())
                {
                    minTitle = temp;
                }
                temp = temp->next;
            }

            // Swap entire nodes using the swapNodes function
            swapNodes(current, minTitle);

            current = current->next;
        }
    }

    void sort_Rating()
    {
        Node *current = head;
        Node *index = nullptr;

        if (!head || !head->next)
        {
            return; // Already sorted or empty list
        }

        // Bubble sort algorithm for sorting based on rating in descending order
        while (current != nullptr)
        {
            index = current->next;

            while (index != nullptr)
            {
                // Compare ratings and swap entire nodes if needed
                if (current->getRating() < index->getRating())
                {
                    // Swap entire nodes
                    swapNodes(current, index);
                }

                index = index->next;
            }

            current = current->next;
        }
    }
    void sort_Length()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return; // Already sorted or empty list
        }

        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;

            while (next != nullptr)
            {
                // Compare and swap based on movie length
                if (current->getLength() > next->getLength())
                {
                    // Swap entire nodes using the swapNodes function
                    swapNodes(current, next);
                }
                next = next->next;
            }

            current = current->next;
        }
    }

    void sort_ReleaseYear()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return; // Already sorted or empty list
        }

        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;

            while (next != nullptr)
            {
                // Compare and swap based on release year
                if (current->getReleaseYear() < next->getReleaseYear())
                {
                    // Swap entire nodes using the swapNodes function
                    swapNodes(current, next);
                }
                next = next->next;
            }

            current = current->next;
        }
    }

    void sort_Genre()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return; // Already sorted or empty list
        }

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

            // Swap entire nodes using the swapNodes function
            swapNodes(current, minGenre);

            current = current->next;
        }
    }

    int createMovie(Node *_movie)
    {
        if (head == nullptr)
        {
            head = _movie;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = _movie;
        }
        updateTextFile();
        return 1;
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

        if (current == nullptr)
            return -1;

        while (current->getTitle() != _movieTitle && current->next != nullptr)
        {
            current = current->next;
        }
        if (current->getTitle() != _movieTitle)
            return 0;

        cout << "What would you like to update? " << endl
             << endl;

        cout << "1. Title" << endl;
        cout << "2. Length" << endl;
        cout << "3. Release Year" << endl;
        cout << "4. Genre" << endl;
        cout << "5. Rating" << endl;

        cout << endl;
        cout << "Your answer: ";

        int answer;
    L1:
        cin >> answer;

        // Input Validation
        if (!(answer >= 1 && answer <= 5))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid answer: ";
            goto L1;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the updated value: ";
        string input;
        getline(cin, input);

        switch (answer)
        {
        case 1:
            current->setTitle(input);
            break;
        case 2:
            current->setLength(stoi(input));
            break;
        case 3:
            current->setReleaseYear(stoi(input));
            break;
        case 4:
            current->setGenre(input);
            break;
        case 5:
            current->setRating(stoi(input));
            break;
        }
        updateTextFile();
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

        if (current->next == nullptr)
        {
            readMovie(current->getTitle());
        }
        while (current)
        {
            readMovie(current->getTitle());
            current = current->next;
            cout << endl;
        }
    }
    void updateTextFile()
    {
        fstream outFile("movieDatabase.txt", ios::out);
        Node *current = head;
        while (current)
        {
            outFile << current->getTitle() << endl;
            outFile << current->getLength() << endl;
            outFile << current->getReleaseYear() << endl;
            outFile << current->getGenre() << endl;
            outFile << current->getRating();

            if (current->next)
                outFile << endl;
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
