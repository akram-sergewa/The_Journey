/*------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------GAME_EVENTS.C------------------------------------------------*/
/*-------THIS FILE HANDLES THE EVENTS DURING GAMEPLAY LIKE PASSING LEVELS AND INTERACTION AND COLLISION WITH OBJECTS------*/
/*------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------FILLS THE MOVEMENT STRUCTURE WITH ALL REQUIRED INFORMATION----------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void movementMaker (MOVEMENT *Movement)
{
    Movement->can_move = TRUE;
    Movement->direction= FALSE;
    Movement->move_holder = FALSE;
    Movement->arrow_right = FALSE;
    Movement->arrow_left = FALSE;
    Movement->arrow_up = FALSE;
    Movement->arrow_down = FALSE;
    Movement->Key_enter = FALSE;
    Movement->frame = FALSE;
    Movement->currentCharacter_frame = FALSE;
    Movement->coin_frame=FALSE;
    Movement->play = FALSE;
    Movement->options = FALSE;
    Movement->ch_chosen = FALSE;
    Movement->Current_Reacher_Map = FALSE;
    Movement->coin_counter = FALSE;
    Movement->move_counter = FALSE;
    Movement->text_count = FALSE;
    Movement->MAP_reached = FALSE;
    Movement->Health_bar = FULLHEALTH;
    Movement->coin_blue_counter = FALSE;
    Movement->coin_green_counter = FALSE;
    Movement->key_room = FALSE;
    Movement->key_Red_room = FALSE;
    Movement->key_Blue_room = FALSE;
    Movement->cloak = FALSE;
    Movement->shield_found = FALSE;
    Movement->spell_counter = FALSE;
    Movement->shield_use = FALSE;
    Movement->wand_found = FALSE;
    Movement->canTeleport = FALSE;

    Movement->char_forest_blocker_axe = FALSE;
    Movement->castle_food = FALSE;
    Movement->call_dialog_surface_blue_hair = FALSE;
    Movement->call_dialog_surface_map_1_char_1 = FALSE;
    Movement->call_dialog_surface_map_1_char_2 = FALSE;
    Movement->call_dialog_surface_map_2_forest_guide = FALSE;
    Movement->call_dialog_surface_map_3_forest_guide = FALSE;
    Movement->sapphire_box_status = FALSE;
    }





/*------------------------------------------------------------------------------------------------------------------------*/
/*--------------CHECKS IF THE POSITION REQUIRES TO MOVE TO ANOTHER MAPS AND EXECUTE THE MOVEMENT TO THE NEW MAP------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
int checkMapNextPrev(MAP Maps[MAPSNUMBER], MAP **currentMap, MOVEMENT *Movement, EXTRA *Extra, SDL_Rect *map_rect, SDL_Rect ch_rect_dest, SDL_Surface **currentMap_surf)
{
    int y = Movement->position_holder_y;
    int x = Movement->position_holder_x;

    if ((*currentMap)->grid[y][x] == NEXT_MAP_CLOSED && Movement->key_room == TRUE)
    {
        (*currentMap)->grid[y][x] = NEXT_MAP;
    }
    if ((*currentMap)->grid[y][x] == NEXT_MAP_CLOSED)
    {
            strcpy(Extra->text_inst, "The door is closed, try to find a key");
    }

    if ((*currentMap)->grid[y][x] == NEXT_MAP)
    {
        if (Movement->MAP_reached==(MAPSNUMBER-1))
        {
            Movement->MAP_reached--;
        }else{
        Movement->MAP_reached++;
        }
        execMapNextPrev(Maps, currentMap, Movement, map_rect, ch_rect_dest, currentMap_surf);
        return NEXT_MAP;
    } else if ((*currentMap)->grid[y][x] == PREVIOUS_MAP)
    {
        Movement->MAP_reached--;
        execMapNextPrev(Maps, currentMap, Movement, map_rect, ch_rect_dest, currentMap_surf);
        Movement->position_holder_y = (*currentMap)->exit[0];
        Movement->position_holder_x = (*currentMap)->exit[1];
        map_rect->x = ch_rect_dest.x - (GRID * Movement->position_holder_x); //sets the position of the map based on the character
        map_rect->y = ch_rect_dest.y - (GRID * Movement->position_holder_y);
        return PREVIOUS_MAP;
    }

return 0;
}


/*--------------------------------------------------------------------------------------*/
/*-------------------------EXECUTE THE MOVEMENT TO THE NEW MAP--------------------------*/
/*--------------------------------------------------------------------------------------*/
void execMapNextPrev(MAP Maps[MAPSNUMBER], MAP **currentMap, MOVEMENT *Movement, SDL_Rect *map_rect, SDL_Rect ch_rect_dest, SDL_Surface **currentMap_surf)
{
   // mapMaker(currentMap); //make map number 0
    *currentMap = &Maps[Movement->MAP_reached];
    Movement->position_holder_y = (*currentMap)->start[0];
    Movement->position_holder_x = (*currentMap)->start[1];
    map_rect->x = ch_rect_dest.x - (GRID * Movement->position_holder_x); //sets the position of the map based on the character
    map_rect->y = ch_rect_dest.y - (GRID * Movement->position_holder_y);
    *currentMap_surf = SDL_LoadBMP((*currentMap)->map_file);

}

