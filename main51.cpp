#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<cwchar>
#include<vector>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std; 
int myscore=-1,distance_travelled=0;
char direction='d',control='@',temp_control='@';//d means right//awsd
int c_x=24,c_y=19;
int r1,r2;
struct foody{
	int xx,yy;
};
struct snake{
	int x,y;
	snake *next;
};
struct foody f[5];
snake *head=NULL,*ptr;
void gotoxy(int x,int y) 
{
	  COORD c;
  c.X=x;
  c.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
 void changecolor(int color)
{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
SetConsoleTextAttribute(hStdOut,color);
	
}	
void font()
{
				CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = 30;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void Lines()
{
	//system("cls");
	int i;
	for(i=2;i<=20;i++)
{
		changecolor(8);
		gotoxy(17,i);
		cout<<"*";
		gotoxy(79,i);
		cout<<"*";
}
    for(i=17;i<=79;i++)
{
	
		changecolor(8);
		gotoxy(i,2);
		cout<<"*";	
		gotoxy(i,20);
		cout<<"*";
}

	}
int random(int lower,int upper){
	return((rand() %(upper - lower + 1)) + lower);
}
bool trev(int x,int y){
	snake *t=head;
	while(t){
	   if(t->x==x && t->y==y)
	   return true;
		t=t->next;
	}
	return false;
}
bool check_food_loc(int r1,int r2){
	if(r1==f[1].xx && r2==f[1].yy)
	return true;
		if(r1==f[2].xx && r2==f[2].yy)
	return true;
		if(r1==f[3].xx && r2==f[3].yy)
	return true;
		if(r1==f[4].xx && r2==f[4].yy)
	return true;
	
	return false;
}
void show_food(int r11,int r22,int f_count){
f[f_count].xx=r11;
f[f_count].yy=r22;
gotoxy(r11,r22);
changecolor(12);
cout<<"@";
}
void food(int f_count){
while(1){
	r1=random(18,78);//range
	r2=random(3,19);//range
	if(!trev(r1,r2))
	{
	if(!check_food_loc(r1,r2))
	break;
   }
}
show_food(r1,r2,f_count);
}	

bool check_forfood(){

	if(c_x==f[1].xx && c_y==f[1].yy){
	food(1);
	return true;
    }
		if(c_x==f[2].xx && c_y==f[2].yy){
	food(2);
	return true;
    }
		if(c_x==f[3].xx && c_y==f[3].yy){
	food(3);
	return true;
    }
		if(c_x==f[4].xx && c_y==f[4].yy){
	food(4);
	return true;
    }
	return false;
			
}
void delay()
{
	for(int i=0;i<10000000;i++){}
	for(int i=0;i<10000000;i++){
	}
}

void small_delay(){
		for(int i=0;i<100000;i++){}
}

void append(int x1,int y1){
	snake *n=new snake;
	n->next=NULL;
	n->x = x1;
	n->y = y1;
	if(head==NULL){
		head=n;
	    ptr=n;
	}
		else{
			ptr->next=n;
			ptr=n;
		}
}
void del(){
	snake *temp=head;
	head=head->next;
	delete temp;
}

void score(){
	myscore++;
	gotoxy(47,1);
	changecolor(13);
	cout<<myscore;
}

void show_finalscore(){
	changecolor(11);
	gotoxy(81,1);	char ch=getch();
system ("cls"); 
cout<<"YOUR SCORE "<<myscore<<endl;
cout<<"DISTANCE TRAVELLED "<<distance_travelled;
delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();
ch =getch();
exit(1);	
}

void check_for_snakebody(){
	if(trev(c_x,c_y))
    show_finalscore();
    	
}

void check_for_boundary(){
 //c_x,c_y
 if(c_x==79 && (temp_control=='d' || temp_control=='@'))
 c_x=c_x-61;
 if(c_y==2 && temp_control=='w')
 c_y=c_y+17;
 if(c_x==17 && temp_control=='a')
 c_x=c_x+61;
 if(c_y==20 && temp_control=='s')
 c_y=c_y-17;
}
void movement(){
	check_for_boundary();

	check_for_snakebody();
		
	//code 
	if(direction==control){
	if(control=='a' || control=='d' || control=='@'){
	small_delay();}
	else if(control=='s' || control=='w'){
	small_delay();}
	else{
		if(direction=='a' || direction=='d')
		small_delay();
		else{
		small_delay();small_delay();}
	}
     }
	else{
		if(control=='a' || control=='d' || control=='@'){
	delay();}
	else if(control=='s' || control=='w'){
		delay();delay();
	}
	else{
		if(direction=='a' || direction=='d'){
		delay();}
		else{
		delay();delay();}
	}
	
	}

	if(check_forfood()==0){
		gotoxy(head->x,head->y);//tail of snake
		changecolor(0);
		cout<<" ";
		del();
	}
	else{// if snake eats foood
			score();//Increasng my score
		//FOOD
	}

	gotoxy(ptr->x,ptr->y);//snake head
	changecolor(10);
	cout<<"+";
	append(c_x,c_y);
	gotoxy(ptr->x,ptr->y);//head of snake
	changecolor(15);
	if(control=='w')
	cout<<"^";
	else if(control=='d' || control=='@')// initial case for snake
	cout<<">";
	else if(control=='s')
	cout<<"v";
	else if(control=='a')
	cout<<"<";
	else{
	if(direction=='w')
	cout<<"^";
	else if(direction=='d')
	cout<<">";
	else if(direction=='s')
	cout<<"v";
	else if(direction=='a')
	cout<<"<";	
	}
	if(control !='w' && control !='a' && control !='s' && control !='d')
	{
	}
	else{
	if(direction!=control)
	direction=control;
	control='$';
        }
}
void left(){
if(direction=='d'){
control='$';
return;
}
	c_x=c_x-1;
	movement();
}
void down(){
if(direction=='w'){
control='$';
return;
}
	c_y=c_y+1; 
		
	movement();
}
void right(){
	if(direction=='a'){
	control='$';
	return;
   }
	//if(direction=='r')
	c_x=c_x+1;
	//if(direction=='d')
	//c_y=c_y+1;
	//if(direction=='u')
	//c_y=c_y-1; 
	movement();
}
void up(){	
if(direction=='s'){
control='$';
return; 
}
	c_y=c_y-1;
		
	movement();
}
void quit(){
	FILE *fp;
    fp = fopen("snake.txt","w");
    fprintf(fp," ");
    fclose(fp);
    fp = fopen("snake.txt","a");
    //for linked list
    	snake *t=head;
	while(t){
		fprintf(fp,"%d,%d ",t->x,t->y);
		t=t->next;
	}
	//for food
	fprintf(fp,"%s","@ ");
	fprintf(fp,"%d,%d ",f[1].xx,f[1].yy);
	fprintf(fp,"%d,%d ",f[2].xx,f[2].yy);
	fprintf(fp,"%d,%d ",f[3].xx,f[3].yy);
	fprintf(fp,"%d,%d ",f[4].xx,f[4].yy);
	//for score
	fprintf(fp,"%s","@");
	fprintf(fp,"%d",myscore);
	//for dis travel
		fprintf(fp,"%s","@");
	fprintf(fp,"%d",distance_travelled);
	//for c_x,c_y
	fprintf(fp,"%s","@");
	fprintf(fp,"%d,%d",c_x,c_y);
	//direction
	fprintf(fp,"%s","@");
	fprintf(fp,"%c",direction);
	//control
	//fprintf(fp,"%s","@");
	//fprintf(fp,"%c ",control);
	// temp control
	fprintf(fp,"%s","@");
	fprintf(fp,"%c ",temp_control);
    //fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014);
    fclose(fp);
    show_finalscore();
}
void makesnake_con();
void makesnake_new();
void startgame(){
while(1){//infinite loop
changecolor(14);
    distance_travelled++;//total distance travelles yet
	gotoxy(1,1);
	cout<<distance_travelled;
	if(kbhit()){
		control=getch();
		if(control!='q')
		temp_control=control;
	    switch(control){
	    case 'a' : left(); break;
		case 's' : down(); break;
		case 'd' : right();break;
		case 'w' : up();   break;
		case 'q' : quit(); break;
	    default  : break;   	
	    }	
	}	
	if(direction=='a')
	left();
	if(direction=='d')
	right();
	if(direction=='w')
	up();
	if(direction=='s')
	down();
}		
}
void makesnake_new(){
//	if(distance_travelled!=0)
//	return;
changecolor(10);
append(18,19);
gotoxy(18,19);
cout<<"+";	
append(19,19);
gotoxy(19,19);
cout<<"+";
append(20,19);
gotoxy(20,19);
cout<<"+";	
append(21,19);
gotoxy(21,19);
cout<<"+";
append(22,19);
gotoxy(22,19);
cout<<"+";	
append(23,19);
gotoxy(23,19);
cout<<"+";
changecolor(15);
append(24,19);
gotoxy(24,19);
cout<<">";
//add snake in heap

food(1);food(2);food(3);food(4);
gotoxy(4,1);
//initialize score with 0
score();
}
void makesnake_con(){
//	if(distance_travelled!=0)
//	return;
FILE *fptr;
fptr=fopen("snake.txt","r");
//retrieving data from file
char a[10000];int i=0;
char ch=fgetc(fptr);
while(ch!=EOF){
	a[i]=ch;
	ch=fgetc(fptr);
	i++;	
}
a[i]='\0';
//for ll
int x_pos=-1,y_pos=-1,y_prevpos,x_prevpos;
char pos='x';
int j=0;
for(int i=1;a[i]!='@';i++){
	if( (a[i]>=48 && a[i]<=57) && (a[i+1]>=48 && a[i+1]<=57) ){//for 2 digit
		if(pos=='x'){
		x_pos=(a[i]-48)*10 + (a[i+1]-48);
	    pos='y';
		}
		else{
		y_pos=(a[i]-48)*10 + (a[i+1]-48);
	    pos='x';
		}
	}
	if( (a[i-1]==32 && a[i+1]==',') || (a[i-1]==',' && a[i+1]==32) ){//for 1 digit
		if(pos=='x'){
		x_pos=a[i]-48;
	    pos='y';
		}
		else{
		y_pos=a[i]-48;
	    pos='x';
		}	
	}
	if(x_pos!=-1 && y_pos!=-1){
		x_prevpos=x_pos;y_prevpos=y_pos;
		append(x_pos,y_pos);
		changecolor(10);
        gotoxy(x_pos,y_pos);
        cout<<"+";
		x_pos=-1;y_pos=-1;
	}
	j++;
}
//for food
x_pos=-1;y_pos=-1;
pos='x';
int foodshow_count=1;
int k=j+2;
for(int i=j+2;a[i]!='@';i++){
if( (a[i]>=48 && a[i]<=57) && (a[i+1]>=48 && a[i+1]<=57) ){//for 2 digit
		if(pos=='x'){
		x_pos=(a[i]-48)*10 + (a[i+1]-48);
	    pos='y';
		}
		else{
		y_pos=(a[i]-48)*10 + (a[i+1]-48);
	    pos='x';
		}
	}
	if( (a[i-1]==32 && a[i+1]==',') || (a[i-1]==',' && a[i+1]==32) ){//for 1 digit
		if(pos=='x'){
		x_pos=a[i]-48;
	    pos='y';
		}
		else{
		y_pos=a[i]-48;
	    pos='x';
		}	
	}
	if(x_pos!=-1 && y_pos!=-1){
		//cout<<x_pos<<","<<y_pos<<endl;
		show_food(x_pos,y_pos,foodshow_count);
		foodshow_count++;
		x_pos= -1;y_pos=-1;
	}
	k++;	
}
//for score
int no;
int prev_score=0;
j=k+1;
for(i=k+1;a[i]!='@';i++){
	no=a[i]-48;
	prev_score=prev_score*10 + no;
	j++;
}
myscore=prev_score;
myscore--;
score();
//distance travelled
int prev_distravelled=0;
for(i=j+1;a[i]!='@';i++){
	no=a[i]-48;
	prev_distravelled=prev_distravelled*10 + no;
}
distance_travelled=prev_distravelled;
//c_x c_y
i++;
if( (a[i]>=48 && a[i]<=57) && (a[i+1]>=48 && a[i+1]<=57) )
{
c_x=(a[i]-48)*10 + (a[i+1]-48);
i+=3;
}
else{
	c_x=a[i]-48;
	i+=2;
}

if( (a[i]>=48 && a[i]<=57) && (a[i+1]>=48 && a[i+1]<=57) )
{
c_y=(a[i]-48)*10 + (a[i+1]-48);
i+=3;
}
else{
	c_y=a[i]-48;
	i+=2;
}
//for direction
direction=a[i];
gotoxy(x_prevpos,y_prevpos);//for head
changecolor(15);
	if(direction=='w')
	cout<<"^";
	else if(direction=='d')
	cout<<">";
	else if(direction=='s')
	cout<<"v";
	else if(direction=='a')
	cout<<"<";
i+=2;
//for temp control and control
control=a[i];
temp_control=a[i];
}
void want_continue(){
	system("cls");
	cout<<"Do you want to continue y/n : ";
	char w_c;
	w_c=getchar();
	fflush(stdin);
	system("cls");
		if(w_c=='y')
		makesnake_con();
		else
		makesnake_new();//******>	
	}
int main(){
	srand(time(0));
	font();
	want_continue();
	Lines();
	startgame();
	getchar();
	getchar();
		return 0;
}
