#include <iostream>
#include <string>
#include <fstream>

using namespace std;
fstream B("Book Data.txt",ios::app);
fstream S("Student Data.txt",ios::app);
struct book
{
public:
	int id;
	  string book;
	  string author;
	  string ISBN;
	  int price;
	  int pages;
	  int issuedby;
	  string issuedon;
	  string returndate;

}b;
struct Student
{
	int id, Rollno, BookIssued;
	string stdname;
	book stdbook[10];
};
struct booklist
{
	int temp;
	void Createbook(book* t, Student* s)
	{
		//fstream B("Library Data.txt", ios::app);
		cout << "\t\t\t\tCREATING A NEW BOOK\n\n" << endl;
		
		cout << "Enter The book id:\t";
		cin >> t->id;

		cout << "\nEnter The Name of The Book:\t";
		cin.ignore();
		getline(cin, t->book);
		
		cout << "\nEnter The Author's Name:\t";
		getline(cin, t->author);
		
		cout << "\nEnter The ISBN:\t";
		getline(cin, t->ISBN);
		
		cout << "\nEnter The Books's Price:\t";
		cin >> t->price;

		cout << "\nEnter The Books's Pages:\t";
		cin >> t->pages;
	u:
		cout << "\nEnter Issued by:\t";
		cin >> t->issuedby;
		for (int i = 0; i < 10; i++)
		{
			if ((s + i)->Rollno == t->issuedby)
			{
				for (int a = 0; a < 10; a++)
				{
					if ((s + i)->stdbook[a].book == "")
					{
						(s + i)->BookIssued++;
						(s + i)->stdbook[a].book = t->book;
						cout << "\nBook Issued to " << (s + i)->stdname << endl;
						goto ArabianSea;
					}
				}
			}
			if (i + 1 == 10)
			{
				cout << "Student Not Found...\n";
				cout << "Existing Students:-\n";
				for (int a = 0; a < 10; a++)
				{
					if ((s + a)->stdname == "")
						continue;
					cout << (s + a)->Rollno << endl;
				}
				cout << "Do you want to try again?(y/n)\t";
				char select;
				cin >> select;
				if (select == 'y')
					goto u;
				else
					goto out;
			}
		}
	ArabianSea:
		cin.ignore();
		cout << "\nEnter Issued on:\t";
		getline(cin, t->issuedon);

		cout << "\nEnter Return date:\t";
		getline(cin, t->returndate);
		
		
		B << "Book ID: " << t->id << endl;
		B << "Book Name: " << t->book << endl;
		B << "Authors Name: " << t->author << endl;
		B << "ISBN: " << t->ISBN << endl;
		B << "Books's Price: " << t->price << endl;
		B << "Book's Pages: " << t->pages << endl;
		B << "Issued By: " << t->issuedby << endl;
		B << "Issued On: " << t->issuedon << endl;
		B << "Return Date: " << t->returndate << endl << endl;

		out:{}
	}

