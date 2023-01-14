#include<iostream>
using namespace std;
 
 
int main(){
    int x = 0;
    int c= 0;
    int arrc[100];
    int arrq[100];
    char choice;

   do
        {
            m:
            cout<<"\n\n Enter Product Code :";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity :";
            cin>>arrq[c];
            for(int i=0; i<c; i++)
            {
               if (arrc[c]==arrc[i])
               {
                cout<<"\n\n Duplicate Product code. Please try again";
                goto m;
               }
                 
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If yes then press Y else no";
            cin>>choice;

        } while (choice == 'y');\

        for(int i=0; i<c; i++)
        {
           cout<< arrc[i]<<" "<<arrq[i];
           cout<<endl;
        }
  
return 0;
}