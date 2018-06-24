
///Jai Mata Di
// Developed by Rahul Chandra, under the suprvision of Mr. Subhash Jha
//This project facilitates a complete end to to end Library Managemen System

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <dos.h>
#include <stdio.h>
#include<stdlib.h>
#include <process.h>


#define clrscr(); system("cls")

using namespace std;
class book
	{
	int bid;
	char bname[20];
	char author[20];
	int qty;
	public:
		book()
		{
		bid=0;
		strcpy(bname,"");
		strcpy(author,"");
		qty=0;
		}
		void getdata()
		{
		cout<<endl<<"Enter the book no:" <<endl;
		cin>>bid;
		cout<<"Enter the book name: " <<endl;
		cin>>bname;
		cout<<" Enter the author name: "<<endl;
		cin>>author;
		cout<<"Enter the quantity of the book: "<<endl;
		cin>>qty;
		}
		void putdata()
		{
		cout<<"\n\n\t"<<bid<<"\t\t"<<bname<<"\t\t"<<author<<"\t\t"<<qty;
		}
	
		char *findbook()
		{
		return (bname);
		}
	//Return bid while doing transaction 
		int checkbook()
		{
			return(bid);
		}
		int issuebook()
		{
			if(qty>0)
			{
				 qty=qty-1;
				 return 1;
			}
			return 0;
	
		}
	};
class member
	{
		int mid;
		char mname[20];
		char mcity[20];
	public:
		member()
		{
			mid=0;
			strcpy(mname,"");
			strcpy(mcity,"");
		}
		void getdata()
		{
			cout<<endl<<"Enter the Memeber Id: "<<endl;
			cin>>mid;
			cout<<endl<<"Enter Member Name:" <<endl;
			cin>>mname;
			cout<<"Enter the Member City:"<<endl;
			cin>>mcity;
		}
		
		void putdata()
		{
			cout<<"\n\t"<<mid<<"\t\t"<<mname<<"\t\t"<<mcity;
		}
		char *findmem()
		{
			return(mname);
		}
		//return member id while issueing book
		int checkmem()
		{
			return mid;
		}
		
	};

class trans
	{
		private:
				int  tbid;
				int  tmid;
				char issuedate[12];
				char estreturndate[12];
				char returndate[12];
								
					public:
				trans()
				{
					tbid=tmid=0;
				}
		
			void getdata(int tm, int tb)
			{
				tbid=tb;
				tmid=tm;
				bissuedate();
				
			}
			void putdata()
			{
				cout<<"\n\t\t"<<tmid<<"\t\t"<<tbid<<"\t\t"<<issuedate<<"\t\t"<<estreturndate;
			}
				void bissuedate()
				{
					strcpy(issuedate,"17-Jun-2018");
					strcpy(estreturndate,"24-Jun-2018");
				}
				int checktrans(int tmid1)
				{
					if(tmid==tmid1)
					{
					//cout<<"<\nMember has already been issued book....";
					return 1;
					}
					return 0;
				}
				int checkmid()
				{
					return tmid;
				}
				int checkbid()
				{
					return tbid;
				}
	};
	
void bookreturn();
void bookissue();
int checktrans(int,int);
void showfirst(void);
void checkpass();
void showmenu();
void add();
void transhowmenu();
void update1();
void firstmenu();
void delete1();
void search();
void dispall();
void memadd();
void memupdate();
void showmenu1();
void memdelete();
void memsearch();
void memdispall();
void disptrans();
char ch1='y';
int i,j,k;

book bobj;
book bobj1;
trans tbobj,tobj1;
member mbobj,mbobj1;
fstream file1;
fstream file;
int main()
{
	clrscr();
	showfirst();
	checkpass();
	if (ch1=='y')
	{
	cout<<"\nWelcome Back !!!!";
	firstmenu();
	}
	else
	{
	cout<<"\n\t\tYou have entered incorrect userid/pass word....";
	}
	getch();

return 0;
}

