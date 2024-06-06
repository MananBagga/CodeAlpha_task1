#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

void playBeep(const string& sound)
{
    if (sound == "invalid")
    {
        MessageBeep(MB_ICONHAND); // Error sound
    }
    else if (sound == "success")
    {
        MessageBeep(MB_ICONASTERISK); // Information sound
    }
}

void game(int num, int chances)
{
    system("CLS");
    srand(time(0));
    int num_to_find = 1 + (rand() % num);
    int user_choice;

    for (int i = 1; i <= chances; i++)
    {
        cout << "\033[1;36m\nEnter the number: \033[0m";
        cin >> user_choice;

        while (cin.fail() || user_choice > num)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\033[1;31m\nInvalid input! Please enter a valid integer: \033[0m";
            playBeep("invalid");
            cin >> user_choice;
        }

        if (user_choice > num_to_find)
        {
            cout << "\033[1;31m\nWrong! The secret number is less than the number you entered. Try again!\033[0m" << endl;
            cout << "\033[1;33m" << chances - i << " chances left!\033[0m" << endl;
        }
        else if (user_choice < num_to_find)
        {
            cout << "\033[1;31m\nWrong! The secret number is greater than the number you entered. Try again!\033[0m" << endl;
            cout << "\033[1;33m" << chances - i << " chances left!\033[0m" << endl;
        }
        else
        {
            cout << "\033[1;32m\nWell done!! You've guessed the number right\033[0m" << endl;
            cout << "\033[1;34mDo you want to play again? Enter y : yes and n : no\033[0m" << endl;
            playBeep("success");
            char yn;
        line34:
            cin >> yn;
            if (yn == 'y')
            {
                return;
            }
            else if (yn == 'n')
            {
                cout << "\033[1;32m\nThanks for playing buddy! See you soon\033[0m";
                exit(0);
            }
            else
            {
                cout << "\033[1;31m\nEnter a valid choice! Choice : \033[0m";
                goto line34;
            }
        }
    }

    cout << "\033[1;31m\n\nChances Over buddy! You've lost the game. Better luck next time\033[0m" << endl;
    cout << "\033[1;33m\nThe secret number was " << num_to_find << "\033[0m" << endl;
    cout << "\033[1;34mDo you want to play again? Enter y : yes and n : no\033[0m" << endl;
    char yn;
    cin >> yn;

    if (yn == 'y')
    {
        return;
    }
    else if (yn == 'n')
    {
        cout << "\033[1;32m\nThanks for playing buddy! See you soon\033[0m";
        exit(0);
    }
}

void printWelcomeMessage()
{
    cout << "\033[1;35m\t\t\t\t\t\t\t\t**********************************************************\n";
    cout << "\t\t\t\t\t\t\t\t*                                                        *\n";
    cout << "\t\t\t\t\t\t\t\t*  __        __   _                                      *\n";
    cout << "\t\t\t\t\t\t\t\t*  \\ \\      / /__| | ___ ___  _ __ ___   ___             *\n";
    cout << "\t\t\t\t\t\t\t\t*   \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\            *\n";
    cout << "\t\t\t\t\t\t\t\t*    \\ V  V /  __/ | (_| (_) | | | | | |  __/            *\n";
    cout << "\t\t\t\t\t\t\t\t*     \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|            *\n";
    cout << "\t\t\t\t\t\t\t\t*                                                        *\n";
    cout << "\t\t\t\t\t\t\t\t*                  Welcome to the Game!                  *\n";
    cout << "\t\t\t\t\t\t\t\t*                                                        *\n";
    cout << "\t\t\t\t\t\t\t\t**********************************************************\033[0m\n";
}

int main()
{
    system("CLS");
    printWelcomeMessage();

    cout << "\033[1;36m\nPress any key to continue....\033[0m" << endl;
    cin.get();

    int diff_level;

    while (true)
    {
        system("CLS");
    line104:
        cout << "\033[1;34m\nEnter difficulty level :- \033[0m" << endl;
        cout << "\033[1;34m\n1 - Easy\033[0m" << endl;
        cout << "\033[1;34m\n2 - Medium\033[0m" << endl;
        cout << "\033[1;34m\n3 - Hard\033[0m" << endl;
        cout << "\033[1;34m\nEnter your choice: \033[0m";
        cin >> diff_level;

        while (cin.fail() || diff_level < 1 || diff_level > 3)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\033[1;31m\nInvalid input! Please enter a valid integer between 1 and 3: \033[0m";
            playBeep("invalid");
            cin >> diff_level;
        }

        if (diff_level == 1)
        {
            cout << "\033[1;32m\nYou've chosen Easy difficulty. You have to guess a number between 1 to 20 in 10 chances. Best of luck!\033[0m" << endl;
            cout << "\033[1;33m\nLoading\033[0m";

            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 1000000000; j++)
                {
                }
                cout << ".";
            }
            game(20, 10);
        }
        else if (diff_level == 2)
        {
            cout << "\033[1;32m\nYou've chosen Medium difficulty. You have to guess a number between 1 to 50 in 8 chances. Best of luck!\033[0m" << endl;
            cout << "\033[1;33m\nLoading\033[0m";

            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 1000000000; j++)
                {
                }
                cout << ".";
            }
            game(50, 8);
        }
        else if (diff_level == 3)
        {
            cout << "\033[1;32m\nYou've chosen Hard difficulty. You have to guess a number between 1 to 80 in 5 chances. Best of luck!\033[0m" << endl;
            cout << "\033[1;33m\nLoading\033[0m";

            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 1000000000; j++)
                {
                }
                cout << ".";
            }
            game(80, 5);
        }
    }
    return 0;
}
