#include <iostream>

using namespace std;

//template used to compare values of different types of variables
template <class T>
T max(T num1, T num2){
	return (num1 >= num2 ? num1 : num2);
}

//Method to compare values but specifically for doubles
/*double max(double num1, double num2){
	return (num1 >= num2 ? num1 : num2);
}
*/

//Can use mutliple different types of classes in templates
template<class TypeName, class Type1>
bool equal(TypeName val1, Type1 val2){
	return (val1 == val2);
}

int main(){
	cout << max<int>(100, 200) << endl;
	cout << max<double>(200.5, 200.5656) << endl;
	//Order of variable types does not matter,
	//as long as the types match up
	//if(equal<int, double>(10.5656, 10));
	if(equal<int, double>(10, 10.0))
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
	
	cin.get();
	
	return 0;
}