//This function is used to show initial first screen
void showfirst()
{
	for(i=0;i<80;i++)
	{
		cout<<"*";
	
	}
	cout<<endl;
	for(i=0;i<10;i++)
	{
	cout<<"*";
	}
cout<<"\t\tLIBRARY MANAGEMENT SYSTEM \t\t";
for(i=0;i<10;i++)
{
cout<<"*";
}
cout<<endl<<endl;
for(i=0;i<10;i++)
{
cout<<"*";
}
cout<<"\t\tDeveloped by : Rahul Chandra\t\t ";
for(i=0;i<10;i++)
{
cout<<"*";
}

cout<<endl<<endl;
for(i=0;i<10;i++)
{
cout<<"*";
}
cout<<"\t\tLanguage Used : Turbo C++ \t\t ";
for(i=0;i<10;i++)
{
cout<<"*";
}

cout<<endl<<endl;
for(i=0;i<10;i++)
{
cout<<"*";
}
cout<<"\t\tVersion : 1.01 (For Windows)\t\t ";
for(i=0;i<10;i++)
{
cout<<"*";
}
cout<<endl<<endl;
for(i=0;i<10;i++)
{
cout<<"*";
}
cout<<"\t\tDate : 28th May 2018\t\t\t ";
for(i=0;i<10;i++)
{
cout<<"*";
}
cout<<endl<<endl;
for(i=0;i<80;i++)
{
cout<<"*";
}
getch();
}
///Showfirst() over now

void checkpass()
	{
	clrscr();
	char uid[10], ch, pass2[10],tuid[10]="Rahul",tpass[10]="Rahul";

	while(ch1=='y')
	{

	cout<<"\n\n\n\t\t\tEnter Userid::";
	cin>>uid;
	cout<<"\n\t\t\tEnter Passcode(5 Characters)::";
	for(i=0;i<5;i++)
	{
	pass2[i]=getch();
	cout<<"*";
	}
	pass2[i]='\0';

	if (!strcmp(pass2,tpass) && !strcmp(uid, tuid) )
	 {
	 cout <<"\n\n\t\t You have been succesfully logged in......";
	 getch();
	 break;
	 }
	else
	{
	 cout<<"\n\n\t\t Password entered is incorrect........";
	 getch();
	 }
	 cout<<"\n\n\t\t Do you want to try again (y/n).....??";
	 cin>>ch1;
	 }
}

/////****First Menu for the Management System///
void firstmenu()
{
int ch;

do
{
clrscr();
	cout<<"\n\n\t\t\t ****LIBRARY MANAGEMENT SYSTEM****";
	cout<<"\n\t\t\t\t **M E N U**";
	cout<<"\n\n\n\t 1.BOOK MANAGEMENT SYSTEM SECTION";
	cout<<"\n\n\n\t 2.MEMBER MANAGEMENT SYSTEM SECTION";
	cout<<"\n\n\n\t 3.TRANSACTION MANAGEMENT SYSTEM";
	cout<<"\n\n\n\t 0.EXIT";
	cout<<"\n\n\n\t  Enter Your Choice In Which Section You Want To Go::";
			cin>>ch;
			switch(ch)
			{
			case 1:
				 showmenu();
				 break;
			case 2:
				 showmenu1();
				 break;
			case 3:
				transhowmenu();
				break;
			case 0:
					break;
			default :
				cout<<"\nInvalid choice";
			}

}while(ch !=0);
}

///*******Menu for the Member Management System
void showmenu1()

