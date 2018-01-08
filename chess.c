//
//  chess.c
//  chess
//
//  Created by PUSHPENDU GHOSH on 21/03/16.
//  Copyright © 2016 PUSHPENDU. All rights reserved.
//

#include <stdio.h>

int B[8][8];
int bking,wking,invalid,turn=1;
int mov[10];
int whitecastle,blackcastle,pseudo;
long int num;
int score[7][8][8]={{780,790,790,785,785,790,790,780,150,150,150,150,150,150,150,150,110,110,120,130,130,120,110,110,105,105,110,125,125,110,105,105,100,100,100,120,120,100,100,100,105,95,90,100,100,90,95,105,105,110,110,80,80,110,110,105,100,100,100,100,100,100,100,100},{500,500,500,500,500,500,500,500,505,510,510,510,510,510,510,505,495,500,500,500,500,500,500,495,495,500,500,500,500,500,500,495,495,500,500,500,500,500,500,495,495,500,500,500,500,500,500,495,495,500,500,500,500,500,500,495,500,500,500,505,505,500,500,500},{270,280,290,290,290,290,280,270,280,300,320,320,320,320,300,280,290,320,330,335,335,330,320,290,290,325,335,340,340,335,325,290,290,320,335,340,340,335,320,290,290,325,330,335,335,330,325,290,280,300,320,325,325,320,300,280,270,280,290,290,290,290,280,270},{310,320,320,320,320,320,320,310,320,330,330,330,330,330,330,320,320,330,335,340,340,335,330,320,320,335,335,340,340,335,335,320,320,330,340,340,340,340,330,320,320,340,340,340,340,340,340,320,320,335,330,330,330,330,335,320,310,320,320,320,320,320,320,310},{880,890,890,895,895,890,890,880,890,900,900,900,900,900,900,890,890,900,905,905,905,905,900,890,895,900,905,905,905,905,900,895,900,900,905,905,905,905,900,895,890,905,905,905,905,905,900,890,890,900,905,900,900,900,900,890,880,890,890,895,895,890,890,880},{19970,19960,19960,19950,19950,19960,19960,19970,19970,19960,19960,19950,19950,19960,19960,19970,19970,19960,19960,19950,19950,19960,19960,19970,19970,19960,19960,19950,19950,19960,19960,19970,19980,19970,19970,19960,19960,19970,19970,19980,19990,19980,19980,19980,19980,19980,19980,19990,20020,20020,20000,20000,20000,20000,20020,20020,20020,20030,20010,20000,20000,20010,20030,20020},{19950,19960,19970,19980,19980,19970,19960,19950,19970,19980,19990,20000,20000,19990,19980,19970,19970,19990,20020,20030,20030,20020,19990,19970,19970,19990,20030,20040,20040,20030,19990,19970,19970,19990,20030,20040,20040,20030,19990,19970,19970,19990,20020,20030,20030,20020,19990,19970,19970,19970,20000,20000,20000,20000,19970,19970,19950,19970,19970,19970,19970,19970,19970,19950}};
int l;
typedef struct
{
    int a;
    int b;
    int c;
    int d;
}moves;

moves X[6][200];

void initial(int A[][8])
{
    int i,j;
    
    A[0][0]=-2;
    A[0][1]=-3;
    A[0][2]=-4;
    A[0][4]=-100;
    A[0][3]=-5;
    A[0][5]=-4;
    A[0][6]=-3;
    A[0][7]=-2;
    
    for(i=0;i<=7;i++)
        A[1][i]=-1;
    
    for(i=0;i<2;i++)
    {
        for(j=0;j<=7;j++)
            A[7-i][j]=(-10*(A[i][j]));
    }
    
}

