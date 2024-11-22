#pragma once

#ifndef CACHE
#define CACHE

#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define HOST     "127.0.0.1"
#define PORT     "12000"

typedef unsigned int int32;
typedef unsigned short int16;
typedef unsigned char int8;

struct s_client {
	int s;
	char ip[16];
	int16 port;
};

typedef struct s_client Client;

void mainloop(int);
int initserver(int16);

#endif;
