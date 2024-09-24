#pragma once
#include <iostream>

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else {
        return false;
    }
}

int Reversed(int testNumber)
{
    int revNumber = 0;
    while (testNumber > 0)
    {
        revNumber = revNumber * 10 + testNumber % 10;
        testNumber /= 10;
    }
    return revNumber;
}

bool isAPalindrome(int testNumber)
{
    return Reversed(testNumber) == testNumber;
}

bool isAPrimeNumber(int numberToTest)
{
    if (numberToTest <= 1) return false;
    for (int i = 2; i * i <= numberToTest; i++)
    {
        if (numberToTest % i == 0)
            return false;
    }
    return true;
}

int input5CharsConvertToInt()
{
    int returnInt = 0;
    char inputChar;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> inputChar;
        if (isdigit(inputChar))
        {
            returnInt = returnInt * 10 + (inputChar - '0');
        }
        else
        {
            std::cout << "Invalid input!" << std::endl;
            return -1;
        }
    }
    return returnInt;
}

int convertBinarytoDecimal(int binaryNumber)
{
    int decimalNumber = 0, base = 1;
    while (binaryNumber > 0)
    {
        int lastDigit = binaryNumber % 10;
        decimalNumber += lastDigit * base;
        binaryNumber /= 10;
        base *= 2;
    }
    return decimalNumber;
}

void drawRightAngledTriangle()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void drawIsocelesTriangle()
{
    int height = 5;
    for (int i = 1; i <= height; i++)
    {
        for (int j = height - i; j > 0; j--)
            std::cout << " ";
        for (int k = 1; k <= (2 * i - 1); k++)
            std::cout << "*";
        std::cout << std::endl;
    }
}
void drawIsocelesTriangle2()
{

}

int find(int size, int arr[], int toFind)
{
    return -1;
}
int find2ndLargest(int size, int arr[])
{
    return -1;
}
void copyArraytoArray(int size, int arr1[], int arr2[])
{
    return;
}
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{

    return false;
}
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{

    return true;
}
int frequencyCount(int size, int arr[], int value)
{

    return 0;
}
int countDuplicates(int size, int arr[])
{

    return 0;
}
void reverse(int size, int arr[])
{
    return;
}
int rotateLeft(int size, int arr[])
{
    return -1;
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
    return false;
}
int wordCounter(int size, char characters[])
{
    return 0;
}