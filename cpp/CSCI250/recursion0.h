/*Factorial Function
n!
Ex: 4! = 4*3*2*1 = 24
note: 0! = 1

don't use loops, accomplish thing by calliing the function itself

n! {
	1 if n = 0
	n * (n-1) otherwise
}
*/

//peer recursion has no global variables and no explicit loops
int factRec (int n){
	if(n == 0) return 1;// base case
	else
		return n * fact(n-1);
}
/*factRec(4) -> 4 + factRec(3)
				|-> 3 + factRec(2)
						|-> 2 + factRec(1)
								|-> 1 + factRec(0)
										|-> */

//Same factorial funtion without recursion
int factLoop (int n){
	int result = 1;
	for( inti = n; i >=0; i--)
		result = result*i;
	return result;
}										

void luvme (){
	char ans;
	cout << "Do you love me?(y/n) ";
	cin >> ans;
	if(ans == 'y')
		cout << "I love you too!";	
	else
		luvme();
}

int multiply(int num1, num2){
	if(num == 1)
		return num1;
	else
		return num1 + multiply(num1, (num2 - 1));
}

/*
num1 = 3 , num2 = 5

multiply(3, 5) -> 3 + multiply(3, 4)
	|->multiply(3, 4) -> 3 + multiply(3, 3)
		|->multiply(3, 3) -> 3 + multiply(3, 2)
			|->multiply(3, 2) -> 3 + multiply(3, 1)
				|-> multiply(3, 1) -> 3

*/

int max(int a[], int length){
	if( length == 1)
		return a[0];
	else if(a[length-1] > max(a, length-1))
		return a[length-1];
	else
		return max(a, length -1);		
}

int maxHelp(int a[], int length, int maxSoFar){
	if(length == 0) int maxSoFar = a[0];
	else if(a[length] > maxSoFar)
		return maxHelp(a, length, maxSoFar);
	else return maxHelp(a, length, maxSoFar);
}

//write a recursive function called astrisks that takes a single non-negative number integer n argument and prints out n astrisks

void astrisk(int n){
	if(n == 1)
		return '*';
	else
		return '*' + astrisk(n-1);
}

bool membership(int a[], int length, int target){
	if(length == 0) return false;
	else if(a[length-1] == target) return true;
	else return membership(a, length-1, target);
}

int sum(int a[], int length){
	if(length == 0) return 0;
	else return a[length-1] + sum(a, length-1);
}

//homework
/*
count({10,5,3,4,3}, 5, 3)
count # of instances of target
*/

int count(int a[], int length, int target){
	if(length == 0)return 0;
	else if(a[length-1] == target)return 1 +count(a, length-1, target);
	else return count(a, length-1, target);
}

struct node{
	int value;
	node* next;
}

int length(node* head){
	if(head == NULL) return 0;
	else return 1 + length(nead->next);
}

void print(node* head){
	if(head != NULL){
	cout << head->value << endl;
	print(head->value);
	}
}

bool member(node* head, int target){
	if(head == NULL) return false;
	else if(head->value == target)return true;
	else return member(head->next, target);
}

void reverse(node* head){
	if(head != NULL){
		reverse(head->next);
		count << head->value;
	}
}

//homework
/*
append two link lists
*/



struct node {
int value;
node *next;
};

node append(node* lst1, node* lst2){
	if(lst2 == NULL){
		if(lst1 == NULL) return NULL;
		return lst1->node;
	}
	if(lst1 != NULL){
		append(lst1, lst2);
		return lst1->node;
	}
	else{
		lst1->node = lst2;
	}
}

int nth(node* head, int n){
	if(n == 0) return node->value;
	else return (node->next, n-1);
}

int sum(node* head){
	if(node == NULL) return 0;
	else return (node->value) + sum(node->next);
}

node reverse(node* head){
	//use append
}

//homework
/*
void triangle(int n)| triangle(n)
					|****
					|***
					|**
					|*
					|*
					|**
					|***
					|****

1.use astrisks(n)
2.no iteration
3.no global variables
4.no local variables
*/

Search
-sequential search		
	"records" -> "Key"(data entry that contains a specialized key)
-binary search
	Requires data to be sorted in ascending/descending order
	can be phrased recursivly
	
