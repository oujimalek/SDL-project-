/**  
* @file main.c  
* @brief Testing Program.  
* @author C Team  
* @version 0.1  
* @date Apr 01, 2015  
*  
* Testing program for background scrollilng  *  
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include <math.h>



void initmap(minimap *m)
{
    m->position_mini.x=250;
    m->position_mini.y=0;
    m->sprite=IMG_Load("bk1 mini.png");
    m->sprite2=IMG_Load("bk2 mini.png");
    m->pM.sprite = IMG_Load("hannabel mini.png");
    m->pM.position_perso.x = 250;
    m->pM.position_perso.y = 120;
}

void afficherminimap (minimap m, SDL_Surface * screen,int niveau)
{        
    if (niveau==1)
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
    else if ( niveau==2)
    SDL_BlitSurface(m.sprite2,NULL,screen,&m.position_mini);
    
    SDL_BlitSurface(m.pM.sprite, NULL, screen, &m.pM.position_perso);
}

void free_minimap (minimap *m)
{
    SDL_FreeSurface(m->sprite);
    SDL_FreeSurface(m->pM.sprite);
}

void initialiser_temps(temps *t)
{
    t->texte = NULL;
    t->position.x=600; 
    t->position.y=15;   
    t->police = TTF_OpenFont("avocado.ttf", 15); 
    strcpy( t->entree,""); 
    (t->secondesEcoulees)=0;
    time(&(t->t1));		
}


void initialiser_score(score *s)
{
    s->texte = NULL;
    s->position.x=300; 
    s->position.y=15;  
    s->police = TTF_OpenFont("avocado.ttf", 15); 
    strcpy( s->msg_score,"Score:0"); 
    s->s=0;
    time(&(s->t1));
}

void afficher_temps(temps *t, SDL_Surface *screen)
{	
    SDL_Color couleurnoir= {0, 0,0};

    time(&(t->t2));

    t->secondesEcoulees = t->t2 - t->t1;

    t->min=((t->secondesEcoulees/60)%60);
    t->sec= ((t->secondesEcoulees)%60);
    sprintf(t->entree,"%02d:%02d",t->min,t->sec);
    
    t->texte = TTF_RenderText_Blended(t->police,t->entree, couleurnoir);

    SDL_BlitSurface(t->texte, NULL, screen, &(t->position)); 
}

void afficher_score(score *s, SDL_Surface *screen)
{	
    SDL_Color couleurnoir= {0, 0,0};
     time(&(s->t2));
     int t=s->t2-s->t1;
    
    sprintf(s->msg_score, "score: %d",s->s+t*15);
     s->texte = TTF_RenderText_Blended(s->police,s->msg_score, couleurnoir);

    SDL_BlitSurface(s->texte, NULL, screen, &(s->position)); 
}

void free_score(score *s,SDL_Surface *screen)
{
    SDL_FreeSurface(s->texte);
    TTF_CloseFont(s->police);
}

void free_temps(temps *t,SDL_Surface *screen)
{
    SDL_FreeSurface(t->texte);
    TTF_CloseFont(t->police);
}

void sauvegarder(score *s, char nomjoueur[], char nomfichier[])
{      
time(&(s->t2));
     int t=s->t2-s->t1;
    FILE* f=NULL;
    f= fopen(nomfichier , "a" );
    if (f==NULL)
        printf("il ya un erreur");
    else
    {
        fprintf(f,"%d,%s\n",s->s+t*15,nomjoueur);
        fclose(f);
    } 
}
void meilleur( char nomfichier[], int *score, char nomjoueur[])
{
FILE* f=NULL;
    f= fopen(nomfichier , "r" );
    if (f==NULL)
        printf("il ya un erreur");
    else
    {
      int maxscore=0 , s;
      char ligne[50] , topjoueur[15];
      while (fgets(ligne,50,f))
      
      { 
      sscanf(ligne,"%d,%s",&s,nomjoueur);
      if (s>maxscore)
      { 
      strcpy(topjoueur,nomjoueur);
      maxscore=s;
      } 
      } *score=maxscore;
      strcpy(nomjoueur,topjoueur);
        fclose(f);
    } 
}

void MAJMinimap(SDL_Rect posJoueur , minimap * m, float redimensionnementx , float redimensionnementy)
{

m->pM.position_perso.x= (posJoueur.x * redimensionnementx) + 250; 

m->pM.position_perso.y=  posJoueur.y*redimensionnementy - 30;
}





