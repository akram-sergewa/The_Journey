/*------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------GAME_GRAPHICS.C-----------------------------------------------------*/
/*-------------------THIS FILE CONTAINS THE GRAPHICS INITIALIZERS AND MAIN GRAPHICS AND FINAL DRAWING---------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------INITIALIZE SDL, TTF AND MIXER----------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void graphInit ()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096); //initialize audio
}


/*------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------INITIALIZE MAINGRAPHICS STRUCUTRE----------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void mainGraphicsMaker(MAINGRAPHICS *mainGraphics)
{
    /*-----SET 0 TO SDL_WINDOW_FULLSCREEN FOR PLAYING IN FULLSCREEN---*/
mainGraphics->window = SDL_CreateWindow("THE JOURNEY", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HIGHT, 0);
mainGraphics->screen = SDL_GetWindowSurface(mainGraphics->window);
mainGraphics->screen_cover = SDL_LoadBMP("image/cover.bmp");
SDL_SetColorKey(mainGraphics->screen_cover,SDL_TRUE,0xff0000);


mainGraphics->main_surf = SDL_LoadBMP("image/main_image.bmp");
mainGraphics->options_surf = SDL_LoadBMP("image/main_options.bmp");

mainGraphics->font=TTF_OpenFont("font/ARLRDBD.TTF",18);
mainGraphics->font_input=TTF_OpenFont("font/LSANSDI.TTF",20);
}




