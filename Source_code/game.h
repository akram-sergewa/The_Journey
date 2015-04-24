/*------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------GAME.H--------------------------------------------------------*/
/*----------------------------------------------THE HEADER FILE FOR THE GAME----------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/


//#include <SDL2/SDL.h>
//#include <SDL2/SDL_mixer.h>
//#include <SDL2/SDL_ttf.h>
#include <errno.h>


#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXCOIN 10
#define PRELOAD_RESOURCES_DEBUG 1
#define DEBUG FALSE
#define SCREEN_WIDTH 800
#define SCREEN_HIGHT 600
#define FILE_MAX 10
#define bool int
#define TRUE 1
#define FALSE 0
#define HALFTRUE 2
#define GRID 32
#define UP 4
#define DOWN 2
#define LEFT 3
#define RIGHT 1
#define BOX 4
#define K_R_BOX 9
#define K_Blue_BOX 33
#define EMPTY_BOX_INFO 17
#define NOTEXIST 99
#define YVALUE 0
#define XVALUE 1
#define EXIST 2



#define WINDOW 5
#define KITCHENFOOD 6
#define CASTLEFOOD 38
#define GUARD_HALT 40
#define BED 7
#define INPUT_TEXT_SIZE 100
#define NEXT_MAP 20
#define PREVIOUS_MAP 21
#define NEXT_MAP_CLOSED 22
#define MAPSNUMBER 5
#define PILES 8
#define CHAR_BLUE_HAIR 11
#define CHAR_FOREST_BLOCKER 13
#define CHAR_FOREST_BLOCKER_AXE 15
#define CLOAK_BOX 37
#define CHAR_FOREST_GUIDE 36
#define CHAR_FOREST_GUIDE2 39
#define CHAR_MAID 41
#define CHAR_WIZARD 42
#define SPEED 4
#define map_1_char_1_interaction 19
#define map_1_char_2_interaction 25
#define map_1_char_3_interaction 23
#define CACTUS 27
#define CACTUS_ROW 29
#define FLOWER 31
#define INN_ENTRANCE 35
#define SHIELD 43
#define WAND 44
#define map_1_vending_interaction 45
#define map_4_vending_interaction 46
#define map_1_bar 47
#define sapphire_box 48
#define DELAYBEFOREDEATH 3000
#define ONESECOND 1000
#define FULLHEALTH 100
#define MOREMAXFILE 2
#define LOADGAME 1
#define SAVEGAME 3



struct extra{
    Mix_Chunk* effect_coin;
    Mix_Chunk* effect_opDoor;
    Mix_Chunk* effect_clDoor;
    Mix_Chunk* music;
    Mix_Chunk* effect_sneeze;
    Mix_Chunk* effect_burp;
    Mix_Chunk* effect_eat;
    Mix_Chunk* effect_guitar;
    Mix_Chunk* effect_lethergo;
    Mix_Chunk* map_1_dialog_show_me_you_got;
    Mix_Chunk* map_1_dialog_westeros_our_end;
    Mix_Chunk* map_1_dialog_what_can_i_do;
    Mix_Chunk* map_1_dialog_wonder_so_many_cactuses;
    Mix_Chunk* map_1_dialog_you_shall_not_pass;
    Mix_Chunk* map_1_dialog_blue_box_cactus;
    Mix_Chunk* map_1_char_oh_cactus;
    Mix_Chunk* map_1_char_I_dislike_cactus;
    Mix_Chunk* map_1_char_cactus_is_blocking;
    Mix_Chunk* map_1_char_holy_axe;
    Mix_Chunk* map_1_char_I_cant_open;
    Mix_Chunk* map_1_char_Inn_not_use;
    Mix_Chunk* map_1_char_teleported;
    Mix_Chunk* map_2_dialog_guide_greetings;
    Mix_Chunk* map_2_dialog_guide_use_it_wisely;
    Mix_Chunk* map_2_dialog_guide_go_find_valuable;
    Mix_Chunk* map_2_char_cannot_see_cloak;
    Mix_Chunk* map_2_char_not_opaque;
    Mix_Chunk* map_2_char_smells_meaty;
    Mix_Chunk* map_3_dialog_castle_grounds;
    Mix_Chunk* map_3_dialog_information_useful;
    Mix_Chunk* map_3_dialog_sell_intelligence;
    Mix_Chunk* map_4_dialog_you_cant_defeat;
    Mix_Chunk* map_4_dialog_the_world_is_ours;
    Mix_Chunk* map_4_dialog_nooo;

    SDL_Surface *Box_surf;
    SDL_Surface *OBox_surf;
    SDL_Surface *CWindow_surf;
    SDL_Surface *Kitchen_food_surf;
    SDL_Surface *castle_food_surf;
    SDL_Surface *Bed_surf;
    SDL_Surface *Guitar_surf;
    SDL_Surface *coin01_surf;
    SDL_Surface *coin_blue_surf;
    SDL_Surface *coin_green_surf;
    //SDL_Surface *mushroom_surf;
    SDL_Surface *two_piles_surf;
    SDL_Surface *Key_surf;
    SDL_Surface *Key_red_surf;
    SDL_Surface *Key_blue_surf;
    SDL_Surface *char_blue_hair_surf;
    SDL_Surface *dialog_box_blue_hair_surf;
    SDL_Surface *char_forest_blocker_surf;
    SDL_Surface *char_forest_blocker_axe_surf;
    SDL_Surface *dialog_box_map_1_char_1_surf;
    SDL_Surface *dialog_box_map_1_char_2_surf;
    SDL_Surface *object_blue_opened_box_surf;
    SDL_Surface *object_map_1_vending_machine_surf;
    SDL_Surface *object_map_1_inn_surf;
    SDL_Surface *object_map_1_bar_surf;
    SDL_Surface *char_forest_guide_surf;
    SDL_Surface *dialog_box_map_2_forest_guide_surf;
    SDL_Surface *char_forest_guide_surf2;
    SDL_Surface *dialog_box_map_3_castle_guide_surf;
    SDL_Surface *char_matthew_surf;
    SDL_Surface *char_jacob_surf;
    SDL_Surface *char_maid_surf;
    SDL_Surface *char_wizard_surf;
    SDL_Surface *cactus_surf;
    SDL_Surface *flower_surf;
    SDL_Surface *cloak_surf;
    SDL_Surface *shield_surf;
    SDL_Surface *object_map_4_vending_machine_surf;
    SDL_Surface *spell_surf3;
    SDL_Surface *spell_surf4;
    SDL_Surface *spell_surf5;
    SDL_Surface *spell_surf6;
    SDL_Surface *spell_surf7;
    SDL_Surface *wand_surf;
    SDL_Surface *game_over;




    int Guitar_active;
    int Guitar_counter;
    int LetHerGo_active;
    int LetHerGo_counter;
    SDL_Rect coin_src_rect[9];
    char coin_file[20];

    //Texts to be printed on the screen
      char text_string_input[INPUT_TEXT_SIZE];
      char text[10];
      char text_blue_coin[10];
      char text_green_coin[10];
      char text_moves_char[10];
      char text_health[10];
      char text_inst[1000];

    };
    typedef struct extra EXTRA;

struct maingraphics{
        SDL_Surface* screen;
        SDL_Surface* screen_cover;
        SDL_Window *window;
        SDL_Surface *text_surf;
        SDL_Surface *text_green_coin_surf;
        SDL_Surface *text_blue_coin_surf;
        SDL_Surface *text_moves;
        SDL_Surface *text_input_surf;
        SDL_Surface *text_inst_surf;
        SDL_Surface *text_health_surf;
        SDL_Surface *main_surf;
        SDL_Surface *options_surf;
        SDL_Surface *currentMap_surf;
        TTF_Font* font;
        TTF_Font* font_input;
        SDL_Rect text_counter_rect;
        SDL_Rect text_input_rect;
        SDL_Rect text_moves_rect;
        SDL_Rect text_inst_rect;
        SDL_Rect text_health_rect;
        SDL_Rect map_rect;
        SDL_Rect text_green_coin_rect;
        SDL_Rect text_blue_coin_rect;

};
    typedef struct maingraphics MAINGRAPHICS;

struct map_level {
        int level;
        int grid [100][100];
        int hight;
        int width;
        int completed;
        char map_file[40];
        int start [2];
        int exit [2];
        int coins [MAXCOIN][3];
        int coins_blue [MAXCOIN][3];
        int coins_green [MAXCOIN][3];
        int boxes [5][3];
        int K_R_boxes [1][3];
        int K_Blue_boxes [1][3];
        int K_Red_boxes [1][3];
        int blue_opened_box [1][3];
        int windows [3][3];
        int kitchen_food[1][3];
        int bed[1][3];
        int mushroom[10][3];
        int two_piles[1][3];
        int char_blue_hair[1][3];
        int char_forest_blocker[1][3];
        int char_forest_guide[1][3];
        int char_forest_guide2[1][3];
        int char_matthew[1][3];
        int char_jacob[1][3];
        int char_maid[1][3];
        int char_wizard[1][3];
        int axe_boxes[1][3];
        int cloak_boxes[1][3];
        int castle_food_boxes[1][3];
        int cactus[3][3];
        int flower[1][3];
        int shield[1][3];
        int spell[1][3];
        int wand[1][3];
};
typedef struct map_level MAP;


struct movement
{
    int can_move;
    int direction;
    int move_holder;
    int position_holder_x;
    int position_holder_y;
    int execute;
    int arrow_right;
    int arrow_down;
    int arrow_left;
    int arrow_up;
    int Key_enter;
    int frame;
    int currentCharacter_frame;
    int coin_frame;
    int play;
    int options;
    int ch_chosen;
    int Current_Reacher_Map;
    int coin_counter;
    int coin_green_counter;
    int coin_blue_counter;
    int move_counter;
    int text_count;
    int MAP_reached;
    int Health_bar;
    int key_room;
    int key_Red_room;
    int key_Blue_room;
    int char_forest_blocker_axe;
    int cloak;
    int castle_food;
    int fps_cheat;
    int shield_found;
    int spell_counter;
    int shield_use;
    int wand_found;
    int canTeleport;
    int whereTeleport;
    int call_dialog_surface_blue_hair;
    int call_dialog_surface_map_1_char_1;
    int call_dialog_surface_map_1_char_2;
    int call_dialog_surface_map_1_forest_blocker;
    int call_dialog_surface_map_2_forest_guide;
    int call_dialog_surface_map_3_forest_guide;
    int sapphire_box_status;
    int game_over;
};
typedef struct movement MOVEMENT;

struct character {
            int id;
            char ch_file[40];
            char ch_fc_file[40];
            SDL_Rect ch_src_rect[12];
            int mv_right[2];  //start frame and end frame
            int mv_left[2];
            int mv_up[2];
            int mv_down[2];
            SDL_Surface *currentCharacter_surf;
            SDL_Rect ch_rect_dest;

};
typedef struct character CHARACTER;



struct cursor{
    int button;
    int x;
    int y;
};
typedef struct cursor CURSOR;

/*--------INITIALIZE SDL, TTF AND MIXER---------*/
void graphInit ();

