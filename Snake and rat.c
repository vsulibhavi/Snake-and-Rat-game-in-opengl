/*Project developed by 

Sandeep Panchmukhi
sandeep.panchamukhi@gmail.com
  
Vishal sulibhavi 
vsulibhavi@gmail.com

Sandeep Ankolakar
sandeep.ylp@gmail.com



*/




#include<stdio.h>
#include<gl/glut.h>
#include<stdlib.h>
#include<signal.h>
#include<math.h>
#include<string.h>

#include<windows.h>
#define UP '8'
#define RIGHT '6'
#define DOWN  '2'
#define LEFT  '4' 


SOCKET s,c,s1;
char buf[15],ch[15];
SOCKET clientsocid;
DWORD threadid;
HANDLE threadhandle;

char si[5]={'2','\0'};
char si2[5]={'2','\0'};
int fulfill=1,plife=3;
int compu=0,tit;
int count,transvar=4;
int no_of_pl=1;
int sound=0,key; 
int mode=0,confail=0;
int intelligence=4,lan;
int n=30,flag=0;
int j,carr;
int i=1,size=2,size2=2;
int x,y;
int printed=0;
int t[100][2],t2[100][2];			
char state[100],state2[100];
int score=0;
int screen=1,po;
void screen3(void);
char str[5]={'0','\0'},bstr[5]={'0','\0'};
void write(char *str,int x,int y);
int hurdle_check(int x,int y);
void vitoa(int val,char s[]);
int best_score=0;
int pro=0;
int life=3;
FILE *fp;
void timer(int val);
void ck_if_ea_it(void);
int state_rat=0;
int mod(int val);
void sock_create();
void rectangle()
{
		

		glBegin(GL_POINTS);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(2,2);
		glColor3f(0.8+i*0.05,0.3+i*0.05,0.3);	
		glVertex2i(0,0);
	
		glEnd();
	
	glFlush();
	
}

void rect2()
{
		

		glBegin(GL_POINTS);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(2,2);
		glColor3f(0.9+i*0.05,0.9+i*0.05,0.1);	
		glVertex2i(0,0);
	
		glEnd();
	
	glFlush();
	
}

void snake_or_rat_tra(int sr)
{    
	if(no_of_pl==1 && lan==0)
	{
		write("score:",20,700);write(str,140,700);
		write("best score:",250,700);write(bstr,420,700);
	}
	if(no_of_pl==2 || lan==1)
	{
			write("score1:",20,700);write(si,140,700);
			write("score2:",210,700);write(si2,320,700);
	}
			
	if(sr==0)
	{
		glLoadIdentity();
		
		switch(state_rat)
		{
		case UP:		y=(y+10)%760;
						break;
		
		case RIGHT:			x=(x+10)%1020;
							break;
		
		case DOWN:			y=(y-10);
							if(y<0) y=y+760;
							break;
		case LEFT :			x=(x-10);
							if(x<0) x=x+1020;
		}
	}

		
	else if(sr==2)
	{
	for(i=1;i<=size;i++)	
	{
			glLoadIdentity();
		//	glColor3f(0.8+i*0.05,0.3+i*0.05,0.3);	
		
		
		switch(state[i])
		{
		case UP :		
						
						
							t[i][1]=(t[i][1]+20)%760;
							glTranslated(t[i][0],t[i][1],0);
							
							rectangle();
							
								
					
						
							
					
						break;
		case RIGHT :		
								
									t[i][0]=(t[i][0]+20)%1020;
									glTranslated(t[i][0],t[i][1],0);
							
									rectangle();
								
						
							break;
		case DOWN :				
									t[i][1]=(t[i][1]-20);
									if(t[i][1]<=0)t[i][1]=(t[i][1]+760);
								
									glTranslated(t[i][0],t[i][1],0);
						
									rectangle();
									
								
							
				
							break;
		case LEFT  :			
									t[i][0]=(t[i][0]-20);
									if(t[i][0]<=0)t[i][0]=(t[i][0]+1020);
			
			
								glTranslated(t[i][0],t[i][1],0);
					
								rectangle();
								
								
								
								break;
		}	
		
	}
	if(no_of_pl==2)
	{
	for(i=1;i<=size2;i++)	
	{
	
		//	glColor3f(0.9+i*0.05,0.9+i*0.05,0.1);
			
		glLoadIdentity();
		
		switch(state2[i])
		{
		case UP :		
						
						
							
							t2[i][1]=(t2[i][1]+20)%760;
							glTranslated(t2[i][0],t2[i][1],0);
							rect2();
								
						
							

					
						break;
		case RIGHT :		
								
									
									t2[i][0]=(t2[i][0]+20)%1020;
									glTranslated(t2[i][0],t2[i][1],0);
							
									rect2();
									
						
									break;
		case DOWN :				
									
									t2[i][1]=(t2[i][1]-20);
									if(t2[i][1]<=0)t2[i][1]=(t2[i][1]+760);
								
									glTranslated(t2[i][0],t2[i][1],0);
						
									rect2();
									
							
				
							break;
		case LEFT  :			
									
								t2[i][0]=(t2[i][0]-20);
									if(t2[i][0]<=0)t2[i][0]=(t2[i][0]+1020);
			
			
								glTranslated(t2[i][0],t2[i][1],0);
					
								rect2();
								
								
								
								break;
		}	
	
	
	
	}
			
	}	
	}	
		
			
					   
		
		
		
		
}
	
