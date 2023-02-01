#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int save(image img, char* nomFichier)
{
    int x = img.sizeX;
    int y = img.sizeY;

    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "r+");

    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        fprintf(fichier,"P3\n%d %d\n255\n",x,y);

        for(int i=0;i<x;i++) //on recup les couleurs via dans le tab 2 dimensions
        {
            for(int u=0;u<y;u++)
            {
                unsigned char r = img.tab[i][u].r;
                unsigned char v = img.tab[i][u].v;
                unsigned char b = img.tab[i][u].b;
                fprintf(fichier,"%d\t%d\t%d\n",r,v,b);//on écrit les couleurs r g b = 0 0 0 = 1 pixel
            }
            fprintf(fichier,"\n");
        }
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}

image init(int sizeX,int sizeY)
{

    image img;
    img.sizeX = sizeX;
    img.sizeY = sizeY;

    img.tab = malloc(sizeof(pixel*)*sizeY); // alloue memoire pour ligne

    for(int i=0; i<sizeY;i++)
    {
        img.tab[i] = malloc(sizeof(pixel)*sizeX);//alloue memoire pour colonne
    }

    for(int i=0; i<sizeY;i++)
    {
        for(int j=0; j<sizeX;j++)
        {
            pixel pix = initPixel();
            img.tab[i][j] = pix;

        }
    }



    return img;
}

pixel initPixel()
{

    int resR = rand() % 256;
    int resB = rand() % 256;
    int resV = rand() % 256;

    pixel pix;
    pix.r = resR;
    pix.b = resB;
    pix.v = resV;

    return pix;
}







