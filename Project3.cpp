//Author:      Fatima Parada-Taboada
//Assignment:  Project 3
//Net ID:      fnp170130
//Function:    Problem: As usual, Wario is concerned about nothing other than acquiring more money. In order to maximize
//             profits, Wario needs to use calculus to create derivatives for analysis.Unfortunately, Wario never took calculus;
//             there wasn’t much need of it in the Mushroom Kingdom.So, Wario is calling on you to help him by creating a
//             program to create derivatives.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Class for functions and their similar elements (members - x, 1-9, sin, cos, tan sec etc.) and manipulating to create derivation (functions)
//LINKED LIST CLASS
class LinkedList
{
	//access modifier
private:
	//data member
	typedef struct node {
		int data;
		node*next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;

	//access modifier
public:
	//default constructor
	LinkedList()
	{
		head = NULL;
		curr = NULL;
		temp = NULL;
	};

	void AddNode(int addData) 
	{
		nodePtr n = new node;
		n->next = NULL;
		n->data = addData;

		//if list exists
		if (head != NULL)
		{
			//copy of list
			curr = head;

			//last node in list
			while (curr->next != NULL)
			{
				curr = curr->next;
			}

			curr->next = n;
		}
		//if list does not exist
		else
		{
			head = n;
		}
	};

	void DeleteNode(int delData)
	{
		nodePtr delPtr = NULL;
		temp = head;
		curr = head;
		while (curr != NULL && curr->data != delData)
		{
			temp = curr;
			curr = curr->next;
        }
		if (curr == NULL)
		{
			cout << delData << "was not in the list\n";
			delete delPtr;
		}
		else 
		{
			delPtr = curr;
			curr = curr->next;
			temp->next = curr;
			delete delPtr;
		}
	};

	void PrintList()
	{
	
	};
};

//Gets each segment in each function
//NODE CLASS
class Node
{
private:
	int outerCoefficient = 0;
	int innerCoefficient = 0;
	int exponent = 0;
	int trigIdentifier = 0;
	struct Node *nextNode = NULL;

public:
	Node();

	Node(int outer, int inner, int exp, int trigID, Node *next)
	{
		outerCoefficient = outer;
		innerCoefficient = inner;
		exponent = exp;
		trigIdentifier = trigID;
		nextNode = next;
	}
};

int main()
{
	string current;
	ifstream function("functions.txt"); 
	int numFunc = 0;
	string newFunc = "A";
	//int *currFunc;
	string *seg1;

	if (function)
	{ 
		int i = 0;

		while (!(function.eof()))
		{
			getline(function, current);
			int j = 0;
			seg1 = new string[current.length()];
			for (int i = 0; current[i] != ' '; i++)
			{
				seg1[j] = current[i];
				j++;
			}

			for (int k = 0; k < j; k++)
			{
				cout << seg1[k];
			}
			LinkedList obj1;
			Node obj2;

			
		}
		
	}
	else
	{
		cout << "File could not be found\n";
	}

	system("pause");
	return 0;
}

