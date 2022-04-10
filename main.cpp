#include <iostream>
using namespace std;

class cricketer
{
public:
    int runs, balls;
    float runrate;
    char name[25];
};

int main()
{
    int n;
    cricketer player[100], t;
    cout << "PROGRAM FOR CRICKET SCOREBOARD\n\n";
    cout << "Enter the number of cricket players : ";
    cin >> n;
    cout << "\nEnter Player Info:\n\nNAME\tRUNS\tBALLS\n---------------------\n";
    for (int i = 0; i < n; i++)
    {
        cin >> player[i].name >> player[i].runs >> player[i].balls;
        player[i].runrate = (float)player[i].runs / (float)player[i].balls;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (player[j].runrate < player[j + 1].runrate)
            {
                t = player[j];
                player[j] = player[j + 1];
                player[j + 1] = t;
            }
        }
    }
    cout << "\n\nSCOREBOARD:\n";
    cout << "\nNO.\tNAME\tRUNS\tBALLS\tSTRIKE RATE\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ".\t" << player[i].name << "\t" << player[i].runs << "\t" << player[i].balls << "\t" << player[i].runrate << "\n";
    }
}
