#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int current;
    int numSuitors;

    cout << "Enter the number of suitors: ";
    cin >> numSuitors;

    if (numSuitors <= 0)
    {
        cout << "Not enough suitors." << endl;
        return (1);
    }

    vector<int> suitors(numSuitors);
    for (int i = 0; i < numSuitors; i++)
        suitors[i] = i + 1;

    if (numSuitors == 1)
        cout << "You would stand first in line." << endl;
    else
    {
        current = 0;
        while (suitors.size() > 1)
        {
            current = (current + 2) % suitors.size();
            suitors.erase(suitors.begin() + current);
        }

        cout << "To win the princess, you should stand in position " << suitors[0] << endl;
    }

    return (0);
}
