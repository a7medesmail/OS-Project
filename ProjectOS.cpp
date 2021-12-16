#include <iostream>
#include<string>
#include<string.h>
using namespace std;
string Method = "Null", Preemptive = "OFF";
int choice = 0;

int menu();
void MethodMenu();


int main()
{
    int i = 0;


    for(i=0;i<5;)            //for loop to make it run until quitting
	{
        choice = 0;
		choice = menu();

	    if(choice==1)
	    {
            MethodMenu();
	    }
	    else if (choice==2)
	    {
            if(Preemptive == "OFF")
            Preemptive =  "ON";
            else if(Preemptive == "ON")
            Preemptive =  "OFF";
		}
	    else if(choice==3)
	    {

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
