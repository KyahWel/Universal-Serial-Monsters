#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <string.h>

// Declare Window Size and Frames
static const int width = 1000;
static const int height = 600;
static const int FPS = 60;
int frametime = 0;
int frametimea = 0;
int frametimeb = 0;
int avoidLag = 0;
int number1,number2;
int damagep1, damagep2, damage;

// Declare Window and Renderer
SDL_Window *window;
SDL_Renderer *renderer;

// Declare Flash drive scanner
bool driveE;
bool driveF;
bool driveG;

int user1 = 0;
int user2 = 0;

int UserRegistered1 = 0;
int UserRegistered2 = 0;

FILE *scanUSM1;
FILE *scanUSM2;
FILE *scanUSM3;
FILE *scanUserUSM1;
FILE *scanUserUSM2;
FILE *scanUserUSM3;

// Declare Registration
FILE *registerUSM;
FILE *loginUSM;


// Declare Loading Screen
SDL_Surface *loadingText;
SDL_Texture *loadingText_texture;
SDL_Surface *loadingText2;
SDL_Texture *loadingText2_texture;
SDL_Surface *loadingText3;
SDL_Texture *loadingText3_texture;

// Declare Loading Screen Positions
SDL_Rect loadingtext_position;

// Declare Title Screen
SDL_Surface *background;
SDL_Texture *background_texture;
SDL_Surface *titleScreen1;
SDL_Texture *titleScreen1_texture;
SDL_Surface *titleScreen2;
SDL_Texture *titleScreen2_texture;
SDL_Surface *pressAny;
SDL_Texture *pressAny_texture;
SDL_Surface *mainTitle;
SDL_Texture *mainTitle_texture;
SDL_Surface *gameDecide;
SDL_Texture *gameDecide_texture;
SDL_Surface *controls;
SDL_Texture *controls_texture;

// Declare Title Screen Positions
SDL_Rect background_position;
SDL_Rect titlescreen_position;
SDL_Rect pressany_position;
SDL_Rect mainTitle_position;
SDL_Rect gameDecide_position;
SDL_Rect controls_position;

// Declare Main Screen Selection & Cursor
SDL_Surface *choices;
SDL_Texture *choices_texture;
SDL_Surface *select;
SDL_Texture *select_texture;
SDL_Surface *gameChoice;
SDL_Texture *gameChoice_texture;
SDL_Surface *singleCursor;
SDL_Texture *singleCursor_texture;
SDL_Surface *cursorGenerator;
SDL_Texture *cursorGenerator_texture;
SDL_Surface *credit;
SDL_Texture *credit_texture;

// Declare Main Screen Selection & Cursor Position
SDL_Rect choices_position;
SDL_Rect select_position;
SDL_Rect gameChoice_position;
SDL_Rect singleCursor_position;
SDL_Rect cursorDecide_position;
SDL_Rect cursorGenerator_position;
SDL_Rect credit_position;

// Chansey (Main Menu)
SDL_Surface *chansey;
SDL_Texture *chansey_texture;
int chanseywidth, chanseyheight, cwidth, cheight;
SDL_Rect chansey_properties;
SDL_Rect chansey_position;
SDL_Rect chansey_b_position;
SDL_Rect chansey2_b_position;

// For Blaziken Front
SDL_Surface *blaziken;
SDL_Texture *blaziken_texture;
int blazikenwidth, blazikenheight, bwidth, bheight;
SDL_Rect blaziken_properties;
SDL_Rect blaziken_position;

// For Blaziken Back
SDL_Surface *blazikenb;
SDL_Texture *blazikenb_texture;
int blazikenbwidth, blazikenbheight, bbwidth, bbheight;
SDL_Rect blazikenb_properties;
SDL_Rect blazikenb_position;

// For Buizel Front
SDL_Surface *buizel;
SDL_Texture *buizel_texture;
int buizelwidth, buizelheight, buwidth, buheight;
SDL_Rect buizel_properties;
SDL_Rect buizel_position;
SDL_Rect buizelmid_position;

// For Buizel Back
SDL_Surface *buizelb;
SDL_Texture *buizelb_texture;
int buizelbwidth, buizelbheight, bubwidth, bubheight;
SDL_Rect buizelb_properties;
SDL_Rect buizelb_position;

// For Bulbasaur Front
SDL_Surface *bulbasaur;
SDL_Texture *bulbasaur_texture;
int bulbasaurwidth, bulbasaurheight, bulwidth, bulheight;
SDL_Rect bulbasaur_properties;
SDL_Rect bulbasaur_position;
SDL_Rect bulbasaurmid_position;

// For Bulbasaur Back
SDL_Surface *bulbasaurb;
SDL_Texture *bulbasaurb_texture;
int bulbasaurbwidth, bulbasaurbheight, bulbwidth, bulbheight;
SDL_Rect bulbasaurb_properties;
SDL_Rect bulbasaurb_position;

// For Celebi Front
SDL_Surface *celebi;
SDL_Texture *celebi_texture;
int celebiwidth, celebiheight, cwidth, cheight;
SDL_Rect celebi_properties;
SDL_Rect celebi_position;
SDL_Rect celebimid_position;

// For Celebi Back
SDL_Surface *celebib;
SDL_Texture *celebib_texture;
int celebibwidth, celebibheight, cbwidth, cbheight;
SDL_Rect celebib_properties;
SDL_Rect celebib_position;

// For Flareon Front
SDL_Surface *flareon;
SDL_Texture *flareon_texture;
int flareonwidth, flareonheight, fwidth, fheight;
SDL_Rect flareon_properties;
SDL_Rect flareon_position;
SDL_Rect flareonmid_position;

// For Flareon Back
SDL_Surface *flareonb;
SDL_Texture *flareonb_texture;
int flareonbwidth, flareonbheight, fbwidth, fbheight;
SDL_Rect flareonb_properties;
SDL_Rect flareonb_position;

// For Electrivire Front
SDL_Surface *electrivire;
SDL_Texture *electrivire_texture;
int electrivirewidth, electrivireheight, ewidth, eheight;
SDL_Rect electrivire_properties;
SDL_Rect electrivire_position;
SDL_Rect electriviremid_position;

// For Electrivire Back
SDL_Surface *electrivireb;
SDL_Texture *electrivireb_texture;
int electrivirebwidth, electrivirebheight, ebwidth, ebheight;
SDL_Rect electrivireb_properties;
SDL_Rect electrivireb_position;

// For Golem Front
SDL_Surface *golem;
SDL_Texture *golem_texture;
int golemwidth, golemheight, gwidth, gheight;
SDL_Rect golem_properties;
SDL_Rect golem_position;
SDL_Rect golemmid_position;

// For Golem Back
SDL_Surface *golemb;
SDL_Texture *golemb_texture;
int golembwidth, golembheight, gbwidth, gbheight;
SDL_Rect golemb_properties;
SDL_Rect golemb_position;

// For Greninja Front
SDL_Surface *greninja;
SDL_Texture *greninja_texture;
int greninjawidth, greninjaheight, grwidth, grheight;
SDL_Rect greninja_properties;
SDL_Rect greninja_position;
SDL_Rect greninjamid_position;

// For Greninja Back
SDL_Surface *greninjab;
SDL_Texture *greninjab_texture;
int greninjabwidth, greninjabheight, grbwidth, grbheight;
SDL_Rect greninjab_properties;
SDL_Rect greninjab_position;

// For Grotle Back
SDL_Surface *grotleb;
SDL_Texture *grotleb_texture;
int grotlebwidth, grotlebheight, grotbwidth, grotbheight;
SDL_Rect grotleb_properties;
SDL_Rect grotleb_position;

// For Grovyle Front
SDL_Surface *grovyle;
SDL_Texture *grovyle_texture;
int grovylewidth, grovyleheight, grovwidth, grovheight;
SDL_Rect grovyle_properties;
SDL_Rect grovyle_position;
SDL_Rect grovylemid_position;

// For Grovyle Back
SDL_Surface *grovyleb;
SDL_Texture *grovyleb_texture;
int grovylebwidth, grovylebheight, grovbwidth, grovbheight;
SDL_Rect grovyleb_properties;
SDL_Rect grovyleb_position;

// For Infernape Front
SDL_Surface *infernape;
SDL_Texture *infernape_texture;
int infernapewidth, infernapeheight, iwidth, iheight;
SDL_Rect infernape_properties;
SDL_Rect infernape_position;
SDL_Rect infernapemid_position;

// For Infernape Back
SDL_Surface *infernapeb;
SDL_Texture *infernapeb_texture;
int infernapebwidth, infernapebheight, ibwidth, ibheight;
SDL_Rect infernapeb_properties;
SDL_Rect infernapeb_position;

// For Jolteon Front
SDL_Surface *jolteon;
SDL_Texture *jolteon_texture;
int jolteonwidth, jolteonheight, jwidth, jheight;
SDL_Rect jolteon_properties;
SDL_Rect jolteon_position;
SDL_Rect jolteonmid_position;

// For Jolteon Back
SDL_Surface *jolteonb;
SDL_Texture *jolteonb_texture;
int jolteonbwidth, jolteonbheight, jbwidth, jbheight;
SDL_Rect jolteonb_properties;
SDL_Rect jolteonb_position;

// For Suicune Front
SDL_Surface *suicune;
SDL_Texture *suicune_texture;
int suicunewidth, suicuneheight, suwidth, suheight;
SDL_Rect suicune_properties;
SDL_Rect suicune_position;
SDL_Rect suicunemid_position;

// For Suicune Back
SDL_Surface *suicuneb;
SDL_Texture *suicuneb_texture;
int suicunebwidth, suicunebheight, subwidth, subheight;
SDL_Rect suicuneb_properties;
SDL_Rect suicuneb_position;

// For Luxray Front
SDL_Surface *luxray;
SDL_Texture *luxray_texture;
int luxraywidth, luxrayheight, lwidth, lheight;
SDL_Rect luxray_properties;
SDL_Rect luxray_position;
SDL_Rect luxraymid_position;

// For Luxray Back
SDL_Surface *luxrayb;
SDL_Texture *luxrayb_texture;
int luxraybwidth, luxraybheight, lbwidth, lbheight;
SDL_Rect luxrayb_properties;
SDL_Rect luxrayb_position;

// For Manectric Front
SDL_Surface *manectric;
SDL_Texture *manectric_texture;
int manectricwidth, manectricheight, mawidth, maheight;
SDL_Rect manectric_properties;
SDL_Rect manectric_position;
SDL_Rect manectricmid_position;

// For Manectric Back
SDL_Surface *manectricb;
SDL_Texture *manectricb_texture;
int manectricbwidth, manectricbheight, mabwidth, mabheight;
SDL_Rect manectricb_properties;
SDL_Rect manectricb_position;

// For Meganium Front
SDL_Surface *meganium;
SDL_Texture *meganium_texture;
int meganiumwidth, meganiumheight, mewidth, meheight;
SDL_Rect meganium_properties;
SDL_Rect meganium_position;
SDL_Rect meganiummid_position;

// For Meganium Back
SDL_Surface *meganiumb;
SDL_Texture *meganiumb_texture;
int meganiumbwidth, meganiumbheight, mebwidth, mebheight;
SDL_Rect meganiumb_properties;
SDL_Rect meganiumb_position;

// For Onix Front
SDL_Surface *onix;
SDL_Texture *onix_texture;
int onixwidth, onixheight, owidth, oheight;
SDL_Rect onix_properties;
SDL_Rect onix_position;
SDL_Rect onixmid_position;

// For Onix Back
SDL_Surface *onixb;
SDL_Texture *onixb_texture;
int onixbwidth, onixbheight, obwidth, obheight;
SDL_Rect onixb_properties;
SDL_Rect onixb_position;

// For Pikachu Front
SDL_Surface *pikachu;
SDL_Texture *pikachu_texture;
int pikachuwidth, pikachuheight, pwidth, pheight;
SDL_Rect pikachu_properties;
SDL_Rect pikachu_position;
SDL_Rect pikachumid_position;

// For Pikachu Back
SDL_Surface *pikachub;
SDL_Texture *pikachub_texture;
int pikachubwidth, pikachubheight, pbwidth, pbheight;
SDL_Rect pikachub_properties;
SDL_Rect pikachub_position;

// For Poliwrath Front
SDL_Surface *poliwrath;
SDL_Texture *poliwrath_texture;
int poliwrathwidth, poliwrathheight, powidth, poheight;
SDL_Rect poliwrath_properties;
SDL_Rect poliwrath_position;
SDL_Rect poliwrathmid_position;

// For Poliwrath Back
SDL_Surface *poliwrathb;
SDL_Texture *poliwrathb_texture;
int poliwrathbwidth, poliwrathbheight, pobwidth, pobheight;
SDL_Rect poliwrathb_properties;
SDL_Rect poliwrathb_position;

// For Raikou Front
SDL_Surface *raikou;
SDL_Texture *raikou_texture;
int raikouwidth, raikouheight, rwidth, rheight;
SDL_Rect raikou_properties;
SDL_Rect raikou_position;
SDL_Rect raikoumid_position;

// For Raikou Back
SDL_Surface *raikoub;
SDL_Texture *raikoub_texture;
int raikoubwidth, raikoubheight, rbwidth, rbheight;
SDL_Rect raikoub_properties;
SDL_Rect raikoub_position;

// For Regirock Front
SDL_Surface *regirock;
SDL_Texture *regirock_texture;
int regirockwidth, regirockheight, rewidth, reheight;
SDL_Rect regirock_properties;
SDL_Rect regirock_position;
SDL_Rect regirockmid_position;

// For Regirock Back
SDL_Surface *regirockb;
SDL_Texture *regirockb_texture;
int regirockbwidth, regirockbheight, rebwidth, rebheight;
SDL_Rect regirockb_properties;
SDL_Rect regirockb_position;

// For Rhydon Front
SDL_Surface *rhydon;
SDL_Texture *rhydon_texture;
int rhydonwidth, rhydonheight, rhwidth, rhheight;
SDL_Rect rhydon_properties;
SDL_Rect rhydon_position;
SDL_Rect rhydonmid_position;

// For Rhydon Back
SDL_Surface *rhydonb;
SDL_Texture *rhydonb_texture;
int rhydonbwidth, rhydonbheight, rhbwidth, rhbheight;
SDL_Rect rhydonb_properties;
SDL_Rect rhydonb_position;

// For Sandslash Front
SDL_Surface *sandslash;
SDL_Texture *sandslash_texture;
int sandslashwidth, sandslashheight, swidth, sheight;
SDL_Rect sandslash_properties;
SDL_Rect sandslash_position;
SDL_Rect sandslashmid_position;

// For Sandslash Back
SDL_Surface *sandslashb;
SDL_Texture *sandslashb_texture;
int sandslashbwidth, sandslashbheight, sbwidth, sbheight;
SDL_Rect sandslashb_properties;
SDL_Rect sandslashb_position;

// Declare Texts
SDL_Surface *textSurface;
SDL_Texture *startgamemessage;
SDL_Surface *text2Surface;
SDL_Texture *tutorialmessage;
SDL_Surface *text3Surface;
SDL_Texture *optionmessage;
SDL_Surface *text4Surface;
SDL_Texture *quitmessage;
SDL_Surface *text5Surface;
SDL_Texture *fdwarning;

// Declare Texts Positions
SDL_Rect mainScreenText;
SDL_Rect fdwarningposition;

// Load Guest Play
SDL_Surface *demoPlat;
SDL_Texture *demoPlat_texture;
SDL_Surface *demoBack;
SDL_Texture *demoBack_texture;

// Load Guest Play Positions
SDL_Rect demoPlat_position;
SDL_Rect demoBack_position;

// Load Monster Generate
SDL_Surface *generatePlat;
SDL_Texture *generatePlat_texture;
SDL_Surface *restart;
SDL_Texture *restart_texture;

// Load Monster Generate
SDL_Rect generatePlat_position;
SDL_Rect restart_position;

// Player 1 / 2 Win
SDL_Surface *player1w;
SDL_Texture *player1w_texture;
SDL_Surface *player2w;
SDL_Texture *player2w_texture;

SDL_Rect player1w_position;
SDL_Rect player2w_position;

// Declare Events
SDL_Event load;
SDL_Event premenuscreen;
SDL_Event mainmenu;
SDL_Event startgamechoice;
SDL_Event guestplay;
SDL_Event userregister;
SDL_Event usergenmons;
SDL_Event userplay;
SDL_Event tutorial;
SDL_Event showmonster;
SDL_Event credits;
SDL_Event registersuccess;
SDL_Event winp1;
SDL_Event winp2;

// Bool Declarations (Default Set to False)
bool mainGame = true;
bool loadingScreen = false;
bool menu = false;
bool premenu = false;
bool startGame = false;
bool guestP = false;
bool userReg = false;
bool generateMons = false;
bool userP = false;
bool tutScreen = false;
bool credScreen = false;
bool showmons = false;
bool regsuccess = false;
bool p1win = false;
bool p2win = false;

// Declare Music
Mix_Music *music;
Mix_Music *music_1;
Mix_Music *music_2;
Mix_Music *music_2_bg;
Mix_Music *music_3;
Mix_Music *select_1;
Mix_Music *select_2;

// Declare Monster Shadows
SDL_Surface *shadow;
SDL_Texture *shadow_texture;

SDL_Rect shadow_position_mainmenu;
SDL_Rect shadow_monsgen_position;
SDL_Rect p1_shadow_b_position;
SDL_Rect p2_shadow_b_position;

