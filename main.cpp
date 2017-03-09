//sodoku game code

#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include<fstream.h>
int level()
{
	cleardevice();
	int x=getmaxx();
	int y=getmaxy();
	int a=x/4;
	int b=y/4;
	setcolor (LIGHTBLUE);
	settextstyle (3, 1,9) ;
	outtextxy ( x/13-55,y/13+15 , "SODOKU");
	gotoxy (a,b);
	textcolor (5);
	setcolor (WHITE);
	rectangle(a,b,a+150,b+50);
	settextstyle (1,0,3);
	setcolor (LIGHTGREEN);
	outtextxy ( a+45,b+8 ,"EASY");
	setcolor (WHITE);
	rectangle(a,b+100,a+150,b+150);
	settextstyle (1,0,3);
	setcolor (LIGHTGREEN);
	outtextxy ( a+30,b+108 ,"MEDIUM");
	setcolor (WHITE);
	rectangle(a,b+200,a+150,b+250);
	settextstyle (1,0,3);
	setcolor (LIGHTGREEN);
	outtextxy ( a+20,b+208 ,"DIFFICULT");

	int kyh=0,flag=0;
	setcolor(RED);
	rectangle(a,b+(flag*100),a+150,b+(flag*100)+50);
	settextstyle (1,0,2);
	flag=1;
	setcolor(YELLOW);
	textcolor(GREEN);
	outtextxy (a+275 ,b+60 , "Use ");
	outtextxy (a+355,b+60 , "To ");
	outtextxy (a+280 , b+100, "<--");
	outtextxy (a+325 , b+100, " -->");
	settextstyle (1,1,3)  ;
	outtextxy (a+310, b+60, "-->");
	settextstyle (1,1,3)  ;
	outtextxy (a+310, b+120, "<--");
	settextstyle (1,0,2);
	outtextxy (a+265, b+150, "Move");
	outtextxy (a+340 , b+150, "Cursor");
	rectangle (getmaxx()/5*3, getmaxy()-80,getmaxx()-50, getmaxy()-40);
	outtextxy ( getmaxx()/5*3+15 ,getmaxy()-110, "Hit Twice To Exit");

	outtextxy ( getmaxx()/7*5-10 ,getmaxy()-75, "Spacebar");
	{
		setcolor (BLUE);
		settextstyle ( 3,0,3);
		outtextxy (getmaxx()-275 , 75 ,"KEY CONTROLLED GAME");
	}

	{
		setcolor (RED);
	settextstyle (1,0,3);
	outtextxy(getmaxx()/5*3+15,150,"Controls of Game");
	}

	while(1)
	{
		kyh=getch();
		if(kyh==80 && flag<3  )
		{
		setcolor(WHITE);
		rectangle (a,b+((flag-1)*100),a+150,b+((flag-1)*100)+50);
		setcolor(RED);
		rectangle(a,b+(flag*100),a+150,b+(flag*100)+50);
		flag++;
		}
		if (kyh==72 && flag>1)
		{
		setcolor(WHITE);
		rectangle(a,b+((flag-1)*100),a+150,b+((flag-1)*100)+50);
		setcolor(RED);
		rectangle(a,b+((flag-2)*100),a+150,b+((flag-2)*100)+50);
		flag--;
	}
	if(kyh==13)
	{
		cleardevice();
		break;
	}
	}//while

	return(flag);
	}//fun

