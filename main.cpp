#include <iostream>
using namespace std;

class cricketer
{
public:
    int runs, balls;
    float strikeRate;
    char name[25];
};

int main()
{
    int numberOfPlayers;
    cricketer playersArray[100], temporaryPlayer;
    cout << "PROGRAM FOR CRICKET SCOREBOARD\n\n";
    cout << "Enter the number of cricket players : ";
    cin >> numberOfPlayers;
    cout << "\nEnter Player Info:\n\nNAME\tRUNS\tBALLS\n---------------------\n";
    for (int idx = 0; idx < numberOfPlayers; idx++)
    {
        cin >> playersArray[idx].name >> playersArray[idx].runs >> playersArray[idx].balls;
        playersArray[idx].strikeRate = (float)playersArray[idx].runs / (float)playersArray[idx].balls;
    }
    for (int iteration = 0; iteration < numberOfPlayers; iteration++)
    {
        for (int idx = 0; idx < numberOfPlayers - 1; idx++)
        {
            if (playersArray[idx].runrate < playersArray[idx + 1].runrate)
            {
                temporaryPlayer = playersArray[idx];
                playersArray[idx] = playersArray[idx + 1];
                playersArray[idx + 1] = temporaryPlayer;
            }
        }
    }
    cout << "\n\nSCOREBOARD:\n";
    cout << "\nNO.\tNAME\tRUNS\tBALLS\tSTRIKE RATE\n";
    cout << "-------------------------------------------\n";
    for (int idx = 0; idx < numberOfPlayers; idx++)
    {
        cout << idx + 1 << ".\t" << playersArray[idx].name << "\t" << playersArray[idx].runs << "\t" << playersArray[idx].balls << "\t" << playersArray[idx].strikeRate << "\n";
    }
}
