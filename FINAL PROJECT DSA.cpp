#include<iostream>
#include<windows.h>   
//for file handling
#include<fstream>
#include <string>
using namespace std;
//class for entering used car data
class Node 
{
public:
	int car_id;
	string car_name;
	int car_price;
	string car_model;
	Node* next;
	Node(int id, string name, int price, string model)
	{
		this->car_id = id;
		this->car_name = name;
		this->car_price = price;
		this->car_model = model;
		this->next = NULL;
	}

};
//class for entering Applied for car data
class Mode
{
public:
	string ncar_name;
	int ncar_price;
	string ncar_model;
	Mode* nnext;
	Mode(string nname, int nprice, string nmodel)
	{
		//this->car_id=id;
		this->ncar_name = nname;
		this->ncar_price = nprice;
		this->ncar_model = nmodel;
		this->nnext = NULL;
	}

};

//insert data for used cars
void insert(Node*& head, int car_id, string car_name, int car_price, string car_model)
{
	fstream file;
	if (head == NULL)
	{
		Node* temp = new Node(car_id, car_name, car_price, car_model);
		head = temp;
	}
	Node* temp = new Node(car_id, car_name, car_price, car_model);
	temp->next = head;
	head = temp;
	//store data in file
	file.open("SCar.txt", ios::app | ios::out);
	file << car_id << " " << car_name << " " << car_price << " " << car_model << endl;
	file.close();


}

//insert data for appliedfor cars
void NCinsert(Mode*& hhead, string ncar_name, int ncar_price, string ncar_model)
{
	fstream file;
	if (hhead == NULL)
	{
		Mode* point = new Mode(ncar_name, ncar_price, ncar_model);
		hhead = point;
	}
	Mode* ttemp = new Mode(ncar_name, ncar_price, ncar_model);
	ttemp->nnext = hhead;
	hhead = ttemp;
	file.open("NCar.txt", ios::app | ios::out);
	file << "New cars detatil is" << endl;
	file << "CAR NAME:" << endl;
	file << ttemp->ncar_name << endl;
	file << endl;
	file << "CAR PRICE:" << endl;
	file << ttemp->ncar_price;
	file << endl;
	file << "CAR MODEL:" << endl;
	file << ttemp->ncar_model;
	file << endl;
	file << "-------------------------" << endl;
	file.close();
}

//function to print all data present in file
void PrintNewCar()
{
	string mytext;
	ifstream MyReadFile("NCar.txt");
	while (getline(MyReadFile, mytext))
	{	
		cout<< mytext << endl;
	}

	MyReadFile.close();

}

//remove data in file handling
void RemoveFileHandlingStudent(int id)
{
	//file read data
	int car_id;
	string car_name;
	int car_price;
	string car_model;

	fstream file, file1;
	file.open("SCar.txt", ios::in);
	{
		file1.open("car2.txt", ios::out | ios::app);

		file >> car_id >> car_name >> car_price >> car_model;
		while (!file.eof())
		{
			if (car_id == id)
			{
				cout << endl << endl << endl << endl;

			}
			else
			{
				file1 << car_id << " " << car_name << " " << car_price << " " << car_model<< endl;
			}
			file >> car_id >> car_name >> car_price >> car_model;

		}
		file1.close();
		file.close();
		remove("SCar.txt");
		rename("car2.txt", "SCar.txt");
	}
}

//delete data in linkedlist

