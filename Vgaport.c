#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
  void idswitch(),ssignal();
  int m_menu[5],sh;
  printf("\n DONOT TRY THIS HARDWARE EXPERIMENT ON YOUR COMPUTER (YOU MAY KILL YOUR PC), EVEN I DIDN'T \n");
  printf("welcome to relay switching and recieving digital sensor signal through VGA");
  do
  {
    m_menu[0]='y';
    printf("\n welcome to main menu \n");
    printf("\n 1. Switching the relay \n");
    printf("\n 2.Getting Digital Signal from Sensor \n");
    printf("\n 3. QUIT \n");
    scanf("%d",&sh);
    switch(sh)
    {
      case 3: getch();
              m_menu[0]='n';
              break;
      case 1: idswitch();
              break;
      case 2: ssignal();
              break;
      default : printf("\n invalid choice please select only from the menu \n");
                getch();
                break;
    }            
  }while(m_menu[0]=='y');
}
void idswitch()
{
  int sno,ks,kpr;
  printf("\n enter the switch number \n");
  scanf("%d", &sno);
  printf("\n enter the state (ON=1 AND OFF =0) \n");
  scanf("%d", &ks);
  if(ks==1)
  {
    if(sno>0 && sno<8)
    kpr=1;
    if(sno>7 && sno<15)
    kpr=2;
    Switch(kpr)
    {
      case 1: outputportb(0x378,(sno-1+16));
              outputportb(0x37a,0xff);
              break;
      case 1: outputportb(0x378,(sno-8+32));
              outputportb(0x37a,0xff);
              break;
      default : break; 
    }
  getch();
  }
  if(ks==0)
  {
    if(sno>0 && sno<8)
    kpr=1;
    if(sno>7 && sno<15)
    kpr=2;
    Switch(kpr)
    {
      case 1: outputportb(0x378,(sno-1+16));
              outputportb(0x37a,0x00);
              break;
      case 1: outputportb(0x378,(sno-8+32));
              outputportb(0x37a,0x00);
              break;
      default : break; 
    }
  getch();
  }
}
void ssignal()
{
  int k,sen;
  outputportb(0x378,00);
  outputportb(0x37a,0x00);
  printf("\n enter sensor number (1-16) \n");
  scanf("%d",&k);
  outputportb(0x378,(k-1+48));
  sen=inportb(0x37a);
  sen=sen&1;
  if(sen==0)
  {
    printf("\n input at sensor no: %d is low i.e 0 \n",k);
    goto a;
  }
  printf("\n input at sensor no: %d is high i.e 1 \n",k);
a:getch();
  outputportb(0x37a,0xff);
}
