#include<bits/stdc++.h>
using namespace std;

class bookshop{
		char *title,*athr,*pub;
		int d,cost,qnt;
	public:
	    int l=0;
	    static int s,u;
		bookshop(){
            d=0;
	        cost=0;
	        qnt=0;
		    title=new char(l+1);
		    athr=new char(l+1);
            pub=new char(l+1);
		}
		void accept(int k,char p[]){
                d=k;
                strcpy(title,p);
                cout<<"\nEnter name of author : ";
                cin.getline(athr,100);
                cout<<"\nEnter name of publication : ";
                cin.getline(pub,100);
                cout<<"\nEnter cost of book : ";
                cin>>cost;
                cout<<"\nEnter quantity of book : ";
                cin>>qnt;

		}
		void display(int);
        friend int compare(bookshop,int);
		int comp(char []);
		//int compare1(char []);
		void modify();
		void del();
		void purchase();
};
int bookshop:: s;
int bookshop:: u;
void bookshop ::purchase(){
        int q,n;
        do{
        cout<<"\nEnter quantity of book: ";
        cin>>q;
        if(qnt>=q){
            cout<<"\nTotal billing amount : "<<q*cost;
            qnt-=q;
            s++;
        }
        else{
            if(qnt>1){
            cout<<"\nonly "<<qnt<<" books are available\nYour transaction cannot be processed";
            }
            else{
                cout<<"\nonly "<<qnt<<" book is available\nYour transaction cannot be processed";
            }
            u++;
        }
        cout<<"\nDo you want to do further transaction for the same book ID?\nIf yes press 1 else 0: ";
        cin>>n;
        }
        while(n==1);
}

int compare(bookshop b, int k){
        if(b.d==k)
            return 0;
        else
            return 1;
}
/*
int bookshop:: compare1(char k[]){
        if(strcmp(title,k)==0)
            return 0;
        else
            return 1;
}
*/
int bookshop:: comp(char k[]){
    if(strcmp(title,k)==0)
        return 0;
    else{
        return 1;
    }

}

void bookshop:: display(int a){
    if(d!=0){
	cout<<" "<<a+1<<"\t\t"<<title<<"\t\t"<<athr<<"\t\t"<<pub<<"\t\t\t"<<d<<"\t\t"<<cost<<"\t\t"<<qnt<<"\n"<<endl;
    }

}

void bookshop::modify(){
    int n,m;
    do{
        cout<<"What do you want to modify:"<<" "<<"1.Title\n";
        cout<<"                           "<<" "<<"2.Author\n";
        cout<<"                           "<<" "<<"3.Publication\n";
        cout<<"                           "<<" "<<"4.Cost\n";
        cout<<"                           "<<" "<<"5.Quantity\n";
        cout<<"                           "<<" "<<"6.Book ID\n";
        cin>>n;
        switch(n){
            case 1:cout<<"Enter book name";
                   cin.getline(title,100);
                   cin.getline(title,100);
                   break;

            case 2:cout<<"\nEnter name of author";
                   cin.getline(athr,100);
                   cin.getline(athr,100);
                   break;

            case 3:cout<<"\nEnter publisher";
                   cin.getline(pub,100);
                   cin.getline(pub,100);
                   break;

            case 4:cout<<"\nEnter the cost";
                   cin>>cost;
                   break;

            case 5:cout<<"\nEnter quantity";
                   cin>>qnt;
                   break;

            case 6:cout<<"\nEnter new book ID";
                   cin>>d;
                   break;        }
        cout<<"Do you want do further change if yes press 1 if no press 0: ";
        cin>>m;
        cout<<"\n";
    }
    while(m==1);
}


void bookshop::del(){
    d=0;
	title='\0';
	athr='\0';
	pub='\0';
	cost=0;
	qnt=0;
}