{       int ch1;

 do
 {
	clrscr();
	cout<<"\n\n*******\t M E N U \t*******";
	cout<<"\n\n\t1.Add A Member";
	cout<<"\n\n\t2.Update A Member Details";
	cout<<"\n\n\t3.Delete A Member from Library";
	cout<<"\n\n\t4.Search A Member Of Library";
	cout<<"\n\n\t5.Display All Member Of Library";
	cout<<"\n\n\t0.Exit....";

	cout<<"\n\n\nEnter your choice what do you want to do"<<endl;
	cin>>ch1;

	switch(ch1)
	{
		case 1:
		memadd();
			break;

		case 2:
		memupdate();
			break;

		case 3:
			memdelete();
			break;

		case 4:
			memsearch();
			break;

		case 5:
			memdispall();
			break;
		case 0:
			cout<<"\n\nt\t Exiting Member Management System.....";
			break;
		default: cout<<"\n\nSorry...Entered wrong choice....";

	}
 }while(ch1 !=0);
}



//*************** Menu for the book managment system
void showmenu()
{       int ch1;

 do
 {
	clrscr();
	cout<<"\n\n*******\t M E N U \t*******";
	cout<<"\n\n\t1.Add A Book In Library";
	cout<<"\n\n\t2.Update A Book Details";
	cout<<"\n\n\t3.Delete A Book from Library";
	cout<<"\n\n\t4.Search A Book In Library";
	cout<<"\n\n\t5.Display All Books In Library";
	cout<<"\n\n\t0.Exit....";

	cout<<"\n\n\nEnter your choice what do you want to do::"<<endl;
	cin>>ch1;

	switch(ch1)
	{
		case 1:
			add();
			break;

		case 2:
			update1();
			break;
		case 3:
		
			delete1();
			
			break;

		case 4:
			search();
			break;

		case 5: 
			dispall();
			break;
		case 0:
			cout<<"\n\nt\t Exiting Library Management System.....";
			break;
		default: cout<<"\n\nSorry...Entered wrong choice....";

	}
 }while(ch1 !=0);
}
//***************Menu for the Book Management System is ended
////************* Menu for the Transaction Management System is strated
void transhowmenu()
{
	clrscr();
	int ch1;
		do
		{
	//		clrscr();
			cout<<"\n\n\t\t\t\t****TRANSACTION MANAGEMENT SYSTEM****";
			cout<<"\n\n\t\t\t1.Issuing A Book";
			cout<<"\n\n\t\t\t2.Return A Book";
			cout<<"\n\n\t\t\t3.Display Transaction Register";
			cout<<"\n\n\t\t\t0.Exit";
			cout<<"\n\n\t\tEnter the choice what you want to do";
			cin>>ch1;
			
			switch(ch1)
			{
					
				case 1:
					bookissue();
					break;
				case 2:
				     bookreturn();
				      break;
				case 3:
					disptrans();
					break;
				case 0:
					break;
				default:
						cout<<"\n\nSorry Entered the wrong choice";
			}
		}while(ch1!=0);
}
//****************Menu for the Transaction Management System Is Ended////

//***************To add a new book in the library throug Book.DAT file
void add()

{
	clrscr();
       ofstream file;
	cout<<"\n\n\n\n\t\t Add A Book In the Library";
	file.open("Book.DAT", ios::out | ios::app | ios::binary );
	if(!file)
	{
	cout<<"\n\n\n\tUnable to Create File";
	getch();
	return;
	}
	bobj.getdata();

	file.write((char *)&bobj, sizeof(bobj));
	cout<<"\n\n\n\n Record successfully inserted.......";
	getch();
	file.close();
}
//***************Adding A New Book System is ended here.

//***************Display of all the book in the file
void dispall()
{
	clrscr();
	cout<<"\n\n\n\n\t\t Display All Books of Library";

	file.open("Book.DAT", ios::in|ios::binary);

	if(!file)
	{
	cout<<"\\n\n\n\t File Not Found";
	getch();
	return;
	}

	file.read((char *)&bobj, sizeof(bobj));

	cout<<"\n\n\tBook No\t\tBookName\t\tAuthor\t\tQty";
	while(!file.eof())
	{
	bobj.putdata();
//	getch();
	file.read((char *)&bobj, sizeof(bobj));
	}

	cout<<"\n\n\n\n Record successfully Displayed.......";
	getch();
	file.close();
}
//***************Display section is ended here



