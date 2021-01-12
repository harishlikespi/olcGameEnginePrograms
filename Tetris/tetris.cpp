#define OLC_PGE_APPLICATION
#include <iostream>
#include "olcPixelGameEngine.h"
#include <conio.h>



class Example : public olc::PixelGameEngine
{




public:
	Example()
	{
		sAppName = "Test";
	}
	

public:
    int height = 20;
    int width = 10;
    struct coord {
        int x;
        int y;
    };

    coord X1{ 0,0 };
    coord X2{ 1,0 };
    coord X3{ 0,1 };
    coord X4{ 1,1 };
    coord X5{ 2,0 };
    coord X6{ 2,1 };
    bool cont = true;
    int randn;
    int selec = 3;
    int cnt = 1;
    int seq;
    int score;


    int gameboard[20][10];
    void clearRow(int row) {
        int sec = 0;
        for (int c = 0; c < width; c++) {
            if (gameboard[row][c] == 2) {
                sec++;
            }
            seq = sec;
        }
    }

    void clr(int row) {
        clearRow(row);
        if (seq == width) {
            score += 100;
            for (int r = 0; r < width; r++) {
                gameboard[row][r] = 0;
            }
            for (int x = row; x > 0; x--) {
                for (int y = 0; y < width; y++) {
                    if (gameboard[x - 1][y] == 2) {
                        gameboard[x][y] = 2;
                        gameboard[x - 1][y] = 0;
                    }
                }
            }
        }
    }

    void input() {
        bool x = true;
        switch (x) {
        case 'a':
            X1.y--;
            X2.y--;
            X3.y--;
            X4.y--;
            X5.y--;
            X6.y--;

            break;
        case 's':
            X1.x++;
            X2.x++;
            X3.x++;
            X4.x++;
            X5.x++;
            X6.x++;
            break;

        case 'd':
            X1.y++;
            X2.y++;
            X3.y++;
            X4.y++;
            X5.y++;
            X6.y++;
            break;

        case 'x':
            cont = false;
        }
    }

    void drawLine() {
        if (X2.x != height - 1) {
            if (gameboard[X2.x + 1][X2.y] != 2) {
                for (int x = 0; x < height; x++) {
                    for (int y = 0; y < width; y++) {
                        if (x == X1.x && y == X1.y || (x == X2.x && y == X2.y)) {
                            gameboard[x][y] = 1;

                        }
                        else {
                            if (gameboard[x][y] != 2)
                                gameboard[x][y] = 0;
                        }
                    }
                }
            }
            else if (gameboard[X2.x + 1][X1.y] == 2) {
                gameboard[X1.x][X1.y] = 2;
                gameboard[X2.x][X2.y] = 2;
                X1 = { 0,0 };
                X2 = { 1,0 };


            }
        }
        else if (X2.x == height - 1) {
            gameboard[X1.x][X1.y] = 2;
            gameboard[X2.x][X2.y] = 2;
            X1 = { 0,0 };
            X2 = { 1,0 };
        }

        for (int row = 0; row < height; row++) {
            clr(row);
        }
    }


    void drawSquare() {
        if (X2.x != height - 1) {
            if (gameboard[X2.x + 1][X2.y] != 2 && gameboard[X4.x + 1][X4.y] != 2) {
                for (int x = 0; x < height; x++) {
                    for (int y = 0; y < width; y++) {
                        if (x == X1.x && y == X1.y || (x == X2.x && y == X2.y) || (x == X3.x && y == X3.y) || (x == X4.x && y == X4.y)) {
                            gameboard[x][y] = 1;

                        }
                        else {
                            if (gameboard[x][y] != 2)
                                gameboard[x][y] = 0;
                        }
                    }
                }
            }
            else if ((gameboard[X2.x + 1][X2.y] == 2) || gameboard[X4.x + 1][X4.y] == 2) {
                gameboard[X1.x][X1.y] = 2;
                gameboard[X2.x][X2.y] = 2;
                gameboard[X3.x][X3.y] = 2;
                gameboard[X4.x][X4.y] = 2;
                X1 = { 0,0 };
                X2 = { 1,0 };
                X3 = { 0,1 };
                X4 = { 1,1 };
            }
        }
        else if (X2.x == height - 1) {
            gameboard[X1.x][X1.y] = 2;
            gameboard[X2.x][X2.y] = 2;
            gameboard[X3.x][X3.y] = 2;
            gameboard[X4.x][X4.y] = 2;
            X1 = { 0,0 };
            X2 = { 1,0 };
            X3 = { 0,1 };
            X4 = { 1,1 };
        }

        for (int row = 0; row < height; row++) {
            clr(row);
        }
    }

    void drawL() {
        if (X5.x != height - 1) {
            if (gameboard[X5.x + 1][X5.y] != 2 && gameboard[X6.x + 1][X6.y] != 2) {
                for (int x = 0; x < height; x++) {
                    for (int y = 0; y < width; y++) {
                        if (x == X1.x && y == X1.y || (x == X2.x && y == X2.y) || (x == X5.x && y == X5.y) || (x == X6.x && y == X6.y)) {
                            gameboard[x][y] = 1;

                        }
                        else {
                            if (gameboard[x][y] != 2)
                                gameboard[x][y] = 0;
                        }
                    }
                }
            }
            else if (gameboard[X5.x + 1][X5.y] == 2 || gameboard[X6.x + 1][X6.y] == 2) {
                gameboard[X1.x][X1.y] = 2;
                gameboard[X2.x][X2.y] = 2;
                gameboard[X5.x][X5.y] = 2;
                gameboard[X6.x][X6.y] = 2;
                X1 = { 0,0 };
                X2 = { 1,0 };
                X5 = { 2,0 };
                X6 = { 2,1 };
            }
        }
        else if (X5.x == height - 1) {
            gameboard[X1.x][X1.y] = 2;
            gameboard[X2.x][X2.y] = 2;
            gameboard[X5.x][X5.y] = 2;
            gameboard[X6.x][X6.y] = 2;
            X1 = { 0,0 };
            X2 = { 1,0 };
            X5 = { 2,0 };
            X6 = { 2,1 };
        }

        for (int row = 0; row < height; row++) {
            clr(row);
        }
    }


  
        

   






	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

        olc::vf2d pos(30, 30);
        
        
        if (GetKey(olc::Key::A).bPressed) {
            X1.y--;
            X2.y--;
            X3.y--;
            X4.y--;
            X5.y--;
            X6.y--;
        }  else {
            X1.x++;
            X2.x++;
            X3.x++;
            X4.x++;
            X5.x++;
            X6.x++;
        }
        DrawString(pos, " " + X1.y, olc::BLUE);
		// called once per frame
        
        for (int x = 0; x < 20; x++) {
            for (int y = 0; y < 10; y++) {
                if (gameboard[x][y] == 0) {
                    Draw(x, y, olc::Pixel(100, 255, 100));
                }
                else if (gameboard[x][y] == 1) {
                    Draw(x, y, olc::Pixel(255, 255, 100));
                } 
                else if (gameboard[x][y] == 2) {
                    Draw(x, y, olc::Pixel(30, 225, 200));
                }
            }
        }
		
	}
        
};



int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}
