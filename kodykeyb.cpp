
#include<fstream>
#include <iostream>
#include <conio.h>


using namespace std;


int raz(){


unsigned char znak;

getch();

while(kbhit()){

znak=getch();
static_cast < int >( znak );




}



return znak;
}


int main(){
int liczba=4;
fstream A;

A.open("kody.txt");


while(liczba!=0){
A<<raz();
A<<endl;
liczba--;

}

return 0;
}