void intelligence1()
{
	if(mod(state[1]-state_rat)==6 && mod(t[1][1]-y)<=120 && mod(t[1][0]-x)<=10)
	{
		if(state_rat=='8')
		state_rat='2';
		else 
			state_rat='8';
	}
	if(mod(state[1]-state_rat)==2 && mod(t[1][0]-x)<=120 && mod(t[1][1]-y)<=10)
	{	
		if(state_rat=='4')
		state_rat='6';
		else 
		state_rat='4';

	}
}

void intelligence2()
{
	if(mod(state[1]-state_rat)==6 && mod(t[1][1]-y)<=120 && mod(t[1][0]-x)<=10)
	{
		if(state_rat=='8')
		state_rat='6';
		else 
			state_rat='4';
	}
	if(mod(state[1]-state_rat)==2 && mod(t[1][0]-x)<=120 && mod(t[1][1]-y)<=10)
	{	
		if(state_rat=='4')
		state_rat='2';
		else 
		state_rat='8';

	}
}
void intelligence3()
{
		if(mod(state[1]-state_rat)==6 && mod(t[1][1]-y)<=120 && mod(t[1][0]-x)<=10)
	{
		if(state_rat=='8')
		state_rat='6';
		else 
			state_rat='4';
	}
	else if(mod(state[1]-state_rat)==2 && mod(t[1][0]-x)<=120 && mod(t[1][1]-y)<=10)
	{	
		if(state_rat=='4')
		state_rat='2';
		else 
		state_rat='8';

	}
	else if((state[1]-state_rat)==0 &&   mod(t[1][0]-x)<=120 && mod(t[1][1]-y)<=10) 
	{
			if((x>=500 && x<=680) || (x>=800 && x<=980) || (x>=800 && x<=980))
			{
				state_rat=UP;
			}

	}
}

void eatable()
{	
	int rem;
	
	
//	glLoadIdentity();
	
	while(printed==0)	
	{
		x=rand()%1000;y=rand()%740;
		rem=x%20;
		x=x-rem;
			rem=y%20;
		y=y-rem;
	
		switch(rand()%4)
		{
		case 0: state_rat=LEFT;
				break;
		case 1: state_rat=UP;
				break;
		case 2: state_rat=RIGHT;
				break;
		case 3: state_rat=DOWN;
				break;
		}
		if(hurdle_check(x,y) || y==0|| x==0 )
		
		
		continue;
		
		
		printed=1;count++;
		
	}	
		
			snake_or_rat_tra(0);
		
		
		if(hurdle_check(x,y) && (state_rat==LEFT ||state_rat==RIGHT))
		{
			
		
			if(state_rat==LEFT)
				x=x+20;
			else if(state_rat==RIGHT)
				x=x-20;
			switch(rand()%2)
			{
			case 0 :    
						state_rat= UP;
						break;
			case 1:      state_rat=DOWN;
						break;
			}
		}
		if(hurdle_check(x,y) && (state_rat==UP ||state_rat==DOWN))
		{
			
			if(state_rat==UP)
				y=y-20;
			else if(state_rat==DOWN)
				y=y+20;
			switch(rand()%2)
			{
			case 0 :    
						state_rat= LEFT;
						break;
			case 1:      state_rat=RIGHT;
						break;
			}
		}
		
	
	
		glBegin(GL_POINTS);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(x+2,y+2);

		glColor3f(0.3,0.8,0.5);
		glVertex2i(x,y);
		glEnd();
		if(no_of_pl==1)
		{
			switch(intelligence)
		{
		case 2 :  intelligence1();
					break;
		case 3 :  intelligence2();
					break;
		case 4 :  intelligence3();
					break;
		}
		}
		if(y==0 && (state_rat==LEFT || state_rat==RIGHT))
			state_rat=UP;
		if(x==0 && (state_rat==UP || state_rat==DOWN))
			state_rat=LEFT;
		
		
		glFlush();
		
	


}
int mod(int val)
{
	if(val<0)
		return -val;
	return val;
}
void update_sna()
{
	for(j=size;j>1;j--)
	{
		state[j]=state[j-1];

	}
	if(no_of_pl==2)
	for(j=size2;j>1;j--)
	{
		state2[j]=state2[j-1];

	}



}
void check()
{
	int diff1= mod((t[1][0]-x))<20;
	int   diff2= mod((t[1][1]-y))<20;
	int diff3= mod((t2[1][0]-x))<20;
	int   diff4= mod((t2[1][1]-y))<20;
	if(diff1 && diff2)
	{	if(sound==1)
		PlaySound("bell1.WAV",NULL,SND_FILENAME|SND_ASYNC);
		printed=0;
				
		size++;
		if(no_of_pl==1)
		{
			score=score+n*size*intelligence;
		
			vitoa(score,str);

		}
		vitoa(size,si);
			vitoa(size,ch);
		
			t[size][1]=t[size-1][1];
	
			t[size][0]=t[size-1][0];
			
		if(size==20 && lan==1)
			screen=3;
		
	}
	if(no_of_pl==2)	
	 if(diff3 && diff4)
	{	if(sound==1)
		PlaySound("bell1.WAV",NULL,SND_FILENAME|SND_ASYNC);
		printed=0;
				
		size2++;
		vitoa(size2,si2);
		
	
			t2[size2][1]=t2[size2-1][1];
			t2[size2][0]=t2[size2-1][0];
	
		
		
		
	}



}

