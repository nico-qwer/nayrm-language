#include <stdio.h>
#include <stdlib.h>

//Counts the lines in a file
int countLines(char fileName[]) {
    FILE* sourceCodeStream = fopen(fileName, "r"); //Open file

    int lines = 0;
    int ch = 0;

    //Code snippet from https://stackoverflow.com/questions/12733105/c-function-that-counts-lines-in-file
    while (!feof(sourceCodeStream)) {
        ch = fgetc(sourceCodeStream);
        if (ch == '\n') {
            lines++;
        }
    }
    //End of code snippet

    fclose(sourceCodeStream); //Close file
    return lines;
}

int main(int argc, char* argv[]) {

    //====================== FILE OPENING ======================//
    FILE* sourceCodeStream = fopen(argv[1], "r"); //Open file

    if (sourceCodeStream == NULL) { perror("Unable to open file."); return 1; } //Make sure file is valid

    char sourceCode[countLines(argv[1])][255]; //Array of the lines of the file

    //Stores file contents in source code variable
    int i = 0;
    while (fgets(sourceCode[i], sizeof(sourceCode[0]), sourceCodeStream)) { i++; }

    fclose(sourceCodeStream); //Close file

    //====================== CODE EXECUTION ======================//

    //sizeof(sourceCode) / sizeof(sourceCode[0]) is for getting array lenght
    for (int i = 0; i < sizeof(sourceCode) / sizeof(sourceCode[0]); i++) {

    }

    return 0;
}