/*------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------LOAD THE BMP FOR EACH CHARACTER AND SET THE RECTs IN THIS FUNCTION---------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void charMaker(CHARACTER* Character, int ch_chosen, SDL_Surface *screen)
{
    Character->id = 1;
   // strcpy(Character->ch_file, "char00.bmp");

        if (ch_chosen == 0){
    Character->currentCharacter_surf = SDL_LoadBMP("image/char00.bmp"); //strcpy(Character->ch_file, "char00.bmp");
        } else if (ch_chosen == 1){
Character->currentCharacter_surf = SDL_LoadBMP("image/char01.bmp");
       } else if (ch_chosen == 2){
Character->currentCharacter_surf = SDL_LoadBMP("image/char02.bmp");
        } else if (ch_chosen == 3){
Character->currentCharacter_surf = SDL_LoadBMP("image/char03.bmp");
        }

 SDL_SetColorKey(Character->currentCharacter_surf,SDL_TRUE,0xff0000);
 Character->ch_rect_dest.x = 300;
Character->ch_rect_dest.y = 200;



    int counter = 0;
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<3 ; j++)
        {
            Character->ch_src_rect[counter].x = j*32;
            Character->ch_src_rect[counter].y = i*32;
            Character->ch_src_rect[counter].w = 27;
            Character->ch_src_rect[counter].h = 32;
            counter++;
        }
    }

    Character->mv_down[0]=0;
    Character->mv_down[1]=2;
    Character->mv_left[0]=3;
    Character->mv_left[1]=5;
    Character->mv_right[0]=6;
    Character->mv_right[1]=8;
    Character->mv_up[0]=9;
    Character->mv_up[1]=11;

}



/*-----------------------------------------------------------------------------------------------------------------*/
/*--------------------------------GIVE VALUES TO THE CONTENTS OF EXTRA STRUCTURE-----------------------------------*/
/*---------------THE SURFACES WILL BE FILLED WITH BMPs AND THE BACKGROUNDS COLORS WILL BE REMOVED------------------*/
/*----------------------------------THE MIX WILL BE FILLED WITH WAV AUDIO FILES------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------*/
void extraMaker(EXTRA *Extra, SDL_Surface *screen)
{
Extra->Box_surf = SDL_LoadBMP("image/box.bmp");
Extra->OBox_surf = SDL_LoadBMP("image/obox.bmp");
Extra->CWindow_surf = SDL_LoadBMP("image/cwindow.bmp");
Extra->Kitchen_food_surf = SDL_LoadBMP("image/kitchenfood.bmp");
Extra->Bed_surf = SDL_LoadBMP("image/bed.bmp");
Extra->Guitar_surf = SDL_LoadBMP("image/guitar.bmp");
Extra->coin01_surf = SDL_LoadBMP("image/coin.bmp");
SDL_SetColorKey(Extra->coin01_surf,SDL_TRUE,0x000000);

Extra->coin_blue_surf = SDL_LoadBMP("image/coin_blue.bmp");
SDL_SetColorKey(Extra->coin_blue_surf,SDL_TRUE,0x000000);

Extra->coin_green_surf = SDL_LoadBMP("image/coin_green.bmp");
SDL_SetColorKey(Extra->coin_green_surf,SDL_TRUE,0x000000);

//Extra->mushroom_surf = SDL_LoadBMP("mushroom.bmp");
//SDL_SetColorKey(Extra->mushroom_surf,SDL_TRUE,0x000000);

Extra->two_piles_surf = SDL_LoadBMP("image/two_piles_stone.bmp");
SDL_SetColorKey(Extra->two_piles_surf,SDL_TRUE,0xffffff);

Extra->Key_surf = SDL_LoadBMP("image/key.bmp");
SDL_SetColorKey(Extra->Key_surf,SDL_TRUE,0x000000);

Extra->Key_red_surf = SDL_LoadBMP("image/key_red.bmp");
SDL_SetColorKey(Extra->Key_red_surf,SDL_TRUE,0x000000);

Extra->Key_blue_surf = SDL_LoadBMP("image/key_blue.bmp");
SDL_SetColorKey(Extra->Key_blue_surf,SDL_TRUE,0x000000);

Extra->object_blue_opened_box_surf = SDL_LoadBMP("image/blue_opened_box.bmp");

Extra->char_blue_hair_surf = SDL_LoadBMP("image/char_blue_hair.bmp");
SDL_SetColorKey(Extra->char_blue_hair_surf,SDL_TRUE,0xff0000);

Extra->dialog_box_blue_hair_surf = SDL_LoadBMP("image/dialog_box_blue_hair.bmp");
SDL_SetColorKey(Extra->dialog_box_blue_hair_surf,SDL_TRUE,0x000000);

Extra->dialog_box_map_1_char_1_surf = SDL_LoadBMP("image/dialog_box_map_1_char_1.bmp");
SDL_SetColorKey(Extra->dialog_box_map_1_char_1_surf,SDL_TRUE,0x000000);

Extra->dialog_box_map_1_char_2_surf = SDL_LoadBMP("image/dialog_box_map_1_char_2.bmp");
SDL_SetColorKey(Extra->dialog_box_map_1_char_2_surf,SDL_TRUE,0x00ff00);

Extra->object_map_1_vending_machine_surf = SDL_LoadBMP("image/map_1_vending_machine.bmp");
SDL_SetColorKey(Extra->object_map_1_vending_machine_surf,SDL_TRUE,0x0000ff);

Extra->char_forest_blocker_surf = SDL_LoadBMP("image/path_blocker.bmp");
SDL_SetColorKey(Extra->char_forest_blocker_surf,SDL_TRUE,0x000000);



Extra->char_forest_blocker_axe_surf = SDL_LoadBMP("image/axe.bmp");
SDL_SetColorKey(Extra->char_forest_blocker_axe_surf,SDL_TRUE,0x000000);

Extra->object_map_1_inn_surf = SDL_LoadBMP("image/broken_inn.bmp");
SDL_SetColorKey(Extra->object_map_1_inn_surf,SDL_TRUE,0xff0000);

Extra->object_map_1_bar_surf = SDL_LoadBMP("image/bar_closed.bmp");
SDL_SetColorKey(Extra->object_map_1_bar_surf,SDL_TRUE,0xff0000);

Extra->char_forest_guide_surf = SDL_LoadBMP("image/char_forestguide.bmp");
SDL_SetColorKey(Extra->char_forest_guide_surf,SDL_TRUE,0xff0000);

Extra->dialog_box_map_2_forest_guide_surf= SDL_LoadBMP("image/dialog_box_map_2_guide.bmp");
SDL_SetColorKey(Extra->dialog_box_map_2_forest_guide_surf,SDL_TRUE,0x00ff00);

Extra->char_matthew_surf = SDL_LoadBMP("image/guard.bmp");
SDL_SetColorKey(Extra->char_matthew_surf,SDL_TRUE,0xff0000);

Extra->char_jacob_surf = SDL_LoadBMP("image/guard2.bmp");
SDL_SetColorKey(Extra->char_jacob_surf,SDL_TRUE,0xff0000);

Extra->char_forest_guide_surf2 = SDL_LoadBMP("image/char_forestguide2.bmp");
SDL_SetColorKey(Extra->char_forest_guide_surf2,SDL_TRUE,0xffffff);

Extra->dialog_box_map_3_castle_guide_surf= SDL_LoadBMP("image/dialog_box_map_3_guide.bmp");
SDL_SetColorKey(Extra->dialog_box_map_3_castle_guide_surf,SDL_TRUE,0x0000ff);

Extra->char_maid_surf = SDL_LoadBMP("image/maid.bmp");
SDL_SetColorKey(Extra->char_maid_surf,SDL_TRUE,0xff0000);

Extra->char_wizard_surf = SDL_LoadBMP("image/char_wizard.bmp");
SDL_SetColorKey(Extra->char_wizard_surf,SDL_TRUE,0xff0000);

Extra->shield_surf = SDL_LoadBMP("image/shield.bmp");
SDL_SetColorKey(Extra->shield_surf,SDL_TRUE,0xff0000);

Extra->cloak_surf = SDL_LoadBMP("image/cloak.bmp");
SDL_SetColorKey(Extra->cloak_surf,SDL_TRUE,0x000000);

Extra->cactus_surf = SDL_LoadBMP("image/cactus.bmp");
SDL_SetColorKey(Extra->cactus_surf,SDL_TRUE,0x000000);

Extra->castle_food_surf = SDL_LoadBMP("image/drumstick.bmp");
SDL_SetColorKey(Extra->castle_food_surf,SDL_TRUE,0x000000);

Extra->object_map_4_vending_machine_surf = SDL_LoadBMP("image/map_4_vending_machine.bmp");
SDL_SetColorKey(Extra->object_map_4_vending_machine_surf,SDL_TRUE,0xff0080);

Extra->spell_surf3 = SDL_LoadBMP("image/spell5.bmp");
SDL_SetColorKey(Extra->spell_surf3,SDL_TRUE,0xff0000);

Extra->spell_surf4 = SDL_LoadBMP("image/spell4.bmp");
SDL_SetColorKey(Extra->spell_surf4,SDL_TRUE,0xff0000);

Extra->spell_surf5 = SDL_LoadBMP("image/spell3.bmp");
SDL_SetColorKey(Extra->spell_surf5,SDL_TRUE,0xff0000);

Extra->spell_surf6 = SDL_LoadBMP("image/spell2.bmp");
SDL_SetColorKey(Extra->spell_surf6,SDL_TRUE,0xff0000);

Extra->spell_surf7 = SDL_LoadBMP("image/spell1.bmp");
SDL_SetColorKey(Extra->spell_surf7,SDL_TRUE,0xff0000);

Extra->wand_surf = SDL_LoadBMP("image/wand.bmp");
SDL_SetColorKey(Extra->wand_surf,SDL_TRUE,0xff0000);

Extra->flower_surf = SDL_LoadBMP("image/flower.bmp");

Extra->game_over = SDL_LoadBMP("image/wasted.bmp");


Extra->Guitar_active = FALSE;
Extra->Guitar_counter = 0;
Extra->LetHerGo_active = FALSE;
Extra->LetHerGo_counter = 0;

//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
Extra->music = Mix_LoadWAV("sound/music.wav");
Extra->effect_opDoor = Mix_LoadWAV("sound/door-open.wav");
Extra->effect_clDoor = Mix_LoadWAV("sound/door-close.wav");
Extra->effect_coin= Mix_LoadWAV("sound/ding.wav");
Extra->effect_burp= Mix_LoadWAV("sound/burp.wav");
Extra->effect_eat= Mix_LoadWAV("sound/crunching.wav");
Extra->effect_sneeze= Mix_LoadWAV("sound/sneezing.wav");
Extra->effect_guitar = Mix_LoadWAV("sound/guitar.wav");
Extra->effect_lethergo = Mix_LoadWAV("sound/lethergo.wav");
//map 1 conversations
Extra->map_1_dialog_show_me_you_got = Mix_LoadWAV("sound/show_me_what_you_have_got.wav");
Extra->map_1_dialog_westeros_our_end = Mix_LoadWAV("sound/westeros_our_end.wav");
Extra->map_1_dialog_what_can_i_do = Mix_LoadWAV("sound/what_can_i_do_for_you.wav");
Extra->map_1_dialog_wonder_so_many_cactuses = Mix_LoadWAV("sound/wonder_so_many_cactuses.wav");
Extra->map_1_dialog_you_shall_not_pass = Mix_LoadWAV("sound/you_shall_not_pass.wav");
Extra->map_1_dialog_blue_box_cactus = Mix_LoadWAV("sound/blue_box_cactus.wav");
Extra->map_1_char_cactus_is_blocking = Mix_LoadWAV("sound/cactus_is_blocking.wav");
Extra->map_1_char_holy_axe = Mix_LoadWAV("sound/holy_axe.wav");
Extra->map_1_char_I_cant_open = Mix_LoadWAV("sound/I_cant_open.wav");
Extra->map_1_char_Inn_not_use = Mix_LoadWAV("sound/Inn_not_use.wav");
Extra->map_1_char_oh_cactus = Mix_LoadWAV("sound/oh_cactus.wav");
Extra->map_1_char_I_dislike_cactus = Mix_LoadWAV("sound/dislike_cactus.wav");
Extra->map_1_char_teleported = Mix_LoadWAV("sound/teleported.wav");
// map 2 3 4 dialogues
Extra->map_2_dialog_guide_greetings = Mix_LoadWAV("sound/greetings.wav");
Extra->map_2_dialog_guide_use_it_wisely = Mix_LoadWAV("sound/use_it_wisely.wav");
Extra->map_2_dialog_guide_go_find_valuable = Mix_LoadWAV("sound/go_find_valuable.wav");
Extra->map_2_char_cannot_see_cloak = Mix_LoadWAV("sound/cannot_see_but_in_bag.wav");
Extra->map_2_char_not_opaque = Mix_LoadWAV("sound/not_opaque.wav");
Extra->map_2_char_smells_meaty = Mix_LoadWAV("sound/smells_meaty.wav");
Extra->map_3_dialog_castle_grounds = Mix_LoadWAV("sound/welcome_to_castle_grounds.wav");
Extra->map_3_dialog_information_useful = Mix_LoadWAV("sound/information_useful.wav");
Extra->map_3_dialog_sell_intelligence = Mix_LoadWAV("sound/sell_intelligence.wav");
Extra->map_4_dialog_you_cant_defeat = Mix_LoadWAV("sound/you_cant_defeat_me.wav");
Extra->map_4_dialog_the_world_is_ours = Mix_LoadWAV("sound/the_world_is_ours.wav");
Extra->map_4_dialog_nooo = Mix_LoadWAV("sound/nooo.wav");



SDL_SetColorKey(Extra->Guitar_surf,SDL_TRUE,0xff0000);




//strcpy(Extra->coin_file, "coin.bmp");
for (int i = 0; i<9; i++)
{
    Extra->coin_src_rect[i].x = i*33;
    Extra->coin_src_rect[i].y = 0;
    Extra->coin_src_rect[i].h = 32;
    Extra->coin_src_rect[i].w = 33;
}
}