void setarray(int a[9][9],int k)
{
	fstream f;
	if(k==1)
	f.open("unsol1.txt",ios::in);
	if(k==2)
	f.open("unsol2.txt",ios::in);
	if(k==3)
	f.open("unsol3.txt",ios::in);
	if(!f)
	{	cout<<"File open error";
	getch();
	exit(0);
	}
	char c;
	int conv=0;
	int line=0,i,j;
	randomize();
	int r=random(3)*82;
	for( j=0;j<r;j++)
	f.get(c);
	for(i=0;i<9;i++)
	for(j=0;j<9;j++)
	{ f.get(c);
	a[i][j]=c-48;
	}

	f.close();
	}

	main()
	{
	int x,y,gd=DETECT , gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	int le=1;
	le=level();
	int xmax=getmaxx();
	char y4[2]=" ";
	for (int p=0;p<=10;p=p+1)
	{
	setcolor(15);
	line(xmax/9*p,0,xmax/9*p ,getmaxy());
	setcolor(10);
	line(xmax/3*p+1,0,xmax/3*p+1 ,getmaxy());
	line(xmax/3*p+2,0,xmax/3*p+2 ,getmaxy());
	line(xmax/3*p+5/2,0,xmax/3*p+5/2 ,getmaxy());
	line(getmaxx(),0,getmaxx() ,getmaxy());
	line(getmaxx()-1,0,getmaxx()-1 ,getmaxy());
	line(getmaxx()-2,0,getmaxx()-2 ,getmaxy());
	}
	int ymax=getmaxy();
	for (int l=0;l<=10;l++)
	{
	setcolor(15);
	line ( 0,ymax/9*l,getmaxx(),ymax/9*l) ;
	setcolor(10);
	line ( 0,ymax/3*l+1,getmaxx(),ymax/3*l+1);
	line ( 0,ymax/3*l+2,getmaxx(),ymax/3*l+2);
	line ( 0,ymax/3*l+5/2,getmaxx(),ymax/3*l+5/2);
	}

	setcolor(15);
	y=ymax/9  ; x=xmax/9;
	int j=x/2+10;
	line (x-j,  y-15, x-30,y-15);

	int arr1[9][9],arr2[9][9];
	setarray(arr1,le); setarray(arr2,le);
	char y3[2]=" ";
	int g1,g2;
	for  (g1=0;g1<9;g1++)
	{
	for(g2=0;g2<9;g2++)
	{  if (arr1[g1][g2]!=0)
	{ setcolor(YELLOW);
	y3[0] =(char)arr1 [g1][g2]+48;
	settextstyle (1,0,3);
	outtextxy ( getmaxx()/9*g2+30, getmaxy()/9*(g1+1)-40,y3 );
	}
}
}
	setcolor (WHITE);
	int kyh=0,flag1=0,flag2=0,g3=0,g4=0;
	int col =0,row=0;
	while (1)
	{  kyh=getch();
	if(kyh==80 && flag1<8)
	{
setcolor(getbkcolor()) ;
line (x-j,y-15,x-30,y-15);
y=y+ymax/9;
setcolor (15);
line (x-j ,y-15,x-30,y-15);
flag1++;
row++;
//arr1
}//if80
if (kyh==32)
break;
if ( kyh==72  && flag1>0)
{ setcolor(getbkcolor()) ;
line (x-j,y-15,x-30,y-15);
y=y-ymax/9;
setcolor (15);
line (x-j ,y-15,x-30,y-15);
flag1--;
row--;

}
if (kyh==75 && flag2>0)
{
setcolor(getbkcolor()) ;
line (x-j,y-15,x-30,y-15);
x=x-xmax/9;
setcolor (15);
line (x-j ,y-15,x-30,y-15);
flag2--;
col--;

}
if (kyh==77 && flag2<8)
{
setcolor(getbkcolor()) ;
line (x-j,y-15,x-30,y-15);
x=x+xmax/9;
setcolor (15);
line (x-j ,y-15,x-30,y-15);
flag2++;
col++;

}


if (kyh>'0' && kyh<='9')
{  int z;
z=kyh-48;

if (arr1[row][col]==0)
{
setcolor(getbkcolor());
outtextxy ( getmaxx()/9*col+30, getmaxy()/9*(row+1)-40,y4);
setcolor(WHITE);
y4[0]=kyh;

settextstyle (1,0,3);
outtextxy ( getmaxx()/9*col+30, getmaxy()/9*(row+1)-40,y4);
arr2[row][col]=z;
}
}

kyh=0 ;
}
getch();
int check=0,flag5=0;
for (int chk1=0;chk1<9;chk1++)
{ for (int chk2=0;chk2<9;chk2++)
{
check=check+arr2[chk1][chk2];
}
if (check==45)
{flag5=1;
}
else
break;
}
cleardevice();
gotoxy ( getmaxx()/2,getmaxy()/2);
if (flag5==1)
{
setcolor (GREEN);
settextstyle (3,0,8);
outtextxy ( getmaxx()/2-140, getmaxy()/2-50,"CORRECT ");
}
else
{
setcolor (GREEN);
settextstyle (3,0,8);
outtextxy ( getmaxx()/2-120, getmaxy()/2-50,"WRONG");
}
int kyh2=0;
kyh2=getch();
if (kyh==32)
{
cleardevice();
setcolor (YELLOW);
settextstyle (3,0,5);
outtextxy (getmaxx()/9*3-20,getmaxy()/9-10, "THANK YOU!!");
setcolor (WHITE);
settextstyle (1,0,2);
outtextxy (getmaxx()/9*3-40,getmaxy()/3, "Do You Want To Continue??");
setcolor (RED);
rectangle(getmaxx()/9*3-20,getmaxy()/2,getmaxx()/9*3+80, getmaxy()/2+50);
setcolor (WHITE);
rectangle(getmaxx()/9*3+120,getmaxy()/2,getmaxx()/9*3+220, getmaxy()/2+50);
settextstyle (1,0,2);
outtextxy(getmaxx()/9*3,getmaxy()/2+10,"Retry");
outtextxy(getmaxx()/9*3+150,getmaxy()/2+10,"Exit");
int kyh1=0,flag6=0;
while (1)
{

kyh1=getch();
if (kyh1==77)//right
{ setcolor (WHITE);
rectangle(getmaxx()/9*3-20,getmaxy()/2,getmaxx()/9*3+80, getmaxy()/2+50);
setcolor (RED);
rectangle(getmaxx()/9*3+120,getmaxy()/2,getmaxx()/9*3+220,getmaxy()/2+50);
flag6=1;
}

if (kyh1==75)
{  setcolor (WHITE);
rectangle(getmaxx()/9*3+120,getmaxy()/2,getmaxx()/9*3+220, getmaxy()/2+50);
setcolor (RED);
rectangle(getmaxx()/9*3-20,getmaxy()/2,getmaxx()/9*3+80, getmaxy()/2+50);
flag6=0;
}
if (kyh1==13)
break;
}//while
if (flag6==1)
{cleardevice ();

settextstyle (1,0,4);
outtextxy ( getmaxx()/9+120,getmaxy()/5,"Developed By:- ") ;
setcolor (LIGHTGREEN);
outtextxy ( getmaxx()/9+75,getmaxy()/5*2, "Aditya Narain Gupta");
setcolor (YELLOW);
outtextxy ( getmaxx()/9+120,getmaxy()/5*3, "Ayush Mishra");
setcolor (CYAN);
outtextxy(getmaxx()/9+122, getmaxy()/5*4 ,"Safal Bahare");
getch();
cleardevice();
outtextxy (getmaxx()/5,getmaxy()/2 , "@ Students of SPSEC @");
getch();
exit(0);
}
else
main();
getch();
}

getch();
closegraph();
return 0;
}
