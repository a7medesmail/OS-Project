#include <iostream>

using namespace std;
void menu(int *choice);
int main()
{
    int choice = 0, i = 0;
    menu(&choice);
    for(i=0;i<5;)            //for loop for make it runs until quit
	{
		menu(&choice);

	    if(choice==1)
	    {

	    }
	    else if (choice==2)
	    {

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
void menu(int *choice)
{
    cout<<endl<<"Menu {CPU Scheduler Simulator}:\n\n1- Scheduling Method (None)\n\n2- Preemptive Method (Off)\n\n3- Show Result\n\n4- End Program\n";
    cin>>*choice;
}

