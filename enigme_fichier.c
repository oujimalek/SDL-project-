#include "enigme_fichier.h"
#define QUESTION 3 
void init_ef(enigme_f *e)//generation aleatoire enigme
{char reponses[4][16];char question[100];char text[5];
FILE *fp;
   char buff[255];
   fp = fopen("enigme.txt", "r");
int l=rand()%QUESTION;l*=5;
for(int i=0;i<l;i++)
   fscanf(fp, "%s\n", buff);
fscanf(fp, "%s", question);
for(int i=0;i<4;i++)
fscanf(fp, "%s", reponses[i]);
e->bg=IMG_Load("background.jpeg");
TTF_Font *font=TTF_OpenFont("fonts/enigme.otf", 60);
SDL_Color color={0,50,100};
e->question = TTF_RenderText_Solid(font,question,color);
e->corr=rand()%4;
sprintf(question,"%s",reponses[e->corr]);
sprintf(reponses[e->corr],"%s",reponses[0]);
sprintf(reponses[0],"%s",question);
for(int i=0;i<4;i++) {sprintf(text,"%c %s",65+i,reponses[i]);e->reponses[i] = TTF_RenderText_Solid(font,text,color);
e->pos[i].x=100;e->pos[i].y=200 + 100*i;e->pos[i].w=e->reponses[i]->w;e->pos[i].h=20;
}
sprintf(text,"WON");e->won = TTF_RenderText_Solid(font,text,color);
sprintf(text,"LOST");e->lost = TTF_RenderText_Solid(font,text,color);
}
void animation_temps(time_t begin,int limite,SDL_Surface *screen)//animation enigme
{
time_t end = time( NULL);
unsigned long secondes = (unsigned long) difftime( end, begin );
SDL_Surface *s;
SDL_Rect pos;pos.y=20;
float a=secondes;a/=limite;
s = SDL_CreateRGBSurface(0,a*screen->w,10, 32,0,0,0, 10);
SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 255, 0, 0));
SDL_BlitSurface(s,NULL,screen,&pos);SDL_Flip(screen);
}
void afficher_e(enigme_f e,SDL_Surface *screen,int x)//affichage enigme
{
SDL_Rect pos;pos.x=100;pos.y=100;
SDL_BlitSurface(e.bg,NULL,screen,NULL);
SDL_BlitSurface(e.question,NULL,screen,&pos);
for(int i=0;i<4;i++){SDL_BlitSurface(e.reponses[i],NULL,screen,&e.pos[i]);}
e.pos[3].y+=100;
if(x==1) SDL_BlitSurface(e.won,NULL,screen,&e.pos[3]);
if(x==0) SDL_BlitSurface(e.lost,NULL,screen,&e.pos[3]);
}
int choix(enigme_f e)//choix reponses clavier
{
Uint8 *keystate = SDL_GetKeyState(NULL);
if ( keystate[SDLK_ESCAPE] ) return 5;
if ( keystate[SDLK_a] ) return 0;
if ( keystate[SDLK_b] ) return 1;
if ( keystate[SDLK_c] ) return 2;
if ( keystate[SDLK_d] ) return 3;
int x,y;
Uint32 buttons = SDL_GetMouseState(&x, &y);//mouse motion
SDL_Rect pos;pos.w=5;pos.h=5;pos.x=x;pos.y=y;
for(int i=0;i<4;i++)
{e.pos[i].y+=50;if ((buttons & SDL_BUTTON_LMASK) != 0)if(collision(pos,e.pos[i]))
return i;}
return -1;
}
time_t init_time()
{ 
return time( NULL );
}
int time_expired(time_t begin,int limit)
{
time_t end = time( NULL);
    unsigned long secondes = (unsigned long) difftime( end, begin );
if(secondes>=limit)return 1;return 0;
}

int enigme_fichier(SDL_Surface *screen)
{
screen=SDL_SetVideoMode(1000,800,32,SDL_SWSURFACE);
enigme_f e;
init_ef(&e);
int b=0;
time_t begin=init_time();
while(b==0)
{SDL_PumpEvents();
if(choix(e)==-1) {afficher_e(e,screen,-1);
animation_temps(begin,10,screen);}
else{if(choix(e)==e.corr) {afficher_e(e,screen,1);SDL_Flip(screen);SDL_Delay(2000);return 1;}
else afficher_e(e,screen,0);SDL_Flip(screen);b=1;}
}
SDL_Delay(2000);return 0;}
