#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


//#include "update_score.h"


#include "entete2.h"
#include "perso.h"
#include "background.h"
#include "minimap.h"
#include "enigme_fichier.h"

int main()
{ TTF_Init();

/*------partie declaration des variables-------*/
TTF_Font *police=NULL;
SDL_Surface *texte1=NULL;
SDL_Surface *number1=NULL;
SDL_Surface *screen;
TTF_Font *text=NULL;
SDL_Surface *texte=NULL;
SDL_Event event;
SDL_Surface *back;
SDL_Surface *coll;
perso p;
char nomjoueur[20];
printf("nom joueur: ");
scanf("%s",nomjoueur);
int continuer=1,droite=0,gauche=0,up=0,dir=2;
Uint32 dt, t_prev;



initPerso(&p);
 

//sccccoreeeeee
  

police = TTF_OpenFont("outils/avocado.ttf", 35);

SDL_Color blanco={255,255,255}; 
texte1= TTF_RenderText_Blended(police,"score :",blanco);
p.position_textee.x=15;
p.position_textee.y=15;


////--------gestion de score-----//
 
p.number[20];
p.valeur_score=2000;
//p.valeur_score=p.valeur_score+1;
sprintf(p.number, "%d",(p.valeur_score));

number1= TTF_RenderText_Blended(police,p.number,blanco);


p.position_number.x=170;
p.position_number.y=20;
TTF_CloseFont(police);



//testevie2
text=TTF_OpenFont("outils/avocado.ttf",35);
SDL_Color couleur={255,255,255};
texte= TTF_RenderText_Blended(text,"Vie :",couleur);
p.position_texte.x=700;
p.position_texte.y=20;
TTF_CloseFont(text);
  
//testevie1


//phtc1

p.image_vie[0]=IMG_Load("outils/hearts03.png") ;
p.image_vie[1]=IMG_Load("outils/hearts02.png") ;
p.image_vie[2]=IMG_Load("outils/hearts01.png") ;
p.image_vie[3]=IMG_Load("outils/hearts00.png") ;
// positions
 p.position_vie.x=800;
 p.position_vie.y=20;
 p.val=3;
 

background b;
initBack(&b);
mouvement M;
Ennemi e,e3; 
initEnnemi1(&e);
initEnnemi3(&e3);
minimap m;    
    temps t;
    score s;
initmap(&m);
    initialiser_temps(&t);
    initialiser_score(&s);
printf("activer le partage d'écran?\n 1:oui, 0:non: ");
scanf("%d",&b.partage);




/*-------partie initialisation-------*/
screen=SDL_SetVideoMode (1000,696,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
back=IMG_Load("background.png");





//------------gestion de vie--------//
int vies=3;
 
   p.val--;
vies--;
    if (vies==2)
    {
	SDL_FreeSurface(p.image_vie[0]);}
    else if (vies==1)
    {SDL_FreeSurface(p.image_vie[1]);}  
    else if (vies==0)
    {SDL_FreeSurface(p.image_vie[2]);}
	//printf("val vie :%d \n",p.val);

/*--------- debut dboucle de jeu -----------*/
while (continuer)
{
t_prev=SDL_GetTicks();

  /*-------- gestion de l'input--------*/  
while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        continuer=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=1;M.right = 1;
                break;
            case SDLK_LEFT:
                gauche=1;M.left = 1;
                break;
            case SDLK_UP:
                up=1;
                break;  

 

      
        }
    break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;
                dir=2;
                p.vitesse=0;
		M.right = 0;
                break;
            case SDLK_LEFT:
                gauche=0;
                p.vitesse=0;
                dir=3;
		M.left = 0;	
                break;
            case SDLK_UP:
                up=0;
                break;    
       

    
        }
    break;
    
    }
}//fin de linput



/*-------------update----------*/

if (droite==1)
{
    p.direction=0;
   p.vitesse=10;
    p.acceleration+=0.5;}
if (gauche==1)
{
    p.direction=1;
    p.vitesse=10;
    p.acceleration+=0.5;
}
if (up==1) 
saut(&p);p.j=0;
if(p.position.x>800 -500*b.partage) {p.position.x=800-500*b.partage;scrolling(&b,  screen, M);}
if(p.position.x<100) {p.position.x=100;scrolling(&b,  screen, M);}




p.acceleration -=0.3;


if (p.acceleration<0 ) p.acceleration=0;
if (p.acceleration>4 ) p.acceleration=4;

p.position.y += p.vitesseV;
p.vitesseV += 10; 
if (p.position.y >= 500)
{
    p.vitesseV=0;
    p.position.y=500;
}
p.position.x+=b.camera1.x;
int col = collisionparfaite(b.masque[b.level],p.position);
while(col!=10) {p.position.y-=10;
col = collisionparfaite(b.masque[b.level],p.position);p.j=1;}
if(col==10)
deplacerPerso(&p,dt);
MAJMinimap(p.position ,&m, 0.14,0.3);
p.position.x-=b.camera1.x;
if(b.partage)
{if(e.position.x>350)e.direction=1;}

SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;
animerPerso(&p);

if ((p.vitesse==0)&&(p.acceleration==0))
{
    p.direction=dir;
}




deplacer(&e);

if(collisionBB(e3.position,p.position)) s.s--;
deplacerIA(&e3, p.position);







if(b.camera1.x>1850 + 500*b.partage) if(enigme_fichier(screen)) return 1;else {b.camera1.x=0;

screen=SDL_SetVideoMode (1000,696,32,SDL_HWSURFACE|SDL_DOUBLEBUF);}

/*---------------affichage------------
*/
//SDL_BlitSurface(back,NULL,screen,NULL);
e.position.x-=b.camera1.x;
e3.position.x-=b.camera1.x;//a repeter
aficherBack(screen, &b);
animerBackground(&b);
animerEnnemi(&e);
animerEnnemi(&e3);
afficherEnnemi(e,screen);
afficherEnnemi(e3,screen);
        afficherminimap(m, screen, 1);
        afficher_temps(&t, screen);
        afficher_score(&s, screen);
afficherPerso(p,screen);
e.position.x+=b.camera1.x;
e3.position.x+=b.camera1.x;//a repeter

      
SDL_BlitSurface(p.image_vie[p.val],NULL,screen,(&p.position_vie));

SDL_BlitSurface(texte,NULL,screen,&(p.position_texte));



 SDL_BlitSurface(texte1, NULL, screen,&p.position_textee);
SDL_BlitSurface(number1, NULL, screen,&p.position_number);
	


   //free
/*SDL_FreeSurface(p.image_vie[0]);
SDL_FreeSurface(p.image_vie[1]);
SDL_FreeSurface(p.image_vie[2]);
SDL_FreeSurface(p.image_vie[3]);*/

SDL_Flip(screen);
SDL_Delay(50);


}
meilleur("top scores",&s.s,nomjoueur);
    sauvegarder(  &s,  nomjoueur, "top scores");    
    free_minimap(&m);
    free_temps(&t, screen);
    free_score(&s,screen);
    SDL_FreeSurface(screen);
TTF_Quit();
}

