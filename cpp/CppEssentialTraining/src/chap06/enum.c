// author: madoodia@gmail.com
// Deck of Cards
#include <stdio.h>

enum card_suit {SPD, HRT, DIA, CLB};
enum card_rank {ACE = 1, JACK = 11, QUEEN = 12, KING = 13};

const char * ace_string = "Ace";
const char * jck_string = "Jack";
const char * que_string = "Queen";
const char * kng_string = "King";
const char * spd_string = "Spades";
const char * hrt_string = "Hearts";
const char * dia_string = "Diamonds";
const char * clb_string = "Clubs";

typedef struct card{
	unsigned char r;
	unsigned char s;
}card_t;

card_t deck[52] = {
		{ACE, SPD},{2, SPD},{3, SPD},{4, SPD},{5, SPD},{6, SPD},{7, SPD},{8, SPD},{9, SPD},{10, SPD},{JACK, SPD},{QUEEN, SPD},{KING, SPD},
		{ACE, HRT},{2, HRT},{3, HRT},{4, HRT},{5, HRT},{6, HRT},{7, HRT},{8, HRT},{9, HRT},{10, HRT},{JACK, HRT},{QUEEN, HRT},{KING, HRT},
		{ACE, DIA},{2, DIA},{3, DIA},{4, DIA},{5, DIA},{6, DIA},{7, DIA},{8, DIA},{9, DIA},{10, DIA},{JACK, DIA},{QUEEN, DIA},{KING, DIA},
		{ACE, CLB},{2, CLB},{3, CLB},{4, CLB},{5, CLB},{6, CLB},{7, CLB},{8, CLB},{9, CLB},{10, CLB},{JACK, CLB},{QUEEN, CLB},{KING, CLB},
};

void print_card(const card_t *c);

int main(int argc, char **argv)
{
	for(int i = 0;i < 52;i++){
		print_card(&deck[i]);
	}
	return 0;
}

void print_card(const card_t *c)
{
	if(c->r >= 2 && c->r <= 10){
		printf("%d", c->r);
	} else{
		switch(c->r){
		case ACE:
			fputs(ace_string, stdout);
			break;
		case JACK:
			fputs(jck_string, stdout);
			break;
		case QUEEN:
			fputs(que_string, stdout);
			break;
		case KING:
			fputs(kng_string, stdout);
			break;
		}
	}
	fputs(" of ", stdout);

	switch(c->s){
	case SPD:
		fputs(spd_string, stdout);
		break;
	case HRT:
		fputs(hrt_string, stdout);
		break;
	case DIA:
		fputs(dia_string, stdout);
		break;
	case CLB:
		fputs(clb_string, stdout);
		break;
	}
	fputs("\n", stdout);
}
