#include <iostream>
#include <random>
#include <String>
using namespace std;

string random_string(size_t length)
{
    const string characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(0, characters.size() - 1);

    string random_string;

    for (size_t i = 0; i < length; ++i)
    {
        random_string += characters[distribution(generator)];
    }

    return random_string;
}

void bubbleSort(string arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int sizeInput;
    cout << "Please enter an array size: ";
    while (true)
    {
        cin >> sizeInput;
        if (sizeInput == NULL or sizeInput <= 0 or sizeInput > 1000000)
        {
            cout << "Please enter a number between 1 and 1 million.\n";
        }
        else
        {
            break;
        }
    }
    // Create one array of 1E6 elements, only sizeInput string elements will be filled.
    string *array1 = new string[1000000];
    srand(time(NULL));
    for (int i = 0; i < sizeInput; i++)
    {
        array1[i] = random_string(5);
        cout << array1[i] << " ";
    }
    bubbleSort(array1, sizeInput);
    cout << endl;
    for (int i = 0; i < sizeInput; i++)
    {
        cout << array1[i] << " ";
    }
    // Delete array
    delete[] array1;
    return 0;
}