	void display_books(book* t)
	{
		for (int i = 0; i < 10; i++)
		{
			if ((t + i)->book == "")
				continue;
			cout << "\t\t\t\tDISPLAYING ALL BOOKS\n\n"
				<< "\nBook id :\t"
				<< (t + i)->id
				<< "\nBook Name :\t"
				<< (t + i)->book
				<< "Author Name :\t"
				<< (t + i)->author
				<< "\nISBN :\t\t"
				<< (t + i)->ISBN
				<< "\nBooks's Price :\t"
				<< (t + i)->price
				<< "\nBooks's Pages :\t"
				<< (t + i)->pages
				<< "\nIssued by :\t"
				<< (t + i)->issuedby
				<< "\nIssued on :\t"
				<< (t + i)->issuedon
				<< "\nReurn date :\t"
				<< (t + i)->returndate << endl;
		}
	}
	void View(book* t)
	{
		int i;
		cout << "Enter the index :\t";
		cin >> i;
		cout << "\t\t\t\tDISPLAYING BOOK ON INDEX " << i << ":-\n\n"
			<< "Book id :\t"
			<< (t + i)->id
			<< "\nBook Name :\t"
			<< (t + i)->book
			<< "\nAuthor Name :\t"
			<< (t + i)->author
			<< "\nISBN :\t"
			<< (t + i)->ISBN
			<< "\nBooks's Price :\t"
			<< (t + i)->price
			<< "\nBooks's Pages :\t"
			<< (t + i)->pages
			<< "\nIssued by :\t"
			<< (t + i)->issuedby
			<< "\nIssued on :\t"
			<< (t + i)->issuedon
			<< "\nReurn date :\t"
			<< (t + i)->returndate << endl;
	}
	void Delete(book* t)
	{
		int i;
	again:
		cout << "\t\t\t\tDELETING A BOOK BY INDEX\n\n";
		cout << "Enter the index you want to delete:\t ";
		cin >> i;
		cout << "Are you sure you want to delete " << (t + i)->book << "?(y/n)\t";
		char select;
		cin >> select;
		if (select == 'y') {
			for (int j = i; j < 10; j++)
				*(t + j) = *(t + j + 1);
			cout << (t + i)->book << " deleted..\n";
		}
		else
		{
			system("CLS");
			goto again;
		}
	}
	void Asc(book* t)
	{
		book* temp = new book[10];
		cout << "\t\t\t\tARRANGING BOOKS IN ASCENDING ORDER\n\n";
		for (int i = 0; i < 10; i++)
		{
			if ((t + i)->id > (t + i + 1)->id)
			{
				*(temp + i + 1) = *(t + i);
				*(t + i) = *(t + i + 1);
				*(t + i + 1) = *(temp + i);

			}
			cout << ".\n";
		}
		cout << "\nARRANGED\n";
		system("pause");
	}
	void Desc(book* t)
	{
		book* temp = new book[10];
		cout << "\t\t\tARRANGING BOOKS IN DESCENDING ORDER\n\n";
		for (int i = 0; i < 9; i++)
		{
			if ((t + i)->id < (t + i + 1)->id)
			{
				*(temp + i + 1) = *(t + i);
				*(t + i) = *(t + i + 1);
				*(t + i + 1) = *(temp + i);
			}
			cout << ".\n";
		}
		cout << "\nARRANGED\n";
		system("pause");
	}

};


struct StudentList
{
	void AddStd(Student* s)
	{
		cin.ignore();
		cout << "\t\t\t\t\tADDING A NEW STUDENT\n\n";
		cout << "Enter Student's name:\t ";
		getline(cin, s->stdname);
		cout << "\nEnter ID:\t ";
		cin >> s->id;
		cout << "\nEnter Roll Number:\t ";
		cin >> s->Rollno;

		S << "\nID: " << s->id;
		S << "\nStudent's name: " << s->stdname;
		S << "\nRoll Number: " << s->Rollno << endl << endl;

	}
	void PrintAll(Student* s)
	{
		cout << "\t\t\t\tPRINTING ALL STUDENTS\n\n";
		for (int i = 0; i < 10; i++)
		{
			if ((s + i)->stdname == "")
				continue;
			cout << "STUDENT " << i + 1 << ":-";
			cout << "\n\nStudent's name:\t" << (s + i)->stdname;
			cout << "\nID:\t" << (s + i)->id;
			cout << "\nRoll Number:\t" << (s + i)->Rollno << endl;
		}
	}
	void Print(Student* s)
	{
		int i;
		cout << "Enter the index of the student you want to print:\t";
		cin >> i;
		cout << "\n\nStudent's name:\t " << (s + i)->stdname;
		cout << "\nID:\t " << (s + i)->id;
		cout << "\nRoll Number:\t " << (s + i)->Rollno << endl;
	}
	void DeleteStd(Student* s)
	{
		bool invalid;
		do
		{
			invalid = true;
			int i;
			cout << "Enter the index you want to remove:\t";
			cin >> i;
			if ((s + i)->stdname == "")
			{
				cout << "No student at this index exists.\n";
				invalid = false;
			}
			else
			{
				cout << "Are you sure you want to remove " << (s + i)->stdname << " ?(y/n)\t";
				char select;
				cin >> select;
				if (select == 'y')
				{
					for (int j = i; j < 9; j++)
						*(s + j) = *(s + j + 1);
					cout << "Deleted..\n";
				}
			}
		}while(invalid);
	}

};

