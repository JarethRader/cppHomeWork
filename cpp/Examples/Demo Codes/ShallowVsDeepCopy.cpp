//Shallow vs deep copy
#include <iostream>
using namespace std;

class Test{
public;
	int nums[2];
	int *dNums;
	Test() {
		nums[0] = 1;
		nums[1] = 1;
		dNums = new int[2];
		dNums[0] = 10;
		dNums[1] = 10;
	}
	
	//Copy constructor
	Test(const Test &other){
		nums[0] = others.nums[0];
		nums[1] = others.nums[1];
		dNums = new int[2]; //need to allocate new memory
		for(int i = 0; i < 2; i++){
			dNums[i] = other.nums[i];
		}
	}
	const Test& operator=(const Test &other){
		//you want to prevent objects from copying themselves
		if(this != &other){
			nums[0] = others.nums[0];
			nums[1] = others.nums[1];
			delete[] dNums;
			dNums = new int[2]; //need to allocate new memory
			for(int i = 0; i < 2; i++){
				dNums[i] = other.nums[i];
			}
		}
		return *this;
	}
	~Test(){
		delete[] dNums;
	}
	
	void print(){
		cout << "Nums contents" << endl;
		printf("nums[0] = %d; and nums[1] = %d\n", nums[0], nums[1]);
		printf("dNums[0] = %d; and dNums[1] = %d\n", dNums[0], dNums[1]);
	}
};

int main(){
	
	Test t1;
	t1.print();
	//line below will use copy constructor and use the deep copy method(copy constuctor must exist)
	//Test t2 = t1;					//copies member by memeber by address; Shallow Copy (no copy constuctor)
	Test t2, t1, t3;
	//t2.operator=(t3.operator=(t1))
	t2 = t3 = t1; 						//shallow copy; unless = operator is overloaded to do a deep copy
	
	cout << "t2 values" << endl;
	t2.print();							//will print same values as t1
	
	t1.dNums[0] = 200;
	t1.dnums[1] = 200;
	t1.print();
	//t1.operator=(t1)
	t1 = t1								//this will cause an error when dNums is deleted; program will try to read from a null pointer value
	cout << "t2 values " << endl;
	t2.print();						//Both t1 and t2 will be changed to 200 and 200
	//with copy constructor present, t1 and t2 do not share the same memory location; they are independant
	
	/*
	int *nums = new int[3];			//pointer type to store addresses
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	
	//below method is called Shallow copy
	//nums and nums1 share the same memory location
	int *nums1 = nums;				//assigns an object to a pointer, copies addresses from nums and stores into nums1
	
	nums1[0] = 100;
	//both the lines below are pointing to the same memory address
	cout << nums[1] << endl;
	cout << nums[0] << endl;
	
	//deep copy
	cout << "deep copy" << endl;
	
	int *nums2 = new int[3];		//seperatly allocate more memory
	for(int i = 0; i < 3; i++){
		nums2[i] = nums[i];
	}
	cout << nums2[2] << endl;
	nums[2] = 100;
	cout << nums2[2] << endl;
	cout << nums[2] << endl;
	*/
	~Test();
	cin.get();
	return 0;
}