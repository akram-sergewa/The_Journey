/*------------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------GAME_SAVE.C------------------------------------------------------*/
/*----------------------------------THIS FILE CONTAINS THE SAVE AND LOAD GAME FUNCTIONS-----------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------*/

int saveGame(FILE* file, MOVEMENT *Movement, MAP *Maps, CHARACTER *currentCharacter )
{
if (file != NULL) {
    fwrite(Movement, sizeof(MOVEMENT), 1, file);
    fwrite(Maps, sizeof(MAP), 2, file);
    fwrite(currentCharacter, sizeof(CHARACTER), 1, file);
    fclose(file);
    return 1;
}else{
return 0;
}
}


int loadGame(FILE* file, MOVEMENT *Movement, MAP *Maps, CHARACTER *currentCharacter )
{
if (file != NULL) {
    fread(Movement, sizeof(MOVEMENT), 1, file);
    fread(Maps, sizeof(MAP), 2, file);
    fread(currentCharacter, sizeof(CHARACTER), 1, file);
    fclose(file);
    return 1;
}else{
return 0;
}
}


/*----------------------------------------------------------------------------------------------*/
/*--------ANALYZE THE TYPED LINE AND EXTRACT THE FILE NAME IN CASE OF SAVE AND LOAD GAME--------*/
/*----------------------------------------------------------------------------------------------*/
int getFilename (char *File_name, char* the_string)
{
    char temp[11];
    temp[10] = '\0';
    for (int i =0; i<10;i++)
    {
        temp[i] = the_string[i];
    }


    if (!strcmp(temp,"Load.Game("))
        {
    int counter = 10;
    int file_counter = 0;
    while (the_string[counter] != '\0' && the_string[counter] != ')')
    {
        File_name[file_counter++] = the_string[counter++];
        File_name[file_counter] = '\0';
        if (file_counter >=FILE_MAX)
        {
            return MOREMAXFILE;
        }
    }
    return LOADGAME;
        } else if (!strcmp(temp,"Save.Game("))
        {
    int counter = 10;
    int file_counter = 0;
    while (the_string[counter] != '\0' && the_string[counter] != ')')
    {
        File_name[file_counter++] = the_string[counter++];
        File_name[file_counter] = '\0';
        if (file_counter >=FILE_MAX)
        {
            return MOREMAXFILE;
        }
    }
    return SAVEGAME;
        }

return FALSE;
}