int shortcutd(int x,int y)
{

	return ((t2[1][1]-0)+(760-y));
}
int shortcutu(int x,int y)
{

	return ((760-t2[1][1])+(y-0));
}		

int shortcutl(int x,int y)
{

	return ((t2[1][0]-0)+(1020-x));
}
int shortcutr(int x,int y)
{

	return ((1020-t2[1][0])+(x-0));
}		

void computer()
{
	int boo=0;
	
	
	switch(fulfill)
	{
		case 1:  
				if( (state2[1]==LEFT ||state2[1]==RIGHT) )
		
				{
			
					if((t2[1][1]-y)<=-20)
					{if( mod(t2[1][1]-y) <=  shortcutd(t2[1][1],y))
					{
						state2[1]=UP;
					}
					else
					{
						state2[1]=DOWN;
					}
					}
								
				
						if(	(t2[1][1]-y)>=20)
						{
						if( mod(t2[1][1]-y) <=  shortcutu(t2[1][1],y))
						{
							state2[1]=DOWN;
						}
						else
						{
							state2[1]=UP;
						}
						}
				}
					boo=  ((t2[1][1]-y)>=-20 && (t2[1][1]-y)<=20);
					if(boo)
					{
						fulfill=2;
					
					}
					break;

		case 2:   
					if( (state2[1]==UP ||state2[1]==DOWN) )
		
				{
			
					if((t2[1][0]-x)<=-20)
					if( mod(t2[1][0]-x) <=  shortcutd(t2[1][0],x))
					{
						state2[1]=RIGHT;
					}
					else
					{
						state2[1]=LEFT;
					}
				
								
				
						if(	(t2[1][0]-x)>=20)
						{
						if( mod(t2[1][0]-x) <=  shortcutu(t2[1][0],x))
						{
							state2[1]=LEFT;
						}
						else
						{
							state2[1]=RIGHT;
						}
						}
				}
				boo=((t2[1][0]-x)>=-20 && (t2[1][0]-x)<=20);
					  if(boo)
					  {
						  fulfill=1;
						 
					  }	
						 break;
	
	}
	
}


		
		
hurdle()
{
	int i;
	if(compu==0 && lan==0 && no_of_pl==1)
	{
	glLoadIdentity();
	glBegin(GL_POINTS);

	for(i=1;i<=8;i++)
	{
		glColor3f(0.4,0.0,0.0);
		glVertex2i(497+i*20,397);
		glColor3f(0.6,0.0,0.0);
		glVertex2i(500+i*20,400);
	}
	for(i=1;i<=8;i++)
	{
		glColor3f(0.4,0.0,0.0);
		glVertex2i(197+i*20,197);
		glColor3f(0.6,0.0,0.0);
		glVertex2i(200+i*20,200);
	}
	
	for(i=1;i<=8;i++)
	{
		glColor3f(0.4,0.0,0.0);
		glVertex2i(797+i*20,597);
		glColor3f(0.6,0.0,0.0);
		glVertex2i(800+i*20,600);
	}
	
	
	glEnd();
	}
	//	glFlush();
}

