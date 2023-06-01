#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

class StudentRecord
{
	string rn, name, add;
	char div;
	ofstream f;
	public:
		void addStudent()
		{
			ofstream f("stud.txt", ios::app);
			cout<<"Enter roll number of the student: ";           //rollno     //name 
			cin>>rn;                                                    //10     hrushikesh 
			cout<<"Enter name of the student: ";
			cin>>name;
			cout<<"Enter division of the student: ";
			cin>>div;
			cout<<"Enter address of the student: ";
			cin>>add;
			
			f<<rn<<setw(20)<<name<<setw(20)<<div<<setw(20)<<add<<endl;           //setw() is a manipulator which 'sets width'
			f.close();
			
			cout<<"RECORD ADDED SUCCESSFULLY."<<endl;
		}
		
		void deleteStudent()
		{
			ifstream f("stud.txt");
			string line;
			cout<<"Enter the roll number to delete: ";
			cin>>rn;
			
			string data;
			
			while(getline(f, line))
			{
				if(line.find(rn)==string::npos)
				{
					data+=line;
					data+="\n";
				}
			}
			ofstream f1("stud.txt", ios::out);
			f1<<data;
			f1.close(); 
			cout<<"RECORD DELETED SUCCESSFULLY.";
		}
		
		void searchStudent()
		{
			string line;
			ifstream f("stud.txt");
			cout<<"Enter roll number to search: ";
			cin>>rn;
			
			bool found = false;          //not found
			
			while(getline(f, line))
			{
				if(line.find(rn)!=string::npos)        //find whether the roll number is on the line or not
				{
					cout<<"Student details:\n"<<line<<endl;
					found=true;              //found
					break;
				}
			}
			if(!found)
			{
				cout<<"Student doesn't exist.";
			}
			f.close();
		}
		
		void printStudent()
		{
			ifstream f("stud.txt");
			string line;
			cout<<endl<<"PRINTING FILE DATA..."<<endl;
			while(getline(f, line))                      //data to be taken from 'f' and put into 'line'
			{
				cout<<line<<endl;
			}
			cout<<"PRINTING COMPLETE."<<endl;
			f.close();
		}
};

int main()
{
	ofstream f("stud.txt", ios::out);
	f<<"ROLL NO."<<setw(20)<<"NAME"<<setw(20)<<"DIVISION"<<setw(20)<<"ADDRESS"<<endl;
	f.close();
	
	StudentRecord s;
	int ch;
	while(1)
	{
		cout<<"\n\n1.ADD STUDENT\n2.DELETE STUDENT\n3.SEARCH STUDENT\n4.PRINT DATA\n5.EXIT"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.addStudent();
				break;
			case 2: 
				s.deleteStudent();
				break;
			case 3:
				s.searchStudent();
				break;
			case 4: 
				s.printStudent();
				break;
			case 5:
				exit(1);
			default:
				cout<<"Incorrect choice. Please enter a valid choice."<<endl;
				break;
		}
	}
}