/// Search a particular record from the Book.DAT file......
void search()
{
	clrscr();
char str[20];
	cout<<"\n\n\n\n\t\t Search A Books from Library";

	file.open("Book.DAT", ios::in|ios::binary);

	if(!file)
	{
	cout<<"\\n\n\n\t File Not Found";
	getch();
	return;
	}
	cout<<"\n\nt\tEnter Book Name to be searched :";
	cin>>str;

	file.read((char *)&bobj, sizeof(bobj));
	while (!file.eof())
	{
	int a = strcmp(str,bobj.findbook());
	if(a==0)
		{
		cout<<"\n\n\tBook No\t\tBookName\tAuthor\tQty";
		bobj.putdata();
		getch();
		}
	file.read((char *)&bobj, sizeof(bobj));

	}
	file.close();
}
///***************Searching Section ends here...

///***************Updation of the record throug the name section
void update1()
{
clrscr();
char str[20];
fstream file;

	cout<<"\n\n\t\t****** BOOK UPDATE MODULE ******";
	cout<<"\n\n\t\t Enter The Book Name To Search::";
	cin>>str;
	file.open("Book.DAT",ios::in |ios::out |ios::binary);

	if(!file)
	{
	cout<<"\n\n\n\t File Not Found....";
	getch();
	return;
	}
	file.read((char *)&bobj, sizeof(bobj));
	while(!file.eof())
	{

		if(strcmp(str,bobj.findbook())==0)
		{
			bobj.putdata();
			cout<<"\n\nEnter New Data :";
			bobj.getdata();
			file.seekg(0,ios::cur);
			file.seekp(file.tellg()-sizeof(bobj));
			file.write((char *)&bobj,sizeof(bobj));
			cout <<"\n\n\t\t Record Successfully updated.....";
		}
	     else
		
		file.read((char *)&bobj, sizeof(bobj));
	}
	file.close();
	
}
///***************Update section ends here//


///***************Function to delete the particular record from the file
void delete1()		//Function to Delete Particular Record from Data STUD
{
	clrscr();
	char n[100];
	cout<<"Enter Book Name  that should be Deleted::";
	cin>>n;
	fstream o,file ;
	o.open("New.DAT",ios::out |ios::app | ios::binary);
	file.open("Book.DAT",ios::in |ios::binary);
	if(!file)
	{
		cout<<"Book not Found";
		exit(0);
	}
	else
	{
		file.read((char*)&bobj, sizeof(bobj));
		while(!file.eof())
		{
			if(strcmp(n,bobj.findbook())!=0)
			{
				o.write((char*)&bobj, sizeof(bobj));
			}
			else
			
			{
				 cout<<"*****Record Deleted Successfully*****"<<endl;
				 getch();
			}
			file.read((char*)&bobj, sizeof(bobj));
		}

	}
	o.close();
	file.close();
	remove("Book.DAT");
	rename("New.DAT", "Book.DAT");
}
//***************Delete records ends here and renaming is also done here

/////********END OF THE BOOK MANAGEMENT SYSTEM*****************
void memadd()
{
			clrscr();
		       ofstream file1;
	cout<<"\n\n\n\n\t\t Add A Member In the Member Management System";
	file1.open("Mem.DAT", ios::out | ios::app | ios::binary );
	if(!file1)
	{
	cout<<"\n\n\n\tUnable to Create File";
	getch();
	return;
	}

	mbobj.getdata();

	file1.write((char *)&mbobj, sizeof(mbobj));
	cout<<"\n\n\n\n Record successfully inserted.......";
	getch();
	file1.close();
}

