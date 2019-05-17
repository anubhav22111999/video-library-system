#include<dos.h>
#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct date1
{ int dd,mm,yy;
};
//class category
 class category
 {
  public:
  char name[50];
  int code;
  char des[50];
 void in()
  {
   cout<<"ENTER CATEGORY CODE>>Category Name>>DESCRIPTION";
   cin>>code>>name>>des;
  }
 };



void menu();
//class video
class video
 {
  public:
  int vno,ccode;
  char title[50];
  int noc,nois;
  float price;
 void in()
  {
   cout<<"\nENTER Category CODE>>TITLE>>NO OF COPIES>>PRICE\n";
   cin>>ccode>>title>>noc>>price;
   nois=0;
  }
 void out();
  };

  void video::out()
  {
    category c;
    cout<<setw(10)<<vno;
    fstream r("category.dat",ios::binary|ios::in);
    while(r.read ((char*)&c,sizeof(c) ))
     {
     if(ccode==c.code)
      {
       cout<<setw(10)<<c.name;
       cout<<setw(10)<<title<<setw(10)<<noc<<setw(10)<<nois<<setw(10)<<price<<"\n";
      }
     }
   r.close();
   }




 //class member

class member
{
 public:
 int mcode;
 char mname[30],add[30],phone[10];
 int maxl,noiss;

 void in()
  {
   cout<<"\nENTER MEMBER CODE>>MEMBER NAME>>ADDRESS>>PHONE NUMBER>>MAXIMUM LIMIT\n";
   cin>>mcode>>mname>>add>>phone>>maxl;
   noiss=0;
  }
 void out()
  {
    cout<<setw(10)<<mcode<<setw(10)<<mname<<setw(10)<<add<<setw(10)<<phone<<setw(10)<<maxl<<setw(10)<<noiss<<setw(10);
  }

 };




//ISSUE CLASS
 class issue
 {
  public:
  int issno;
  int vc;
  int mcode;
  int fine;
   date1 doi,dor;
  void in()
  {
   cout<<"\n\nInput ViDEO CODE>>MEMBER CODE>>DATE OF ISSUE DD MM YY";
   cin>>vc>>mcode>>doi.dd>>doi.mm>>doi.yy;
   }
  void out()
  {
  cout<<setw(5)<<issno<<setw(5)<<vc<<setw(5)<<mcode<<setw(12)<<doi.dd<<"/"<<doi.mm<<"/"<<doi.yy<<setw(12)<<dor.dd<<"/"<<dor.mm<<"/"<<dor.yy<<setw(10)<<fine;
  }
 }I,fi;




  //vprocess



  void addvid()
  { clrscr();
   cout<<"\t\t VIDEO LIBRARY\n\n";
   cout<<"\t\t Add Video\n\n";
    int s=0;
    fstream a("library.dat",ios::in|ios::binary);
    video b;
    while(a!=0)
     {
     a.read((char*)&b,sizeof(video));
     s++;
     }

    b.in();
    b.vno=s+1;
    a.close();
    fstream w("library.dat",ios::binary|ios::app);
    w.write((char*)&b,sizeof(b));
    w.close();
    menu();
   }





   void modvid()
   {
    clrscr();
    video v;int vn;
    cout<<"Enter video number you want to modify";
    cin>>vn;
    fstream r("library.dat",ios::binary|ios::in);
    fstream w("temp.dat",ios::binary|ios::out);
    while(r.read((char*)&v,sizeof(v)))
    { if (v.vno==vn)
      {
       v.in();
      }
       w.write((char*)&v,sizeof(v));
     }
    r.close();
    w.close();
   remove("library.dat");
   rename("temp.dat","library.dat");
   menu();
   }




void vprocess()
 {
  clrscr();
  cout<<"\t\tVIDEO PROCESS MENU";
  cout<<"\n\nENTER YOUR CHOICE" ;
  cout<<"\n\n1.Add a new Video\n2. Modify Video\n3.REeturn to main MENU";
  int c;
  cin>>c;
  switch (c)
   {
    case 1:addvid();break;
    case 2:modvid();break;
    case 3:menu();break;
   }
   menu();
 }

