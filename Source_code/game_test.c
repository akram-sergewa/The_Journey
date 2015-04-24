/*------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------GAME_TEST.c-----------------------------------------------------*/
/*-----------------THE TEST FILE FOR CHECKING THE EXISTENCE OF THE BMP FILES AND FURTHER DEBIGGING FOR SDL----------------*/
/*------------------------------------------------------------------------------------------------------------------------*/


void testSDL(int boolean){

    if(boolean == TRUE){
        printf("\n\t\t  ***** Pre-load Debug Mode:  - ON -  *****\n\n\n");
        FILE *resource_list = fopen("resource_list.txt", "r");

        if(resource_list == NULL){

            fprintf(stderr, "\tFile I/O_Error: Couldn't open 'resource_list.txt'\n\t%s\n\n", strerror(errno) );
            printf("\n\t--- Press Enter to continue ---\n\n");
            while (getchar()!= '\n'){}
        }
        else{
            char Name_of_File[80], *END_OF_SURFACE = "END_OF_SURFACE", *END_OF_MIXER = "END_OF_MIXER", *END_OF_TTF = "END_OF_TTF";
            int running = 1;

            loadAfterColon(resource_list);
            while(running == 1){
                fscanf(resource_list, "%s", Name_of_File);
                if(strcmp(Name_of_File, END_OF_SURFACE) != 0){
                    testSDLSufaces(Name_of_File);
                }
                else{
                    running++;
                }
            }
            loadAfterColon(resource_list);
            while(running == 2){
                fscanf(resource_list, "%s", Name_of_File);

                if(strcmp(Name_of_File, END_OF_MIXER) != 0){
                    testSDLMix(Name_of_File);
                }
                else{
                    running++;
                }
            }
            loadAfterColon(resource_list);
            while(running == 3){
                fscanf(resource_list, "%s", Name_of_File);

                if(strcmp(Name_of_File, END_OF_TTF) != 0){
                    testSDLTTF(Name_of_File);
                }
                else{
                    running++;
                }
            }
        }//else
        printf("\n   ***** Pre-load Debug Mode:  - ALL RESOURCES CHECKED -  *****\n\n\n");
    }
    else{
        printf("\n\t\t  ***** Pre-load Debug Mode:  - OFF -  *****\n\n\n");
    }

}

void testSDLSufaces ( char *name){

    SDL_Surface* loading = SDL_LoadBMP(name);

    if (loading == NULL){
        //keep the output print in this format, because sometimes SDL_GetError does not show the actual error, same for other functions below.
        printf( "  SDL_Error: Couldn't open %s\n  %s\n\n",name, SDL_GetError() );
        printf("\n\t--- Press Enter to continue ---\n\n");
        while (getchar()!= '\n'){}
    }
    SDL_free(loading);
}

void testSDLMix(char* name){

    Mix_Chunk* sound_effect = Mix_LoadWAV(name);

    if (sound_effect == NULL){
        printf( "  MIX_Error: Couldn't open %s\n  %s\n\n", name, Mix_GetError() );
        printf("\n\t--- Press Enter to continue ---\n\n");
        while (getchar()!= '\n'){}
    }
    Mix_FreeChunk(sound_effect);
}

void testSDLTTF( char *name){

    TTF_Font* font = TTF_OpenFont(name,18);

    if (font == NULL){
        printf( "  TTF_Error: Couldn't open %s\n  %s\n\n",name, SDL_GetError()  );
        printf("\n\t--- Press Enter to continue ---\n\n");
        while (getchar()!= '\n'){}
    }

}

void loadAfterColon(FILE* loadGame){

    char c;
    do{
        c = fgetc(loadGame);
    }while (c != ':');

}