struct Library
{
	void Issue(book* t, Student* s)
	{
		uganda:
		cout << "Enter the book you want to issue:\t ";
		string bookname;
		cin >> bookname;
		for (int i = 0; i < 10; i++)
		{
			if ((t + i)->book == bookname)
			{
				africa:
				cout << "Enter the Student:\t ";
				string name;
				cin >> name;
				for (int k = 0; k < 10; k++)
				{
					if ((s + k)->stdname == name)
					{
						for (int l = 0; l < 10; l++)
						{
							if ((s + k)->stdbook[l].book == "")
							{
								(s + k)->stdbook[l].book = bookname;
								cout << (s + k)->stdbook[l].book << " issued.\n";
								break;
							}
						}
					}
					if (k + 1 == 10)
					{
						cout << "Student Not Found...\n";
						cout << "Existing Students:-\n";
						for (int a = 0; a < 10; a++)
						{
							if ((s+a)->stdname == "")
								continue;
							cout << (s+a)->stdname << endl;
						}
						cout << "Do you want to try again?(y/n)\t";
						char select;
						cin >> select;
						if (select == 'y')
							goto africa;
						else
							break;
					}

				}

			}
			if (i + 1 == 10)
			{
				cout << "Book Not Found...\n";
				cout << "Existing Books:\n";
				for (int a = 0; a < 10; a++)
				{
					if ((t+a)->book == "")
						continue;
					cout << (t+a)->book << endl;
				}
				cout << "Do you want to try again?(y/n)\t";
				char select;
				cin >> select;
				if (select == 'y')
					goto uganda;
				else
					break;
			}
		}
	}