/*-----------------------------------------------------------------------------------------------------------------------------*/
/*-------------------UPDATES THE POSITIONS OF THE CONTENT OF EXTRA AND DRAWS ALL THE RELATED SURFACES--------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------*/
void extraDrawUpdate(EXTRA *Extra, MAP *currentMap, MOVEMENT *Movement, SDL_Surface *screen, SDL_Rect map_rect)
{
    SDL_Rect Box_rect[5], kitchen_food_rect, Bed_rect, CWindow_rect[3], coin_rect[MAXCOIN], two_piles_rect, K_R_box_rect,  axe_boxes_rect;
    SDL_Rect coin_blue_rect[MAXCOIN], coin_green_rect[MAXCOIN], char_blue_hair_rect, char_forest_blocker_rect, cactus_rect[3], flower_rect, char_forest_guide_rect;
    SDL_Rect cloak_boxes_rect, castle_food_boxes_rect, char_forest_guide2_rect, char_guard_rect, char_maid_rect, char_wizard_rect, shield_rect;
    SDL_Rect spell_rect, wand_rect,  blue_opened_box_rect;
    SDL_Rect dialog_box_char_blue_hair_rect,  dialog_box_map_1_char_1_rect, object_map_1_vending_machine_rect,  object_map_1_inn_rect, object_map_4_vending_machine_rect ;
    SDL_Rect dialog_box_map_2_guide_rect, dialog_box_map_3_guide_rect, object_map_1_bar_rect, dialog_box_map_1_char_2_rect, dialog_box_map_1_forest_blocker_rect;


    int ch_y = Movement->position_holder_y;
    int ch_x = Movement->position_holder_x;


/*---------------- common objects---------------------------------*/

        for (int i = 0; i<MAXCOIN; i++)
        {
            coin_rect[i].x = map_rect.x + (GRID * currentMap->coins[i][XVALUE]);
            coin_rect[i].y = map_rect.y + (GRID * currentMap->coins[i][YVALUE]);
            coin_rect[i].w = 0;
            coin_rect[i].h = 0;
            if (currentMap->coins[i][EXIST] == TRUE)
            {
                SDL_BlitSurface(Extra->coin01_surf,&(Extra->coin_src_rect[Movement->coin_frame]),screen,&coin_rect[i]);
            }
        }

        for (int i = 0; i<MAXCOIN; i++)
        {
            coin_blue_rect[i].x = map_rect.x + (GRID * currentMap->coins_blue[i][XVALUE]);
            coin_blue_rect[i].y = map_rect.y + (GRID * currentMap->coins_blue[i][YVALUE]);
            coin_blue_rect[i].w = 0;
            coin_blue_rect[i].h = 0;
            if (currentMap->coins_blue[i][EXIST] == TRUE)
            {
                SDL_BlitSurface(Extra->coin_blue_surf,&(Extra->coin_src_rect[Movement->coin_frame]),screen,&coin_blue_rect[i]);
            }
        }

        for (int i = 0; i<MAXCOIN; i++)
        {
            coin_green_rect[i].x = map_rect.x + (GRID * currentMap->coins_green[i][XVALUE]);
            coin_green_rect[i].y = map_rect.y + (GRID * currentMap->coins_green[i][YVALUE]);
            coin_green_rect[i].w = 0;
            coin_green_rect[i].h = 0;
            if (currentMap->coins_green[i][EXIST] == TRUE)
            {
                SDL_BlitSurface(Extra->coin_green_surf,&(Extra->coin_src_rect[Movement->coin_frame]),screen,&coin_green_rect[i]);
            }
        }
        for (int i = 0; i<5; i++)
        {
            Box_rect[i].x = map_rect.x + (GRID * currentMap->boxes[i][XVALUE]); //sets the position of the map based on the character
            Box_rect[i].y = map_rect.y + (GRID * currentMap->boxes[i][YVALUE]);
            if (currentMap->boxes[i][EXIST] == TRUE)
            {
              SDL_BlitSurface(Extra->Box_surf,NULL,screen,&Box_rect[i]);
            }else if (currentMap->boxes[i][EXIST] == FALSE)
                {
                    //printf("box  no.%d status %d, x = %d, y= %d\n ", i,currentMap->boxes[i][0], currentMap->boxes[i][2], currentMap->boxes[i][1]);
                    SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&Box_rect[i]);
                }
        }


