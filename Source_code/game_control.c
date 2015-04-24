/*------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------GAME_CONTROL.C------------------------------------------------------*/
/*---------------------------THIS FILE CONTROLS STARTING THE GAME AND THE MAIN PAGE AND OPTIONS---------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------RESTART ALL THE VALUES TO START A NEW GAME-------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void restartGame(MAP Maps[MAPSNUMBER], MAP **currentMap, MOVEMENT *Movement, CHARACTER *currentCharacter, MAINGRAPHICS *mainGraphics, SDL_Surface **currentMap_surf, EXTRA* Extra)
{
    mapMaker(Maps);
    int characterHolder = Movement->ch_chosen;
    charMaker(currentCharacter,Movement->ch_chosen, mainGraphics->screen); //make player before loading Movements
    movementMaker(Movement);
    Movement->ch_chosen = characterHolder;
    *currentMap = &Maps[0];
    Movement->play = TRUE;
    if (DEBUG)
    {
        Movement->fps_cheat= 60;
        Movement->key_room = TRUE;
        Movement->key_Red_room= TRUE;
        Movement->char_forest_blocker_axe = TRUE;
        Movement->cloak = TRUE;
        Movement->castle_food = TRUE;
        Movement->coin_counter = 100;
        Movement->coin_blue_counter = 100;
        Movement->coin_green_counter = 100;
    }
    else{
        Movement->fps_cheat = 30;
        //Quest items
        Movement->key_room = FALSE;
        Movement->key_Red_room = FALSE;
        Movement->key_Blue_room = FALSE;
        Movement->char_forest_blocker_axe = FALSE;
        Movement->cloak = FALSE;
        Movement->castle_food = FALSE;
        Movement->shield_found = FALSE;
        Movement->wand_found = FALSE;
        Movement->call_dialog_surface_blue_hair = FALSE;
        Movement->call_dialog_surface_map_1_char_1 = FALSE;
        Movement->call_dialog_surface_map_1_char_2 = FALSE;
        Movement->call_dialog_surface_map_2_forest_guide = FALSE;
        Movement->call_dialog_surface_map_3_forest_guide = FALSE;
        Movement->sapphire_box_status = FALSE;
        Movement->game_over = FALSE;
    }


    Movement->position_holder_y = (*currentMap)->start[0];
    Movement->position_holder_x = (*currentMap)->start[1];
    mainGraphics->map_rect.x = currentCharacter->ch_rect_dest.x - (GRID * Movement->position_holder_x); //sets the position of the map based on the character
    mainGraphics->map_rect.y = currentCharacter->ch_rect_dest.y - (GRID * Movement->position_holder_y);
    *currentMap_surf = SDL_LoadBMP((*currentMap)->map_file);
    instructionHelp(Extra, *currentMap);
}



/*------------------------------------------------------------------------------------------------------------------------*/
/*-----------------THE TRACKER FOR THE CURSOR FOR MAIN PAGE TO TRACK WHICH BUTTON ON THE SCREEN IS CLICKED----------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void mainPageActivity(CURSOR *Cursor, int *play, int *options, int* running)
{
    if (Cursor->button)
    {
            if (Cursor->x >135 && Cursor->x< 240 && Cursor->y > 280 && Cursor->y <320)
                {
                    *play = 1;
                }
            if (Cursor->x  >95 && Cursor->x < 280 && Cursor->y > 350 && Cursor->y <390)
                {
                    *options = 1;
                }
            if (Cursor->x >140 && Cursor->x< 263 && Cursor->y > 420 && Cursor->y <452)
                {
                    //SDL_Quit();
                    *running = 0;
                }
    }
}

/*------------------------------------------------------------------------------------------------------------------------*/
/*----------------THE TRACKER FOR THE CURSOR FOR OPTIONS PAGE TO TRACK WHICH BUTTON ON THE SCREEN IS CLICKED--------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void mainOptionsActivity(CURSOR *Cursor, MOVEMENT *Movement, int* running)
{
    if (Cursor->button)
    {
                 if (Cursor->x >50 && Cursor->x< 240 && Cursor->y > 395 && Cursor->y  <430)
                        {
                              Movement->options = 0;
                        }
                if (Cursor->x >97 && Cursor->x< 196 && Cursor->y  > 460 && Cursor->y  <496)
                        {
                           // SDL_Quit();
                           *running = 0;

                        }
                if (Cursor->x >80 && Cursor->x< 193 && Cursor->y  > 240 && Cursor->y  <353)
                        {
                            Movement->ch_chosen = 0;
                            Movement->options = 0;

                        }
                if (Cursor->x >255 && Cursor->x< 368 && Cursor->y  > 240 && Cursor->y  <353)
                        {
                            Movement->ch_chosen = 1;
                            Movement->options = 0;
                        }
                if (Cursor->x >434 && Cursor->x< 545 && Cursor->y  > 240 && Cursor->y  <353)
                        {
                            Movement->ch_chosen = 2;
                            Movement->options = 0;
                        }
                if (Cursor->x >620 && Cursor->x< 735 && Cursor->y  > 240 && Cursor->y  <353)
                        {
                            Movement->ch_chosen = 3;
                            Movement->options = 0;
                        }

    }
}



/*--------------------------------------------------------------------------------------*/
/*--------------CHECKS IF THERE IS A PRESSED ARROW AND CALL CHECKMOVEABLE---------------*/
/*--------------------------------------------------------------------------------------*/
void checkMoveKey(CHARACTER *currentCharacter, MAP *currentMap, MOVEMENT *Movement, char* text_inst)
{
  if (Movement->arrow_right)
        {
            if (Movement->can_move)
            Movement->direction = RIGHT;
            if (checkMoveable(currentCharacter, currentMap, Movement))
            {
                (Movement->move_counter)++;
                strcpy(text_inst,"");
            }else if (Movement->can_move)
                    Movement->currentCharacter_frame = currentCharacter->mv_right[0];//if the character can't move to the new position this line will change the direction that the character is facing
        }

        if (Movement->arrow_left)
        {
            if (Movement->can_move)
            Movement->direction = LEFT;
            if (checkMoveable(currentCharacter, currentMap, Movement))
            {
                (Movement->move_counter)++;
                strcpy(text_inst,"");
            }else if (Movement->can_move)
                    Movement->currentCharacter_frame = currentCharacter->mv_left[0];

        }


        if (Movement->arrow_up)
        {
            if (Movement->can_move)
            Movement->direction = UP;
            if (checkMoveable(currentCharacter, currentMap, Movement))
            {
                (Movement->move_counter)++;
                strcpy(text_inst,"");
            }else if (Movement->can_move)
                    Movement->currentCharacter_frame = currentCharacter->mv_up[0];
        }

        if (Movement->arrow_down)
        {
            if (Movement->can_move)
            Movement->direction = DOWN;
            if (checkMoveable(currentCharacter, currentMap, Movement))
            {
                (Movement->move_counter)++;
                strcpy(text_inst,"");
            }else if (Movement->can_move)
                    Movement->currentCharacter_frame = currentCharacter->mv_down[0];
        }

}






