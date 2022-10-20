#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;


const int rows = 9; // Number of rows for 1 level
const int elements = 9; // Numbers elements for 1 level
int maxships = 9; // Number of maxships for 1 level
int matrix[rows][elements]; //
void SetShipS() // funcion Set Ships random way  level 1
{
    int s1 = 0;
    while (s1 < maxships)
    {
        int x_x = rand() % rows;
        int y_y = rand() % elements;
        if (matrix[x_x][y_y] != 1)
        {
            s1++;
            matrix[x_x][y_y] = 1;
        }
    }
}

bool AttacK(int x_x, int y_y) // funcion Attack ships  level 1
{
    if (matrix[x_x][y_y] == 1)
    {
        matrix[x_x][y_y] = 2;
        return true;
    }
    return false;
}

void Clear() // funcion for clear  level 1
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < elements; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Show() // funcion for Show level map  level 1
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < elements; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

int NumberOfShips() //  level 1
{
    int c = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < elements; j++)
        {
            if (matrix[i][j] == 1)
                c++;
        }
    }

    return c;
}

void SetShips() // funcion Set Ships random way  level 1
{
    int s = 0;
    while (s < maxships)
    {
        int x = rand() % rows;
        int y = rand() % elements;
        if (matrix[x][y] != 1)
        {
            s++;
            matrix[x][y] = 1;
        }
    }
}

bool Attack(int x, int y) // funcion Attack ships  level 1
{
    if (matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}

int level_one()
{
    srand(time(NULL));
    Clear();
    SetShips();
    int pos1, pos2;
    char prompt;
    while (1)
    {
        cout << "Please provide coordinates: "; cin >> pos1 >> pos2;
        if (Attack(pos1, pos2))
            cout << "you got into the ship" << endl;
        else
            cout << "Sorry no ship at that position!" << endl;
        cout << "Ships left: " << NumberOfShips() << endl;
        cout << "Do you want to surrender (y/n)? "; cin >> prompt;
        if (prompt == 'y')
            break;
    }
    cout << "Geme over!" << endl;
    Show();
    system("pause");
    return 0;
}