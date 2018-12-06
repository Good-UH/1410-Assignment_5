/*COSC 1410, Assignment 5
Tuesday, October 14, 2014
Write a function called sortMe that sorts the elements of an array in nemerical order from highest to lowest values (descending order) or vice versa (ascending order).
sortMe does NOT re-arrange elements in the array; instead, it uses a second array, an array of indexes for the elements in the original array and then sortMe
sorts the second array based on the values in the original array A sorted version of the original array can then be produced with these sorted indexes.
mode 'a', function sorts in the ascending order, mode 'd' function sorts in the descending order.
Assume that the user will always enter proper type of mode (char).
*/
#include <iostream>
using namespace std;

const int MAX_ARRAY_SIZE = 7; //Have a constant array value size to change the value of the array

void sortMe(int array[], int sortedIndexes[], int size, char mode); //function to sort the array in a decending or ascending order
int getSmallestAvailableIndex(int sortedIndexes[], int size); //function to go to the next available index
bool isExist(int smallestIndex, int sortedIndexes[]); //bool function to check if the current index hasn't been used
char getMode(); //function to get the user input of ascending or descending mode
void printArray(int array[], int sortedIndexes[]); //function to print out the newly sorted array
char mode; //char called mode to hold a character of the mode chosen
bool isModeValid(char mode); //bool function to validate the input

int main()
{
	int array[MAX_ARRAY_SIZE] = { 2, 4, -5, 7, 0, 1, -8 }; //Declare and initialize the original array an the values
	int sortedIndexes[MAX_ARRAY_SIZE]; //Declare the array sortedIndexes but do not initialize
	mode = getMode(); //the mode will be returned by using the function getMode
	sortMe(array, sortedIndexes, MAX_ARRAY_SIZE, mode); //sort the array in a ascending or descending order 
	printArray(array, sortedIndexes); //print out the sorted array

	system("pause");
	return 0;
}

void sortMe(int array[], int sortedIndexes[], int size, char mode) //function that sorts the second array based on the values in the original array
{
	int smallestIndex, smallestValue; //init variables to find the smallestIndex and smallestValue
	if (mode == 'a') //if the user inputs mode a(scending)
	{
		for (int index = 0; index < MAX_ARRAY_SIZE; index++) //for loop to go through each index
		{
			smallestIndex = getSmallestAvailableIndex(sortedIndexes, MAX_ARRAY_SIZE); //used to calculate the smallestAvailable index
			smallestValue = array[smallestIndex]; //used to calculate the value with the smallest index(already found) in the array
			for (int index2 = 0; index2 < MAX_ARRAY_SIZE; index2++) //for loop to run through each index2 in the 2nd array (used to find a smallest value available)
			{
				if (!isExist(index2, sortedIndexes)) //checks if the value from index2, is not already a sortedIndexes value
				{
					if (smallestValue >= array[index2]) //if statement to compare the smallest value if it is greater than or equal to another value in the array using index2
					{ //if a smaller value is found using index2 in the array then update the smallest index and value
						smallestIndex = index2; //index2 is equal to the smallest index or updates the smallest index
						smallestValue = array[smallestIndex]; //places the value of array[smallestIndex] as the smallest value
					}
				}
			}
			sortedIndexes[index] = smallestIndex; //places the smallestIndex available(that has the smallest value) into the array of sortedIndexes
		}
	}
	else if (mode == 'd') //if the user inputs mode d(escending)
	{
		for (int index = 0; index < size; index++) //for loop to go through each index
		{
			smallestIndex = getSmallestAvailableIndex(sortedIndexes, size); //used to calculate the smallestAvailable index
			smallestValue = array[smallestIndex]; //used to calculate the value with the smallest index(already found) in the array
			for (int index2 = 0; index2 < size; index2++) //for loop to run through each index2 in the 2nd array (used to find the highest value available)
			{
				if (!isExist(index2, sortedIndexes)) //checks if the value from index2, is not already a sortedIndexes value
				{
					if (smallestValue <= array[index2]) //if statement to compare the smallest value if it is less than or equal to another value in the array using index2
					{ //if a greater value is found using index2 in the array then update the smallest index and value
						smallestIndex = index2; //index2 is equal to the smallest index or updates the smallest index
						smallestValue = array[smallestIndex]; //places the value of array[smallestIndex] as the smallest value
					}
				}

			}
			sortedIndexes[index] = smallestIndex; //places the smallestIndex available(that has the highest value) into the array of sortedIndexes
		}
	}
}

int getSmallestAvailableIndex(int sortedIndexes[], int size) //function to check the smallestAvailableIndex 
{
	for (int index = 0; index < MAX_ARRAY_SIZE; index++) //for loop to go through each index
	{
		if (!isExist(index, sortedIndexes)) //if the index does not exist in the sortedIndexes
		{
			return index; //return the index
		}
	}
}

bool isExist(int smallestIndex, int sortedIndexes[]) //function to check if the smallest index exists
{
	for (int index = 0; index < MAX_ARRAY_SIZE; index++) //for loop to go through each index
	{
		if (smallestIndex == sortedIndexes[index]) //if the smallestIndex is found in the sortedIndexes array
		{
			return true; //return true 
		}
	}
	return false; //otherwise return false
}

char getMode() //function to get the input from the user to determine the mode
{
	do //ask the user for a valid mode
	{
		cout << "We are going to assort the array { 2,4,-5,7,0,1,-8 }" << endl //Print out the instructions to the user
			<< "Choose 'a' for ascending order and 'd' for descending order: ";
		cin >> mode; //ask for the mode
	} while (isModeValid(mode) == false); //ignore input if its not 'a' or 'd'

	return mode; //return the mode
}

void printArray(int array[], int sortedIndexes[]) //function to print the sorted array
{
	cout << "The new order is:" << endl; //print out the new ordered array
	for (int index = 0; index < MAX_ARRAY_SIZE; index++) //for loop from the first index to the max array size
	{
		cout << array[sortedIndexes[index]] << endl; //this prints the values of the array using the sortedIndexes
	}
}

bool isModeValid(char mode) //function to verify the input is a or d
{
	if (mode == 'a' || mode == 'd') //returns true if the input is a or d
	{
		return true;
	}
	else //returns false if it is not a valid input
	{
		return false;
	}
}
