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
       cout<<"\t"<<real<<" + i"<<img<<endl;
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
    cout<<"\n\tEnter your choice :\n";
    int m;
    cout<<"\t1.Addition\n\t2.Subtraction\n\t";
    cin>>m;
    Complex a,b,c;
    int x,y;
    switch(m)
    {
        case 1:cout<<"\n\tEnter the value for first complex number :";
                cin>>x>>y;
                a=Complex(x,y);
                cout<<"\n\tEnter the value for second complex number :";
                cin>>x>>y;
                b=Complex(x,y);
                c=a+b;
                c.display();
                break;
        case 2: cout<<"\n\tEnter the value for first complex number :";
                cin>>x>>y;
                a=Complex(x,y);
                cout<<"\n\tEnter the value for second complex number :";
                cin>>x>>y;
                b=Complex(x,y);
                c=a-b;
                c.display();
                break;
        default:"\n\tInvalid Choice!";
    }
}
void friendf()
{
    cout<<"\n\tEnter your choice :\n";
    int m;
    cout<<"\t1.Multiplication\n\t2.Division\n\t";
    cin>>m;
    Complex a,b,c;
    int x,y;
    switch(m)
    {
        case 1:cout<<"\n\tEnter the value for first complex number :";
                cin>>x>>y;
                a=Complex(x,y);
                cout<<"\n\tEnter the value for second complex number :";
                cin>>x>>y;
                b=Complex(x,y);
                c=a*b;
                c.display();
                break;
        case 2: cout<<"\n\tEnter the value for first complex number :";
                cin>>x>>y;
                a=Complex(x,y);
                cout<<"\n\tEnter the value for second complex number :";
                cin>>x>>y;
                b=Complex(x,y);
                c=a/b;
                c.display();
                break;
        default:"\n\tInvalid Choice!";
    }
}

int main()
{
    int choice;
    int ch;
    do{
        cout<<"\n\tEnter your choice:";
        cout<<"\n\t1.Member Function\n\t2.Friend Function\n\t";
        cin>>choice;
        switch(choice)
        {
            case 1: memf();
                    break;
            case 2: friendf();
                    break;
            default:cout<<"\n\tinvalid Choice:";
        }
        cout<<"\n\tDo you wish to continue(1/0):";

        cin>>ch;
    }while(ch==1);
}