/*--------INITIALIZE THE STRUCUTRE AND FILL THEM WITH DATA---------*/
void mapMaker(MAP the_map[MAPSNUMBER]);
void charMaker(CHARACTER* the_character, int ch_chosen, SDL_Surface *screen);
void extraMaker(EXTRA *Extra, SDL_Surface *screen);
void movementMaker (MOVEMENT *Movement);
void mainGraphicsMaker(MAINGRAPHICS *mainGraphics);
void coinMaker(EXTRA* Extra);


/*--------CHECK THE POSSIBILITY TO MOVE TO ANOTHER POSITION AND EXCUTE ANIMATION---------*/
void checkMoveKey(CHARACTER *currentCharacter, MAP *currentMap, MOVEMENT *Movement, char* text_inst);
int checkMoveable(CHARACTER* currentCharacter, MAP* currentMap, MOVEMENT *Movement);
void  execMove(MOVEMENT *Movement, SDL_Rect *ch_rect_dest, CHARACTER* currentCharacter, SDL_Rect *map_rect);


/*------CALLS THE MAIN PAGE OPTIONS AND THE POSITIONS OF THE BUTTONS------*/
void mainOptionsActivity(CURSOR *Cursor, MOVEMENT *Movement, int* running);
void mainPageActivity(CURSOR *Cursor, int *play, int *options, int* running);


