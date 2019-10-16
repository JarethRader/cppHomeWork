//Linked List: List of elements called nodes that are linked together by pointers

/*singly linked list /or forward linked list
data only has a single link and can only go forward
		Nodes
		each node points to the next node
first	1000                         2000                         5000
head-->|	10	|	    -|---------> |	15	|		-|---------> |	100	|	0	-|--> (last node hits null pointer)
1000	data^	pointer^              data^	pointer^ 			  data^  pointer^
				link						link						 link
tail is last pointer
can use index to sort through data
	
				
*/

struct nodeType
{
	int data;
	nodeType &link;
};

//these are pointers because they're pointing to an address that stores actual data
nodeType *head;	//you  can never lose the head pointer, otherwise you lose track of the whole link list; cause a memory leak
//can define a new point say current and copy head into it in order to preserve head
nodeType *current;
nodeType *tail;
nodeType *node = new nodeType;
node->data=5;
node->link = nullptr;

//example of traversing the nodes in the list
current = current->link;
current->info = 63;
current->link = 3600;
current = current->link;
current->info = 45;
current->link = nullptr;

while(current != nullptr)
{
	cout << current->info << " " << current = current->link;
}

//create an empty link list
head->nullptr;
tail->nullptr;