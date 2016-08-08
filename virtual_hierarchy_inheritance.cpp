#include<bits/stdc++.h>
using namespace std;

class info{
        protected:
        char *name,*bg;
        char *dob;
        int l,a,k;
        public:
            info(){
                l=0;a=0;k=0;
            }
        info(char n[], char b[], char d[]){
            l=strlen(n);
            a=strlen(b);
            k=strlen(d);
            name = new char(l+1);
            bg = new char(a+1);
            dob = new char(k+1);
            strcpy(name,n);
            strcpy(bg,b);
            strcpy(dob,d);
        }
};

class height: virtual public info{
        protected:
        double ht,wt;
        public:
            height(){
                ht=0;
                wt=0;
            }
            height(double a, double k){
                ht=a;
                wt=k;
            }
};

class insurance: virtual public info{
    protected:
        long long int ipnum;
        char *cadd;
        int l;
    public:
        insurance(){
            l=0;
            ipnum=0;
        }
        insurance(long long int m, char f[]){
            l=strlen(f);
            ipnum=m;
            cadd = new char(l+1);
            strcpy(cadd,f);
        }
};

class license: virtual public height ,  virtual public insurance{
    protected:
        long long int innum,tlnum;
    public:
        license(){
            innum=0;
            tlnum=0;
        }
        license(char n[],char b[], char d[],double a,double k,long long int m, char f[],long long int r, long long int s):
           info(n,b,d), height(a,k), insurance(m,f) {
            innum=r;
            tlnum=s;
        }
        void display();
        int comp(long long int);
        void modify();
        void del();
        int compare();
};

int license::compare(){
    if(ipnum!=0)
        return 1;
    else
        return 0;
}

void license:: display(){
    cout<<endl;
    cout<<"NAME:                 "<<name<<endl;
    cout<<"DOB:                  "<<dob<<endl;
    cout<<"CONTACT ADDRESS:      "<<cadd<<endl;
    cout<<"TELEPHONE NUM:        "<<tlnum<<endl;
    cout<<"BLOOD GROUP:          "<<bg<<endl;
    cout<<"HEIGHT:               "<<ht<<endl;
    cout<<"WEIGHT:               "<<wt<<endl;
    cout<<"INSURANCE POLICY NUM: "<<ht<<endl;
    cout<<"DRIVING LICENSE NUM:  "<<innum<<endl;
    cout<<"------------------------------";
}

int license:: comp(long long int k){
    if(ipnum==k)
        return 1;
    else
        return 0;
}

void license::modify(){
    int n,m;
    do{
        cout<<"What do you want to modify:"<<" "<<"1.Name\n";
        cout<<"                           "<<" "<<"2.Date of birth\n";
        cout<<"                           "<<" "<<"3.Contact address\n";
        cout<<"                           "<<" "<<"4.Telephone number\n";
        cout<<"                           "<<" "<<"5.Blood group\n";
        cout<<"                           "<<" "<<"6.Height\n";
        cout<<"                           "<<" "<<"7.weight\n";
        cout<<"                           "<<" "<<"8.Insurance policy number\n";
        cout<<"                           "<<" "<<"9.Driving license number\n";
        cin>>n;
        switch(n){
            case 1:cout<<"Enter name: ";
                   cin.getline(name,100);
                   cin.getline(name,100);
                   break;

            case 2:cout<<"\nEnter Date of birth: ";
                   cin.getline(dob,100);
                   cin.getline(dob,100);
                   break;

            case 3:cout<<"\nEnter contact address";
                   cin.getline(cadd,100);
                   cin.getline(cadd,100);
                   break;

            case 4:cout<<"\nEnter the telephone number";
                   cin>>tlnum;
                   break;

            case 5:cout<<"\nEnter Blood group";
                   cin.getline(bg,100);
                   cin.getline(bg,100);
                   break;

            case 6:cout<<"\nEnter height";
                   cin>>ht;
                   break;

            case 7:cout<<"\nEnter weight";
                   cin>>wt;
                   break;

            case 8:cout<<"\nEnter Insurance policy number";
                   cin>>ipnum;
                   break;

           case 9:cout<<"\nEnter Driving license number";
                   cin>>innum;
                   break;


                       }
        cout<<"Do you want do further change if yes press 1 if no press 0: ";
        cin>>m;
        cout<<"\n";
    }
    while(m==1);
}

void license::del(){
    name='\0';
    bg='\0';
    dob='\0';
    ipnum=0;
    innum=0;
}

int main(){
    char a[25],b[20],c[20],d[50];
    double e,f;
    long long int g,h,i,s;
    int j=0,n,t,x;
    license l[100];

    while(1){
    cout<<"\n";
    cout<<"\t\t\t\t"<<" ________________________________________________"<<endl;
	cout<<"\t\t\t\t"<<"| MENU:"<<"1.Insert infos"<<"                            |"<<endl;
	cout<<"\t\t\t\t"<<"|      "<<"2.Display records"<<"                         |"<<endl;
	cout<<"\t\t\t\t"<<"|      "<<"3.Update old infos"<<"                        |"<<endl;
	cout<<"\t\t\t\t"<<"|      "<<"4.Delete data"<<"                             |"<<endl;
	cout<<"\t\t\t\t"<<"|      "<<"5.Search a person's data"<<"                  |"<<endl;
	cout<<"\t\t\t\t"<<"|      "<<"6.Exit"<<"                                    |"<<endl;
    cout<<"\t\t\t\t"<<"|________________________________________________|"<<endl;
    cout<<"\n";
    cout<<"\t\t\t\t"<<"ENTER YOUR CHOICE: ";
    cin>>n;
    cout<<endl;


    switch(n){
    case 1:{ cout<<"\nEnter name: ";
            cin.getline(a,0);
            cin.getline(a,25);
            cout<<"\nEnter date of birth: ";
            cin.getline(b,20);
            cout<<"\nEnter blood group: ";
            cin.getline(c,20);
            cout<<"\nEnter your contact address: ";
            cin.getline(d,50);
            cout<<"\nEnter height: ";
            cin>>e;
            cout<<"\nEnter weight: ";
            cin>>f;
            cout<<"\nEnter insurance policy number: ";
            cin>>g;
            cout<<"\nEnter telephone number: ";
            cin>>h;
            cout<<"\nEnter license number: ";
            cin>>i;
            license o(a,c,b,e,f,g,d,i,h);
            l[j]=o;
            j++;
            break;}
     case 2:for(x=0;x<j;x++){
            t=1;
            t=l[x].compare();
            if(t==1)
                l[x].display();
        }
          break;

    case 3:{
           cout<<"\n Enter the Insurance policy number : ";
           cin>>s;
           cout<<endl;
           t=1;
            for(x=0;x<j;x++){
                t=l[x].comp(s);
                if(t==1){
                    l[x].modify();
                     break;
                }
             }
            if(x==j){
                cout<<"Data is not present\n";
                }
           break;
    }

     case 4:{
            cout<<"\n Enter the Insurance policy number : ";
            cin>>s;
            t=1;
            for(x=0;x<j;x++){
                t=l[x].comp(s);
                if(t==1){
                    l[x].del();
                     break;
                }
             }
            if(x==j){
                cout<<"Data is not present\n";
                }
           break;
     }

     case 5:{
            cout<<"\n Enter the Insurance policy number : ";
            cin>>s;
             t=1;
             for(x=0;x<j;x++){
                t=l[x].comp(s);
                if(t==1){
                    l[x].display();
                     break;
               }
             }
           if(x==j)
              cout<<"\nData is not present";
          break;
     }

     case 6:return 0;

    }
}
	return 0;
}


