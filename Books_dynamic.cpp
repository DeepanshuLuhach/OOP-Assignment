#include<bits/stdc++.h>
#include<string.h>
using namespace std;
class Books
{
    static int successful,unsuccessful;
    int len, price, stock,id;
    char *title,*author,*pub;
    public:
    Books()
    {
        len=0;
        id=0;
        price=0;
        stock=0;
        title = new char(len+1);
        title="\0";
        pub =new char(len+1);
        author=new char(len+1);
        pub="\0";
        author="\0";
    }
   /* Books(char *t, char *a,char *p,int r,int s)
    {
        len=strlen(t);
        title=new char(len+1);
        strcpy(title,t);

        len=strlen(a);
        author=new char(len+1);
        strcpy(author,a);

        len=strlen(p);
        pub=new char(len+1);
        strcpy(pub,p);

        price=r;
        stock=s;

    }*/
    void add()
    {
        cout<<"Enter the book id:";
        cin>>id;
        cout<<"Enter the title :";
        title=new char(1);
        cin>>title;
        cout<<"Enter the publisher :";
        pub=new char(1);
        cin>>pub;
        cout<<"Enter the author :";
        author=new char(1);
        cin>>author;
        cout<<"Enter the price :";
        cin>>price;
        cout<<"Enter the stock number :";
        cin>>stock;
    }
    void Display()
    {
        cout<<title<<"\t"<<author<<"\t"<<pub<<"\t"<<price<<"\t"<<stock<<endl;
    }
    int searchb();
};
int main()
{
    Books s[10];
    int ch, k=0;
    while(1)
    {
        cout<<"Enter your choice \n1.Add a book \n2.update\n3.Search a book \n4.Purchase a book \n5.Number of successful and Unsuccessful attempts \n6.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    s[k].add();
                    k++;
                    s[k].Display();
                    break;
            case 2:
                    int f=searchb();
            default:  cout<<"INVALID";
        }
    }
    return 0;

}