// MEMBER PROCESS



 void addmem()
  {
   clrscr();
   member m;
   fstream w("member.dat",ios::binary|ios::app);
   m.in();
   w.write((char*)&m,sizeof(m));
   w.close();
   menu();
  }

  void modmem()
   {
    clrscr();
    member m;int mc;
    cout<<"Enter Member code of member you want to modify";
    cin>>mc;
    fstream r("member.dat",ios::binary|ios::in);
    fstream w("temp.dat",ios::binary|ios::out);
    while(    r.read((char*)&m,sizeof(m)))
{     if (m.mcode==mc)
      {
       m.in();
       }
       w.write((char*)&m,sizeof(m));
      }
    r.close();
    w.close();
   remove("member.dat");
   rename("temp.dat","member.dat");
   menu();
   }



void delmem()
  {
   clrscr();             member m;
   cout<<"\t\tMember Delete Menu\n\n";
   cout<<"Enter your member code\n\t";
   int code;
   cin>>code;
   fstream r("member.dat",ios::binary|ios::in);
   fstream w("temp.dat",ios::binary|ios::out);
   while (r.read((char*)&m,sizeof(m)))
   {
    if(code!=m.mcode)
    {
     w.write((char*)&m,sizeof(m));
    }
    r.close();
    w.close();
    remove("member.dat");
    rename("temp.dat","member.dat");
   }
  menu();
 }



void mprocess()
 {
  clrscr();
  int c;
  cout<<"\t\tMember PROCESS MENU";
  cout<<"\n\nENTER YOUR CHOICE" ;
  cout<<"\n\n1.Add a new Member\n2. Modify Member\n3.Delete Member\n 4.REeturn to main MENU";
  cin>>c;
  switch (c)
  {case 1:addmem();break;
   case 2:modmem();break;
   case 3:delmem();break;
   case 4:menu();break;
   }
   menu();
 }


 //cprocess


 void addcat()
 {
  clrscr();
  category c;
  fstream w("category.dat",ios::binary|ios::app);
  c.in();
  w.write((char*)&c,sizeof(c));
  w.close();
  menu();
 }