/*------------------------------------------------------------------------------------------------------------------------*/
/*----------------------CHECK THE TYPED LINE OF CODE AND CONDUCT A SPECIFIC ACTION BASED ON IT----------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
int checkPlayEvents(MOVEMENT *Movement, MAP **currentMap, EXTRA *Extra, CHARACTER *currentCharacter, MAINGRAPHICS *mainGraphics, MAP Maps[MAPSNUMBER])
{
        //HELP
    int i,j;

    if (!strcmp(Extra->text_string_input,"help"))
    {
        instructionHelp(Extra, (*currentMap));
    }
    int ch_y = Movement->position_holder_y;
    int ch_x = Movement->position_holder_x;


    //Cheat code for faster movement speed.
    if (!strcmp(Extra->text_string_input,"WING(ME)"))
    {
        Movement->fps_cheat = 90;
    }
    if (!strcmp(Extra->text_string_input,"SLOW(ME)"))
    {
        Movement->fps_cheat = 30;
    }

    if (Extra->text_string_input[0] == 't' &&Extra->text_string_input[1] == 'e' &&Extra->text_string_input[2] == 'l' &&Extra->text_string_input[3] == 'e')
    {
        int mapnumber = (int) Extra->text_string_input[4]- (int)'0';

        if( mapnumber < MAPSNUMBER){
            Movement->canTeleport = TRUE;
            Movement->whereTeleport = mapnumber;
        }
        else{
            Movement->canTeleport = FALSE;
            strcpy(Extra->text_inst,"Target map does not exist");
        }
    }
    //Normal BOX
    if ((*currentMap)->grid[ch_y][ch_x] == BOX)
    {
        strcpy(Extra->text_inst,"You can open boxes with the command Action.Open(BOX) and close them with the command Action.Close(BOX)");
        if (!strcmp(Extra->text_string_input,"Action.Open(BOX)"))
           {
                (*currentMap)->boxes[0][EXIST] = FALSE;
                Mix_PlayChannel(-1,Extra->effect_opDoor,0);
           }
        if (!strcmp(Extra->text_string_input,"Action.Close(BOX)"))
           {
                (*currentMap)->boxes[0][EXIST] = TRUE;
                Mix_PlayChannel(-1,Extra->effect_clDoor,0);
           }
    }
/* ---------------------- MAP 0 in the bedroom -------------------------------*/

    if((*currentMap)->level == 0){


        //Window and Bed
        if ((*currentMap)->grid[ch_y][ch_x] == BED || (*currentMap)->grid[ch_y][ch_x] == WINDOW+BED)
        {
            strcpy(Extra->text_inst,"You can make your bed with the command Action.Make(BED)");
            if (!strcmp(Extra->text_string_input,"Action.Make(BED)"))
               {
                    (*currentMap)->bed[0][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_clDoor,0);
               }
        }




        //WINDOW AND BED
        if ((*currentMap)->grid[ch_y][ch_x] == WINDOW || (*currentMap)->grid[ch_y][ch_x] == WINDOW+BED ) // window + bed = 12
        {
            int i;
            int the_window = 0;
            for (i = 0; i<3; i++)
            {
                if ((ch_y-2) == (*currentMap)->windows[i][YVALUE] && ch_x == (*currentMap)->windows[i][XVALUE])
                    the_window = i;
            }
           strcpy(Extra->text_inst,"You can open windows with the command Action.Open(WINDOW) and close them with the command Action.Close(WINDOW)");
            if (!strcmp(Extra->text_string_input,"Action.Open(WINDOW)"))
               {

                    (*currentMap)->windows[the_window][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
               }
            if (!strcmp(Extra->text_string_input,"Action.Close(WINDOW)"))
               {
                    (*currentMap)->windows[the_window][EXIST] = TRUE;
                    Mix_PlayChannel(-1,Extra->effect_clDoor,0);
               }
        }

        //KICHEN AND MAKING FOOD
        if ((*currentMap)->grid[ch_y][ch_x] == KITCHENFOOD)
        {
            strcpy(Extra->text_inst,"you can make food with the command Action.Make(FOOD) and eat food with the command Action.Eat(FOOD)");
            if (!strcmp(Extra->text_string_input,"Action.Eat(FOOD)") && (*currentMap)->kitchen_food[0][EXIST] == TRUE)
               {
                    (*currentMap)->kitchen_food[0][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_eat,0);
                    Movement->Health_bar = 100;
               }
            if (!strcmp(Extra->text_string_input,"Action.Make(FOOD)"))
               {
                    (*currentMap)->kitchen_food[0][EXIST] = TRUE;
                    Mix_PlayChannel(-1,Extra->effect_clDoor,0);
               }
        }


        //THE BOX WITH THE KEY IN THE ROOM
        if ((*currentMap)->grid[ch_y][ch_x] == K_R_BOX)
        {
            if(Movement->key_room == FALSE){
                strcpy(Extra->text_inst,"You can open the box with Action.Open(BOX) and you can take what is inside with Action.Take(OBJECT)");
            }
            if (!strcmp(Extra->text_string_input,"Action.Open(BOX)") && (*currentMap)->K_R_boxes[0][EXIST] == TRUE)
               {
                   if (Movement->key_room == TRUE)
                   {
                        (*currentMap)->K_R_boxes[0][EXIST] = FALSE;
                   } else {
                        (*currentMap)->K_R_boxes[0][EXIST] = HALFTRUE;
                   }
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
               }
            if (!strcmp(Extra->text_string_input,"Action.Take(KEY)")&& (*currentMap)->K_R_boxes[0][EXIST] == HALFTRUE)
               {
                    (*currentMap)->K_R_boxes[0][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    Movement->key_room = TRUE;
               }
            if (!strcmp(Extra->text_string_input,"Action.Close(BOX)")&& ((*currentMap)->K_R_boxes[0][EXIST] == HALFTRUE || (*currentMap)->K_R_boxes[0][EXIST] == FALSE))
               {
                    (*currentMap)->K_R_boxes[0][EXIST] = TRUE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
               }
        }
    }


/* ---------------------- MAP 1 village -------------------------------*/

    if((*currentMap)->level == 1){
       //Empty fake box
        if ((*currentMap)->grid[ch_y][ch_x] == EMPTY_BOX_INFO)
        {
            strcpy(Extra->text_inst,"You can open boxes with the command Action.Open(BOX) and close them with the command Action.Close(BOX)");
            if (!strcmp(Extra->text_string_input,"Action.Open(BOX)"))
               {
                    strcpy(Extra->text_inst,"This box is firmly locked!");
                    Mix_PlayChannel(-1,Extra->map_1_char_I_cant_open,0);
               }

        }

        //map 1 character 1 on the top left
        if ((*currentMap)->grid[ch_y][ch_x] == map_1_char_1_interaction)
        {
            strcpy(Extra->text_inst,"To talk with the character type            Talk()");
            if (!strcmp(Extra->text_string_input,"Talk()"))
               {
                    if(Movement->call_dialog_surface_map_1_char_1 == 3){
                        strcpy(Extra->text_inst,"Don't forget, it is  Action.Cut(PLANT)");
                   }
                    if (Movement->call_dialog_surface_map_1_char_1 != 3){
                        strcpy(Extra->text_inst,"That blue BOX is surrounded by cactus and boulders.");
                        Movement->call_dialog_surface_map_1_char_1 = TRUE;
                        Mix_PlayChannel(-1,Extra->map_1_dialog_blue_box_cactus,0);
                   }
               }
            if (Movement->call_dialog_surface_map_1_char_1 == TRUE){
                 if (!strcmp(Extra->text_string_input,"yes") || !strcmp(Extra->text_string_input,"Yes"))
                    {
                        if (Movement->coin_blue_counter >=1){
                            strcpy(Extra->text_inst,"Maybe you should try Action.Cut(PLANT) on any plants");
                            Movement->coin_blue_counter = Movement->coin_blue_counter-1;
                            Movement->call_dialog_surface_map_1_char_1 = 3;
                        }
                        else{
                            Movement->call_dialog_surface_map_1_char_1 = FALSE;
                            strcpy(Extra->text_inst,"Come to me when you get rich");
                        }

                    }
                if (!strcmp(Extra->text_string_input,"no") || !strcmp(Extra->text_string_input,"No")){
                    Movement->call_dialog_surface_map_1_char_1 = FALSE;
                }
            }
        }


        //map 1 character  2  in the top middle
        if ((*currentMap)->grid[ch_y][ch_x] == map_1_char_2_interaction)
        {
            strcpy(Extra->text_inst,"To talk with the character type            Talk()");
            if (!strcmp(Extra->text_string_input,"Talk()"))
               {
                    if(Movement->call_dialog_surface_map_1_char_2 == 3){
                        strcpy(Extra->text_inst,"I love sapphire but I need money to buy some bread! ");
                   }
                    if (Movement->call_dialog_surface_map_1_char_2 != 3){
                        strcpy(Extra->text_inst,"Westeros has been devastated by the plague. Is this our end?");
                        Mix_PlayChannel(-1,Extra->map_1_dialog_westeros_our_end,0);
                        Movement->call_dialog_surface_map_1_char_2 = TRUE;
                   }
               }
            if (Movement->call_dialog_surface_map_1_char_2 == TRUE){
                 if (!strcmp(Extra->text_string_input,"yes") || !strcmp(Extra->text_string_input,"Yes"))
                    {
                        if (Movement->coin_counter >=1){
                            strcpy(Extra->text_inst,"This sapphire key will be useful in some way I reckon");
                            Movement->coin_counter = Movement->coin_counter-1;
                            Movement->key_Blue_room = TRUE;
                            Movement->call_dialog_surface_map_1_char_2 = 3;
                        }
                        else{
                            Movement->call_dialog_surface_map_1_char_2 = FALSE;
                            strcpy(Extra->text_inst,"Just for one ruby coin!");
                        }

                    }
                if (!strcmp(Extra->text_string_input,"no") || !strcmp(Extra->text_string_input,"No")){
                    strcpy(Extra->text_inst,"Ciao!");
                    Movement->call_dialog_surface_map_1_char_2 = FALSE;
                }
            }
        }

            //sapphire box
        if ((*currentMap)->grid[ch_y][ch_x] == sapphire_box)
        {
            strcpy(Extra->text_inst,"You can open boxes with the command Action.Open(BOX) and close them with the command Action.Close(BOX)");
            if (!strcmp(Extra->text_string_input,"Action.Open(BOX)"))
               {
                    if(Movement->key_Blue_room == FALSE){
                        strcpy(Extra->text_inst,"I don't have a key!");
                        Mix_PlayChannel(-1,Extra->map_1_char_I_cant_open,0);
                    }
                    if(Movement->key_Blue_room == TRUE && Movement->sapphire_box_status != TRUE){
                        int m,k;
                        strcpy(Extra->text_inst,"Treasure!");
                        (*currentMap)->grid[2][1] = 1;
                        Movement->sapphire_box_status = TRUE;
                        for(k = 1, m = 3; k<=4 && m<=6;k++, m++){
                            (*currentMap)->coins_blue[k][0] = m;
                            (*currentMap)->coins_blue[k][1] = 1;
                            (*currentMap)->coins_blue[k][2] = TRUE;
                        }
                        (*currentMap)->coins_blue[5][0] = 2;
                        (*currentMap)->coins_blue[5][1] = 3;
                        (*currentMap)->coins_blue[5][2] = TRUE;
                        (*currentMap)->coins_blue[6][0] = 2;
                        (*currentMap)->coins_blue[6][1] = 4;
                        (*currentMap)->coins_blue[6][2] = TRUE;
                        //Mix_PlayChannel(-1,Extra->map_1_char_I_cant_open,0);
                    }

               }
        }

        //map 1 character on the top right directing the character towards the flower
        if ((*currentMap)->grid[ch_y][ch_x] == map_1_char_3_interaction)
        {

            strcpy(Extra->text_inst,"To talk with the character type            Talk()");
            if (!strcmp(Extra->text_string_input,"Talk()"))
               {
                   strcpy(Extra->text_inst,"I wonder why the flower is surrounded by so many cactus's");
                   Mix_PlayChannel(-1,Extra->map_1_dialog_wonder_so_many_cactuses,0);

               }
        }
        //map 1 vending machine
            if ((*currentMap)->grid[ch_y][ch_x] == map_1_vending_interaction)
            {
                strcpy(Extra->text_inst,"Category A +15 hp      Category B +15 hp    Category C +25 hp");
                if (Extra->text_string_input[0] == 'a' || Extra->text_string_input[0] == 'A'|| Extra->text_string_input[0] == 'b'|| Extra->text_string_input[0] == 'B')
                   {
                        if (Movement->coin_counter >=2){

                            Movement->coin_counter = Movement->coin_counter-2;
                            if (Movement->Health_bar+15 >= 100){
                                Movement->Health_bar = 100;
                                Mix_PlayChannel(-1,Extra->effect_eat,0);
                                strcpy(Extra->text_inst,"Full HP!");
                            }
                            else{
                                Movement->Health_bar = Movement->Health_bar+15;
                                Mix_PlayChannel(-1,Extra->effect_eat,0);
                                strcpy(Extra->text_inst,"+15 HP ");
                            }
                        }
                        else{
                            strcpy(Extra->text_inst,"You need more money!");
                        }
                   }
                if (Extra->text_string_input[0] == 'c' || Extra->text_string_input[0] == 'C'){
                     if (Movement->coin_green_counter >=1){

                            Movement->coin_green_counter = Movement->coin_green_counter-1;
                            if (Movement->Health_bar+25 >= 100){
                                Movement->Health_bar = 100;
                                Mix_PlayChannel(-1,Extra->effect_eat,0);
                                strcpy(Extra->text_inst,"Full HP!");
                            }
                            else{
                                Movement->Health_bar = Movement->Health_bar+25;
                                Mix_PlayChannel(-1,Extra->effect_eat,0);
                                strcpy(Extra->text_inst,"+25 HP ");
                            }
                        }
                        else{
                            strcpy(Extra->text_inst,"You need more money!");
                        }
                }
            }


        //TWO PILES
        if ((*currentMap)->grid[ch_y][ch_x] == PILES)
        {

            if (!strcmp(Extra->text_string_input,"Action.Split(ROCKS)"))
               {
                    (*currentMap)->two_piles[0][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    (*currentMap)->grid[17][13] = 1;
                    (*currentMap)->grid[17][14] = 1;
                    (*currentMap)->grid[18][13] = 1;
                    (*currentMap)->grid[18][14] = 1;
               }
            else if (!strcmp(Extra->text_string_input,"Action.Break(PILES)")){
                strcpy(Extra->text_inst,"This ancient spell is no longer in use, go and ask someone");
            }
            else{
               strcpy(Extra->text_inst,"The bridge is blocked, go and find someone to help you");
            }
        }


        //Cactus blocker
        if ((*currentMap)->grid[ch_y][ch_x] == CACTUS)
        {

            if (!strcmp(Extra->text_string_input,"Action.Cut(PLANT)") || !strcmp(Extra->text_string_input,"Action.Cut"))
               {
                    (*currentMap)->cactus[0][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    (*currentMap)->grid[3][4] = 1;
                    (*currentMap)->grid[4][4] = 1;
                    (*currentMap)->grid[3][5] = 1;
               }else{
               strcpy(Extra->text_inst,"The cactus is blocking the way, go and find someone to help you");
               Mix_PlayChannel(-1,Extra->map_1_char_I_dislike_cactus,0);
               }
        }


        //Cactus in a row blocker
        if ((*currentMap)->grid[ch_y][ch_x] == CACTUS_ROW)
        {

            if (!strcmp(Extra->text_string_input,"Action.Cut(PLANT)") || !strcmp(Extra->text_string_input,"Action.Cut"))
               {
                    (*currentMap)->cactus[1][EXIST] = FALSE;
                    (*currentMap)->cactus[2][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    (*currentMap)->grid[3][19] = 1;
                    (*currentMap)->grid[3][20] = 1;
                    (*currentMap)->grid[2][19] = 1;
                    (*currentMap)->grid[2][20] = 1;
               }else{
                   strcpy(Extra->text_inst,"Oh, cactus!");
                   Mix_PlayChannel(-1,Extra->map_1_char_oh_cactus,0);
               }
        }


        //Flower blocker
        if ((*currentMap)->grid[ch_y][ch_x] == FLOWER )
        {

            if (!strcmp(Extra->text_string_input,"Action.Cut(PLANT)") || !strcmp(Extra->text_string_input,"Action.Cut(FLOWER)") || !strcmp(Extra->text_string_input,"Action.Cut"))
               {
                    (*currentMap)->flower[0][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    (*currentMap)->grid[1][19] = CHAR_FOREST_BLOCKER_AXE;
                    (*currentMap)->grid[0][20] = CHAR_FOREST_BLOCKER_AXE;
               }else{
               strcpy(Extra->text_inst,"Something is underneath this strange flower, I think I can cut it down");
               }
        }

        //BOX with AXE
        if ((*currentMap)->grid[ch_y][ch_x] == CHAR_FOREST_BLOCKER_AXE)
        {
            if(Movement->char_forest_blocker_axe == FALSE){
                strcpy(Extra->text_inst,"A treasure box! Open it and you may take whatever is inside with Action.Take(OBJECT)");
            }
            if (!strcmp(Extra->text_string_input,"Action.Open(BOX)") && (*currentMap)->axe_boxes[0][EXIST] == TRUE)
               {
                   if(Movement->char_forest_blocker_axe == FALSE){
                        strcpy(Extra->text_inst,"A fine AXE! You may want to take it with Action.Take(AXE)");
                   }
                   Mix_PlayChannel(-1,Extra->map_1_char_holy_axe,0);

                   if (Movement->char_forest_blocker_axe == TRUE)
                   {
                        (*currentMap)->axe_boxes[0][EXIST] = FALSE;
                   } else {
                        (*currentMap)->axe_boxes[0][EXIST] = HALFTRUE;
                   }
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
               }
            if (!strcmp(Extra->text_string_input,"Action.Take(AXE)")&& (*currentMap)->axe_boxes[0][EXIST] == HALFTRUE)
               {
                    (*currentMap)->axe_boxes[0][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    Movement->char_forest_blocker_axe = TRUE;
                    strcpy(Extra->text_inst,"");
               }
            if (!strcmp(Extra->text_string_input,"Action.Close(BOX)")&& ((*currentMap)->axe_boxes[0][EXIST] == HALFTRUE || (*currentMap)->axe_boxes[0][EXIST] == FALSE))
               {
                    (*currentMap)->axe_boxes[0][EXIST] = TRUE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
               }
        }

        //THE GIRL WITH BLUE HAIR
        if ((*currentMap)->grid[ch_y][ch_x] == CHAR_BLUE_HAIR)
        {
            strcpy(Extra->text_inst,"To talk with the character type            Talk()");
            if (!strcmp(Extra->text_string_input,"Talk()"))
               {
                    if(Movement->call_dialog_surface_blue_hair == 3){
                        strcpy(Extra->text_inst,"Oh, remember it is  Action.Split(ROCKS)");
                   }
                    if (Movement->call_dialog_surface_blue_hair != 3){
                        Movement->call_dialog_surface_blue_hair = TRUE;
                        Mix_PlayChannel(-1,Extra->map_1_dialog_what_can_i_do,0);
                   }
               }
            if (Movement->call_dialog_surface_blue_hair == TRUE){
                 if (!strcmp(Extra->text_string_input,"yes") || !strcmp(Extra->text_string_input,"Yes"))
                    {
                        if (Movement->coin_counter >=2){
                            strcpy(Extra->text_inst,"You can remove them by Action.Split(ROCKS)");
                            Movement->coin_counter = Movement->coin_counter-2;
                            Movement->call_dialog_surface_blue_hair = 3;
                        }
                        else{
                            Movement->call_dialog_surface_blue_hair = FALSE;
                            strcpy(Extra->text_inst,"Not enough money");
                        }

                    }
                if (!strcmp(Extra->text_string_input,"no") || !strcmp(Extra->text_string_input,"No")){
                    Movement->call_dialog_surface_blue_hair = FALSE;
                }
            }
        }


        //INN entrance
        if ((*currentMap)->grid[ch_y][ch_x] == INN_ENTRANCE)
        {
            Mix_PlayChannel(-1,Extra->map_1_char_Inn_not_use,0);
            strcpy(Extra->text_inst,"This inn is no longer in use");

        }

        //CHAR_FOREST_BLOCKER
        if ((*currentMap)->grid[ch_y][ch_x] == CHAR_FOREST_BLOCKER)
        {
            if(Movement->char_forest_blocker_axe != TRUE){
                strcpy(Extra->text_inst,"Beyond here lies the forest of death! YOU SHALL NOT PASS, without the 'HOLY AXE'");
                Mix_PlayChannel(-1,Extra->map_1_dialog_you_shall_not_pass,0);
            }else if (Movement->char_forest_blocker_axe == TRUE){
                strcpy(Extra->text_inst,"I see you have found the axe. You may now enter by typing Action.Show(AXE).");

            }
            if (  (!strcmp(Extra->text_string_input,"Action.Show(AXE)") || !strcmp(Extra->text_string_input,"Pass")  )&& Movement->char_forest_blocker_axe == TRUE)
               {
                    strcpy(Extra->text_inst,"Let the force be with you!");
                    (*currentMap)->char_forest_blocker[0][2] = FALSE;
                    (*currentMap)->grid[24][27] = 1;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    (*currentMap)->grid[24][28] = 1;

                }

        }
        //teleport way point from home
        if (ch_y == 25 && ch_x == 27)
        {
            if(Movement->char_forest_blocker_axe != TRUE){
                strcpy(Extra->text_inst,"I have no idea how to use it yet.");
            }

            else if (Movement->char_forest_blocker_axe == TRUE){
                if (!strcmp(Extra->text_string_input,"teleport(ME)")){
                    Movement->position_holder_x = 18;
                    Movement->position_holder_y = 0;
                    mainGraphics->map_rect.x = currentCharacter->ch_rect_dest.x - (GRID * Movement->position_holder_x); //sets the position of the map based on the character
                    mainGraphics->map_rect.y = currentCharacter->ch_rect_dest.y - (GRID * Movement->position_holder_y);
                    Mix_PlayChannel(-1,Extra->map_1_char_teleported,0);
                }
                else{
                    strcpy(Extra->text_inst,"This machine could teleport me to desert");
                }

            }

        }

        //teleport way point from flower
        if (ch_y == 0 && ch_x == 18)
        {
            if(Movement->char_forest_blocker_axe != TRUE){
                strcpy(Extra->text_inst,"I can only master this if I have the Holy Axe");
            }

            else if (Movement->char_forest_blocker_axe == TRUE){
                if (!strcmp(Extra->text_string_input,"teleport(ME)")){
                    Movement->position_holder_x = 27;
                    Movement->position_holder_y = 25;
                    mainGraphics->map_rect.x = currentCharacter->ch_rect_dest.x - (GRID * Movement->position_holder_x); //sets the position of the map based on the character
                    mainGraphics->map_rect.y = currentCharacter->ch_rect_dest.y - (GRID * Movement->position_holder_y);
                    Mix_PlayChannel(-1,Extra->map_1_char_teleported,0);
                }
                else{
                    strcpy(Extra->text_inst,"I think this machine could bring me back home, teleport(ME)");
                }

            }

        }
    }

/* ---------------------- MAP 2 in the forest -------------------------------*/

    if((*currentMap)->level == 2){
        //CHAR_FOREST_GUIDE
        if ((*currentMap)->grid[ch_y][ch_x] == CHAR_FOREST_GUIDE)
        {
            if (!strcmp(Extra->text_string_input,"Talk()"))
               {
                   Mix_PlayChannel(-1,Extra->map_2_dialog_guide_greetings,0);
                   strcpy(Extra->text_inst,"The castle has two guards - Matthew and Jacob.  Matthew can be bribed with food to let you pass but to pass Jacob you will need to wear an invisibility cloak.\n\nYou can find these items in the forest before proceeding to the castle.\n\n        Good luck!");
                    if(Movement->call_dialog_surface_map_2_forest_guide == 3){
                        strcpy(Extra->text_inst,"Good luck!");
                   }
                    if (Movement->call_dialog_surface_map_2_forest_guide != 3){
                        Movement->call_dialog_surface_map_2_forest_guide = TRUE;
                        //Mix_PlayChannel(-1,Extra->map_1_dialog_blue_box_cactus,0);
                   }
               }
            if (Movement->call_dialog_surface_map_2_forest_guide == TRUE){
                 if (!strcmp(Extra->text_string_input,"yes") || !strcmp(Extra->text_string_input,"Yes"))
                    {
                        if (Movement->coin_blue_counter >=3){
                            strcpy(Extra->text_inst,"Here is the ruby key.");
                            Movement->coin_blue_counter = Movement->coin_blue_counter-3;
                            Movement->call_dialog_surface_map_2_forest_guide = 3;
                            Movement->key_Red_room = TRUE;
                            Mix_PlayChannel(-1,Extra->map_2_dialog_guide_use_it_wisely,0);
                        }
                        else{
                            Movement->call_dialog_surface_map_2_forest_guide = FALSE;
                            Mix_PlayChannel(-1,Extra->map_2_dialog_guide_go_find_valuable,0);
                            strcpy(Extra->text_inst,"Find some coins in forest");
                        }

                    }
                if (!strcmp(Extra->text_string_input,"no") || !strcmp(Extra->text_string_input,"No")){
                    Movement->call_dialog_surface_map_2_forest_guide = FALSE;
                }
            }
        }
        //BOX with CLOAK
        if ((*currentMap)->grid[ch_y][ch_x] == CLOAK_BOX)
        {
            if(Movement->cloak == FALSE){
                strcpy(Extra->text_inst,"A treasure box! Open it and you may take whatever is inside with Action.Take(OBJECT)");
            }
            if (!strcmp(Extra->text_string_input,"Action.Open(BOX)") && (*currentMap)->cloak_boxes[0][2] == TRUE)
               {

                    if(Movement->key_Red_room == FALSE){
                        strcpy(Extra->text_inst,"You need a ruby key to open it");
                    }
                    if(Movement->key_Red_room == TRUE){
                       strcpy(Extra->text_inst,"An invisibility CLOAK! You may want to take it with Action.Take(CLOAK)");
                       Mix_PlayChannel(-1,Extra->map_2_char_not_opaque,0);
                       if (Movement->cloak == TRUE)
                       {
                            (*currentMap)->cloak_boxes[0][2] = FALSE;
                       } else {
                            (*currentMap)->cloak_boxes[0][2] = HALFTRUE;
                       }
                        Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    }
               }
            if (!strcmp(Extra->text_string_input,"Action.Take(CLOAK)")&& (*currentMap)->cloak_boxes[0][2] == HALFTRUE)
               {
                    (*currentMap)->cloak_boxes[0][2] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    Movement->cloak = TRUE;
                    strcpy(Extra->text_inst,"");
                    Mix_PlayChannel(-1,Extra->map_2_char_cannot_see_cloak,0);
               }
            if (!strcmp(Extra->text_string_input,"Action.Close(BOX)")&& ((*currentMap)->cloak_boxes[0][2] == HALFTRUE || (*currentMap)->cloak_boxes[0][2] == FALSE))
               {
                    (*currentMap)->cloak_boxes[0][2] = TRUE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
               }
        }

        //BOX with CASTLE FOOD
        if ((*currentMap)->grid[ch_y][ch_x] == CASTLEFOOD)
        {
            if(Movement->castle_food == FALSE){
                strcpy(Extra->text_inst,"A treasure box! Open it and you may take whatever is inside with Action.Take(OBJECT)");
            }
            if (!strcmp(Extra->text_string_input,"Action.Open(BOX)") && (*currentMap)->castle_food_boxes[0][EXIST] == TRUE)
               {
                   strcpy(Extra->text_inst,"Food you could use to bribe the guard Matthew! You may want to take it with Action.Take(FOOD)");

                   if (Movement->castle_food == TRUE)
                   {
                        (*currentMap)->castle_food_boxes[0][EXIST] = FALSE;
                   } else {
                        (*currentMap)->castle_food_boxes[0][EXIST] = HALFTRUE;
                   }
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
               }
            if (!strcmp(Extra->text_string_input,"Action.Take(FOOD)")&& (*currentMap)->castle_food_boxes[0][EXIST] == HALFTRUE)
               {
                    (*currentMap)->castle_food_boxes[0][EXIST] = FALSE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                    Movement->castle_food = TRUE;
                    strcpy(Extra->text_inst,"");
                    Mix_PlayChannel(-1,Extra->map_2_char_smells_meaty,0);
               }
            if (!strcmp(Extra->text_string_input,"Action.Close(BOX)")&& ((*currentMap)->castle_food_boxes[0][EXIST] == HALFTRUE || (*currentMap)->castle_food_boxes[0][EXIST] == FALSE))
               {
                    (*currentMap)->castle_food_boxes[0][EXIST] = TRUE;
                    Mix_PlayChannel(-1,Extra->effect_opDoor,0);
               }
        }
    }

/* ---------------------- MAP 3 before castle -------------------------------*/

    if((*currentMap)->level == 3){

        //CHAR_FOREST_GUIDE 2
        if ((*currentMap)->grid[ch_y][ch_x] == CHAR_FOREST_GUIDE2)
        {
            if (!strcmp(Extra->text_string_input,"Talk()"))
               {
                    strcpy(Extra->text_inst,"Welcome to the castle grounds!");
                    Mix_PlayChannel(-1,Extra->map_3_dialog_castle_grounds,0);
                    if(Movement->call_dialog_surface_map_3_forest_guide == 3){
                        strcpy(Extra->text_inst,"Use the following command\nif(MATTHEW) then FOOD else if(JACOB) then CLOAK");

                   }
                    if (Movement->call_dialog_surface_map_3_forest_guide != 3){
                        Movement->call_dialog_surface_map_3_forest_guide = TRUE;
                        //Mix_PlayChannel(-1,Extra->map_1_dialog_blue_box_cactus,0);
                   }
               }
            if (Movement->call_dialog_surface_map_3_forest_guide == TRUE){
                 if (!strcmp(Extra->text_string_input,"yes") || !strcmp(Extra->text_string_input,"Yes"))
                    {
                        if (Movement->coin_green_counter >=2){
                            strcpy(Extra->text_inst,"Either Matthew or Jacob will be guarding the castle entrance but you don't know in advance who it will be. Use the following command to get past depending on who appears:\n\nif(MATTHEW) then FOOD else if(JACOB) then CLOAK");
                            Movement->coin_green_counter = Movement->coin_green_counter-2;
                            Movement->call_dialog_surface_map_3_forest_guide = 3;
                        }
                        else{
                            Movement->call_dialog_surface_map_3_forest_guide = FALSE;
                            strcpy(Extra->text_inst,"I only sell intelligence!");
                            Mix_PlayChannel(-1,Extra->map_3_dialog_sell_intelligence,0);
                        }

                    }
                if (!strcmp(Extra->text_string_input,"no") || !strcmp(Extra->text_string_input,"No")){
                    strcpy(Extra->text_inst,"I promise my information is useful!");
                    Mix_PlayChannel(-1,Extra->map_3_dialog_information_useful,0);
                    Movement->call_dialog_surface_map_3_forest_guide = FALSE;
                }
            }
        }
        //Castle guard entrance
        if ((*currentMap)->grid[ch_y][ch_x] == GUARD_HALT)
        {
            strcpy(Extra->text_inst,"HALT! To enter the castle type the command to get past the guards.");
            if ( ( !strcmp(Extra->text_string_input,"if(MATTHEW) then FOOD else if(JACOB) then CLOAK") || !strcmp(Extra->text_string_input,"Bribe") ) && Movement->castle_food && Movement->cloak)
                {
                    (*currentMap)->grid[22][24] = 1;
                    int x = rand()%2;
                    switch(x){
                    case 0:
                        (*currentMap)->char_matthew[0][EXIST] = TRUE;
                        break;
                    case 1:
                        (*currentMap)->char_jacob[0][EXIST] = TRUE;
                        break;
                    }

                }
        }
    }

/* ---------------------- MAP 4 in castle -------------------------------*/

    if((*currentMap)->level == 4){
        //Shield
        if ((*currentMap)->grid[ch_y][ch_x] == SHIELD )
        {

            if (!strcmp(Extra->text_string_input,"Action.Take(SHIELD)"))
               {
                    (*currentMap)->shield[0][EXIST] = FALSE;
                    (*currentMap)->grid[23][9] = 1;
                    (*currentMap)->grid[22][9] = 1;
                    (*currentMap)->grid[23][10] = 1;
                    Movement->shield_found = TRUE;
               }
        }
        //CHAR_MAID
        if ((*currentMap)->grid[ch_y][ch_x] == CHAR_MAID)
        {
            if (!strcmp(Extra->text_string_input,"Talk()"))
               {
                    strcpy(Extra->text_inst,"Congratulations! You are close to defeating the wizard and freeing the townspeople!\n\nBefore your duel with the wizard you need to find the shield, which is located somewhere in this part of the castle. You can pick it up with the command:\n\nAction.Take(SHIELD)");
            }


        }
        //FIGHTING THE WIZARD
        if ((*currentMap)->grid[ch_y][ch_x] == CHAR_WIZARD)
        {
            if (!strcmp(Extra->text_string_input,"while(FIRING){Action.Use(SHIELD)}") || !strcmp(Extra->text_string_input,"while(FIRING) {Action.Use(SHIELD)}") || !strcmp(Extra->text_string_input,"Block") )
               {
                   Movement->shield_use = TRUE;

                   if(Movement->shield_found == FALSE){
                   strcpy(Extra->text_inst,"You do not have the shield to protect you. Go and find it before attempting to get the wand!");

                   }
                   else{
                   (*currentMap)->grid[11][13] = WAND;
                   (*currentMap)->grid[11][15] = WAND;
                   Mix_PlayChannel(-1,Extra->map_4_dialog_the_world_is_ours,0);
                   strcpy(Extra->text_inst,"You can now move forward and take the wand. Use it to defeat the wizard.\n\nHint: you can use the wand in the same way you used the shield");
                   }
               }

        }
        // wand
        if (Movement->wand_found == TRUE)
        {

            if (!strcmp(Extra->text_string_input,"Action.Use(WAND)") || !strcmp(Extra->text_string_input,"while(FIRING){Action.Use(WAND)}") ||!strcmp(Extra->text_string_input,"while(FIRING) {Action.Use(WAND)}") || !strcmp(Extra->text_string_input,"Attack"))
               {
                   (*currentMap)->char_wizard[0][EXIST] = FALSE;
                   (*currentMap)->spell[0][EXIST] = FALSE;
                   Mix_PlayChannel(-1,Extra->map_4_dialog_nooo,0);
                   strcpy(Extra->text_inst,"Congratulations! You have defeated the wizard and saved the people of Westeros!");
                   for(int i = 11; i < 13; i++){
                        for(int j = 12; j < 17; j++){
                            (*currentMap)->grid[i][j] = 1;
                    }
                   }
                   (*currentMap)->grid[7][14] = 1;
                   (*currentMap)->grid[6][14] = 1;
               }
            else if ((*currentMap)->char_wizard[0][EXIST] == TRUE){
                strcpy(Extra->text_inst,"Take action, you have the wand!! Use its power to defeat the wizard!");
            }
        }
        // wand interacting area
        if ((*currentMap)->grid[ch_y][ch_x] == WAND)
        {
            if (!strcmp(Extra->text_string_input,"Action.Take(WAND)"))
               {
                   Movement->wand_found = TRUE;
                   (*currentMap)->wand[0][EXIST] = FALSE;
                   strcpy(Extra->text_inst,"You cannot defeat me!");
                   Mix_PlayChannel(-1,Extra->map_4_dialog_you_cant_defeat,0);
                   if(ch_x == 13){
                        (*currentMap)->grid[11][12] = 0;
                        (*currentMap)->grid[12][13] = 0;
                   }else if(ch_x == 15){
                        (*currentMap)->grid[11][16] = 0;
                        (*currentMap)->grid[12][15] = 0;
                   }
               }
            else if (Movement->wand_found == FALSE){
                strcpy(Extra->text_inst,"Pick up the wand and fight back!");
            }
        }
    }
        //map 4 vending machine
        if ((*currentMap)->grid[ch_y][ch_x] == map_4_vending_interaction)
        {
            strcpy(Extra->text_inst,"Category A +20 hp      Category B +35 hp ");
            if (Extra->text_string_input[0] == 'a' || Extra->text_string_input[0] == 'A')
               {
                    if (Movement->coin_counter >=3){

                        Movement->coin_counter = Movement->coin_counter-3;
                        if (Movement->Health_bar+15 >= 100){
                            Movement->Health_bar = 100;
                            Mix_PlayChannel(-1,Extra->effect_eat,0);
                            strcpy(Extra->text_inst,"Full HP!");
                        }
                        else{
                            Movement->Health_bar = Movement->Health_bar+20;
                            Mix_PlayChannel(-1,Extra->effect_eat,0);
                            strcpy(Extra->text_inst,"+20 HP ");
                        }
                    }
                    else{
                        strcpy(Extra->text_inst,"You need more money!");
                    }
               }
            if ( Extra->text_string_input[0] == 'b'|| Extra->text_string_input[0] == 'B'){
                 if (Movement->coin_green_counter >=1 && Movement->coin_blue_counter >=1 ){

                        Movement->coin_green_counter = Movement->coin_green_counter-1;
                        Movement->coin_blue_counter = Movement->coin_blue_counter-1;

                        if (Movement->Health_bar+35 >= 100){
                            Movement->Health_bar = 100;
                            Mix_PlayChannel(-1,Extra->effect_eat,0);
                            strcpy(Extra->text_inst,"Full HP!");
                        }
                        else{
                            Movement->Health_bar = Movement->Health_bar+35;
                            Mix_PlayChannel(-1,Extra->effect_eat,0);
                            strcpy(Extra->text_inst,"+35 HP ");
                        }
                    }
                    else{
                        strcpy(Extra->text_inst,"You need more money!");
                    }
            }
        }

/* ---------------------- Maybe not in use -------------------------------*/

    //THE BOX WITH THE BLUE KEY
    if ((*currentMap)->grid[ch_y][ch_x] == K_Blue_BOX)
    {
        strcpy(Extra->text_inst,"you can open the box with Action.Open(BOX) and you can take what is inside with Action.Take(OBJECT)");
        if (!strcmp(Extra->text_string_input,"Action.Open(BOX)") && (*currentMap)->K_Blue_boxes[0][EXIST] == TRUE)
           {
               if (Movement->key_Blue_room == TRUE)
               {
                    (*currentMap)->K_Blue_boxes[0][EXIST] = FALSE;
               } else {
                    (*currentMap)->K_Blue_boxes[0][EXIST] = HALFTRUE;
               }
                Mix_PlayChannel(-1,Extra->effect_opDoor,0);
           }
        if (!strcmp(Extra->text_string_input,"Action.Take(KEY)")&& (*currentMap)->K_Blue_boxes[0][EXIST] == HALFTRUE)
           {
                (*currentMap)->K_Blue_boxes[0][EXIST] = FALSE;
                Mix_PlayChannel(-1,Extra->effect_opDoor,0);
                Movement->key_Blue_room = TRUE;
           }
        if (!strcmp(Extra->text_string_input,"Action.Close(BOX)")&& ((*currentMap)->K_Blue_boxes[0][EXIST] == HALFTRUE || (*currentMap)->K_Blue_boxes[0][EXIST] == FALSE))
           {
                (*currentMap)->K_Blue_boxes[0][EXIST] = TRUE;
                Mix_PlayChannel(-1,Extra->effect_opDoor,0);
           }
    }

/*-------------------------------------More Actions, Only sound effects--------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------*/
if (!strcmp(Extra->text_string_input,"Action(SNEEZE)"))
    {Mix_PlayChannel(-1,Extra->effect_sneeze,0);}

if (!strcmp(Extra->text_string_input,"Action(BURP)"))
    {Mix_PlayChannel(-1,Extra->effect_burp,0);}

if (!strcmp(Extra->text_string_input,"Action.Play(GUITAR)"))
    {Extra->Guitar_active = TRUE;
    Mix_PlayChannel(-1,Extra->effect_guitar,0);}

if (!strcmp(Extra->text_string_input,"Action.Sing(LET_HER_GO)"))
    {Extra->LetHerGo_active = TRUE;
    strcpy(Extra->text_inst,"you only need the light when it's burning low Only miss the sun when it starts to snow Only know you love her when you let her go                               LET HER GO            PASSENGER");
    Mix_PlayChannel(-1,Extra->effect_lethergo,0);}

if (!strcmp(Extra->text_string_input,"position"))
    {sprintf(Extra->text_inst,"y=%d   x=%d    map=%d",Movement->position_holder_y,Movement->position_holder_x,Movement->MAP_reached);      }

    //Load and Save Game, limit is set to 10
    char file_name[10];
if (getFilename(file_name, Extra->text_string_input) == LOADGAME)
    {
   FILE * file = fopen(file_name, "rb");
   if (loadGame(file, Movement,Maps,currentCharacter))
       {
         sprintf(Extra->text_inst,"the game is loaded from the file %s",file_name);
         SDL_Delay(500);//short delay to give the impression of loading
         //printf("\nThe Character is %d", Movement->ch_chosen);
         charMaker(currentCharacter, Movement->ch_chosen,mainGraphics->screen);
         printf("\ncharacter %d\n", Movement->ch_chosen);
         *currentMap = &Maps[Movement->MAP_reached];
         mainGraphics->map_rect.x = currentCharacter->ch_rect_dest.x - (GRID * Movement->position_holder_x); //sets the position of the map based on the character
         mainGraphics->map_rect.y = currentCharacter->ch_rect_dest.y - (GRID * Movement->position_holder_y);

       }
    }else if (getFilename(file_name, Extra->text_string_input) == SAVEGAME)
    {
   FILE * file = fopen(file_name, "wb");
   if (saveGame(file, Movement,Maps,currentCharacter))
       {
         sprintf(Extra->text_inst,"the game is save in the file %s",file_name);
                  printf("\nThe Character is %d", Movement->ch_chosen);

       }
    }else if (getFilename(file_name, Extra->text_string_input) == MOREMAXFILE){
       strcpy(Extra->text_inst,"The name of the file should not be larger than 10 letters");

    }

    return 0;
}




int charObjectCollision(MOVEMENT *Movement,MAP* currentMap, EXTRA *Extra)
{
    int y = Movement->position_holder_y;
    int x = Movement->position_holder_x;


    for (int i = 0; i<MAXCOIN; i++)
    {
       if (Movement->position_holder_y == currentMap->coins[i][YVALUE] && Movement->position_holder_x == currentMap->coins[i][XVALUE])
       {
        if (currentMap->coins[i][EXIST] == TRUE){
        currentMap->coins[i][EXIST] = FALSE;
        Movement->coin_counter++;
        Mix_PlayChannel(-1,Extra->effect_coin,0);
           }


       }

       if (Movement->position_holder_y == currentMap->coins_blue[i][YVALUE] && Movement->position_holder_x == currentMap->coins_blue[i][XVALUE])
       {
        if (currentMap->coins_blue[i][EXIST] == TRUE){
        currentMap->coins_blue[i][EXIST] = FALSE;
        Movement->coin_blue_counter++;
        Mix_PlayChannel(-1,Extra->effect_coin,0);
           }

       }


       if (Movement->position_holder_y == currentMap->coins_green[i][YVALUE] && Movement->position_holder_x == currentMap->coins_green[i][XVALUE])
       {
        if (currentMap->coins_green[i][EXIST] == TRUE){
        currentMap->coins_green[i][EXIST] = FALSE;
        Movement->coin_green_counter++;
        Mix_PlayChannel(-1,Extra->effect_coin,0);
           }
       }

    }


if (currentMap->mushroom[0][YVALUE] == y && currentMap->mushroom[0][XVALUE] == x)
{
    currentMap->mushroom[0][EXIST] = FALSE;
    Movement->Health_bar = 100;
}


 if(currentMap->level == 3 && (Movement->position_holder_x == 23 || Movement->position_holder_x == 24) && Movement->position_holder_y == 21)
            {
                if (currentMap->char_matthew[0][EXIST] == TRUE ||currentMap->char_jacob[0][EXIST] == TRUE)
                    strcpy(Extra->text_inst,"You've successfully duped the guards! Well done. You can now enter the castle.");
                else
                    strcpy(Extra->text_inst,"HALT! To enter the castle type the command to get past the guards.");
            }
            if(currentMap->level == 4 && currentMap->grid[Movement->position_holder_y][Movement->position_holder_x] == CHAR_WIZARD)
            {
                currentMap->spell[0][EXIST] = TRUE;
                if(!Movement->shield_use){
                strcpy(Extra->text_inst,"The wizard is firing at you! Hold up your shield to protect yourself until he stops. Use command:\n while(FIRING)\n{Action.Use(SHIELD)}");
                }
            }


return 0;
}


/*------------------------------------------------------------------------------------------------------------------------*/
/*--------------------SPECIAL FUNCTION FOR FAST MOVEMENT TO DIFFERENT MAPS DURING PLAYING  (FOR DEBUG)--------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void teleport(MAP Maps[MAPSNUMBER], MAP **currentMap, MOVEMENT *Movement,  CHARACTER *currentCharacter, MAINGRAPHICS *mainGraphics, SDL_Surface **currentMap_surf, int teleMap)
{
    *currentMap = &Maps[teleMap];
    Movement->position_holder_y = (*currentMap)->start[0];
    Movement->position_holder_x = (*currentMap)->start[1];
    mainGraphics->map_rect.x = currentCharacter->ch_rect_dest.x - (GRID * Movement->position_holder_x); //sets the position of the map based on the character
    mainGraphics->map_rect.y = currentCharacter->ch_rect_dest.y - (GRID * Movement->position_holder_y);
    Movement->MAP_reached = teleMap;
    *currentMap_surf = SDL_LoadBMP((*currentMap)->map_file);

}