// Declare Monster Encounter Messages
SDL_Surface *buizelenc;
SDL_Texture *buizelenc_texture;
SDL_Surface *bulbasaurenc;
SDL_Texture *bulbasaurenc_texture;
SDL_Surface *celebienc;
SDL_Texture *celebienc_texture;
SDL_Surface *flareonenc;
SDL_Texture *flareonenc_texture;
SDL_Surface *electrivireenc;
SDL_Texture *electrivireenc_texture;
SDL_Surface *golemenc;
SDL_Texture *golemenc_texture;
SDL_Surface *greninjaenc;
SDL_Texture *greninjaenc_texture;
SDL_Surface *grovyleenc;
SDL_Texture *grovyleenc_texture;
SDL_Surface *infernapeenc;
SDL_Texture *infernapeenc_texture;
SDL_Surface *jolteonenc;
SDL_Texture *jolteonenc_texture;
SDL_Surface *suicuneenc;
SDL_Texture *suicuneenc_texture;
SDL_Surface *luxrayenc;
SDL_Texture *luxrayenc_texture;
SDL_Surface *manectricenc;
SDL_Texture *manectricenc_texture;
SDL_Surface *meganiumenc;
SDL_Texture *meganiumenc_texture;
SDL_Surface *onixenc;
SDL_Texture *onixenc_texture;
SDL_Surface *pikachuenc;
SDL_Texture *pikachuenc_texture;
SDL_Surface *poliwrathenc;
SDL_Texture *poliwrathenc_texture;
SDL_Surface *raikouenc;
SDL_Texture *raikouenc_texture;
SDL_Surface *regirockenc;
SDL_Texture *regirockenc_texture;
SDL_Surface *rhydonenc;
SDL_Texture *rhydonenc_texture;
SDL_Surface *sandslashenc;
SDL_Texture *sandslashenc_texture;

// Declare Bacground UI
SDL_Texture *Waterp1_texture;
SDL_Surface *Waterp1;
SDL_Rect Waterp1_position;

SDL_Texture *Waterp2_texture;
SDL_Surface *Waterp2;
SDL_Rect Waterp2_position;

SDL_Texture *Grassp1_texture;
SDL_Surface *Grassp1;
SDL_Rect Grassp1_position;

SDL_Texture *Grassp2_texture;
SDL_Surface *Grassp2;
SDL_Rect Grassp2_position;

SDL_Texture *Firep1_texture;
SDL_Surface *Firep1;
SDL_Rect Firep1_position;

SDL_Texture *Firep2_texture;
SDL_Surface *Firep2;
SDL_Rect Firep2_position;

SDL_Texture *Grass2p1_texture;
SDL_Surface *Grass2p1;
SDL_Rect Grass2p1_position;

SDL_Texture *Grass2p2_texture;
SDL_Surface *Grass2p2;
SDL_Rect Grass2p2_position;

SDL_Texture *Electricp1_texture;
SDL_Surface *Electricp1;
SDL_Rect Electricp1_position;

SDL_Texture *Electricp2_texture;
SDL_Surface *Electricp2;
SDL_Rect Electricp2_position;

SDL_Texture *Rockp1_texture;
SDL_Surface *Rockp1;
SDL_Rect Rockp1_position;

SDL_Texture *Rockp2_texture;
SDL_Surface *Rockp2;
SDL_Rect Rockp2_position;

SDL_Rect encountermessage_position;

// Declare TTF for Guest Play
SDL_Surface *player1health;
SDL_Texture *player1health_texture;
SDL_Surface *player2health;
SDL_Texture *player2health_texture;
SDL_Surface *p1damage;
SDL_Texture *p1damage_texture;
SDL_Surface *p2damage;
SDL_Texture *p2damage_texture;

SDL_Rect p1healthpos;
SDL_Rect p2healthpos;
SDL_Rect p1damagepos;
SDL_Rect p2damagepos;

TTF_Font *bitfont;


SDL_Color black = {0,0,0};
SDL_Color white = {255,255,255};

// Function for Text
void initText()
{


TTF_Init();

bitfont = TTF_OpenFont("resource/fonts/8-bit_pusab.ttf", 25);
player1health = TTF_RenderText_Solid(bitfont,  "200" , white);
player1health_texture = SDL_CreateTextureFromSurface(renderer, player1health);

player2health = TTF_RenderText_Solid(bitfont, "200" , white);
player2health_texture = SDL_CreateTextureFromSurface(renderer, player2health);

p1damage = TTF_RenderText_Solid(bitfont, "0" , white);
p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);

p2damage = TTF_RenderText_Solid(bitfont, "0" , white);
p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);

SDL_QueryTexture(player1health_texture, NULL, NULL, &p1healthpos.w, &p1healthpos.h);
SDL_QueryTexture(player2health_texture, NULL, NULL, &p2healthpos.w, &p2healthpos.h);
SDL_QueryTexture(p1damage_texture, NULL, NULL, &p1damagepos.w, &p1damagepos.h);
SDL_QueryTexture(p2damage_texture, NULL, NULL, &p2damagepos.w, &p2damagepos.h);

p1healthpos.x = 790;
p1healthpos.y = 45;
p2healthpos.x = 50;
p2healthpos.y = 510;

p1damagepos.x = 50;
p1damagepos.y = 425;
p2damagepos.x = 855;
p2damagepos.y = 130;
}


// Declare BG UI

void wp1()
{
    Waterp1 = IMG_Load("resource/Skills/wp1.png");
    Waterp1_texture = SDL_CreateTextureFromSurface(renderer, Waterp1);
    Waterp1_position.x = 0;
    Waterp1_position.y = 0;
    Waterp1_position.h = 600;
    Waterp1_position.w = 1000;

}
void wp2 ()
{
    Waterp2 = IMG_Load("resource/Skills/wp2.png");
    Waterp2_texture = SDL_CreateTextureFromSurface(renderer, Waterp2);
    Waterp2_position.x = 0;
    Waterp2_position.y = 0;
    Waterp2_position.h = 600;
    Waterp2_position.w = 1000;

}
void gp1()
{
    Grassp1 = IMG_Load("resource/Skills/gp1.png");
    Grassp1_texture = SDL_CreateTextureFromSurface(renderer, Grassp1);
    Grassp1_position.x = 0;
    Grassp1_position.y = 0;
    Grassp1_position.h = 600;
    Grassp1_position.w = 1000;
}
void gp2()
{
    Grassp2 = IMG_Load("resource/Skills/gp2.png");
    Grassp2_texture = SDL_CreateTextureFromSurface(renderer, Grassp2);
    Grassp2_position.x = 0;
    Grassp2_position.y = 0;
    Grassp2_position.h = 600;
    Grassp2_position.w = 1000;
}
void g2p1()
{
    Grass2p1 = IMG_Load("resource/Skills/g2p1.png");
    Grass2p1_texture = SDL_CreateTextureFromSurface(renderer, Grass2p1);
    Grass2p1_position.x = 0;
    Grass2p1_position.y = 0;
    Grass2p1_position.h = 600;
    Grass2p1_position.w = 1000;

}
void g2p2()
{
    Grass2p2 = IMG_Load("resource/Skills/g2p2.png");
    Grass2p2_texture = SDL_CreateTextureFromSurface(renderer, Grass2p2);
    Grass2p2_position.x = 0;
    Grass2p2_position.y = 0;
    Grass2p2_position.h = 600;
    Grass2p2_position.w = 1000;
}
void fp1()
{
    Firep1 = IMG_Load("resource/Skills/fp1.png");
    Firep1_texture = SDL_CreateTextureFromSurface(renderer, Firep1);
    Firep1_position.x = 0;
    Firep1_position.y = 0;
    Firep1_position.h = 600;
    Firep1_position.w = 1000;
}
void fp2()
{
    Firep2 = IMG_Load("resource/Skills/fp2.png");
    Firep2_texture = SDL_CreateTextureFromSurface(renderer, Firep2);
    Firep2_position.x = 0;
    Firep2_position.y = 0;
    Firep2_position.h = 600;
    Firep2_position.w = 1000;
}
void ep1()
{
    Electricp1 = IMG_Load("resource/Skills/ep1.png");
    Electricp1_texture = SDL_CreateTextureFromSurface(renderer, Electricp1);
    Electricp1_position.x = 0;
    Electricp1_position.y = 0;
    Electricp1_position.h = 600;
    Electricp1_position.w = 1000;
}
void ep2()
{
    Electricp2 = IMG_Load("resource/Skills/ep2.png");
    Electricp2_texture = SDL_CreateTextureFromSurface(renderer, Electricp2);
    Electricp2_position.x = 0;
    Electricp2_position.y = 0;
    Electricp2_position.h = 600;
    Electricp2_position.w = 1000;
}
void rp1()
{
    Rockp1 = IMG_Load("resource/Skills/earthp1.png");
    Rockp1_texture = SDL_CreateTextureFromSurface(renderer, Rockp1);
    Rockp1_position.x = 0;
    Rockp1_position.y = 0;
    Rockp1_position.h = 600;
    Rockp1_position.w = 1000;
}
void rp2()
{
    Rockp2 = IMG_Load("resource/Skills/earthp2.png");
    Rockp2_texture = SDL_CreateTextureFromSurface(renderer, Rockp2);
    Rockp2_position.x = 0;
    Rockp2_position.y = 0;
    Rockp2_position.h = 600;
    Rockp2_position.w = 1000;
}