void memdispall()
{
	clrscr();
	cout<<"\n\n\n\n\t\t\t\t Display All Members of Library";

	file1.open("Mem.DAT", ios::in|ios::binary);

	if(!file1)
	{
	cout<<"\\n\n\n\t File Not Found";
	getch();
	return;
	}

	file1.read((char *)&mbobj, sizeof(mbobj));

	cout<<"\n\n\tMember-No\t\tMember-Name\t\t\Member-City"<<endl;
	while(!file1.eof())
	{
	mbobj.putdata();
  //	getch();
	file1.read((char *)&mbobj, sizeof(mbobj));
	}

	cout<<"\n\n\n\n Record successfully Displayed.......";
	getch();
	file1.close();
}

void memsearch()
{
	clrscr();
char str[20];

	cout<<"\n\n\n\n\t\t Search A Member from Member Management System";

	file1.open("Mem.DAT", ios::in|ios::binary);

	if(!file1)
	{
	cout<<"\n\n\n\t File Not Found";
	getch();
	return;
	}
	cout<<"\n\n\t\tEnter Member Name to be searched :";
	cin>>str;

	file1.read((char *)&mbobj, sizeof(mbobj));
	while (!file1.eof())
	{
	int a = strcmp(str,mbobj.findmem());
	if(a==0)
		{
		cout<<"\n\n\tMember\t\MemberName\t\t\MemberCity";
		mbobj.putdata();
		getch();
		}
	file1.read((char *)&mbobj, sizeof(mbobj));

	}
	file1.close();
}
void memupdate()
{
	clrscr();
char str[20];
	
	cout<<"\n\n\t\t\****** MEMBER UPDATE MODULE ******";
	cout<<"\n\n\t\t Enter The Member Name To Search";
	cin>>str;
	file1.open("Mem.DAT",ios::in |ios::out|ios::binary);

	if(!file1)
	{
	cout<<"\n\n\n\t File Not Found";
	getch();
	return;
	}
	file1.read((char *)&mbobj, sizeof(mbobj));
	while(!file1.eof())
	{

		if(strcmp(str,mbobj.findmem())==0)
		{		mbobj.putdata();
			cout<<"\n\nEnter New Data :";
			mbobj.getdata();
			file1.seekg(0,ios::cur);
			file1.seekp(file1.tellg()-sizeof(mbobj));
			file1.write((char *)&mbobj,sizeof(mbobj));
			cout <<"\n\n\t\t Record Successfully added.....";
		}
	     else
		file1.read((char *)&mbobj, sizeof(mbobj));
	}
	file1.close();
}

void memdelete()		//Function to Delete Particular Record from Data STUD
{
	clrscr();
	char n[100];
	cout<<"Enter Member Name  that should be Deleted :";
	gets(n);
	ofstream o;
	o.open("New2.DAT",ios::out);
	file1.open("Mem.DAT",ios::in);
	if(!file1)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		file1.read((char*)&mbobj, sizeof(mbobj));
		while(!file1.eof())
		{
			if(strcmp(n,mbobj.findmem())!=0)
			{
				o.write((char*)&mbobj, sizeof(mbobj));
			}
			else
			{
				 cout<<"Record Deleted Successfully....."<<endl;
				 getch();
			}
			file1.read((char*)&mbobj, sizeof(mbobj));
		}

	}
	o.close();
	file1.close();
	remove("Mem.DAT");
	rename("New2.DAT", "Mem.DAT");
}
////////////////////////////////////////////////////////////////////////////////////////////
//***** The Functions For the Transaction Management System is started here////