/*---------------- map 0 bedroom---------------------------------*/


    if(currentMap->level == 0)
    {
        //close window rect
        for (int i = 0;i<3;i++)
        {
           CWindow_rect[i].x = map_rect.x + (GRID * currentMap->windows[i][XVALUE]);
           CWindow_rect[i].y = map_rect.y + (GRID * currentMap->windows[i][YVALUE]);
           if (currentMap->windows[i][EXIST] == TRUE)
            {
                SDL_BlitSurface(Extra->CWindow_surf,NULL,screen,&CWindow_rect[i]);
            }
        }
         //kitchen food
        kitchen_food_rect.x = map_rect.x + (GRID * currentMap->kitchen_food[0][XVALUE]); //sets the position of the map based on the character
        kitchen_food_rect.y = map_rect.y + (GRID * currentMap->kitchen_food[0][YVALUE]);
        if (currentMap->kitchen_food[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->Kitchen_food_surf,NULL,screen,&kitchen_food_rect);
        }

        //bed
        Bed_rect.x = map_rect.x + (GRID * currentMap->bed[0][XVALUE]);
        Bed_rect.y = map_rect.y + (GRID * currentMap->bed[0][YVALUE]);
        if (currentMap->bed[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->Bed_surf,NULL,screen,&Bed_rect);
        }

        //yellow key box
        K_R_box_rect.x = map_rect.x + (GRID * currentMap->K_R_boxes[0][XVALUE]);
        K_R_box_rect.y = map_rect.y + (GRID * currentMap->K_R_boxes[0][YVALUE]);
        if (currentMap->K_R_boxes[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->Box_surf,NULL,screen,&K_R_box_rect);
        } else if (currentMap->K_R_boxes[0][EXIST] == HALFTRUE)
            {
                SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&K_R_box_rect);
                SDL_BlitSurface(Extra->Key_surf,NULL,screen,&K_R_box_rect);
            } else if (currentMap->K_R_boxes[0][EXIST] == FALSE)
                {
                    SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&K_R_box_rect);
                }


    }

/*---------------- map 1 village---------------------------------*/


    if(currentMap->level == 1)
    {

        //character next to bedroom, bridge manager
        char_blue_hair_rect.x = map_rect.x + (GRID * currentMap->char_blue_hair[0][XVALUE]);
        char_blue_hair_rect.y = map_rect.y + (GRID * currentMap->char_blue_hair[0][YVALUE]);
        if (currentMap->char_blue_hair[0][EXIST] == TRUE)
        {
          SDL_BlitSurface(Extra->char_blue_hair_surf,NULL,screen,&char_blue_hair_rect);
        }

        //Holy axe quest, forest blocker
        char_forest_blocker_rect.x = map_rect.x + (GRID * currentMap->char_forest_blocker[0][XVALUE]);
        char_forest_blocker_rect.y = map_rect.y + (GRID * currentMap->char_forest_blocker[0][YVALUE]);
        if (currentMap->char_forest_blocker[0][EXIST] == TRUE)
        {
          SDL_BlitSurface(Extra->char_forest_blocker_surf,NULL,screen,&char_forest_blocker_rect);
        }

        //blue treasure box
        blue_opened_box_rect.x = map_rect.x + (GRID * currentMap->blue_opened_box[0][XVALUE]);
        blue_opened_box_rect.y = map_rect.y + (GRID * currentMap->blue_opened_box[0][YVALUE]);
        if (Movement->sapphire_box_status == TRUE && currentMap->level == 1)
        {
            SDL_BlitSurface(Extra->object_blue_opened_box_surf,NULL,screen,&blue_opened_box_rect);
        }

        //Axe box
        axe_boxes_rect.x = map_rect.x + (GRID * currentMap->axe_boxes[0][XVALUE]);
        axe_boxes_rect.y = map_rect.y + (GRID * currentMap->axe_boxes[0][YVALUE]);
        if (currentMap->axe_boxes[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->Box_surf,NULL,screen,&axe_boxes_rect);
        } else if (currentMap->axe_boxes[0][EXIST] == HALFTRUE)
            {
                SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&axe_boxes_rect);
                SDL_BlitSurface(Extra->char_forest_blocker_axe_surf,NULL,screen,&axe_boxes_rect);
            } else if (currentMap->axe_boxes[0][EXIST] == FALSE)
                {
                    SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&axe_boxes_rect);
                }

        //two piles blocker
        two_piles_rect.x = map_rect.x + (GRID * currentMap->two_piles[0][XVALUE]);
        two_piles_rect.y = map_rect.y + (GRID * currentMap->two_piles[0][YVALUE]);
        if (currentMap->two_piles[0][EXIST] == TRUE)
        {
           SDL_BlitSurface(Extra->two_piles_surf,NULL,screen,&two_piles_rect);
        }

        //flower_
        flower_rect.x = map_rect.x + (GRID * currentMap->flower[0][XVALUE]);
        flower_rect.y = map_rect.y + (GRID * currentMap->flower[0][YVALUE]);
        if (currentMap->flower[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->flower_surf,NULL,screen,&flower_rect);
        }

        //cactus_
        for (int i = 0; i<3; i++)
        {
            cactus_rect[i].x = map_rect.x + (GRID * currentMap->cactus[i][XVALUE]);
            cactus_rect[i].y = map_rect.y + (GRID * currentMap->cactus[i][YVALUE]);
            if (currentMap->cactus[i][EXIST] == TRUE){
                SDL_BlitSurface(Extra->cactus_surf,NULL,screen,&cactus_rect[i]);
            }
        }
                //show scroll for blue hair girl
        if (currentMap->grid[ch_y][ch_x] == CHAR_BLUE_HAIR && Movement->call_dialog_surface_blue_hair == TRUE)
        {
            dialog_box_char_blue_hair_rect.x = 45;
            dialog_box_char_blue_hair_rect.y = 100;
            SDL_BlitSurface(Extra->dialog_box_blue_hair_surf ,NULL,screen,&dialog_box_char_blue_hair_rect);
        }
        //show scroll for map_1_char_1, top left
        if (currentMap->grid[ch_y][ch_x] == map_1_char_1_interaction && Movement->call_dialog_surface_map_1_char_1 == TRUE)
        {
            dialog_box_map_1_char_1_rect.x = 45;
            dialog_box_map_1_char_1_rect.y = 100;
            SDL_BlitSurface(Extra->dialog_box_map_1_char_1_surf ,NULL,screen,&dialog_box_map_1_char_1_rect);
        }

        //show scroll for map_1_char_2, top middle
        if (currentMap->grid[ch_y][ch_x] == map_1_char_2_interaction && Movement->call_dialog_surface_map_1_char_2 == TRUE)
        {
            dialog_box_map_1_char_2_rect.x = 370;
            dialog_box_map_1_char_2_rect.y = 100;
            SDL_BlitSurface(Extra->dialog_box_map_1_char_2_surf ,NULL,screen,&dialog_box_map_1_char_2_rect);
        }

        //show vending machine map 1
        if (currentMap->grid[ch_y][ch_x] == map_1_vending_interaction)
        {
            object_map_1_vending_machine_rect.x = 50;
            object_map_1_vending_machine_rect.y = 50;
            SDL_BlitSurface(Extra->object_map_1_vending_machine_surf ,NULL,screen,&object_map_1_vending_machine_rect);
        }
        //show bar  map 1
        if (currentMap->grid[ch_y][ch_x] == map_1_bar)
        {
            object_map_1_bar_rect.x = 50;
            object_map_1_bar_rect.y = 100;
            SDL_BlitSurface(Extra->object_map_1_bar_surf ,NULL,screen,&object_map_1_bar_rect);
        }
         //show broken inn picture
        if (currentMap->grid[ch_y][ch_x] == INN_ENTRANCE)
        {
            object_map_1_inn_rect.x = 270;
            object_map_1_inn_rect.y = 50;
            SDL_BlitSurface(Extra->object_map_1_inn_surf ,NULL,screen,&object_map_1_inn_rect);
        }


    }

