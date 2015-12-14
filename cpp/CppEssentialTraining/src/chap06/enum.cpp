// author: madoodia@gmail.com
// Deck of Cards
#include <iostream>
#include <stdio.h>

using namespace std;

enum card_suit {SPD, HRT, DIA, CLB};
enum card_rank {ACE = 1, JACK = 11, QUEEN = 12, KING = 13};

const string ace_string = "Ace";
const string jck_string = "Jack";
const string que_string = "Queen";
const string kng_string = "King";
const string spd_string = "Spades";
const string hrt_string = "Hearts";
const string dia_string = "Diamonds";
const string clb_string = "Clubs";

struct card{
	unsigned char r;
	unsigned char s;
};

card deck[52] = {
		{ACE, SPD},{2, SPD},{3, SPD},{4, SPD},{5, SPD},{6, SPD},{7, SPD},{8, SPD},{9, SPD},{10, SPD},{JACK, SPD},{QUEEN, SPD},{KING, SPD},
		{ACE, HRT},{2, HRT},{3, HRT},{4, HRT},{5, HRT},{6, HRT},{7, HRT},{8, HRT},{9, HRT},{10, HRT},{JACK, HRT},{QUEEN, HRT},{KING, HRT},
		{ACE, DIA},{2, DIA},{3, DIA},{4, DIA},{5, DIA},{6, DIA},{7, DIA},{8, DIA},{9, DIA},{10, DIA},{JACK, DIA},{QUEEN, DIA},{KING, DIA},
		{ACE, CLB},{2, CLB},{3, CLB},{4, CLB},{5, CLB},{6, CLB},{7, CLB},{8, CLB},{9, CLB},{10, CLB},{JACK, CLB},{QUEEN, CLB},{KING, CLB},
};

void print_card(const card &c);

int main(int argc, char **argv)
{
	for(int i = 0;i < 52;i++){
		print_card(deck[i]);
	}
	return 0;
}

void print_card(const card &c)
{
	if(c.r >= 2 && c.r <= 10){
		printf("%d", c.r);
	} else{
		switch(c.r){
		case ACE:
			cout << ace_string;
			break;
		case JACK:
			cout << jck_string;
			break;
		case QUEEN:
			cout << que_string;
			break;
		case KING:
			cout << kng_string;
			break;
		}
	}
	cout << " of ";

	switch(c.s){
	case SPD:
		cout << spd_string;
		break;
	case HRT:
		cout << hrt_string;
		break;
	case DIA:
		cout << dia_string;
		break;
	case CLB:
		cout << clb_string;
		break;
	}
	cout << endl;
}