/*-----------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------SDL FUNCTION----------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------*/
void SDLEvents(SDL_Event *event,CURSOR *Cursor,MOVEMENT *Movement, char *text_string_input, int *running)
{
switch (event->type)
            {
            case SDL_QUIT:
                (*running)=FALSE;
                break;
            //text input

            case SDL_TEXTINPUT:
                if (Movement->text_count<INPUT_TEXT_SIZE)
                {
                   text_string_input[Movement->text_count++] = event->text.text[0];
                text_string_input[Movement->text_count] = '\0';
                }
            break;



            case SDL_MOUSEBUTTONDOWN:
                Cursor->x  = event->button.x;
                Cursor->y  = event->button.y;
                Cursor->button  = 1;
                break;

            case SDL_MOUSEBUTTONUP:
                Cursor->button  = 0;
                break;

            case SDL_KEYDOWN:
                switch (event->key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    //SDL_Quit();
                    Movement->play=0;
                    break;

                    case SDLK_BACKSPACE: //event backspace to delete one letter
                    if (Movement->text_count>0)
                    text_string_input[--Movement->text_count] = '\0';
                    break;

                    case SDLK_RIGHT:
                        Movement->arrow_right = 1;
                    break;

                    case SDLK_LEFT:
                        Movement->arrow_left = 1;
                    break;

                    case SDLK_UP:
                        Movement->arrow_up = 1;
                    break;

                    case SDLK_DOWN:

                        Movement->arrow_down = 1;
                    break;

                    case SDLK_RETURN:
                        Movement->Key_enter = 1;
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event->key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        Movement->arrow_right = 0;
                    break;

                    case SDLK_LEFT:
                        Movement->arrow_left = 0;
                    break;

                    case SDLK_UP:
                        Movement->arrow_up = 0;
                    break;

                    case SDLK_DOWN:
                        Movement->arrow_down = 0;
                    break;
                    case SDLK_RETURN:
                        Movement->Key_enter = 0;
                    break;
                }


                break;

            }//end of switch (event.type)}
}






/*------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------DEALS WITH THE HEALTH BAR CONDITIONS-------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void healthDetector(MOVEMENT *Movement, char * text_inst)
{
         //Health bar
        if (!(Movement->frame%150))
        {
            Movement->Health_bar--;
        }

        if (Movement->Health_bar == 0){
            Movement->game_over = TRUE;
            strcpy(text_inst, "YOUR HEALTH HAS REACHED ZERO, THE GAME WILL RESTART");
        }
        else if (Movement->Health_bar < 5)
        {
         strcpy(text_inst, "YOUR HEALTH IS IN CRITICAL SITUATION");
        }

}




