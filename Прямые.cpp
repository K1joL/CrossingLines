#include <iostream>
using namespace std;

struct line
{
    double x1, y1, x2, y2;
};

void cross(line line1, line line2)
{
    double solveX, solveY, k1, b1, k2, b2;

    if (line1.y2 - line1.y1 != 0)
        k1 = (line1.y2 - line1.y1) / (line1.x2 - line1.x1);
    else
        k1 = 0;
    b1 = (line1.x2 * line1.y1 - line1.x1 * line1.y2) / (line1.x2 - line1.x1);
    if (line2.y2 - line2.y1 != 0)
        k2 = (line2.y2 - line2.y1) / (line2.x2 - line2.x1);
    else
        k2 = 0;
    b2 = (line2.x2 * line2.y1 - line2.x1 * line2.y2) / (line2.x2 - line2.x1);

    cout << "Отрезки пересекаются в точке M(";
    if (((line1.x2 - line1.x1) != 0) and ((line2.x2 - line2.x1) != 0))
    {
            solveX = (b2 - b1) / (k1 - k2);
            solveY = k1 * solveX + b1;

            if (k1 == k2)
                cout << "Прямые параллельны.\n";
            else
                cout << solveX << ";" << solveY << ")" << endl;
    }
    else
    {
        if ((line1.x2 - line1.x1) == 0)
        {
            solveX = line1.x1;
            solveY = k2 * solveX + b2;
            cout << solveX << ";" << solveY << ")" << endl;
        }
        else
        {
            solveX = line2.x1;
            solveY = k1 * solveX + b1;
            cout << solveX << ";" << solveY << ")" << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    line line1;
    cin >> line1.x1 >> line1.y1 >> line1.x2 >> line1.y2;
    cout << "Отрезок1: (" << line1.x1 << ";" << line1.y1 << ") (" << line1.x2 << ";" << line1.y2 << ")\n";
    line line2;
    cin >> line2.x1 >> line2.y1 >> line2.x2 >> line2.y2;
    cout << "Отрезок2: (" << line2.x1 << ";" << line2.y1 << ") (" << line2.x2 << ";" << line2.y2 << ")\n";

    cross(line1, line2);

    return 32;
}