	void Return(book* t, Student* s)
	{	
	polistan:
	cout << "Enter the Student:\t ";
	string name;
	cin >> name;
	for (int k = 0; k < 10; k++)
	{
		if ((s + k)->stdname == name)
		{
		uzbekistan:
			cout << "Enter the book you want to return:\t ";
			string bookname;
			cin >> bookname;
			for (int i = 0; i < 10; i++)
			{
				if ((s + k)->stdbook[i].book == bookname)
				{
					for (int l = 0; l < 10; l++)
					{
						if ((s + k)->stdbook[l].book == bookname)
						{
							for (int a = l; a < 9; a++)
							{
								(s + k)->stdbook[a] = (s + k)->stdbook[a + 1];
							}
							cout << "Returned...\n";
							break;
						}
					}
				}
				if (i + 1 == 10)
				{
					cout << "Book Not Found...\n";
					cout << "Existing Books:\n";
					for (int a = 0; a < 10; a++)
					{
						if ((s+k)->stdbook[a].book == "")
							continue;
						cout << (s + k)->stdbook[a].book << endl;
					}
					cout << "Do you want to try again?(y/n)\t";
					char select;
					cin >> select;
					if (select == 'y')
						goto uzbekistan;
					else
						break;
				}
			}
						
		}
		if (k + 1 == 10)
		{
			cout << "Student Not Found...\n";
			cout << "Existing Students:-\n";
			for (int a = 0; a < 10; a++)
			{
				if ((s + a)->stdname == "")
					continue;
				cout << (s + a)->stdname << endl;
			}
			cout << "Do you want to try again?(y/n)\t";
			char select;
			cin >> select;
			if (select == 'y')
				goto polistan;
			else
				break;
		}
	}
	}
	void PrintBooks(Student* s)
	{
		cout << "\t\t\t\t\tBOOKS ISSUED\n\n";
		for (int i = 0; i < 10; i++)
		{
			if ((s + i)->stdname == "")
				continue;
			cout << "Student: " << (s + i)->stdname;
			cout << "\tBooks Issued: ";
			for (int j = 0; j < 10; j++)
			{
				if ((s + i)->stdbook[j].book == "")
					continue;
				cout << (s + i)->stdbook[j].book << ", ";
			}
			cout << endl << endl;
		}
	}
};
void Clear();
int main()
{
	ofstream Students("Student Data.txt");
	ofstream Booklists("Book Data.txt");
	Students.close();
	Booklists.close();
	int option, bok, lst, index;
	int stdcount = 0, bookcount = 0;
	book* t = new book[10];
	booklist books, * b;
	Student* std = new Student[10];
	StudentList studentlist, * stdlist;
	stdlist = &studentlist;
	b = &books;
	Library library, * lib;
	lib = &library;
	do
	{
	high:
		cout << "\t\t\t\tLIBRARY MANAGEMENT SYSTEM\n\n";
		cout << "1. STUDENT\n"
			<< "2. BOOKS\n"
			<< "3. LIBRARY\n"
			<< "4. EXIT\n\n";
		cin >> option;
		system("CLS");
		switch (option)
		{
			case 1:
				int op;
				go:
				cout << "\t\t\tSTUDENT'S MENU\n\n";
				cout << "\n\n1. ADD A NEW STUDENT\n";
				cout << "\n2. DELETE A STUDENT\n";
				cout << "\n3. SHOW ALL STUDENTS\n";
				cout << "\n4. SHOW A PARTICULAR STUDENT\n";
				cout << "\n5. MAIN MENU\n";
				cin >> op;
				Clear();
				switch (op)
				{
					case 1:
						if (stdcount >= 10)
						{
							cout << "Cannot add more students.\n";
							Clear();
							goto high;
						}
						  stdlist->AddStd(&std[stdcount]);
						  stdcount++;
						  Clear();
						  break;
					case 2:
						stdlist->DeleteStd(std);
						Clear();
						break;
					case 3:
						stdlist->PrintAll(std);
						Clear();
						break;
					case 4:
						stdlist->Print(std);
						Clear();
						break;
					case 5:
						goto high;
						break;
					default:
						cout << "Choose from the following...\n\n";
						system("CLS");
						goto go;
						break;

				}
				break;
			case 2:
				Again : 
				cout << "\t\t\t\t\tBOOKS MENU\n"
					<< "\n1. ADD A NEW BOOK\n"
					<< "\n2. DELETE AN EXISTING BOOK\n"
					<< "\n3. VIEW A PARTICULAR BOOK\n"
					<< "\n4. VIEW ALL BOOKS\n"
					<< "\n5. SORT BOOKS IN ASCENDING ORDER\n"
					<< "\n6. SORT BOOKS IN DESCENDING ORDER\n";
				cin >> bok;
				Clear();
				switch (bok)
				{
					case 1:
						if (bookcount >= 10)
						{
							cout << "Cannot add more books...\n";
							Clear();
							goto high;
						}
						  b->Createbook(&t[bookcount], std);
						  bookcount++;
						  Clear();
						  break;

					case 2:
						b->Delete(t);
						Clear();
						break;
					case 3:
						b->View(t);
						Clear();
						break;
					case 4:
						b->display_books(t);
						Clear();
						break;
					case 5:
						b->Asc(t);
						Clear();
						break;
					case 6:
						b->Desc(t);
						Clear();
						break;
					default:
						cout << "Choose from the following...\n";
						system("CLS");
						goto Again;
						break;

				}
				break;
			case 3:
				int op1;
				up:
				cout << "\t\t\tLIBRARY SUB MENU\n\n";
				cout << "1. ISSUE A BOOK\n";
				cout << "\n2. RETURN A BOOK\n";
				cout << "\n3. PRINT THE BOOKS WHICH HAVE BEEN ISSUED\n";
				cin >> op1;
				Clear();
				switch (op1)
				{
					case 1:
						lib->Issue(t, std);
						Clear();
						break;
					case 2:
						lib->Return(t, std);
						Clear();
						break;
					case 3:
						lib->PrintBooks(std);
						Clear();
						break;
					default:
						cout << "Choose from the following...\n";
						goto up;
						break;
				}
				break;
			case 4:
				exit;
				break;
			default:
				system("CLS");
				cout << "Choose from the following...\n";
				goto high;
				break;
		}
	} while (option != 4);
}
void Clear()
{
	system("pause");
	system("CLS");
}