void write(char *str,int x,int y)
{
		
	glLoadIdentity();
	glTranslated(x,y,0);
	if(tit==1)
	{	
 		glScalef(0.4,0.4,0);
	}
	else
	glScalef(0.25,0.22,0);
	glColor3f(1.0,1.0,1.0);
	while(*str != '\0')
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*str);
		str++;
	}
	
		

}
void rect4menu(int x, int y)
{
	y=y+transvar * -50;
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(x-4,y-7);
		glVertex2i(x-4,y+33);
		glVertex2i(x+426,y+33);
		glVertex2i(x+426,y-7);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2i(x,y-10);
		glVertex2i(x,y+30);
		glVertex2i(x+430,y+30);
		glVertex2i(x+430,y-10);
	glEnd();
}

void backbutton()
{
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
		glVertex2i(847,52);
		glVertex2i(947,52);
		glVertex2i(947,102);
		glVertex2i(847,102);
		
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
		glVertex2i(850,50);
		glVertex2i(950,50);
		glVertex2i(950,100);
		glVertex2i(850,100);
		
	glEnd();
	if(screen==1|| (screen==3 && confail==0))
		write("EXIT",868,60);
	else if(screen==6 || screen==5 ||screen==7 ||(screen==3 && confail==1))
		write("BACK",860,60);
}
screen1()
{
	
	if(po==0 && sound==1)
	{
		PlaySound("GAMESOUND.WAV",NULL,SND_FILENAME|SND_ASYNC);po=1;
	}
	rect4menu(280,500);
	tit=1;
	write("----------------",190,690);
	write("SNAKE AND RAT GAME",200,650);
	write("----------------",190,610);
	tit=0;
	write("PLAY",450,500);
	write("PLAY WITH COMPUTER",310,450);
	write("GAME SETTINGS",360,400);
	write("HELP (SINGLE PLAYER)",300,350);
	write("HELP (TWO PLAYER)",330,300);

	backbutton();
}
void ck_if_ea_it()
{
	if(no_of_pl==1)
	{for(i=1;i<size;i++)
		{
			for(j=i+1;j<=size;j++)
			{
				if(t[i][0]==t[j][0] && t[i][1]==t[j][1])
				{
					
					
					glutPostRedisplay();
					if(sound==1)
					PlaySound("1.WAV",NULL,SND_FILENAME|SND_ASYNC);
				
					screen=3;
					screen3();
					
					
				}
			}
		}
	if(no_of_pl==2)
	for(i=1;i<size2;i++)
		{
			for(j=i+1;j<=size2;j++)
			{
				if(t2[i][0]==t2[j][0] && t2[i][1]==t2[j][1])
				{
					
				
					glutPostRedisplay();
					if(sound==1)
					PlaySound("1.WAV",NULL,SND_FILENAME|SND_ASYNC);
			//		screen=3;
			//		screen3();
					
					
				}
			}
		}

	}

}
int hurdle_check(int x,int y)
{
		
		int c1=(x>=500 && x<=680),c2=(y>=400 && y<=410);
		if(compu==0 && lan==0 && no_of_pl==1)
		{
		if(c1 && c2)
		{
			
			
			return 1;
			

		}
		if((x>=200 && x<=380) && (y>=200 && y<=210))
		{
			return 1;
			

		}
		if((x>=800 && x<=980) && (y>=600 && y<=610))
		{
			return 1;
			

		}
		}
		return 0;
		
}
void vitoa(int val,char s[])
{
	int  rem,i=0;
	while(val>0)
	{
		
	
			rem=val%10;
			val=val/10;
		
	
		
		s[i]=48+rem;
		i++;
	}
	
	s[i]='\0';
	if(s[0]=='\0')
	{	
		s[0]=48;
		s[1]='\0';
	}
	strrev(s);	
	

}