void deleteCar(Node*& head, int id)
{

	if (head->car_id == id)
	{
		Node* temp = head;
		head = head->next;
		cout << "                  " << endl;
		cout << "\t\t\t\t\t ------------------" << endl;
		cout << "\t\t\t\t\t Your deleted Car DETAIL Is..... "<< endl;
		
		cout << "\t\t\t\t\t DELETED CAR ID IS: "<<temp->car_id<<endl;
		cout << "\t\t\t\t\t DELETED CAR Name IS: "<< temp->car_name<<endl;
		cout << "\t\t\t\t\t DELETED CAR Price IS: "<< temp->car_price<<endl;
		cout << "\t\t\t\t\t DELETED CAR Model IS: "<< temp->car_model;
		cout << endl;
		cout << endl;
		RemoveFileHandlingStudent(id);
		delete temp;
	}
	else
	{
		Node* temp;
		Node* curr = head;
		while (curr->next != NULL)
		{
			if (curr->next->car_id == id)
			{
				temp = curr->next;
				curr->next = curr->next->next;
				cout << "\t\t\t\t\t ------------------" << endl;
				cout << "\t\t\t\t\t Your deleted Car Detailed is" << endl;
				cout << "\t\t\t\t\t DELETED CAR ID IS: "<< temp->car_id<<endl;
				cout << "\t\t\t\t\t DELETED CAR Name IS: "<< temp->car_name<<endl;
				cout << "\t\t\t\t\t DELETED CAR Price IS: "<< temp->car_price<<endl;
				cout << "\t\t\t\t\t DELETED CAR Model IS: "<< temp->car_model<<endl;
				RemoveFileHandlingStudent(id);
				delete temp;
				break;
			}
			else
			{
				curr = curr->next;
			}
		}

	}
}

//search data in linked list

void serchName(Node*& head, string name)
{
	Node* temp = head;
	while (temp->next != NULL)
	{

		if (temp->car_name == name)
		{
			cout << "\t\t\t\t\t  CAR ID IS: "<< temp->car_id << endl;
			cout << "\t\t\t\t\t  CAR Name IS: "<< temp->car_name << endl;
			cout << "\t\t\t\t\t  CAR Model IS: "<< temp->car_model << endl;
			cout << "\t\t\t\t\t  CAR Price IS: "<< temp->car_price << endl;
			break;

		}
		else
		{
			cout << "No car available of this name" << endl;
			temp = temp->next;
		}
	}

}

//function used to count total cars

void TotalCar(Node*& head)
{
	Node* temp = head;
	int total = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		++total;
	}
	cout << "\t\t\t\t\t  TOTAL CARS AVAILABLE AT THIS TIME: "<< total << endl;
}

//display linked list data

void display(Node*& head)
{
	int i = 1;
	Node* temp = head;
	while (temp->next != NULL)
	{
		
		cout << "\t\t\t\t\t   Car " << i << " Detail " << endl;
		cout << endl;
		cout << "\t\t\t\t\t   Car id is:";
		cout << temp->car_id;
		cout<<endl;
		cout << "\t\t\t\t\t   Car name is: ";
		cout << temp->car_name;
		cout<<endl;
		cout << "\t\t\t\t\t   Car price  is: ";
		cout << temp->car_price;
		cout<<endl;
		cout << "\t\t\t\t\t   Car model is: ";
		cout << temp->car_model;
		cout << endl;
		temp = temp->next;
		cout << endl;
		i++;
	}
}