/*---------------- map 2 woods---------------------------------*/
    if(currentMap->level == 2)
    {

        //guide 1
        char_forest_guide_rect.x = map_rect.x + (GRID * currentMap->char_forest_guide[0][1]);
        char_forest_guide_rect.y = map_rect.y + (GRID * currentMap->char_forest_guide[0][0]);
        if (currentMap->char_forest_guide[0][EXIST] == TRUE)
        {
          SDL_BlitSurface(Extra->char_forest_guide_surf,NULL,screen,&char_forest_guide_rect);
        }

        //Cloak box
        cloak_boxes_rect.x = map_rect.x + (GRID * currentMap->cloak_boxes[0][1]);
        cloak_boxes_rect.y = map_rect.y + (GRID * currentMap->cloak_boxes[0][0]);
        if (currentMap->cloak_boxes[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->Box_surf,NULL,screen,&cloak_boxes_rect);
        } else if (currentMap->cloak_boxes[0][EXIST] == HALFTRUE)
            {
                SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&cloak_boxes_rect);
                SDL_BlitSurface(Extra->cloak_surf,NULL,screen,&cloak_boxes_rect);
            } else if (currentMap->cloak_boxes[0][EXIST] == FALSE)
                {
                    SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&cloak_boxes_rect);
                }

        //Castle food box
        castle_food_boxes_rect.x = map_rect.x + (GRID * currentMap->castle_food_boxes[0][1]);
        castle_food_boxes_rect.y = map_rect.y + (GRID * currentMap->castle_food_boxes[0][0]);
        if (currentMap->castle_food_boxes[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->Box_surf,NULL,screen,&castle_food_boxes_rect);
        } else if (currentMap->castle_food_boxes[0][EXIST] == HALFTRUE)
            {
                SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&castle_food_boxes_rect);
                SDL_BlitSurface(Extra->castle_food_surf,NULL,screen,&castle_food_boxes_rect);
            } else if (currentMap->castle_food_boxes[0][EXIST] == FALSE)
                {
                    SDL_BlitSurface(Extra->OBox_surf,NULL,screen,&castle_food_boxes_rect);
                }
        //show scroll for guide map 2
        if (currentMap->grid[ch_y][ch_x] == CHAR_FOREST_GUIDE && Movement->call_dialog_surface_map_2_forest_guide == TRUE)
        {
            dialog_box_map_2_guide_rect.x = 45;
            dialog_box_map_2_guide_rect.y = 100;
            SDL_BlitSurface(Extra->dialog_box_map_2_forest_guide_surf ,NULL,screen,&dialog_box_map_2_guide_rect);
        }

    }

/*---------------- map 3 path to castle---------------------------------*/
    if(currentMap->level == 3)
    {

        //guide 2
        char_forest_guide2_rect.x = map_rect.x + (GRID * currentMap->char_forest_guide2[0][1]);
        char_forest_guide2_rect.y = map_rect.y + (GRID * currentMap->char_forest_guide2[0][0]);
        if (currentMap->char_forest_guide2[0][EXIST] == TRUE)
        {
          SDL_BlitSurface(Extra->char_forest_guide_surf2,NULL,screen,&char_forest_guide2_rect);
        }

        /*--- matthew or jacob ---*/
        char_guard_rect.x = map_rect.x + (GRID * currentMap->char_matthew[0][1]);
        char_guard_rect.y = map_rect.y + (GRID * currentMap->char_matthew[0][0]);
        // matthew
        if (currentMap->char_matthew[0][EXIST] == TRUE)
        {
          SDL_BlitSurface(Extra->char_matthew_surf,NULL,screen,&char_guard_rect);
        }
        //jacob
        if (currentMap->char_jacob[0][EXIST] == TRUE)
        {
          SDL_BlitSurface(Extra->char_jacob_surf,NULL,screen,&char_guard_rect);
        }

        //show scroll for guide map 3
        if (currentMap->grid[ch_y][ch_x] == CHAR_FOREST_GUIDE2 && Movement->call_dialog_surface_map_3_forest_guide == TRUE)
        {
            dialog_box_map_3_guide_rect.x = 45;
            dialog_box_map_3_guide_rect.y = 100;
            SDL_BlitSurface(Extra->dialog_box_map_3_castle_guide_surf ,NULL,screen,&dialog_box_map_3_guide_rect);
        }

    }