void screen3()
{
	
	char s1[20],s2[20];
	plife=3;
	if(confail==1)
	{
		write("Connection Failed",400,350);
		backbutton();

	}
	else if(confail==0)
	{
	if(no_of_pl==1 && lan==0)
	{
	tit=1;
	write("GAME OVER!!!..",330,600);
	tit=0;
	vitoa(score,str);
	vitoa(best_score,bstr);
	write("LAST BEST SCORE :",100,400);
	write(bstr,500,400);
	write("YOUR SCORE :",100,300);
	write(str,390,300);
	if(best_score <=score)
	{
		
		
		write("CONGRATS !!!!",100,350);
	}
	
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
		glVertex2i(41,52);
		glVertex2i(174,52);
		glVertex2i(174,104);
		glVertex2i(41,104);
		
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
		glVertex2i(44,50);
		glVertex2i(176,50);
		glVertex2i(176,102);
		glVertex2i(44,102);
		
	glEnd();
	if(lan!=1)
	{
	write("RETRY",60,60);
	backbutton();
	}
	}
	else if(no_of_pl==2 || lan==1)
	{
		if(compu==1)
		{
			write("player 1 score:",100,700);
			vitoa(size,s1);
			write(s1,400,700);
			write("Computer score:",100,650);
			vitoa(size2,s2);
			write(s2,400,650);
			if(size>size2)
				write("PLAYER1 WON THE GAME",100,600);
			else if(size==size2)
				write("DRAW",100,600);
			else
				write("Computer WON THE GAME",100,550);
		}
		else
		{
		write("player 1 score:",100,700);
		vitoa(size,s1);
		write(s1,400,700);
		write("player 2 score:",100,650);
		vitoa(size2,s2);
		write(s2,400,650);
		if(size>size2)
			write("PLAYER1 WON THE GAME",100,600);
		else if(size==size2)
			write("DRAW",100,600);
			else
				write("PLAYER2 WON THE GAME",100,550);
		}
		if(lan!=1)
		{
glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
		glVertex2i(41,52);
		glVertex2i(174,52);
		glVertex2i(174,104);
		glVertex2i(41,104);
		
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
		glVertex2i(44,50);
		glVertex2i(176,50);
		glVertex2i(176,102);
		glVertex2i(44,102);
		
	glEnd();
	write("RETRY",60,60);
	backbutton();
		}
	
	}
	}
	
}
void screen5()
{
	
	write("Use the arrows to move the snake",20,700);
	write("to move the snake in the desired  direction.",20,650);
	
	write("Score & best score is displayed on the screen.",20,600);
	write("The user is free to move on the scores.",20,550);
	write("Press space  to pause & q to quit game",20,500);
	
	write("SEE GAME SETTINGS FOR MORE INFORMATION",20,200);
	backbutton();
		


}
void screen7()
{
	write("player1 should use arrows to move snake.",20,700);
	write("player2 should use w a s d to move the snake",20,650);
	write("score= size of snake",20,600);
	write("20 rats are generated ",20,550);
	write("if a player hits hurdle the size reduces by 1",20,500);
	write("game ends if the size of snake is 0 ",20,450);
	write("a player who has greater score wins",20,400);
	backbutton();
}
void lifedraw(int x, int y)
{
	glLoadIdentity();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(x,y);
		glVertex2i(x+20,y);
		glVertex2i(x+20,y+20);
		glVertex2i(x,y+20);
	glEnd();
}
void screen2()
{
	if(po==0 && sound==1)
	{
		PlaySound("GAMESOUND.WAV",NULL,SND_FILENAME|SND_ASYNC);po=1;
	}
			hurdle();
		
			snake_or_rat_tra(2);
			ck_if_ea_it();
			update_sna();
			eatable();
		check();
	
		if(hurdle_check(t[1][0],t[1][1]) && no_of_pl==1 )
		{
			
			
			glutPostRedisplay();
			if(sound==1)
			PlaySound("1.WAV",NULL,SND_FILENAME|SND_ASYNC);
			plife=plife-1;
			if(plife==0)
			{
			screen=3;
			screen3();
			}		
		}
		if(no_of_pl==2)
		{
		
		if(hurdle_check(t[1][0],t[1][1]))
		{
			
			
		//	glutPostRedisplay();
			if(sound==1)
			PlaySound("1.WAV",NULL,SND_FILENAME|SND_ASYNC);
			if(compu==0)
			{
				t[size][0]=0;t[size][1]=0;state[size]=0;
				size--;
			}
			vitoa(size,si);
			//		screen=3;
	//		screen3();
		}
			if(compu==1)
			computer();
		if(hurdle_check(t2[1][0],t2[1][1]))
		{
			
		

		//	glutPostRedisplay();
			if(sound==1)
			PlaySound("1.WAV",NULL,SND_FILENAME|SND_ASYNC);
				
			if(compu==0)
			{
				t2[size2][0]=0;t2[size2][1]=0;state2[size2]=0;
				size2--;
			}

			vitoa(size2,si2);			
		//		screen=3;
//			screen3();
		}

		if(size==0 || size2==0 || count==20 )
		{		screen=3;
				screen3();
		}

		}
		if(no_of_pl==1)
		{
		write("LIFE",850,20);
		if(plife==3)
		{
			for(i=0;i<3;i++)
				lifedraw(950+i*25,20);
		}
		else if(plife==2)
		{
			for(i=0;i<2;i++)
				lifedraw(950+i*25,20);
		}
		else if(plife==1)
		{
			for(i=0;i<1;i++)
				lifedraw(950+i*25,20);
		}
		}
}


		
void rectangle2(int x,int y)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,1.0,0.0);
	glVertex2i(x,y);
	glVertex2i(x,y+20);
	glVertex2i(x+20,y+20);
	glVertex2i(x+20,y);
	glEnd();
	if(carr==1)
	{
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.2,0.0);
		glVertex2i(x,y+1);
		glVertex2i(x+20,y+1);
		glVertex2i(x+10,y+19);
	glEnd();
	}
	else if(carr==0)
	{
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.2,0.0);
		glVertex2i(x,y+20);
		glVertex2i(x+20,y+20);
		glVertex2i(x+10,y);
	glEnd();
	}
}