/*------FUNCTIONS FOR SAVING AND LOADING THE GAME AND CHECKING THE FILE------*/
int saveGame(FILE* file, MOVEMENT *Movement, MAP *Maps, CHARACTER *currentCharacter );
int loadGame(FILE* file, MOVEMENT *Movement, MAP *Maps, CHARACTER *currentCharacter );
int getFilename (char *File_name, char* the_string);


/*------FUNCTIONS FOR CHECKING AND EXECUTING MOVEMENT FROM ONE MAP TO ANOTHER------*/
int checkMapNextPrev(MAP Maps[MAPSNUMBER], MAP **currentMap, MOVEMENT *Movement, EXTRA *Extra, SDL_Rect *map_rect, SDL_Rect ch_rect_dest, SDL_Surface **currentMap_surf);
void execMapNextPrev(MAP Maps[MAPSNUMBER], MAP **currentMap, MOVEMENT *Movement, SDL_Rect *map_rect, SDL_Rect ch_rect_dest, SDL_Surface **currentMap_surf);


int charObjectCollision(MOVEMENT *Movement,MAP* currentMap, EXTRA *Extra);


/*--------CHECKS THE TYPED COMMAND BY THE USER AND CALL DIFFERENT FUNCTIONS BASED ON IT-------*/
int checkPlayEvents(MOVEMENT *Movement, MAP **currentMap, EXTRA *Extra, CHARACTER *currentCharacter, MAINGRAPHICS *mainGraphics, MAP Maps[MAPSNUMBER]);


