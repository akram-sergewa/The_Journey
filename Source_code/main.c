/*------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------MAIN.C----------------------------------------------------------*/
/*----------------------MAIN FILE THAT CALLS ALL OTHER FILES AND FUNCTIONS AND CONTAINS THE FPS LOOP----------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/

#include "game.h"
#include "game_control.c"
#include "game_contents.c"
#include "game_save.c"
#include "game_graphics.c"
#include "game_events.c"
#include "game_animation.c"
#include "game_test.c"


/*-----------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------THE MAIN FUNCTION--------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------*/
int main (int argc, char* args[])
{
    srand(time(NULL));

/*INITIALIZE THE GRAPHICS AND SDL*/
    graphInit();
    MAINGRAPHICS mainGraphics;
    mainGraphicsMaker(&mainGraphics);
    const int FPS = 30;
    bool running = TRUE;
    Uint32 start;
    Uint32 color1 = 0x000000;

    testSDL(PRELOAD_RESOURCES_DEBUG);

/*--------------------COLORS FOR TEXTS------------------------*/
  SDL_Color text_color = {255,255,255};
  SDL_Color text_input_color = {0,0,0};

/*INITIALIZE THE EXTRA STRUCTURE THAT HOLDS MOST OF THE SURFACES*/
EXTRA Extra;
extraMaker(&Extra, mainGraphics.screen);//assigns all values to Extra

/*-----------SET VALUES OF THE TEXTS TO "" EMPTY---------------*/
  strcpy(Extra.text_string_input,"");
  strcpy(Extra.text_inst,"");


/*----------SET THE POSITIONS OF THE TEXTS--------------------*/
textPosition(&mainGraphics);


/*------------INITIALIZE THE CURSOR STRUCTURE---------------*/
CURSOR Cursor;


/*-----------------INITIALIZE THE MOVEMENT STRUCTURE------------------*/
/*ABILITIES, MOVEMENTS, COUNTERS, POSITIONS ARE ALL STORED IN MOVEMENT*/
/*---ASSIGN VALUES TO MOVEMENT FOR STARTING THE GAME THE FIRST TIME---*/
MOVEMENT Movement;
movementMaker (&Movement);
    Movement.fps_cheat = FPS; //temporary


/*----------INITIALIZE MAPS STRUCTURE AS AN ARRAY---------------*/
MAP Maps[MAPSNUMBER];
mapMaker(Maps);

/*-----SET currentMap TO HOLD A POINTER TO THE CURRENT MAP----*/
MAP *currentMap;
currentMap = &Maps[0];
mainGraphics.currentMap_surf = SDL_LoadBMP(currentMap->map_file);


/*--------------INITIALIZE CHARACTER STRUCTURE----------------*/
CHARACTER currentCharacter;

/*RESTARTGAME FUNCTION TO INITIALIZE THE CONTENTS EVEN BEFORE STARTING PLAYING,*/
/*TO FIX A BUG THAT MAY HAPPEN WHILE SHOWING THE MAIN OPTIONS BEFORE PLAYING*/
restartGame(Maps, &currentMap, &Movement, &currentCharacter, &mainGraphics, &mainGraphics.currentMap_surf , &Extra);

/*------SET THE GAME TO THE MAIN PAGE PHASE BY SETTING PLAY TO FALSE------------*/
Movement.play = FALSE;


/*--------PLAY THE BACKGROUND MUSIC-------*/
Mix_PlayChannel(-1,Extra.music,-1);

/*----INITIALIZE THE INPUT------*/
SDL_StartTextInput();
while (running)
    {
        start = SDL_GetTicks();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            /*---------DEALS WITH EVENTS FROM KEYBOARD AND MOUSE----------*/
           SDLEvents(&event,&Cursor,&Movement, Extra.text_string_input, &running);
        }

        /*-----------------------KEY LOGIC-------------------------*/
        checkMoveKey(&currentCharacter, currentMap, &Movement, Extra.text_inst);

        /*-----------------------IF THE KEY ENTER WAS PRESSED-------------------------*/
        if (Movement.Key_enter)
        {
            /*----------CHECK THE WRITTEN CODE AND PASS TEXT INSTRUCTIONS-------------*/
            checkPlayEvents(&Movement, &currentMap, &Extra, &currentCharacter, &mainGraphics, Maps);
            strcpy(Extra.text_string_input,"");             /*----Set the text box to empty-----*/
            Movement.text_count = 0;
            Movement.Key_enter = FALSE;
            mainGraphics.currentMap_surf  = SDL_LoadBMP(currentMap->map_file);   /*-----loads map in case of map changes-----*/

        }

         /*----------------DISPLAY MAIN PAGE-----------------*/
        if (Movement.play == FALSE)
        {

            if (Movement.options == FALSE)
            {
                SDL_BlitSurface(mainGraphics.main_surf,NULL,mainGraphics.screen,NULL); /*Draw the main page background*/
                if (Cursor.button)
                {
                mainPageActivity(&Cursor, &Movement.play, &Movement.options, &running); /*Check the events from the cursor for main page*/
                }
                if (Movement.play) /*IF PLAY BUTTON WAS CLICKED ON*/
                {
                    /*START A NEW GAME*/
                restartGame(Maps, &currentMap, &Movement, &currentCharacter, &mainGraphics, &mainGraphics.currentMap_surf , &Extra);
                }


         /*----------------DISPLAY OPTIONS PAGE-----------------*/
            }else if (Movement.options)
                {
                    SDL_BlitSurface(mainGraphics.options_surf,NULL,mainGraphics.screen,NULL);/*Draw the options page background*/
                    if (Cursor.button)
                    {
                    mainOptionsActivity(&Cursor, &Movement,&running);  /*Check the events from the cursor for options page*/
                    }
                }
        }
        /*NO ELSE HERE, TWO SEPARATE CONDITIONS*/

        /*-----------START THE GAME PLAY--------------*/
        if(Movement.play)
        {
            /*SPECIAL CASE FOR DEBUG BY JUMPING DIRECTLY FROM ONE MAP TO ANOTHER BAY TYPING TELE THEN NUMBER OF THE MAP*/
            if (Movement.canTeleport == TRUE)
            {
                Movement.canTeleport = FALSE;
              teleport(Maps, &currentMap, &Movement, &currentCharacter, &mainGraphics, &(mainGraphics.currentMap_surf),Movement.whereTeleport);
            }


            /*---CHECK IF THE PLAYER IS IN A POSITION THAT ALLOWS THEM TO ACCESS ANOTHER MAP, THEN CONDITION WILL EXECUTE THE MOVEMENT TO THE NEW MAP
            AND RETURN TRUE, IN CASE TRUE PRINT THE INSTRUCTIONS FOR THE NEW MAP------*/
            if (checkMapNextPrev(Maps, &currentMap, &Movement, &Extra, &mainGraphics.map_rect, currentCharacter.ch_rect_dest, &mainGraphics.currentMap_surf ) == TRUE){
            instructionHelp(&Extra, currentMap); //is called to update the instructions whenever you move to a different map
            }


            /*----IF THERE WAS A MOVEMENT THAT SHOULD BE UNDERTAKEN THE MOVE_HOLDER WILL BE TRUE, AND IN EVERY FRAME THIS
            CONDITION WILL BE EXECUTED UNTIL THE CHARACTER REACHES THE NEW POSITION--------*/
            if (Movement.move_holder)
            {
                execMove(&Movement, &currentCharacter.ch_rect_dest, &currentCharacter, &mainGraphics.map_rect);
            }

            /*-----------------------DEBUG-------------------------*/
            if (DEBUG)
            {
                Movement.Health_bar = 100; /*----SET HEALTH ALWAYS TO 100-----*/
                 if (!(Movement.frame %30)) /*-----EVERY 30 FRAMES PRINT THESE VALUES ON THE TERMINAL-----*/
                    {
                        system("cls");
                        printf("\n    Y value %d", Movement.position_holder_y);
                        printf("\n   X value  %d", Movement.position_holder_x);
                        printf("\n       map  %d", Movement.MAP_reached);
                        printf("\ngrid value  %d", currentMap->grid[Movement.position_holder_y][Movement.position_holder_x]);
                        printf("\n   start y  %d", currentMap->start[0]);
                        printf("\n   start x  %d", currentMap->start[1]);
                        printf("\n    exit y  %d", currentMap->exit[0]);
                        printf("\n    exit x  %d", currentMap->exit[1]);
                        printf("\n    NEXT_MAP is grid[y][x]");
                        printf("\n    FPS  %d", Movement.fps_cheat);
                        printf("\n    character %d\n", Movement.ch_chosen);
                    }
            }

            /*--------TAKE COINS BY DETECTING COLLISION----------*/
            charObjectCollision(&Movement,currentMap, &Extra);


            /*--------FUNCTION TO DEAL WITH THE HEALTH BAR CONDITIONS----------*/
            healthDetector(&Movement, Extra.text_inst);

            /*-----BLACK BACKGROUND TO ERASE EVERYTHING BEFORE PUTTING SURFACES------*/
            SDL_FillRect(mainGraphics.screen, &mainGraphics.screen->clip_rect,color1);



            /*----------FRAMES USED TO INDICATE WHICH FRAME OF EACH OBJECT SHOULD BE CONSIDERED--------*/
            incremintFrames(&Movement);


            /*----------------FILL THE STRINGS WITH INFORMATION---------------*/
            sprintf(Extra.text, "%d", Movement.coin_counter);
            sprintf(Extra.text_blue_coin, "%d", Movement.coin_blue_counter);
            sprintf(Extra.text_green_coin, "%d", Movement.coin_green_counter);
            sprintf(Extra.text_moves_char, "%d", Movement.move_counter);
            sprintf(Extra.text_health, "%d", Movement.Health_bar);

            /*---------------DRAWING------------------*/
            finalDrawer(currentMap, &Extra,&currentCharacter, &mainGraphics, &Movement, Movement.fps_cheat, mainGraphics.currentMap_surf );
            drawTexts(&mainGraphics, text_color, text_input_color, &Extra);
            /*-----------FREEING THE MEMORY FROM TEXTS--------*/
            /*---------VERY IMPORTANT TO REDUCE MEMORY CONSUMPTION---------*/
            SDLFreeText(&mainGraphics);



            }/*--------END OF IF MOVEMENT.PLAY------*/

          /*-------------------UPDATE THE SDL WINDOW-------------------*/
            SDL_UpdateWindowSurface(mainGraphics.window);




            /*---------FORSE THE GAME TO BE PLAYED ON THE VALUE OF FPS----------*/
           if (ONESECOND/Movement.fps_cheat>SDL_GetTicks()-start)
                {
                 SDL_Delay((ONESECOND/Movement.fps_cheat)-(SDL_GetTicks()-start));
                }
    }/*-------END OF WHILE RUNNING-------*/

SDL_StopTextInput();

 /*-----------FREEING THE MEMORY FROM SURFACES--------*/
SDLFreeSurfaces(&mainGraphics, &Extra);
Mix_CloseAudio();
SDL_Quit();

    return 0;
}
