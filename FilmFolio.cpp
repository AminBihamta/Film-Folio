#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "List.cpp"

using namespace std;

// List Definition

// Determine User Type
int takeListInput(int max)
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
}

int main() // TODO:
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
            movieList.sort_Alphabetical();
            break;
        case 2:
            movieList.sort_Rating();
            break;
        case 3:
            movieList.sort_Length();
            break;
        case 4:
            movieList.sort_ReleaseYear();
            break;
        default:
            movieList.sort_Genre();
        }
    }
    else
    {
        cout << endl;
        cout << "Enter movie title: ";
        string input;
        getline(cin, input);
        cout << endl;
        movieList.readMovie(input);
    }

ADMIN:
    printLogo();
    cout << "Choose what you'd like to do!" << endl;
    cout << endl;
    cout << "1. Add Movie" << endl;
    cout << "2. Update Movie" << endl;
    cout << "3. Delete Movie" << endl;
    cout << endl;
    cout << "Your answer: " << endl;

    switch (takeListInput(3))
    {
    case 1:
    {
        system("cls");

        string _movieTitle;
        int _movieLengthMinuets;
        int _movieReleaseYear;
        string _movieGenre;
        float _movieRating;
        cout << "Enter movie title: ";
        getline(cin, _movieTitle);

        cout << "Enter movie length: ";
        cin >> _movieLengthMinuets;

        cout << "Enter movie release year: ";
        cin >> _movieReleaseYear;

        cout << "Enter movie rating: ";
        cin >> _movieRating;

        Node *movieNode = new Node(_movieTitle, _movieLengthMinuets, _movieReleaseYear, _movieGenre, _movieRating);
        movieList.addMovie(movieNode);
        break;
    }
    case 2:
    {
        string _movieTitle;
        int choice;

        cout << "Enter movie title: ";
        getline(cin, _movieTitle);

        movieList.updateMovie(_movieTitle);
        break;
    }
    case 3:
        string _movieTitle;
        int choice;

        cout << "Enter movie title: ";
        getline(cin, _movieTitle);

        movieList.deleteMovie(_movieTitle);
        break;
    }

    return 0;
}