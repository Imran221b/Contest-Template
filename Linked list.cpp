nstruct node
{
  int roll;
	node *next;
};
node *root=NULL;
 
// ---------------
 
void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=new node(); //create new node in root
		root->roll=roll;
       root->next=NULL;
	}
}
 
//-----------------
 
void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=new node();
		root->roll=roll;
		root->next=NULL;
	}
	else
	{
		node *current_node=root; //make a copy of root node
		while(current_node->next!=NULL) //Find the last node
		{
			current_node=current_node->next; //go to next address
		}
		node *newnode = new node(); //create a new node
		newnode->roll=roll;
		newnode->next=NULL;
 
		current_node->next=newnode; //link the last node with new node
	}
}
 
 
//-------------------------
 
 
void print()
{
		node *current_node=root;
		while(current_node!=NULL) //loop until you reach null
		{
			printf("%d\n",current_node->roll);
			current_node=current_node->next;
		}
}
 
 
//-------------------------------
 
 
void delete_node(int roll)
{
	node *current_node=root;
	node *previous_node=NULL;
	while(current_node->roll!=roll) //Searching node
	{
		previous_node=current_node; //Save the previous node
		current_node=current_node->next;
	}
	if(current_node==root) //Delete root
	{
		node *temp=root; //save root in temporary variable
		root=root->next; //move root forward
		delete(temp); //free memory
	}
	else //delete non-root node
	{
		previous_node->next=current_node->next; //previous node points the current node's next node
		delete(current_node); //free current node
	}
}
 
 
//---------------------
 
 
struct node
{
	int roll;
	node *left, *right;
	node() //initialize the node using null
	{
		left=NULL;
		right=NULL;
	}
};
node *root;
 
//----------------------
 
void insert(int roll)
{
	if(root==NULL) //first node in tree
	{
		root=new node();
		root->roll=roll;
	}
	else
	{
		node *current=root,*parent;
		while(current!=NULL)
		{
				if(roll<current->roll)
				{
					parent=current; //keep track of parent node
					current=current->left;
				}
				else
				{
					parent=current;
					current=current->right;
				}
		}
		node *newnode=new node();
		newnode->roll=roll;
		if(newnode->roll<parent->roll) parent->left=newnode;
		else parent->right=newnode;
	}
}

