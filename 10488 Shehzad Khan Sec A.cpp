/*Singly linkedlist*/
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class SLL
{
private:
	node *head, *tail;
	int count;

public:
	SLL()
	{
		count = 0;
		head = NULL;
		tail = NULL;
	}

	void CreateNodes()
	{
		int num;
		char choice;

		do
		{
			cout << "Enter number you want to be inserted :";
			cin >> num;

			node *temp = new node;
			temp->data = num;
			temp->next = NULL;

			if (count == 0)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
			count++;
			cout << "You want to continue y/n :";
			cin >> choice;
		} while (choice == 'y' && choice != 'n');
	}

	void Bubblesort()
	{
		node *temp = new node;
		node *curr;
		node *prev;
		prev = head;
		//the base condition
		//if user call directly sorting in main
		// the program must be genenrate message like this please insert data first
		if (count == 0)
		{
			cout << "List in empty please insert data first!" << endl;
		}
		else
		{
			cout << "Applying sorting Successfully" << endl;
			while (prev != NULL)
			{
				curr = prev->next;
				while (curr != NULL)
				{
					if (prev->data > curr->data)
					{
						temp->data = prev->data;
						prev->data = curr->data;
						curr->data = temp->data;
					}
					curr = curr->next;
				}
				prev = prev->next;
			}
		}
	}
	void display()
	{
		node *print;
		print = head;

		if (count == 0)
		{
			cout << "List is empty please insert data first!" << endl;
		}
		else
		{
			cout << "Data in list :";
			while (print != NULL)
			{
				cout << print->data << " ";
				print = print->next;
			}
			cout << "\nTotal Nodes :" << count << endl;
		}
	}
};

main()
{
	int choice;
	SLL obj;

	do
	{
		cout << "Menu" << endl;
		cout << "1.Insertion\n2.Bubble Sort\n3.Display\n4.Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			obj.CreateNodes();
			break;
		case 2:
			obj.Bubblesort();
			break;
		case 3:
			obj.display();
			break;
		default:
			cout<<"Please enter correct option"<<endl;
			break;
		}
	} while (choice != 4);
}
