#pragma once
#include "structs.h"
#include "constantes.h"

extern int PL;
extern int BL;


void initBot(Player& b);

void initPlayer(Player& p);

void initBall(Ball& b);

void InitObstaculo(Obstaculo obstaculo[], int size);

void CreateObstaculo(Obstaculo obstaculo[], int size);

void UpdateObstaculo(Obstaculo obstaculo[], int size);

void InitJogador(Jogador& jogador);

bool endgame(int PL, int BL);
