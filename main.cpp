#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "ZeroCircle.h"
#include <ctime>

using namespace std;

int winCheck(bool []);
void interFace(string [][3],string,string);
void Con_R_Exit(int,int,int,bool);
void scoreBoard(int,int,int);
void compTurn(string [][3], bool [],string,bool [],string);

int main()
{
	string pos[][3]={{"A 1","A 2","A 3"},{"B 1","B 2","B 3"},{"C 1","C 2","C 3"}},playMark,compMark;
	unsigned int numRand=0;
	static int once=0;

    if(once==0)
    {
        LOGO_SCREEN();
        once++;
    }
	srand((unsigned int)time(NULL));
	numRand=rand()%2;
	if(numRand==0)
	{
		playMark=" X ";
		compMark=" O ";
	}
	else
	{
		playMark=" O ";
		compMark=" X ";
	}
	interFace(pos,playMark,compMark);
	cin.get();
}
void interFace(string pos[][3],string playMark,string compMark)
{
	char strChoice[1000]={0};
	int Pwins=1,Cwins,noPlay=0;
	static unsigned int cScore=0,pScore=0,draw=0;
	bool Pswtch[9]={false,false,false,false,false,false,false,false,false},conSwtch=false;
	bool Cswtch[9]={false,false,false,false,false,false,false,false,false};
	bool swtch2[9]={false,false,false,false,false,false,false,false,false};

	while(1)
	{
		Cwins=winCheck(Cswtch);
		system("cls");
		for(int i=0;i<80;i++)
			cout<<"*";
		cout<<"\t\t\t      T I C - T A C - T O E\n";
		for(int i=0;i<80;i++)
			cout<<"*";
		cout<<" Player's Mark is:"<<playMark<<"\t\t\t\t\t\t      X to Exit\n";
		for(int i=0;i<80;i++)
			cout<<"*";
		cout<<"\n\n\n\t\t\t\t     |     |     "<<endl;
		cout<<"\t\t\t\t "<<pos[0][0]<<" | "<<pos[0][1]<<" | "<<pos[0][2]<<endl;
		cout<<"\t\t\t\t_____|_____|_____"<<endl;
		cout<<"\t\t\t\t     |     |     "<<endl;
		cout<<"\t\t\t\t "<<pos[1][0]<<" | "<<pos[1][1]<<" | "<<pos[1][2]<<endl;
		cout<<"\t\t\t\t_____|_____|_____"<<endl;
		cout<<"\t\t\t\t     |     |     "<<endl;
		cout<<"\t\t\t\t "<<pos[2][0]<<" | "<<pos[2][1]<<" | "<<pos[2][2]<<endl;
		cout<<"\t\t\t\t     |     |     "<<endl;
		if(noPlay>8)
		{
			cout<<"\n\n\t\t\t\t      *Draw*";
			draw++;
			conSwtch=true;
			wait(3,0,0);
		}
		else if(Pwins==0 )
		{
			cout<<"\n\n\t\t\t\t  *Player Wins*";
			pScore++;
			conSwtch=true;
			wait(3,0,0);
		}
		else if(Cwins==0)
		{
			cout<<"\n\n\t\t\t\t *Computer Wins*";
			cScore++;
			conSwtch=true;
			wait(3,0,0);
		}
		if(conSwtch==true)
			Con_R_Exit(pScore,cScore,draw,false);
		cout<<"\n\n\nEnter What Is In The Grid To Put Your Mark: ";
		cin.getline(strChoice,999,'\n');
		int k=0;
        for(unsigned int i=0;i<999;i++)
        {
            if(isspace(strChoice[i])==0)
            {
                strChoice[k]=strChoice[i];
                k++;
                continue;
            }
            strChoice[i]='\0';
        }
		if((strncmp(strChoice,"A1\0",3)==0 || strncmp(strChoice,"a1\0",3)==0 ) && pos[0][0]=="A 1")
		{
			pos[0][0]=playMark;
			Pswtch[0]=true;
		}
		else if((strncmp(strChoice,"A2\0",3)==0 || strncmp(strChoice,"a2\0",3)==0 ) && pos[0][1]=="A 2")
		{
			pos[0][1]=playMark;
			Pswtch[1]=true;
		}
		else if((strncmp(strChoice,"A3\0",3)==0 || strncmp(strChoice,"a3\0",3)==0 ) && pos[0][2]=="A 3")
		{
			pos[0][2]=playMark;
			Pswtch[2]=true;
		}
		else if((strncmp(strChoice,"B1\0",3)==0 || strncmp(strChoice,"b1\0",3)==0 ) && pos[1][0]=="B 1")
		{
			pos[1][0]=playMark;
			Pswtch[3]=true;
		}
		else if((strncmp(strChoice,"B2\0",3)==0 || strncmp(strChoice,"b2\0",3)==0 ) && pos[1][1]=="B 2")
		{
			pos[1][1]=playMark;
			Pswtch[4]=true;
		}
		else if((strncmp(strChoice,"B3\0",3)==0 || strncmp(strChoice,"b3\0",3)==0 ) && pos[1][2]=="B 3")
		{
			pos[1][2]=playMark;
			Pswtch[5]=true;
		}
		else if((strncmp(strChoice,"C1\0",3)==0 || strncmp(strChoice,"c1\0",3)==0 ) && pos[2][0]=="C 1")
		{
			pos[2][0]=playMark;
			Pswtch[6]=true;
		}
		else if((strncmp(strChoice,"C2\0",3)==0 || strncmp(strChoice,"c2\0",3)==0 ) && pos[2][1]=="C 2")
		{
			pos[2][1]=playMark;
			Pswtch[7]=true;
		}
		else if((strncmp(strChoice,"C3\0",3)==0 || strncmp(strChoice,"c3\0",3)==0 ) && pos[2][2]=="C 3")
		{
			pos[2][2]=playMark;
			Pswtch[8]=true;
		}
		else if(strncmp(strChoice,"X\0",2)==0 || strncmp(strChoice,"x\0",2)==0)
			scoreBoard(pScore,cScore,draw);
		else
		{
			cout<<"\n\t\t\t     Wrong Input, Try Again";
			wait(2,0,'\0');
			continue;
		}
		Pwins=winCheck(Pswtch);
		if(Pwins==0)
            continue;
        compTurn(pos,Cswtch,compMark,swtch2,playMark);
		noPlay+=2;
	}
}
int winCheck(bool swtch[])
{
	if(swtch[0]==true && swtch[1]==true && swtch[2])
		return 0;
	if(swtch[3]==true && swtch[4]==true && swtch[5])
		return 0;
	if(swtch[6]==true && swtch[7]==true && swtch[8])
		return 0;
	if(swtch[0]==true && swtch[4]==true && swtch[8])
		return 0;
	if(swtch[2]==true && swtch[4]==true && swtch[6])
		return 0;
	if(swtch[0]==true && swtch[3]==true && swtch[6])
		return 0;
	if(swtch[1]==true && swtch[4]==true && swtch[7])
		return 0;
	if(swtch[2]==true && swtch[5]==true && swtch[8])
		return 0;
	return -1;
}
void compTurn(string pos[][3], bool swtch[],string compMark,bool swtch2[],string playMark)
{
	unsigned int num;

	if((swtch[0]==true && swtch[1]==true && pos[0][2]=="A 3") || (swtch[0]==true && pos[0][1]=="A 2" && swtch[2]==true) || (pos[0][0]=="A 1" && swtch[1]==true && swtch[2]==true))
    {
        if(pos[0][2]=="A 3")
        {
            pos[0][2]=compMark;swtch[0]=true;
        }
        else if(pos[0][1]=="A 2")
        {
            pos[0][2]=compMark;swtch[1]=true;
        }
        else if(pos[0][0]=="A 1")
        {
            pos[0][0]=compMark;swtch[2]=true;
        }
        return;
    }
    if((swtch[3]==true && swtch[4]==true && pos[1][2]=="B 3") || (swtch[3]==true && pos[1][1]=="B 2" && swtch[5]==true) || (pos[1][0]=="B 1" && swtch[4]==true && swtch[5]==true))
    {
        if(pos[1][2]=="B 3")
		{
            pos[1][2]=compMark;swtch[5]=true;
		}
        else if(pos[1][1]=="B 2")
		{
            pos[1][1]=compMark;swtch[4]=true;
		}
        else if(pos[1][0]=="B 1")
		{
            pos[1][0]=compMark;swtch[3]=true;
		}
        return;
    }
	if((swtch[6]==true && swtch[7]==true && pos[2][2]=="C 3") || (swtch[6]==true && pos[2][1]=="C 2" && swtch[8]==true) || (pos[2][0]=="C 1" && swtch[7]==true && swtch[8]==true))
    {
        if(pos[2][2]=="C 3")
		{
            pos[2][2]=compMark;swtch[8]=true;
		}
        else if(pos[2][1]=="C 2")
		{
            pos[2][1]=compMark;swtch[7]=true;
		}
        else if(pos[2][0]=="C 1")
		{
            pos[2][0]=compMark;swtch[6]=true;
		}
        return;
    }
	if((swtch[0]==true && swtch[4]==true && pos[2][2]=="C 3") || (swtch[6]==true && pos[1][1]=="B 2" && swtch[8]==true) || (pos[0][0]=="A 1" && swtch[7]==true && swtch[8]==true))
    {
        if(pos[2][2]=="C 3")
		{
            pos[2][2]=compMark;swtch[8]=true;
		}
        else if(pos[1][1]=="B 2")
		{
            pos[1][1]=compMark;swtch[4]=true;
		}
        else if(pos[0][0]=="A 1")
		{
            pos[0][0]=compMark;swtch[0]=true;
		}
        return;
    }
	if((swtch[2]==true && swtch[4]==true && pos[2][0]=="C 1") || (swtch[2]==true && pos[1][1]=="B 2" && swtch[6]==true) || (pos[0][2]=="A 3" && swtch[4]==true && swtch[6]==true))
    {
        if(pos[2][0]=="C 1")
		{
            pos[2][0]=compMark;swtch[6]=true;
		}
        else if(pos[1][1]=="B 2")
		{
            pos[1][1]=compMark;swtch[4]=true;
		}
        else if(pos[0][2]=="A 3")
		{
            pos[0][2]=compMark;swtch[2]=true;
		}
        return;
    }
	if((swtch[0]==true && swtch[3]==true && pos[2][0]=="C 1") || (swtch[0]==true && pos[1][0]=="B 1" && swtch[6]==true) || (pos[0][0]=="A 1" && swtch[3]==true && swtch[6]==true))
    {
        if(pos[2][0]=="C 1")
		{
            pos[2][0]=compMark;swtch[6]=true;
		}
        else if(pos[1][0]=="B 1")
		{
            pos[1][0]=compMark;swtch[3]=true;
		}
        else if(pos[0][0]=="A 1")
		{
            pos[0][0]=compMark;swtch[0]=true;
		}
        return;
    }
	if((swtch[1]==true && swtch[4]==true && pos[2][1]=="C 2") || (swtch[1]==true && pos[1][1]=="B 2" && swtch[7]==true) || (pos[0][1]=="A 2" && swtch[4]==true && swtch[7]==true))
    {
        if(pos[2][1]=="C 2")
		{
            pos[2][1]=compMark;swtch[7]=true;
		}
        else if(pos[1][1]=="B 2")
		{
            pos[1][1]=compMark;swtch[4]=true;
		}
        else if(pos[0][1]=="A 2")
		{
            pos[0][1]=compMark;swtch[1]=true;
		}
        return;
    }
	if((swtch[2]==true && swtch[5]==true && pos[2][2]=="C 3") || (swtch[2]==true && pos[1][2]=="B 3" && swtch[8]==true) || (pos[0][2]=="A 3" && swtch[5]==true && swtch[8]==true))
    {
        if(pos[2][2]=="C 3")
		{
            pos[2][2]=compMark;swtch[8]=true;
		}
        else if(pos[1][2]=="B 3")
		{
            pos[1][2]=compMark;swtch[5]=true;
		}
        else if(pos[0][2]=="A 3")
		{
            pos[0][2]=compMark;swtch[2]=true;
		}
        return;
    }
    if((pos[0][0]==playMark && pos[0][1]==playMark && pos[0][2]=="A 3") || (pos[0][0]==playMark && pos[0][1]=="A 2" && pos[0][2]==playMark) || (pos[0][0]=="A 1" && pos[0][1]==playMark && pos[0][2]==playMark))
    {
        if(pos[0][2]=="A 3")
        {
            pos[0][2]=compMark;swtch[0]=true;
        }
        else if(pos[0][1]=="A 2")
        {
            pos[0][2]=compMark;swtch[1]=true;
        }
        else if(pos[0][0]=="A 1")
        {
            pos[0][2]=compMark;swtch[2]=true;
        }
        return;
    }
    if((pos[1][0]==playMark && pos[1][1]==playMark && pos[1][2]=="B 3") || (pos[1][0]==playMark && pos[1][1]=="B 2" && pos[1][2]==playMark) || (pos[1][0]=="B 1" && pos[1][1]==playMark && pos[1][2]==playMark))
    {
        if(pos[1][2]=="B 3")
		{
            pos[1][2]=compMark;swtch[5]=true;
		}
        else if(pos[1][1]=="B 2")
		{
            pos[1][1]=compMark;swtch[4]=true;
		}
        else if(pos[1][0]=="B 1")
		{
            pos[1][0]=compMark;swtch[3]=true;
		}
        return;
    }
	if((pos[2][0]==playMark && pos[2][1]==playMark && pos[2][2]=="C 3") || (pos[2][0]==playMark && pos[2][1]=="C 2" && pos[2][2]==playMark) || (pos[2][0]=="C 1" && pos[2][1]==playMark && pos[2][2]==playMark))
    {
        if(pos[2][2]=="C 3")
		{
            pos[2][2]=compMark;swtch[8]=true;
		}
        else if(pos[2][1]=="C 2")
		{
            pos[2][1]=compMark;swtch[7]=true;
		}
        else if(pos[2][0]=="C 1")
		{
            pos[2][0]=compMark;swtch[6]=true;
		}
        return;
    }
	if((pos[0][0]==playMark && pos[1][1]==playMark && pos[2][2]=="C 3") || (pos[0][0]==playMark && pos[1][1]=="B 2" && pos[2][2]==playMark) || (pos[0][0]=="A 1" && pos[1][1]==playMark && pos[2][2]==playMark))
    {
        if(pos[2][2]=="C 3")
		{
            pos[2][2]=compMark;swtch[8]=true;
		}
        else if(pos[1][1]=="B 2")
		{
            pos[1][1]=compMark;swtch[4]=true;
		}
        else if(pos[0][0]=="A 1")
		{
            pos[0][0]=compMark;swtch[0]=true;
		}
        return;
    }
	if((pos[0][2]==playMark && pos[1][1]==playMark && pos[2][0]=="C 1") || (pos[0][2]==playMark && pos[1][1]=="B 2" && pos[2][0]==playMark) || (pos[0][2]=="A 3" && pos[1][1]==playMark && pos[2][0]==playMark))
    {
        if(pos[2][0]=="C 1")
		{
            pos[2][0]=compMark;swtch[6]=true;
		}
        else if(pos[1][1]=="B 2")
		{
            pos[1][1]=compMark;swtch[4]=true;
		}
        else if(pos[0][2]=="A 3")
		{
            pos[0][2]=compMark;swtch[2]=true;
		}
        return;
    }
	if((pos[0][0]==playMark && pos[1][0]==playMark && pos[2][0]=="C 1") || (pos[0][0]==playMark && pos[1][0]=="B 1" && pos[2][0]==playMark) || (pos[0][0]=="A 1" && pos[1][0]==playMark && pos[2][0]==playMark))
    {
        if(pos[2][0]=="C 1")
		{
            pos[2][0]=compMark;swtch[6]=true;
		}
        else if(pos[1][0]=="B 1")
		{
            pos[1][0]=compMark;swtch[3]=true;
		}
        else if(pos[0][0]=="A 1")
		{
            pos[0][0]=compMark;swtch[0]=true;
		}
        return;
    }
	if((pos[0][1]==playMark && pos[1][1]==playMark && pos[2][1]=="C 2") || (pos[0][1]==playMark && pos[1][1]=="B 2" && pos[2][1]==playMark) || (pos[0][1]=="A 2" && pos[1][1]==playMark && pos[2][1]==playMark))
    {
        if(pos[2][1]=="C 2")
		{
            pos[2][1]=compMark;swtch[7]=true;
		}
        else if(pos[1][1]=="B 2")
		{
            pos[1][1]=compMark;swtch[4]=true;
		}
        else if(pos[0][1]=="A 2")
		{
            pos[0][1]=compMark;swtch[1]=true;
		}
        return;
    }
	if((pos[0][2]==playMark && pos[1][2]==playMark && pos[2][2]=="C 3") || (pos[0][2]==playMark && pos[1][2]=="B 3" && pos[2][2]==playMark) || (pos[0][2]=="A 3" && pos[1][2]==playMark && pos[2][2]==playMark))
    {
        if(pos[2][2]=="C 3")
		{
            pos[2][2]=compMark;swtch[8]=true;
		}
        else if(pos[1][2]=="B 3")
		{
            pos[1][2]=compMark;swtch[5]=true;
		}
        else if(pos[0][2]=="A 3")
		{
            pos[0][2]=compMark;swtch[2]=true;
		}
        return;
    }
	while(1)
	{
		num=rand()%9;
		if(num==0 && swtch2[0]==false  && pos[0][0]=="A 1")
		{
			pos[0][0]=compMark;
			swtch[0]=true;
			swtch2[0]=true;
			return;
		}
		else if(num==1 && swtch2[1]==false && pos[0][1]=="A 2")
		{
			pos[0][1]=compMark;
			swtch[1]=true;
			swtch2[1]=true;
			return;
		}
		else if(num==2 && swtch2[2]==false && pos[0][2]=="A 3")
		{
			pos[0][2]=compMark;
			swtch[2]=true;
			swtch2[2]=true;
			return;
		}
		else if(num==3 && swtch2[3]==false && pos[1][0]=="B 1")
		{
			pos[1][0]=compMark;
			swtch[3]=true;
			swtch2[3]=true;
			return;
		}
		else if(num==4 && swtch2[4]==false && pos[1][1]=="B 2")
		{
			pos[1][1]=compMark;
			swtch[4]=true;
			swtch2[4]=true;
			return;
		}
		else if(num==5 && swtch2[5]==false && pos[1][2]=="B 3")
		{
			pos[1][2]=compMark;
			swtch[5]=true;
			swtch2[5]=true;
			return;
		}
		else if(num==6 && swtch2[6]==false && pos[2][0]=="C 1")
		{
			pos[2][0]=compMark;
			swtch[6]=true;
			swtch2[6]=true;
			return;
		}
		else if(num==7 && swtch2[7]==false && pos[2][1]=="C 2")
		{
			pos[2][1]=compMark;
			swtch[7]=true;
			swtch2[7]=true;
			return;
		}
		else if(num==8 && swtch2[8]==false && pos[2][2]=="C 2")
		{
			pos[2][2]=compMark;
			swtch[8]=true;
			swtch2[8]=true;
			return;
		}
		else if(pos[0][0]!="A 1" && pos[0][1]!="A 2" && pos[0][1]!="A 3" && pos[1][0]!="B 1" && pos[1][1]!="B 2" && pos[1][2]!="B 3" && pos[2][0]!="C 1" && pos[2][1]!="C 2" && pos[2][2]!="C 3")
			return;
	}
}
void scoreBoard(int player,int dealer,int draws)
{
    char ban[] = "S C O R E B O A R D";
	system("cls");
    banner(ban);
    stars(640,0,0);
    cout<<"\n\t\t  *PLAYER*\t   *DEALER*\t    *DRAWS*\n";
    cout<<"\t\t     "<<player<<"\t\t      "<<dealer<<"\t\t       "<<draws<<"\n\n";
    stars(799,0,0);
    cout<<"\010";
    wait(9,0,'0');
    exit(0);
}
void Con_R_Exit(int player,int dealer,int draws,bool ext)
{
	unsigned char choice;
	bool swtch1=true,swtch2=false;
	if(ext==true)
		scoreBoard(player,dealer,draws);
	else
	{
		cout<<"\n\nPress Any To Play Again...\nPress X to Exit...\nChoice :";
		while(1)
		{
			choice=_getch();
			if(choice==224 || swtch2==true)
			{
				if(swtch1==true)
				{
					swtch2=true;
					swtch1=false;
					continue;
				}
				if(swtch2==true)
				{
					swtch1=true;
					swtch2=false;
					break;
				}
			}
			break;
		}
		switch(choice)
		{
			case 'x':
			case 'X':	scoreBoard(player,dealer,draws);
						break;

			default: main();
		}

	}
}
