#include "perso.h"


void initPerso(perso *p)
  
{ p->spritesheet=IMG_Load("perso.png");
    
    p->position.x=50;
    p->position.y=500;
    p->position.h= 140;
    p->position.w= 100;
    p->direction=2;

    p->acceleration=0;
    p->vitesse=0;
    p->vitesseV=0;

    
    p->pos_sprite.x= 0;
    p->pos_sprite.y= 450;
    p->pos_sprite.h= 150;
    p->pos_sprite.w= 100;
}




void afficherPerso(perso p, SDL_Surface * screen){
    SDL_BlitSurface(p.spritesheet,&p.pos_sprite,screen,&p.position);
}


void animerPerso (perso* p){
    p->pos_sprite.x += 100;
    if (p->pos_sprite.x >= 300) p->pos_sprite.x = 0;

    p->pos_sprite.y = p->direction * 150 ;
}


void deplacerPerso (perso *p,int dt){
    double dx;
    dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ; 
    if ((p->direction==0))// || (p->direction==2))
    {
        p->position.x += dx ;
    }
    else if ((p->direction==1))
    p->position.x -= dx ;
   
}


void saut (perso* p) {
    if ((p->position.y==500)||(p->j==1))
    {
        p->vitesseV=-50;
    }
    
}










