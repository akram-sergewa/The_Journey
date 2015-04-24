/*----------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------GAME_CONTENTS.C---------------------------------------------------*/
/*-----THIS FILE INCLUDES ALL THE FUNCTIONS THAT CONTAIN THE REQUIRED INFORMATION FOR THE MAPS AND THE OBJECTS OVER THEM------*/
/*-----------CHANGES ON THIS FILE ONLY REQUIRED WHENEVER THERE IS A NEED TO ADD A NEW MAP OR A NEW OBJECT ON ANY MAP----------*/
/*----------------------------------------------------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------------------------------*/
/*-----------FILLS THE MAP STRUCTURE WITH VALUES FOR ALL THE CONTENTS OF THE MAPS IN THE GAME-------------*/
/*---------BOXES, WINDOWS, PLANTS, COINS, AND THE START AND EXIT POINTS FOR EACH MAP ARE SET HERE---------*/
/*--------------------------------------------------------------------------------------------------------*/

void mapMaker(MAP the_map[MAPSNUMBER])
{

/*-----------------------------------------------GRAPHICS NULLIFIER--------------------------------------------*/
/*-----TO AVOID DRAWING SURFACE BECAUSE OF THE GARBAGE VALUES THIS LOOP SET A SPECIAL VALUE TO EVERYTHING------*/
/*------------ON THE MAPS TO NULLIFY THEM THEN FOR EACH MAP ONLY THE NEEDED ONES WILL BE SET TO TRUE-----------*/
    for (int i = 0; i<MAPSNUMBER; i++)
    {
        the_map[i].boxes[0][EXIST]=NOTEXIST;
        the_map[i].boxes[1][EXIST]=NOTEXIST;
        the_map[i].boxes[2][EXIST]=NOTEXIST;
        the_map[i].boxes[3][EXIST]=NOTEXIST;
        the_map[i].boxes[4][EXIST]=NOTEXIST;
        the_map[i].K_Blue_boxes[0][EXIST]=NOTEXIST;
        the_map[i].K_Red_boxes[0][EXIST]=NOTEXIST;
        the_map[i].K_R_boxes[0][EXIST]=NOTEXIST;
        the_map[i].axe_boxes[0][EXIST]=NOTEXIST;
        the_map[i].cloak_boxes[0][EXIST]=NOTEXIST;
        the_map[i].castle_food_boxes[0][EXIST]=NOTEXIST;
        for (int j = 0; j<MAXCOIN; j++){
            the_map[i].coins[j][EXIST]=NOTEXIST;
            the_map[i].coins_blue[j][EXIST]=NOTEXIST;
            the_map[i].coins_green[j][EXIST]=NOTEXIST;
        }

        for (int j = 0; j<3; j++){
             the_map[i].cactus[j][EXIST]=NOTEXIST;
        }
    }



/*-----------------------------------------------------------------------------*/
/*---------------------------------MAP 0 bedroom-------------------------------*/
/*-----------------------------------------------------------------------------*/
        the_map[0].level = 0;
        the_map[0].hight = 17;
        the_map[0].width = 19;
        the_map[0].completed = 0;
        strcpy(the_map[0].map_file, "map/house01.bmp");
        the_map[0].start[0]=6;
        the_map[0].start[1]=4;
        the_map[0].exit[0]=12;
        the_map[0].exit[1]=13;

        the_map[0].coins[0][YVALUE]=6;
        the_map[0].coins[0][XVALUE]=10;
        the_map[0].coins[1][YVALUE]=7;
        the_map[0].coins[1][XVALUE]=11;
        the_map[0].coins[2][YVALUE]=11;
        the_map[0].coins[2][XVALUE]=15;
        the_map[0].coins[3][YVALUE]=10;
        the_map[0].coins[3][XVALUE]=6;
        the_map[0].coins[4][YVALUE]=9;
        the_map[0].coins[4][XVALUE]=10;
        the_map[0].coins[5][YVALUE]=13;
        the_map[0].coins[5][XVALUE]=13;
        the_map[0].coins[0][EXIST]=TRUE;
        the_map[0].coins[1][EXIST]=TRUE;
        the_map[0].coins[2][EXIST]=TRUE;
        the_map[0].coins[3][EXIST]=TRUE;
        the_map[0].coins[4][EXIST]=TRUE;
        the_map[0].coins[5][EXIST]=TRUE;

        the_map[0].K_R_boxes[0][YVALUE]=10;
        the_map[0].K_R_boxes[0][XVALUE]=4;
        the_map[0].K_R_boxes[0][EXIST]=TRUE;





        for (int i = 0; i<20;i++)
        {
            for (int j = 0;j<20;j++)
            {
               the_map[0].grid[i][j] = 0;
            }
        }

        the_map[0].grid[8][2] = 0;
        the_map[0].grid[6][4] = WINDOW+BED;
        the_map[0].grid[7][4] = BED;
        the_map[0].grid[6][8] = WINDOW;
        the_map[0].grid[6][10] = WINDOW;

        //the_map[0].grid[6][4] = 1;
        the_map[0].grid[6][7] = 1;
        //the_map[0].grid[6][8] = 1;
        the_map[0].grid[6][9] = 0;//BOX
        //the_map[0].grid[6][10] = 1;
        the_map[0].grid[6][13] = KITCHENFOOD;
        the_map[0].grid[6][14] = KITCHENFOOD;
        the_map[0].grid[6][15] = KITCHENFOOD;

        //the_map[0].grid[7][4] = 1;
        the_map[0].grid[7][7] = 1;
        the_map[0].grid[7][8] = 1;
        the_map[0].grid[7][9] = BOX;//position where interacts with the box
        the_map[0].grid[7][10] = 1;
        the_map[0].grid[7][11] = 1;
        the_map[0].grid[7][12] = 1;
        the_map[0].grid[7][13] = 1;
        the_map[0].grid[7][14] = 1;
        the_map[0].grid[7][15] = 1;

        the_map[0].grid[8][3] = 1;
        the_map[0].grid[8][4] = 1;
        the_map[0].grid[8][5] = BED;
        the_map[0].grid[8][7] = 1;
        the_map[0].grid[8][8] = 1;
        the_map[0].grid[8][9] = 1;
        the_map[0].grid[8][10] = 1;
        the_map[0].grid[8][13] = 1;
        the_map[0].grid[8][14] = 1;
        the_map[0].grid[8][15] = 1;

        the_map[0].grid[9][3] = 1;
        the_map[0].grid[9][4] = K_R_BOX;
        the_map[0].grid[9][5] = 1;
        the_map[0].grid[9][6] = 1;
        the_map[0].grid[9][7] = 1;
        the_map[0].grid[9][8] = 1;
        the_map[0].grid[9][9] = 1;
        the_map[0].grid[9][10] = 1;
        the_map[0].grid[9][13] = 1;
        the_map[0].grid[9][14] = 1;
        the_map[0].grid[9][15] = 1;

        the_map[0].grid[10][3] = K_R_BOX;;
        the_map[0].grid[10][4] = 0;
        the_map[0].grid[10][5] = K_R_BOX;
        the_map[0].grid[10][6] = 1;
        the_map[0].grid[10][7] = 1;
        the_map[0].grid[10][8] = 1;
        the_map[0].grid[10][9] = 1;
        the_map[0].grid[10][10] = 1;
        the_map[0].grid[10][13] = 1;
        the_map[0].grid[10][14] = 1;
        the_map[0].grid[10][15] = 1;

        the_map[0].grid[11][7] = 1;
        the_map[0].grid[11][8] = 1;
        the_map[0].grid[11][9] = 1;
        the_map[0].grid[11][10] = 1;
        the_map[0].grid[11][11] = 1;
        the_map[0].grid[11][12] = 1;
        the_map[0].grid[11][13] = 1;
        the_map[0].grid[11][14] = 1;
        the_map[0].grid[11][15] = 1;

        the_map[0].grid[12][13] = 1;
        the_map[0].grid[13][13] = 1;
        the_map[0].grid[14][13] = NEXT_MAP_CLOSED;


        the_map[0].bed[0][YVALUE]=6;
        the_map[0].bed[0][XVALUE]=5;
        the_map[0].bed[0][EXIST]=TRUE;

        the_map[0].kitchen_food[0][YVALUE]=5;
        the_map[0].kitchen_food[0][XVALUE]=14;
        the_map[0].kitchen_food[0][EXIST]=FALSE;

        the_map[0].boxes[0][YVALUE]=6;
        the_map[0].boxes[0][XVALUE]=9;
        the_map[0].boxes[0][EXIST]=TRUE;

        the_map[0].windows[0][YVALUE]=4;
        the_map[0].windows[0][XVALUE]=4;
        the_map[0].windows[0][EXIST]=FALSE;

        the_map[0].windows[1][YVALUE]=4;
        the_map[0].windows[1][XVALUE]=8;
        the_map[0].windows[1][EXIST]=FALSE;

        the_map[0].windows[2][YVALUE]=4;
        the_map[0].windows[2][XVALUE]=10;
        the_map[0].windows[2][EXIST]=FALSE;



/*-----------------------------------------------------------------------------*/
/*---------------------------------MAP 1 village-------------------------------*/
/*-----------------------------------------------------------------------------*/
    int i,j;
    the_map[1].start[0]=24;
    the_map[1].start[1]=25;
    the_map[1].level = 1;
    the_map[1].hight = 30;
    the_map[1].width = 30;
    the_map[1].completed = 0;
    the_map[1].boxes[0][XVALUE]=100;

    strcpy(the_map[1].map_file, "map/main_map_30x30v2.bmp");

    for (i = 0; i<=30; i++){
        for (j = 0; j<=30; j++){
            the_map[1].grid [i][j] = 0;
        }
    }

    //top left path
    the_map[1].grid[2][2] = 1;
    the_map[1].grid[2][3] = 1;
    the_map[1].grid[2][4] = 1;
    the_map[1].grid[3][4] = 0;  //cuttable plant
    the_map[1].grid[3][5] = 1;
    the_map[1].grid[4][4] = 1;
    for ( i = 3; i <= 10; i++){
        the_map[1].grid[i][1] = 1;
    }



    the_map[1].grid[2][1] = EMPTY_BOX_INFO;
    the_map[1].grid[11][1] = EMPTY_BOX_INFO;

    the_map[1].grid[2][1] = sapphire_box;
    the_map[1].blue_opened_box[0][YVALUE]= 1;
    the_map[1].blue_opened_box[0][XVALUE]= 1;
    the_map[1].blue_opened_box[0][EXIST]= FALSE;



    the_map[1].grid[4][4] = 1;

    //the_map[1].grid[4][5] = steps to yellow stone building;
    the_map[1].grid[4][5] = 1;

    for ( i = 5; i <= 8; i++){
        for ( j = 4; j <= 16; j++){
            the_map[1].grid[5][16] = EMPTY_BOX_INFO;

            the_map[1].grid[i][j] = 1;
        }
    }
    //map1-character in the middle in black
    the_map[1].grid[5][14] = map_1_char_2_interaction;


    //map 1-character on the top left
    the_map[1].grid[6][6] = 0;
    the_map[1].grid[7][6] = map_1_char_1_interaction;
    //the_map[1].grid[7][4] = step to white stone building;
    the_map[1].grid[7][4] = 1;

    the_map[1].grid[8][4] = 0;
    the_map[1].grid[8][5] = 0;
    the_map[1].grid[8][12] = 0;


    for ( i = 9; i <= 11; i++){
        for ( j = 8; j <= 10; j++){
            the_map[1].grid[i][j] = 1;
        }
    }
    for ( i = 9; i <= 11; i++){
        for ( j = 12; j <= 16; j++){
            the_map[1].grid[i][j] = 1;
        }
    }
    the_map[1].grid[9][12] = 0;

    for ( i = 12; i <= 13; i++){
        for ( j = 12; j <= 21; j++){
            the_map[1].grid[i][j] = 1;
        }
    }



    // left PUB
    for ( i = 3; i <= 11; i++){
        for ( j = 19; j <= 21; j++){
            the_map[1].grid[i][j] = 1;
        }
    }
    //character 3 on the top right
     the_map[1].grid[4][21] = 0;
     the_map[1].grid[5][21] = map_1_char_3_interaction;
     the_map[1].grid[4][20] = map_1_char_3_interaction;


    //the_map[1].grid[3][22] = steps to PUB;
    the_map[1].grid[3][22] = map_1_bar;

    the_map[1].grid[6][21] = EMPTY_BOX_INFO;
    the_map[1].grid[8][22] = 1;
    the_map[1].grid[11][22] = 1;
    the_map[1].grid[12][22] = 0;

for(i=0;i<=1;i++)
{
    for(j=18;j<=20;j++)
    {
        the_map[1].grid[i][j] = 1;
    }
}
the_map[1].grid[0][19] = 0;

    //bottom PUB
    for ( i = 13; i <= 14; i++){
        for ( j = 21; j <= 26; j++){
            the_map[1].grid[i][j] = 1;
        }
    }

    //Right PUB
    for ( i = 6; i <= 13; i++){
        for ( j = 26; j <= 28; j++){
            the_map[1].grid[i][j] = 1;
        }
    }
    the_map[1].grid[6][28] = 0;
    the_map[1].grid[7][28] = 0;
    the_map[1].grid[8][28] = 0;

    //the_map[1].grid[10][26] = steps to PUB;
    the_map[1].grid[10][26] = map_1_bar;


    the_map[1].grid[9][26] = 0;
    the_map[1].grid[11][26] = 0;
    the_map[1].grid[12][26] = 0;


    //bridge
    for ( i = 14; i <= 17; i++){
        for ( j = 13; j <= 14; j++){
            the_map[1].grid[i][j] = 1;
        }
    }

    //bottom bridge
    for ( i = 18; i <= 19; i++){
        for ( j = 12; j <= 17; j++){
            the_map[1].grid[i][j] = 1;
        }
    }
    the_map[1].grid[19][19] = 1;
    the_map[1].grid[19][20] = 1;


    //roof on INN
    for ( i = 20; i <= 21; i++){
        for ( j = 3; j <= 12; j++){
            the_map[1].grid[i][j] = 1;
        }
    }
    the_map[1].grid[20][3] = 0;
    the_map[1].grid[20][9] = 0;

    //normal BOX on Roof
    the_map[1].grid[20][12] = 0;
    the_map[1].boxes[0][YVALUE]=20;
    the_map[1].boxes[0][XVALUE]=12;
    the_map[1].boxes[0][EXIST]=TRUE;
    the_map[1].grid[21][12] = BOX;
    the_map[1].grid[21][13] = 0;
    the_map[1].boxes[0][EXIST] = TRUE;
    the_map[1].boxes[0][YVALUE] = 20;
    the_map[1].boxes[0][XVALUE] = 12;

    //ladder to roof
    for ( i = 22; i <= 25; i++){
        the_map[1].grid[i][12] = 1;
    }


    //Right INN
    for ( i = 20; i <= 25; i++){
        for ( j = 15; j <= 19; j++){
            the_map[1].grid[i][j] = 1;
        }
    }
    the_map[1].grid[22][15] = 0;
    //the_map[1].grid[23][15] = steps to INN;
    the_map[1].grid[23][15] = INN_ENTRANCE;
    the_map[1].grid[24][15] = 0;
    the_map[1].grid[25][15] = 0;

    //bottom HOME
    for ( i = 24; i <= 25; i++){
        for ( j = 20; j <= 27; j++){
            the_map[1].grid[i][j] = 1;
        }
    }

    the_map[1].coins[0][YVALUE] = 24;
    the_map[1].coins[0][XVALUE] = 26;
    the_map[1].coins[0][EXIST] = TRUE;


    the_map[1].coins_blue[0][YVALUE] = 24;
    the_map[1].coins_blue[0][XVALUE] = 24;
    the_map[1].coins_blue[0][EXIST] = TRUE;


    the_map[1].coins_green[0][YVALUE] = 24;
    the_map[1].coins_green[0][XVALUE] = 25;
    the_map[1].coins_green[0][EXIST] = TRUE;
    //the_map[1].grid[23][22] = door to bedroom;
    the_map[1].grid[23][25] = PREVIOUS_MAP;

    //bottom INN
    for ( i = 26; i <= 27; i++){
        for ( j = 2; j <= 17; j++){
            the_map[1].grid[i][j] = 1;
        }
    }


    // path to forest
    the_map[1].grid[28][17] = 0;
    the_map[1].grid[29][17] = 0;

    // stone blocker on bridge
    the_map[1].two_piles[0][YVALUE]=17;
    the_map[1].two_piles[0][XVALUE]=13;
    the_map[1].two_piles[0][EXIST]=TRUE;
    the_map[1].grid[17][13] = 0;
    the_map[1].grid[17][14] = 0;

    //path to new map from right.
    the_map[1].grid[23][28] = 1;

    // CHAR_FOREST_BLOCKER AT 24,28
    the_map[1].grid[24][27] = CHAR_FOREST_BLOCKER;
    the_map[1].char_forest_blocker[0][YVALUE]=24;
    the_map[1].char_forest_blocker[0][XVALUE]=28;
    the_map[1].char_forest_blocker[0][EXIST]=TRUE;
    the_map[1].grid[24][28] = 0;


    //grid[24][29] connects next map
    the_map[1].grid[24][29] = NEXT_MAP;


    the_map[1].grid[26][14] = 0;
    //the_map[1].grid[26][EXIST] = NEXT_MAP;

    the_map[1].exit[0] = 24;
    the_map[1].exit[1] = 28;

    /* Interact grids to break piles */
    the_map[1].grid[18][13]=PILES;
    the_map[1].grid[18][14]=PILES;

     //cactus blocker
    the_map[1].cactus[0][YVALUE]=3;
    the_map[1].cactus[0][XVALUE]=4;
    the_map[1].cactus[0][EXIST]=TRUE;
    the_map[1].grid[3][4] = 0;
    //interact to cactus
    the_map[1].grid[4][4] = CACTUS;
    the_map[1].grid[3][5] = CACTUS;

     //cactus in a row blocker
    the_map[1].cactus[1][YVALUE]=2;
    the_map[1].cactus[1][XVALUE]=19;
    the_map[1].cactus[1][EXIST]=TRUE;
    the_map[1].grid[1][19] = 1;
    the_map[1].cactus[2][YVALUE]=2;
    the_map[1].cactus[2][XVALUE]=20;
    the_map[1].cactus[2][EXIST]=TRUE;
    the_map[1].grid[2][20] = 0;
    //interact to cactus
    the_map[1].grid[3][19] = CACTUS_ROW;
    the_map[1].grid[3][20] = CACTUS_ROW;


    //Flower on BOX
    the_map[1].flower[0][YVALUE]=0;
    the_map[1].flower[0][XVALUE]=19;
    the_map[1].flower[0][EXIST]=TRUE;
    the_map[1].grid[0][19] = 0;
    //interact to flower
    the_map[1].grid[1][19] = FLOWER;
    the_map[1].grid[0][18] = 1;
    the_map[1].grid[0][20] = FLOWER;


    //AXE BOX under Flower
    the_map[1].axe_boxes[0][YVALUE]=0;
    the_map[1].axe_boxes[0][XVALUE]=19;
    the_map[1].axe_boxes[0][EXIST]=TRUE;
    //interact position will be enabled after flower is gone

    //vending machine
    the_map[1].grid[6][27] = map_1_vending_interaction;
    the_map[1].grid[6][26] = map_1_vending_interaction;

    /*blue hair character on map*/
    the_map[1].char_blue_hair[0][YVALUE]=20;
    the_map[1].char_blue_hair[0][XVALUE]=19;
    the_map[1].char_blue_hair[0][EXIST]=TRUE;
    the_map[1].grid[21][19] = CHAR_BLUE_HAIR;
    the_map[1].grid[20][18] = CHAR_BLUE_HAIR;
    the_map[1].grid[20][19] = 0;


/*-----------------------------------------------------------------------------*/
/*---------------------------------MAP 2 woods --------------------------------*/
/*-----------------------------------------------------------------------------*/

    the_map[2].level = 2;
    the_map[2].hight = 30;
    the_map[2].width = 30;
    the_map[2].completed = 0;
    strcpy(the_map[2].map_file, "map/woods.bmp");
    //sprintf(the_map[0].map_file, "house01.bmp");


    the_map[2].start[0]=4;
    the_map[2].start[1]=1;


    the_map[2].char_forest_guide[0][YVALUE] = 7;
    the_map[2].char_forest_guide[0][XVALUE] = 22;
    the_map[2].char_forest_guide[0][EXIST] = TRUE;

    //Cloak box
    the_map[2].cloak_boxes[0][YVALUE]=20;
    the_map[2].cloak_boxes[0][XVALUE]=10;
    the_map[2].cloak_boxes[0][EXIST]=TRUE;

    //Castle food box
    the_map[2].castle_food_boxes[0][YVALUE]=11;
    the_map[2].castle_food_boxes[0][XVALUE]=24;
    the_map[2].castle_food_boxes[0][EXIST]=TRUE;

    for (i = 0; i<=29; i++){
        for (j = 0; j<=29; j++){
            the_map[2].grid [i][j] = 1;
        }
    }

    //upper trees
    for (i = 0; i<=3; i++){
        for (j = 0; j<=29; j++){
            the_map[2].grid [i][j] = 0;
        }
    }
    //trees on the left part
    for (i = 7; i<=29; i++){
        for (j = 0; j<=3; j++){
            the_map[2].grid [i][j] = 0;
        }
    }

    //trees on the right all the way down to the cliff
    for (i = 4; i<=19; i++){
        for (j = 26; j<=29; j++){
            the_map[2].grid [i][j] = 0;
        }
    }

    for (i = 22; i<=29; i++){
        for (j = 26; j<=29; j++){
            the_map[2].grid [i][j] = 0;
        }
    }

    //cliffs
    for (i = 22; i<=29; i++){
        for (j = 22; j<=25; j++){
            the_map[2].grid [i][j] = 0;
        }
    }

    for (i = 25; i<=29; i++){
        for (j = 14; j<=25; j++){
            the_map[2].grid [i][j] = 0;
        }
    }


    //camp part

    for (i = 4; i<=6; i++){
        for (j = 15; j<=25; j++){
            the_map[2].grid [i][j] = 0;
        }
    }

    //middle trees
    for (i = 6; i<=19; i++){
        for (j = 8; j<=11; j++){
            the_map[2].grid [i][j] = 0;
        }
    }

    for (i = 20; i<=23; i++){
        for (j = 11; j<=18; j++){
            the_map[2].grid [i][j] = 0;
        }
    }

    for (i = 14; i<=19; i++){
        for (j = 12; j<=14; j++){
            the_map[2].grid [i][j] = 0;
        }
    }
    for (i = 26; i<=29; i++){
        for (j = 4; j<=13; j++){
            the_map[2].grid [i][j] = 0;
        }
    }
    for (i = 24; i<=26; i++){
        for (j = 13; j<=16; j++){
            the_map[2].grid [i][j] = 1;
        }
    }

    //Character forest guide
    the_map[2].grid [7][22] = 0;
    the_map[2].grid [7][21] = CHAR_FOREST_GUIDE;
    the_map[2].grid [7][23] = CHAR_FOREST_GUIDE;
    the_map[2].grid [8][22] = CHAR_FOREST_GUIDE;

    //Cloak box
    the_map[2].grid [20][10] = 0;
    the_map[2].grid [21][10] = CLOAK_BOX;
    the_map[2].grid [20][9] = CLOAK_BOX;

    //Castle food box
    the_map[2].grid [11][24] = 0;
    the_map[2].grid [12][24] = CASTLEFOOD;
    the_map[2].grid [11][23] = CASTLEFOOD;
    the_map[2].grid [10][24] = CASTLEFOOD;
    the_map[2].grid [11][25] = CASTLEFOOD;

    //Coins
    for(i = 13, j = 0; i <= 24 && j < 3; i+=4, j++){
        the_map[2].coins[j][YVALUE] = i;
        the_map[2].coins[j][XVALUE] = 20;
        the_map[2].coins[j][EXIST] = TRUE;
    }

    for(i = 10, j = 3; i <= 19 && j < 6; i+=3, j++){
        the_map[2].coins[j][YVALUE] = 24;
        the_map[2].coins[j][XVALUE] = i;
        the_map[2].coins[j][EXIST] = TRUE;
    }

    the_map[2].coins_blue[0][YVALUE] = 12;
    the_map[2].coins_blue[0][XVALUE] = 20;
    the_map[2].coins_blue[0][EXIST] = TRUE;
    the_map[2].coins_blue[1][YVALUE] = 12;
    the_map[2].coins_blue[1][XVALUE] = 22;
    the_map[2].coins_blue[1][EXIST] = TRUE;
    the_map[2].coins_blue[2][YVALUE] = 12;
    the_map[2].coins_blue[2][XVALUE] = 24;
    the_map[2].coins_blue[2][EXIST] = TRUE;

    the_map[2].coins_green[0][YVALUE] = 21;
    the_map[2].coins_green[0][XVALUE] = 10;
    the_map[2].coins_green[0][EXIST] = TRUE;
    the_map[2].coins_green[1][YVALUE] = 23;
    the_map[2].coins_green[1][XVALUE] = 10;
    the_map[2].coins_green[1][EXIST] = TRUE;

    the_map[2].grid [9][19] = 0;
    the_map[2].grid [9][20] = 0;
    the_map[2].grid [24][21] = 0;
    the_map[2].grid [14][15] = 0;
    the_map[2].grid [15][15] = 0;

    the_map[2].exit[0] = 20;
    the_map[2].exit[1] = 28;

    the_map[2].grid[4][0] = PREVIOUS_MAP;
    the_map[2].grid[5][0] = PREVIOUS_MAP;
    the_map[2].grid[6][0] = PREVIOUS_MAP;
    the_map[2].grid[7][0] = PREVIOUS_MAP;

    the_map[2].grid[20][29] = NEXT_MAP;
    the_map[2].grid[21][29] = NEXT_MAP;


/*-----------------------------------------------------------------------------*/
/*---------------------------MAP 3 before castle-------------------------------*/
/*-----------------------------------------------------------------------------*/
    the_map[3].level = 3;
    the_map[3].hight = 30;
    the_map[3].width = 30;
    the_map[3].completed = 0;
    strcpy(the_map[3].map_file, "map/path_to_castle.bmp");
    //sprintf(the_map[0].map_file, "house01.bmp");

    the_map[3].start[0]=4;
    the_map[3].start[1]=1;
    //the_map[3].exit[0]=12;
    //the_map[3].exit[1]=13;

    //Guide character
    the_map[3].char_forest_guide2[0][YVALUE] = 4;
    the_map[3].char_forest_guide2[0][XVALUE] = 5;
    the_map[3].char_forest_guide2[0][EXIST] = TRUE;

    //Guards
    the_map[3].char_matthew[0][YVALUE] = 22;
    the_map[3].char_matthew[0][XVALUE] = 23;
    the_map[3].char_matthew[0][EXIST] = FALSE;
    the_map[3].char_jacob[0][YVALUE] = 22;
    the_map[3].char_jacob[0][XVALUE] = 23;
    the_map[3].char_jacob[0][EXIST] = FALSE;

    //bridge    path
    for (i = 2; i<=23; i++){
        for (j = 3; j<=26; j++){
            the_map[3].grid [i][j] = 0;
        }
    }

    for (i = 4; i<=5; i++){
        for (j = 0; j<=5; j++){
            the_map[3].grid [i][j] = 1;
        }
    }

    for (i = 6; i<=9; i++){
        for (j = 5; j<=6; j++){
            the_map[3].grid [i][j] = 1;
        }
    }

    for (i = 9; i<=10; i++){
        for (j = 7; j<=13; j++){
            the_map[3].grid [i][j] = 1;
        }
    }

    for (i = 10; i<=15; i++){
        for (j = 14; j<=15; j++){
            the_map[3].grid [i][j] = 1;
        }
    }

    for (i = 15; i<=16; i++){
        for (j = 16; j<=25; j++){
            the_map[3].grid [i][j] = 1;
        }
    }
    //paths after the bridge
    for (i = 17; i<=21; i++){
        for (j = 20; j<=25; j++){
            the_map[3].grid [i][j] = 1;
        }
    }

    for (i = 19; i<=21; i++){
        for (j = 26; j<=27; j++){
            the_map[3].grid [i][j] = 1;
        }
    }

    for (i = 22; i<=23; i++){
        for (j = 23; j<=24; j++){
            the_map[3].grid [i][j] = 1;
        }
    }


    for (i = 19; i<=23; i++){
        for (j = 17; j<=19; j++){
            the_map[3].grid [i][j] = 1;
        }
    }

    //Coins
    the_map[3].coins[0][YVALUE] = 21;
    the_map[3].coins[0][XVALUE] = 21;
    the_map[3].coins[0][EXIST] = TRUE;
    the_map[3].coins[1][YVALUE] = 21;
    the_map[3].coins[1][XVALUE] = 26;
    the_map[3].coins[1][EXIST] = TRUE;

    the_map[3].coins_green[0][YVALUE] = 21;
    the_map[3].coins_green[0][XVALUE] = 22;
    the_map[3].coins_green[0][EXIST] = TRUE;
    the_map[3].coins_green[1][YVALUE] = 21;
    the_map[3].coins_green[1][XVALUE] = 25;
    the_map[3].coins_green[1][EXIST] = TRUE;

    the_map[3].coins_blue[0][YVALUE] = 21;
    the_map[3].coins_blue[0][XVALUE] = 23;
    the_map[3].coins_blue[0][EXIST] = TRUE;
    the_map[3].coins_blue[1][YVALUE] = 21;
    the_map[3].coins_blue[1][XVALUE] = 24;
    the_map[3].coins_blue[1][EXIST] = TRUE;

    //Castle guide
    the_map[3].grid[4][5]= 0;
    the_map[3].grid[5][5]= CHAR_FOREST_GUIDE2;

    //Guards
    the_map[3].grid[21][23] = GUARD_HALT;
    the_map[3].grid[21][24] = GUARD_HALT;
    the_map[3].grid[22][23] = 0;
    the_map[3].grid[22][24] = 0;

    the_map[3].exit[0] = 21;
    the_map[3].exit[1] = 27;

    the_map[3].grid[23][23]=NEXT_MAP;
    the_map[3].grid[23][24]=NEXT_MAP;

    the_map[3].grid[4][YVALUE] = PREVIOUS_MAP;
    the_map[3].grid[5][YVALUE] = PREVIOUS_MAP;


/*-----------------------------------------------------------------------------*/
/*----------------------------MAP 4 castle interior----------------------------*/
/*-----------------------------------------------------------------------------*/

        the_map[4].level = 4;
        the_map[4].hight = 30;
        the_map[4].width = 30;
        the_map[4].completed = 0;
        strcpy(the_map[4].map_file, "map/Castle_interior.bmp");

        the_map[4].start[0]=25;
        the_map[4].start[1]=14;

        the_map[4].char_maid[0][YVALUE] = 20;
        the_map[4].char_maid[0][XVALUE] = 21;
        the_map[4].char_maid[0][EXIST] = TRUE;
        the_map[4].char_wizard[0][YVALUE] = 6;
        the_map[4].char_wizard[0][XVALUE] = 14;
        the_map[4].char_wizard[0][EXIST] = TRUE;

        the_map[4].shield[0][YVALUE] = 23;
        the_map[4].shield[0][XVALUE] = 9;
        the_map[4].shield[0][EXIST] = TRUE;

        the_map[4].spell[0][YVALUE] = 7;
        the_map[4].spell[0][XVALUE] = 14;
        the_map[4].spell[0][EXIST] = FALSE;

        the_map[4].wand[0][YVALUE] = 11;
        the_map[4].wand[0][XVALUE] = 14;
        the_map[4].wand[0][EXIST] = TRUE;

        //Coins
        for(i = 12, j = 0; i <= 17 && j < 6; i++, j++){
            the_map[4].coins[j][YVALUE] = i;
            the_map[4].coins[j][XVALUE] = 19;
            the_map[4].coins[j][EXIST] = TRUE;
        }
        for(i = 15, j = 0; i <= 19 && j < 5; i++, j++){
            the_map[4].coins_blue[j][YVALUE] = 12;
            the_map[4].coins_blue[j][XVALUE] = i;
            the_map[4].coins_blue[j][EXIST] = TRUE;
        }

        for(i = 15, j = 0; i <= 20 && j < 6; i++, j++){
            the_map[4].coins_green[j][YVALUE] = 20;
            the_map[4].coins_green[j][XVALUE] = i;
            the_map[4].coins_green[j][EXIST] = TRUE;
        }
        for(i = 20, j = 0; i <= 23 && j < 4; i++, j++){
            the_map[4].coins_green[j][YVALUE] = i;
            the_map[4].coins_green[j][XVALUE] = 14;
            the_map[4].coins_green[j][EXIST] = TRUE;
        }
        for(i = 9, j = 5; i <= 10 && j < 7; i++, j++){
            the_map[4].coins_blue[j][YVALUE] = 22;
            the_map[4].coins_blue[j][XVALUE] = i;
            the_map[4].coins_blue[j][EXIST] = TRUE;
        }
        the_map[4].coins_blue[7][YVALUE] = 23;
        the_map[4].coins_blue[7][XVALUE] = 10;
        the_map[4].coins_blue[7][EXIST] = TRUE;

    for (i = 0; i<=30; i++){
        for (j = 0; j<=30; j++){
            the_map[4].grid [i][j] = 0;
        }
    }


    for (i = 3; i<=23; i++){
        for (j = 2; j<=26; j++){
            the_map[4].grid [i][j] = 1;
        }
    }

    //top left wall benches
    for (i = 3; i<=12; i++){
            the_map[4].grid [i][2] = 0;
    }

    //left chair and chest
    for (i = 4; i<=5; i++){
        for (j = 10; j<=13; j++){
            the_map[4].grid [i][j] = 0;
        }
    }
    //right chair and chest
    for (i = 4; i<=5; i++){
        for (j = 15; j<=18; j++){
            the_map[4].grid [i][j] = 0;
        }
    }

    //desk and seats
    for (i = 8; i<=10; i++){
        for (j = 13; j<=15; j++){
            the_map[4].grid [i][j] = 0;
        }
    }

    //piano and seat
    the_map[4].grid [5][25] = 0;
    for (i = 3; i<=4; i++){
        for (j = 24; j<=26; j++){
            the_map[4].grid [i][j] = 0;
        }
    }

    //wall weapons
    for (i = 8; i<=16; i++){
            the_map[4].grid [i][23] = 0;
    }

    //walls next to weapons
    for (i = 8; i<=18; i++){
        for (j = 24; j<=26; j++){
            the_map[4].grid [i][j] = 0;
        }
    }

    //wooden door entrance
    the_map[4].grid [18][25] = 1;



    //mid walls and drinks
    for (i = 13; i<=17; i++){
        for (j = 2; j<=15; j++){
            the_map[4].grid [i][j] = 0;
        }
    }

    //yellow box bottom left
    for (i = 21; i<=23; i++){
        for (j = 2; j<=5; j++){
            the_map[4].grid [i][j] = 0;
        }
    }

    //brown box bottom left
    for (i = 22; i<=23; i++){
        for (j = 6; j<=8; j++){
            the_map[4].grid [i][j] = 0;
        }
    }

    //plant bottom right
    the_map[4].grid [23][26] = 0;


    //white stone stairs
    the_map[4].grid [22][25] = 0;

    //main entrance
    for (i = 24; i<=29; i++){
        for (j = 13; j<=16; j++){
            the_map[4].grid [i][j] = 1;
        }
    }
    the_map[4].grid[2][14]=0;
    //the_map[4].grid[2][14]=NEXT_MAP;


    for(j = 13; j<=16; j++){
        the_map[4].grid[29][j] = PREVIOUS_MAP;
    }

    for(j = 2; j<=15; j++){
        the_map[4].grid[18][j] = map_4_vending_interaction;
    }

    the_map[4].grid[20][21]=0;
    the_map[4].grid[20][20]= CHAR_MAID;
    the_map[4].grid[6][14]=0;
    the_map[4].grid[7][14]=0;
    the_map[4].grid[23][9]=0;
    the_map[4].grid[23][10]=SHIELD;
    the_map[4].grid[22][9]=SHIELD;

    for(j = 13; j < 16; j++){
        the_map[4].grid[12][j] = CHAR_WIZARD;
    }
    for(j = 13; j < 16; j++){
        the_map[4].grid[11][j] = 0;
   }



}