void printer(int i,int j,int A[][8])
{
    switch(A[i][j])
    {
        case -1:
        case 1: printf("BP");
            break;
            
        case -10:
        case 10: printf("WP");
            break;
            
        case -100:
        case 100: printf("B+");
            break;
            
        case -1000:
        case 1000: printf("W+");
            break;
            
        case -2:
        case 2: printf("BR");
            break;
            
        case -20:
        case 20: printf("WR");
            break;
            
        case -3:
        case 3: printf("BK");
            break;
            
        case -30:
        case 30: printf("WK");
            break;
            
        case -4:
        case 4: printf("BB");
            break;
            
        case -40:
        case 40: printf("WB");
            break;
            
        case -5:
        case 5: printf("BQ");
            break;
            
        case -50:
        case 50: printf("WQ");
            break;
            
        default: printf("  ");
            
    }
}

void output(int A[][8])
{
    int i,j;
    
    printf("    ");
    for(i=0;i<8;i++)
        printf("  %d  ",i+1);
    
    for(i=0;i<=16;i++)
    {
        printf("\n");
        
        if(i%2==1)
            printf(" %d ",i/2+1);
        else
            printf("   ");
        
        if(i==0)
        {
            for(j=0;j<=16;j++)
            {
                if(j%2!=0)
                    printf("___");
                
                else
                    printf("  ");
            }
        }
        
        else if(i==16)
        {
            for(j=0;j<=16;j++)
            {
                if(j%2!=0)
                    printf("___");
                
                else
                    printf("  ");
            }
        }
        
        else if(i%2!=0)
        {
            
            for(j=0;j<=16;j++)
            {
                if(j%2==0)
                    printf(" | ");
                
                else
                    printer(i/2,j/2,A);
            }
        }
        
        else
        {
            for(j=0;j<=16;j++)
            {
                if(j%2!=0)
                    printf("___");
                
                else
                    printf("  ");
            }
        }
    }
}

