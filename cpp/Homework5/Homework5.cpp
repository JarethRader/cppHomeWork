#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findMax(vector<int> &list, int lowerIndex, int upperIndex);
int findMin(vector<int> &list, int lowerIndex, int upperIndex);
int getSum(vector<int> &);
int findAvg(vector<int> &);

int main(){
	int temp;
	vector<int> numsList;
	while(true){
		try {
			cout << "Enter numbers into list. Enter 0 when done" << endl;
			cin >> temp;
			if (temp == 0) break;
			numsList.push_back(temp);
		}
		catch(invalid_argument){
			cout << "Invalid Data Type for Input" << endl;
		}
		break;
	}
	findMax(numsList, 0, numsList.size());
	findMin(numsList, 0, numsList.size());

	cin.get();
	return 0;
}

int findMax(vector<int> &list, int lowerIndex, int upperIndex){
	int max;
	//base case:first case == last case
	if (lowerIndex == upperIndex)
		return list[lowerIndex];
	//general case: store number from other index into temp int Max, and compare to first value
	else
		max = findMax(list, lowerIndex + 1, upperIndex);
		if (list[lowerIndex] > max)
			return list[lowerIndex];
		else
			return max;
}

int findMin(vector<int> &list, int lowerIndex, int upperIndex){
	int min;
	//base case
	if (lowerIndex == upperIndex)
		return list[lowerIndex];
	//general case
	else{
		min = findMax(list, lowerIndex + 1, upperIndex);
	if (list[lowerIndex] > min)
		return list[lowerIndex];
	else
		return min;
	}
}

int getSum(vector<int> &list, int index){
	int sum;
	if(list.front()== list.back())
		return list.front();
	else{
		sum = getSum(list, index++);
		return sum;
	}
}

int findAvg(vector<int> &list){
	return (getSum(list, 0))/list.size();
}