/*---------------- map 4 castle---------------------------------*/

    if(currentMap->level == 4)
    {

        //maid
        char_maid_rect.x = map_rect.x + (GRID * currentMap->char_maid[0][1]);
        char_maid_rect.y = map_rect.y + (GRID * currentMap->char_maid[0][0]);
        if (currentMap->char_maid[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->char_maid_surf,NULL,screen,&char_maid_rect);
        }

        //wizard
        char_wizard_rect.x = map_rect.x + (GRID * currentMap->char_wizard[0][1]);
        char_wizard_rect.y = map_rect.y + (GRID * currentMap->char_wizard[0][0]);
        if (currentMap->char_wizard[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->char_wizard_surf,NULL,screen,&char_wizard_rect);
        }


        //spell
        spell_rect.x = map_rect.x + (GRID * currentMap->spell[0][1]);
        spell_rect.y = map_rect.y + (GRID * currentMap->spell[0][0]);
        if (currentMap->spell[0][EXIST] == TRUE)
        {
              switch(Movement->spell_counter){
                case 0:
                currentMap->spell[0][0] = 7;
                SDL_BlitSurface(Extra->spell_surf3,NULL,screen,&spell_rect);
                break;

                case 1:
                currentMap->spell[0][0] = 8;
                SDL_BlitSurface(Extra->spell_surf4,NULL,screen,&spell_rect);
                break;

                case 2:
                currentMap->spell[0][0] = 9;
                SDL_BlitSurface(Extra->spell_surf5,NULL,screen,&spell_rect);
                break;

                case 3:
                currentMap->spell[0][0] = 10;
                SDL_BlitSurface(Extra->spell_surf6,NULL,screen,&spell_rect);
                break;

                case 4:
                currentMap->spell[0][0] = 11;
                SDL_BlitSurface(Extra->spell_surf7,NULL,screen,&spell_rect);
                break;
              }

        }

        //shield
        shield_rect.x = map_rect.x + (GRID * currentMap->shield[0][1]);
        shield_rect.y = map_rect.y + (GRID * currentMap->shield[0][0]);
        if (currentMap->shield[0][EXIST] == TRUE)
        {
          SDL_BlitSurface(Extra->shield_surf,NULL,screen,&shield_rect);
        }

        //wand
        wand_rect.x = map_rect.x + (GRID * currentMap->wand[0][1]);
        wand_rect.y = map_rect.y + (GRID * currentMap->wand[0][0]);
        if (currentMap->wand[0][EXIST] == TRUE)
        {
            SDL_BlitSurface(Extra->wand_surf,NULL,screen,&wand_rect);
        }

        //show vending machine map 4
        if (currentMap->grid[ch_y][ch_x] == map_4_vending_interaction)
        {
            object_map_4_vending_machine_rect.x = 50;
            object_map_4_vending_machine_rect.y = 50;
            SDL_BlitSurface(Extra->object_map_4_vending_machine_surf ,NULL,screen,&object_map_4_vending_machine_rect);
        }

    }
     /*---------------- map 5 UNDEFINED---------------------------------*/



}


/*------------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------DRAWS ON THE SCREEN SMALL COINS FOR THE TAKEN ELEMENTS ----------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void screenObjects(MOVEMENT *Movement, EXTRA *Extra, SDL_Surface *screen)
{
    SDL_Rect K_R_screen_rect;
    K_R_screen_rect.x = 50;
    K_R_screen_rect.y = 550;
        if (Movement->key_room == TRUE)
        {
        SDL_BlitSurface(Extra->Key_surf,NULL,screen,&K_R_screen_rect);
        }

    SDL_Rect K_blue_screen_rect;
    K_blue_screen_rect.x = 0;
    K_blue_screen_rect.y = 550;
        if (Movement->key_Blue_room == TRUE)
        {
        SDL_BlitSurface(Extra->Key_blue_surf,NULL,screen,&K_blue_screen_rect);
        }

    SDL_Rect key_red_screen_rect;
    key_red_screen_rect.x = 100;
    key_red_screen_rect.y = 550;
        if (Movement->key_Red_room == TRUE)
        {
        SDL_BlitSurface(Extra->Key_red_surf,NULL,screen,&key_red_screen_rect);
        }

    SDL_Rect char_forest_blocker_axe_screen_rect;
    char_forest_blocker_axe_screen_rect.x = 150;
    char_forest_blocker_axe_screen_rect.y = 550;
        if (Movement->char_forest_blocker_axe == TRUE)
        {
        SDL_BlitSurface(Extra->char_forest_blocker_axe_surf,NULL,screen,&char_forest_blocker_axe_screen_rect);
        }


    SDL_Rect cloak_screen_rect;
    cloak_screen_rect.x = 200;
    cloak_screen_rect.y = 550;
        if (Movement->cloak == TRUE)
        {
        SDL_BlitSurface(Extra->cloak_surf,NULL,screen,&cloak_screen_rect);
        }
    SDL_Rect castle_food_screen_rect;
    castle_food_screen_rect.x = 250;
    castle_food_screen_rect.y = 550;
        if (Movement->castle_food == TRUE)
        {
        SDL_BlitSurface(Extra->castle_food_surf,NULL,screen,&castle_food_screen_rect);
        }
    SDL_Rect shield_screen_rect;
    shield_screen_rect.x = 300;
    shield_screen_rect.y = 550;
        if (Movement->shield_found == TRUE)
        {
        SDL_BlitSurface(Extra->shield_surf,NULL,screen,&shield_screen_rect);
        }
    SDL_Rect wand_screen_rect;
    wand_screen_rect.x = 350;
    wand_screen_rect.y = 550;
        if (Movement->wand_found == TRUE)
        {
        SDL_BlitSurface(Extra->wand_surf,NULL,screen,&wand_screen_rect);
        }
}



/*-----------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------INSTRUCTIONS ARE STORED IN THE STRING BASED ON THE CURRENT MAP-----------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------*/
void instructionHelp (EXTRA *Extra, MAP* currentMap){
    if (currentMap->level == 0)
        {
            strcpy(Extra->text_inst,"You need to leave the house to enter the village and begin your journey.\n\nTry to find a key to open the door...\n\nPress enter at any time for hints");
        }
    else if (currentMap->level == 1)
        {
            strcpy(Extra->text_inst,"You need to enter the forest to your right to go to the castle, however you might like to collect some items from the village before you go.\n\nTalk to the villagers for advice on what to take...");
        }
    else if (currentMap->level == 2)
        {
            strcpy(Extra->text_inst,"You made it to the woods!\n\nTry and find a forest guide to speak to - they are very knowledgeable and may have useful advice on how you can enter the castle");
        }
    else if (currentMap->level == 3)
        {
            strcpy(Extra->text_inst,"You will need to get past the guards to enter the castle.\n\nYou can use the following command to help you:\n\nif(MATTHEW) then FOOD else if(JACOB) then CLOAK\n\nSpeak to castle aid for the full explanation.");
        }
    else if (currentMap->level == 4)
        {
            strcpy(Extra->text_inst,"You need to defeat the wizard to lift the curse and free the villagers. The wizard will try to defeat you by firing spells but you can use a shield as protection with the following command:\n\nwhile(FIRING)\n{Action.Use(SHIELD)}\n\nType this as one line with no spaces");
        }
        else {
            strcpy(Extra->text_inst,"THIS MAP is not defined yet");
        }
}