void queen(int i,int j,int a,int b,int A[][8])
{
    int max,min,x,y=0;
    invalid=1;
    
    i--;j--;a--;b--;
    
    if(i==a)
    {
        max=j>b?j:b;
        min=j<b?j:b;
        
        for(x=min+1;x<=max-1;x++)
        {
            if(A[i][x]!=0)
            {
                invalid=0;
                break;
            }
        }
        
        if((invalid!=0)&&A[a][b]<=0)
        {
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
            invalid=0;
    }
    
    else if(j==b)
    {
        max=i>a?i:a;
        min=i<a?i:a;
        
        for(x=min+1;x<=max-1;x++)
        {
            if(A[x][j]!=0)
            {
                invalid=0;
                break;
            }
        }
        
        if((invalid!=0)&&A[a][b]<=0)
        {
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
            invalid=0;
    }
    
    else if(i-a==j-b)
    {
        max=i>a?i:a;
        min=i<a?i:a;
        
        if(max==a)
            y=j+1;
        else if(max==i)
            y=b+1;
        
        for(x=min+1;x<=max-1;x++,y++)
        {
            if(A[x][y]!=0)
            {
                invalid=0;
                break;
            }
        }
        
        if((invalid!=0)&&A[a][b]<=0)
        {
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
            invalid=0;
    }
    
    else if(i-a==b-j)
    {
        max=i>a?i:a;
        min=i<a?i:a;
        
        if(max==a)
            y=j-1;
        else if(max==i)
            y=b-1;
        
        for(x=min+1;x<=max-1;x++,y--)
        {
            if(A[x][y]!=0)
            {
                invalid=0;
                break;
                
            }
        }
        
        if((invalid!=0)&&A[a][b]<=0)
        {
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
            invalid=0;
    }
    
    else
    {
        invalid=0;
    }
    i++;j++;a++;b++;
    
}

void rook(int i,int j,int a,int b,int A[][8])
{
    int max,min,x;
    invalid=1;
    i--;j--;a--;b--;
    
    if(i==a)
    {
        max=j>b?j:b;
        min=j<b?j:b;
        
        for(x=min+1;x<=max-1;x++)
        {
            if(A[i][x]!=0)
            {
                invalid=0;
                break;
            }
        }
        
        if((invalid!=0)&&A[a][b]<=0)
        {
            if(blackcastle==0&&pseudo==0)
                if(A[i][j]==2)
                    blackcastle=1;
            
            if(whitecastle==0&&pseudo==0)
                if(A[i][j]==20)
                    whitecastle=1;
            
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
            invalid=0;
    }
    
    else if(j==b)
    {
        max=i>a?i:a;
        min=i<a?i:a;
        
        for(x=min+1;x<=max-1;x++)
        {
            if(A[x][j]!=0)
            {
                invalid=0;
                break;
            }
        }
        
        if((invalid!=0)&&A[a][b]<=0)
        {
            if(blackcastle==0&&pseudo==0)
                if(A[i][j]==2)
                    blackcastle=1;
            
            if(whitecastle==0&&pseudo==0)
                if(A[i][j]==20)
                    whitecastle=1;
            
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
            invalid=0;
    }
    
    else
    {
        invalid=0;
    }
    
    
    
    i++;j++;a++;b++;
    
}

void bishop(int i,int j,int a,int b,int A[][8])
{
    int max,min,x,y=0;
    invalid=1;
    
    i--;j--;a--;b--;
    
    if(i-a==j-b)
    {
        max=i>a?i:a;
        min=i<a?i:a;
        
        if(max==a)
            y=j+1;
        else if(max==i)
            y=b+1;
        
        for(x=min+1;x<=max-1;x++,y++)
        {
            if(A[x][y]!=0)
            {
                invalid=0;
                break;
            }
        }
        
        if((invalid!=0)&&A[a][b]<=0)
        {
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
            invalid=0;
    }
    
    else if(i-a==b-j)
    {
        max=i>a?i:a;
        min=i<a?i:a;
        
        if(max==a)
            y=j-1;
        else if(max==i)
            y=b-1;
        
        for(x=min+1;x<=max-1;x++,y--)
        {
            if(A[x][y]!=0)
            {
                invalid=0;
                break;
            }
        }
        
        if((invalid!=0)&&A[a][b]<=0)
        {
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
            invalid=0;
    }
    
    else
    {
        invalid=0;
    }
    i++;j++;a++;b++;
}

void knight(int i,int j,int a,int b,int A[][8])
{
    a--;b--;i--;j--;
    
    if((( ((a==i-1)||(a==i+1)) && ((b==j-2)||(b==j+2)) ) || ( ((b==j-1)||(b==j+1)) && ((a==i-2)||(a==i+2)) ))&&(A[a][b]<=0))
    {
        A[a][b]=A[i][j];
        A[i][j]=0;
    }
    else
    {
        invalid=0;
    }
    
    a++,b++,i++,j++;
    
}

void special1(int a,int b,int A[][8])
{
    int opt,z;
    
    if(pseudo==0){
        output(A);
    do
    {
        printf("\n\nEnter the correct option to which you want to promote your pawn :\n 1 Rook\n 2 Knight\n 3 Bishop\n 4 Queen\n\n Option : ");
        scanf("%d",&opt);
        
        z=1;
        switch(opt)
        {
            case 1 : A[a][b]*=2;
                break;
                
            case 2 : A[a][b]*=3;
                break;
                
            case 3 : A[a][b]*=4;
                break;
                
            case 4 : A[a][b]*=5;
                break;
                
            default : printf("Enter a valid option.");
                z=0;
        }
    }while(z==0);
    }
    else{
        A[a][b]*=5;
    }
}

void pawn(int i,int j,int a,int b,int A[][8])
{
    a--;b--;i--;j--;
    
    if(A[i][j]==1)
    {
        if(((b==j)&&(a==i+1)&&(A[a][b]==0)) || (((b==j-1)||(b==j+1))&&(a==i+1)&&(A[a][b]<0)) || ((i==1)&&(a==3)&&(b==j)&&(A[a][b]==0)&&(A[2][b]==0)))
        {
            A[a][b]=A[i][j];
            A[i][j]=0;
            
            if(a==7)
                special1(a,b,A);
        }
        else
        {
            invalid=0;
        }
    }
    
    else if(A[i][j]==10)
    {
        if(((b==j)&&(a==i-1)&&(A[a][b]==0)) || (((b==j-1)||(b==j+1))&&(a==i-1)&&(A[a][b]<0)) || ((i==6)&&(a==4)&&(b==j)&&(A[a][b]==0)&&(A[4][b]==0)))
        {
            A[a][b]=A[i][j];
            A[i][j]=0;
            
            
            if(a==0)
                special1(a,b,A);
        }
        else
        {
            invalid=0;
        }
    }
    
    else
    {
        invalid=0;
    }
    
    
    a++;b++;i++;j++;
    
}

void king(int i,int j,int a,int b,int A[][8])
{
    a--;b--;i--;j--;int castle=0;//i=7 j=4 a=6 b=4
    
    
    if(a==0&&b==2&&blackcastle==0)
    {
        if(A[0][0]==2&&A[0][1]==0&&A[0][2]==0&&A[0][3]==0&&A[0][4]==100)
        {
            A[0][3]=2;
            A[0][2]=100;
            A[0][0]=0;
            A[0][4]=0;
            castle=1;
            
            if(pseudo==0)
                blackcastle=1;
            
            
            return;
        }
    }
    else if(a==0&&b==6&&blackcastle==0)
    {
        if(A[0][7]==2&&A[0][6]==0&&A[0][5]==0&&A[0][4]==100)
        {
            A[0][5]=2;
            A[0][6]=100;
            A[0][7]=0;
            A[0][4]=0;
            castle=1;
            
            if(pseudo==0)
                blackcastle=1;
            
            
            return;
        }
    }
    else if(a==7&&b==2&&whitecastle==0)
    {
        if(A[7][0]==20&&A[7][1]==0&&A[7][2]==0&&A[7][3]==0&&A[7][4]==1000)
        {
            A[7][3]=20;
            A[7][2]=1000;
            A[7][0]=0;
            A[7][4]=0;
            castle=1;
            
            if(pseudo==0)
                whitecastle=1;
            
            
            return;
        }
    }
    else if(a==7&&b==6&&whitecastle==0)
    {
        if(A[7][7]==20&&A[7][6]==0&&A[7][5]==0&&A[7][4]==1000)
        {
            A[7][5]=20;
            A[7][6]=1000;
            A[7][7]=0;
            A[7][4]=0;
            castle=1;
            
            if(pseudo==0)
                whitecastle=1;
            
            
            return;
        }
    }
    
    else if(((A[a][b]<=0)&&(((a!=i)||(b!=j)))))
    {
        if (((i==a)||(i==a-1)||(i==a+1)) && ((j==b)||(j==b-1)||(j==b+1)))
        {
            if(blackcastle==0&&pseudo==0)
                if(A[i][j]==100)
                    blackcastle=1;
            
            if(whitecastle==0&&pseudo==0)
                if(A[i][j]==1000)
                    whitecastle=1;
            
            
            A[a][b]=A[i][j];
            A[i][j]=0;
        }
        else
        {
            invalid=0;
        }
    }
    
    else
    {
        invalid=0;
    }
    
    a++;b++;i++;j++;
}

void count(int A[][8])
{
    bking=0;
    wking=0;
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(A[i][j]==100||A[i][j]==-100)
                bking++;
            
            if(A[i][j]==1000||A[i][j]==-1000)
                wking++;
        }
    }
}

void inverse(int A[][8])
{
    int i,j;
    
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            A[i][j]=(-1)*(A[i][j]);
        }
    }
}

void rules(int i, int j, int a, int b,int A[][8])
{
    switch(A[i-1][j-1])
    {
        case 1 :
        case 10:
            pawn(i,j,a,b,A);
            break;
            
        case 2:
        case 20: rook(i,j,a,b,A);
            break;
            
        case 3:
        case 30: knight(i,j,a,b,A);
            break;
            
        case 4:
        case 40: bishop(i,j,a,b,A);
            break;
            
        case 5:
        case 50:
            queen(i,j,a,b,A);
            break;
            
        case 100:
        case 1000: king(i,j,a,b,A);
            break;
            
        default:
            invalid=0;
    }
}

void backup(int A[][8],int B[][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            B[i][j]=A[i][j];
        }
    }
}

void getback(int A[][8],int B[][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            A[i][j]=B[i][j];
        }
    }
}

void checkrules(int i,int j,int a,int b,int A[][8])
{
    i--;j--;a--;b--; int max,min,x,y;
    switch (A[i][j])
    {
            
        case 1: if(((b==j)&&(a==i+1)&&(A[a][b]==0)) || (((b==j-1)||(b==j+1))&&(a==i+1)&&(A[a][b]<0)) || ((i==1)&&(a==3)&&(b==j)&&(A[3][b]==0)&&(A[2][b]==0)))
        { invalid = 1 ; break; }
            
        else invalid=0;
            
            break;
            
        case 10: if(((b==j)&&(a==i-1)&&(A[a][b]==0)) || (((b==j-1)||(b==j+1))&&(a==i-1)&&(A[a][b]<0)) || ((i==6)&&(a==4)&&(b==j)&&(A[a][b]==0)&&(A[4][b]==0)))
        { invalid = 1 ; break; }
            
        else invalid=0;
            break;
            
        case 2 :
        case 20 : if(i==a)
        {
            max=j>b?j:b;
            min=j<b?j:b;
            
            for(x=min+1;x<=max-1;x++)
            {
                if(A[i][x]!=0)
                {
                    invalid=0;
                    break;
                }
            }
            
            if((invalid!=0)&&A[a][b]<=0){}
            else
                invalid=0;
        }
            
        else if(j==b)
        {
            max=i>a?i:a;
            min=i<a?i:a;
            
            for(x=min+1;x<=max-1;x++)
            {
                if(A[x][j]!=0)
                {
                    invalid=0;
                    break;
                }
            }
            
            if((invalid!=0)&&A[a][b]<=0){}
            else
                invalid=0;
        }
            
        else
        {
            invalid=0;
        }
            break;   //castling is left
            
            
        case 3:
        case 30:if((( ((a==i-1)||(a==i+1)) && ((b==j-2)||(b==j+2)) ) || ( ((b==j-1)||(b==j+1)) && ((a==i-2)||(a==i+2)) ))&&(A[a][b]<=0))
        {}
        else
        {
            invalid=0;
        }
            break;
            
            
            
        case 4 :
        case 40 :if(i-a==j-b)
        {
            max=i>a?i:a;
            min=i<a?i:a;
            
            if(max==a)
                y=j+1;
            else if(max==i)
                y=b+1;
            
            for(x=min+1;x<=max-1;x++,y++)
            {
                if(A[x][y]!=0)
                {
                    invalid=0;
                    break;
                }
            }
            
            if((invalid!=0)&&A[a][b]<=0){}
            else
                invalid=0;
        }
            
        else if(i-a==b-j)
        {
            max=i>a?i:a;
            min=i<a?i:a;
            
            if(max==a)
                y=j-1;
            else if(max==i)
                y=b-1;
            
            for(x=min+1;x<=max-1;x++,y--)
            {
                if(A[x][y]!=0)
                {
                    invalid=0;
                    break;
                }
            }
            
            if((invalid!=0)&&A[a][b]<=0){}
            else
                invalid=0;
        }
            
        else
            invalid=0;
            
            break;
            
        case 5:
        case 50: if(i==a)
        {
            max=j>b?j:b;
            min=j<b?j:b;
            
            for(x=min+1;x<=max-1;x++)
            {
                if(A[i][x]!=0)
                {
                    invalid=0;
                    break;
                }
            }
            
            if((invalid!=0)&&A[a][b]<=0)
            {}
            else
                invalid=0;
        }
            
        else if(j==b)
        {
            max=i>a?i:a;
            min=i<a?i:a;
            
            for(x=min+1;x<=max-1;x++)
            {
                if(A[x][j]!=0)
                {
                    invalid=0;
                    break;
                }
            }
            
            if((invalid!=0)&&A[a][b]<=0)
            {}
            else
                invalid=0;
        }
            
        else if(i-a==j-b)
        {
            max=i>a?i:a;
            min=i<a?i:a;
            
            if(max==a)
                y=j+1;
            else if(max==i)
                y=b+1;
            
            for(x=min+1;x<=max-1;x++,y++)
            {
                if(A[x][y]!=0)
                {
                    invalid=0;
                    break;
                }
            }
            
            if((invalid!=0)&&A[a][b]<=0)
            {}
            else
                invalid=0;
        }
            
        else if(i-a==b-j)
        {
            max=i>a?i:a;
            min=i<a?i:a;
            
            if(max==a)
                y=j-1;
            else if(max==i)
                y=b-1;
            
            for(x=min+1;x<=max-1;x++,y--)
            {
                if(A[x][y]!=0)
                {
                    invalid=0;
                    break;
                }
            }
            
            if((invalid!=0)&&A[a][b]<=0)
            {}
            else
                invalid=0;
        }
            
        else
        {
            invalid=0;
        }
            break;
            
            
        case 100:
        case 1000:
            if(((A[a][b]<=0)&&((a!=i)||(b!=j))))
            {
                if (((i==a)||(i==a-1)||(i==a+1)) && ((j==b)||(j==b-1)||(j==b+1)))
                {}
                else
                {
                    invalid=0;
                }
            }
            
            else
            {
                invalid=0;
            }
            break;
            
        default:invalid=0;
            
    }
}


void possible_moves(int B[][8],int m)
{
    int i,j,l,k,t=0,limit=0;
    
    
    for(i=1;i<9;i++)
    {
        for(j=1;j<9;j++)
        {
            if(B[i-1][j-1]>0)
            {   limit++;
                if(limit>16)
                    break;
                for(k=1;k<9;k++)
                {
                    for(l=1;l<9;l++)
                    {
                        if(B[k-1][l-1]<=0)
                        {
                            invalid=1;
                            
                            checkrules(i,j,k,l,B);
                            
                            if(invalid!=0)
                            {
                                X[m-1][t].a=i;
                                X[m-1][t].b=j;
                                X[m-1][t].c=k;
                                X[m-1][t].d=l;
                                t++;
                            }
                        }
                    }
                }
            }
        }
        if(limit>16)
            break;
    }
    
    mov[m-1]=t;
}

void follow(moves f,int A[][8])
{
    rules(f.a,f.b,f.c,f.d,A);
    
    inverse(A);
    
}

int getpoint(int A[][8],int i,int j)
{
    int point;
    
    switch(A[i][j])
    {
        case -1: point=(-1)*score[0][7-i][7-j];
            break;
        case 1 : point=score[0][7-i][7-j];
            break;
        case -10: point=(-1)*score[0][i][j];
            break;
        case 10: point=score[0][i][j];
            break;
            
        case -2: point=(-1)*score[1][7-i][7-j];
            break;
        case 2: point=score[1][7-i][7-j];
            break;
        case -20: point=(-1)*score[1][i][j];
            break;
        case 20: point=score[1][i][j];
            break;
            
        case -3: point=(-1)*score[2][7-i][7-j];
            break;
        case 3: point=score[2][7-i][7-j];
            break;
        case -30: point=(-1)*score[2][i][j];
            break;
        case 30: point=score[2][i][j];
            break;
            
        case -4: point=(-1)*score[3][7-i][7-j];
            break;
        case 4: point=score[3][7-i][7-j];
            break;
        case -40: point=(-1)*score[3][i][j];
            break;
        case 40: point=score[3][i][j];
            break;
            
        case -5: point=(-1)*score[4][7-i][7-j];
            break;
        case 5: point=score[4][7-i][7-j];
            break;
        case -50: point=(-1)*score[4][i][j];
            break;
        case 50: point=score[4][i][j];
            break;
            
        case -100: point=(-1)*score[5][7-i][7-j];
            break;
        case 100: point=score[5][7-i][7-j];
            break;
        case -1000: point=(-1)*score[5][i][j];
            break;
        case 1000: point=score[5][i][j];
            break;
    }
    
    return point;
}

int calcpoint(int A[][8],moves f)
{
    int M[8][8],tot=0,i,j;
    int point;
    
    backup(A,M);
    
    follow(f,M);
    
    
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(M[i][j]!=0)
            {
                point=getpoint(M,i,j);
                
                tot+=point;
            }
        }
    }
    num++;
    
    return tot;
    
}