void cprocess()
 {
  clrscr();
 int c;
  cout<<"\t\tCategory PROCESS MENU";
  cout<<"\n\nENTER YOUR CHOICE" ;
  cout<<"\n\n1.Add a new Category\n2.Return to main MENU";
  cin>>c;
  switch (c)
  {case 1:addcat();break;
   case 2:menu();break;
  }
 }








 //ISSUE RETURN PROCESS
   void issue()
  {
   clrscr();

   member m;
   int vc,mc;
   video v;
   cout<<"Enter Member Code\n\n";
   cin>>mc;
   fstream rm("member.dat",ios::binary|ios::in);

	     int ctr=0;
   while(rm.read((char*)&m,sizeof(m)))
   {
    if(m.mcode==mc)
    {  ctr++;
      cout<<"\Member FOUND\n\n";

      if(m.maxl<=m.noiss)
       {
       cout<<"Maximum Videos Issued";
       break;
       }
       cout<<"Enter video number you want to issue...";
       cin>>vc;
   fstream rv("library.dat",ios::binary|ios::in);
      while(rv.read ((char*)&v,sizeof(v)))
       {
	if(v.vno==vc && v.noc>=v.nois)
	{
	 cout<<"Video Found";
	 fstream ri("issue.dat",ios::binary|ios::in);
	 int count=1;
	 while(ri.read((char*)&I,sizeof(I)))
	  {
	   count++;
	  }
	 ri.close();
	 I.issno=count+1;
	 I.vc=vc;
	 I.mcode=mc;
	 struct date dd;
	 getdate(&dd);
	 I.doi.dd=dd.da_day;
	 I.doi.mm=dd.da_mon;
	 I.doi.yy=dd.da_year;
	 m.noiss=m.noiss+1;

	 v.nois=v.nois+1;
	 cout<<"\nEnter Date of Return DD MM YYYY\n";
	 cin>>I.dor.dd>>I.dor.mm>>I.dor.yy;
	 int k=I.dor.dd-I.doi.dd;
	  if(k>7)
	  I.fine=(k-7)*10;

	 fstream w("issue.dat",ios::binary|ios::app);

	 w.write((char*)&I,sizeof(I));
	 w.close();



		 member mor;
	 fstream rmem("member.dat",ios::binary|ios::in);
	 fstream wmem("temp.dat",ios::binary|ios::out);

	 while(rmem.read((char*)&mor,sizeof(mor)))
	 {
	    if (mor.mcode==m.mcode)
	   {

	    wmem.write((char*)&m,sizeof(m));
	   }
	 else
	  wmem.write((char*)&mor,sizeof(mor));
	 }
	 rmem.close();
	 wmem.close();
	 remove("member.dat");
	 rename("temp.dat","member.dat");


	 video vor;
	 fstream rvid("library.dat",ios::binary|ios::in);
	 fstream wvid("temp.dat",ios::binary|ios::out);
	 while(rvid.read((char*)&vor,sizeof(vor)))
	 {

	  if (vor.vno==v.vno)
	    {
	    wvid.write((char*)&v,sizeof(v));
	    }
	   else
	    wvid.write((char*)&vor,sizeof(vor));
	  }
	  rvid.close();
	  wvid.close();
	  remove("library.dat");
	  rename("temp.dat","library.dat");
	  break;
		 }
		 }
       if(ctr==0)
       cout<<"\nVideo Unavailable";
    rv.close();
      }
     else
     cout<<"\nMember Not found";
    }
    rm.close();
    }

    //***************************************************************
//    	function to RETURN book
//****************************************************************


