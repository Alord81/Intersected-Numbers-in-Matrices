#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int RandomeNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FullArrayWithOrderdNumber(short arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            arr[i][j] = RandomeNumber(0, 100);
        }
    }
}

void PrintArrayInMatrix(short arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d\t", 2, arr[i][j]);
        }
        cout << endl;
    }
}

bool IsNumberInMatrix(short Matrix[3][3], short Row, short Col, short Number)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (Matrix[i][j] == Number)
            {
                return true;
            }
        }
    }

    return false;
}

void PrintIntersectedNumbers(short Matrix1[3][3], short Matrix2[3][3], short Row, short Col)
{
    for (short i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (IsNumberInMatrix(Matrix2, Row, Col, Matrix1[i][j]))
            {
                cout << Matrix1[i][j];
                cout << "\t";
            }
        }
    }
    cout << endl;
}

int main()
{

    srand((unsigned)time(NULL));
    short Matrix1[3][3], Matrix2[3][3];
    short cols = 3, rows = 3, Number;

    FullArrayWithOrderdNumber(Matrix1, rows, cols);
    FullArrayWithOrderdNumber(Matrix2, rows, cols);

    cout << "Matrix1:\n";
    PrintArrayInMatrix(Matrix1, rows, cols);

    cout << "Matrix2:\n";
    PrintArrayInMatrix(Matrix2, rows, cols);

    cout << "\nIntersected Numbers are: ";
    PrintIntersectedNumbers(Matrix1, Matrix2, rows, cols);

    return 0;
}