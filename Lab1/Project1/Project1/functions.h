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

int find(int size, int array[], int toFind)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == toFind)
        {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}
int find2ndLargest(int size, int arr[])
{
    if (size < 2) return -1; // Not enough elements

    int largest = arr[0];
    int secondLargest = -1; // Initialize as -1 since we want a simple return value if no second-largest is found.

    // Find the largest element first
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest; // Move current largest to secondLargest
            largest = arr[i]; // Update largest
        }
        else if (arr[i] < largest && (secondLargest == -1 || arr[i] > secondLargest))
        {
            secondLargest = arr[i]; // Update secondLargest if arr[i] is less than largest but greater than current secondLargest
        }
    }

    return secondLargest; // If no valid second-largest, secondLargest remains -1
}

void copyArraytoArray(int size, int arr1[], int arr2[])
{
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr1[i]; // Copy each element from arr1 to arr2
    }
}
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{
    if (count >= size || insertIndex < 0 || insertIndex > count)
    {
        return false; // Array is full or invalid index
    }

    // Shift elements to the right to make space
    for (int i = count; i > insertIndex; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[insertIndex] = elementToInsert;
    count++; // Increase the count of elements
    return true;
}
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{
    if (deleteIndex < 0 || deleteIndex >= count)
    {
        return false; // Invalid index
    }

    // Shift elements to the left to overwrite the element to delete
    for (int i = deleteIndex; i < count - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    count--; // Decrease the count of elements
    return true;
}
int frequencyCount(int size, int arr[], int value)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            count++;
        }
    }

    return count;
}
int countDuplicates(int size, int arr[])
{
    int duplicates = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicates++;
                break; // Stop after the first duplicate
            }
        }
    }

    return duplicates;
}
void reverse(int size, int arr[])
{
    for (int i = 0; i < size / 2; i++)
    {
        std::swap(arr[i], arr[size - i - 1]); // Swap elements from start to end
    }
}
void rotateLeft(int size, int arr[])
{
    if (size == 0)
    {
        return;
    }

    int firstElement = arr[0];

    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[size - 1] = firstElement; // Move the first element to the end
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (movieLengths[i] + movieLengths[j] == flightLength)
            {
                return true;
            }
        }
    }

    return false;
}
int wordCounter(int size, char characters[])
{
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; i < size; i++)
    {
        if (characters[i] != ' ' && !inWord)
        {
            inWord = true; // We're in a word
            wordCount++;
        }
        else if (characters[i] == ' ')
        {
            inWord = false; // End of the word
        }
    }

    return wordCount;
} 