/*--------RESTART ALL THE VALUES TO START A NEW GAME-------*/
void restartGame(MAP Maps[MAPSNUMBER], MAP **currentMap, MOVEMENT *Movement, CHARACTER *currentCharacter, MAINGRAPHICS *mainGraphics, SDL_Surface **currentMap_surf, EXTRA* Extra);


/*-----------------FUNCTIONS TO DEAL WITH SDL GRAPHICS AND TTF AND MIX AUDIO------------------*/
/*---TRACK SDL EVENTS--*/
void SDLEvents(SDL_Event *event,CURSOR *Cursor,MOVEMENT *Movement, char *text_string_input, int *running);
/*---DRAW ELEMENTS FROM EXTRA STRUCUTRE--*/
void extraDrawUpdate(EXTRA *Extra, MAP *currentMap, MOVEMENT *Movement, SDL_Surface *screen, SDL_Rect map_rect);
/*---CONTAINS THE POSITIONS FOR ALL THE TEXTS ON THE SCREEN--*/
void textPosition(MAINGRAPHICS *mainGraphics);
/*---DRAW THE TEXTS ON THE SCREEN--*/
void drawTexts(MAINGRAPHICS *mainGraphics, SDL_Color text_color, SDL_Color text_input_color, EXTRA *Extra);
/*---DRAW ALL THE ELEMENTS BY CALLING ALL THE REQUIRED FUNCTIONS--*/
void finalDrawer(MAP *currentMap, EXTRA *Extra,CHARACTER *currentCharacter, MAINGRAPHICS *mainGraphics, MOVEMENT *Movement, int FPS, SDL_Surface *currentMap_surf);
/*---INCREMENT THE FRAME VALUE FOR THE GAME PLAY AND COINS AND OTHER OBJECTS--*/
void incremintFrames(MOVEMENT *Movement);
/*---DRAW THE SMALL ICONS ON THE SCREEN--*/
void screenObjects(MOVEMENT *Movement, EXTRA *Extra, SDL_Surface *screen);
/*---CONTAINS THE TEXTS THAT SHOULD BE DRAWN FOR EACH MAP--*/
void instructionHelp (EXTRA *Extra, MAP* currentMap);
/*-----FREE SURFACES FROM MEMORY------*/
void SDLFreeSurfaces(MAINGRAPHICS *mainGraphics, EXTRA *Extra);
/*-----FREE TEXTS FROM MEMORY------*/
void SDLFreeText(MAINGRAPHICS *mainGraphics);



/*------NON ESSENTIAL FUNCTIONS TO ADD DIVERSITY TO THE PLAYING EXPERIENCE------*/
void extraGuitar(EXTRA *Extra,MOVEMENT *Movement, CHARACTER *currentCharacter, SDL_Surface *screen, SDL_Rect ch_rect_dest, int FPS);
void extraLetgergo(EXTRA *Extra,MOVEMENT *Movement, CHARACTER *currentCharacter, SDL_Surface *screen, SDL_Rect ch_rect_dest, int FPS);
void teleport(MAP Maps[MAPSNUMBER], MAP **currentMap, MOVEMENT *Movement,  CHARACTER *currentCharacter, MAINGRAPHICS *mainGraphics, SDL_Surface **currentMap_surf, int teleMap);



/*--------CHECKS THE HEALTH BAR AND REACT BASED ON IT-------*/
void healthDetector(MOVEMENT *Movement, char * text_string_input);


/* ---------------SDL TESTING------------------*/
void testSDL(int boolean);
void testSDLSufaces ( char *name);
void testSDLMix(char* name);
void testSDLTTF( char *name);
void loadAfterColon(FILE* loadGame);
