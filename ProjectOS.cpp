#include <iostream>
#include<string>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<ctype.h>
#include<string.h>
#include<cstdio>
#include<string>
using namespace std;
string Method = "Null", Preemptive = "OFF";
int choice = 0;


// Linked List Declaration (start)
typedef struct node{
	int data;
	struct node *next; // i think without struct
}node1;

node * createNode(int);
node * insertBack( node *, int);
node * insertFront( node *, int);
void insertAfter( node *, int);
void deleteAfter( node *);
node *deleteFront( node *);
node *deleteBack( node *);
void display(struct node *);
//LL end


int menu();
void MethodMenu();
void FCFS();
void SJF();

int main()
{
    int i = 0;
    fstream createFile("Inputs.txt",ios::app); //opens a text file for appending. (appending means to add text at the end).
    cout<<"Please, before using the application make sure you save the inputs \nin the created Inputs.txt file at the same directory!\n\n";


    for(i=0;i<5;)            //for loop to make it run until quitting
	{
        choice = 0;
		choice = menu();

	    if(choice==1)
	    {
            MethodMenu();
	    }
	    else if (choice==2) //ON Off
	    {
            if(Preemptive == "OFF")
            Preemptive =  "ON";
            else if(Preemptive == "ON")
            Preemptive =  "OFF";
		}
	    else if(choice==3)
	    {
            if (Method == "FCFS")
            {
                FCFS();
            }
            else if (Method == "SJF")
            {
                SJF();
            }
		}
		else if(choice==4)
		{

		}


	}
    return 0;
}
int menu() //menu function
{
    cout<<endl<<"Menu {CPU Scheduler Simulator}:\n\n1- Scheduling Method ("<<Method<<")\n\n2- Preemptive Method ("<<Preemptive<<")\n\n3- Show Result\n\n4- End Program\n";
    int x;
    cin>>x;
    return x;
}

void MethodMenu()
{
    cout<<"Choose A Scheduling Method By Number:- \n1-First Come First Serve \n2-Shortest Job First \n3-Priority \n4-Round Robin";
    int num;
    cin>>num;
    if (num == 1)
    {
        Method = "FCFS";
    }
    else if(num == 2)
    {
        Method = "SJF";
    }
    else if(num == 3)
    {
        Method = "Priority";
    }
    else if(num == 4)
    {
        Method = "RR";
    }
}

void FCFS()
{
    ifstream createFile("Inputs.txt");
    node *header = NULL;
    char x;
    while(createFile.get(x)) //read every char in a file
    {
        if ( isdigit(x) ) // to ignore :
        {
            int ix = x - '0'; //to convert char to int
            header=insertBack(header,ix);
        }

    }

    display(header);
    cout<<endl;
    node *fcfs = NULL;
//

    int burst = 0;

    node *temp = header;


    int o = 3;

    while (temp != NULL)
    {

        if(o%3 ==0)
        {
            burst = temp->data;
            fcfs = insertBack(fcfs,burst);
        }


        o+=1;
        temp=temp->next;

    }

    cout << endl;
    display(fcfs);
    temp = fcfs;
    float i = 1, total = 0;
    cout<<"Waiting Times:-"<<endl;
    while (temp != NULL)
    {


        cout<<"p"<<i<<": "<<total<<endl;
        total+= temp->data;
        i++;
        temp=temp->next;
    }
    cout<<total<<"wheew"<<i;
    float avg = 0;
    avg = total/(i-1);
    cout<<"Average Waiting Time: "<<avg;
}

