#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "List.cpp"

using namespace std;

int takeListInput(int max) // Determine user type
{
    cout << endl;
    cout << "Your answer: ";

    int answer;
L1:
    cin >> answer;

    // Input Validation
    if (!(answer >= 1 && answer <= max))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid answer: ";
        goto L1;
    }
    return answer;
}

void printLogo()
{
    system("cls");
    std::cout << "      ::::::::::       :::::::::::       :::          :::   :::        ::::::::::       ::::::::       :::        :::::::::::       ::::::::\n"
                 "     :+:                  :+:           :+:         :+:+: :+:+:       :+:             :+:    :+:      :+:            :+:          :+:    :+: \n"
                 "    +:+                  +:+           +:+        +:+ +:+:+ +:+      +:+             +:+    +:+      +:+            +:+          +:+    +:+  \n"
                 "   :#::+::#             +#+           +#+        +#+  +:+  +#+      :#::+::#        +#+    +:+      +#+            +#+          +#+    +:+   \n"
                 "  +#+                  +#+           +#+        +#+       +#+      +#+             +#+    +#+      +#+            +#+          +#+    +#+    \n"
                 " #+#                  #+#           #+#        #+#       #+#      #+#             #+#    #+#      #+#            #+#          #+#    #+#     \n"
                 "###              ###########       ########## ###       ###      ###              ########       ########## ###########       ########      \n";
    cout << endl;
}

int main()
{
    List movieList;
    printLogo();
    movieList.readTextFile();
    cout << endl;
    cout << "Are you a user or an administrator?" << endl;
    cout << "1. User" << endl;
    cout << "2. Administrator" << endl;

    if (takeListInput(2) == 2)
        goto ADMIN;

    printLogo();

    cout << "What would you like to do?" << endl;
    cout << endl;

    cout << "1. View all movies" << endl;
    cout << "2. Search for a specific movie" << endl;

    if (takeListInput(2) == 1)
    {
        printLogo();

        cout << "How would you like to view the list of movies?" << endl;
        cout << endl;

        cout << "1. Alphabetical sort" << endl;
        cout << "2. Sort based on rating" << endl;
        cout << "3. Sort based on length" << endl;
        cout << "4. Sort based on year released" << endl;
        cout << "5. Sort based on genre" << endl;

        switch (takeListInput(5))
        {
        case 1:
            printLogo();
            movieList.readAllMovies();
            break;
        case 2:
            printLogo();

            movieList.sort_Rating();
            break;
        case 3:
            printLogo();

            movieList.sort_Length();
            break;
        case 4:
            printLogo();

            movieList.sort_ReleaseYear();
            break;
        default:
            printLogo();

            movieList.sort_Genre();
        }
    }
    else
    {
        printLogo();

        cout << endl;
        cout << "Enter movie title: ";
        string input;
        getline(cin, input);
        cout << endl;
        movieList.readMovie(input);
    }
    return 0;

ADMIN:
    printLogo();
    cout << "Choose what you'd like to do!" << endl;
    cout << endl;
    cout << "1. Add Movie" << endl;
    cout << "2. Update Movie" << endl;
    cout << "3. Delete Movie" << endl;
    switch (takeListInput(3))
    {
    case 1:
    {
        printLogo();

        string _movieTitle;
        int _movieLengthMinuets;
        int _movieReleaseYear;
        string _movieGenre;
        float _movieRating;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter movie title: ";

        getline(cin, _movieTitle);

        cout << "Enter movie length: ";

        cin >> _movieLengthMinuets;

        cout << "Enter movie release year: ";

        cin >> _movieReleaseYear;

        cout << "Enter movie genre: " << endl;
        cin >> _movieGenre;

        cout << "Enter movie rating: ";

        cin >> _movieRating;

        Node *movieNode = new Node(_movieTitle, _movieLengthMinuets, _movieReleaseYear, _movieGenre, _movieRating);
        if (movieList.createMovie(movieNode))
            cout << "Movie added successfully" << endl;
        break;
    }
    case 2:
    {
        printLogo();
        string _movieTitle;
        int choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter movie title: ";
        getline(cin, _movieTitle);

        if (movieList.updateMovie(_movieTitle) == -1)
        {
            cout << "Updating movie was unsuccessful" << endl;
        }
        else
        {
            cout << "Movie successfully updated" << endl;
        }
        break;
    }
    case 3:
        printLogo();

        string _movieTitle;
        int choice;

        cout << "Enter movie title: ";
        getline(cin, _movieTitle);

        if (movieList.deleteMovie(_movieTitle) == -1)
        {
            cout << "Deleting movie was unsuccessful" << endl;
        }
        else
        {
            cout << "Movie successfully deleted" << endl;
        }
        break;
    }

    return 0;
}