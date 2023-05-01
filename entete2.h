#ifndef ENTETE_H
#define ENTETE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 801
#define SCREEN_H 603
/**

*@file entete2.h
*/
/**


*@struct image
*@brief structure of an image  wich we can dispaly with it 


*/
typedef struct{
SDL_Surface *img;
SDL_Rect position;
}image;
/**


*@struct Ennemi
*@brief structure of the ennemi  


*/

typedef struct {
SDL_Rect position; /* !< Rectangle*/
SDL_Surface *m[2][10]; /* !< surface*/
int direction;/* !< direction*/
int next;/* !< next*/
int stat;
}Ennemi;

void initover(image *a);
void initcar(image *a);
void initboom(image *a);
void initheart(image *a);
void initheart2(image *a);
void initheart3(image *a);
void initEnnemi1(Ennemi*e);
void initEnnemi2(Ennemi*e);
void initEnnemi3(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi *e);
void deplacer( Ennemi *e);
void afficheimg(image a,SDL_Surface *screen);
int collisionBB (SDL_Rect e,SDL_Rect p);
void deplacerIA( Ennemi * e, SDL_Rect posPerso);
void deplacer_perso(image *p);

#endif







//khedma mte3i




//int collisionBB( personne p, Ennemi e) ou int collisionBB( SDL_Rect posp, SDL_Rect pose);
//void deplacerIA( Ennemi * e, SDL_Rect posPerso);