void rectangle3(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.6,0.5);
	glVertex2i(x,y);
	glVertex2i(x,y+10);
	glVertex2i(x+10,y+10);
	glVertex2i(x+10,y);
	glEnd();
}

void screen6()
{
	char speed[6],inte[6];
	glPointSize(1.0);
	write("GAME SOUND : ",100,600);
	write("YES ",450,600);
	write("NO ",600,600);
	write("SNAKE SPEED :",100,450);
	vitoa(n,speed);
	write(speed,400,450);
	write("SKILL LEVEL OF RAT:",100,300);
	vitoa(intelligence,inte);
	write(inte,500,300);
	write("NO OF PLAYERS :",100,200);
	write("ONE",480,200);
	write("TWO",680,200);
	glLoadIdentity();
	carr=1;
	rectangle2(400,500);
	rectangle2(500,350);
	carr=0;
	rectangle2(400,400);
	
	rectangle2(500,250);
	carr=3;
	rectangle2(450,200);
	rectangle2(650,200);
	rectangle2(420,600);
	rectangle2(570,600);
	if(no_of_pl==1)
		rectangle3(455,205);
	else
		rectangle3(655,205);
	if(sound==1)
		rectangle3(425,605);
	else
		rectangle3(575,605);
	backbutton();
	glFlush();
}


void display(void)
{
	
	if(screen!=4)
	{
		glLoadIdentity();
	
	
		glClear(GL_COLOR_BUFFER_BIT);
		if(screen==1)
		{
		screen1();
		}
		if(screen==2)
		{
		
			screen2();
	
	
	
		}
	
	if(screen==3)
		screen3();
	  
	if(screen==5)
		screen5();
	
	if(screen==5)
		screen5();
	
		if(screen==6)
		screen6();
		if(screen==7)
		screen7();
		
		glutSwapBuffers();

	
	}

}