int depth4(moves z3,int A[][8])
{
    int test4[8][8],i; int minpoint=1000000,point;
    
    backup(A,test4);
    
    follow(z3,test4);
    
    possible_moves(test4,4);
    
    for(i=0;i<mov[3];i++)
    {
        point=calcpoint(test4,X[3][i]);
        
        if(minpoint>=point)
        {
            minpoint=point;
        }
    }
    
    return minpoint;
    
}

int depth3(moves z2,int A[][8])
{
    int test3[8][8],i; int maxpoint=-1000000,point;
    
    backup(A,test3);
    
    follow(z2,test3);
    
    possible_moves(test3,3);
    
    for(i=0;i<mov[2];i++)
    {
        point=depth4(X[2][i],test3);
        
        if(maxpoint<=point)
        {
            maxpoint=point;
        }
    }
    
    return maxpoint;
}

int depth2(moves z1,int A[][8])
{
    int test2[8][8],i; int minpoint=1000000,point;
    
    backup(A,test2);
    
    follow(z1,test2);
    
    possible_moves(test2,2);
    
    for(i=0;i<mov[1];i++)
    {
        point=depth3(X[1][i],test2);
        
        if(minpoint>=point)
        {
            minpoint=point;
        }
    }
    return minpoint;
}
int mate;
moves depth1(int A[][8])
{
    int test1[8][8],i; int maxpoint=-1000000,point;
    moves actual;
    mate=1;
    backup(A,test1);
    
    possible_moves(test1,1);
    
    for(i=0;i<mov[0];i++)
    {
        printf("\n %d :",i+1);
        point=depth2(X[0][i],test1);
        printf(" %d (%d%d%d%d)",point,X[0][i].a,X[0][i].b,X[0][i].c,X[0][i].d);
        
        if(point<19000)
            mate=0; //not a mate
        
        if(maxpoint<=point)
        {
            maxpoint=point;
            actual=X[0][i];
        }
    }
    if(maxpoint>19000)
        printf("It's a CHECK ");
    if(mate==1)
        printf("mate !!! ");
    return actual;
}


