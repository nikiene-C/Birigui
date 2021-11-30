﻿#include "structs.h"
#include "constantes.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void initBot(Player& b) {
	b.x = (width / 2) - 50;
	b.y = height / 8;
	b.width = 60;
	b.height = 25;

	b.sprite = al_load_bitmap("botSprite.png");
}

void initPlayer(Player& p) {
	p.id = JOGADOR;
	p.x = (width / 2) - 50;
	p.y = (3 * height) / 4;
	p.width = 60;
	p.height = 25;

	p.sprite = al_load_bitmap("playerSprite.png");
}

void initBall(Ball& b) {
	b.x = width / 2;
	b.y = height / 2;
	b.width = 20;
	b.height = 20;
	b.raio = 5.5;
	b.xDir = 1;
	b.yDir = 1;
}


void InitObstaculo(Obstaculo obstaculo[], int size) {
	for (int i = 0; i < size; i++) {
		obstaculo[i].ID = OBSTACULOS;
		obstaculo[i].velocidade = 1.0;
		obstaculo[i].status = MORTO;
	}
}

void CreateObstaculo(Obstaculo obstaculo[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		if (obstaculo[i].status == MORTO) {
			obstaculo[i].tipo = rand() % 2;
			obstaculo[i].posicao = rand() % 3;
			obstaculo[i].edgeRate = 1;
			obstaculo[i].edgeRate2 = 1;
			switch (obstaculo[i].posicao) {
			case 0:
				obstaculo[i].x1 = 280 + 25;
				obstaculo[i].y1 = 145;
				obstaculo[i].x2 = 280 + 30;
				obstaculo[i].y2 = 150;
				obstaculo[i].status = VIVO;
				break;
			case 1:
				obstaculo[i].x1 = 280 + 40;
				obstaculo[i].y1 = 145;
				obstaculo[i].x2 = 280 + 45;
				obstaculo[i].y2 = 150;
				obstaculo[i].status = VIVO;
				break;
			case 2:
				obstaculo[i].x1 = 280 + 55;
				obstaculo[i].y1 = 145;
				obstaculo[i].x2 = 280 + 70;
				obstaculo[i].y2 = 150;
				obstaculo[i].status = VIVO;
				break;
			case 3:
				obstaculo[i].status = MORTO;
			}
			return;
		}
	}
}

void UpdateObstaculo(Obstaculo obstaculo[], int size) {
	for (int i = 0; i < size; i++) {
		if (obstaculo[i].status == VIVO) {
			obstaculo[i].y1 += obstaculo[i].velocidade;
			obstaculo[i].y2 += obstaculo[i].velocidade + obstaculo[i].edgeRate2;
			obstaculo[i].edgeRate2 += (double) 0.15;
			if (obstaculo[i].posicao == 0) {
				obstaculo[i].x1 -= obstaculo[i].edgeRate;
				obstaculo[i].x2 -= obstaculo[i].edgeRate / 2;
				obstaculo[i].edgeRate += 0.29;
			}
			else if (obstaculo[i].posicao == 1) {
				obstaculo[i].x1 -= obstaculo[i].edgeRate / 2;
				obstaculo[i].x2 += obstaculo[i].edgeRate / 2;
				obstaculo[i].edgeRate += 0.15;
			}
			else if (obstaculo[i].posicao == 2) {
				obstaculo[i].x1 += obstaculo[i].edgeRate / 2;
				obstaculo[i].x2 += obstaculo[i].edgeRate;
				obstaculo[i].edgeRate += 0.29;
			}
			obstaculo[i].velocidade += 0.5;
			if (obstaculo[i].y1 < 150 && obstaculo[i].y1 < 250) {
				obstaculo[i].velocidade -= 0.01;
			}
			else if (obstaculo[i].y1 >= 150 && obstaculo[i].y1 < 315) {
				obstaculo[i].velocidade += 0.15;
			}
			else if (obstaculo[i].y1 >= 315 && obstaculo[i].y1 <= 500) {
				obstaculo[i].velocidade += 0.01;
			} if (obstaculo[i].y1 > height) {
				obstaculo[i].status = MORTO;
				obstaculo[i].velocidade = 1;
				obstaculo[i].edgeRate = 1;
				obstaculo[i].edgeRate2 = 1;
			}
		}
	}
}

void InitJogador(Jogador& jogador) {
	jogador.ID = JOGADOR;

	jogador.posicao = MEIO;

	jogador.x1 = 295; //25
	jogador.x2 = 345; //25
	jogador.y1 = 450; //parte inferior da tela "chao"
	jogador.y2 = 375; //chao + 75

	jogador.status = VIVO;
}

int endgame(int PL, int BL) {
	if (PL <= 0) {
		printf_s("você Ganhou! Deseja começar de novo?");
		return 1;
	}
	else if (BL <= 0) {
		printf_s("você Perdeu! Deseja começar de novo?");
		return 0;
	}
}