void SJF()
{
    ifstream createFile("Inputs.txt");
    node *header = NULL;
    char x;
    while(createFile.get(x)) //read every char in a file
    {
        if ( isdigit(x) ) // to ignore :
        {
            int ix = x - '0'; //to convert char to int
            header=insertBack(header,ix);
        }

    }

    display(header);
    cout<<endl;
    node *sjf = NULL;
//

    int burst = 0;

    node *temp = header;


    int o = 3, size = 0;

    while (temp != NULL)
    {

        if(o%3 ==0)
        {
            burst = temp->data;
            sjf = insertBack(sjf,burst);
        }


        o+=1;
        temp=temp->next;
        size++;
    }

    cout << endl;
    display(sjf);

    int j=0, i=0, min = 0;
    node *avoidError = sjf;
   //temp = sjf;
	for (i=0;i < size - 1 ;i++)
	{
		min = i ;
		for (j = i+1;j<size;j++)
		{
			if ( sjf->data < avoidError->data )
			{
				x = sjf->data;
				sjf->data = avoidError->data;
				avoidError->data = x;


			}

			avoidError->next = avoidError->next->next;
			temp = avoidError;
			avoidError = NULL;
			//avoidError = temp->next;
		}

		//swap (a[i], a[min]);
	}
	cout<<endl<<temp<<endl;
				cin>>i;
}



//  Linked List functions

node * createNode(int item)
{
     node * temp;
     temp = (struct node *) malloc(sizeof(node));
     temp->data = item;
     temp->next = NULL;
     return temp;
}

node * insertBack(struct node *header, int data)
{
       // 1. Create node
       node * temp = createNode(data);
       node * headertemp;
       // 2. Check if the list is empty
       if (header == NULL)
       {
          header = temp;
          return header;
       }
       // 3. Find the end of list
       headertemp=header;

       while(headertemp->next != NULL)
            headertemp=headertemp->next;
       // 4. Connect new node to the end of list.
       headertemp->next = temp;
       // 5. Return header
       return header;
}

node * insertFront(struct node *header, int data)
{
     // 1. Create node
     struct node * temp = createNode(data);
     // 2. Connect new node to the front of the list
     temp->next = header;
     // 3. Change the header value so that it points
     // to the beginning of the LL.
     header=temp;
     // 4. Return new header
     return header;
}

void insertAfter(struct node *afterNode, int data)
{
     // 1. Create node
     struct node * temp = createNode(data);
     // 2. Connect new node after the AfterNode
     temp->next=afterNode->next;
     // 3. Change the AfterNode pointer value so
     //that it points to the new node.
     afterNode->next = temp;
}

void deleteAfter(struct node *afterNode)
{
    struct node *temp;
	//If next node of afterNode or afterNode is NULL,
	//we cant remove anything
	if(afterNode->next==NULL || afterNode==NULL)
        return;
    //Set temp to next node of afterNode
    temp =afterNode->next;
    //Set afterNode's next node to temp's next node.
    afterNode->next=temp->next;
    free(temp);
}

node *deleteFront(struct node *header)
{
    //Create temp node
    struct node *temp;
    //Check if the list is empty
    if(header==NULL){
        return header;
    }
	//Assign header to temp
    temp=header;
    //Point header, to next node
	header= header->next;
	//Free temp
    free(temp);
    //Return new header
    return header;
}

node *deleteBack(struct node *header)
{
    //Create a temp node (this will hold node that is going to be removed)
    // Create headertemp node (this node will be used to iterate through nodes, so we can
    // find the last node.
    struct node *temp, *headertemp;
    //Check if list is empty
    if(header==NULL){
        return header;
    }
    //Assign header to headertemp
	headertemp=header;
    //Iterate through the list and set headertemp to last node.
	while(headertemp->next->next!=NULL){
        headertemp =headertemp->next;
	}
    //assign header temp's next node to temp (which is the node before end node)
	temp=headertemp->next;
	//set next node of headertemp to NULL, this will remove the node.
    headertemp->next=NULL;
    //Free temp
    free(temp);
    //Return new header
	return header;

}

void display(struct node *header)
{
    if (header == NULL)
        cout << "List is empty" << endl;

    struct node *temp = header;

    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp=temp->next;
    }
    cout << endl;
}

//LL end