void retn()
  {
   clrscr();
   member m;

   int vc,mc,ic;
   video v;
   cout<<"Enter ISSUE Code\n\n";
   cin>>ic;

   fstream s("issue.dat",ios::in|ios::binary);
   int ctr=0;
    while ( s.read((char*)&I,sizeof(I) ))
    {
     if (ic==I.issno)
      {
       ctr++;
	      //issue temp;
       fstream w("temp.dat",ios::binary|ios::out);
       while (s.read((char*)&fi,sizeof(fi)))
       {
	 if(ic!=fi.issno)
	  {
	   w.write((char*)&fi,sizeof(fi));
	  }
	  s.close();
	  w.close();
	  remove("issue.dat");
	  rename("temp.dat","issue.dat");
       }

    // UPDATE VIDEO
      fstream temp("temp.dat",ios::binary|ios::out);
      fstream rv("library.dat",ios::binary|ios::in);
      while(rv.read ((char*)&v,sizeof(v)))
      {
	if(v.vno==I.vc)
	{

	 v.nois=v.nois-1;
	 temp.write((char*)&v,sizeof(v));
	}
	else
	{
	 temp.write((char*)&v,sizeof(v));
	}
      }
      rv.close();
      temp.close();
      remove("library.dat");
      rename("temp.dat","library.dat");

     //UPDATE Member
      member m;
      fstream tempo("temp.dat",ios::binary|ios::out);
      fstream rm("member.dat",ios::binary|ios::in);
      while(rm.read ((char*)&m,sizeof(m)))
      {
	if(m.mcode==I.mcode)
	{

	 m.noiss=m.noiss-1;
	 tempo.write((char*)&m,sizeof(m));
	}
	else
	{
	 tempo.write((char*)&m,sizeof(m));
	}
      }
      rm.close();
      tempo.close();
      remove("member.dat");
      rename("temp.dat","member.dat");
    }

    }
    if(ctr==0)
     cout<<"\n\t\tINCORRECT Issue NO";
  }




 void irprocess()
 {
  clrscr();
  int c;
  cout<<"\t\tIssue/Return MENU";
  cout<<"\n\nENTER YOUR CHOICE" ;
  cout<<"\n\n 1.Issue Video \n 2.Return a Video\n 3.Return to main MENU";
  cin>>c;
  switch (c)
  {case 1:issue();break;
   case 2:retn();break;
   case 3:menu();break;
  }
 }



 //report

  //CATEGORY WISE VIDEO LIST
  void vidlis()
  {
   clrscr();
   video v;
   category cat;

    cout<<setw(10)<<"video no"<<setw(10)<<"Category"<<setw(10)<<"Title"<<setw(10)<<"No cop"<<setw(10)<<"NO. ISS"<<setw(10)<<"price\n\n";
   fstream c("category.dat",ios::in|ios::binary);
   while (c.read((char*)&cat,sizeof(cat)))
   {
   fstream r("library.dat",ios::binary|ios::in);
    while(r.read((char*)&v,sizeof(v)))
    { if(cat.code==v.ccode)
     {
     cout<<"\n";
     v.out();
     cout<<"\n";
     }
   }
   r.close();
   }
   getch();
   c.close();
   menu();
   }

  //ISSUE LIST
  void isslis()
  {

   fstream r("issue.dat",ios::binary | ios::in);
   cout<<setw(10)<<"Issue no"<<setw(10)<<"Video Code"<<setw(10)<<"Member Code"<<setw(10)<<"DATE OF ISSUE"<<setw(10)<<"DATE OF RETURN"<<setw(10)<<"FINE";
   while(r.read((char*)&I,sizeof(I)))
   {
   cout<<"\n";
   I.out();
   cout<<"\n";
   }
   getch();
   r.close();
   menu();
  }

  void avalvid()
  {
   clrscr();
   video v;
   fstream r("library.dat",ios::binary|ios::in);
    cout<<setw(10)<<"Video no"<<setw(10)<<"Category"<<setw(10)<<"Title"<<setw(10)<<"No cop"<<setw(10)<<"NO. ISS"<<setw(10)<<"price\n\n";
   while(r.read((char*)&v,sizeof(v)))
   {
    if((v.noc-v.nois)>=0)
     {
      cout<<"\n";
      v.out();
      cout<<"\n";
     }
    }
  getch();
  r.close();
  menu();
  }

  void memlis()
  {
   member m;
   fstream r("member.dat",ios::binary | ios::in);
   cout<<setw(10)<<"Member Code"<<setw(10)<<"Member Name"<<setw(10)<<"Address"<<setw(10)<<"Phone"<<setw(10)<<"Max Limit"<<setw(10)<<"ISSUED";
   while(r.read((char*)&m,sizeof(m)))
   {
    cout<<"\n";
    m.out();
    cout<<"\n";
   }
   getch();
   r.close();
   menu();
  }




 void report()
 {
  clrscr();
  int c;
  cout<<"\t\tREPORTING MENU";
  cout<<"\n\nENTER YOUR CHOICE" ;
  cout<<"\n\n 1.Category wise Video list \n 2. List of Video issued\n 3.List of Available Videos\n 4.Defaulter List\n5.Member List\n6.Return to main MENU";
  cin>>c;
  switch (c)
  {
   case 1:vidlis();break;
   case 2:isslis();break;
   case 3:avalvid();break;
   //case 4:deflis();break;
   case 5:memlis();break;
   case 6:menu();break;
  }
 }



 void menu()
 {
  clrscr();
  int c;
  cout<<"\t\tVIDEO LIBRARY MANAGEMENT SYSTEM"<<"\nEnter OPTION";
  cout<<"\n1. Video Processing\n\n2. Member Processing\n\n3. Category Processing\n\n4. Issue/Return a Video";
  cout<<"\n\n5. Reporting\n\n6. Exit\n\n";
  cin>>c;
  switch (c)
  {
   case 1: vprocess();break;
   case 2: mprocess();break;
   case 3: cprocess();break;
   case 4: irprocess();break;
   case 5: report();break;
   case 6: exit(1);break;
  }
 }
void main()
 {
  menu();
 }