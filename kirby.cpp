#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <mmsystem.h>
#include <mmsyscom.h>
#pragma comment(lib, "Winmm.lib")

// value
#define MAP_WIDTH 900
#define MAP_LENGTH 600
#define BOX_SIDE 50
#define LINE 9
#define COLUMN 12
#define X_START 100
#define Y_START 100
// operation
#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'
#define QUIT 'q'
#define RETRY 'r'

#define isvalid(next) (next.x >= 0 && next.x < LINE && next.y >= 0 && next.y < COLUMN)
typedef enum DIRECTION DIRECTION;
typedef struct POS POS;

enum PROPS {
	WALL,
	FLOOR,
	DES,
	MAN,
	CBOX,
	RBOX,
	ABOX,
	CHIT,
	RHIT,
	AHIT,
	ALL
};

enum DIRECTION {
	U,
	D,
	L,
	R
};

struct POS {
	int x;
	int y;
};


// game map using 2D-array
// 0 represents wall; 1 represents floor; 2 represents destination for box;
//		3 represents character; 4 to 9 respectively represent C, R, A box
int map[LINE][COLUMN] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 2, 2, 1, 1, 1, 2, 2, 0, 0},
	{0, 1, 4, 1, 0, 1, 1, 0, 1, 1, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0, 5, 1, 1, 0},
	{0, 1, 0, 1, 0, 1, 1, 6, 1, 1, 1, 0},
	{0, 1, 1, 1, 0, 3, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 0},
	{0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int map2[LINE][COLUMN] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 2, 2, 1, 1, 1, 2, 2, 0, 0},
	{0, 1, 4, 1, 0, 1, 1, 0, 1, 1, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0, 5, 1, 1, 0},
	{0, 1, 0, 1, 0, 1, 1, 6, 1, 1, 1, 0},
	{0, 1, 1, 1, 0, 3, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 0},
	{0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


IMAGE images[ALL];

// character location:
POS man = { 0,0 };

bool is_over() {
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (map[i][j] == DES) {
				return false;
			}
		}	
	}
	return true;
}


void change_map(POS *pos, PROPS prop) {
	map[pos->x][pos->y] = prop;
	putimage(X_START + pos->y * BOX_SIDE, Y_START + pos->x * BOX_SIDE, &images[prop]);
}

void game_control(DIRECTION op) {
	POS next = man;
	POS next_next = man;

	switch(op) {
	case U:
		next.x --;
		next_next.x -= 2;
		break;
	case D:
		next.x ++;
		next_next.x += 2;
		break;
	case L:
		next.y --;
		next_next.y -= 2; 
		break;
	case R:
		next.y ++;
		next_next.y += 2;
		break;
	}

	if (isvalid(next) && map[next.x][next.y] == FLOOR) {
		change_map(&next, MAN);
		change_map(&man, FLOOR);
		man = next;
	}

	if (isvalid(next) && map[next.x][next.y] == RBOX) {
		if (isvalid(next_next) && map[next_next.x][next_next.y] == FLOOR) {
			change_map(&next_next, RBOX);
			change_map(&next, MAN);
			change_map(&man, FLOOR);
			man = next;
		}
		else if (isvalid(next_next) && map[next_next.x][next_next.y] == DES) {
			change_map(&next_next, RHIT);
			change_map(&next, MAN);
			change_map(&man, FLOOR);
			man = next;
		}
	}
	else if (isvalid(next) && map[next.x][next.y] == CBOX) {
		if (isvalid(next_next) && map[next_next.x][next_next.y] == FLOOR) {
			change_map(&next_next, CBOX);
			change_map(&next, MAN);
			change_map(&man, FLOOR);
			man = next;
		}
		else if (isvalid(next_next) && map[next_next.x][next_next.y] == DES) {
			change_map(&next_next, CHIT);
			change_map(&next, MAN);
			change_map(&man, FLOOR);
			man = next;
		}
	}
	else if (isvalid(next) && map[next.x][next.y] == ABOX) {
		if (isvalid(next_next) && map[next_next.x][next_next.y] == FLOOR) {
			change_map(&next_next, ABOX);
			change_map(&next, MAN);
			change_map(&man, FLOOR);
			man = next;
		}
		else if (isvalid(next_next) && map[next_next.x][next_next.y] == DES) {
			change_map(&next_next, AHIT);
			change_map(&next, MAN);
			change_map(&man, FLOOR);
			man = next;
		}
	}
}