int main()
{
    int A[8][8]={0};int opt;
    
    initial(A);
    
    int i,j,a,b;
    moves com;
    
    do{
        printf("Play as :\n 1.White\n 2.Black\n Option : ");
        scanf("%d",&opt);
    }while(opt!=1&&opt!=2);
    
    if(opt==2)
    {
        printf("\n User : Black\n ");
        turn=2;
    }
    else
        printf("\n User : White\n");
    
    do
    {
        invalid=1;
        
        printf("\n");
        
        output(A);
        
        if(turn%2==0)
            printf("\n\t\tBlack move \n");
        else
            printf("\n\t\tWhite move \n");
        
        if(turn %2==1)
        {
            pseudo=0;
            
            printf(" Initial r : ");
            scanf("%d",&i);
            
            printf(" Initial c : ");
            scanf("%d",&j);
            
            printf(" Final r : ");
            scanf("%d",&a);
            
            printf(" Final c : ");
            scanf("%d",&b);
        }
        
        else
        {
            pseudo=1;
            
            com=depth1(A);
            i=com.a;
            j=com.b;
            a=com.c;
            b=com.d;
            
            printf("\n %ld Outcome : %d %d %d %d",num,i,j,a,b);
            printf(" Blackcastle=%d Whitecastle=%d",blackcastle,whitecastle);
        }
        
        invalid=1;
        
        rules(i,j,a,b,A);
        
        count(A);
        
        if(invalid==1)
        {
            inverse(A);
            turn++;
        }
        else
            printf("Invalid move");
        
        
    }while(bking!=0&&wking!=0);
    
    output(A);
    
    if(bking==0)
        printf("\n\n\t White wins.\n");
    
    if(wking==0)
        printf("\n\n\t Black wins.\n");
    
    return 0;
}
/* My errors:
 1. possibilities not checking castling
 2. white king moved but yet whitecastle variable is 0 
 3. 8687 didnt do */