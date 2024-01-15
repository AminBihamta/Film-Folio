#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "List.cpp"

using namespace std;

string clearCommand;

string convertToPascalCase(string input)
{
    string pascalCaseString;

    bool capitalizeNext = true;

    for (char c : input)
    {
        if (std::isalpha(c))
        {
            if (capitalizeNext)
            {
                pascalCaseString += std::toupper(c);
                capitalizeNext = false;
            }
            else
            {
                pascalCaseString += std::tolower(c);
            }
        }
        else if (c == ' ')
        {
            pascalCaseString += ' ';
            capitalizeNext = true;
        }
        else
        {
            pascalCaseString += c;
        }
    }

    return pascalCaseString;
}

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

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
    system(clearCommand.c_str());
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

#if defined(__linux__)
    clearCommand = "clear";
#elif _WIN32
    clearCommand = "cls"
#endif

    // cout << "Choose your operating system" << endl;
    // cout << "1. Windows" << endl;
    // cout << "2. Linux" << endl;
    // if (takeListInput(2) == 1)
    //{
    //     clearCommand = "cls";
    // }
    // else
    //{
    //     clearCommand = "clear";
    // }

    List movieList;
    movieList.readTextFile();

START:

    printLogo();
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
            cout << "Alphabetically sorted list!" << endl
                 << endl;
            movieList.sort_Alphabetical();
            movieList.readAllMovies();
            break;
        case 2:
            printLogo();
            cout << "Listed sorted based on rating!" << endl
                 << endl;
            movieList.sort_Rating();
            movieList.readAllMovies();
            break;
        case 3:
            printLogo();
            cout << "Listed sorted based on length!" << endl
                 << endl;
            movieList.sort_Length();
            movieList.readAllMovies();
            break;
        case 4:
            printLogo();
            cout << "Listed sorted based on release year!" << endl
                 << endl;
            movieList.sort_ReleaseYear();
            movieList.readAllMovies();
            break;
        default:
            printLogo();
            cout << "Listed sorted based on genre!" << endl
                 << endl;
            movieList.sort_Genre();
            movieList.readAllMovies();
        }
    }
    else
    {
        printLogo();

        cout << endl;
        clearInput();
        cout << "Enter movie title: ";
        string input;
        getline(cin, input);
        cout << endl;
        movieList.readMovie(convertToPascalCase(input));
    }
    goto END;

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
        int _movieRating;
        string input;
        clearInput();

        cout << "Enter movie title: ";
        getline(cin, input);
        _movieTitle = convertToPascalCase(input);

        cout << "Enter movie length: ";
    LENGTH:
        cin >> input;
        if (!isdigit(input[0]))
        {
            cout << "Invalid input! Please enter a number: ";
            goto LENGTH;
        }
        _movieLengthMinuets = stoi(input);

        cout << "Enter movie release year: ";
    RELEASEYEAR:
        cin >> input;
        if (!isdigit(input[0]))
        {
            cout << "Invalid input! Please enter a number: ";
            goto RELEASEYEAR;
        }
        _movieReleaseYear = stoi(input);

        clearInput();
        cout << "Enter movie genre: ";
        getline(cin, input);
        _movieGenre = convertToPascalCase(input);

        cout << "Enter movie rating: ";
    RATING:
        cin >> input;
        if (!isdigit(input[0]))
        {
            cout << "Invalid input! Please enter a number: ";
            goto RATING;
        }
        _movieRating = stoi(input);

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
        clearInput();
        cout << "Enter movie title: ";
        getline(cin, _movieTitle);
        cout << endl;

        int wasSuccessful = movieList.updateMovie(convertToPascalCase(_movieTitle));

        if (wasSuccessful == -1)
        {
            cout << "Updating movie was unsuccessful" << endl;
        }
        else if (wasSuccessful == 0)
        {
            cout << "Movie not found!" << endl;
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
        clearInput();
        getline(cin, _movieTitle);

        if (movieList.deleteMovie(convertToPascalCase(_movieTitle)) == -1)
        {
            cout << "Deleting movie was unsuccessful" << endl;
        }
        else
        {
            cout << "Movie successfully deleted" << endl;
        }
        break;
    }

END:
    cout << endl;
    cout << "Would you like to exit the program?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    if (takeListInput(2) == 2)
        goto START;
    return 0;
}