// Declare Pokemon Animation
void animationBuizelp1()
{
     frametimea++;
            if(FPS/frametimea == 20)
            {
                frametimea = 0;
                buizelb_properties.x += bubwidth;
                if (buizelb_properties.x >= buizelbwidth)
                {
                    buizelb_properties.x = 0;
                    buizelb_properties.y += bubheight;
                    if (buizelb_properties.y >= buizelbheight)
                    {
                        buizelb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , buizelb_texture, &buizelb_properties, &buizelb_position);

            }
}
void animationBuizelp2()
{
    frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                buizel_properties.x += buwidth;
                if (buizel_properties.x >= buizelwidth)
                {
                    buizel_properties.x = 0;
                    buizel_properties.y += buheight;
                    if (buizel_properties.y >= buizelheight)
                    {
                        buizel_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , buizel_texture, &buizel_properties, &buizel_position);
                SDL_RenderPresent(renderer);
            }

}
void animationBulbasaurp1()
{
    frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                bulbasaurb_properties.x += bulbwidth;
                if (bulbasaurb_properties.x >= bulbasaurbwidth)
                {
                    bulbasaurb_properties.x = 0;
                    bulbasaurb_properties.y += bulbheight;
                    if (bulbasaurb_properties.y >= bulbasaurbheight)
                    {
                        bulbasaurb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , bulbasaurb_texture, &bulbasaurb_properties, &bulbasaurb_position);

            }
}
void animationBulbasaurp2()
{
    frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                bulbasaur_properties.x += bulwidth;
                if (bulbasaur_properties.x >= bulbasaurwidth)
                {
                    bulbasaur_properties.x = 0;
                    bulbasaur_properties.y += bulheight;
                    if (bulbasaur_properties.y >= bulbasaurheight)
                    {
                        bulbasaur_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, bulbasaur_texture, &bulbasaur_properties, &bulbasaur_position);
                SDL_RenderPresent(renderer);
            }
}
void animationCelebip1()
{
    frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                celebib_properties.x += cbwidth;
                if (celebib_properties.x >= celebibwidth)
                {
                    celebib_properties.x = 0;
                    celebib_properties.y += cbheight;
                    if (celebib_properties.y >= celebibheight)
                    {
                        celebib_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, celebib_texture, &celebib_properties, &celebib_position);
            }
}
void animationCelebip2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                celebi_properties.x += cwidth;
                if (celebi_properties.x >= celebiwidth)
                {
                    celebi_properties.x = 0;
                    celebi_properties.y += cheight;
                    if (celebi_properties.y >= celebiheight)
                    {
                        celebi_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, celebi_texture, &celebi_properties, &celebi_position);
                SDL_RenderPresent(renderer);
            }
}
void animationFlareonp1()
{
    frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                flareonb_properties.x += fbwidth;
                if (flareonb_properties.x >= flareonbwidth)
                {
                    flareonb_properties.x = 0;
                    flareonb_properties.y += fbheight;
                    if (flareonb_properties.y >= flareonbheight)
                    {
                        flareonb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , flareonb_texture, &flareonb_properties, &flareonb_position);
            }
}
void animationFlareonp2()
{
    frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                flareon_properties.x += fwidth;
                if (flareon_properties.x >= flareonwidth)
                {
                    flareon_properties.x = 0;
                    flareon_properties.y += fheight;
                    if (flareon_properties.y >= flareonheight)
                    {
                        flareon_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , flareon_texture, &flareon_properties, &flareon_position);
                SDL_RenderPresent(renderer);
            }
}
void animationElectrivirep1()
{
    frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                electrivireb_properties.x += ebwidth;
                if (electrivireb_properties.x >= electrivirebwidth)
                {
                    electrivireb_properties.x = 0;
                    electrivireb_properties.y += ebheight;
                    if (electrivireb_properties.y >= electrivirebheight)
                    {
                        electrivireb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , electrivireb_texture, &electrivireb_properties, &electrivireb_position);
            }
}
void animationElectrivirep2()
{
    frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                electrivire_properties.x += ewidth;
                if (electrivire_properties.x >= electrivirewidth)
                {
                    electrivire_properties.x = 0;
                    electrivire_properties.y += eheight;
                    if (electrivire_properties.y >= electrivireheight)
                    {
                        electrivire_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , electrivire_texture, &electrivire_properties, &electrivire_position);
                SDL_RenderPresent(renderer);
            }
}
void animationGolemp1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                golemb_properties.x += gbwidth;
                if (golemb_properties.x >= golembwidth)
                {
                    golemb_properties.x = 0;
                    golemb_properties.y += gbheight;
                    if (golemb_properties.y >= golembheight)
                    {
                        golemb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , golemb_texture, &golemb_properties, &golemb_position);
            }
}
void animationGolemp2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                golem_properties.x += gwidth;
                if (golem_properties.x >= golemwidth)
                {
                    golem_properties.x = 0;
                    golem_properties.y += gheight;
                    if (golem_properties.y >= golemheight)
                    {
                        golem_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , golem_texture, &golem_properties, &golem_position);
                SDL_RenderPresent(renderer);
            }
}
void animationGreninjap1()
{
    frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                greninjab_properties.x += grbwidth;
                if (greninjab_properties.x >= greninjabwidth)
                {
                    greninjab_properties.x = 0;
                    greninjab_properties.y += grbheight;
                    if (greninjab_properties.y >= greninjabheight)
                    {
                        greninjab_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , greninjab_texture, &greninjab_properties, &greninjab_position);
            }
}
void animationGreninjap2()
{
    frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                greninja_properties.x += grwidth;
                if (greninja_properties.x >= greninjawidth)
                {
                    greninja_properties.x = 0;
                    greninja_properties.y += grheight;
                    if (greninja_properties.y >= greninjaheight)
                    {
                        greninja_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , greninja_texture, &greninja_properties, &greninja_position);
                SDL_RenderPresent(renderer);
            }
}
void animationGrovylep1()
{
    frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                grovyleb_properties.x += grovbwidth;
                if (grovyleb_properties.x >= grovylebwidth)
                {
                    grovyleb_properties.x = 0;
                    grovyleb_properties.y += grovbheight;
                    if (grovyleb_properties.y >= grovylebheight)
                    {
                       grovyleb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , grovyleb_texture, &grovyleb_properties, &grovyleb_position);
            }
}
void animationGrovylep2()
{
    frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                grovyle_properties.x += grovwidth;
                if (grovyle_properties.x >= grovylewidth)
                {
                    grovyle_properties.x = 0;
                    grovyle_properties.y += grovheight;
                    if (grovyle_properties.y >= grovyleheight)
                    {
                       grovyle_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , grovyle_texture, &grovyle_properties, &grovyle_position);
                SDL_RenderPresent(renderer);
            }
}
void animationInfernapep1()
{
    frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                infernapeb_properties.x += ibwidth;
                if (infernapeb_properties.x >= infernapebwidth)
                {
                    infernapeb_properties.x = 0;
                    infernapeb_properties.y += ibheight;
                    if (infernapeb_properties.y >= infernapebheight)
                    {
                        infernapeb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , infernapeb_texture, &infernapeb_properties, &infernapeb_position);

            }
}
void animationInfernapep2()
{
    frametimeb++;
            if(FPS/frametimeb== 10)
            {
                frametimeb = 0;
                infernape_properties.x += iwidth;
                if (infernape_properties.x >= infernapewidth)
                {
                    infernape_properties.x = 0;
                    infernape_properties.y += iheight;
                    if (infernape_properties.y >= infernapeheight)
                    {
                        infernape_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , infernape_texture, &infernape_properties, &infernape_position);
                SDL_RenderPresent(renderer);
            }
}
void animationJolteonp1()
{
    frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                jolteonb_properties.x += jbwidth;
                if (jolteonb_properties.x >= jolteonbwidth)
                {
                    jolteonb_properties.x = 0;
                    jolteonb_properties.y += jbheight;
                    if (jolteonb_properties.y >= jolteonbheight)
                    {
                        jolteonb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , jolteonb_texture, &jolteonb_properties, &jolteonb_position);

            }
}
void animationJolteonp2()
{
    frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                jolteon_properties.x += jwidth;
                if (jolteon_properties.x >= jolteonwidth)
                {
                    jolteon_properties.x = 0;
                    jolteon_properties.y += jheight;
                    if (jolteon_properties.y >= jolteonheight)
                    {
                        jolteon_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , jolteon_texture, &jolteon_properties, &jolteon_position);
                SDL_RenderPresent(renderer);
            }
}
void animationSuicunep1()
{
     frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                suicuneb_properties.x += subwidth;
                if (suicuneb_properties.x >= suicunebwidth)
                {
                    suicuneb_properties.x = 0;
                    suicuneb_properties.y += subheight;
                    if (suicuneb_properties.y >= suicunebheight)
                    {
                        suicuneb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, suicuneb_texture, &suicuneb_properties, &suicuneb_position);
            }
}
void animationSuicunep2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                suicune_properties.x += suwidth;
                if (suicune_properties.x >= suicunewidth)
                {
                    suicune_properties.x = 0;
                    suicune_properties.y += suheight;
                    if (suicune_properties.y >= suicuneheight)
                    {
                        suicune_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, suicune_texture, &suicune_properties, &suicune_position);
                SDL_RenderPresent(renderer);
            }
}
void animationLuxrayp1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                luxrayb_properties.x += lbwidth;
                if (luxrayb_properties.x >= luxraybwidth)
                {
                    luxrayb_properties.x = 0;
                    luxrayb_properties.y += lbheight;
                    if (luxrayb_properties.y >= luxraybheight)
                    {
                        luxrayb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, luxrayb_texture, &luxrayb_properties, &luxrayb_position);
            }
}
void animationLuxrayp2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                luxray_properties.x += lwidth;
                if (luxray_properties.x >= luxraywidth)
                {
                    luxray_properties.x = 0;
                    luxray_properties.y += lheight;
                    if (luxray_properties.y >= luxrayheight)
                    {
                        luxray_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, luxray_texture, &luxray_properties, &luxray_position);
                SDL_RenderPresent(renderer);
            }
}
void animationManectricp1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                manectricb_properties.x += mabwidth;
                if (manectricb_properties.x >= manectricbwidth)
                {
                    manectricb_properties.x = 0;
                    manectricb_properties.y += mabheight;
                    if (manectricb_properties.y >= manectricbheight)
                    {
                        manectricb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, manectricb_texture, &manectricb_properties, &manectricb_position);
            }
}
void animationManectricp2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                manectric_properties.x += mawidth;
                if (manectric_properties.x >= manectricwidth)
                {
                    manectric_properties.x = 0;
                    manectric_properties.y += maheight;
                    if (manectric_properties.y >= manectricheight)
                    {
                        manectric_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, manectric_texture, &manectric_properties, &manectric_position);
                SDL_RenderPresent(renderer);
            }
}
void animationMeganiump1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                meganiumb_properties.x += mebwidth;
                if (meganiumb_properties.x >= meganiumbwidth)
                {
                    meganiumb_properties.x = 0;
                    meganiumb_properties.y += mebheight;
                    if (meganiumb_properties.y >= meganiumbheight)
                    {
                        meganiumb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, meganiumb_texture, &meganiumb_properties, &meganiumb_position);
            }
}
void animationMeganiump2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                meganium_properties.x += mewidth;
                if (meganium_properties.x >= meganiumwidth)
                {
                    meganium_properties.x = 0;
                    meganium_properties.y += meheight;
                    if (meganium_properties.y >= meganiumheight)
                    {
                        meganium_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, meganium_texture, &meganium_properties, &meganium_position);
                SDL_RenderPresent(renderer);
            }
}
void animationOnixp1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                onixb_properties.x += obwidth;
                if (onixb_properties.x >= onixbwidth)
                {
                    onixb_properties.x = 0;
                    onixb_properties.y += obheight;
                    if (onixb_properties.y >= onixbheight)
                    {
                        onixb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, onixb_texture, &onixb_properties, &onixb_position);
            }
}
void animationOnixp2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                onix_properties.x += owidth;
                if (onix_properties.x >= onixwidth)
                {
                    onix_properties.x = 0;
                    onix_properties.y += oheight;
                    if (onix_properties.y >= onixheight)
                    {
                        onix_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, onix_texture, &onix_properties, &onix_position);
                SDL_RenderPresent(renderer);
            }
}
void animationPikachup1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                pikachub_properties.x += pbwidth;
                if (pikachub_properties.x >= pikachubwidth)
                {
                    pikachub_properties.x = 0;
                    pikachub_properties.y += pbheight;
                    if (pikachub_properties.y >= pikachubheight)
                    {
                        pikachub_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, pikachub_texture, &pikachub_properties, &pikachub_position);
            }
}
void animationPikachup2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                pikachu_properties.x += pwidth;
                if (pikachu_properties.x >= pikachuwidth)
                {
                    pikachu_properties.x = 0;
                    pikachu_properties.y += pheight;
                    if (pikachu_properties.y >= pikachuheight)
                    {
                        pikachu_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, pikachu_texture, &pikachu_properties, &pikachu_position);
                SDL_RenderPresent(renderer);
            }
}
void animationPoliwrathp1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                poliwrathb_properties.x += pobwidth;
                if (poliwrathb_properties.x >= poliwrathbwidth)
                {
                    poliwrathb_properties.x = 0;
                    poliwrathb_properties.y += pobheight;
                    if (poliwrathb_properties.y >= poliwrathbheight)
                    {
                        poliwrathb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, poliwrathb_texture, &poliwrathb_properties, &poliwrathb_position);
            }
}
void animationPoliwrathp2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                poliwrath_properties.x += powidth;
                if (poliwrath_properties.x >= poliwrathwidth)
                {
                    poliwrath_properties.x = 0;
                    poliwrath_properties.y += poheight;
                    if (poliwrath_properties.y >= poliwrathheight)
                    {
                        poliwrath_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, poliwrath_texture, &poliwrath_properties, &poliwrath_position);
                SDL_RenderPresent(renderer);
            }
}
void animationRaikoup1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                raikoub_properties.x += rbwidth;
                if (raikoub_properties.x >= raikoubwidth)
                {
                    raikoub_properties.x = 0;
                    raikoub_properties.y += rbheight;
                    if (raikoub_properties.y >= raikoubheight)
                    {
                        raikoub_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, raikoub_texture, &raikoub_properties, &raikoub_position);
            }
}
void animationRaikoup2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                raikou_properties.x += rwidth;
                if (raikou_properties.x >= raikouwidth)
                {
                    raikou_properties.x = 0;
                    raikou_properties.y += rheight;
                    if (raikou_properties.y >= raikouheight)
                    {
                        raikou_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, raikou_texture, &raikou_properties, &raikou_position);
                SDL_RenderPresent(renderer);
            }
}
void animationRegirockp1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                regirockb_properties.x += rebwidth;
                if (regirockb_properties.x >= regirockbwidth)
                {
                    regirockb_properties.x = 0;
                    regirockb_properties.y += rebheight;
                    if (regirockb_properties.y >= regirockbheight)
                    {
                        regirockb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, regirockb_texture, &regirockb_properties, &regirockb_position);
            }
}
void animationRegirockp2()
{
        frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                regirock_properties.x += rewidth;
                if (regirock_properties.x >= regirockwidth)
                {
                    regirock_properties.x = 0;
                    regirock_properties.y += reheight;
                    if (regirock_properties.y >= regirockheight)
                    {
                        regirock_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, regirock_texture, &regirock_properties, &regirock_position);
                SDL_RenderPresent(renderer);
            }
}
void animationRhydonp1()
{
        frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                rhydonb_properties.x += rhbwidth;
                if (rhydonb_properties.x >= rhydonbwidth)
                {
                    rhydonb_properties.x = 0;
                    rhydonb_properties.y += rhbheight;
                    if (rhydonb_properties.y >= rhydonbheight)
                    {
                        rhydonb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, rhydonb_texture, &rhydonb_properties, &rhydonb_position);
            }
}
void animationRhydonp2()
{
            frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                rhydon_properties.x += rhwidth;
                if (rhydon_properties.x >= rhydonwidth)
                {
                    rhydon_properties.x = 0;
                    rhydon_properties.y += rhheight;
                    if (rhydon_properties.y >= rhydonheight)
                    {
                        rhydon_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, rhydon_texture, &rhydon_properties, &rhydon_position);
                SDL_RenderPresent(renderer);
            }
}
void animationSandslashp1()
{
            frametimea++;
            if(FPS/frametimea == 10)
            {
                frametimea = 0;
                sandslashb_properties.x += sbwidth;
                if (sandslashb_properties.x >= sandslashbwidth)
                {
                    sandslashb_properties.x = 0;
                    sandslashb_properties.y += sbheight;
                    if (sandslashb_properties.y >= sandslashbheight)
                    {
                        sandslashb_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, sandslashb_texture, &sandslashb_properties, &sandslashb_position);
            }
}
void animationSandslashp2()
{
            frametimeb++;
            if(FPS/frametimeb == 10)
            {
                frametimeb = 0;
                sandslash_properties.x += swidth;
                if (sandslash_properties.x >= sandslashwidth)
                {
                    sandslash_properties.x = 0;
                    sandslash_properties.y += sheight;
                    if (sandslash_properties.y >= sandslashheight)
                    {
                        sandslash_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, sandslash_texture, &sandslash_properties, &sandslash_position);
                SDL_RenderPresent(renderer);
            }
}

// Initialize Monster Encounters

void encounterMessages()
{
    buizelenc = IMG_Load("resource/monsters/monsEnc/buizelencounter.png");
    buizelenc_texture = SDL_CreateTextureFromSurface(renderer, buizelenc);
    bulbasaurenc = IMG_Load("resource/monsters/monsEnc/bulbasaurencounter.png");
    bulbasaurenc_texture = SDL_CreateTextureFromSurface(renderer, bulbasaurenc);
    celebienc = IMG_Load("resource/monsters/monsEnc/celebiencounter.png");
    celebienc_texture = SDL_CreateTextureFromSurface(renderer, celebienc);
    flareonenc = IMG_Load("resource/monsters/monsEnc/flareonencounter.png");
    flareonenc_texture = SDL_CreateTextureFromSurface(renderer, flareonenc);
    electrivireenc = IMG_Load("resource/monsters/monsEnc/electrivireencounter.png");
    electrivireenc_texture = SDL_CreateTextureFromSurface(renderer, electrivireenc);
    golemenc = IMG_Load("resource/monsters/monsEnc/golemencounter.png");
    golemenc_texture = SDL_CreateTextureFromSurface(renderer, golemenc);
    greninjaenc = IMG_Load("resource/monsters/monsEnc/greninjaencounter.png");
    greninjaenc_texture = SDL_CreateTextureFromSurface(renderer, greninjaenc);
    grovyleenc = IMG_Load("resource/monsters/monsEnc/grovyleencounter.png");
    grovyleenc_texture = SDL_CreateTextureFromSurface(renderer, grovyleenc);
    infernapeenc = IMG_Load("resource/monsters/monsEnc/infernapeencounter.png");
    infernapeenc_texture = SDL_CreateTextureFromSurface(renderer, infernapeenc);
    jolteonenc = IMG_Load("resource/monsters/monsEnc/jolteonencounter.png");
    jolteonenc_texture = SDL_CreateTextureFromSurface(renderer, jolteonenc);
    suicuneenc = IMG_Load("resource/monsters/monsEnc/suicuneencounter.png");
    suicuneenc_texture = SDL_CreateTextureFromSurface(renderer, suicuneenc);
    luxrayenc = IMG_Load("resource/monsters/monsEnc/luxrayencounter.png");
    luxrayenc_texture = SDL_CreateTextureFromSurface(renderer, luxrayenc);
    manectricenc = IMG_Load("resource/monsters/monsEnc/manectricencounter.png");
    manectricenc_texture = SDL_CreateTextureFromSurface(renderer, manectricenc);
    meganiumenc = IMG_Load("resource/monsters/monsEnc/meganiumencounter.png");
    meganiumenc_texture = SDL_CreateTextureFromSurface(renderer, meganiumenc);
    onixenc = IMG_Load("resource/monsters/monsEnc/onixencounter.png");
    onixenc_texture = SDL_CreateTextureFromSurface(renderer, onixenc);
    pikachuenc = IMG_Load("resource/monsters/monsEnc/pikachuencounter.png");
    pikachuenc_texture = SDL_CreateTextureFromSurface(renderer, pikachuenc);
    poliwrathenc = IMG_Load("resource/monsters/monsEnc/poliwrathencounter.png");
    poliwrathenc_texture = SDL_CreateTextureFromSurface(renderer, poliwrathenc);
    raikouenc = IMG_Load("resource/monsters/monsEnc/raikouencounter.png");
    raikouenc_texture = SDL_CreateTextureFromSurface(renderer, raikouenc);
    regirockenc = IMG_Load("resource/monsters/monsEnc/regirockencounter.png");
    regirockenc_texture = SDL_CreateTextureFromSurface(renderer, regirockenc);
    rhydonenc = IMG_Load("resource/monsters/monsEnc/rhydonencounter.png");
    rhydonenc_texture = SDL_CreateTextureFromSurface(renderer, rhydonenc);
    sandslashenc = IMG_Load("resource/monsters/monsEnc/sandslashencounter.png");
    sandslashenc_texture = SDL_CreateTextureFromSurface(renderer, sandslashenc);

    encountermessage_position.x = 0;
    encountermessage_position.y = 0;
    encountermessage_position.h = 600;
    encountermessage_position.w = 1000;
}
void shadowSprite()
{
    shadow = IMG_Load("resource/monsters/shadow.png");
    shadow_texture = SDL_CreateTextureFromSurface(renderer, shadow);

    shadow_position_mainmenu.x = 20;
    shadow_position_mainmenu.y = 360;
    shadow_position_mainmenu.h = 200;
    shadow_position_mainmenu.w = 300;

    p1_shadow_b_position.x = 230;
    p1_shadow_b_position.y = 330;
    p1_shadow_b_position.h = 200;
    p1_shadow_b_position.w = 300;

    p2_shadow_b_position.x = 570;
    p2_shadow_b_position.y = 150;
    p2_shadow_b_position.h = 200;
    p2_shadow_b_position.w = 300;

    shadow_monsgen_position.x = 345;
    shadow_monsgen_position.y = 170;
    shadow_monsgen_position.h = 200;
    shadow_monsgen_position.w = 300;
}
void Chansey()
{
    chansey = IMG_Load("resource/monsters/Sprite2.png");
    chansey_texture = SDL_CreateTextureFromSurface(renderer, chansey);
    SDL_QueryTexture(chansey_texture, NULL, NULL, &cwidth, &cheight);

    chanseywidth = cwidth / 10;
    chanseyheight = cheight / 1;

    chansey_properties.x = 0;
    chansey_properties.y = 0;
    chansey_properties.w = chanseywidth;
    chansey_properties.h = chanseyheight;

    chansey_position.x = 40;
    chansey_position.y = 350;
    chansey_position.w = 250;
    chansey_position.h = 192;

}
void Blaziken()
{
    blaziken = IMG_Load("Pokemon/Blaziken.png");
    blaziken_texture = SDL_CreateTextureFromSurface(renderer, blaziken);
    SDL_QueryTexture(blaziken_texture, NULL, NULL, &blazikenwidth, &blazikenheight);

    bwidth = blazikenwidth / 113 ;
    bheight = blazikenheight / 1 ;
    blaziken_properties.x = 0;
    blaziken_properties.y = 0;
    blaziken_properties.w = bwidth;
    blaziken_properties.h = bheight;

    blaziken_position.x = 590;
    blaziken_position.y = 120;
    blaziken_position.w = 260;
    blaziken_position.h = 240;
}
void Blazikenback()
{
    blazikenb = IMG_Load("Pokemon/Blazikenback.png");
    blazikenb_texture = SDL_CreateTextureFromSurface(renderer, blazikenb);
    SDL_QueryTexture(blazikenb_texture, NULL, NULL, &blazikenbwidth, &blazikenbheight);

    bbwidth = blazikenbwidth / 113 ;
    bbheight = blazikenbheight / 1 ;
    blazikenb_properties.x = 0;
    blazikenb_properties.y = 0;
    blazikenb_properties.w = bbwidth;
    blazikenb_properties.h = bbheight;

    blazikenb_position.x = 254;
    blazikenb_position.y = 320;
    blazikenb_position.w = 260;
    blazikenb_position.h = 240;
}
void Buizel()
{
    buizel = IMG_Load("Pokemon/Buizel.png");
    buizel_texture = SDL_CreateTextureFromSurface(renderer, buizel);
    SDL_QueryTexture(buizel_texture, NULL, NULL, &buizelwidth, &buizelheight);

    buwidth = buizelwidth / 49 ;
    buheight = buizelheight / 1 ;
    buizel_properties.x = 0;
    buizel_properties.y = 0;
    buizel_properties.w = buwidth;
    buizel_properties.h = buheight;

    buizel_position.x = 640;
    buizel_position.y = 90;
    buizel_position.w = 280;
    buizel_position.h = 240;

    buizelmid_position.h = 195;
    buizelmid_position.w = 180;
    buizelmid_position.x = 430;
    buizelmid_position.y = 160;
}
void Buizelback()
{
    buizelb = IMG_Load("Pokemon/Buizelback.png");
    buizelb_texture = SDL_CreateTextureFromSurface(renderer, buizelb);
    SDL_QueryTexture(buizelb_texture, NULL, NULL, &buizelbwidth, &buizelbheight);

    bubwidth = buizelbwidth / 49 ;
    bubheight = buizelbheight / 1 ;
    buizelb_properties.x = 0;
    buizelb_properties.y = 0;
    buizelb_properties.w = bubwidth;
    buizelb_properties.h = bubheight;

    buizelb_position.x = 140;
    buizelb_position.y = 270;
    buizelb_position.w = 300;
    buizelb_position.h = 240;
}
void Bulbasaur()
{
    bulbasaur = IMG_Load("Pokemon/Bulbasaur.png");
    bulbasaur_texture = SDL_CreateTextureFromSurface(renderer, bulbasaur);
    SDL_QueryTexture(bulbasaur_texture, NULL, NULL, &bulbasaurwidth, &bulbasaurheight);

    bulwidth = bulbasaurwidth / 41;
    bulheight = bulbasaurheight / 1 ;
    bulbasaur_properties.x = 0;
    bulbasaur_properties.y = 0;
    bulbasaur_properties.w = bulwidth;
    bulbasaur_properties.h = bulheight;

    bulbasaur_position.x = 610;
    bulbasaur_position.y = 150;
    bulbasaur_position.w = 190;
    bulbasaur_position.h = 180;

    bulbasaurmid_position.h = 180;
    bulbasaurmid_position.w = 195;
    bulbasaurmid_position.x = 400;
    bulbasaurmid_position.y = 170;
}
void Bulbasaurback()
{
    bulbasaurb = IMG_Load("Pokemon/Bulbasaurback.png");
    bulbasaurb_texture = SDL_CreateTextureFromSurface(renderer, bulbasaurb);
    SDL_QueryTexture(bulbasaurb_texture, NULL, NULL, &bulbasaurbwidth, &bulbasaurbheight);

    bulbwidth = bulbasaurbwidth / 45 ;
    bulbheight = bulbasaurbheight / 1 ;
    bulbasaurb_properties.x = 0;
    bulbasaurb_properties.y = 0;
    bulbasaurb_properties.w = bulbwidth;
    bulbasaurb_properties.h = bulbheight;

    bulbasaurb_position.x = 275;
    bulbasaurb_position.y = 335;
    bulbasaurb_position.w = 195;
    bulbasaurb_position.h = 180;
}
void Celebi()
{
    celebi = IMG_Load("Pokemon/Celebi.png");
    celebi_texture = SDL_CreateTextureFromSurface(renderer, celebi);
    SDL_QueryTexture(celebi_texture, NULL, NULL, &celebiwidth, &celebiheight);

    cwidth = celebiwidth / 75 ;
    cheight = celebiheight / 1 ;
    celebi_properties.x = 0;
    celebi_properties.y = 0;
    celebi_properties.w = cwidth;
    celebi_properties.h = cheight;

    celebi_position.x = 630;
    celebi_position.y = 90;
    celebi_position.w = 195;
    celebi_position.h = 180;

    celebimid_position.h = 180;
    celebimid_position.w = 195;
    celebimid_position.x = 380;
    celebimid_position.y = 120;
}
void Celebiback()
{
    celebib = IMG_Load("Pokemon/Celebiback.png");
    celebib_texture = SDL_CreateTextureFromSurface(renderer, celebib);
    SDL_QueryTexture(celebib_texture, NULL, NULL, &celebibwidth, &celebibheight);

    cbwidth = celebibwidth / 75 ;
    cbheight = celebibheight / 1 ;
    celebib_properties.x = 0;
    celebib_properties.y = 0;
    celebib_properties.w = cbwidth;
    celebib_properties.h = cbheight;

    celebib_position.x = 254;
    celebib_position.y = 240;
    celebib_position.w = 260;
    celebib_position.h = 240;
}
void Flareon()
{
    flareon = IMG_Load("Pokemon/Flareon.png");
    flareon_texture = SDL_CreateTextureFromSurface(renderer, flareon);
    SDL_QueryTexture(flareon_texture, NULL, NULL, &flareonwidth, &flareonheight);

    fwidth = flareonwidth / 29 ;
    fheight = flareonheight / 1 ;
    flareon_properties.x = 0;
    flareon_properties.y = 0;
    flareon_properties.w = fwidth;
    flareon_properties.h = fheight;

    flareon_position.x = 635;
    flareon_position.y = 120;
    flareon_position.w = 190;
    flareon_position.h = 210;

    flareonmid_position.h = 210;
    flareonmid_position.w = 225;
    flareonmid_position.x = 400;
    flareonmid_position.y = 140;
}
void Flareonback()
{
    flareonb = IMG_Load("Pokemon/Flareonback.png");
    flareonb_texture = SDL_CreateTextureFromSurface(renderer, flareonb);
    SDL_QueryTexture(flareonb_texture, NULL, NULL, &flareonbwidth, &flareonbheight);

    fbwidth = flareonbwidth / 33 ;
    fbheight = flareonbheight / 1 ;
    flareonb_properties.x = 0;
    flareonb_properties.y = 0;
    flareonb_properties.w = fbwidth;
    flareonb_properties.h = fbheight;

    flareonb_position.x = 245;
    flareonb_position.y = 270;
    flareonb_position.w = 260;
    flareonb_position.h = 240;
}
void Electrivire()
{
    electrivire = IMG_Load("Pokemon/Electrivire.png");
    electrivire_texture = SDL_CreateTextureFromSurface(renderer, electrivire);
    SDL_QueryTexture(electrivire_texture, NULL, NULL, &electrivirewidth, &electrivireheight);

    ewidth = electrivirewidth / 59 ;
    eheight = electrivireheight / 1 ;
    electrivire_properties.x = 0;
    electrivire_properties.y = 0;
    electrivire_properties.w = ewidth;
    electrivire_properties.h = eheight;

    electrivire_position.x = 600;
    electrivire_position.y = 95;
    electrivire_position.w = 260;
    electrivire_position.h = 240;

    electriviremid_position.h = 180;
    electriviremid_position.w = 195;
    electriviremid_position.x = 390;
    electriviremid_position.y = 175;
}
void Electrivireback()
{
    electrivireb = IMG_Load("Pokemon/Electrivireback.png");
    electrivireb_texture = SDL_CreateTextureFromSurface(renderer, electrivireb);
    SDL_QueryTexture(electrivireb_texture, NULL, NULL, &electrivirebwidth, &electrivirebheight);

    ebwidth = electrivirebwidth / 59 ;
    ebheight = electrivirebheight / 1 ;
    electrivireb_properties.x = 0;
    electrivireb_properties.y = 0;
    electrivireb_properties.w = ebwidth;
    electrivireb_properties.h = ebheight;

    electrivireb_position.x = 230;
    electrivireb_position.y = 275;
    electrivireb_position.w = 260;
    electrivireb_position.h = 240;
}
void Golem()
{
    golem = IMG_Load("Pokemon/Golem.png");
    golem_texture = SDL_CreateTextureFromSurface(renderer, golem);
    SDL_QueryTexture(golem_texture, NULL, NULL, &golemwidth, &golemheight);

    gwidth = golemwidth / 60 ;
    gheight = golemheight / 1 ;
    golem_properties.x = 0;
    golem_properties.y = 0;
    golem_properties.w = gwidth;
    golem_properties.h = gheight;

    golem_position.x = 575;
    golem_position.y = 100;
    golem_position.w = 260;
    golem_position.h = 240;

    golemmid_position.h = 180;
    golemmid_position.w = 195;
    golemmid_position.x = 380;
    golemmid_position.y = 170;
}
void Golemback()
{
    golemb = IMG_Load("Pokemon/Golemback.png");
    golemb_texture = SDL_CreateTextureFromSurface(renderer, golemb);
    SDL_QueryTexture(golemb_texture, NULL, NULL, &golembwidth, &golembheight);

    gbwidth = golembwidth / 63 ;
    gbheight = golembheight / 1 ;
    golemb_properties.x = 0;
    golemb_properties.y = 0;
    golemb_properties.w = gbwidth;
    golemb_properties.h = gbheight;

    golemb_position.x = 254;
    golemb_position.y = 280;
    golemb_position.w = 260;
    golemb_position.h = 240;
}
void Greninja()
{
    greninja = IMG_Load("Pokemon/Greninja.png");
    greninja_texture = SDL_CreateTextureFromSurface(renderer, greninja);
    SDL_QueryTexture(greninja_texture, NULL, NULL, &greninjawidth, &greninjaheight);

    grwidth = greninjawidth / 39 ;
    grheight = greninjaheight / 1 ;
    greninja_properties.x = 0;
    greninja_properties.y = 0;
    greninja_properties.w = grwidth;
    greninja_properties.h = grheight;

    greninja_position.x = 640;
    greninja_position.y = 150;
    greninja_position.w = 210;
    greninja_position.h = 180;

    greninjamid_position.h = 180;
    greninjamid_position.w = 195;
    greninjamid_position.x = 420;
    greninjamid_position.y = 175;
}
void Greninjaback()
{
    greninjab = IMG_Load("Pokemon/Greninjaback.png");
    greninjab_texture = SDL_CreateTextureFromSurface(renderer, greninjab);
    SDL_QueryTexture(greninjab_texture, NULL, NULL, &greninjabwidth, &greninjabheight);

    grbwidth = greninjabwidth / 41 ;
    grbheight = greninjabheight / 1 ;
    greninjab_properties.x = 0;
    greninjab_properties.y = 0;
    greninjab_properties.w = grbwidth;
    greninjab_properties.h = grbheight;

    greninjab_position.x = 215;
    greninjab_position.y = 279;
    greninjab_position.w = 280;
    greninjab_position.h = 240;
}
void Grovyle()
{
    grovyle = IMG_Load("Pokemon/Grovyle.png");
    grovyle_texture = SDL_CreateTextureFromSurface(renderer, grovyle);
    SDL_QueryTexture(grovyle_texture, NULL, NULL, &grovylewidth, &grovyleheight);

    grovwidth = grovylewidth / 49 ;
    grovheight = grovyleheight / 1 ;
    grovyle_properties.x = 0;
    grovyle_properties.y = 0;
    grovyle_properties.w = grovwidth;
    grovyle_properties.h = grovheight;

    grovyle_position.x = 590;
    grovyle_position.y = 100;
    grovyle_position.w = 260;
    grovyle_position.h = 240;

    grovylemid_position.h = 180;
    grovylemid_position.w = 195;
    grovylemid_position.x = 390;
    grovylemid_position.y = 175;
}
void Grovyleback()
{
    grovyleb = IMG_Load("Pokemon/Grovyleback.png");
    grovyleb_texture = SDL_CreateTextureFromSurface(renderer, grovyleb);
    SDL_QueryTexture(grovyleb_texture, NULL, NULL, &grovylebwidth, &grovylebheight);

    grovbwidth = grovylebwidth / 49 ;
    grovbheight = grovylebheight / 1 ;
    grovyleb_properties.x = 0;
    grovyleb_properties.y = 0;
    grovyleb_properties.w = grovbwidth;
    grovyleb_properties.h = grovbheight;

    grovyleb_position.x = 235;
    grovyleb_position.y = 280;
    grovyleb_position.w = 260;
    grovyleb_position.h = 240;
}
void Infernape()
{
    infernape = IMG_Load("Pokemon/Infernape.png");
    infernape_texture = SDL_CreateTextureFromSurface(renderer, infernape);
    SDL_QueryTexture(infernape_texture, NULL, NULL, &infernapewidth, &infernapeheight);

    iwidth = infernapewidth / 39 ;
    iheight = infernapeheight / 1 ;
    infernape_properties.x = 0;
    infernape_properties.y = 0;
    infernape_properties.w = iwidth;
    infernape_properties.h = iheight;

    infernape_position.x = 600;
    infernape_position.y = 100;
    infernape_position.w = 260;
    infernape_position.h = 240;

    infernapemid_position.h = 180;
    infernapemid_position.w = 195;
    infernapemid_position.x = 400;
    infernapemid_position.y = 177;
}
void Infernapeback()
{
    infernapeb = IMG_Load("Pokemon/Infernapeback.png");
    infernapeb_texture = SDL_CreateTextureFromSurface(renderer, infernapeb);
    SDL_QueryTexture(infernapeb_texture, NULL, NULL, &infernapebwidth, &infernapebheight);

    ibwidth = infernapebwidth / 39 ;
    ibheight = infernapebheight / 1 ;
    infernapeb_properties.x = 0;
    infernapeb_properties.y = 0;
    infernapeb_properties.w = ibwidth;
    infernapeb_properties.h = ibheight;

    infernapeb_position.x = 210;
    infernapeb_position.y = 282;
    infernapeb_position.w = 260;
    infernapeb_position.h = 240;
}
void Jolteon()
{
    jolteon = IMG_Load("Pokemon/Jolteon.png");
    jolteon_texture = SDL_CreateTextureFromSurface(renderer, jolteon);
    SDL_QueryTexture(jolteon_texture, NULL, NULL, &jolteonwidth, &jolteonheight);

    jwidth = jolteonwidth / 40 ;
    jheight = jolteonheight / 1 ;
    jolteon_properties.x = 0;
    jolteon_properties.y = 0;
    jolteon_properties.w = jwidth;
    jolteon_properties.h = jheight;

    jolteon_position.x = 650;
    jolteon_position.y = 160;
    jolteon_position.w = 155;
    jolteon_position.h = 180;

    jolteonmid_position.h = 180;
    jolteonmid_position.w = 195;
    jolteonmid_position.x = 400;
    jolteonmid_position.y = 177;
}
void Jolteonback()
{
    jolteonb = IMG_Load("Pokemon/Jolteonback.png");
    jolteonb_texture = SDL_CreateTextureFromSurface(renderer, jolteonb);
    SDL_QueryTexture(jolteonb_texture, NULL, NULL, &jolteonbwidth, &jolteonbheight);

    jbwidth = jolteonbwidth / 39 ;
    jbheight = jolteonbheight / 1 ;
    jolteonb_properties.x = 0;
    jolteonb_properties.y = 0;
    jolteonb_properties.w = jbwidth;
    jolteonb_properties.h = jbheight;

    jolteonb_position.x = 245;
    jolteonb_position.y = 280;
    jolteonb_position.w = 260;
    jolteonb_position.h = 240;
}
void Suicune()
{
    suicune = IMG_Load("Pokemon/Suicune.png");
    suicune_texture = SDL_CreateTextureFromSurface(renderer, suicune);
    SDL_QueryTexture(suicune_texture, NULL, NULL, &suicunewidth, &suicuneheight);

    suwidth = suicunewidth / 60;
    suheight = suicuneheight / 1 ;
    suicune_properties.x = 0;
    suicune_properties.y = 0;
    suicune_properties.w = suwidth;
    suicune_properties.h = suheight;

    suicune_position.x = 565;
    suicune_position.y = 100;
    suicune_position.w = 270;
    suicune_position.h = 240;

    suicunemid_position.h = 180;
    suicunemid_position.w = 285;
    suicunemid_position.x = 330;
    suicunemid_position.y = 175;
}
void Suicuneback()
{
    suicuneb = IMG_Load("Pokemon/Suicuneback.png");
    suicuneb_texture = SDL_CreateTextureFromSurface(renderer, suicuneb);
    SDL_QueryTexture(suicuneb_texture, NULL, NULL, &suicunebwidth, &suicunebheight);

    subwidth = suicunebwidth / 59 ;
    subheight = suicunebheight / 1 ;
    suicuneb_properties.x = 0;
    suicuneb_properties.y = 0;
    suicuneb_properties.w = subwidth;
    suicuneb_properties.h = subheight;

    suicuneb_position.x = 240;
    suicuneb_position.y = 270;
    suicuneb_position.w = 260;
    suicuneb_position.h = 240;
}
void Luxray()
{
    luxray = IMG_Load("Pokemon/Luxray.png");
    luxray_texture = SDL_CreateTextureFromSurface(renderer, luxray);
    SDL_QueryTexture(luxray_texture, NULL, NULL, &luxraywidth, &luxrayheight);

    lwidth = luxraywidth / 59 ;
    lheight = luxrayheight / 1 ;
    luxray_properties.x = 0;
    luxray_properties.y = 0;
    luxray_properties.w = lwidth;
    luxray_properties.h = lheight;

    luxray_position.x = 620;
    luxray_position.y = 160;
    luxray_position.w = 190;
    luxray_position.h = 180;

    luxraymid_position.h = 180;
    luxraymid_position.w = 195;
    luxraymid_position.x = 390;
    luxraymid_position.y = 175;
}
void Luxrayback()
{
    luxrayb = IMG_Load("Pokemon/Luxrayback.png");
    luxrayb_texture = SDL_CreateTextureFromSurface(renderer, luxrayb);
    SDL_QueryTexture(luxrayb_texture, NULL, NULL, &luxraybwidth, &luxraybheight);

    lbwidth = luxraybwidth / 63 ;
    lbheight = luxraybheight / 1 ;
    luxrayb_properties.x = 0;
    luxrayb_properties.y = 0;
    luxrayb_properties.w = lbwidth;
    luxrayb_properties.h = lbheight;

    luxrayb_position.x = 230;
    luxrayb_position.y = 280;
    luxrayb_position.w = 260;
    luxrayb_position.h = 240;
}
void Manectric()
{
    manectric = IMG_Load("Pokemon/Manectric.png");
    manectric_texture = SDL_CreateTextureFromSurface(renderer, manectric);
    SDL_QueryTexture(manectric_texture, NULL, NULL, &manectricwidth, &manectricheight);

    mawidth = manectricwidth / 49 ;
    maheight = manectricheight / 1 ;
    manectric_properties.x = 0;
    manectric_properties.y = 0;
    manectric_properties.w = mawidth;
    manectric_properties.h = maheight;

    manectric_position.x = 620;
    manectric_position.y = 156;
    manectric_position.w = 195;
    manectric_position.h = 180;

    manectricmid_position.h = 180;
    manectricmid_position.w = 195;
    manectricmid_position.x = 390;
    manectricmid_position.y = 175;
}
void Manectricback()
{
    manectricb = IMG_Load("Pokemon/Manectricback.png");
    manectricb_texture = SDL_CreateTextureFromSurface(renderer, manectricb);
    SDL_QueryTexture(manectricb_texture, NULL, NULL, &manectricbwidth, &manectricbheight);

    mabwidth = manectricbwidth / 53 ;
    mabheight = manectricbheight / 1 ;
    manectricb_properties.x = 0;
    manectricb_properties.y = 0;
    manectricb_properties.w = mabwidth;
    manectricb_properties.h = mabheight;

    manectricb_position.x = 253;
    manectricb_position.y = 275;
    manectricb_position.w = 260;
    manectricb_position.h = 240;
}
void Meganium()
{
    meganium = IMG_Load("Pokemon/Meganium.png");
    meganium_texture = SDL_CreateTextureFromSurface(renderer, meganium);
    SDL_QueryTexture(meganium_texture, NULL, NULL, &meganiumwidth, &meganiumheight);

    mewidth = meganiumwidth / 59 ;
    meheight = meganiumheight / 1 ;
    meganium_properties.x = 0;
    meganium_properties.y = 0;
    meganium_properties.w = mewidth;
    meganium_properties.h = meheight;

    meganium_position.x = 600;
    meganium_position.y = 155;
    meganium_position.w = 195;
    meganium_position.h = 180;

    meganiummid_position.h = 230;
    meganiummid_position.w = 200;
    meganiummid_position.x = 380;
    meganiummid_position.y = 125;
}
void Meganiumback()
{
    meganiumb = IMG_Load("Pokemon/Meganiumback.png");
    meganiumb_texture = SDL_CreateTextureFromSurface(renderer, meganiumb);
    SDL_QueryTexture(meganiumb_texture, NULL, NULL, &meganiumbwidth, &meganiumbheight);

    mebwidth = meganiumbwidth / 59 ;
    mebheight = meganiumbheight / 1 ;
    meganiumb_properties.x = 0;
    meganiumb_properties.y = 0;
    meganiumb_properties.w = mebwidth;
    meganiumb_properties.h = mebheight;

    meganiumb_position.x = 254;
    meganiumb_position.y = 275;
    meganiumb_position.w = 260;
    meganiumb_position.h = 240;
}
void Onix()
{
    onix = IMG_Load("Pokemon/Onix.png");
    onix_texture = SDL_CreateTextureFromSurface(renderer, onix);
    SDL_QueryTexture(onix_texture, NULL, NULL, &onixwidth, &onixheight);

    owidth = onixwidth / 61 ;
    oheight = onixheight / 1 ;
    onix_properties.x = 0;
    onix_properties.y = 0;
    onix_properties.w = owidth;
    onix_properties.h = oheight;

    onix_position.x = 585;
    onix_position.y = 100;
    onix_position.w = 260;
    onix_position.h = 240;

    onixmid_position.h = 210;
    onixmid_position.w = 235;
    onixmid_position.x = 375;
    onixmid_position.y = 145;
}
void Onixback()
{
    onixb = IMG_Load("Pokemon/Onixback.png");
    onixb_texture = SDL_CreateTextureFromSurface(renderer, onixb);
    SDL_QueryTexture(onixb_texture, NULL, NULL, &onixbwidth, &onixbheight);

    obwidth = onixbwidth / 64 ;
    obheight = onixbheight / 1 ;
    onixb_properties.x = 0;
    onixb_properties.y = 0;
    onixb_properties.w = obwidth;
    onixb_properties.h = obheight;

    onixb_position.x = 257;
    onixb_position.y = 226;
    onixb_position.w = 325;
    onixb_position.h = 300;
}
void Pikachu()
{
    pikachu = IMG_Load("Pokemon/Pikachu.png");
    pikachu_texture = SDL_CreateTextureFromSurface(renderer, pikachu);
    SDL_QueryTexture(pikachu_texture, NULL, NULL, &pikachuwidth, &pikachuheight);

    pwidth = pikachuwidth / 33 ;
    pheight = pikachuheight / 1 ;
    pikachu_properties.x = 0;
    pikachu_properties.y = 0;
    pikachu_properties.w = pwidth;
    pikachu_properties.h = pheight;

    pikachu_position.x = 655;
    pikachu_position.y = 156;
    pikachu_position.w = 195;
    pikachu_position.h = 180;

    pikachumid_position.h = 175;
    pikachumid_position.w = 210;
    pikachumid_position.x = 420;
    pikachumid_position.y = 180;
}
void Pikachuback()
{
    pikachub = IMG_Load("Pokemon/Pikachuback.png");
    pikachub_texture = SDL_CreateTextureFromSurface(renderer, pikachub);
    SDL_QueryTexture(pikachub_texture, NULL, NULL, &pikachubwidth, &pikachubheight);

    pbwidth = pikachubwidth / 33 ;
    pbheight = pikachubheight / 1 ;
    pikachub_properties.x = 0;
    pikachub_properties.y = 0;
    pikachub_properties.w = pbwidth;
    pikachub_properties.h = pbheight;

    pikachub_position.x = 205;
    pikachub_position.y = 275;
    pikachub_position.w = 260;
    pikachub_position.h = 240;
}
void Poliwrath()
{
    poliwrath = IMG_Load("Pokemon/Poliwrath.png");
    poliwrath_texture = SDL_CreateTextureFromSurface(renderer, poliwrath);
    SDL_QueryTexture(poliwrath_texture, NULL, NULL, &poliwrathwidth, &poliwrathheight);

    powidth = poliwrathwidth / 37 ;
    poheight = poliwrathheight / 1 ;
    poliwrath_properties.x = 0;
    poliwrath_properties.y = 0;
    poliwrath_properties.w = powidth;
    poliwrath_properties.h = poheight;

    poliwrath_position.x = 600;
    poliwrath_position.y = 155;
    poliwrath_position.w = 195;
    poliwrath_position.h = 180;

    poliwrathmid_position.h = 180;
    poliwrathmid_position.w = 195;
    poliwrathmid_position.x = 380;
    poliwrathmid_position.y = 175;
}
void Poliwrathback()
{
    poliwrathb = IMG_Load("Pokemon/Poliwrathback.png");
    poliwrathb_texture = SDL_CreateTextureFromSurface(renderer, poliwrathb);
    SDL_QueryTexture(poliwrathb_texture, NULL, NULL, &poliwrathbwidth, &poliwrathbheight);

    pobwidth = poliwrathbwidth / 40 ;
    pobheight = poliwrathbheight / 1 ;
    poliwrathb_properties.x = 0;
    poliwrathb_properties.y = 0;
    poliwrathb_properties.w = pobwidth;
    poliwrathb_properties.h = pobheight;

    poliwrathb_position.x = 267;
    poliwrathb_position.y = 277;
    poliwrathb_position.w = 260;
    poliwrathb_position.h = 240;
}
void Raikou()
{
    raikou = IMG_Load("Pokemon/Raikou.png");
    raikou_texture = SDL_CreateTextureFromSurface(renderer, raikou);
    SDL_QueryTexture(raikou_texture, NULL, NULL, &raikouwidth, &raikouheight);

    rwidth = raikouwidth / 60 ;
    rheight = raikouheight / 1 ;
    raikou_properties.x = 0;
    raikou_properties.y = 0;
    raikou_properties.w = rwidth;
    raikou_properties.h = rheight;

    raikou_position.x = 610;
    raikou_position.y = 160;
    raikou_position.w = 195;
    raikou_position.h = 180;

    raikoumid_position.h = 180;
    raikoumid_position.w = 195;
    raikoumid_position.x = 385;
    raikoumid_position.y = 178;
}
void Raikouback()
{
    raikoub = IMG_Load("Pokemon/Raikouback.png");
    raikoub_texture = SDL_CreateTextureFromSurface(renderer, raikoub);
    SDL_QueryTexture(raikoub_texture, NULL, NULL, &raikoubwidth, &raikoubheight);

    rbwidth = raikoubwidth / 59 ;
    rbheight = raikoubheight / 1 ;
    raikoub_properties.x = 0;
    raikoub_properties.y = 0;
    raikoub_properties.w = rbwidth;
    raikoub_properties.h = rbheight;

    raikoub_position.x = 243;
    raikoub_position.y = 270;
    raikoub_position.w = 260;
    raikoub_position.h = 255;
}
void Regirock()
{
    regirock = IMG_Load("Pokemon/Regirock.png");
    regirock_texture = SDL_CreateTextureFromSurface(renderer, regirock);
    SDL_QueryTexture(regirock_texture, NULL, NULL, &regirockwidth, &regirockheight);

    rewidth = regirockwidth / 69 ;
    reheight = regirockheight / 1 ;
    regirock_properties.x = 0;
    regirock_properties.y = 0;
    regirock_properties.w = rewidth;
    regirock_properties.h = reheight;

    regirock_position.x = 590;
    regirock_position.y = 98;
    regirock_position.w = 260;
    regirock_position.h = 240;

    regirockmid_position.h = 195;
    regirockmid_position.w = 210;
    regirockmid_position.x = 380;
    regirockmid_position.y = 160;
}
void Regirockback()
{
    regirockb = IMG_Load("Pokemon/Regirockback.png");
    regirockb_texture = SDL_CreateTextureFromSurface(renderer, regirockb);
    SDL_QueryTexture(regirockb_texture, NULL, NULL, &regirockbwidth, &regirockbheight);

    rebwidth = regirockbwidth / 69 ;
    rebheight = regirockbheight / 1 ;
    regirockb_properties.x = 0;
    regirockb_properties.y = 0;
    regirockb_properties.w = rebwidth;
    regirockb_properties.h = rebheight;

    regirockb_position.x = 254;
    regirockb_position.y = 280;
    regirockb_position.w = 260;
    regirockb_position.h = 240;
}
void Rhydon()
{
    rhydon = IMG_Load("Pokemon/Rhydon.png");
    rhydon_texture = SDL_CreateTextureFromSurface(renderer, rhydon);
    SDL_QueryTexture(rhydon_texture, NULL, NULL, &rhydonwidth, &rhydonheight);

    rhwidth = rhydonwidth / 47 ;
    rhheight = rhydonheight / 1 ;
    rhydon_properties.x = 0;
    rhydon_properties.y = 0;
    rhydon_properties.w = rhwidth;
    rhydon_properties.h = rhheight;

    rhydon_position.x = 590;
    rhydon_position.y = 100;
    rhydon_position.w = 260;
    rhydon_position.h = 240;

    rhydonmid_position.h = 195;
    rhydonmid_position.w = 210;
    rhydonmid_position.x = 385;
    rhydonmid_position.y = 160;
}
void Rhydonback()
{
    rhydonb = IMG_Load("Pokemon/Rhydonback.png");
    rhydonb_texture = SDL_CreateTextureFromSurface(renderer, rhydonb);
    SDL_QueryTexture(rhydonb_texture, NULL, NULL, &rhydonbwidth, &rhydonbheight);

    rhbwidth = rhydonbwidth / 50 ;
    rhbheight = rhydonbheight / 1 ;
    rhydonb_properties.x = 0;
    rhydonb_properties.y = 0;
    rhydonb_properties.w = rhbwidth;
    rhydonb_properties.h = rhbheight;

    rhydonb_position.x = 243;
    rhydonb_position.y = 282;
    rhydonb_position.w = 260;
    rhydonb_position.h = 240;
}
void Sandslash()
{
    sandslash = IMG_Load("Pokemon/Sandslash.png");
    sandslash_texture = SDL_CreateTextureFromSurface(renderer, sandslash);
    SDL_QueryTexture(sandslash_texture, NULL, NULL, &sandslashwidth, &sandslashheight);

    swidth = sandslashwidth / 48 ;
    sheight = sandslashheight / 1 ;
    sandslash_properties.x = 0;
    sandslash_properties.y = 0;
    sandslash_properties.w = swidth;
    sandslash_properties.h = sheight;

    sandslash_position.x = 620;
    sandslash_position.y = 154;
    sandslash_position.w = 195;
    sandslash_position.h = 180;

    sandslashmid_position.h = 180;
    sandslashmid_position.w = 195;
    sandslashmid_position.x = 400;
    sandslashmid_position.y = 175;
}
void Sandslashback()
{
    sandslashb = IMG_Load("Pokemon/Sandslashback.png");
    sandslashb_texture = SDL_CreateTextureFromSurface(renderer, sandslashb);
    SDL_QueryTexture(sandslashb_texture, NULL, NULL, &sandslashbwidth, &sandslashbheight);

    sbwidth = sandslashbwidth / 51 ;
    sbheight = sandslashbheight / 1 ;
    sandslashb_properties.x = 0;
    sandslashb_properties.y = 0;
    sandslashb_properties.w = sbwidth;
    sandslashb_properties.h = sbheight;

    sandslashb_position.x = 254;
    sandslashb_position.y = 280;
    sandslashb_position.w = 260;
    sandslashb_position.h = 240;
}

// Declare Event Resources

void initGameResources()
{
    window = SDL_CreateWindow("Universal Serial Monsters v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          width, height, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    music = Mix_LoadMUS("resource/sound/bg/Gamestart.mp3");
    music_1 = Mix_LoadMUS("resource/sound/bg/Littleroot.mp3");
    music_2 = Mix_LoadMUS("resource/sound/bg/Gamemenu.mp3");
    music_2_bg = Mix_LoadWAV("resource/sound/bg/Littleroot.wav");
    music_3 = Mix_LoadMUS("resource/sound/bg/RandomEncounter.mp3");
    select_1 = Mix_LoadWAV("resource/sound/sfx/Select.wav");
    select_2 = Mix_LoadWAV("resource/sound/sfx/Gamestart.wav");

}
void initLoadScreenResource()
{
    loadingText = IMG_Load("resource/loadingasset/load1.png");
    loadingText_texture = SDL_CreateTextureFromSurface(renderer, loadingText);
    loadingText2 = IMG_Load("resource/loadingasset/load2.png");
    loadingText2_texture = SDL_CreateTextureFromSurface(renderer, loadingText2);
    loadingText3 = IMG_Load("resource/loadingasset/load3.png");
    loadingText3_texture = SDL_CreateTextureFromSurface(renderer, loadingText3);

    loadingtext_position.x = 20;
    loadingtext_position.y = 500;
    loadingtext_position.h = 100;
    loadingtext_position.w = 300;
}
void initPreMenuResource()
{
    background = IMG_Load("resource/mainmenu/Background.png");
    background_texture = SDL_CreateTextureFromSurface(renderer, background);
    titleScreen1 = IMG_Load("resource/mainmenu/USM.png");
    titleScreen1_texture = SDL_CreateTextureFromSurface(renderer, titleScreen1);
    titleScreen2 = IMG_Load("resource/mainmenu/USM2.png");
    titleScreen2_texture = SDL_CreateTextureFromSurface(renderer, titleScreen2);
    pressAny = IMG_Load("resource/mainmenu/Start.png");
    pressAny_texture = SDL_CreateTextureFromSurface(renderer, pressAny);
    mainTitle = IMG_Load("resource/mainmenu/mm.png");
    mainTitle_texture = SDL_CreateTextureFromSurface(renderer, mainTitle);

    background_position.x = 0;
    background_position.y = 0;
    background_position.h = 600;
    background_position.w = 1000;

    titlescreen_position.x = 150;
    titlescreen_position.y = 50;
    titlescreen_position.h = 400;
    titlescreen_position.w = 700;

    pressany_position.x = 320;
    pressany_position.y = 450;
    pressany_position.h = 200;
    pressany_position.w = 350;

    mainTitle_position.x = 20;
    mainTitle_position.y = 10;
    mainTitle_position.h = 200;
    mainTitle_position.w = 350;
}
void initMainMenuResource()
{
    choices = IMG_Load("resource/mainmenu/mainmenu.png");
    choices_texture = SDL_CreateTextureFromSurface(renderer, choices);
    select = IMG_Load("resource/mainmenu/select.png");
    select_texture = SDL_CreateTextureFromSurface(renderer, select);
    gameChoice = IMG_Load("resource/mainmenu/gamechoice.png");
    gameChoice_texture = SDL_CreateTextureFromSurface(renderer, gameChoice);
    singleCursor = IMG_Load("resource/mainmenu/singlecursor.png");
    singleCursor_texture = SDL_CreateTextureFromSurface(renderer, singleCursor);
    gameDecide = IMG_Load("resource/mainmenu/registerback.png");
    gameDecide_texture = SDL_CreateTextureFromSurface(renderer, gameDecide);
    controls = IMG_Load("resource/mainmenu/Controls.png");
    controls_texture = SDL_CreateTextureFromSurface(renderer, controls);
    credit = IMG_Load("resource/mainmenu/Credits.png");
    credit_texture = SDL_CreateTextureFromSurface(renderer, credit);
    player1w = IMG_Load("resource/mainmenu/p1win.png");
    player1w_texture = SDL_CreateTextureFromSurface(renderer, player1w);
    player2w = IMG_Load("resource/mainmenu/p2win.png");
    player2w_texture = SDL_CreateTextureFromSurface(renderer, player2w);

    choices_position.x = 400;
    choices_position.y = 152;
    choices_position.h = 350;
    choices_position.w = 600;

    select_position.h = 560;
    select_position.w = 550;

    gameChoice_position.x = 200;
    gameChoice_position.y = 180;
    gameChoice_position.h = 250;
    gameChoice_position.w = 600;

    singleCursor_position.h = 76;
    singleCursor_position.w = 72;

    gameDecide_position.x = 0;
    gameDecide_position.y = 0;
    gameDecide_position.h = 600;
    gameDecide_position.w = 1000;

    cursorDecide_position.h = 57;
    cursorDecide_position.w = 54;

    controls_position.x = 0;
    controls_position.y = 0;
    controls_position.h = 600;
    controls_position.w = 1000;

    credit_position.x = 0;
    credit_position.y = 0;
    credit_position.h = 600;
    credit_position.w = 1000;

    player1w_position.x = 0;
    player1w_position.y = 0;
    player1w_position.h = 600;
    player1w_position.w = 1000;

    player2w_position.x = 0;
    player2w_position.y = 0;
    player2w_position.h = 600;
    player2w_position.w = 1000;
}
void initGuestPlayResource()
{
    demoPlat = IMG_Load("resource/battle/battleplat.png");
    demoPlat_texture = SDL_CreateTextureFromSurface(renderer, demoPlat);
    demoBack = IMG_Load("resource/battle/battleback.jpg");
    demoBack_texture = SDL_CreateTextureFromSurface(renderer, demoBack);

    demoPlat_position.x = 0;
    demoPlat_position.y = 0;
    demoPlat_position.h = 600;
    demoPlat_position.w = 1000;

    demoBack_position.x = 0;
    demoBack_position.y = 0;
    demoBack_position.h = 600;
    demoBack_position.w = 1000;
}
void initGenerateResource()
{
    generatePlat = IMG_Load("resource/mainmenu/randompick.png");
    generatePlat_texture = SDL_CreateTextureFromSurface(renderer, generatePlat);
    cursorGenerator = IMG_Load("resource/mainmenu/singlecursor2.png");
    cursorGenerator_texture = SDL_CreateTextureFromSurface(renderer, cursorGenerator);
    restart = IMG_Load("resource/mainmenu/success.png");
    restart_texture = SDL_CreateTextureFromSurface(renderer, restart);


    cursorGenerator_position.h = 38;
    cursorGenerator_position.w = 34;

    generatePlat_position.x = 0;
    generatePlat_position.y = 0;
    generatePlat_position.h = 600;
    generatePlat_position.w = 1000;

    restart_position.x = 0;
    restart_position.y = 0;
    restart_position.h = 600;
    restart_position.w = 1000;
}
void destroyGenerateResource()
{
    SDL_DestroyTexture(buizel_texture);
    SDL_DestroyTexture(bulbasaur_texture);
    SDL_DestroyTexture(celebi_texture);
    SDL_DestroyTexture(flareon_texture);
    SDL_DestroyTexture(electrivire_texture);
    SDL_DestroyTexture(golem_texture);
    SDL_DestroyTexture(greninja_texture);
    SDL_DestroyTexture(grovyle_texture);
    SDL_DestroyTexture(infernape_texture);
    SDL_DestroyTexture(jolteon_texture);
    SDL_DestroyTexture(suicune_texture);
    SDL_DestroyTexture(luxray_texture);
    SDL_DestroyTexture(manectric_texture);
    SDL_DestroyTexture(meganium_texture);
    SDL_DestroyTexture(onix_texture);
    SDL_DestroyTexture(pikachu_texture);
    SDL_DestroyTexture(poliwrath_texture);
    SDL_DestroyTexture(raikou_texture);
    SDL_DestroyTexture(regirock_texture);
    SDL_DestroyTexture(rhydon_texture);
    SDL_DestroyTexture(sandslash_texture);
}

// Declare Event Functions
void readFlashDrive()
{
    scanUSM1 = fopen("E:/usmdetect.dbf", "w");
    scanUSM2 = fopen("F:/usmdetect.dbf", "w");
    scanUSM3 = fopen("G:/usmdetect.dbf", "w");

    fclose(scanUSM1);
    fclose(scanUSM2);
    fclose(scanUSM3);

    scanUSM1 = fopen("E:/usmdetect.dbf", "r");
    scanUSM2 = fopen("F:/usmdetect.dbf", "r");
    scanUSM3 = fopen("G:/usmdetect.dbf", "r");

    fclose(scanUSM1);
    fclose(scanUSM2);
    fclose(scanUSM3);

    printf("Flashdrive Pre-scan:");
    if (scanUSM1 == NULL)
        {
            printf("\nE: No flashdrive found.");
            driveE = false;
        }
        if (scanUSM1 != NULL)
        {
            printf("\nE: Flashdrive found.");
            driveE = true;
            if (user1 == 0)
                user1 = 1;
            else if (user1 != 0)
                user2 = 1;
        }
        if (scanUSM2 == NULL)
        {
            printf("\nF: No flashdrive found.");
            driveF = false;
        }
        if (scanUSM2 != NULL)
        {
            printf("\nF: Flashdrive found.");
            driveF = true;
                if (user1 == 0)
                user1 = 1;
                else if (user1 != 0)
                user2 = 1;
        }
        if (scanUSM3 == NULL)
        {
            printf("\nG: No flashdrive found.");
            driveG = false;
        }
        if (scanUSM3 != NULL)
        {
            printf("\nG: Flashdrive found.");
            driveG = true;
            if (user1 == 0)
                user1 = 1;
            else if (user1 != 0)
                user2 = 1;
        }

        if (user1 == 1)
            printf("\nUser 1: Available");
        else
            printf("\nUser 1: Unavailable");
        if (user2 == 1)
            printf("\nUser 2: Available");
        else
            printf("\nUser 2: Unavailable");

                if (UserRegistered1 == 1)
        printf("\nPlayer 1 is registered.");
    else
        printf("\nPlayer 1 is unregistered.");
    if (UserRegistered2 == 1)
        printf("\nPlayer 2 is registered.");
    else
        printf("\nPlayer 2 is unregistered.");

            loadingScreen = true;

}
void readUser()
{
    scanUserUSM1 = fopen("E:/usmpokemon.dbf", "r");
    scanUserUSM2 = fopen("F:/usmpokemon.dbf", "r");
    scanUserUSM3 = fopen("G:/usmpokemon.dbf", "r");

    if (scanUserUSM1 != NULL)
    {
            if (UserRegistered1 == 0)
                UserRegistered1 = 1;
            else if (UserRegistered1 != 0)
                UserRegistered2 = 1;
    }
    if (scanUserUSM2 != NULL)
    {
            if (UserRegistered1 == 0)
                UserRegistered1 = 1;
            else if (UserRegistered1 != 0)
                UserRegistered2 = 1;
    }
    if (scanUserUSM3 != NULL)
    {
        if (UserRegistered1 == 0)
                UserRegistered1 = 1;
            else if (UserRegistered1 != 0)
                UserRegistered2 = 1;
    }


}
void initloadScreen()
{
    while (loadingScreen)
    {
        while(SDL_PollEvent(&load) != 0)
        {
            if(load.type == SDL_QUIT)
            {
                loadingScreen = false;
            }
        }

        // Looping
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loadingText_texture, NULL, &loadingtext_position);
        delay(250);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loadingText2_texture, NULL, &loadingtext_position);
        delay(250);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loadingText3_texture, NULL, &loadingtext_position);
        delay(250);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loadingText_texture, NULL, &loadingtext_position);
        delay(250);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loadingText2_texture, NULL, &loadingtext_position);
        delay(250);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loadingText3_texture, NULL, &loadingtext_position);
        delay(250);
        SDL_RenderPresent(renderer);
        loadingScreen = false;
        premenu = true;
    }
}
void initPreMenu()
{
    Mix_PlayMusic(music_1, -1);
    while (premenu)
    {
        while(SDL_PollEvent(&premenuscreen) != 0)
        {
            // Looping
            if (premenuscreen.type == SDL_QUIT)
            {
                premenu = false;
                    mainGame = false;
            }
            if (premenuscreen.type == SDL_KEYDOWN)
            {
                    premenu = false;
                    Mix_PlayMusic(music,0);
            }
        }
        // Background Process
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background_texture, NULL, &background_position);
        SDL_RenderCopy(renderer, titleScreen2_texture, NULL, &titlescreen_position);
        SDL_RenderCopy(renderer, pressAny_texture, NULL, &pressany_position);
        SDL_RenderPresent(renderer);
        SDL_Delay(400);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background_texture, NULL, &background_position);
        SDL_RenderCopy(renderer, titleScreen2_texture, NULL, &titlescreen_position);
        SDL_RenderPresent(renderer);
        SDL_Delay(400);
    }
    Mix_PlayMusic(music_1, 0);
}
void initMainmenu()
{
    frametime = 0;
    frametimea = 0;
    frametimeb = 0;
    avoidLag = 0;
    singleCursor_position.x = 145;
    singleCursor_position.y = 180;
    select_position.x = 430;
    select_position.y = 95;
    int choice = 1;
    printf("\n\nMain Menu Log:");
    Chansey();
    shadowSprite();
    menu = true;
    while(menu)
    {
        while(SDL_PollEvent(&mainmenu) != 0)
        {
            if(mainmenu.type == SDL_QUIT)
            {
                menu = false;
                mainGame = false;
            }
            if(mainmenu.type == SDL_KEYDOWN)
            {
                switch(mainmenu.key.keysym.sym)
                {
                case SDLK_UP:
                    if (choice > 1)
                    {
                        Mix_PlayChannel(-1, select_1, 0);
                        select_position.y -= 85;
                        choice--;
                    }
                    break;
                case SDLK_DOWN:
                    if (choice < 4)
                    {
                        Mix_PlayChannel(-1, select_1, 0);
                        select_position.y += 85;
                        choice++;
                    }
                    break;
                case SDLK_RETURN:
                    if (choice == 1)
                    {
                        Mix_PlayChannel(-1, select_2, 0);
                        printf("\nPlayer Select -> Start Game");
                        menu = false;
                        startGame = true;
                    }
                    if (choice == 2)
                    {
                        Mix_PlayChannel(-1, select_2, 0);
                        printf("\nPlayer Select -> Tutorial");
                        menu = false;
                        tutScreen = true;
                    }
                    if (choice == 3)
                    {
                        Mix_PlayChannel(-1, select_2, 0);
                        printf("\nPlayer Select -> Credits");
                        menu = false;
                        credScreen = true;
                    }
                    if (choice == 4)
                    {
                        Mix_PlayChannel(-1, select_2, 0);
                        printf("\nPlayer Select -> Quit Game");
                        menu = false;
                        mainGame = false;
                    }
                    break;

                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background_texture, NULL, &background_position);
        SDL_RenderCopy(renderer, choices_texture, NULL, &choices_position);
        SDL_RenderCopy(renderer, select_texture, NULL, &select_position);
        SDL_RenderCopy(renderer, mainTitle_texture, NULL, &mainTitle_position);

        // Decide Main Menu Message
        if (choice == 1)
            SDL_RenderCopy(renderer, startgamemessage, NULL, &mainScreenText);
        else if (choice == 2)
            SDL_RenderCopy(renderer, tutorialmessage, NULL, &mainScreenText);
        else if (choice == 3)
            SDL_RenderCopy(renderer, optionmessage, NULL, &mainScreenText);
        else
            SDL_RenderCopy(renderer, quitmessage, NULL, &mainScreenText);

        // For GIFS frames
        frametime++;

        if(FPS/frametime == 10)
        {
            frametime = 0;
            chansey_properties.x += chanseywidth;
            if (chansey_properties.x >= cwidth)
            {
                chansey_properties.x = 0;
                chansey_properties.y += chanseyheight;
                if (chansey_properties.y >= cheight)
                {
                    chansey_properties.y = 0;
                }
            }

        }
        SDL_RenderCopy(renderer, chansey_texture, &chansey_properties, &chansey_position);
        SDL_RenderCopy(renderer, shadow_texture, NULL, &shadow_position_mainmenu);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(chansey_texture);

    }
}
void initGameDecide()
{
    int startChoice = 1;
    while (startGame)
    {
    while(SDL_PollEvent(&startgamechoice) != 0)
    {
        if (startgamechoice.type == SDL_QUIT)
        {
            startGame = false;
            mainGame = false;
        }
        if (startgamechoice.type == SDL_KEYDOWN)
        {
            switch(startgamechoice.key.keysym.sym)
            {
            case SDLK_UP:
                if (startChoice == 2)
                {
                    Mix_PlayChannel(-1, select_1, 0);
                    singleCursor_position.y -= 160;
                    startChoice--;
                }
                break;
            case SDLK_DOWN:
                if (startChoice == 1)
                {
                    Mix_PlayChannel(-1, select_1, 0);
                    singleCursor_position.y += 160;
                    startChoice++;
                }
                break;

            case SDLK_RETURN:
                if (startChoice == 1)
                {
                    Mix_PlayChannel(-1, select_2, 0);
                    printf("\nSelect: Guest Play");
                    avoidLag = 1;
                    startGame = false;
                    guestP = true;
                }
                if (startChoice == 2)
                {
                    Mix_PlayChannel(-1, select_2, 0);
                    printf("\nPlayer Select -> User Play");
                    if (user1 == 0 && user2 == 0)
                        printf("\n[!] No flashdrives found!");
                    else if (UserRegistered1 == 0)
                        {
                            startGame = false;
                            userReg = true;
                        }
                    else
                    {
                        avoidLag = 1;
                        startGame = false;
                        userP = true;
                    }
                }
                break;
            case SDLK_BACKSPACE:
                startGame = false;
                premenu = false;
                guestP = false;
                menu = true;
                break;
            }
        }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background_texture, NULL, &background_position);
    SDL_RenderCopy(renderer, gameChoice_texture, NULL, &gameChoice_position);
    SDL_RenderCopy(renderer, singleCursor_texture, NULL, &singleCursor_position);
    SDL_RenderPresent(renderer);
    }
}
void initGuestPlay()
{
    Buizel();
    Buizelback();
    Bulbasaur();
    Bulbasaurback();
    Celebi();
    Celebiback();
    Flareon();
    Flareonback();
    Electrivire();
    Electrivireback();
    Golem();
    Golemback();
    Greninja();
    Greninjaback();
    Grovyle();
    Grovyleback();
    Infernape();
    Infernapeback();
    Jolteon();
    Jolteonback();
    Suicune();
    Suicuneback();
    Luxray();
    Luxrayback();
    Manectric();
    Manectricback();
    Meganium();
    Meganiumback();
    Onix();
    Onixback();
    Pikachu();
    Pikachuback();
    Poliwrath();
    Poliwrathback();
    Raikou();
    Raikouback();
    Regirock();
    Regirockback();
    Rhydon();
    Rhydonback();
    Sandslash();
    Sandslashback();
    wp1();
    wp2();
    gp1();
    gp2();
    g2p1();
    g2p2();
    fp1();
    fp2();
    ep1();
    ep2();
    rp1();
    rp2();
    initText();

    srand(time(NULL));
    int player1 = (rand()%21)+1;
    int player2 = (rand()%21)+1;
    system("@cls||clear");
    Mix_PlayMusic(music_2, -1);
    char dmga[5];
    char dmgb[5];
    char num1[5];
    char num2[5];
    int p1health = 200;
    int p2health = 200;
    int player1pick = 0;
    int player2pick = 0;

    while(guestP && p1health >0 && p2health > 0 )
    {
        while(SDL_PollEvent(&guestplay) != 0)
        {
            while (damagep1 != 0 && damagep2 !=0)
                {
                    if(damagep1 > damagep2)
                        {
                            damage = damagep1 - damagep2;
                            p2health -= damage;
                            itoa(p2health, num2, 10);
                            player1health = TTF_RenderText_Solid(bitfont, num2 , white);
                            player1health_texture = SDL_CreateTextureFromSurface(renderer, player1health);
                            damagep1 = 0;
                            damagep2 = 0;
                            printf("\n[!] Player 1 inflicted %d damage to Player 2! [!]\n", damage);
                            itoa(damagep1, dmga, 10);
                            itoa(damagep2, dmgb, 10);
                            p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                            p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                            p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                            p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                            player1pick = 0;
                            player2pick = 0;
                        }
                    else
                        {
                            damage = damagep2 - damagep1;
                            p1health -= damage;
                            itoa(p1health, num1, 10);
                            player2health = TTF_RenderText_Solid(bitfont, num1 , white);
                            player2health_texture = SDL_CreateTextureFromSurface(renderer, player2health);
                            damagep1 = 0;
                            damagep2 = 0;
                            printf("\n[!] Player 2 inflicted %d damage to Player 1! [!]\n", damage);
                            itoa(damagep1, dmga, 10);
                            itoa(damagep2, dmgb, 10);
                            p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                            p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                            p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                            p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                            player1pick = 0;
                            player2pick = 0;
                        }
                }

            if (guestplay.type == SDL_QUIT)
            {
                loadingScreen = false;
                menu = false;
                premenu = false;
                startGame = false;
                guestP = false;
                mainGame = false;
            }
            if (guestplay.type == SDL_KEYUP)
            {

                switch(guestplay.key.keysym.sym)
                {
                case SDLK_1:
                    if (player1pick == 0)
                    {
                    damagep1 = (rand()%100)+1;
                    printf("\nPlayer 1 Damage: %d", damagep1);
                    itoa(damagep1, dmga, 10);
                    p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                    p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                    player1pick = 1;
                    }
                    else
                        printf("\nPlayer 1: You already picked!");
                    break;

                case SDLK_2:
                    if (player1pick == 0)
                    {
                    damagep1 = (rand()%100)+1;
                    printf("\nPlayer 1 Damage: %d", damagep1);
                    itoa(damagep1, dmga, 10);
                    p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                    p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                    player1pick = 1;
                    }
                    else
                        printf("\nPlayer 1: You already picked!");
                    break;
                case SDLK_3:
                    if (player1pick == 0)
                    {
                    damagep1 = (rand()%100)+1;
                    printf("\nPlayer 1 Damage: %d", damagep1);
                    itoa(damagep1, dmga, 10);
                    p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                    p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                    player1pick = 1;
                    }
                    else
                        printf("\nPlayer 1: You already picked!");
                    break;
                case SDLK_4:
                    if (player1pick == 0)
                    {
                    damagep1 = (rand()%100)+1;
                    printf("\nPlayer 1 Damage: %d", damagep1);
                    itoa(damagep1, dmga, 10);
                    p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                    p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                    player1pick = 1;
                    }
                    else
                        printf("\nPlayer 1: You already picked!");
                    break;

                case SDLK_a:
                    if (player2pick == 0)
                    {
                    damagep2 = (rand()%100)+1;
                    printf("\nPlayer 2 Damage: %d", damagep2);
                    itoa(damagep2, dmgb, 10);
                    p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                    p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                    player2pick = 1;
                    }
                    else
                        printf("\nPlayer 2: You already picked!");
                break;
                case SDLK_b:
                    if (player2pick == 0)
                    {
                    damagep2 = (rand()%100)+1;
                     printf("\nPlayer 2 Damage: %d", damagep2);
                     itoa(damagep2, dmgb, 10);
                    p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                    p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                    player2pick = 1;
                    }
                    else
                        printf("\nPlayer 2: You already picked!");
                break;
                case SDLK_c:
                    if (player2pick == 0)
                    {
                    damagep2 = (rand()%100)+1;
                     printf("\nPlayer 2 Damage: %d", damagep2);
                     itoa(damagep2, dmgb, 10);
                    p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                    p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                    player2pick = 1;
                    }
                    else
                        printf("\nPlayer 2: You already picked!");
                break;
                case SDLK_d:
                    if (player2pick == 0)
                    {
                    damagep2 = (rand()%100)+1;
                     printf("\nDamage p2: %d", damagep2);
                     itoa(damagep2, dmgb, 10);
                    p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                    p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                    player2pick = 1;
                    }
                    else
                        printf("\nPlayer 2: You already picked!");
                break;

                case SDLK_ESCAPE:
                    guestP = false;
                    avoidLag = 0;
                    menu = true;
                break;

                }
            }



        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, demoBack_texture, NULL, &demoBack_position);
        SDL_RenderCopy(renderer, demoPlat_texture, NULL, &demoPlat_position);
        SDL_RenderCopy(renderer, shadow_texture, NULL, &p1_shadow_b_position);
        SDL_RenderCopy(renderer, shadow_texture, NULL, &p2_shadow_b_position);

        if (player1 == 1)
            {
                animationBuizelp1();
                SDL_RenderCopy(renderer, Waterp1_texture, NULL, &Waterp1_position);
            }
        else if (player1 == 2)
            {
                animationBulbasaurp1();
                SDL_RenderCopy(renderer, Grassp1_texture, NULL, &Grassp1_position);

            }
        else if (player1 == 3)
            {
                animationCelebip1();
                SDL_RenderCopy(renderer, Grass2p1_texture, NULL, &Grass2p1_position);

            }
        else if (player1 == 4)
            {
                animationFlareonp1();
                SDL_RenderCopy(renderer, Firep1_texture, NULL, &Firep1_position);
            }
        else if (player1 == 5)
            {
                animationElectrivirep1();
                SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
            }
        else if (player1 == 6)
            {
                animationGolemp1();
                SDL_RenderCopy(renderer, Rockp1_texture, NULL, &Rockp1_position);
            }
        else if (player1 == 7)
        {
            animationGreninjap1();
            SDL_RenderCopy(renderer, Waterp1_texture, NULL, &Waterp1_position);
        }
        else if (player1 == 8)
        {
            animationGrovylep1();
            SDL_RenderCopy(renderer, Grass2p1_texture, NULL, &Grass2p1_position);
        }
        else if (player1 == 9)
        {
            animationInfernapep1();
            SDL_RenderCopy(renderer, Firep1_texture, NULL, &Firep1_position);
        }
        else if (player1 == 10)
        {
            animationJolteonp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 11)
        {
            animationSuicunep1();
            SDL_RenderCopy(renderer, Waterp1_texture, NULL, &Waterp1_position);
        }
        else if (player1 == 12)
        {
            animationLuxrayp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 13)
        {
            animationManectricp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 14)
        {
            animationMeganiump1();
            SDL_RenderCopy(renderer, Grassp1_texture, NULL, &Grassp1_position);
        }
        else if (player1 == 15)
        {
            animationOnixp1();
            SDL_RenderCopy(renderer, Rockp1_texture, NULL, &Rockp1_position);
        }
        else if (player1 == 16)
        {
            animationPikachup1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 17)
        {
            animationPoliwrathp1();
            SDL_RenderCopy(renderer, Waterp1_texture, NULL, &Waterp1_position);
        }
        else if (player1 == 18)
        {
            animationRaikoup1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 19)
        {
            animationRegirockp1();
            SDL_RenderCopy(renderer, Rockp1_texture, NULL, &Rockp1_position);
        }
        else if (player1 == 20)
        {
            animationRhydonp1();
            SDL_RenderCopy(renderer, Rockp1_texture, NULL, &Rockp1_position);
        }
        else if (player1 == 21)
        {
            animationSandslashp1();
            SDL_RenderCopy(renderer, Rockp1_texture, NULL, &Rockp1_position);
        }

        // Player 2 Display
        if (player2 == 1)
            {
                SDL_RenderCopy(renderer, Waterp2_texture, NULL, &Waterp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationBuizelp2();
            }
        else if (player2 == 2)
            {
                SDL_RenderCopy(renderer, Grassp2_texture, NULL, &Grassp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);

                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationBulbasaurp2();
            }

        else if (player2 == 3)
           {
                SDL_RenderCopy(renderer, Grass2p2_texture, NULL, &Grass2p2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationCelebip2();

           }

        else if (player2 == 4)
            {
                SDL_RenderCopy(renderer, Firep2_texture, NULL, &Firep2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationFlareonp2();

            }

        else if (player2 == 5)
            {
                SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationElectrivirep2();
            }
        else if (player2 == 6)
            {
                SDL_RenderCopy(renderer, Rockp2_texture, NULL, &Rockp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationGolemp2();
            }
        else if (player2 == 7)
            {
                SDL_RenderCopy(renderer, Waterp2_texture, NULL, &Waterp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationGreninjap2();
            }
        else if (player2 == 8)
        {
                SDL_RenderCopy(renderer, Grassp2_texture, NULL, &Grassp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationGrovylep2();
        }
        else if (player2 == 9)
        {
            SDL_RenderCopy(renderer, Firep2_texture, NULL, &Firep2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationInfernapep2();
        }
        else if (player2 == 10)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationJolteonp2();
        }
        else if (player2 == 11)
        {
            SDL_RenderCopy(renderer, Waterp2_texture, NULL, &Waterp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationSuicunep2();
        }
        else if (player2 == 12)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationLuxrayp2();
        }
        else if (player2 == 13)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationManectricp2();
        }
        else if (player2 == 14)
        {
            SDL_RenderCopy(renderer, Grassp2_texture, NULL, &Grassp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationMeganiump2();
        }
        else if (player2 == 15)
        {
            SDL_RenderCopy(renderer, Rockp2_texture, NULL, &Rockp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationOnixp2();
        }
        else if (player2 == 16)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationPikachup2();
        }
        else if (player2 == 17)
        {
            SDL_RenderCopy(renderer, Waterp2_texture, NULL, &Waterp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            animationPoliwrathp2();
        }
        else if (player2 == 18)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationRaikoup2();
        }
        else if (player2 == 19)
        {
            SDL_RenderCopy(renderer, Rockp2_texture, NULL, &Rockp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationRegirockp2();
        }
        else if (player2 == 20)
        {
            SDL_RenderCopy(renderer, Rockp2_texture, NULL, &Rockp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationRhydonp2();
        }
        else if (player2 == 21)
        {
            SDL_RenderCopy(renderer, Rockp2_texture, NULL, &Rockp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationSandslashp2();
        }

        if (p1health <= 0)
        {
            guestP = false;
            p2win = true;
        }
        else if (p2health <= 0)
        {
            guestP = false;
            p1win = true;
        }

    }

}
void initUserRegister()
{
    cursorDecide_position.x = 380;
    cursorDecide_position.y = 380;
    int gameRegisterChoice = 1;
    while (userReg)
    {
        while(SDL_PollEvent(&userregister) != 0)
        {
            if(userregister.type == SDL_QUIT)
            {
                userReg = false;
                mainGame = false;
            }
            if(userregister.type == SDL_KEYDOWN)
            {
                switch (userregister.key.keysym.sym)
                {
                case SDLK_DOWN:
                    if (gameRegisterChoice == 1)
                    {
                        Mix_PlayChannel(-1, select_1, 0);
                        cursorDecide_position.y += 85;
                        gameRegisterChoice++;
                    }
                    break;
                case SDLK_UP:
                    if (gameRegisterChoice == 2)
                    {
                        Mix_PlayChannel(-1, select_1, 0);
                        cursorDecide_position.y -= 85;
                        gameRegisterChoice--;
                    }
                    break;
                case SDLK_RETURN:
                    if (gameRegisterChoice == 1)
                    {
                        Mix_PlayChannel(-1, select_2, 0);
                        avoidLag = 1;
                        userReg = false;
                        generateMons = true;
                    }
                    if (gameRegisterChoice == 2)
                    {
                        Mix_PlayChannel(-1, select_2, 0);
                        userReg = false;
                        menu = true;
                    }
                    break;
                }
            }
        }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, gameDecide_texture, NULL, &gameDecide_position);
    SDL_RenderCopy(renderer, singleCursor_texture, NULL, &cursorDecide_position);
    SDL_RenderPresent(renderer);

    }

}
void initGenerate()
{
    cursorGenerator_position.x = 285;
    cursorGenerator_position.y = 535;

    // Randomize Encounters
    int genChoice = 1;
    int randomNum;
    srand(time(NULL));
    randomNum = (rand() % 21) + 1;

    // Declare Monsters
    Blaziken();
    Buizel();
    Bulbasaur();
    Celebi();
    Flareon();
    Electrivire();
    Golem();
    Greninja();
    Grovyle();
    Infernape();
    Jolteon();
    Suicune();
    Luxray();
    Manectric();
    Meganium();
    Onix();
    Pikachu();
    Poliwrath();
    Raikou();
    Regirock();
    Rhydon();
    Sandslash();
    encounterMessages();
    shadowSprite();
    system("@cls||clear");
    Mix_PlayMusic(music_3, 0);

    while(generateMons)
    {
        while(SDL_PollEvent(&usergenmons) != 0)
        {
            if(usergenmons.type == SDL_QUIT)
            {
                generateMons = false;
            }
            if(usergenmons.type == SDL_KEYDOWN)
            {
                switch(usergenmons.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    if (genChoice == 1)
                    {
                    Mix_PlayChannel(-1, select_1, 0);
                    cursorGenerator_position.x += 290;
                    genChoice++;
                    }
                    break;
                case SDLK_LEFT:
                    if (genChoice == 2)
                    {
                        Mix_PlayChannel(-1, select_1, 0);
                        cursorGenerator_position.x -= 290;
                        genChoice--;
                    }
                    break;
                case SDLK_RETURN:
                    if (genChoice == 1)
                    {
                        Mix_PlayChannel(-1, select_2, 0);
                        if (driveE)
                        {
                            registerUSM = fopen("E:/usmpokemon.dbf", "w");
                            fprintf(registerUSM, "%d", randomNum);
                            fclose(registerUSM);
                            if (UserRegistered1 == 0)
                                UserRegistered1 = 1;
                            if (UserRegistered1 != 0)
                                UserRegistered2 = 1;
                            printf("\nPokemon is now registered! Please restart.");
                            generateMons = false;
                            regsuccess = true;
                        }
                        if (driveF)
                        {
                            registerUSM = fopen("F:/usmpokemon.dbf", "w");
                            fprintf(registerUSM, "%d", randomNum);
                            fclose(registerUSM);
                            if (UserRegistered1 == 0)
                                UserRegistered1 = 1;
                            if (UserRegistered1 != 0)
                                UserRegistered2 = 1;
                            printf("\nPokemon is now registered! Please restart.");
                            generateMons = false;
                            regsuccess = true;
                        }
                        if (driveG)
                        {
                            registerUSM = fopen("E:/usmpokemon.dbf", "w");
                            fprintf(registerUSM, "%d", randomNum);
                            fclose(registerUSM);
                            if (UserRegistered1 == 0)
                                UserRegistered1 = 1;
                            if (UserRegistered1 != 0)
                                UserRegistered2 = 1;
                            printf("\nPokemon is now registered! Please restart.");
                            generateMons = false;
                            regsuccess = true;
                        }
                    }
                    if (genChoice == 2)
                    {
                        Mix_PlayChannel(-1, select_2, 0);
                        generateMons = false;
                        destroyGenerateResource();
                    }
                  break;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, generatePlat_texture, NULL, &generatePlat_position);
        SDL_RenderCopy(renderer, shadow_texture, NULL, &shadow_monsgen_position);
        SDL_RenderCopy(renderer, cursorGenerator_texture, NULL, &cursorGenerator_position);

        if (randomNum == 1)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                buizel_properties.x += buwidth;
                if (buizel_properties.x >= buizelwidth)
                {
                    buizel_properties.x = 0;
                    buizel_properties.y += buheight;
                    if (buizel_properties.y >= buizelheight)
                    {
                        buizel_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , buizel_texture, &buizel_properties, &buizelmid_position);
                SDL_RenderCopy(renderer, buizelenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 2)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                bulbasaur_properties.x += bulwidth;
                if (bulbasaur_properties.x >= bulbasaurwidth)
                {
                    bulbasaur_properties.x = 0;
                    bulbasaur_properties.y += bulheight;
                    if (bulbasaur_properties.y >= bulbasaurheight)
                    {
                        bulbasaur_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , bulbasaur_texture, &bulbasaur_properties, &bulbasaurmid_position);
                SDL_RenderCopy(renderer, bulbasaurenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 3)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                celebi_properties.x += cwidth;
                if (celebi_properties.x >= celebiwidth)
                {
                    celebi_properties.x = 0;
                    celebi_properties.y += cheight;
                    if (celebi_properties.y >= celebiheight)
                    {
                        celebi_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer, celebi_texture, &celebi_properties, &celebimid_position);
                SDL_RenderCopy(renderer, celebienc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 4)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                flareon_properties.x += fwidth;
                if (flareon_properties.x >= flareonwidth)
                {
                    flareon_properties.x = 0;
                    flareon_properties.y += fheight;
                    if (flareon_properties.y >= flareonheight)
                    {
                        flareon_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , flareon_texture, &flareon_properties, &flareonmid_position);
                SDL_RenderCopy(renderer, flareonenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 5)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                electrivire_properties.x += ewidth;
                if (electrivire_properties.x >= electrivirewidth)
                {
                    electrivire_properties.x = 0;
                    electrivire_properties.y += eheight;
                    if (electrivire_properties.y >= electrivireheight)
                    {
                        electrivire_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , electrivire_texture, &electrivire_properties, &electriviremid_position);
                SDL_RenderCopy(renderer, electrivireenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 6)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                golem_properties.x += gwidth;
                if (golem_properties.x >= golemwidth)
                {
                    golem_properties.x = 0;
                    golem_properties.y += gheight;
                    if (golem_properties.y >= golemheight)
                    {
                        golem_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , golem_texture, &golem_properties, &golemmid_position);
                SDL_RenderCopy(renderer, golemenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 7)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                greninja_properties.x += grwidth;
                if (greninja_properties.x >= greninjawidth)
                {
                    greninja_properties.x = 0;
                    greninja_properties.y += grheight;
                    if (greninja_properties.y >= greninjaheight)
                    {
                        greninja_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , greninja_texture, &greninja_properties, &greninjamid_position);
                SDL_RenderCopy(renderer, greninjaenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 8)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                grovyle_properties.x += grovwidth;
                if (grovyle_properties.x >= grovylewidth)
                {
                    grovyle_properties.x = 0;
                    grovyle_properties.y += grovheight;
                    if (grovyle_properties.y >= grovyleheight)
                    {
                        grovyle_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , grovyle_texture, &grovyle_properties, &grovylemid_position);
                SDL_RenderCopy(renderer, grovyleenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 9)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                infernape_properties.x += iwidth;
                if (infernape_properties.x >= infernapewidth)
                {
                    infernape_properties.x = 0;
                    infernape_properties.y += iheight;
                    if (infernape_properties.y >= infernapeheight)
                    {
                        infernape_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , infernape_texture, &infernape_properties, &infernapemid_position);
                SDL_RenderCopy(renderer, infernapeenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 10)
        {

            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                jolteon_properties.x += jwidth;
                if (jolteon_properties.x >= jolteonwidth)
                {
                    jolteon_properties.x = 0;
                    jolteon_properties.y += jheight;
                    if (jolteon_properties.y >= jolteonheight)
                    {
                        jolteon_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , jolteon_texture, &jolteon_properties, &jolteonmid_position);
                SDL_RenderCopy(renderer, jolteonenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 11)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                suicune_properties.x += suwidth;
                if (suicune_properties.x >= suicunewidth)
                {
                    suicune_properties.x = 0;
                    suicune_properties.y += suheight;
                    if (suicune_properties.y >= suicuneheight)
                    {
                        suicune_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , suicune_texture, &suicune_properties, &suicunemid_position);
                SDL_RenderCopy(renderer, suicuneenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 12)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                luxray_properties.x += lwidth;
                if (luxray_properties.x >= luxraywidth)
                {
                    luxray_properties.x = 0;
                    luxray_properties.y += lheight;
                    if (luxray_properties.y >= luxrayheight)
                    {
                        luxray_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , luxray_texture, &luxray_properties, &luxraymid_position);
                SDL_RenderCopy(renderer, luxrayenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 13)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                manectric_properties.x += mawidth;
                if (manectric_properties.x >= manectricwidth)
                {
                    manectric_properties.x = 0;
                    manectric_properties.y += maheight;
                    if (manectric_properties.y >= manectricheight)
                    {
                        manectric_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , manectric_texture, &manectric_properties, &manectricmid_position);
                SDL_RenderCopy(renderer, manectricenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 14)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                meganium_properties.x += mewidth;
                if (meganium_properties.x >= meganiumwidth)
                {
                    meganium_properties.x = 0;
                    meganium_properties.y += meheight;
                    if (meganium_properties.y >= meganiumheight)
                    {
                        meganium_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , meganium_texture, &meganium_properties, &meganiummid_position);
                SDL_RenderCopy(renderer, meganiumenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 15)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                onix_properties.x += owidth;
                if (onix_properties.x >= onixwidth)
                {
                    onix_properties.x = 0;
                    onix_properties.y += oheight;
                    if (onix_properties.y >= onixheight)
                    {
                        onix_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , onix_texture, &onix_properties, &onixmid_position);
                SDL_RenderCopy(renderer, onixenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 16)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                pikachu_properties.x += pwidth;
                if (pikachu_properties.x >= pikachuwidth)
                {
                    pikachu_properties.x = 0;
                    pikachu_properties.y += pheight;
                    if (pikachu_properties.y >= pikachuheight)
                    {
                        pikachu_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , pikachu_texture, &pikachu_properties, &pikachumid_position);
                SDL_RenderCopy(renderer, pikachuenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 17)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                poliwrath_properties.x += powidth;
                if (poliwrath_properties.x >= poliwrathwidth)
                {
                    poliwrath_properties.x = 0;
                    poliwrath_properties.y += poheight;
                    if (poliwrath_properties.y >= poliwrathheight)
                    {
                        poliwrath_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , poliwrath_texture, &poliwrath_properties, &poliwrathmid_position);
                SDL_RenderCopy(renderer, poliwrathenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 18)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                raikou_properties.x += rwidth;
                if (raikou_properties.x >= raikouwidth)
                {
                    raikou_properties.x = 0;
                    raikou_properties.y += rheight;
                    if (raikou_properties.y >= raikouheight)
                    {
                        raikou_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , raikou_texture, &raikou_properties, &raikoumid_position);
                SDL_RenderCopy(renderer, raikouenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 19)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                regirock_properties.x += rewidth;
                if (regirock_properties.x >= regirockwidth)
                {
                    regirock_properties.x = 0;
                    regirock_properties.y += reheight;
                    if (regirock_properties.y >= regirockheight)
                    {
                        regirock_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , regirock_texture, &regirock_properties, &regirockmid_position);
                SDL_RenderCopy(renderer, regirockenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 20)
        {
            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                rhydon_properties.x += rhwidth;
                if (rhydon_properties.x >= rhydonwidth)
                {
                    rhydon_properties.x = 0;
                    rhydon_properties.y += rhheight;
                    if (rhydon_properties.y >= rhydonheight)
                    {
                        rhydon_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , rhydon_texture, &rhydon_properties, &rhydonmid_position);
                SDL_RenderCopy(renderer, rhydonenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
        if (randomNum == 21)
        {

            frametime++;
            if(FPS/frametime == 10)
            {
                frametime = 0;
                sandslash_properties.x += swidth;
                if (sandslash_properties.x >= sandslashwidth)
                {
                    sandslash_properties.x = 0;
                    sandslash_properties.y += sheight;
                    if (sandslash_properties.y >= sandslashheight)
                    {
                        sandslash_properties.y = 0;
                    }
                }
                SDL_RenderCopy(renderer , sandslash_texture, &sandslash_properties, &sandslashmid_position);
                SDL_RenderCopy(renderer, sandslashenc_texture, NULL, &encountermessage_position);
                SDL_RenderPresent(renderer);
            }
        }
  }
}
void initUserPlay()
{
    Buizel();
    Buizelback();
    Bulbasaur();
    Bulbasaurback();
    Celebi();
    Celebiback();
    Flareon();
    Flareonback();
    Electrivire();
    Electrivireback();
    Golem();
    Golemback();
    Greninja();
    Greninjaback();
    Grovyle();
    Grovyleback();
    Infernape();
    Infernapeback();
    Jolteon();
    Jolteonback();
    Suicune();
    Suicuneback();
    Luxray();
    Luxrayback();
    Manectric();
    Manectricback();
    Meganium();
    Meganiumback();
    Onix();
    Onixback();
    Pikachu();
    Pikachuback();
    Poliwrath();
    Poliwrathback();
    Raikou();
    Raikouback();
    Regirock();
    Regirockback();
    Rhydon();
    Rhydonback();
    Sandslash();
    Sandslashback();
    wp1();
    wp2();
    gp1();
    gp2();
    g2p1();
    g2p2();
    fp1();
    fp2();
    ep1();
    ep2();
    rp1();
    rp2();
    initText();

    int player1;
    int player2;
    int player1useE = 0;
    int player1useF = 0;
    int player1useG = 0;
    char dmga[5];
    char dmgb[5];
    char num1[5];
    char num2[5];
    int p1health = 200;
    int p2health = 200;

    if (driveE)
    {
        loginUSM = fopen("E:/usmpokemon.dbf", "r");
        fscanf(loginUSM, "%2d", &player1);
        fclose(loginUSM);
        player1useE = 1;
    }
    else if (driveF)
    {
        loginUSM = fopen("F:/usmpokemon.dbf", "r");
        fscanf(loginUSM, "%2d", &player1);
        fclose(loginUSM);
        player1useF = 1;
    }
    else if (driveG)
    {
        loginUSM = fopen("G:/usmpokemon.dbf", "r");
        fscanf(loginUSM, "%2d", &player1);
        fclose(loginUSM);
        player1useG = 1;
    }

    if (UserRegistered2 == 1)
    {
        if (driveE = true && player1useE != 1)
        {
            loginUSM = fopen("E:/usmpokemon.dbf", "r");
            fscanf(loginUSM, "%1d", &player2);
            fclose(loginUSM);
        }
        else if (driveF = true && player1useF != 1)
        {
            loginUSM = fopen("F:/usmpokemon.dbf", "r");
            fscanf(loginUSM, "%1d", &player2);
            fclose(loginUSM);
        }
        else if (driveG = true && player1useG != 1)
        {
            loginUSM = fopen("G:/usmpokemon.dbf", "r");
            fscanf(loginUSM, "%1d", &player2);
            fclose(loginUSM);
        }
    }
    else
    {
        srand(time(NULL));
        player2 = (rand() % 5) + 1;
        printf("%d", player2);
    }


    system("@cls||clear");
    Mix_PlayMusic(music_2, -1);

    int player1pick = 0;
    int player2pick = 0;

    while(userP && p1health>0 && p2health>0)
    {
        while(SDL_PollEvent(&userplay) != 0)
        {
            if (damagep1 != 0 && damagep2 !=0)
                {
                    if(damagep1 > damagep2)
                        {
                            damage = damagep1 - damagep2;
                            p2health -= damage;
                            itoa(p2health, num2, 10);
                            player1health = TTF_RenderText_Solid(bitfont, num2 , white);
                            player1health_texture = SDL_CreateTextureFromSurface(renderer, player1health);
                            damagep1 = 0;
                            damagep2 = 0;
                            printf("\n[!] Player 1 inflicted %d damage to Player 2! [!]\n", damage);
                            itoa(damagep1, dmga, 10);
                            itoa(damagep2, dmgb, 10);
                            p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                            p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                            p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                            player1pick = 0;
                            player2pick = 0;
                        }
                    else
                        {
                            damage = damagep2 - damagep1;
                            p1health -= damage;
                            itoa(p1health, num1, 10);
                            player2health = TTF_RenderText_Solid(bitfont, num1 , white);
                            player2health_texture = SDL_CreateTextureFromSurface(renderer, player2health);
                            damagep1 = 0;
                            damagep2 = 0;
                            printf("\n[!] Player 2 inflicted %d damage to Player 1! [!]\n", damage);
                            itoa(damagep1, dmga, 10);
                            itoa(damagep2, dmgb, 10);
                            p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                            p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                            p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                            p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                            player1pick = 0;
                            player2pick = 0;
                        }
                }

            if (userplay.type == SDL_QUIT)
            {
                loadingScreen = false;
                menu = false;
                premenu = false;
                startGame = false;
                guestP = false;
                mainGame = false;
            }
            if (userplay.type == SDL_KEYUP)
            {

                switch(userplay.key.keysym.sym)
                {
                case SDLK_1:
                    if (player1pick == 0)
                    {
                    damagep1 = (rand()%100)+1;
                    printf("\nPlayer 1 Damage: %d", damagep1);
                    itoa(damagep1, dmga, 10);
                    p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                    p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                    player1pick = 1;
                    }
                    else
                        printf("\nPlayer 1: You already picked!");
                    break;
                case SDLK_2:
                    if (player1pick == 0)
                    {
                    damagep1 = (rand()%100)+1;
                    printf("\nPlayer 1 Damage: %d", damagep1);
                    itoa(damagep1, dmga, 10);
                    p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                    p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                    player1pick = 1;
                    }
                    else
                        printf("\nPlayer 1: You already picked!");
                    break;
                case SDLK_3:
                    if (player1pick == 0)
                    {
                    damagep1 = (rand()%100)+1;
                    printf("\nPlayer 1 Damage: %d", damagep1);
                    itoa(damagep1, dmga, 10);
                    p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                    p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                    player1pick = 1;
                    }
                    else
                        printf("\nPlayer 1: You already picked!");
                    break;
                case SDLK_4:
                    if (player1pick == 0)
                    {
                    damagep1 = (rand()%100)+1;
                    printf("\nPlayer 1 Damage: %d", damagep1);
                    itoa(damagep1, dmga, 10);
                    p1damage = TTF_RenderText_Solid(bitfont, dmga , white);
                    p1damage_texture = SDL_CreateTextureFromSurface(renderer, p1damage);
                    player1pick = 1;
                    }
                    else
                        printf("\nPlayer 1: You already picked!");
                    break;

                case SDLK_a:
                    if (player2pick == 0)
                    {
                    damagep2 = (rand()%100)+1;
                    printf("\nPlayer 2 Damage: %d", damagep2);
                    itoa(damagep2, dmgb, 10);
                    p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                    p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                    player2pick = 1;
                    }
                    else
                        printf("\nPlayer 2: You already picked!");
                break;
                case SDLK_b:
                    if (player2pick == 0)
                    {
                    damagep2 = (rand()%100)+1;
                    printf("\nPlayer 2 Damage: %d", damagep2);
                     itoa(damagep2, dmgb, 10);
                    p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                    p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                    player2pick = 1;
                    }
                    else
                        printf("\nPlayer 2: You already picked!");
                break;
                case SDLK_c:
                    if (player2pick == 0)
                    {
                    damagep2 = (rand()%100)+1;
                    printf("\nPlayer 2 Damage: %d", damagep2);
                     itoa(damagep2, dmgb, 10);
                    p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                    p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                    player2pick = 1;
                    }
                    else
                        printf("\nPlayer 2: You already picked!");
                break;
                case SDLK_d:
                    if (player2pick == 0)
                    {
                    damagep2 = (rand()%100)+1;
                    printf("\nPlayer 2 Damage: %d", damagep2);
                     itoa(damagep2, dmgb, 10);
                    p2damage = TTF_RenderText_Solid(bitfont, dmgb , white);
                    p2damage_texture = SDL_CreateTextureFromSurface(renderer, p2damage);
                    player2pick = 1;
                    }
                    else
                        printf("\nPlayer 2: You already picked!");

                break;
                case SDLK_ESCAPE:
                    guestP = false;
                    avoidLag = 0;
                    menu = true;
                break;

                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, demoBack_texture, NULL, &demoBack_position);
        SDL_RenderCopy(renderer, demoPlat_texture, NULL, &demoPlat_position);
        SDL_RenderCopy(renderer, shadow_texture, NULL, &p1_shadow_b_position);
        SDL_RenderCopy(renderer, shadow_texture, NULL, &p2_shadow_b_position);

        if (player1 == 1)
            {
                animationBuizelp1();
                SDL_RenderCopy(renderer, Waterp1_texture, NULL, &Waterp1_position);
            }

        else if (player1 == 2)
            {
                animationBulbasaurp1();
                SDL_RenderCopy(renderer, Grassp1_texture, NULL, &Grassp1_position);

            }

        else if (player1 == 3)
            {
                animationCelebip1();
                SDL_RenderCopy(renderer, Grass2p1_texture, NULL, &Grass2p1_position);

            }
        else if (player1 == 4)
            {
                animationFlareonp1();
                SDL_RenderCopy(renderer, Firep1_texture, NULL, &Firep1_position);

            }

         else if (player1 == 5)
            {
                animationElectrivirep1();
                SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
            }
            else if (player1 == 6)
            {
                animationGolemp1();
                SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
            }
        else if (player1 == 7)
        {
            animationGreninjap1();
            SDL_RenderCopy(renderer, Waterp1_texture, NULL, &Waterp1_position);
        }
        else if (player1 == 8)
        {
            animationGrovylep1();
            SDL_RenderCopy(renderer, Grass2p1_texture, NULL, &Grass2p1_position);
        }
        else if (player1 == 9)
        {
            animationInfernapep1();
            SDL_RenderCopy(renderer, Firep1_texture, NULL, &Firep1_position);
        }
        else if (player1 == 10)
        {
            animationJolteonp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 11)
        {
            animationSuicunep1();
            SDL_RenderCopy(renderer, Waterp1_texture, NULL, &Waterp1_position);
        }
        else if (player1 == 12)
        {
            animationLuxrayp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 13)
        {
            animationManectricp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 14)
        {
            animationMeganiump1();
            SDL_RenderCopy(renderer, Grassp1_texture, NULL, &Grassp1_position);
        }
        else if (player1 == 15)
        {
            animationOnixp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 16)
        {
            animationPikachup1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 17)
        {
            animationPoliwrathp1();
            SDL_RenderCopy(renderer, Waterp1_texture, NULL, &Waterp1_position);
        }
        else if (player1 == 18)
        {
            animationRaikoup1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 19)
        {
            animationRegirockp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 20)
        {
            animationRhydonp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }
        else if (player1 == 21)
        {
            animationSandslashp1();
            SDL_RenderCopy(renderer, Electricp1_texture, NULL, &Electricp1_position);
        }

        // Player 2 Display

        if (player2 == 1)
            {
                SDL_RenderCopy(renderer, Waterp2_texture, NULL, &Waterp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationBuizelp2();
            }

        else if (player2 == 2)
            {
                SDL_RenderCopy(renderer, Grassp2_texture, NULL, &Grassp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationBulbasaurp2();
            }

        else if (player2 == 3)
           {
                SDL_RenderCopy(renderer, Grass2p2_texture, NULL, &Grass2p2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationCelebip2();

           }

        else if (player2 == 4)
            {
                SDL_RenderCopy(renderer, Firep2_texture, NULL, &Firep2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationFlareonp2();

            }
        else if (player2 == 5)
            {
                SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationElectrivirep2();
            }
        else if (player2 == 6)
            {
                SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationGolemp2();
            }
        else if (player2 == 7)
            {
                SDL_RenderCopy(renderer, Waterp2_texture, NULL, &Waterp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
                SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationGreninjap2();
            }
        else if (player2 == 8)
        {
                SDL_RenderCopy(renderer, Grassp2_texture, NULL, &Grassp2_position);
                SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
                SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
                SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
                animationGrovylep2();
        }
        else if (player2 == 9)
        {
            SDL_RenderCopy(renderer, Firep2_texture, NULL, &Firep2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationInfernapep2();
        }
        else if (player2 == 10)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationJolteonp2();
        }
        else if (player2 == 11)
        {
            SDL_RenderCopy(renderer, Waterp2_texture, NULL, &Waterp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationSuicunep2();
        }
        else if (player2 == 12)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationLuxrayp2();
        }
        else if (player2 == 13)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationManectricp2();
        }
        else if (player2 == 14)
        {
            SDL_RenderCopy(renderer, Grassp2_texture, NULL, &Grassp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationMeganiump2();
        }
        else if (player2 == 15)
        {
            SDL_RenderCopy(renderer, Grassp2_texture, NULL, &Grassp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationOnixp2();
        }
        else if (player2 == 16)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationPikachup2();
        }
        else if (player2 == 17)
        {
            SDL_RenderCopy(renderer, Waterp2_texture, NULL, &Waterp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            animationPoliwrathp2();
        }
        else if (player2 == 18)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationRaikoup2();
        }
        else if (player2 == 19)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationRegirockp2();
        }
        else if (player2 == 20)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationRhydonp2();
        }
        else if (player2 == 21)
        {
            SDL_RenderCopy(renderer, Electricp2_texture, NULL, &Electricp2_position);
            SDL_RenderCopy(renderer, player1health_texture, NULL, &p1healthpos);
            SDL_RenderCopy(renderer, player2health_texture, NULL, &p2healthpos);
            SDL_RenderCopy(renderer, p1damage_texture, NULL, &p1damagepos);
            SDL_RenderCopy(renderer, p2damage_texture, NULL, &p2damagepos);
            animationSandslashp2();
        }

        if (p1health <= 0)
        {
            guestP = false;
            p1win = true;
        }
        else if (p2health <= 0)
        {
            guestP = false;
            p2win = true;
        }

    }
}
void initTutorial()
{
    while (tutScreen)
    {
        while(SDL_PollEvent(&tutorial) != 0)
        {
            if (tutorial.type == SDL_QUIT)
            {
                tutScreen = false;
                mainGame = false;
            }
            if (tutorial.type == SDL_KEYDOWN)
            {
                switch(tutorial.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    tutScreen = false;
                    menu = true;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, controls_texture, NULL, &controls_position);
        SDL_RenderPresent(renderer);
    }
}
void initCredits()
{
    while (credScreen)
    {
        while(SDL_PollEvent(&credits) != 0)
        {
            if (credits.type == SDL_QUIT)
            {
                credScreen = false;
                mainGame = false;
            }
            if (credits.type == SDL_KEYDOWN)
            {
                switch(credits.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    credScreen = false;
                    menu = true;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, credit_texture, NULL, &credit_position);
        SDL_RenderPresent(renderer);
    }
}
void initSuccReg()
{
    while (regsuccess)
    {
        while(SDL_PollEvent(&registersuccess) != 0)
        {
            if (registersuccess.type == SDL_QUIT)
            {
                regsuccess = false;
                mainGame = false;
            }

            SDL_Delay(2000);
            regsuccess = false;
            mainGame = false;

        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, restart_texture, NULL, &restart_position);
        SDL_RenderPresent(renderer);
    }
}
void initPlayer1win()
{
    while (p1win)
    {
        while(SDL_PollEvent(&winp1) != 0)
        {
            if (winp1.type == SDL_QUIT)
            {
                p1win = false;
                mainGame = false;
            }
            if (winp1.type == SDL_KEYDOWN)
            {
                {
                    p1win = false;
                    mainGame = false;
                }
            }

        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, player1w_texture, NULL, &player1w_position);
        SDL_RenderPresent(renderer);
    }
}
void initPlayer2win()
{
    while (p2win)
    {
        while(SDL_PollEvent(&winp2) != 0)
        {
            if (winp2.type == SDL_QUIT)
            {
                p2win = false;
                mainGame = false;
            }
            if (winp2.type == SDL_KEYDOWN)
            {
                {
                    p2win = false;
                    mainGame = false;
                }
            }

        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, player2w_texture, NULL, &player2w_position);
        SDL_RenderPresent(renderer);
    }
}
int main(int argc, char **argv)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_AllocateChannels(8);

    readUser();

    initGameResources();
    initLoadScreenResource();
    initPreMenuResource();
    initMainMenuResource();
    initGuestPlayResource();
    initGenerateResource();
    system("@cls||clear");
    readFlashDrive();


    while(mainGame)
    {
        // Main Menu Muna
        initloadScreen();
        initPreMenu();
        initMainmenu();
        initGameDecide();
        initTutorial();
        initCredits();
        initUserRegister();

        // may mga monsters na dito e
        if (avoidLag == 1)
        {
        initGuestPlay();
        initUserPlay();
        initGenerate();
        }

        initSuccReg();
        initPlayer1win();
        initPlayer2win();
    }

    return 0;
}