int main()
{
	cout << "\t\t\t\t---------------------------------------------------------"<<endl;
	cout << "\t\t\t\t*************CAR-SHOWROOM MANAGMENT SYSTEM****************"<<endl;
	cout << "\t\t\t\t--------------------------------------------------------" << endl;
	cout<<"                                                                   "<<endl;
	cout << "\n\t\t\t\t\t\t*SIGN-UP PAGE*" << endl;
	string username, password;
	cout << "\n\t\t\t\t\t\t ENTER USERNAME: ";
	cin >> username;
	cout << "\n\t\t\t\t\t\t ENTER PASSWORD: ";
	cin >> password;
	cout << "\n\t\t\t\t\tYOUR ID IS CREATING PLEASE WAIT ";
	for (int i = 0; i < 6; i++)
	{
		cout << ".";
		Sleep(500);
	}
	cout << "\n\n\t\t\t\t\tYOUR ID IS CREATED SUCCESFULLY. " << endl;
	Sleep(1000);
	start:
	system("CLS");   //for clear screen
	cout << "\t\t\t\t---------------------------------------------------------"<<endl;
	cout << "\t\t\t\t*************CAR-SHOWROOM MANAGMENT SYSTEM****************"<<endl;
	cout << "\t\t\t\t--------------------------------------------------------" << endl;
	cout<<"                                                                   "<<endl;
	cout << "\n\n\t\t\t\t\t\t*LOGIN PAGE*" << endl;
	string username1, password1;
	cout << "\n\t\t\t\t\t\t ENTER USERNAME: ";
	cin >> username1;
	cout << "\n\t\t\t\t\t\t ENTER PASSWORD: ";
	cin >> password1;
	if (username1 == username && password1 == password)
	{
		Node* head;
		head = NULL;
		Mode* hhead;
		hhead = NULL;
		system("CLS");
		char user;
		cout << "\t\t\t\t---------------------------------------------------------"<<endl;
		cout << "\t\t\t\t*************CAR-SHOWROOM MANAGMENT SYSTEM****************"<<endl;
		cout << "\t\t\t\t--------------------------------------------------------" << endl;
		cout<<"                                                                   "<<endl;
		int i = 0;
		while (i < 10)
		{
			i++;
			cout<<"\t\t\t\tPress 1 to enter Appliedfor cars detail"<< endl;
			cout<<"\t\t\t\t----------------------------------------"<< endl;
			cout<<"\t\t\t\tPress 2 to enter second hand car detail" << endl;
		 	cout<<"\t\t\t\t------------------------------------------"<<endl;
			cout<<"\t\t\t\tPress Any Number for exit"<<endl;
			cout<<"                         "<<endl;
			int choice;
			cout << "   " << endl;
			cout << "\t\t\t\tPlease enter your choice.....";
			cin >> choice;
			system("CLS");

			if (choice == 1)
			{
				cout << "\t\t\t\t---------------------------------------------------------"<<endl;
				cout << "\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM*************"<<endl;
				cout << "\t\t\t\t--------------------------------------------------------" << endl;
				cout<<"                                                                   "<<endl;
				int slute;
				cout<<"\t\t\t\t--------------ENTERING APPLIED-FOR CAR DETAIL---------------"<<endl;
				cout<<"                                                                   "<<endl;
				cout<<"\t\t\t\tHow many new cars available ";
				cin >> slute;
				system("CLS");
				cout << "\t\t\t\t---------------------------------------------------------"<<endl;
				cout << "\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM*************"<<endl;
				cout << "\t\t\t\t--------------------------------------------------------" << endl;
				cout<<"                                                                   "<<endl;
				string nname;
				int pprice;
				string mmodel;
				for (int j = 0; j < slute; j++)
				{

					cout<<"\t\t\t\t------Enter " << j + 1 << " Detail--------" << endl;
					cout<<"                                                                   "<<endl;
					cout<<"\t\t\t\tEnter Car Name: ";
					cin>>nname;
					cout<<"\t\t\t\tEnter Car Price is: " ;
					cin>>pprice;
					cout<<"\t\t\t\tEnter Car Model is: ";
					cin>>mmodel;
					cout<<endl;
					cout<<endl;
					NCinsert(hhead, nname, pprice, mmodel);

				}
				system("CLS");
				cout << "\t\t\t\t---------------------------------------------------------"<<endl;
				cout <<"\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM*************"<<endl;
				cout <<"\t\t\t\t--------------------------------------------------------" << endl;
				cout<<"                                                                   "<<endl;
				cout <<"\t\t\t\tPress 1 to see Applied for cars ";
				int n;
				cin >> n;
				if (n == 1)
				{
					PrintNewCar();
				}
				else
				{
					cout << "Invalid num" << endl;
				}
			}
			else if (choice == 2)
			{

				int slote;
				cout << "\t\t\t\t---------------------------------------------------------"<<endl;
				cout <<"\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM*************"<<endl;
				cout <<"\t\t\t\t--------------------------------------------------------" << endl;
				cout<<"                                                                   "<<endl;
				cout << "\t\t\t\t\t---------*****************-------------"<< endl;
				cout << "\t\t\t\t\t Enter second hand car detail" << endl;
				cout << "\t\t\t\t\t---------*****************-------------"<< endl;
				cout << "                                                  " << endl;
				cout << "\t\t\t\t\tEnter How many slot available in showroom ";
				cin >> slote;
				system("CLS");
				cout << "\t\t\t\t---------------------------------------------------------"<<endl;
				cout <<"\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM*************"<<endl;
				cout <<"\t\t\t\t--------------------------------------------------------" << endl;
				cout<<"                                                                   "<<endl;
				int id;
				string name;
				int price;
				string model;
				for (int i = 0; i < slote; i++)
				{
					cout << "\t\t\t\t\t   Enter Car " << i + 1 << " Detail"<<endl;
					cout<<endl;
					cout<<endl;
					cout << "\t\t\t\t\t   Enter Car Id " ;
					cin >> id;
					cout << "\t\t\t\t\t   Enter Car Name " ;
					cin >> name;
					cout << "\t\t\t\t\t   Enter Car Price " ;
					cin >> price;
					cout << "\t\t\t\t\t   Enter Car Model " ;
					cin >> model;
					cout<<endl;
					insert(head, id, name, price, model);
				}
				system("CLS");
				
				cout << "\t\t\t\t---------------------------------------------------------"<<endl;
				cout <<"\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM***************"<<endl;
				cout <<"\t\t\t\t--------------------------------------------------------" << endl;
				cout<<"                                                                   "<<endl;
				int i=0;
				while(i<100)
				{
				cout<<"\t\t\t\t-----------------------------------------------"<<endl;
				cout << "\t\t\t\t\t  PRESS 1 To DISPLAY CAR DATA " << endl;
				cout << "\t\t\t\t\t  PRESS 2 To DELETE CAR Data " << endl;
				cout << "\t\t\t\t\t  PRESS 3 TO SEARCH CAR DATA " << endl;
				cout << "\t\t\t\t\t  PRESS 4 To TOTAL CARS Enter" << endl;
				cout<<"\t\t\t\t\t  Press num grater than 4 and less than 1 to exit"<<endl;
				cout<<"\t\t\t\t-----------------------------------------------"<<endl;
				int num;
				cout << "\t\t\t\t\t  Enter yor choice...... ";
				cin >> num;
				if(num==1)
				{
					system("CLS");
					cout << "\t\t\t\t---------------------------------------------------------"<<endl;
					cout <<"\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM***************"<<endl;
					cout <<"\t\t\t\t--------------------------------------------------------" << endl;
					cout<<"                                                                   "<<endl;
					display(head);
				}
				else if (num == 2)
				{
					system("CLS");
					cout << "\t\t\t\t---------------------------------------------------------"<<endl;
					cout <<"\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM***************"<<endl;
					cout <<"\t\t\t\t--------------------------------------------------------" << endl;
					cout<<"                                                                   "<<endl;
					int idd;
					cout<<"\t\t\t\t\t  -----------------------------------"<<endl;
					cout << "\t\t\t\t\t  Enter car id which can you delete....";
					cin >> idd;
					deleteCar(head, idd);
				}
				else if(num==3)
				{
					system("CLS");
					cout << "\t\t\t\t---------------------------------------------------------"<<endl;
					cout <<"\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM***************"<<endl;
					cout <<"\t\t\t\t--------------------------------------------------------" << endl;
					cout<<"                                                                   "<<endl;
					cout<<"\t\t\t\t\t  -----------------------------------"<<endl;
					cout<<"\t\t\t\t\t  Enter Car Name to Search....";
					string name;
					cin>>name;
					serchName(head,name);
				}
				else if(num==4)
				{
					system("CLS");
					cout << "\t\t\t\t---------------------------------------------------------"<<endl;
					cout <<"\t\t\t\t************CAR-SHOWROOM MANAGMENT SYSTEM***************"<<endl;
					cout <<"\t\t\t\t--------------------------------------------------------" << endl;
					cout<<"                                                                   "<<endl;
					cout<<"\t\t\t\t\t  -----------------------------------"<<endl;
					cout<<"\t\t\t\t\t  Total cars available in showroom"<<endl;
					cout<<"        "<<endl;
					TotalCar(head);
					cout<<endl;
				}
				
				else 
				{
					break;
				}
		    }
			}
			else
			{
				break;
			}
		}


	}
	else if (username1 != username)
	{
		cout << "\a\n\t\t\t\t\t\tYOUR USERNAME IS INCORRECT: ";
		Sleep(3000);
		goto start;
	}
	else if (password1 != password)
	{
		cout << "\a\n\t\t\t\t\t\tYOUR PASSWORD IS INCORRECT: ";
		Sleep(3000);
		goto start;
	}
}