void keyboard(unsigned char key,int x,int y)
{
	
	
	
	if(screen==1)
	{
		if(key=='1')
		{		
			if(flag==0)
			{
			
				glutTimerFunc(100,timer,n);
				
			}	
			screen=2;
		}
		else if(key=='2')
		screen=5;
		
		
		else if(key=='3')
			screen=6;

		else if(key=='4')
		screen=7;
		else if(key=='5')
		{
			no_of_pl=2;
			compu=1;
			screen=2;
			if(flag==0)
			glutTimerFunc(100,timer,20);
			
		
		}
	//	PlaySound("button1.WAV",NULL,SND_FILENAME|SND_ASYNC);
				po=0;
	
	}
	else if(screen==5 && key=='b')
	{	screen=1;
		PlaySound("button1.WAV",NULL,SND_FILENAME|SND_ASYNC);
				po=0;
	}
	else if(screen==6  )
	{
		if(key=='b')
		{
			if(flag==0)
			{flag=1;	
			glutTimerFunc(100,timer,n);}
		
		screen=1;glLoadIdentity();glPointSize(20.0);
		
		
		}
		if(key=='1')
			no_of_pl=1;
		else if(key=='2')
			no_of_pl=2;
			
		if(key=='y'||key=='Y')
			sound=1;
		else if(key=='n'||key=='N') 
			sound=0;
		
		PlaySound("button1.WAV",NULL,SND_FILENAME|SND_ASYNC);
				po=0;
	}
	else if(screen==7 && key=='b')
		screen=1;
	
	else if(screen==3 && key=='e'||key=='E')
	{
		screen=2;
		size=2;
		po=0;
		state[1]='6';
		t[1][0]=140;
		t[1][1]=20;
		t[2][0]=120;
		t[2][1]=20;
		state[2]='6';
		size=2;
		x=0;y=0;
		glLoadIdentity();
		for(i=3;i<=50;i++)
		{
			state[i]=0;
			t[i][1]=0;
		}
		i=1;j=0;po=0;pro=0;
		if(no_of_pl==2)
		{	

			state2[1]='6';
			t2[1][0]=140;
			t2[1][1]=660;
			t2[2][0]=120;
			t2[2][1]=660;
			state2[2]='6';
			size2=2;
		
			for(i=3;i<=50;i++)
			{
				state2[i]=0;
				t2[i][1]=0;
			}
			count=0;
			vitoa(size,si);
			vitoa(size2,si2);
		}
		if(no_of_pl==1)
		{
			if(best_score < score)
			{	
				best_score=score;
		
				vitoa(best_score,bstr);
			}
			score=0;vitoa(score,str);
		}
		

	}
	
		
	if(screen==2 && (key=='0'|| key==' '|| key=='p'))
	{
		screen=4;
	}
	else if(screen==4 && (key=='0'|| key==' '|| key=='p'))
	{
		screen=2;
	}
	
	
	
	
	if(key=='w')
	{	if(state2[1]!=DOWN)
		state2[1]=UP;
	}

	else if(key=='d')
	{
		if(state2[1]!=LEFT)
		state2[1]=RIGHT;
	}
		
	else if(key=='s')
	{	
		if(state2[1]!=UP)
		state2[1]=DOWN;
	}

	else if(key=='a')
	{
		if(state2[1]!=RIGHT)
		state2[1]=LEFT;
	}


	else if(key=='q'||key=='Q') 
	{	
		fp=fopen("gfile.dat","wb");
		fwrite(&best_score,4,1,fp);
		fclose(fp);
		exit(0);
			
	
	}
		
	if(screen!=2)
	glutPostRedisplay();

	



}

void mouse(int btn,int states,int x,int y)
{
	
	if(screen==1 && btn==GLUT_LEFT_BUTTON && states==GLUT_DOWN)
	{
		switch(transvar)
		{
		case 0:if(flag==0)
			   {
			
			    	glutTimerFunc(100,timer,n);
			 	
			   }	
			   screen=2;
			   break;
		case 1:no_of_pl=2;
			   compu=1;
			   screen=2;
			   if(flag==0)
			   glutTimerFunc(100,timer,20);
				break;
		case 2:screen=6;
				break;
		case 3:	screen=5;
				break;
		case 4:screen=7;
				break;
		
		}
		y=768-y;
		if((x>=850 && x<=950)&& (y>=50 && y<=100))
		exit(0);
	}
	if(screen==6)
	{
	y=768-y;
	
	if(btn==GLUT_LEFT_BUTTON && states==GLUT_DOWN)
	{	
		if((x>=400 && x<=420) && (y>=500 && y<=520))
		{	n=n+5;
		
			if(sound==1)	
			PlaySound("button9.WAV",NULL,SND_FILENAME|SND_ASYNC);
		}
		
		else if((x>=400 && x<=420) && (y>=400 && y<=420))
		{	n=n-5;
		
			if(sound==1)	
			PlaySound("button9.WAV",NULL,SND_FILENAME|SND_ASYNC);
		}

		else if((x>=500 && x<=520) && (y>=350 && y<=370))
		{	if(intelligence<4)
			intelligence++;
			
		
			if(sound==1)	
			PlaySound("button9.WAV",NULL,SND_FILENAME|SND_ASYNC);
		}
		else if((x>=500 && x<=520) && (y>=250 && y<=270))
		{	if(intelligence>1)
			intelligence--;
			
		
			if(sound==1)	
			PlaySound("button9.WAV",NULL,SND_FILENAME|SND_ASYNC);
		}
		else if((x>=450 && x<=470)&& (y>=200 && y<=220))
		{
			no_of_pl=1;
		}
		else if((x>=650 && x<=670)&& (y>=200 && y<=220))
		{
			no_of_pl=2;
		}
		else if((x>=420 && x<=440)&& (y>=600 && y<=620))
		{
			sound=1;
		}
		else if((x>=570 && x<=590)&& (y>=600 && y<=620))
		{
			sound=0;
		}
		else if((x>=850 && x<=950)&& (y>=50 && y<=100))
		{
			if(flag==0)
			{
				flag=1;	
				glutTimerFunc(100,timer,n);
			}
		
			screen=1;
			glLoadIdentity();
			glPointSize(20.0);
		}
	}

		glutPostRedisplay();
		
		po=0;
		
		
	}

	if((screen==5||screen==7)&& btn==GLUT_LEFT_BUTTON && states==GLUT_DOWN)
	{
		y=768-y;
		if((x>=850 && x<=950)&& (y>=50 && y<=100))
			screen=1;
	}
	if(screen==3  && confail==0 && btn==GLUT_LEFT_BUTTON && states==GLUT_DOWN)
	{
		y=768-y;
		if((x>=44 && x<=176)&&(y>=50 && y<=102))
		{

			screen=2;
			size=2;
			po=0;
			state[1]='6';
			t[1][0]=140;
			t[1][1]=20;
			t[2][0]=120;
			t[2][1]=20;
			state[2]='6';
			size=2;
			x=0;y=0;
			glLoadIdentity();
			for(i=3;i<=50;i++)
			{
				state[i]=0;
				t[i][1]=0;
			}
			i=1;j=0;po=0;pro=0;
			if(no_of_pl==2)
			{	

				state2[1]='6';
				t2[1][0]=140;
				t2[1][1]=660;
				t2[2][0]=120;
				t2[2][1]=660;
				state2[2]='6';
				size2=2;
		
				for(i=3;i<=50;i++)
				{
					state2[i]=0;
					t2[i][1]=0;
				}
				count=0;
				vitoa(size,si);
				vitoa(size2,si2);
			}
			if(no_of_pl==1)
			{
				if(best_score < score)
				{	
					best_score=score;
		
					vitoa(best_score,bstr);
				}
				score=0;vitoa(score,str);
			}
		}
		else if((x>=850 && x<=950)&& (y>=50 && y<=100))
		{
			exit(0);
		}
	}
	 else if(screen==3 && confail==1 && btn==GLUT_LEFT_BUTTON && states==GLUT_DOWN)
	{
		 y=768-y;
		if((x>=850 && x<=950)&& (y>=50 && y<=100))
		{
			confail=0;
			screen=1;
		}
	
	}
	
}
void timer(int val)
{
	glutPostRedisplay();
		glutTimerFunc(1000/val,timer,val);

}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(20.0);
	gluOrtho2D(0,1024,0,768);
	glMatrixMode(GL_MODELVIEW);

	

}

