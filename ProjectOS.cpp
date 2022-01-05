//   -std=c++11         add this when compiling "Runme"
// Ahmed Esmail    21906571



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
#include<sstream>
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
void PRIORITY();

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
            else if (Method == "Priority")
            {
                PRIORITY();
            }
		}
		else if(choice==4)
		{
            FCFS();
            SJF();
            PRIORITY();


            return 0;

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
    char x,y;
    string trying="";
    while(createFile.get(x)) //read every char in a file
    {
        if ( isdigit(x) ) // to ignore :
        {
            y = x;
            createFile.get(x);
            if ( isdigit(x) )
            {
                string trying = "";
                trying += y;
                trying += x  ;


                cout<<trying<<"look ";
                stringstream wow(trying);
                int wow2 = 0;
                wow >> wow2;
                header=insertBack(header,wow2);
            }
            else
            {
                int ix = y - '0'; //to convert char to int
                header=insertBack(header,ix);
            }


        }

    }

    //display(header);
    cout<<endl;
    node *fcfs = NULL;
//

    int burst = 0;

    node *temp = header;


    int o = 3;
//add to LL
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
   // display(fcfs);
    temp = fcfs;
    float i = 1, total = 0, result=0;
    cout<<"Waiting Times:- FCFS"<<endl;
    //calculate FCFS
    while (temp != NULL)
    {


        cout<<"p"<<i<<": "<<total<<endl;
        result+= total;
        total+= temp->data;

        i++;
        temp=temp->next;
    }
    float avg = 0;
    avg = result/(i-1);
    cout<<"Average Waiting Time: "<<avg<<endl<<endl;
}

