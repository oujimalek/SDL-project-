#include "entete2.h"

/**
*@file fonction.c

*/


/**
@brief to initialize the first ennemi
@param e ENNEMI
@return Nothing

*/
void initEnnemi1(Ennemi*e)
{
//0 adrite
//1 agauuche

e->next=0;
e->position.x=0;
e->position.y=520;

e->direction=0;
e->m[0][0]=IMG_Load("images/cc1.png");
e->m[0][1]=IMG_Load("images/cc2.png");
e->m[0][2]=IMG_Load("images/cc3.png");
e->m[0][3]=IMG_Load("images/cc4.png");
e->m[0][4]=IMG_Load("images/cc5.png");
e->m[0][5]=IMG_Load("images/cc6.png");
e->m[0][6]=IMG_Load("images/cc7.png");
e->m[0][7]=IMG_Load("images/cc8.png");
e->m[0][8]=IMG_Load("images/cc9.png");
e->m[0][9]=IMG_Load("images/cc10.png");
e->m[1][0]=IMG_Load("images/c1.png");
e->m[1][1]=IMG_Load("images/c2.png");
e->m[1][2]=IMG_Load("images/c3.png");
e->m[1][3]=IMG_Load("images/c4.png");
e->m[1][4]=IMG_Load("images/c5.png");
e->m[1][5]=IMG_Load("images/c6.png");
e->m[1][6]=IMG_Load("images/c7.png");
e->m[1][7]=IMG_Load("images/c8.png");
e->m[1][8]=IMG_Load("images/c9.png");
e->m[1][9]=IMG_Load("images/c10.png");
e->position.w=148;
e->position.h=132;

//printf("e.posw=%d\n",e->position.w);
//printf("e.posh=%d\n",e->position.h);
}
/**
@brief to initialize the second ennemi
@param e ENNEMI
@return Nothing

*/
void initEnnemi2(Ennemi*e)
{
//0 adrite
//1 agauuche
//2 jump
e->next=0;
e->position.x=0;
e->position.y=0;

e->direction=0;
e->m[0][0]=IMG_Load("images/0.png");
e->m[0][1]=IMG_Load("images/1.png");
e->m[0][2]=IMG_Load("images/2.png");
e->m[0][3]=IMG_Load("images/3.png");
e->m[0][4]=IMG_Load("images/4.png");
e->m[0][5]=IMG_Load("images/5.png");	
e->m[0][6]=IMG_Load("images/6.png");
e->m[0][7]=IMG_Load("images/7.png");
e->m[0][8]=IMG_Load("images/8.png");
e->m[0][9]=IMG_Load("images/8.png");
e->m[1][0]=IMG_Load("images/00.png");
e->m[1][1]=IMG_Load("images/11.png");
e->m[1][2]=IMG_Load("images/22.png");
e->m[1][3]=IMG_Load("images/33.png");
e->m[1][4]=IMG_Load("images/44.png");
e->m[1][5]=IMG_Load("images/55.png");
e->m[1][6]=IMG_Load("images/66.png");
e->m[1][7]=IMG_Load("images/77.png");
e->m[1][8]=IMG_Load("images/88.png");
e->m[1][9]=IMG_Load("images/88.png");
e->position.w=148;
e->position.h=132;

}

/**
@brief to annimate  ennemi
@param e ENNEMI
@return Nothing

*/
void animerEnnemi( Ennemi * e)
{

e->next++;
if(e->next>9)
  {
  e->next=0;
  }


}
/**
@brief to show the  ennemi
@param e ENNEMI
@param screen SDL_SURFACE
@return Nothing

*/
void afficherEnnemi(Ennemi e, SDL_Surface *screen)
{
	
        SDL_BlitSurface(e.m[e.direction][e.next], NULL, screen, &e.position);

}
/**
@brief to MOVE  the  ennemi
@param e ENNEMI
@return Nothing

*/
void deplacer( Ennemi * e)
{
SDL_Surface *m[2][10];
int min =0;
int max=600;

if(e->position.x<min)
{
e->direction=0;

}

if(e->position.x>max)
{
e->direction=1;


}
if(e->direction==0)
  {	
    e->position.x+=8;
   // e->position.x+=3;

  }
if(e->direction==1)
  {
   //e->position.x-=10;
   e->position.x-=8;
 }
//printf("deplacer\n");
}
/**
@brief to show INITALIZE  THE BOOM ENNEMI
@param e ENNEMI

@return Nothing

*/
void initboom(image *a)
{
a->img=IMG_Load("images/borken.png");

//y=rand()% 100 +1;
a->position.x=175;
a->position.y=300;
a->position.w=277;
a->position.h=200;
}
/**
@brief to show AN  IMAGE
@param a IMAGE
@param screen SDL_SURFACE
@return Nothing

*/
void afficheimg(image a,SDL_Surface *screen)
{
        SDL_BlitSurface(a.img, NULL, screen, &a.position);
}
/**
@brief to check that there is a collision between two charcter or now the  ennemi
@param e ENNEMI
@param p SDL_Rect;
@return x

*/
int collisionBB (SDL_Rect e,SDL_Rect p)
{
    int collide;
p.w=p.w/3;
e.w=e.w/3;


    if (((p.x + p.w) < e.x) || (p.x > (e.x + e.w)) || ((p.y + p.h) < e.y) || (p.y > (e.y + e.h)))
    {
        collide = 0;
    }
    else
    {
        collide = 1;
    }
    
    return collide;
}

