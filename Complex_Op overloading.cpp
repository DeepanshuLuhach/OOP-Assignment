 #include<iostream>
 using namespace std;

 class Complex
{
    int real,img;
public:
   Complex();
   Complex(int ,int );
   Complex operator + (Complex);
   Complex operator - (Complex);
   friend Complex operator * (Complex,Complex);
   friend Complex operator / (Complex,Complex);
   void display()
   {
       cout<<real<<" + i"<<img<<endl;
   }


};
Complex::Complex()
   {
       real=0;
       img=0;
   }
Complex::Complex(int r,int i)
   {
       real=r;
       img=i;
   }
Complex Complex:: operator + (Complex C1)
{
    Complex C;
    C.real = real+C1.real;
    C.img=img+C1.img;
    return C;

}
Complex Complex :: operator - (Complex C1)
{
    Complex C;
    C.real = real-C1.real;
    C.img=img-C1.img;
    return C;

}
Complex operator / (Complex C1,Complex C2)
{

    Complex C;
    C.real = (C1.real*C2.real-C1.img*C2.img)/(C2.real*C2.real+C2.img*C2.img);
    C.img= (C1.real*C2.img + C2.real*C1.img)/(C2.real*C2.real+C2.img*C2.img);
    return C;

}
Complex operator * (Complex C1,Complex C2)
{
    Complex C;
    C.real = C1.real*C2.real-C1.img*C2.img;
    C.img= C1.real*C2.img + C2.real*C1.img;
    return C;

}
void memf()
{
    cout<<"Enter your choice :\n";
    int m;
    cout<<"1.Addition\n2.Subtraction\n";
    cin>>m;
    Complex a,b,c;
    int x,y;
    switch(m)
    {
        case 1:cout<<"Enter the value for first complex number :";
                cin>>x>>y;
                a=Complex(x,y);
                cout<<"Enter the value for second complex number :";
                cin>>x>>y;
                b=Complex(x,y);
                c=a+b;
                c.display();
                break;
        case 2: cout<<"Enter the value for first complex number :";
                cin>>x>>y;
                a=Complex(x,y);
                cout<<"Enter the value for second complex number :";
                cin>>x>>y;
                b=Complex(x,y);
                c=a-b;
                c.display();
                break;
        default:"Invalid Choice!";
    }
}
void friendf()
{
    cout<<"Enter your choice :\n";
    int m;
    cout<<"1.Multiplication\n2.Division\n";
    cin>>m;
    Complex a,b,c;
    int x,y;
    switch(m)
    {
        case 1:cout<<"Enter the value for first complex number :";
                cin>>x>>y;
                a=Complex(x,y);
                cout<<"Enter the value for second complex number :";
                cin>>x>>y;
                b=Complex(x,y);
                c=a*b;
                c.display();
                break;
        case 2: cout<<"Enter the value for first complex number :";
                cin>>x>>y;
                a=Complex(x,y);
                cout<<"Enter the value for second complex number :";
                cin>>x>>y;
                b=Complex(x,y);
                c=a/b;
                c.display();
                break;
        default:"Invalid Choice!";
    }
}

int main()
{
    int choice;
    char ch;
    do{
        cout<<"Enter your choice:";
        cout<<"\n1.Member Function\n2.Friend Function";
        cin>>choice;
        switch(choice)
        {
            case 1: memf();
                    break;
            case 2: friendf();
                    break;
            default:cout<<"invalid Choice:";
        }
        cout<<"\nDo you wish to continue(y/n)\n";

        cin>>ch;
    }while(ch=='Y'||ch=='y');
}

