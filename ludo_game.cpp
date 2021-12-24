#include<cmath>
#include<iostream>
#include<graphics.h>
#include<cstdlib>
#include<time.h>
#include<windows.h>
using namespace std;
int a1,b1,p1,d1,l1,h1,h2,page=0;
class dice
{
    public:
    int x1;
    int y1;
    int x2;
    int y2;
}di;
class token
{
    public:
    int x;
    int y;
    int r;
    int index;

}tk[16],init_pos[16];
void bar(int a,int b,int c,int d,int l,int c1,int c2,int c3,int c4)
{
    setcolor(0);
    setfillstyle(1,c1);
    bar(a,b,a+l,b+l);
    setfillstyle(1,c2);
    bar(a,d-l,a+l,d);
    setfillstyle(1,c3);
    bar(c-l,b,c,b+l);
    setfillstyle(1,c4);
    bar(c-l,d-l,c,d);
}
 void way(int a,int b,int c,int d ,int c1)
 {
     static int k=0;

     int h=d-b,l=c-a,p=4;
     for(int j=b;p--;j+=h/3){
            if(p==0)
            j=b+h;
     line(a,j,c,j);
     }
     if(k==0){
            p=5;
     line(a+l/6,b,a+l/6,b+h);
     line(a+l,b,a+l,b+h);}
     else{
            p=4;
        line(a,b,a,b+h);
        line(a+5*l/6,b,a+5*l/6-3,b+h);
     }
     setfillstyle(1,c1);
     floodfill(a+l/2,b+h/2,0);
     for(int i=a+l/6;p--;i+=l/6)
        line(i,b,i,b+h);
     if(k==0) {
         floodfill(a+l/5,b+h/4,0);
         int z=sqrt(l/12*l/12+h/6*h/6);
         circle(c-l/2-l/11,d-h/6,l/12);
         floodfill(c-l/2-l/11,d-h/6,0);

     }
     else {
         floodfill(c-l/5,d-h/5,0);
           int z=sqrt(l/12*l/12+h/6*h/6);
         circle(a+l/2+l/12,b+h/6,l/12);
         floodfill(a+l/2+l/12,b+h/6,0);
         k-=2;
     }
     k++;


 }
 void way1(int a,int b,int c,int d ,int c1)
 {
     static int k=0;
     int h=d-b,l=c-a,p=4;

     for(int i=a;p--;i+=l/3) {
     line(i,b,i,b+h);
     }
     if(k==0){
     line(a,b+5*h/6,a+l,b+5*h/6);
     line(a,b,a+h,b);
     p=4; }
     else{
        line(a,b+h/6,a+l,b+h/6);
        line(a,b+h,a+l,b+h);
        p=5; }

     setfillstyle(1,c1);
     floodfill(a+l/2,b+h/2,0);
      for(int i=b+h/6;p--;i+=h/6)
      line(a,i,a+l,i);
      if(k==0) {
       floodfill(a+l/6,d-h/6-h/12,0);
         circle(c-l/6,d-h/3-h/11,h/12);
         floodfill(c-l/6,d-h/3-h/11,0);
      }
      else {
        floodfill(c-l/4,b+h/5,0);
         circle(a+l/6,b+h/3+h/12,h/12);
         floodfill(a+l/6,b+h/3+h/12,0);
         k-=2;

      }
     k++;



 }
 void tokens(int a,int b,int c,int d,int l,int c1,int c2,int c3,int c4,int *mov)
{
    setcolor(0);
    int  cr[4]={c1,c2,c3,c4},p=0,q=0;
    int ck[8]={a+l/2,b+l/2,c-l/2,b+l/2,a+l/2,d-l/2,c-l/2,d-l/2},pk=4;
     static int i=0;
     if(i>=16)
        i=0;
        setcolor(7);
    for(pk=0;pk<4;i++,pk++)
    {

        tk[i].r=l/2;
       tk[i].index=i;
       init_pos[i].index=i;

       p++;

       tk[i].x=ck[q]+mov[q];


       init_pos[i].x=ck[q];

       q++;

       tk[i].y=ck[q]+mov[q];


       init_pos[i].y=ck[q];

       q++;
       circle(tk[i].x,tk[i].y,tk[i].r);
       setfillstyle(1,cr[pk]);
       floodfill(tk[i].x,tk[i].y,7);
    }

   setcolor(0);
}
void swaps(int &a,int &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
void copy_a(int *mov,int *mov1,int *mov2,int *mov3,int *mov4)
{
    int i=0;


     for( int p=0;i<8;i++,p++)
    mov1[p]=mov[i];
     for( int p=0;i<16;i++,p++)
    mov2[p]=mov[i];
     for( int p=0;i<24;i++,p++)
    mov3[p]=mov[i];
     for( int p=0;i<32;i++,p++)
    mov4[p]=mov[i];
}
void draw(int *mov)
{
    int *mov1=new int[8],*mov2=new int [8];
    int *mov3=new int[8],*mov4=new int [8];
    copy_a(mov,mov1,mov2,mov3,mov4);

     setfillstyle(1,10);
     floodfill(100,100,WHITE);
     setcolor(0);
    int x=getmaxx(),y=getmaxy(),b=40,a=(x-y+2*b)/2-41,c=(x+y-2*b)/2,d=y-40,l=y/2-120,c1=1,c2=4,c3=2,c4=14;
      rectangle(a,b,c,d);
    bar(a,b,c,d,l,c1,c2,c3,c4);
     // blw

    rectangle(a+l,b+l,c-l,d-l);
    line(a+l,b+l,c-l,d-l);
    line(a+l,d-l,c-l,b+l);
    setfillstyle(1,2);
    floodfill(a+5+l,b+l+1,0);
    setfillstyle(1,1);
    floodfill(a+l+1,b+l+5,0);
    setfillstyle(1,14);
    floodfill(c-l-1,b+l+5,0);
    setfillstyle(1,4);
    floodfill(a+l+5,d-l-1,0);


   //way

      way(a,b+l,a+l,d-l,1);
      way(c-l,b+l,c,d-l,14);
      way1(a+l,d-l,c-l,d,4);
     way1(a+l,b,c-l,b+l,2);


    //
    a1=a,b1=b,p1=c,d1=d,l1=l;

      h1=d-b-2*l;
      h2=c-a-2*l;

    l-=1*l/100;
    a+=6*y/100,b+=6*y/100,c-=6*y/100,d-=50,l-=(12*y)/100,c1=c2=c3=c4=15;
      bar(a,b,c,d,l,c1,c2,c3,c4);





    a+=3*y/100,b+=3*y/100,c-=3*y/100,d-=3*y/100,l=l/2-5*y/100,c1=1,c2=4,c3=2,c4=14;

     bar(a,b,c,d,l,c1,c2,c3,c4);

      tokens(a,b,c,d,l,1,2,4,14,mov1);

     a+=10*y/100,c-=10*y/100;
    bar(a,b,c,d,l,c1,c2,c3,c4);

     tokens(a,b,c,d,l,1,2,4,14,mov2);

    b+=10*y/100,d-=10*y/100;
    bar(a,b,c,d,l,c1,c2,c3,c4);

     tokens(a,b,c,d,l,1,2,4,14,mov3);

    a-=10*y/100,c+=10*y/100;
    bar(a,b,c,d,l,c1,c2,c3,c4);
     tokens(a,b,c,d,l,1,2,4,14,mov4);

// dice
      setfillstyle(1,0);
      static int inital=0;
      if(inital==0) {
      di.x1=12*y/100,di.x2=2*di.x1,di.y1=di.x1,di.y2=2*di.x1;
      inital++;
      }
     bar3d(di.x1,di.y1,di.x2,di.y2,15,1);
     setcolor(8);
      settextstyle(1,0,8);

     outtextxy(di.x1+10,di.y1+10,"P");
    //
}
 void getpos()
 {

       POINT cursorposition;
     GetCursorPos(&cursorposition);
     int k=0;
     while(8){
            k=1;
    if(GetAsyncKeyState(VK_SHIFT)) {
    GetCursorPos(&cursorposition);
    if(k==1){
    cout<<cursorposition.x<<" "<<cursorposition.y<<endl;
    k=0;  }

    }
     }

 }
 int dice(int *mov)
 {
     char *ch=new char[100];

     setfillstyle(1,0);
     srand(time(NULL));
     int n=rand()%6+1;
   //  bar3d(100,100,200,200,15,1);      //size=100;
    settextstyle(1,0,8);
     POINT p;


   while(1) {

       GetCursorPos(&p);
       draw(mov);
      if(GetAsyncKeyState(VK_RBUTTON)&&p.x>=di.x1&&p.x<=di.x2&&p.y<=di.y2&&p.y>=di.y1){

     sprintf(ch,"%d",n);
     outtextxy(di.x1+10,di.y1+10,ch);

     delay(1);
     page=1-page;
      setactivepage(page);
               setvisualpage(1-page);

                cleardevice();

        return n;

      }


   }

 }
 void next(int *mov,int n)
 {
     int x=getmaxx(),y=getmaxy();
      settextstyle(1,0,8);

             if((n-1)%4==0) {
            di.x1=p1+100;
            di.x2=di.x1+100;
            di.y1=70;
            di.y2=di.y1+100;

             }
          else if((n-2)%4==0)
            {
                      di.x1=a1-200;
            di.x2=di.x1+100;
            di.y1=y-40-130;
            di.y2=di.y1+100;


            }

          else if((n-3)%4==0) {

             di.x1=p1+100;
            di.x2=di.x1+100;
             di.y1=y-40-130;
            di.y2=di.y1+100;  }
          else
             {
                      di.x1=a1-200;
            di.x2=di.x1+100;
             di.y1=70;
            di.y2=di.y1+100;
             }


             draw(mov);
          delay(500);

     page=1-page;
      setactivepage(page);
               setvisualpage(1-page);
               cleardevice();


 }
 int choose(int *opt)
 {
     POINT p;
     while(true)
     {

        GetCursorPos(&p);
if(GetAsyncKeyState(VK_LBUTTON)&&p.x>=tk[opt[0]].x-tk[opt[0]].r&&p.x<=tk[opt[0]].x+tk[opt[0]].r&&p.y>=tk[opt[0]].y-tk[opt[0]].r&&p.y<=tk[opt[0]].y+tk[opt[0]].r  )
                 return(opt[0]);
        else if(opt[1]!=-1){
if(GetAsyncKeyState(VK_LBUTTON)&&p.x>=tk[opt[1]].x-tk[opt[1]].r&&p.x<=tk[opt[1]].x+tk[opt[1]].r&&p.y>=tk[opt[1]].y-tk[opt[1]].r&&p.y<=tk[opt[1]].y+tk[opt[1]].r  )
                 return(opt[1]);
         else if(opt[2]!=-1)  {

if(GetAsyncKeyState(VK_LBUTTON)&&p.x>=tk[opt[2]].x-tk[opt[2]].r&&p.x<=tk[opt[2]].x+tk[opt[2]].r&&p.y>=tk[opt[2]].y-tk[opt[2]].r&&p.y<=tk[opt[2]].y+tk[opt[2]].r  )
                 return(opt[2]);
         else if(opt[3]!=-1)

if(GetAsyncKeyState(VK_LBUTTON)&&p.x>=tk[opt[3]].x-tk[opt[3]].r&&p.x<=tk[opt[3]].x+tk[opt[3]].r&&p.y>=tk[opt[3]].y-tk[opt[3]].r&&p.y<=tk[opt[3]].y+tk[opt[3]].r  )
                 return(opt[3]);


         }


        }

     }

 }
 void invalid()
 {
      settextstyle(1,0,10);
      outtextxy(100,100,"illegal move");
                delay(1);
     page=1-page;
      setactivepage(page);
               setvisualpage(1-page);
               cleardevice();
 }
  void anime(int n,int x,int y,int *mov,int pos)
  {
      int i=2*n,dif_x,dif_y,init_x,init_y;
      dif_x=x-tk[n].x;
           dif_y=y-tk[n].y;

           init_x=mov[i];
           init_y=mov[i+1];
       if(pos==0||pos==5||pos==3||pos==2||pos==4||pos==1||pos==6||pos==7)
       {


           for(int j=0;5;j+=l1/12)
           {


               if(pos==0||pos==5||pos==4)
               mov[i]=init_x+j;
               if(pos==1||pos==6||pos==7)
                mov[i]=init_x-j;
               if(pos==5||pos==3||pos==7)
               mov[i+1]=init_y-j;
               if(pos==2||pos==4||pos==6)
                mov[i+1]=init_y+j;
               if(mov[i]>=dif_x+init_x&&(pos==0||pos==5||pos==1||pos==6))
               {
                mov[i]=init_x+dif_x;
               mov[i+1]=init_y+dif_y;
               }
               if(mov[i+1]>=dif_y+init_y&&(pos==3||pos==2||pos==4||pos==7))
                 mov[i]=init_x+dif_x;
                 mov[i+1]=init_y+dif_y;
               draw(mov);

              delay(1);

               delay(1);
     page=1-page;
      setactivepage(page);
               setvisualpage(1-page);
               cleardevice();
              if(mov[i]>=dif_x+init_x&&(pos==0||pos==5||pos==4||pos==1||pos==6||pos==7))
                break;
              if(mov[i+1]>=dif_y+init_y&&(pos==3||pos==2))
                break;


           }


               draw(mov);
                 delay(1);
     page=1-page;
      setactivepage(page);
               setvisualpage(1-page);
               cleardevice();

       }



  }
 int* changes(int dice,int selected,int *mov)
 {
     int *a=new int[2];
     a[0]=-1,a[1]=-1;
      if(tk[selected].x==init_pos[selected].x&&tk[selected].y==init_pos[selected].y)
      {
          if(selected==0||selected%4==0)
          {
              a[0]=a1+l1/6+l1/12;
              a[1]=b1+l1+h1/6;
              return a;
          }
          else if(selected==1||(selected-1)%4==0)
          {

              a[0]=p1-l1-h2/6;
              a[1]=b1+l1/6+l1/12;
              return a;
          }
            else if(selected==2||(selected-2)%4==0)
          {
              a[0]=a1+l1+h2/6;
              a[1]=d1-l1/6-l1/12;
              return a;
          }
            else if(selected==3||(selected-3)%4==0)
          {

              a[0]=p1-l1/6-l1/12;
              a[1]=d1-l1-h1/6;
              return a;
          }

      }
      else
      {

             while(dice)
             {

                int num;
             if(tk[selected].y>=b1+l1&&tk[selected].y<=b1+l1+h1/3&&dice!=0){
                num=tk[selected].x-a1-l1/12;
                num/=l1/6;

                if(num<=5)
                {
                     num=6-num-1;
                    if(num==0)
                    {
                          anime(selected,a1+l1+h2/6,b1+l1-l1/12,mov,5);
                         dice--;
                    }

                   else if(dice<=num)
                    {
                        anime(selected,a1+l1/12+(dice+6-num-1)*l1/6,tk[selected].y,mov,0);

                        return a;
                    }
                    else
                    {
                        cout<<num<<endl;
                         anime(selected,a1+l1-l1/12,tk[selected].y,mov,0);

                         dice-=num;

                        anime(selected,a1+l1+h2/6,b1+l1-l1/12,mov,5);
                         dice--;
                    }
                }


             }
             // 1st

            if(tk[selected].x>=a1+l1&&tk[selected].x<=a1+l1+h2/3)
             {


                 num=b1+l1-l1/12-tk[selected].y;
                 num/=l1/6;
                 if(num>=0) {
                     num=6-num-1;

                     if(num==0)
                    {
                              anime(selected,a1+l1+h2/3+h2/6,tk[selected].y,mov,0);
                         dice--;
                    }

                   else if(dice<=num)
                    {
                        cout<<dice<<" "<<num<<endl;
                        anime(selected,tk[selected].x,b1+l1-l1/12-(dice+6-num-1)*l1/6,mov,3);
                        return a;
                    }
                    else
                    {
                        cout<<num<<endl;
                         anime(selected,tk[selected].x,b1+l1/12,mov,3);
                         dice-=num;

                        anime(selected,a1+l1+h2/3+h2/6,tk[selected].y,mov,0);
                         dice--;
                    }

                 }

             }

              if(tk[selected].x>=a1+l1+h2/3&&tk[selected].x<=a1+l1+h2/3+h2/3){
             if(tk[selected].x>=a1+l1+h2/3&&tk[selected].x<=a1+l1+h2/3+h2/3&&tk[selected].y>=b1&&tk[selected].y<=b1+l1/6&&dice!=0)
             {

                 if(selected==1||(selected-1)%4==0)
                 {
                     num=tk[selected].y-b1-l1/12;
                     num/=l1/6;
                     if(num<=5){
                        if(num==5)
                            anime(selected,tk[selected].x,b1+l1+l1/6,mov,2);

                        anime(selected,tk[selected].x,b1+l1/12+(dice+num)*l1/6,mov,2); }

                        return a;
                 }
                 else{

                    dice--;
                     anime(selected,a1+l1+h2/3+h2/6+h2/3,tk[selected].y,mov,0);

                 }
             }
             else{


                num=tk[selected].y-b1-l1/12;
                     num/=l1/6;

                     if(num<=5){
                        if(num==5)
                            anime(selected,tk[selected].x,b1+l1+l1/6,mov,2);

                        anime(selected,tk[selected].x,b1+l1/12+(dice+num)*l1/6,mov,2);
                        return a;
                     }


             }
              }
             if(tk[selected].x>=a1+l1+2*h2/3&&tk[selected].x<=a1+l1+h2)
             {
                 num=tk[selected].y-b1-l1/12;
                 num/=l1/6;
                 if(num<=5)
                 {
                     num=6-num-1;
                     if(num==0)
                     {
                         anime(selected,p1-l1+l1/12,b1+l1+h1/6,mov,4);
                         dice--;
                     }
                     else if(dice<=num)
                     {
                         anime(selected,tk[selected].x,b1+l1/12+(dice+6-num-1)*l1/6,mov,2);
                          return a;
                     }
                     else{

                         anime(selected,tk[selected].x,b1+l1-l1/12,mov,2);
                         dice-=num;
                        anime(selected,p1-l1+l1/12,b1+l1+h1/6,mov,4);
                        dice--;

                     }



                 }

             }
               // second
             if(tk[selected].y>=b1+l1&&tk[selected].y<=b1+l1+h1/3&&dice!=0){
                num=tk[selected].x-p1+l1-l1/12;
                num/=l1/6;

                if(num<=5)
                {
                     num=6-num-1;
                    if(num==0)
                    {
                          anime(selected,tk[selected].x,b1+l1+h1/3+h1/6,mov,2);
                         dice--;
                    }

                   else if(dice<=num)
                    {

                        anime(selected,p1-l1+l1/12+(dice+6-num-1)*l1/6,tk[selected].y,mov,0);

                        return a;
                    }
                    else
                    {

                         anime(selected,p1-l1/12,tk[selected].y,mov,0);

                         dice-=num;

                        anime(selected,tk[selected].x,b1+l1+h1/3+h1/6,mov,2);
                         dice--;
                    }
                }


             }
             if(tk[selected].y>=b1+l1+h1/3&&tk[selected].y<=b1+l1+h1/3+h1/3&&dice!=0){

             if(tk[selected].y>=b1+l1+h1/3&&tk[selected].y<=b1+l1+h1/3+h1/3&&tk[selected].x<=p1&&tk[selected].x>=p1-l1/6)
             {
                 if(selected==3||(selected-3)%4==0)
                 {

                     anime(selected,p1-l1/12-dice*l1/6,tk[selected].y,mov,1);

                     return a;
                 }
                 else
                 {
                     dice--;
                      anime(selected,tk[selected].x,b1+l1+h1/3+h1/6+h1/3,mov,2);
                 }
             }
             else{
                    cout<<"i am here"<<endl;
                   num=p1-l1/12-tk[selected].x;
                   num/=l1/6;
             if(num<=5) {
                    anime(selected,p1-l1/12-(dice+num)*l1/6,tk[selected].y,mov,1);
                    return a;
             }
             }
             }
          if(tk[selected].y<=b1+l1+h1&&tk[selected].y>=b1+l1+h1-h1/3&&dice!=0)
          {
              num=p1-l1/12-tk[selected].x;
              num/=l1/6;
              if(num<=5)
              {
                  num=6-num-1;
                  if(num==0)
                  {
                      anime(selected,p1-l1-h2/6,d1-l1+l1/12,mov,6);
                      dice--;
                  }
                  else{
                    if(dice<=num)
                    {
                       anime(selected,p1-l1/12-(dice+6-num-1)*l1/6,tk[selected].y,mov,1);
                        return a;
                    }
                    else
                    {
                        anime(selected,p1-l1+l1/12,tk[selected].y,mov,1);
                        dice-=num;
                        anime(selected,p1-l1-h2/6,d1-l1+l1/12,mov,6);
                      dice--;
                    }

                  }
              }
          }
          // third

          if(tk[selected].x<=p1-l1&&tk[selected].x>=p1-l1-h2/3&&dice!=0)
          {

              num=tk[selected].y-d1+l1-l1/12;
              num/=l1/6;
              if(num<=5)
              {
                  num=6-num-1;
                  if(num==0)
                  {
                      anime(selected,p1-l1-h2/3-h2/6,tk[selected].y,mov,1);
                      dice--;
                  }
                  else
                  {
                      if(dice<=num)
                      {
                          anime(selected,tk[selected].x,d1-l1+l1/12+(dice+6-num-1)*l1/6,mov,2);
                          return a;
                      }
                      else{

                        anime(selected,tk[selected].x,d1-l1/12,mov,2);
                        dice-=num;
                        anime(selected,p1-l1-h2/3-h2/6,tk[selected].y,mov,1);
                      dice--;
                      }
                  }
              }
          }

          if(tk[selected].x<=p1-l1-h2/3&&tk[selected].x>=p1-l1-h2/3-h2/3&&dice!=0)
             {


                 num=d1-l1/12-tk[selected].y;
                 num/=l1/6;
                 if(num==0)
                 {

                     if(selected==2||(selected-2)%4==0)
                     {

                         anime(selected,tk[selected].x,d1-l1/12-dice*l1/6,mov,3);
                         return a;
                     }
                     else{

                         anime(selected,p1-l1-h2/3-h2/6-h2/3,tk[selected].y,mov,1);
                        dice--;
                     }
                 }
                 else
                 {

                      anime(selected,tk[selected].x,d1-l1/12-(dice+num)*l1/6,mov,3);
                      return a;
                 }
             }
             if(tk[selected].x<=a1+l1+h2/3&&tk[selected].x>=a1+l1&&dice!=0)
             {
                 cout<<"entered1"<<endl;
                 num=d1-l1/12-tk[selected].y;
                 num/=l1/6;
                 if(num<=5)
                 {

                    num=6-num-1;
                     if(num==0)
                     {
                         anime(selected,a1+l1-l1/12,d1-l1-h1/6,mov,7);

                         dice--;
                     }
                     else
                     {
                         if(dice<=num)
                         {
                             anime(selected,tk[selected].x,d1-l1/12-(dice+6-num-1)*l1/6,mov,3);

                             return a;
                         }
                         else{

                            anime(selected,tk[selected].x,d1-l1+l1/12,mov,3);

                            dice-=num;
                            anime(selected,a1+l1-l1/12,d1-l1-h1/6,mov,7);
                         dice--;

                         }

                     }
                 }
             }
             //forth
             if(tk[selected].y>=b1+l1+2*h1/3&&tk[selected].y<=b1+l1+h1&&dice!=0)
             {
                 num=a1+l1-l1/12-tk[selected].x;
                 num/=l1/6;
                 if(num>=0)
                 {
                     num=6-num-1;
                     if(num==0)
                     {
                         anime(selected,tk[selected].x,b1+l1+h1/3+h1/6,mov,2);
                         dice--;

                     }
                     else{
                        if(dice<=num)
                        {
                            anime(selected,a1+l1-l1/12-(dice+6-num-1)*l1/6,tk[selected].y,mov,1);
                            return a;

                        }
                        else{
                            anime(selected,a1+l1/12,tk[selected].y,mov,1);
                            dice-=num;
                             anime(selected,tk[selected].x,b1+l1+h1/3+h1/6,mov,2);
                         dice--;
                        }
                     }
                 }
             }
             if(tk[selected].y>=b1+l1+h1/3&&tk[selected].y<=b1+l1+2*h1/3&&dice!=0)
             {
                 num=tk[selected].x-(a1+l1/12);
                 num/=l1/6;
                 if(num<=5)
                 {
                     if(num==0)
                     {
                         if(selected==0||selected%4==0)
                         {
                             cout<<"here"<<endl;
                             anime(selected,a1+l1/12+dice*l1/6,tk[selected].y,mov,0);
                             return a;
                         }
                         else{
                            anime(selected,tk[selected].x,b1+l1+h1/6,mov,3);
                            dice--;
                         }
                     }
                     else
                     {
                         anime(selected,a1+l1/12+(dice+num)*l1/6,tk[selected].y,mov,0);
                             return a;
                     }
                 }
             }

    }//while loop
      return a;
      }
 }
 int death=0;
  void deaths(int n,int *mov)
  {
     mov[2*n]=0;
     mov[2*n+1]=0;
      draw(mov);
      delay(10);
      page=1-page;
      setactivepage(page);
               setvisualpage(1-page);
               cleardevice();
               death=1;

  }
  int cheack(int n,int x1,int x2,int y1,int y2)
  {
      if(tk[n].x>=x1&&tk[n].x<=x2&&tk[n].y>=y1&&tk[n].y<=y2)
        return 0;
       return 1;
  }
   void killing(int n,int *mov)
   {
       int x1[]={a1+l1/6,a1+l1,p1-l1-h2/3,p1-l1/3-l1/6,p1-l1/6-l1/6,p1-l1-h2/3,a1+l1,a1+l1/3};
       int x2[]={a1+l1/3,a1+h2/3+l1,p1-l1,p1-l1/3,p1-l1/6,p1-l1,a1+l1+h2/3,a1+l1/3+l1/6};
       int y1[]={b1+l1,b1+l1/3,b1+l1/6,b1+l1,b1+2*h1/3+l1,d1-l1/3-l1/6,d1-l1/3,b1+l1+2*h1/3};
       int y2[]={b1+l1+h1/3,b1+l1/3+l1/6,b1+l1/3,b1+l1+h1/3,b1+h1+l1,d1-l1/3,d1-l1/6,b1+l1+h1};
       int k=0;
       for(int i=0;i<8;i++)
       {
           if(cheack(n,x1[i],x2[i],y1[i],y2[i])==0) {
                k=1;
           break;
           }
       }
       cout<<"value K"<<k<<endl;
       if(k==0)
       {
           int num=n-n/4*4;
           for(int i=0;i<16;i++)
           {
               if((i-num)%4!=0)
               {
                   cout<<i<<" "<<n<<" "<<num<<endl;
                   cout<<tk[i].x<<" "<<tk[n].x<<" "<<tk[i].y<<" "<<tk[n].y<<endl;
                   if(tk[i].x<=tk[n].x+l1/12&&tk[i].x>=tk[n].x-l1/12&&tk[i].y<=tk[n].y+l1/12&&tk[i].y>=tk[n].y-l1/12)
                   {
                       cout<<"piy "<<i<<" "<<n<<" "<<num<<endl;
                       deaths(i,mov);
                   }
               }
           }
       }
   }
 int* turn(int dice,int num,int *mov)
 {
       int *change=new int[3];



     int option[4]={-1,-1,-1,-1},yes=0;
     if(dice!=6)
     {
        for(int i=yes;i<4;i++)
        {
            if(tk[num].x!=init_pos[num].x||tk[num].y!=init_pos[num].y)
            {

                 option[yes]=num;
                 yes++;
            }

            num+=4;
        }


     }
     else {

            for(int i=yes;i<4;i++){
            option[yes]=num;
            yes++;
        num+=4;
      }
     }
     for(int i=0;i<yes;i++)
     {
         int z=option[i],num1;

             if(tk[z].x>=a1+l1+h2/3&&tk[z].x<=a1+l1+2*h2/3)
             {
                 if((num-1)%4==0) {
                 num1=tk[z].y-b1-l1/12-l1/6;
                                  num1/=l1/6;
                      if(num1<=5) {
                 if(num1+dice>5)
                  option[i]=-1;
                      }
                 }
                if((num-2)%4==0) {
                    num1=d1-l1/6-l1/12-tk[z].y;
                                     num1/=l1/6;

                 if(num1+dice>5&&num1<=5)
                  option[i]=-1;

                }

             }
            if(tk[z].y>=b1+l1+h1/3&&tk[z].y<=b1+l1+h1/3+h1/3)
             {
                 if((num)%4==0) {
                    num1=tk[z].x-a1-l1/6-l1/12;
                       num1/=l1/6;
                 if(num1+dice>5&&num1<=5)
                  option[i]=-1;
                 }
                 if((num-3)%4==0) {
                    num1=p1-l1/6-l1/12-tk[z].x;
                       num1/=l1/6;
                 if(num1+dice>5&&num1<=5)
                  option[i]=-1;
                 }


             }



     }
     int dec=0;

     for(int i=0;i<yes;i++)
     {
         while(option[i]==-1&&i<yes)
         {
             i++;
         }
         if(dec==0&&i==yes)
            option[0]=-1;
         else
         {
               option[dec]=option[i];

             if(i!=dec){
             option[i]=-1; }
             cout<<option[dec]<<endl;
             dec++;
         }
     }
     yes=dec;

     cout<<endl<<dice<<endl;
      if(option[0]==-1)
      {


         change[0]=change[1]=change[2]=-1;
         return change;
      }
      else {

               int select;

                select=choose(option);



                 change=changes(dice,select,mov);
                cout<<"sea "<<select<<endl;
                cout<<change[1]<<endl;
                 change[2]=select;
           killing(select,mov);
                 return change;
      }

 }
int main()
{
    DWORD w_sc=GetSystemMetrics(SM_CXSCREEN);
    DWORD h_sc=GetSystemMetrics(SM_CYSCREEN);
     int mov[32]={0};
    initwindow(w_sc,h_sc,"",0,0,true,true);

    setactivepage(1-page);
    draw(mov);
    setcolor(8);
    int TURN =0;
  while(7)
  {
    int k,i=0,*change=new int[3];
      if(TURN>3)
        TURN=0;

   setactivepage(page);
               setvisualpage(1-page);
               cleardevice();
                next(mov,TURN);
    k=dice(mov);
    change=turn(k,TURN,mov); /// turn change

    if(change[0]==-1) {
            cout<<"piyush34"<<endl;


    }
    else
    {

        int i=2*change[2];
        if(tk[change[2]].x!=change[0]&&tk[change[2]].y!=change[1])
        {
           if(tk[change[2]].x==init_pos[change[2]].x&&tk[change[2]].y==init_pos[change[2]].y) {
             mov[i]+=change[0]-tk[change[2]].x;
             mov[i+1]+=change[1]-tk[change[2]].y;
             draw(mov);
              delay(1);
     page=1-page;
      setactivepage(page);
               setvisualpage(1-page);
               cleardevice();

               }
             else
             {

             }
        }
        else
        {

        }

    }

   if(k!=6&&death==0) {
    TURN++;
      }
      death=0;

  }
    cout<<90<<endl;
    getch();
    return 0;
}





































































/*
  for(int j=mov[i],k=mov[i+1];k<=(change[1]-y1);j--,k++)
           {
               setactivepage(page);
               setvisualpage(1-page);
               cleardevice();
               if(j>=(change[0]-x1))
               mov[i]=j;
                mov[i+1]=k;
               draw(mov);


               page=1-page;
                delay(0);

           }
*/