/*------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------CONTAINS THE POSITIONS FOR ALL THE TEXTS ON THE SCREEN----------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void textPosition(MAINGRAPHICS *mainGraphics)
{
    mainGraphics->text_counter_rect.x = 615;
    mainGraphics->text_counter_rect.y = 465;


    mainGraphics->text_green_coin_rect.x = 615;
    mainGraphics->text_green_coin_rect.y = 530;


    mainGraphics->text_blue_coin_rect.x = 615;
    mainGraphics->text_blue_coin_rect.y = 495;


    mainGraphics->text_input_rect.x = 70;
    mainGraphics->text_input_rect.y = 475;

    mainGraphics->text_inst_rect.x = 570;
    mainGraphics->text_inst_rect.y = 80;

    mainGraphics->text_moves_rect.x = 722;
    mainGraphics->text_moves_rect.y = 500;

    mainGraphics->text_health_rect.x = 722;
    mainGraphics->text_health_rect.y = 465;


}





/*------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------DRAW THE TEXTS ON THE SCREEN------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void drawTexts(MAINGRAPHICS *mainGraphics, SDL_Color text_color, SDL_Color text_input_color, EXTRA *Extra)
{
            //initialize the font for each text
            mainGraphics->text_surf = TTF_RenderText_Solid(mainGraphics->font,Extra->text,text_color);
            mainGraphics->text_blue_coin_surf = TTF_RenderText_Solid(mainGraphics->font,Extra->text_blue_coin,text_color);
            mainGraphics->text_green_coin_surf = TTF_RenderText_Solid(mainGraphics->font,Extra->text_green_coin,text_color);

            mainGraphics->text_moves = TTF_RenderText_Solid(mainGraphics->font,Extra->text_moves_char,text_color);
            mainGraphics->text_input_surf = TTF_RenderText_Blended_Wrapped(mainGraphics->font_input,Extra->text_string_input,text_input_color,480);
            mainGraphics->text_inst_surf = TTF_RenderText_Blended_Wrapped(mainGraphics->font,Extra->text_inst,text_color,210);
            mainGraphics->text_health_surf = TTF_RenderText_Blended(mainGraphics->font,Extra->text_health,text_color);


            //draw the texts on the screen as surfaces
            SDL_BlitSurface(mainGraphics->text_surf,NULL,mainGraphics->screen,&mainGraphics->text_counter_rect);
            SDL_BlitSurface(mainGraphics->text_blue_coin_surf,NULL,mainGraphics->screen,&mainGraphics->text_blue_coin_rect);

            SDL_BlitSurface(mainGraphics->text_green_coin_surf,NULL,mainGraphics->screen,&mainGraphics->text_green_coin_rect);

            SDL_BlitSurface(mainGraphics->text_moves,NULL,mainGraphics->screen,&mainGraphics->text_moves_rect);
            SDL_BlitSurface(mainGraphics->text_input_surf,NULL,mainGraphics->screen,&mainGraphics->text_input_rect);
            SDL_BlitSurface(mainGraphics->text_inst_surf,NULL,mainGraphics->screen,&mainGraphics->text_inst_rect);
            SDL_BlitSurface(mainGraphics->text_health_surf,NULL,mainGraphics->screen,&mainGraphics->text_health_rect);
}



/*------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------DRAW ALL THE ELEMENTS BY CALLING ALL THE REQUIRED FUNCTIONS-------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void finalDrawer(MAP *currentMap, EXTRA *Extra,CHARACTER *currentCharacter, MAINGRAPHICS *mainGraphics, MOVEMENT *Movement, int FPS, SDL_Surface *currentMap_surf)
{
        SDL_Rect map_rect_temp = mainGraphics->map_rect; //used to allow map to take values below zero
        SDL_BlitSurface(currentMap_surf,NULL,mainGraphics->screen,&map_rect_temp);
        SDL_BlitSurface(currentCharacter->currentCharacter_surf,&currentCharacter->ch_src_rect[Movement->currentCharacter_frame],mainGraphics->screen,&currentCharacter->ch_rect_dest);
        extraDrawUpdate(Extra, currentMap, Movement, mainGraphics->screen, mainGraphics->map_rect);
        SDL_BlitSurface(mainGraphics->screen_cover,NULL,mainGraphics->screen,NULL); //covers everything except for the small window

        if (Extra->Guitar_active)
        {
            extraGuitar(Extra,Movement,currentCharacter, mainGraphics->screen, currentCharacter->ch_rect_dest, FPS);
        }

        if (Extra->LetHerGo_active)
        {
            extraLetgergo(Extra,Movement,currentCharacter, mainGraphics->screen, currentCharacter->ch_rect_dest, FPS);
        }
        /* -------------------- HP = 0 Game Over--------------------------------*/

        if (Movement->game_over == TRUE){
            SDL_Rect game_over_rect;
            game_over_rect.x = 38;
            game_over_rect.y = 36;
            SDL_BlitSurface(Extra->game_over,NULL,mainGraphics->screen,&game_over_rect);
            SDL_UpdateWindowSurface(mainGraphics->window);
            SDL_Delay(DELAYBEFOREDEATH);
            Movement->play = FALSE;
        }

        screenObjects(Movement,Extra, mainGraphics->screen);


}