void spec_keys(int key,int x,int y)
{
	
	switch(key)
	{
	case GLUT_KEY_UP: if(state[1]!=DOWN)
						state[1]=UP;
						break;

	case GLUT_KEY_DOWN:if(state[1]!=UP)
						state[1]=DOWN;
						break;
		
	case GLUT_KEY_RIGHT:if(state[1]!=LEFT)
						state[1]=RIGHT;
						break;
	case GLUT_KEY_LEFT: 	if(state[1]!=RIGHT)
							state[1]=LEFT;	
							break;

	
	}


}

void passivemotion(int x, int y)
{
	
	if(screen != 2)
	{
	y=768-y+25;
	
	if((x>=280 && x<=680)&&(y>=500 && y<=540))
		transvar=0;
	else if((x>=280 && x<=680)&&(y>=460 && y<=500))
		transvar=1;
	else if((x>=280 && x<=680)&&(y>=420 && y<=460))
		transvar=2;
	else if((x>=280 && x<=680)&&(y>=380 && y<=420))
		transvar=3;
	else if((x>=280 && x<=680)&&(y>=340 && y<=380))
		transvar=4;

	glutPostRedisplay();

	}
	}




	




void main(int argc,char ** argv)
{

	fp=fopen("gfile.dat","rb");
	if(fp!='\0')
	{
		fread(&best_score,4,1,fp);vitoa(best_score,bstr);	
		fclose(fp);	
	}
	srand(20);
	srand(rand());


		state[1]='6';
		t[1][0]=140;
		t[1][1]=20;
		t[2][0]=120;
		t[2][1]=20;
		state[2]='6';
	size=2;

	
		state2[1]='6';
		t2[1][0]=140;
		t2[1][1]=660;
		t2[2][0]=120;
		t2[2][1]=660;
		state2[2]='6';
	size2=2;
		glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(0,0);
	glutCreateWindow("game");
	glutDisplayFunc(display);

	glutMouseFunc(mouse);
	glutPassiveMotionFunc(passivemotion);
	glutSpecialFunc(spec_keys);
	glutKeyboardFunc(keyboard);
	glClearColor(0.3,0.2,0.6,1.0);
	init();
	glutFullScreen();
	 
	glutMainLoop();

}
