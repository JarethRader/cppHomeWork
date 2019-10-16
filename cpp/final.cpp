#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int ARRAY_SIZE = 20;						//Const int for array size
void populateArray(int nums[], int size);		//Declare function to populate an array of defined size

int[] swap(int[]  array, int num1, int num2);	//Declare swap function to switch two elements in an array

int[] bubbleSort(int nums[], int size);			//Declare bubble sort function
int[] selectionSort(int nums[], int size);		//Declare selection sort function
int[] insertionSort(int nums[], int size);		//Declare insertion sort function
int[] quickSort(int nums[], int size);			//Declare quick sort function
int[] mergeSort(int nums[], int size);			//Declare merge sort function

int main() {
	srand(time(NULL));							//new random seed
	int *numbers = new int[ARRAY_SIZE];			//Define a new dynamic array
	populateArray(numbers, ARRAY_SIZE);			//run populateArray function to add variables into array, numbers
	for (int i = 0; i < ARRAY_SIZE; i++) {		//for loop printing out all numbers in array
		cout << numbers[i] << endl;
	}
	//--------------------------BUBBLE SORT---------------------------
	int[] bubbleSorted = new int[ARRAY_SIZE];			//Defining a new array to be bubble sorted
	bubbleSorted = bubbleSort(numbers, ARRAY_SIZE);		//bubble sorting array

	for (int i = 0; i < ARRAY_SIZE; i++) {				//for loop printing out bubble sorted array
		cout << bubbleSorted[i] << endl;
	}
	
	//--------------------------SELECTION SORT---------------------------
	int[] selectionSorted = new int[ARRAY_SIZE];
	selectionSorted = selectionSort(numbers, ARRAY_SIZE);
	
	for (int i = 0; i < ARRAY_SIZE; i++) {				//for loop printing out selection sorted array
		cout << selectionSorted[i] << endl;
	}
	
	//--------------------------INSERTION SORT---------------------------
	int[] insertionSorted = new int[ARRAY_SIZE];
	insertionSorted = insertionSort(numbers, ARRAY_SIZE);
	
	for (int i = 0; i < ARRAY_SIZE; i++) {				//for loop printing out insertion sorted array
		cout << insertionSorted[i] << endl;
	}
	
	//--------------------------QUICK SORT---------------------------
	int[] quickSorted = new int[ARRAY_SIZE];
	quickSorted = quickSort(numbers, ARRAY_SIZE);
	
	for (int i = 0; i < ARRAY_SIZE; i++) {				//for loop printing out quick sorted array
		cout << quickSorted[i] << endl;
	}
	
	//--------------------------MERGE SORT---------------------------
	int[] mergeSorted = new int[ARRAY_SIZE];
	mergeSorted = mergeSort(numbers, ARRAY_SIZE);
	
	for (int i = 0; i < ARRAY_SIZE; i++) {				//for loop printing out merge sorted array
		cout << mergeSorted[i] << endl;
	}

	delete [] numbers;				//deleting dynamic instance of array
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}

//define function to swap two elements in an array
int[] swap(int[]  array, int index1, int index2){
	int[] copy = new int[array.size()];				//defining a copy of array passed in through function
	for (int i = 0; i < array.size(); i++) {		//for loop copying values of 'array' into 'copy'
		copy[i] = array[i];
	}
	int temp = array[index1];
	copy[index1] = copy[index2];
	copy[index2] = temp;
	return copy;
}

void populateArray(int nums[], int size) {
	for (int i = 0; i < size; i++) {				//for loop traversing every value of array 'nums'
		nums[i] = rand() % 100 + 1;					//generate a new random number from 1 to 100 and assign into nums at index i
	}
}

int[] bubbleSort(int nums[], int size) {
	bool sort = false;					//boolean to check if array has been completely sorted through
	int *copy = new int[size];			//creating a copy of array ,'nums'
	for (int i = 0; i < size; i++) {	//for loop copying values of 'nums' into 'copy'
		copy[i] = nums[i];
	}
	int count;							//int to count number of swaps made in while loop
	while (sort == false) {
		count = 0;						//setting count to 0
		for (int i = 0; i < size-1; i++) {		//for loop to check every value of array 'copy'
			int temp = copy[i];
			if (copy[i] > copy[i + 1]) {		//checking if number at current index is greater than next number
				copy = swap(copy, i, i+1);		//if so, swap two values in array
				cout << "Swapping element " << copy[i] << " and " << copy[i + 1] << endl;
				count++;			//index count by 1
			}

		}
		if (count == 0)				//if whole array has been traversed, check value of count
		sort = true;				//if count = 0, array has been completely sorted
	}
	return copy;					//return array 'copy'
}

int[] selectionSort(int nums[], int size) {
	bool sort = false;				//define boolean to check if array has been completely sorted through
	int index;						//define int to store index of array to be swaped
	int *copy = new int[size];		//define new array to copy 'nums' into
	int temp = copy[i];				//define int to store min value of array
	for (int i = 0; i < size; i++) {//copying value from 'nums' into 'copy'
		copy[i] = nums[i];
	}
	int count;						//define new int to count number of swaps made
	while(sort == false){			//while loop to sort array
		count = 0;					//int count set to 0
		for (int i = 0; i < size-1; i++) {	//for loop to run through every value of array
			for(int i = 0; i < size; i++)	//for loop to find minimun value in array
				if (copy[i] <= temp){			//if current index is less than temp
					temp = copy[i];				//store current index into temp
					index = i;					//set int index to current index
				}
			copy = swap(copy, index, i);		//swap values in array
		}
		
		if(count == 0)				//if count = 0, no changes were made and array should be sorted
			sort == true;			// set sort to true
	}	
}

int[] insertionSort(int nums[], int size){
	bool sort = false;				//define boolean to check if array has been completely sorted through
	int index;						//define int to store index of array to be swaped
	int *copy = new int[size];		//define new array to copy 'nums' into
	for (int i = 0; i < size; i++) {//copying value from 'nums' into 'copy'
		copy[i] = nums[i];
	}
	int temp;
	for(int i = 0; i < size; i++){
		if(!copy[i]<copy[i+1]){
			for(int j = i+1; j > 0; j--){
				copy = swap(copy, j, j-1)
			}
		}
	} 
}

int[] quickSort(int nums[], int size){
	
}

int[] mergeSort(int nums[], int size){
	
}


