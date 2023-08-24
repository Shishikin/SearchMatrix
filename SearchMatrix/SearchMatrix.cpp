#include <stdio.h>
#include <iostream>
#include <random>
#include <string>
#include <cmath>

//Матрица [2][2]
struct Matrix
{
    double matrix[2][2];
};

//найти определить матрицы [2][2]
double Determinant(Matrix matrix)
{
    double determinant = (matrix.matrix[0][0]) * (matrix.matrix[1][1]) - (matrix.matrix[0][1]) * (matrix.matrix[1][0]);
    return determinant;
}



//вывод матрицы [2][2]
void Print(Matrix matrix)
{
    std::cout << matrix.matrix[0][0] << " " << matrix.matrix[0][1] << "\n";
    std::cout << matrix.matrix[1][0] << " " << matrix.matrix[1][1] << "\n";
    std::cout << "\n";
}

//поиск матрицы с заданным определителем в массиве 
int Search(Matrix* matrix, int size, double min, double max)//это надо мне запомнить
{
    for (int i = 0; i < size; i++)
    {
        if ((min < Determinant(matrix[i])) && (Determinant(matrix[i]) < max))
        {
            return i;
        }
    }
    return -1;
}

//генерация вещественного значения в заданном диапозоне
double GetRandom(double min = 0, double max = 70)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution <double>distrib(min, max);
    return distrib(generator);
}

//создание случайной матрицы [2][2]
Matrix GetRandomMatrix()
{
    Matrix matrix;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix.matrix[i][j] = GetRandom();
        }
    }
    return matrix;
}

//заполнение массива матриц
void FillMatrixArray(Matrix* matrix, int size)
{
    for (int i = 0; i < 100; i++)
    {
        matrix[i] = GetRandomMatrix();
    }
}

int main() {
    //Matrix *matrix;возможный вариант вместо низ лежащего
    Matrix matrix[100];
    FillMatrixArray(matrix, 100);
    int indexFound = Search(matrix, 100, 75, 100);
    if (indexFound == -1)
    {
        std::cout << "элемент не найден";
    }
    else
    {
        std::cout << "Найдена искомая матрица с индексом " << Search(matrix, 100, 75, 100) <<
            " с определителем " << Determinant(matrix[Search(matrix, 100, 75, 100)]);
    }
    std::cout << " The end programm";
    return 0;
}