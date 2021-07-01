#include<bits/stdc++.h>
using namespace std;
class Polynomial{

    public:
    int *degOfCoefficient;
    int limit ;

    Polynomial(){
        this->degOfCoefficient=new int[6];
        this->limit=5;
    }
    Polynomial (int limit){
        this->degOfCoefficient=new int[limit+1];
        this->limit=limit;
    }
    Polynomial (Polynomial const &X){
    int *newdeg=new int[X.limit+1];
      for(int i=0;i<=X.limit;i++)
      newdeg[i]=X.degOfCoefficient[i];
      this->degOfCoefficient=newdeg;
      this->limit=X.limit;
    }
    void setCoefficient(int deg,int coef){
        if(deg>limit){
            int newlimit=deg;
            int *newdeg=new int[newlimit+1];
            for(int i=0;i<=limit;i++)
                newdeg[i]=degOfCoefficient[i];

            this->degOfCoefficient=newdeg;
            this->limit=newlimit;
            degOfCoefficient[deg]=coef;
        }
        else{
            degOfCoefficient[deg]=coef;
        }
    }
    Polynomial operator+(Polynomial const &X2){
    int newcap=max(this->limit,X2.limit);
    Polynomial X3(newcap);
        for(int i=0;i<=newcap;i++){
            if(i<=limit && i<=X2.limit)
                X3.degOfCoefficient[i]=this->degOfCoefficient[i]+X2.degOfCoefficient[i];
            else if(i<=limit)
                X3.degOfCoefficient[i]=this->degOfCoefficient[i];
            else
                X3.degOfCoefficient[i]=X2.degOfCoefficient[i];
        }

        return X3;
    }
    Polynomial operator-(Polynomial const &X2){
    int newcap=max(this->limit,X2.limit);
    Polynomial X3(newcap);
        for(int i=0;i<=newcap;i++){
            if(i<=limit && i<=X2.limit)
                X3.degOfCoefficient[i]=this->degOfCoefficient[i]-X2.degOfCoefficient[i];
            else if(i<=limit)
                X3.degOfCoefficient[i]=this->degOfCoefficient[i];
            else
                X3.degOfCoefficient[i]=-X2.degOfCoefficient[i];
        }

        return X3;
    }
    Polynomial operator*(Polynomial const &X2){
    int newcap=this->limit+X2.limit;
    Polynomial X3(newcap);
        for(int i=0;i<=this->limit;i++){
            for(int j=0;j<=X2.limit;j++){
                X3.degOfCoefficient[i+j]+=this->degOfCoefficient[i]*X2.degOfCoefficient[j];
            }
        }
        return X3;
    }
    void operator=(Polynomial const &X){
        int *newdeg=new int[X.limit+1];
         for(int i=0;i<X.limit;i++)
            newdeg[i]=X.degOfCoefficient[i];
        this->degOfCoefficient=newdeg;
        this->limit=X.limit;
    }
    void print(){
       for(int i=0;i<=this->limit;i++){
            if(degOfCoefficient[i]!=0)
                cout<<degOfCoefficient[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }

};
int main()
{
    int c1,c2,choice;
    cin >> c1;

    int *deg1 = new int[c1];
    int *coeff1 = new int[c1];

    for(int i=0;i < c1; i++) {
        cin >> deg1[i];
    }

    for(int i=0;i < c1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < c1; i++){
        first.setCoefficient(deg1[i],coeff1[i]);
    }

    cin >> c2;

    int *deg2 = new int[c2];
    int *coeff2 = new int[c2];

    for(int i=0;i < c2; i++) {
        cin >> deg2[i];
    }

    for(int i=0;i < c2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < c2; i++){
        second.setCoefficient(deg2[i],coeff2[i]);
    }

    cin >> choice;

    switch(choice){
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 :
        {
            Polynomial third(first);
            if(third.degOfCoefficient == first.degOfCoefficient) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
        case 5 :
        {
            Polynomial fourth(first);
            if(fourth.degOfCoefficient == first.degOfCoefficient) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }
     return 0;
}

