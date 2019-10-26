#include<iostream>
#include<string>
#include <fstream>
#include <stdio.h>
using namespace std;
class patient{
	public:
		string firstname;
		string lastname;
		int age;
		string gender;
		string status;
		int id;
		static int number;
	void getdata();
	void changestatus();
	void putdata();
	void putdatatofile(string filename);
};

int patient::number=1700;

void patient::getdata(){
	cout<<"enter patients firstname"<<endl;
	cin>>firstname;
	cout<<"enter patients lasttname"<<endl;
	cin>>lastname;
	cout<<"enter patients age"<<endl;
	cin>>age;
	cout<<"enter patients gender"<<endl;
	cin>>gender;
	status="admitted";
	cout<<"patient status:"<<status<<endl;
	id=number;
	cout<<"patient id:"<<id<<endl;
	number++;
	
}

void patient::changestatus(){
	if (status=="admitted"){
		status="discharged";
	} else {
		status="admitted";
	}
}

void patient::putdata(){
	if(status=="admitted"){
		cout<<"Firstname: "<<firstname<<endl<<endl;
		cout<<"lastname:"<<lastname<<endl<<endl;
		cout<<"age:"<<age<<endl<<endl;
		cout<<"gender:"<<gender<<endl<<endl;
		cout<<"status:"<<status<<endl<<endl;
		cout<<"id:"<<id<<endl<<endl;
		
	}
}
void patient::putdatatofile(string filename){
	ofstream file;
	file.open(filename, ios::app);
	file<<firstname<<endl;
	file<<lastname<<endl;
	file<<age<<endl;
	file<<gender<<endl;
	file<<status<<endl;
	file<<id<<endl<<endl;
	file.close();
}

int main(){
	char filename[] = "hms.txt";
		ifstream file;
		file.open(filename);
		patient h;
		while (file>>h.firstname>>h.lastname>>h.age>>h.gender>>h.status>>h.id)
		{
			patient::number=h.id+1;
		}
	while (true)
	{
		int options;
		system("cls");
		cout<<"HOSPITAL MANAGEMENT SYSTEM"<<endl;
		cout<<"1. register patient"<<endl;
		cout<<"2. display all patients"<<endl;
		cout<<"3. search for  patient"<<endl;
		cout<<"4. change patient status"<<endl;
		cout<<"5. search by gender"<<endl;
		cout<<"6. delete patient record"<<endl;
		cout<<"7. end program!"<<endl;
		cin>>options;
		if (options==1){
			system("cls");
			patient h;
			h.getdata();

			h.putdatatofile(filename);
		} else if (options==2){
			system("cls");
			ifstream file;
			file.open(filename);
			patient h;
			while (file>>h.firstname>>h.lastname>>h.age>>h.gender>>h.status>>h.id)
			{
				if(h.status=="admitted"){
					h.putdata();
				}
			}
			file.close();		
		} else if (options==3){
			system("cls");
			cout<<"who are you searching for";
			string search;
			cin>>search;
			ifstream file;
			file.open(filename);
			patient h;
			while (file>>h.firstname>>h.lastname>>h.age>>h.gender>>h.status>>h.id)
			{
				if (h.firstname==search){
					h.putdata();
				}
			}
			file.close();
		} else if (options==4){
			system("cls");
			cout<<"whose status do you want to change?";
			string search;
			cin>>search;
			ifstream file;
			file.open(filename);
			patient h;
			while (file>>h.firstname>>h.lastname>>h.age>>h.gender>>h.status>>h.id)
			{
				if (h.firstname==search){
					h.changestatus();
				}
				h.putdatatofile("temp.txt");
			}
			file.close();
			remove(filename);
			rename("temp.txt", filename);
			
		}else if(options==5){
			system("cls");
			cout<<"which gender are you searching for";
			string gsearch;
			cin>>gsearch;
			ifstream file;
			file.open(filename);
			patient h;
			while (file>>h.firstname>>h.lastname>>h.age>>h.gender>>h.status>>h.id)
			{
				if (h.gender==gsearch){
					h.putdata();
				}
			}
			file.close();
	}else if(options==6){
		system("cls");
		cout<<"who do you want to delete"<<endl;
		int id;
		cout<<"enter id to delete"<<endl;
		cin>>id;
		ifstream file;
		file.open(filename);
		patient h;
		while (file>>h.firstname>>h.lastname>>h.age>>h.gender>>h.status>>h.id)
		{
			if (h.id!=id){
				h.putdatatofile("temp.txt");
			}
		}
		file.close();
		remove(filename);
		rename("temp.txt", filename);
	}else if(options==7){
		return 0;
	}else{
		cout<<"invalid option"<<endl;
	}
		
		system("pause");	
}
}


