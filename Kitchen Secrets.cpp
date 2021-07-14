//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
 #include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
using namespace std;
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
class project
{
	int rno;
	char name[50];
	char course[50];
	char cuisine[50];
	char type[50];
	int  ct;
	int  ni;
	char ci[40];
	int  calories;
public:
	void accept();	//function to get data from user
	void display();  //function to display data
     int retnumber() { return(rno);} // return function for recipe number
};
void project::accept()
{ 
    cout<<"\n Enter The recipe No. : ";
	cin>>rno;
	cout<<"\n Enter name : ";
	cin.ignore();
	gets(name);
	cout<<"\n Enter course : ";
	gets(course);
	cout<<"\n Enter cuisine : ";
	gets(cuisine);
	cout<<"\n Enter type(veg/non-veg) : ";
	gets(type);
	cout<<"\n Enter cook time(minutes) :";
	cin>>ct;
	cout<<"\n Enter number of ingredients : ";
	cin>>ni;
	cout<<"\n Enter core ingredient : ";
	cin.ignore();
	gets(ci);
	cout<<"\n Enter calories : ";
	cin>>calories;
	cout<<"\n\n Recipe book updated.."; 
}
void project::display() 
{ 
	cout<<"\n\n Recipe Number : "<<rno;
	cout<<"\n\n Recipe  Name : ";
	cout<<name;
	cout<<"\n\n Course : ";
	cout<<course;
	cout<<"\n\n Cuisine : ";
	cout<<cuisine;
	cout<<"\n\n Type : ";
	cout<<type;
	cout<<"\n\n Cook time(minutes) : "<<ct;
	cout<<"\n\n Number of ingredients : "<<ni;
	cout<<"\n\n Core ingredient : ";
	cout<<ci;
	cout<<"\n\n Calories : "<<calories;
}
char choice;
project p;
fstream file, tempfile;

