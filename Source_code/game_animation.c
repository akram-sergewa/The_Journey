/*------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------GAME_ANIMATION.C-----------------------------------------------*/
/*-------THIS FILE CONTAINS THE FUNCTIONS REQUIRED TO HANDLE MOVEMENT AND ANIMATION OF THE CHARACTERS AND OBJECTS---------*/
/*------------------------------------------------------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------THIS FUNCTION CHECKS IF IT IS POSSIBLE TO MOVE TO ANOTHER DIRECTION-------------------------------*/
/*IF TRUE IT SETS MOVE_HOLDER TO TRUE AND CHANGES THE POSITION INDISE THE MOVEMENT STRUCUTRE TO THE NEW PLACE AND RETURNS TRUE*/
/*----------------------------------------------------------------------------------------------------------------------------*/
int checkMoveable(CHARACTER* currentCharacter, MAP* currentMap, MOVEMENT *Movement)
{

    if (Movement->direction == RIGHT)   //right
    {
        if (currentMap->grid[Movement->position_holder_y][Movement->position_holder_x+1]&& Movement->can_move)  //check if the next box is available
                 {
                     Movement->move_holder = TRUE;
                     Movement->can_move = FALSE;
                     Movement->position_holder_x++;
                     return TRUE;
                 }
    }

    if (Movement->direction == DOWN)
    {
        if (currentMap->grid[Movement->position_holder_y+1][Movement->position_holder_x] && Movement->can_move)  //check if the next box is available
                 {
                     Movement->move_holder = TRUE;
                     Movement->can_move = FALSE;
                     Movement->position_holder_y++;
                     return TRUE;

                 }
    }

    if (Movement->direction == LEFT)   //left
    {
        if (currentMap->grid[Movement->position_holder_y][Movement->position_holder_x-1] && Movement->can_move)  //check if the next box is available
                 {
                     Movement->move_holder = TRUE;
                     Movement->can_move = FALSE;
                     Movement->position_holder_x--;
                     return TRUE;

                 }
    }

    if (Movement->direction == UP)
    {
        if (currentMap->grid[Movement->position_holder_y-1][Movement->position_holder_x] && Movement->can_move)  //check if the next box is available
                 {
                     Movement->move_holder = TRUE;
                     Movement->can_move = FALSE;
                     Movement->position_holder_y--;
                     return TRUE;

                 }
    }
             return 0;
}


/*-------------CONDUCTS THE ANIMATION OF THE MOVEMENT FROM ONE POSITION TO ANOTHER------------*/
/*--------------------------------------------------------------------__----------------------*/
void  execMove(MOVEMENT *Movement, SDL_Rect *ch_rect_dest, CHARACTER* currentCharacter, SDL_Rect *map_rect)
{
    if (Movement->direction==RIGHT)
    {
            if (ch_rect_dest->x == (map_rect->x + (GRID * Movement->position_holder_x)))
                {
                    Movement->can_move = TRUE;
                    Movement->move_holder = FALSE;
                }else{
                    map_rect->x-=SPEED; //moves the map
                    if (Movement->frame%2){
                        if (Movement->currentCharacter_frame < currentCharacter->mv_right[0] || Movement->currentCharacter_frame >= currentCharacter->mv_right[1])
                        Movement->currentCharacter_frame = currentCharacter->mv_right[0];
                        else
                        (Movement->currentCharacter_frame)++;
                        }
                       }
    }

    if (Movement->direction==DOWN)
    {
            if (ch_rect_dest->y == (map_rect->y + (GRID * Movement->position_holder_y))){
                    Movement->can_move =TRUE;
                    Movement->move_holder = FALSE;
                }else{
                    //ch_rect_dest->y+=2;
                    map_rect->y-=SPEED; //moves the map
                    if (Movement->frame%2){
                    if (Movement->currentCharacter_frame < currentCharacter->mv_down[0] || Movement->currentCharacter_frame >= currentCharacter->mv_down[1])
                    Movement->currentCharacter_frame = currentCharacter->mv_down[0];
                    else
                    (Movement->currentCharacter_frame)++;
                    }}
    }

    if (Movement->direction==LEFT)
    {
            if (ch_rect_dest->x == (map_rect->x + (GRID * Movement->position_holder_x))){
                    Movement->can_move =TRUE;
                    Movement->move_holder = FALSE;
                }else{
                    //ch_rect_dest->x-=2;

                    map_rect->x+=SPEED; //moves the map
                    if (Movement->frame%2){
                    if (Movement->currentCharacter_frame < currentCharacter->mv_left[0] || Movement->currentCharacter_frame >= currentCharacter->mv_left[1])
                    Movement->currentCharacter_frame = currentCharacter->mv_left[0];
                    else
                    (Movement->currentCharacter_frame)++;
                    }}
    }

    if (Movement->direction==UP)
    {
            if (ch_rect_dest->y == (map_rect->y + (GRID * Movement->position_holder_y))){
                    Movement->can_move =TRUE;
                    Movement->move_holder = FALSE;
                }else{

                    //ch_rect_dest->y-=2;
                    map_rect->y+=SPEED; //moves the map
                    if (Movement->frame%2){
                    if (Movement->currentCharacter_frame < currentCharacter->mv_up[0] || Movement->currentCharacter_frame >= currentCharacter->mv_up[1])
                    Movement->currentCharacter_frame = currentCharacter->mv_up[0];
                    else
                    (Movement->currentCharacter_frame)++;
                    }}
    }


}


