#include<stdio.h>
#include<stdlib.h>

int main(){ 
    char grid[11][11],result[3][3],ay,over,n;
    int i,j,a=0,icounter,jcounter,b,check=0,turn=0,draw=0,x=0,players;
    restart:
    printf("*** WELCOME TO THE CLASSIC TIC-TAC-TOE ***\nPress ENTER for instructions\n");
    scanf("%c",&ay);
    for(n='1',i=0;i<11;i++){
         for(j=0;j<11;j++){
		if(i==3||i==7){
                       if(j==3||j==7)
				grid[i][j]='+';
			else
                                grid[i][j]='-';
			}
		else if(j==3||j==7)
			grid[i][j]='|';
		else if((i-1)%4==0&&(j-1)%4==0)
			grid[i][j]=n++;
		else
			grid[i][j]=' ';
                    }
                 }
    for(i=0;i<11;i++){
	for(j=0;j<11;j++)
            printf("%c",grid[i][j]);
        printf("\n"); 
        }
     printf("The grid above is your playing area\napni Chaal chalne k liye khaane ka no. enter karein\nTo restart the game enter the restart code 2690\n-----------\n");
     Multiplayer:
     printf("press 2 for multiplayer [*Note=Single player not supported]\n");
     scanf("%d",&players);
     if(players!=2)goto Multiplayer;
     Chaal:{
         if(x%2+1==1){
             printf("\nPlayer_%d enter box number:",(x++)%2+1);
             scanf("%d",&b);
             }
        else if(x%2+1==2){
	    if(players==2){
                printf("\nPlayer_%d enter box number:",(x++)%2+1);
		scanf("%d",&b);
		}
	else if(players==1){
		b=rand()%9+1;
		x++;}
		}
        draw++;
       }
     if(b==2690)
     goto restart;
     else if(b<1||b>9){
	printf("Invalid Move\n");
	goto Chaal;
     } 

     switch(b%3){
	case 1: jcounter=0;break;
	case 2: jcounter=1;break;
	case 0: jcounter=2;break;
        }
   {
   if(b<4)
	icounter=0;
   else if(b<7)
        icounter=1;
   else if(b<10)
        icounter=2;
}
//------chaal bhari
   if(grid[icounter*4][jcounter*4]!=' '){
	printf("Invalid Move\n"); 
	goto Chaal;
    } 
   for(a=0,j=jcounter*4;j<=jcounter*4+2;j++){
	for(i=icounter*4;i<=icounter*4+2;i++,a++){
		if(turn%2==0){
			if(i%2!=0&&j%2!=0)
				grid[i][j]='_';
			else
				grid[i][j]='O';
				}
		else if(a%2==0)
				grid[i][j]='X';
			}
	}
     for(i=0;i<11;i++){
           for(j=0;j<11;j++)
	       printf("%c",grid[i][j]);
           printf("\n"); 
           }
     turn++;
//-----checking results--------
     for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		result[i][j]=grid[i*4+1][j*4+1];
	      }
        }
     for(i=0;i<3;i++){
           for(check=0,j=1;j<3;j++){
	        if(result[i][j]==' ')
	               continue;
	        else if(result[i][j]==result[i][0]){
		       check++;
		//printf("%c %c %d i=%d j=%d\n",result[i][j],result[i][0],check,i,j);
		if(check==2)
		       goto parinaam;
	}
	else
		check=0;
	}
       }
     for(j=0;j<3;j++){
     for(check=0,i=1;i<3;i++){
           if(result[i][j]==' ')
	        continue;
	   else if(result[i][j]==result[0][j]){
		check++;
	   if(check==2)
		goto parinaam;}
	   else
		check=0;
	}
     }
     
     for(check=0,i=1,j=1;i<3;i++,j++){
          if(result[i][j]==' ')
	       continue;
	  else if(result[i][j]==result[0][0]){
	       check++;
	  if(check==2)
	       goto parinaam;
	}
	else
		check=0;
	}

    for(check=0,i=1,j=1;i>=0;i--,j++){
	if(result[i][j]==' ')
               continue;
	else if(result[i][j]==result[2][0]){
		check++;
	if(check==2)
		goto parinaam;
	}
	else
		check=0;
	}
parinaam:
   if(check==2){
       printf("\n---------------------\n*** Player_%d WINs ***\n---------------------\nyou are 1000 rupees wealthier\n",(turn%2+1)%2+1);
   return 0;
}
if(draw==9){
    printf("\n--------##MATCH TIED##--------\n");
    printf("Press R to restart and Q to exit");
    scanf("%c",&over);
    if(over=='r'||over=='R')
	goto restart;
    else if(over=='q'||over=='Q')
	return 0;
    else
	printf("\nInvalid\n");
    }
goto Chaal;
}
