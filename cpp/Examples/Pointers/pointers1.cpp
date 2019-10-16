// more pointers
//'*' operator -> deference operator
//'new' operator to allocate new memory address in 'heap memory'
#include <iostream>
using namespace std;

int main ()
{
//					0       1       2       3        4
//		array	|	10	|	20	|	30	|	40	|	50	|
//				  1000    1004     1008    1012    1016 	//increments by 4 bytes because it's storing ints, which are 4 bytes large

  int numbers[5];		//for arrays, memory's allocated in stack
  int * p;
  p = numbers;  		// copies base address array of numbers array
  *p = 10;
  
  p++;  *p = 20;
  p = &numbers[2];  *p = 30;
  p = numbers + 3;  *p = 40;
  p = numbers;  *(p+4) = 50;
  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";
  int i = 0;
  p = numbers;
  cout << endl;
  while(i<5)
  {
    cout << (*p)++ << endl;
    i++;
  }
  return 0;
}