//treu
/*int collisionBB (SDL_Rect e,SDL_Rect p)
{
    int collide;
    if (((p.x + p.w) > e.x) || (p.x < (e.x + e.w)) || ((p.y + p.h) > e.y) || (p.y < (e.y + e.h)))
    {


        collide = 0;
    }
    else
    {



        collide = 1;
    }

    printf("collide =%d\n",collide);
 
   return collide;
}
*/

/*int collisionBB (SDL_Rect r1,SDL_Rect r2)

 {
    int collide;
    if ( r1.x <= r2.x+r2.w && r1.x+r1.w >= r2.x&&  r1.y<= r2.y + r2.h && r1.y+r1.h >= r2.y)
       {
        collide = 1;
       }
     else
       {
        collide = 0;
       }
    
    return collide;
 }*/


/**
@brief to initalize the  caracter  life
@param a image

@return Nothing

*/

void initcar(image *a)
{
a->img=IMG_Load("images/car.png");
//a->position.x=500;
//a->position.y=300;
a->position.x=400;

a->position.y=300;
a->position.w=240;
a->position.h=200;

}

/**
@brief to initialize the  game over image
@param a image

@return Nothing

*/
void initover(image *a)
{
a->img=IMG_Load("images/over.png");
a->position.x=80;
a->position.y=29;
}
/**
@brief to initalize the  first  life
@param a image

@return Nothing

*/
void initheart(image *a)
{
a->img=IMG_Load("images/heart.png");
a->position.x=0;
a->position.y=0;
a->position.w=50;
a->position.h=50;
}
/**
@brief to initalize the  second  life
@param a image

@return Nothing

*/

void initheart2(image *a)
{
a->img=IMG_Load("images/heart.png");
a->position.x=40;
a->position.y=0;
a->position.w=50;
a->position.h=50;
}
/**
@brief to initalize the  third  ennemy
@param e Ennemi

@return Nothing

*/

void initEnnemi3(Ennemi*e)
{
//0 adrite
//1 agauuche
//2 jump
e->next=0;
e->position.x=0;
e->position.y=550;

e->direction=0;
e->m[0][0]=IMG_Load("images/ennemi3/0.png");
e->m[0][1]=IMG_Load("images/ennemi3/1.png");
e->m[0][2]=IMG_Load("images/ennemi3/2.png");
e->m[0][3]=IMG_Load("images/ennemi3/3.png");
e->m[0][4]=IMG_Load("images/ennemi3/4.png");
e->m[0][5]=IMG_Load("images/ennemi3/5.png");
e->m[0][6]=IMG_Load("images/ennemi3/6.png");
e->m[0][7]=IMG_Load("images/ennemi3/7.png");
e->m[0][8]=IMG_Load("images/ennemi3/0.png");
e->m[0][9]=IMG_Load("images/ennemi3/1.png");
e->m[1][0]=IMG_Load("images/ennemi3/00.png");
e->m[1][1]=IMG_Load("images/ennemi3/11.png");
e->m[1][2]=IMG_Load("images/ennemi3/22.png");
e->m[1][3]=IMG_Load("images/ennemi3/33.png");
e->m[1][4]=IMG_Load("images/ennemi3/44.png");
e->m[1][5]=IMG_Load("images/ennemi3/55.png");
e->m[1][6]=IMG_Load("images/ennemi3/66.png");
e->m[1][7]=IMG_Load("images/ennemi3/77.png");
e->m[1][8]=IMG_Load("images/ennemi3/00.png");
e->m[1][9]=IMG_Load("images/ennemi3/11.png");
e->position.w=148;
e->position.h=132;
//printf("e.posw=%d\n",e->position.w);
//printf("e.posh=%d\n",e->position.h);
}
/**
@brief to initalize the  third  life
@param a image

@return Nothing

*/

void initheart3(image *a)
{
a->img=IMG_Load("images/heart.png");
a->position.x=80;
a->position.y=0;
a->position.w=50;
a->position.h=50;
}
/**
@brief to move character  with artificial intelligence 
@param e Ennemi
@param pos perso  the position of personal character in game
@return Nothing

*/

void deplacerIA( Ennemi * e, SDL_Rect posPerso)
{

if(e->position.x>posPerso.x && e->direction==0)
 {
  e->direction=1;
 }
if(e->position.x<posPerso.x && e->direction==1)
 {
  e->direction=0;
 }
if(e->direction==0)
  {	
   // e->position.x+=10;
    e->position.x+=3;


  }
if(e->direction==1)
  {
//   e->position.x-=10;
    e->position.x-=3;
  }

}
/**
@brief to move the  principal character of the game  
@param p image

@return Nothing

*/

void deplacer_perso(image *p)
{	
  SDL_Event event;
	SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            p->position.y=p->position.y-60;
                            break;
                        case SDLK_DOWN:
                            p->position.y=p->position.y+60;
                            break;
                        case SDLK_RIGHT:
                            p->position.x=p->position.x+60;
                            break;
                        case SDLK_LEFT:
                            p->position.x=p->position.x-60;
                            break;
                        }
                 break;
             }
}
//update ennemi
void updatee(Ennemi *e,int d)
{
//1 waiting
//2 following
//3 attacking
switch(e->stat)
   {  
	 case 1:animerEnnemi(e);
	break;
	case 2:animerEnnemi(e);
	//deplacement vers hero
	break;
	//deplacemnt et aatck
	break;
   }
}