void disptrans()
{
	clrscr();
	fstream f;
	f.open("Trans.DAT", ios :: in | ios :: binary);
	if (!f)
	{
		cout<<"\nFile Not found";
		return;
	}
	cout <<"\n\n\tMember Id\t\tBook Id\t\tBook Issue Date\t\t Return Date";
	
	f.read((char *)&tobj1, sizeof(tobj1));
	while (!f.eof())
	{
	tobj1.putdata();
	f.read((char *)&tobj1, sizeof(tobj1));	}
	f.close();
}
void bookissue()
{
	clrscr();
	book bobj1;
	int tmid1,tbid1,x;
	cout<<"\nEnter Member Id::";
	cin>>tmid1;
	cout<<"\nEnter Book Id::";
	cin>>tbid1;

		fstream mfile;
		x=0;
		mfile.open("Mem.DAT",ios::in|ios::binary);
		while(!mfile.eof() && x!=tmid1)
		{
			mfile.read((char *)&mbobj1,sizeof(mbobj1));
			x=mbobj1.checkmem();
			if(x==tmid1)
			{
				cout<<"\n\t\t Requested Member details are as:";
				cout<<"\n\t"<<"Member Id"<<"\t\t"<<"Member name"<<"\t\t"<<"M-City"<<"\n\n";
				mbobj1.putdata();
				cout<<"\n\n";
			}
		}
		mfile.close();
		//cout<<"\n\t x="<<x<<"\ttmid1="<<tmid1;
		if( x!=tmid1)
		{
			cout<<"\n Requested Member Not In Library....Exiting .....";
			return;
		}
		
		
		fstream bfile;
		x=0;
		bfile.open("Book.DAT", ios::in | ios::binary);
		while(!bfile.eof() && x!=tbid1)
		{
			bfile.read((char *)&bobj1,sizeof(bobj1));
			x=bobj1.checkbook();
			if(x==tbid1)
			{
				cout<<"\n\t\tRequested books details are as:";
				cout<<"\n\t Book No\t\tBook Name\tAuthor Name\tQuantity"<<endl;
				bobj1.putdata();
			}
		}
		bfile.close();
		if( x!=tbid1)
		{
			cout<<"\n Requested book not in library....exiting .....";
			return;
		}
		cout<<"\n Entering Transaction..........";
		
		fstream tfile;
		
		tfile.open("Trans.DAT",ios::in | ios::binary);
		
		if(!tfile)
		{
			tfile.close();
			tfile.open("Trans.DAT",ios::out | ios::binary);
			cout<<"\nUnable to find old file, but created a new file"; 
			tfile.close();
		}
	//	tfile.open("Trans.DAT",ios::in | ios::binary);
		while(!tfile.eof())
		{
			tfile.read((char *)&tobj1, sizeof(tobj1));
			
			int x=tobj1.checktrans(tmid1);
			if(x==1)
			{
				cout<<"\n\n\t\tMember has already been issued book...sorry....";
				return;
			}
		}
		tfile.close();
	
		tfile.open("Trans.DAT",ios::app|ios::binary);	
		tobj1.getdata(tmid1,tbid1);
		tfile.write((char *)&tobj1,sizeof(tobj1));
		tfile.close();
		cout<<"\n Successfully issued book";

}
///////Deletion of the book on returning......
void bookreturn()
{
	clrscr();
	int nmid,nbid;
	cout<<"\n\n\n\t\t\t\t\t******BOOK RETURN SYSTEM******";
	cout<<"\n\n\n\n\t\tEnter the Id Of The Member book to return::";
	cin>>nmid;
	ofstream o;
	fstream tfile;
	o.open("Trans2.DAT",ios::out);
	tfile.open("Trans.DAT",ios::in);
	
	if(!tfile)
	{
		cout<<"The Trans File Not Found.....";
		exit(0);
	}
	else
	{
		tfile.read((char *)&tbobj,sizeof(tbobj));
		while(!tfile.eof())
		{
			if(nmid!=tbobj.checkmid())
			{
				o.write((char *)&tbobj,sizeof(tbobj));
			}
			else
			{
				cout<<"\n\n\t\t\tRECORD DELETED SUCCESFULLY........"<<endl;
				getch();
			}
			tfile.read((char *)&tbobj,sizeof(tbobj));
		}
	}
	o.close();
	tfile.close();
	remove("Trans.DAT");
	rename("Trans2.DAT","Trans.DAT");
}