/*------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------INCREMENT THE FRAMES FOR THE GAME AND THE COINS ---------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void incremintFrames(MOVEMENT *Movement)
{
Movement->frame++;
        if (Movement->coin_frame>7)
            {
                Movement->coin_frame = 0;
        }else if (!(Movement->frame%2))
            {
                Movement->coin_frame++;
            }
        if(Movement->spell_counter > 5)
        {
            Movement->spell_counter = 0;
        } else if(!(Movement->frame%2)){
            Movement->spell_counter++;
        }
}


/*------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------SPECIAL FUNCTION DEALS WITH DRAWING THE GUITAR---------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void extraGuitar(EXTRA *Extra,MOVEMENT *Movement, CHARACTER *currentCharacter, SDL_Surface *screen, SDL_Rect ch_rect_dest, int FPS)
{

            Extra->Guitar_counter++;
            SDL_BlitSurface(Extra->Guitar_surf,NULL,screen,&ch_rect_dest);
            Movement->can_move = FALSE;
            Movement->currentCharacter_frame = currentCharacter->mv_down[0];

            if (Extra->Guitar_counter > FPS*4)
            {
              Extra->Guitar_active = FALSE;
              Movement->can_move = TRUE;
              Extra->Guitar_counter = 0;
            }

}

/*------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------SPECIAL FUNCTION DEALS WITH DRAWING THE GUITAR AND PLAYING A SONG-------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/
void extraLetgergo(EXTRA *Extra,MOVEMENT *Movement, CHARACTER *currentCharacter, SDL_Surface *screen, SDL_Rect ch_rect_dest, int FPS)
{
              Extra->LetHerGo_counter++;
            SDL_BlitSurface(Extra->Guitar_surf,NULL,screen,&ch_rect_dest);
            Movement->can_move = FALSE;
            Movement->currentCharacter_frame = currentCharacter->mv_down[0];

            if (Extra->LetHerGo_counter > FPS*13)
            {
              Extra->LetHerGo_active = FALSE;
              Movement->can_move = TRUE;
              Extra->LetHerGo_counter = 0;
            }
}



void SDLFreeSurfaces(MAINGRAPHICS *mainGraphics, EXTRA *Extra)
{
        /*-------MAINGRAPHICS SURFACES FREEING-----------*/

        SDL_FreeSurface(mainGraphics->screen);
        SDL_FreeSurface(mainGraphics->screen_cover);
        SDL_FreeSurface(mainGraphics->main_surf);
        SDL_FreeSurface(mainGraphics->options_surf);
        SDL_FreeSurface(mainGraphics->currentMap_surf);


        /*-------EXTRA SURFACES FREEING-----------*/
        SDL_FreeSurface(Extra->Box_surf);
        SDL_FreeSurface(Extra->OBox_surf);
        SDL_FreeSurface(Extra->CWindow_surf);
        SDL_FreeSurface(Extra->Kitchen_food_surf);
        SDL_FreeSurface(Extra->castle_food_surf);
        SDL_FreeSurface(Extra->Bed_surf);
        SDL_FreeSurface(Extra->Guitar_surf);
        SDL_FreeSurface(Extra->coin01_surf);
        SDL_FreeSurface(Extra->coin_blue_surf);
        SDL_FreeSurface(Extra->coin_green_surf);
        SDL_FreeSurface(Extra->two_piles_surf);
        SDL_FreeSurface(Extra->Key_surf);
        SDL_FreeSurface(Extra->Key_red_surf);
        SDL_FreeSurface(Extra->Key_blue_surf);
        SDL_FreeSurface(Extra->char_blue_hair_surf);
        SDL_FreeSurface(Extra->dialog_box_blue_hair_surf);
        SDL_FreeSurface(Extra->char_forest_blocker_surf);
        SDL_FreeSurface(Extra->char_forest_blocker_axe_surf);
        SDL_FreeSurface(Extra->dialog_box_map_1_char_1_surf);
        SDL_FreeSurface(Extra->dialog_box_map_1_char_2_surf);
        SDL_FreeSurface(Extra->object_blue_opened_box_surf);
        SDL_FreeSurface(Extra->object_map_1_vending_machine_surf);
        SDL_FreeSurface(Extra->object_map_1_inn_surf);
        SDL_FreeSurface(Extra->object_map_1_bar_surf);
        SDL_FreeSurface(Extra->char_forest_guide_surf);
        SDL_FreeSurface(Extra->dialog_box_map_2_forest_guide_surf);
        SDL_FreeSurface(Extra->char_forest_guide_surf2);
        SDL_FreeSurface(Extra->dialog_box_map_3_castle_guide_surf);
        SDL_FreeSurface(Extra->char_matthew_surf);
        SDL_FreeSurface(Extra->char_jacob_surf);
        SDL_FreeSurface(Extra->char_maid_surf);
        SDL_FreeSurface(Extra->char_wizard_surf);
        SDL_FreeSurface(Extra->cactus_surf);
        SDL_FreeSurface(Extra->flower_surf);
        SDL_FreeSurface(Extra->cloak_surf);
        SDL_FreeSurface(Extra->shield_surf);
        SDL_FreeSurface(Extra->object_map_4_vending_machine_surf);
        SDL_FreeSurface(Extra->spell_surf3);
        SDL_FreeSurface(Extra->spell_surf4);
        SDL_FreeSurface(Extra->spell_surf5);
        SDL_FreeSurface(Extra->spell_surf6);
        SDL_FreeSurface(Extra->spell_surf7);
        SDL_FreeSurface(Extra->wand_surf);
        SDL_FreeSurface(Extra->game_over);


        /*-------EXTRA MIX FREEING-----------*/

        Mix_FreeChunk(Extra->effect_coin);
        Mix_FreeChunk(Extra->effect_opDoor);
        Mix_FreeChunk(Extra->effect_clDoor);
        Mix_FreeChunk(Extra->music);
        Mix_FreeChunk(Extra->effect_sneeze);
        Mix_FreeChunk(Extra->effect_burp);
        Mix_FreeChunk(Extra->effect_eat);
        Mix_FreeChunk(Extra->effect_guitar);
        Mix_FreeChunk(Extra->effect_lethergo);
        Mix_FreeChunk(Extra->map_1_dialog_show_me_you_got);
        Mix_FreeChunk(Extra->map_1_dialog_westeros_our_end);
        Mix_FreeChunk(Extra->map_1_dialog_what_can_i_do);
        Mix_FreeChunk(Extra->map_1_dialog_wonder_so_many_cactuses);
        Mix_FreeChunk(Extra->map_1_dialog_you_shall_not_pass);
        Mix_FreeChunk(Extra->map_1_dialog_blue_box_cactus);
        Mix_FreeChunk(Extra->map_1_char_oh_cactus);
        Mix_FreeChunk(Extra->map_1_char_I_dislike_cactus);
        Mix_FreeChunk(Extra->map_1_char_cactus_is_blocking);
        Mix_FreeChunk(Extra->map_1_char_holy_axe);
        Mix_FreeChunk(Extra->map_1_char_I_cant_open);
        Mix_FreeChunk(Extra->map_1_char_Inn_not_use);
        Mix_FreeChunk(Extra->map_1_char_teleported);
        Mix_FreeChunk(Extra->map_2_dialog_guide_greetings);
        Mix_FreeChunk(Extra->map_2_dialog_guide_use_it_wisely);
        Mix_FreeChunk(Extra->map_2_dialog_guide_go_find_valuable);
        Mix_FreeChunk(Extra->map_2_char_cannot_see_cloak);
        Mix_FreeChunk(Extra->map_2_char_not_opaque);
        Mix_FreeChunk(Extra->map_2_char_smells_meaty);
        Mix_FreeChunk(Extra->map_3_dialog_castle_grounds);
        Mix_FreeChunk(Extra->map_3_dialog_information_useful);
        Mix_FreeChunk(Extra->map_3_dialog_sell_intelligence);
        Mix_FreeChunk(Extra->map_4_dialog_you_cant_defeat);
        Mix_FreeChunk(Extra->map_4_dialog_the_world_is_ours);
        Mix_FreeChunk(Extra->map_4_dialog_nooo);
}


void SDLFreeText(MAINGRAPHICS *mainGraphics)
{
        SDL_FreeSurface(mainGraphics->text_surf);
        SDL_FreeSurface(mainGraphics->text_green_coin_surf);
        SDL_FreeSurface(mainGraphics->text_blue_coin_surf);
        SDL_FreeSurface(mainGraphics->text_moves);
        SDL_FreeSurface(mainGraphics->text_input_surf);
        SDL_FreeSurface(mainGraphics->text_inst_surf);
        SDL_FreeSurface(mainGraphics->text_health_surf);
}
