#include <iostream>
using namespace std;

class cricketer
{
public:
    int runs, balls;
    float strikeRate;
    char name[25];
    static void quicksort(cricketer arr[], int left, int right);
};

void getPlayerCount(int &numberOfPlayers);

void getPlayerInfo(int numberOfPlayers, cricketer playersArray[100]);

void printScoreBoard(int numberOfPlayers, cricketer playersArray[100]);

int main()
{
    int numberOfPlayers;
    cricketer playersArray[100];
    cout << "PROGRAM FOR CRICKET SCOREBOARD" << "\n\n";
    getPlayerCount(numberOfPlayers);
    getPlayerInfo(numberOfPlayers, playersArray);
    cricketer::quicksort(playersArray, 0, numberOfPlayers - 1);
    printScoreBoard(numberOfPlayers, playersArray);
}

void getPlayerCount(int &numberOfPlayers)
{
    cout << "Enter the number of cricket players : ";
    cin >> numberOfPlayers;
    cout << "\n";
}

void getPlayerInfo(int numberOfPlayers, cricketer playersArray[100])
{
    cout << "Enter Player Info:" << "\n\n";
    cout << "NAME" << "\t" << "RUNS" << "\t" << "BALLS" << "\n";
    cout << "---------------------" << "\n";
    for (int idx = 0; idx < numberOfPlayers; idx++)
    {
        cin >> playersArray[idx].name;
        cin >> playersArray[idx].runs;
        cin >> playersArray[idx].balls;
        playersArray[idx].strikeRate = (float)playersArray[idx].runs / (float)playersArray[idx].balls;
    }
    cout << "\n\n";
}

void printScoreBoard(int numberOfPlayers, cricketer playersArray[100])
{
    cout << "SCOREBOARD:" << "\n\n";
    cout << "NO." << "\t" << "NAME" << "\t" << "RUNS" << "\t" << "BALLS" << "\t" << "STRIKE RATE" << "\n";
    cout << "-------------------------------------------" << "\n";
    for (int idx = 0; idx < numberOfPlayers; idx++)
    {
        cout << idx + 1 << "." << "\t";
        cout << playersArray[idx].name << "\t";
        cout << playersArray[idx].runs << "\t";
        cout << playersArray[idx].balls << "\t";
        cout << playersArray[idx].strikeRate << "\n";
    }
}

void cricketer::quicksort(cricketer arr[], int left, int right)
{
    int i = left, j = right;
    cricketer tmp;
    float pivot = arr[(left + right) / 2].strikeRate;

    while (i <= j)
    {
        while (arr[i].strikeRate > pivot)
            i++;
        while (arr[j].strikeRate < pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}
