#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include<fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

bool gameover;



struct{
int headx;
int heady;

}head;






struct{

int placeX[360];


int placeY[360];



}body;



struct{
int fruitX;
int fruitY;


}fruit;



int height=20;
int width=20;
int score=0;
int ctr=0;


unsigned char znak;
char matrix[20][20];


int setup(){

srand(time (NULL));

head.headx=height/2;
head.heady=width/2;

fruit.fruitX=(rand()%18)+1;
fruit.fruitY=(rand()%18)+1;




matrix[head.headx][head.heady]='@';

matrix[fruit.fruitY][fruit.fruitX]='$';





for(int i=0; i<20;i++){
matrix[0][i]='#';
matrix[i][0]='#';
matrix[i][19]='#';
matrix[19][i]='#';
}




};



int input(){


while(kbhit()){

znak=getch();
static_cast < int >( znak );


}



};
int logic(){







///////////////////////////////////////////////////
if(znak==75){//lewo

if(matrix[head.heady][head.headx-1]=='$'){//fruit
score++;
ctr++;
}

if(matrix[head.heady][head.headx-1]=='#' || matrix[head.heady][head.headx-1]=='o'){//wall
gameover=1;
}

if(body.placeY[ctr]!=0)
matrix[body.placeY[ctr]][body.placeX[ctr]]=' ';

body.placeX[0]=head.headx;
body.placeY[0]=head.heady;



for(int i=ctr; i>0;i--){

    body.placeX[i]=body.placeX[i-1];
    body.placeY[i]=body.placeY[i-1];
}






matrix[head.heady][head.headx]=' ';
head.headx--;
matrix[head.heady][head.headx]='@';



for(int i=ctr;i>0;i--){

    matrix[body.placeY[i]][body.placeX[i]]='o';


}






}
///////////////////////////////////////////////////
if(znak==72){//g�ra


if(matrix[head.heady-1][head.headx]=='$'){//fruit
score++;
ctr++;
}

if(matrix[head.heady-1][head.headx]=='#' || matrix[head.heady-1][head.headx]=='o' ){//wall
gameover=1;
}
if(body.placeY[ctr]!=0)
matrix[body.placeY[ctr]][body.placeX[ctr]]=' ';

body.placeY[0]=head.heady;
body.placeX[0]=head.headx;


for(int i=ctr; i>0;i--){

    body.placeX[i]=body.placeX[i-1];
    body.placeY[i]=body.placeY[i-1];
}


matrix[head.heady][head.headx]=' ';
head.heady--;
matrix[head.heady][head.headx]='@';


for(int i=ctr;i>0;i--){

    matrix[body.placeY[i]][body.placeX[i]]='o';

}



}
/////////////////////////////////////////////////////
if(znak==77){//prawo


if(matrix[head.heady][head.headx+1]=='$'){//fruit
score++;
ctr++;
}

if(matrix[head.heady][head.headx+1]=='#' || matrix[head.heady][head.headx+1]=='o' ){//wall
gameover=1;
}
if(body.placeY[ctr]!=0)
matrix[body.placeY[ctr]][body.placeX[ctr]]=' ';


body.placeY[0]=head.heady;
body.placeX[0]=head.headx;


for(int i=ctr; i>0;i--){

    body.placeX[i]=body.placeX[i-1];
    body.placeY[i]=body.placeY[i-1];
}



matrix[head.heady][head.headx]=' ';
head.headx++;
matrix[head.heady][head.headx]='@';


for(int i=ctr;i>0;i--){

    matrix[body.placeY[i]][body.placeX[i]]='o';
}


}
////////////////////////////////////////////////////////
if(znak==80){//dol


if(matrix[head.heady+1][head.headx]=='$'){//fruit
score++;
ctr++;
}

if(matrix[head.heady+1][head.headx]=='#' || matrix[head.heady+1][head.headx]=='o' ){//wall
gameover=1;
}


if(body.placeY[ctr]!=0)
matrix[body.placeY[ctr]][body.placeX[ctr]]=' ';


body.placeY[0]=head.heady;
body.placeX[0]=head.headx;



for(int i=ctr; i>0;i--){
    body.placeX[i]=body.placeX[i-1];
    body.placeY[i]=body.placeY[i-1];
}


matrix[head.heady][head.headx]=' ';
head.heady++;
matrix[head.heady][head.headx]='@';




for(int i=ctr;i>0;i--){

    matrix[body.placeY[i]][body.placeX[i]]='o';
}



}



};
////////////////////////////////////////////////////////////


void draw(){



    if(matrix[fruit.fruitY][fruit.fruitX]=='@'){
do{


fruit.fruitX=(rand()%18)+1;
fruit.fruitY=(rand()%18)+1;

}while(matrix[fruit.fruitY][fruit.fruitX]=='o');



    }


matrix[fruit.fruitY][fruit.fruitX]='$';







    system("cls");

  for(int i=0; i < height; i++ ){


    for(int j=0; j < height; j++ ){

        cout<<matrix[i][j];


    }
        cout<<endl;
  }
}

int main(){

setup();
while (!gameover){


    input();
    logic();

    if(gameover==1)continue;

    draw();
    cout<<"SCORE: "<<score<<endl;
    


Sleep(100);

}

return 0;
}


