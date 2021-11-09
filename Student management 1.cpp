// Student management 1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
class student
{
public:
	string st_name, subject[5], status[5];
	int reg_no;
	void getdata_st()
	{
		cout << "Enter name: " << endl;
		cin >> st_name;
		cout << "Enter number: " << endl;
			cin >> reg_no;
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter subject: " << endl;
			cin >> subject[i];
			cout << "Enter status: " << endl;
			cin >> status[i];
		}
	}
	void display_st()
	{
		cout << "Student name: " << st_name << endl << "Registration number: " << reg_no << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Subject: " << subject[i] << endl << "Status: " << status[i] << endl;
		}
	}
};
class faculty : public student
{
protected:
	string fa_name, hand_subject;
	int id_no;
public:
	void getdata_fa()
	{
		cout << "Enter name: " << endl;
		cin >> fa_name;
		cout << "Enter ID: " << endl;
		cin >> id_no;
		cout << "Enter handling subject: " << endl;
		cin >> hand_subject;
	}
	void display_fa()
	{
		cout << "Faculty name: " << fa_name << endl << "Faculty ID: " << id_no << endl << "Faculty handling subject: " << hand_subject << endl;
	}
};
class hod : public faculty
{
protected:
	string hod_name;
	int hod_id;
public:
	void getdata_hod()
	{
		cout << "Enter name: " << endl;
		cin >> hod_name;
		cout << "Enter ID: " << endl;
		cin >> hod_id;
	}
	void display_hod()
	{
		cout << "HOD name: " << hod_name << endl;
		cout << "HOD ID: " << hod_id << endl;
	}
};
class admin : public hod
{
private:
	string admin_name;
	int admin_id;
public:
	void getdata_admin()
	{
		cout << "Enter name: " << endl;
		cin >> admin_name;
		cout << "Enter your ID: " << endl;
		cin >> admin_id;
	}
	void display_admin()
	{
		cout << "Admin name: " << admin_name << endl << "Admin ID: " << admin_id << endl;
	}
};
int main()
{
	int n;
	cout << "Welcome!" << endl << "Enter 1 for Admin, 2 for HOD, 3 for Faculty, 4 for Student" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "Welcome Admin. Enter password: ";
		break;
	case 2:
		cout << "Welcome HOD. Enter password: ";
		break;
	case 3:
		cout << "Welcome Faculty. Enter password: ";
		break;
	case 4:
		cout << "Welcome Student. Enter password: ";
		break;
	default:
		cout << "Invalid number. Please check!" << endl;
	}
	string password; 
	cin >> password;
	if (password == "admin1")
	{
		admin obj1;
		obj1.getdata_admin();
		obj1.display_admin();
		cout << "Press 1 for updating student details" << endl << "Press 2 for updating faculty details" << endl << "Press 3 for updating HOD details" << endl;
		int n1;
		cin >> n1; 
		switch (n1)
		{
		case 1:
			obj1.student::getdata_st();
			obj1.student::display_st();
			break;
		case 2:
			obj1.faculty::getdata_fa();
			obj1.faculty::display_fa();
			break;
		case 3:
			obj1.hod::getdata_hod();
			obj1.hod::display_hod();
			break;
		default:
			cout << "Invalid key" << endl;
		}
	}
	if (password == "hod2")
	{
		hod obj2;
		obj2.getdata_hod();
		obj2.display_hod();
		cout << "Press 1 for updating student details" << endl << "Press 2 for updating faculty details" << endl;
		int n2;
		cin >> n2;
		switch (n2)
		{
		case 1:
			obj2.student::getdata_st();
			obj2.student::display_st();
			break;
		case 2:
			obj2.faculty::getdata_fa();
			obj2.faculty::display_fa();
			break;
		default:
			cout << "Invalid key" << endl;
		}
	}
	if (password == "faculty3")
	{
		faculty obj3;
		obj3.getdata_fa();
		obj3.display_fa();
		cout << "Press 1 for updating student details" << endl;
		int n3;
		cin >> n3;
		for (int i = 0; i < 5; i++)
		{
			obj3.getdata_st();
			obj3.display_st();
		}
	}
	if (password == "student4")
	{
		student obj4;
		obj4.getdata_st();
		obj4.display_st();
	}
	return 0;
}
