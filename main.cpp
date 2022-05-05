#include <iostream>
using namespace std;

class cricketer
{
public:
    int runs, balls;
    float strikeRate;
    char name[25];
};

void quicksort(cricketer arr[], int left, int right);

int main()
{
    int numberOfPlayers;
    cricketer playersArray[100];
    cout << "PROGRAM FOR CRICKET SCOREBOARD\n\n";
    cout << "Enter the number of cricket players : ";
    cin >> numberOfPlayers;
    cout << "\nEnter Player Info:\n\nNAME\tRUNS\tBALLS\n---------------------\n";
    for (int idx = 0; idx < numberOfPlayers; idx++)
    {
        cin >> playersArray[idx].name >> playersArray[idx].runs >> playersArray[idx].balls;
        playersArray[idx].strikeRate = (float)playersArray[idx].runs / (float)playersArray[idx].balls;
    }
    quicksort(playersArray, 0, numberOfPlayers - 1);
    cout << "\n\nSCOREBOARD:\n";
    cout << "\nNO.\tNAME\tRUNS\tBALLS\tSTRIKE RATE\n";
    cout << "-------------------------------------------\n";
    for (int idx = 0; idx < numberOfPlayers; idx++)
    {
        cout << idx + 1 << ".\t" << playersArray[idx].name << "\t" << playersArray[idx].runs << "\t" << playersArray[idx].balls << "\t" << playersArray[idx].strikeRate << "\n";
    }
}

void quicksort(cricketer arr[], int left, int right)
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
