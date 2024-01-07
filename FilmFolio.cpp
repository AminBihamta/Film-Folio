#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Node.cpp"
#include "List.cpp"

using namespace std;

// List Definition

// Determine User Type
bool takeLogin()
{
    cout << "Are you a user or an administrator?" << endl;
    cout << "1. User" << endl;
    cout << "2. Administrator" << endl
         << endl;

    cout << "Your answer: ";

    int answer;
L1:
    cin >> answer;

    // Input Validation
    if (answer != 1 && answer != 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid answer: ";
        goto L1;
    }
    return answer - 1;
}

void printLogo()
{
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
    movieList.readTextFile();

    bool isAdmin = takeLogin(); // User Type

    if (isAdmin)
        goto ADMIN;

    return 0;

ADMIN:
    cout << "Choose what you'd like to do!" << endl;
    cout << endl;
    cout << "1. Add Movie" << endl;
    cout << "2. Update Movie" << endl;
    cout << "3. Delete Movie" << endl;
    cout << endl;
    cout << "Your answer: " << endl;
    char choice;
    cin >> choice;
    cin.clear();
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
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
    //
}