int main(void) {
	IMAGE background_img;	
	IMAGE begin1;
	IMAGE begin2;
	IMAGE begin3;
	IMAGE begin4;
	IMAGE end;
	// initialize the map
	initgraph(MAP_WIDTH, MAP_LENGTH);
	mciSendString("open bgm1.mp3", NULL, 0, NULL);
	mciSendString("play bgm1.mp3 repeat", NULL, 0, NULL);
	loadimage(&begin1, "begin1.jpg", MAP_WIDTH, MAP_LENGTH, true);
	putimage(0, 0, &begin1);
	int check = 2;
		while (true) {
			char key = _getch();
			if (key && check == 0) {
				loadimage(&begin4, "begin4.jpg", MAP_WIDTH, MAP_LENGTH, true);
				putimage(0, 0, &begin4);
				check--;
			}
			else if (key && check == 2) {
				loadimage(&begin2, "begin2.jpg", MAP_WIDTH, MAP_LENGTH, true);
				putimage(0, 0, &begin2);
				check--;
			}
			else if (key && check == 1) {
				loadimage(&begin3, "begin3.jpg", MAP_WIDTH, MAP_LENGTH, true);
				putimage(0, 0, &begin3);
				check--;
			} 
			else if (check < 0) {
				mciSendString("close bgm1.mp3", 0, 0, 0);
				break;
			}
		}
		bool retry = false;
		bool quit = false;
		while (retry != true && quit != true) {
			for (int i = 0; i < LINE; i++) {
				for (int j = 0; j < COLUMN; j++) {
					map[i][j] = map2[i][j];
				}
			}
	mciSendString("open bgm2.mp3", NULL, 0, NULL);
	mciSendString("play bgm2.mp3 repeat", NULL, 0, NULL);
		loadimage(&background_img, "bg.bmp", MAP_WIDTH, MAP_LENGTH, true);
		putimage(0, 0, &background_img);
		// place box, character, floor, etc
		loadimage(&images[WALL], "wall_right.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[FLOOR], "floor.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[DES], "des.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[MAN], "man.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[CBOX], "C_BOX.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[RBOX], "R_BOX.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[ABOX], "A_BOX.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[CHIT], "C_BOX.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[RHIT], "R_BOX.bmp", BOX_SIDE, BOX_SIDE, true);
		loadimage(&images[AHIT], "A_BOX.bmp", BOX_SIDE, BOX_SIDE, true);

		for (int i = 0; i < LINE; i++) {
			for (int j = 0; j < COLUMN; j++) {
				if (map[i][j] == MAN) {
					man.x = i;
					man.y = j;
				}
				putimage(X_START + j * BOX_SIDE, Y_START + i * BOX_SIDE,
					&images[map[i][j]]);
			}
		}

		do {
			if (_kbhit()) {
				char ch = _getch();
				if (ch == UP) {
					game_control(U);
				}
				else if (ch == DOWN) {
					game_control(D);
				}
				else if (ch == LEFT) {
					game_control(L);
				}
				else if (ch == RIGHT) {
					game_control(R);
				}
				else if (ch == QUIT) {
					HWND hnd = GetHWnd(); 
					int result = MessageBox(hnd, "Do you want to quit?", "Confirmation", MB_YESNO | MB_DEFBUTTON2);
					if (result == IDYES) {
						quit = true;
					}
				}
				else if (ch == RETRY) {
					HWND hnd = GetHWnd();
					int result = MessageBox(hnd, "Do you want to retry?", "Confirmation", MB_YESNO | MB_DEFBUTTON2);
					if (result == IDYES) {
						mciSendString("close bgm2.mp3", 0, 0, 0);
						break;
					}
				}
				if (is_over()) {
					mciSendString("close bgm2.mp3", 0, 0, 0);
					mciSendString("open bgm3.mp3", NULL, 0, NULL);
					mciSendString("play bgm3.mp3 repeat", NULL, 0, NULL);
					loadimage(&end, "end.jpg", MAP_WIDTH, MAP_LENGTH, true);
					putimage(0, 0, &end);
					retry = true;
				}
			}
			// rest
			Sleep(100);
		} while (quit != true);
		if (retry == true) {
			system("pause");
			return 0;
		}
	}
}