void SJF() //none preemptive
{
    ifstream createFile("Inputs.txt");
    node *header = NULL;
    char x,y;
    string trying="";
    while(createFile.get(x)) //read every char in a file
    {
        if ( isdigit(x) ) // to ignore :
        {
            y = x;
            createFile.get(x);
            if ( isdigit(x) )
            {
                string trying = "";
                trying += y;
                trying += x  ;


                cout<<trying<<"look ";
                stringstream wow(trying);
                int wow2 = 0;
                wow >> wow2;
                header=insertBack(header,wow2);
            }
            else
            {
                int ix = y - '0'; //to convert char to int
                header=insertBack(header,ix);
            }


        }

    }

   // display(header);
    cout<<endl;
    node *sjf = NULL;
//

    int burst = 0;

    node *temp = header;


    int o = 3, size = 0;
//ADD to LL
    while (temp != NULL)
    {

        if(o%3 ==0)
        {
            burst = temp->data;
            sjf = insertBack(sjf,burst);
            size++;
        }


        o+=1;
        temp=temp->next;

    }


    int j=0, i=0;
    //this five line of code will remember the order of the processes (p1, p2, ...)
    node *order =NULL;

    for(i = 1; i <size+1; i++)
    {
        order = insertBack(order,i);
    }
   // cout<<endl<<"Order is :";
   // display(order);
    node *temp5 = order;//
    node *temp6 = order;//order temps
    //end of ordering LL






    //cout << endl;
    //display(sjf);

    //to sort a LL
    node *temp1 = sjf;
    node *temp2 = sjf;
    for(i = 0; i <size; i++)
    {
        for (int j = 0; j <size-1; j++)
        {
            if(temp2->data < temp1->data)
            {
                int x = temp2->data;
                temp2->data = temp1->data;
                temp1->data = x;

                int x3 = temp6->data;       //for order
                temp6->data = temp5->data;
                temp5->data = x3;
            }
            temp1 = temp1->next;
            temp5 = temp5->next;//order
        }
        temp1 = sjf;
        temp2 = sjf->next;

        temp5 = order;//order
        temp6 = order->next;//order
        for (int k = 0; k<i; k++)
        {
            temp2 = temp2->next;
            temp6 = temp6->next;
        }
    }

  //  cout<<"it is working!!"<<endl;
   // display(sjf);

 //   cout<<"order after !!"<<endl;
   // display(order);
    //calculate SJF (none preemptive)
    temp = sjf;
    float z = 1, total = 0, result=0;
    cout<<"Waiting Times:- SJF non-preemptive"<<endl;
    node *noOrder = NULL;
    while (temp != NULL)
    {

        noOrder = insertBack(noOrder,total);
       // cout<<"p"<<z<<": "<<total<<endl;
        result+=total;
        total+= temp->data;
        z++;
        temp=temp->next;

    }


    temp1 = order;
    temp2 = order;
    node *temp3 = noOrder;
    node *temp4 = noOrder;
    for(i = 0; i <size; i++)
    {
        for (int j = 0; j <size-1; j++)
        {
            if(temp2->data < temp1->data)
            {
                int x = temp2->data; //sort the order to show the result in 1 2 3 rather than 2 1 3
                temp2->data = temp1->data;
                temp1->data = x;

                int x2 = temp4->data;//sort results with the same order of question (order variable)
                temp4->data = temp3->data;
                temp3->data = x2;

            }
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        temp1 = order;
        temp2 = order->next;

        temp3 = noOrder;
        temp4 = noOrder->next;
        for (int k = 0; k<i; k++)
        {
            temp2 = temp2->next;
            temp4 = temp4->next;
        }
    }

    float z1 = 1, total2 = 0;
    temp1 = noOrder;
    while (temp1 != NULL)
    {

        cout<<"p"<<z1<<": "<<temp1->data<<endl;
        z1++;
        temp1=temp1->next;
    }




    float avg = 0;
    avg = result/(z-1);
    cout<<"Average Waiting Time: "<<avg<<endl<<endl;



}

void PRIORITY() //none preemptive
{
    ifstream createFile("Inputs.txt");
    node *header = NULL;
    char x,y;
    string trying="";
    while(createFile.get(x)) //read every char in a file
    {
        if ( isdigit(x) ) // to ignore :
        {
            y = x;
            createFile.get(x);
            if ( isdigit(x) )
            {
                string trying = "";
                trying += y;
                trying += x  ;


                cout<<trying<<"look ";
                stringstream wow(trying);
                int wow2 = 0;
                wow >> wow2;
                header=insertBack(header,wow2);
            }
            else
            {
                int ix = y - '0'; //to convert char to int
                header=insertBack(header,ix);
            }


        }

    }

    //display(header);
    //cout<<endl;




    node *BURST = NULL;
    node *PRIORITY = NULL;
//

    int holder = 0;

    node *tempBurst = header;
    node *tempPriority = header;

    int o = 3, o2 = 1, size = 0;
//ADD to LL
    while (tempPriority != NULL)
    {


        if(o%3 ==0)
        {
            holder = tempBurst->data;
            BURST = insertBack(BURST,holder);
        }
        if (o2%3 ==0)
        {
            holder = tempPriority->data;
            PRIORITY = insertBack(PRIORITY,holder);
            size++;
        }

        o+=1;
        o2+=1;
        tempBurst=tempBurst->next;
        tempPriority=tempPriority->next;

    }
   // cout<<endl<<"Burst: ";
  //  display(BURST);
  //  cout<<endl<<"Priority: ";
   // display(PRIORITY);


    int j=0, i=0;
    //to sort a LL
    node *temp1 = PRIORITY; //I will sort according to priority
    node *temp2 = PRIORITY;
    node *temp3 = BURST;
    node *temp4 = BURST;//to change burst also with respect to priority


    //this five line of code will remember the order of the processes (p1, p2, ...)
    node *order =NULL;

    for(i = 1; i <size+1; i++)
    {
        order = insertBack(order,i);
    }
    //cout<<endl<<"Order is :";
   // display(order);
    node *temp5 = order;//
    node *temp6 = order;//order temps
    //end of ordering


    //sort LL
    for(i = 0; i <size; i++)
    {
        for (int j = 0; j <size-1; j++)
        {
            if(temp2->data < temp1->data)
            {
                int x = temp2->data;//sort priority
                temp2->data = temp1->data;
                temp1->data = x;

                int x2 = temp4->data;//sort burst with exact order of priority
                temp4->data = temp3->data;
                temp3->data = x2;

                int x3 = temp6->data;       //for order
                temp6->data = temp5->data;
                temp5->data = x3;

            }
            temp1 = temp1->next;//priority var next
            temp3 = temp3->next;//burst var next
            temp5 = temp5->next;//order var next
        }
        temp1 = PRIORITY;   //priority var
        temp2 = PRIORITY->next;   //priority var next

        temp3 = BURST;      //burst var
        temp4 = BURST->next;   //burst var next

        temp5 = order;//order var
        temp6 = order->next;//order var next
        for (int k = 0; k<i; k++)
        {
            temp2 = temp2->next;//priority
            temp4 = temp4->next;//burst
            temp6 = temp6->next;//order
        }
    }
   // cout<<endl<<"BURST sorted: ";
 //   display(BURST);
//    cout<<endl<<"Priority sorted: ";
 //   display(PRIORITY);
 //   cout<<endl<<"Order is :";
//    display(order);
    //end of sorting



    //now we calculate
    //1- without order of p1, p2,...
    temp1 = BURST;
    float z = 1, total = 0, result = 0;
    cout<<"Waiting Times:- Priority non-preemptive"<<endl;
    node *noOrder = NULL;
    while (temp1 != NULL)
    {

        //int or1 = order->data;//this line is useless??
      //  cout<<"p"<<or1<<": "<<total<<endl;
        noOrder = insertBack(noOrder,total);
        result+= total;
        total+= temp1->data;

        z++;
        temp1=temp1->next;
      //  order = order->next;
    }
//


    //with order

        //to sort a LL with sorting the order also
    temp1 = order;
    temp2 = order;
    temp3 = noOrder;
    temp4 = noOrder;
    for(i = 0; i <size; i++)
    {
        for (int j = 0; j <size-1; j++)
        {
            if(temp2->data < temp1->data)
            {
                int x = temp2->data; //sort the order to show the result in 1 2 3 rather than 2 1 3
                temp2->data = temp1->data;
                temp1->data = x;

                int x2 = temp4->data;//sort results with the same order of question (order variable)
                temp4->data = temp3->data;
                temp3->data = x2;

            }
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        temp1 = order;
        temp2 = order->next;

        temp3 = noOrder;
        temp4 = noOrder->next;
        for (int k = 0; k<i; k++)
        {
            temp2 = temp2->next;
            temp4 = temp4->next;
        }
    }







      //  int or1 = noOrder->data;
       // cout<<"p"<<or1<<": "<<total<<endl;


    //show results using past outputs
    float z1 = 1, total2 = 0;
    temp1 = noOrder;
    while (temp1 != NULL)
    {

        cout<<"p"<<z1<<": "<<temp1->data<<endl;
        //total2+= temp1->data;
        z1++;
        temp1=temp1->next;



        /*int or1 = order->data;
       cout<<"p"<<or1<<": "<<total<<endl;
        noOrder = insertBack(noOrder,total);
        result+= total;
        total+= temp1->data;

        z++;
        temp1=temp1->next;
      //  order = order->next;*/
    }
    float avg = 0;
    avg = result/(z1-1);

    cout<<"Average Waiting Time: "<<avg<<endl<<endl;

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