void create() //function to create the file
{
	system("cls");
	char ch='y';
	file.open("rec.dat",ios::out|ios::binary);
	cout<<"\n Recipe book created...\n";
	do
	{
		p.accept();
		file.write((char*)&p, sizeof(p));
		cout<<" Do you want to enter more recipess"<<endl;
		cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	file.close();
}

	void display() //function to read the file
	{   system("cls");
		file.open("rec.dat",ios::in|ios::binary);
		while(file.read((char*)&p, sizeof(p)))
		{
			p.display();
		}
		file.close();
	}
	
	void search_recipe() //function to search a recipe
	{   system("cls");
		int recipno;
		file.open("rec.dat",ios::in|ios::binary);
		cout<<" Enter recipe number to be searched: ";
		cin>>recipno;
		while(file.read((char*)&p, sizeof(p)))
		{
			if(p.retnumber()==recipno)
			{  cout<<"\nRecipe details: ";
				p.display();		
			}
		}
	}
	
	
	void insertatn()    //function to insert a recipe at any place
	{   system("cls");
		ifstream file("rec.dat", ios::in);
	ofstream fout("temp.dat", ios::out);
	char last='y';
	cout<<" Enter recipe information whose record is to be inserted\n";
	p.accept();
	while(!file.eof())
	{
		file.read((char *)&p, sizeof(p));
		if(p.retnumber()<=p.retnumber())
		{
			fout.write((char *)&p, sizeof(p));
			last = 'n';
			break;
		}
		else
		{
			fout.write((char *)&p, sizeof(p));
		}
	}
	if(last == 'y')
	{
		fout.write((char *)&p, sizeof(p));
	}
	else if(!file.eof())
	{
		while(!file.eof())
		{
			file.read((char *)&p, sizeof(p));
			fout.write((char *)&p, sizeof(p));
		}
	}
	cout<<"\n Recipe book updated..";
	file.close();
	fout.close();
	remove("rec.dat");
	rename("temp.dat", "rec.dat");
	file.open("recin.dat", ios::in);
	}
	
	void deleteone() //function to delete first recipe
	{    system("cls");
		fstream temp;
		file.open("rec.dat",ios::in| ios::binary);
		temp.open("new.dat",ios::out|ios::binary);
		file.read((char*)&p,sizeof(p));
		while(file.read((char*)&p,sizeof(p)));
		{
			temp.write((char*)&p,sizeof(p));
			cout<<"\n Recipe deleted..";
		}
		temp.close();
		file.close();
		remove("rec.dat");
		rename("new.dat","recin.dat");
			}
 void deletelast() //function to delete last recipe
	{	system("cls");
    fstream temp;
		file.open("rec.dat",ios::in| ios::binary);
		temp.open("new.dat",ios::out|ios::binary);
		file.seekg(0,ios::end);
		int last=file.tellg();
		int s=sizeof(p);
		int lastrec=last/s;
		int r=1;
		file.seekg(0);
		while(r<lastrec)
		{
			file.read((char*)&p,sizeof(p));
			temp.write((char*)&p,sizeof(p));
			r++;
			cout<<"\n Recipe deleted..";
		}
		temp.close();
		file.close();
		remove("rec.dat");
		rename("new.dat","rec.dat");
			}		
			
	void deleten()  //function to delete any recipe
	{	system("cls");
         fstream temp;
		file.open("rec.dat",ios::in| ios::binary);
		temp.open("new.dat",ios::out|ios::binary);
		int r=1;
		int n;
		cout<<" Enter recipe number to be deleted:" ;
		cin>>n;
		while(file.read((char*)&p,sizeof(p)))
		{
			if(r!=n)
				temp.write((char*)&p,sizeof(p));
			r++;
			cout<<"\n Recipe deleted..";
		}
		temp.close();
		file.close();
		remove("rec.dat");
		rename("new.dat","rec.dat");
		}
	
	
	void modifyone()  //function to modify first recipe
	{       system("cls");
        	fstream temp;
		file.open("rec.dat",ios::in| ios::binary);
		temp.open("new.dat",ios::out|ios::binary);
		file.read((char*)&p,sizeof(p));
		while(file.read((char*)&p,sizeof(p)));
		{
			cout<<" Enter new information  ";
				p.accept();
				temp.write((char*)&p,sizeof(p));
				cout<<"\n Recipe modified..";
		}
		temp.close();
		file.close();
		remove("rec.dat");
		rename("new.dat","rec.dat");
			}
			
				
	void modifylast()  //function to modify last recipe
	{    system("cls");
        fstream temp;
		file.open("rec.dat",ios::in|ios::binary);
		temp.open("new.dat",ios::out|ios::binary);
		file.seekg(0,ios::end);
		int last=file.tellg();
		int s=sizeof(p);
		int lastrec=last/s;
		int r=1;
		file.seekg(0);
		while(r==lastrec)
		{
				cout<<" Enter new information: ";
				p.accept();
				temp.write((char*)&p,sizeof(p));
				cout<<"\n Recipe modified..";
		}
		temp.close();
		file.close();
		remove("rec.dat");
		rename("new.dat","rec.dat");
	}
	
	void modifyn()  //function to modify any recipe
	{	fstream temp;
		file.open("rec.dat",ios::in| ios::binary);
		temp.open("new.dat",ios::out|ios::binary);
		int r=0;
		int n;
		system("cls");
		cout<<"\n Enter recipe number to be edited:" ;
		cin>>n;
		while(file.read((char*)&p,sizeof(p)))
		{
			if(r==n)
			{
				cout<<"\n Enter new information: ";
				p.accept();
				temp.write((char*)&p,sizeof(p));
				cout<<"\n Recipe modified..";
			}
		}
		temp.close();
		file.close();
		remove("rec.dat");
		rename("new.dat","rec.dat");
	}
void intro()  //introduction function
   {
  cout<<"\n\n\n\t*****************************************************";
  cout<<"\n\n\t*            Computer Science Project               *";
  cout<<"\n\n\t*               ==================                  *";
  cout<<"\n\n\t*                 Kitchen Secrets                   *";
  cout<<"\n\n\t*               ==================                  *";
  cout<<"\n\n\t*                    Made By:-                      *";
  cout<<"\n\n\t*            Rahul Goyal & Vernika Gupta            *";
  cout<<"\n\n\t*                       12-B                        *";
  cout<<"\n\n\t*****************************************************";
  cout<<"\n\n\n\tPress Enter to continue....";
  }

int main()  //main function
{
	int choice;
	intro();
	getch();
	do{
	system("cls");
    cout<<"\t               ==================                  ";
    cout<<"\n\t                   Features                        ";
    cout<<"\n\t               ==================                  ";
    cout<<"\n 1.To create a recipe and enter records"<<endl;
    cout<<"\n 2.To view all recipes"<<endl;
    cout<<"\n 3.To search a recipe"<<endl;
    cout<<"\n 4.Insert a recipe at nth position, accept n from user"<<endl;
    cout<<"\n 5.Delete the first recipe"<<endl;
    cout<<"\n 6.Delete the last recipe"<<endl;
    cout<<"\n 7.Delete the any recipe"<<endl;
    cout<<"\n 8.Modify the first recipe"<<endl;
    cout<<"\n 9.Modify the nth record"<<endl;
    cout<<"\n 10.Modify the last recipe"<<endl;
    cout<<"\n Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    	case 1: create();break;
    	case 2: display();break;
    	case 3: search_recipe();break;
    	case 4: insertatn();break;
    	case 5: deleteone();break;
    	case 6: deletelast();break;
    	case 7: deleten();break;
    	case 8: modifyone();break;
    	case 9: modifylast();break;
    	case 10: modifyn();break;
    	case 0 : ;
	}
}while(!0);
	cout<<"\n\t\t**************";

	cout<<"\n End of output....";
	getch();
	return 0;
  }
//***************************************************************
//                   END OF PROJECT
//****************************************************************

