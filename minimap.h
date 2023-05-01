#ifndef __MINIMAP_H 
#define __MINIMAP_H 
#include <SDL/SDL.h> 
#include <SDL/SDL_ttf.h> 
#include <time.h> 

typedef struct
{
    SDL_Rect position_perso; 
    SDL_Surface* sprite; 
} Personne; 

typedef struct
{
    SDL_Rect position_mini; 
    SDL_Surface* sprite; 
    SDL_Surface* sprite2;
    Personne pM; 
} minimap; 

typedef struct temps {
    SDL_Surface* texte; 
    SDL_Rect position; 

    TTF_Font* police; 
    
    char entree[7]; 
    
    int secondesEcoulees; 

    time_t t1, t2; 
    		   
    int min, sec; 
} temps;

typedef struct score {
    SDL_Surface* texte; 
    SDL_Rect position; 

    TTF_Font* police; 
    time_t t1, t2; 
    
    int s ;
    char msg_score[13];
    } score ;

void initmap(minimap* m); 
void afficherminimap(minimap m, SDL_Surface* screen,int niveau); 
void free_minimap(minimap* m); 
void sauvegarder(score *s, char nomjoueur[], char nomfichier[]);
void MAJMinimap(SDL_Rect posJoueur , minimap * m, float redimensionnementx , float redimentionnementy);
 void meilleur( char nomfichier[], int *score, char nomjoueur[]); 
void initialiser_temps(temps* t);
void afficher_temps(temps* t, SDL_Surface* ecran);
void free_temps(temps* t, SDL_Surface* ecran);


void initialiser_score(score* s);
void afficher_score(score* s, SDL_Surface* ecran);
void free_score(score* s, SDL_Surface* ecran);
#endif