int main()
{
    int id,p,n,i,t,j,flag=0,r;
    static int m=0;
    char s[100];

    bookshop a[1000];
	while(1){
    cout<<"\n";
    cout<<"\t\t\t\t"<<"##################################################"<<endl;
	cout<<"\t\t\t\t"<<"# MENU:"<<"1.Insert book details"<<"                     #"<<endl;
	cout<<"\t\t\t\t"<<"#      "<<"2.Display book records"<<"                    #"<<endl;
	cout<<"\t\t\t\t"<<"#      "<<"3.Update old details"<<"                      #"<<endl;
	cout<<"\t\t\t\t"<<"#      "<<"4.Purchase books"<<"                          #"<<endl;
	cout<<"\t\t\t\t"<<"#      "<<"5.successful and unsuccessful transaction"<<" #"<<endl;
    cout<<"\t\t\t\t"<<"#      "<<"6.Delete a books detail"<<"                   #"<<endl;
    cout<<"\t\t\t\t"<<"#      "<<"7.Exit"<<"                                    #"<<endl;
    cout<<"\t\t\t\t"<<"##################################################"<<endl;
    cout<<"\n";
    cout<<"\t\t\t\t"<<"ENTER YOUR CHOICE: ";
    cin>>n;
    cout<<endl;

    switch(n){
    case 1:flag=1;
          t=1;
         cout<<"Enter book ID: ";
         cin>>id;
         cout<<"\n";
         for(i=0;i<m;i++){
            t=compare(a[i],id);
            if(t==0){
                break;
            }
         }
         if(t==1){
             cout<<"Enter title of book : ";
             cin.getline(s,0);
             cin.getline(s,100);
             for(i=0;i<m;i++){
                t=a[i].comp(s);
                if(t==0){
                    break;
                }
             }
         }
         if(t==1){
          a[m].accept(id,s);
         m++;
         }
         else{
            cout<<"\nBook already exists";
         }
         break;

    case 2: if(flag==1){
              int p;
              cout<<"\n1: Display complete record\n2: Display specific record\nEnter your choice: ";
              cin>>p;
              switch(p){
                    case 1:cout<<"\nS.No.\t\tTitle\t\tAuthor\t\tPublication\t\tID\t\tCost\t\tQuantity\n";
                           for(i=0;i<m;i++)
                            a[i].display(i);
                           break;
                    case 2:cout<<"\nEnter the book name to be displayed: ";
                           cin>>s;
                           t=1;
                            for(i=0;i<m;i++){
                                t=a[i].comp(s);
                                if(t==0){
                                    cout<<"\nS.No.\t\tTitle\t\tAuthor\t\tPublication\t\tID\t\tCost\t\tQuantity\n";
                                        a[i].display(i);
                                         break;
                                }
                             }
                           if(i==m)
                              cout<<"\nData is not present";
                          break;
              }
            }
        else{
            cout<<"please input some data\n"<<endl;
        }
            break;

    case 3:
           cout<<"Enter the book name to be modified\n";
           cin>>s;
           t=1;
            for(i=0;i<m;i++){
                t=a[i].comp(s);
                if(t==0){
                    a[i].modify();
                     break;
                }
             }
            if(i==m){
                cout<<"Data for this book name does not exist\n";
                }
           break;

    case 4:if(flag==1){
           cout<<"\nS.No.\t\tTitle\t\tAuthor\t\tPublication\t\tID\t\tCost\t\tQuantity\n";
           for(i=0;i<m;i++)
            a[i].display(i);
            cout<<"\nEnter the book name you want to purchase: ";
            cin>>s;
            t=1;
            for(i=0;i<m;i++){
                t=a[i].comp(s);
                if(t==0){
                    a[i].purchase();
                     break;
                }
             }
            if(i==m){
                cout<<"\nNo such book exists";
            }
    }
        else
            cout<<"\nNo books available";
        break;

    case 5:cout<<"\nnumber of successful transactions:   "<<bookshop::s;
           cout<<"\nnumber of unsuccessful transactions: "<<bookshop::u;
           break;

    case 6:cout<<"Enter the book name to be deleted\n";
           cin>>s;
           t=1;
            for(i=0;i<m;i++){
                t=a[i].comp(s);
                if(t==0){
                    a[i].del();
                     break;
                }
             }
           if(t==1){
                cout<<"Data for this book name does not exist\n";
                 }
           break;

    case 7:return 0;

    default :cout<<"!!!INVALID INPUT!!! :(";
    }
  }
	return 0;
}
