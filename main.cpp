#include <iostream>
#include <cstdlib>
using namespace std;



/*
Simple Chess game
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀
⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀ ⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀
⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀
⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀
⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀
⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀
⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀
⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀ ⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

Unfinished - By Edin Ziga


*/
int bd[64],bds[64],mvs[27];///bd - Piece memory, bds - Board Status, mvs - Move saver
void intro()
{
    cout <<"Welcome to basic chess"<<endl;
    cout <<char(224)<<" = Pawn"<<endl;
    cout <<char(234)<<" = Rook"<<endl;
    cout <<char(225)<<" = Knight"<<endl;
    cout <<char(232)<<" = Bishup"<<endl;
    cout <<char(75) <<" = King"<<endl;
    cout <<char(81) <<" = Queen"<<endl;
}
void board() /// For drawing the board
{
    int j=65,k=1;///J - Char for A-H, K - Int for bottom numbers
    for(int i=0; i<=63; i++)
    {
         if(i%8==0) /// Numbers for side of the board
         {
          cout<<endl;
          cout<<k++<<" "<<char(179);
         }
        cout <<char(bd[i])<<" "; ///Actual Board
    }
    /// Bottom Part
    cout<<endl;
    cout<<"  "<<char(192);
    for(int i=0;i<15;i++)cout<<char(196);
    cout <<endl<<"   ";
    for (int i=1; i<=8; i++)
    {
        cout <<char(j++)<<" ";
    }

}
void setp()
{
    for(int i=0; i<=15; i++) bds[i]=0; ///white
    for(int i=16; i<=47; i++) bds[i]=2; ///empty
    for(int i=48; i<=63; i++) bds[i]=1; ///black
    for(int i=0; i<=63; i++) ///Whole Board to empty spaces
        bd[i]=32;
    for(int i=8; i<=15; i++) ///White Pawns
        bd[i]=224;
    for(int i=48; i<=55; i++) ///Black pawns
        bd[i]=224;
        bd[0]=234;bd[7]=234;bd[56]=234;bd[63]=234; ///Rooks
        bd[1]=225;bd[6]=225;bd[57]=225;bd[62]=225; ///Knights
        bd[2]=232;bd[5]=232;bd[58]=232;bd[61]=232; ///Bishups
        bd[3]=81;bd[59]=81;bd[4]=75;bd[60]=75; ///Kings & Queens

}
void piececalc(int pos,int bw) ///Move Posibility Calculator
{
    for(int i=0; i<=26; i++) mvs[i]=-1;///Clearing Array for movements

    switch (bd[pos])
    {
    case 224:///Pawn
        cout<<"Pawn"<<endl;
           switch (bw) ///Movement
           {
               case 0: ///For white
                   ///Basic Moves
                   if(pos>=8 && pos<=15) ///First Row
                   {
                       if(bds[pos+8]==2 && bds[pos+16]==2)
                       {
                                mvs[0]=pos+8; mvs[1]=pos+16;
                       }
                   } else
                   if(bds[pos+8]==2) /// Other Positions
                       {
                                mvs[0]=pos+8;
                       }
                   ///Eating
               if(bds[pos+7]==1 && (pos+7)/8!=pos/8) ///Left Corner
               {
                   mvs[2]=pos+7;
               }
               if(bds[pos+9]==1 && (pos+9)/8-pos/8!=2) ///Right Corner
               {
                   mvs[3]=pos+9;
               }
               break;
               ///----------------------------
               case 1: ///For Black
                    ///Basic Moves
                   if(pos>=48 && pos<=55) ///First Row
                   {
                       if(bds[pos-8]==2 && bds[pos-16]==2)
                       {
                                mvs[0]=pos-8; mvs[1]=pos-16;
                       }
                   } else
                   if(bds[pos-8]==2) ///Other positions
                       {
                                mvs[0]=pos-8;
                       }
                        ///Eating
             if(bds[pos-7]==0 && (pos-7)/8!=pos/8) ///Right Corner
               {
                   mvs[2]=pos-7;
               }
               if(bds[pos-9]==0 && pos/8-(pos-9)/8!=2) ///Left Corner
               {
                   mvs[3]=pos-9;
               }
           break;
           }
           break;
    case 234:///Rook
        cout<<"Rook"<<endl;
        break;
    case 225:///Knight
        cout<<"Knight"<<endl;
        break;
    case 232:///Bishup
        cout<<"Bishup"<<endl;
        break;
    case 75:///King
        cout<<"King"<<endl;
        break;
    case 81:///Queen
        cout<<"Queen"<<endl;
        break;
    }
}
void moven(int bw)
{
    /// Initial Selection
     char a;
     int b,calc1,calc2,buffer;/// Calc1&2 - Position number calculator
     bool lgl=1;
     cout <<"Select a piece to move"<<endl;
     while(lgl==1)
     {
         lgl=0;
     cin>>a>>b;
     if((int(a)<65 || int(a)>72) && (int(a)<97 || int(a)>104))
     {
         cout<<"Illegal Selection"<<endl; lgl=1;
     }
     if((b<1 || b>8) && lgl!=1)
     {
         cout<<"Illegal Selection"<<endl; lgl=1;
     }
     if(int(a)>=65 && int(a)<=72) calc1=int(a)-65+(b-1)*8;
     else calc1=int(a)-97+(b-1)*8;
     if(bds[calc1]!=bw)
     {
         cout <<"Illegal Selection"<<endl; lgl=1;
     }
     if(lgl==0)
     {
         lgl=1;
          piececalc(calc1,bw);
     for(int i=0; i<=26; i++)
        {
         if(mvs[i]!=-1)
         {cout <<char (65 + mvs[i]%8)<<mvs[i]/8 + 1<<" "; lgl=0;}
     }
     if(lgl==1) {cout <<"No places to move, select another piece";}
     cout<<endl;
     }
     }
     ///-------------------------------------------------------------------
     ///Actual Move
     lgl=1;
     cout <<"Select a place to move it to"<<endl;
     while(lgl==1)
     {
          lgl=0;
     cin>>a>>b;
     if((int(a)<65 || int(a)>72) && (int(a)<97 || int(a)>104))
     {
         cout<<"Illegal Selection"<<endl; lgl=1;
     }
     if((b<1 || b>8) && lgl!=1)
     {
         cout<<"Illegal Selection"<<endl; lgl=1;
     }
     if(int(a)>=65 && int(a)<=72) calc2=int(a)-65+(b-1)*8;
     else calc2=int(a)-97+(b-1)*8;
     lgl=1;
     for(int i=0; i<=27; i++)
     {
         if(mvs[i]==calc2)
         {
             lgl=0;
             break;
         }
     }
     if(lgl==1) {cout <<"Unable"<<endl;}
     if(bds[calc2]!=bw && lgl==0)
     {
         buffer=bd[calc1];
         bd[calc1]=bd[calc2];
         bd[calc2]=buffer;

         buffer=bds[calc1];
         bds[calc1]=bds[calc2];
         bds[calc2]=buffer;
     }
     }
}
int main()
{
    bool bw=0; ///0=white,1=black
    setp();
    while(1)
    {
        intro();
        board();
        if(bw==0) cout<<endl<<"White"; else cout<<endl<<"Black";
        cout <<" is playing"<<endl<<"Letter - Number"<<endl;
        moven(bw);
        if(bw==0)bw=1; else bw=0;
        system("CLS");
    }
    return 0;
}
