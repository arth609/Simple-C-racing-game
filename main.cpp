#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int windowWidth = 800;
const int windowHeight = 600;
const int roadWidth = 200;
const int roadHeight = 600;
int roadSpeed = 5;

void moveCarLeft(int& x) {
    x -= 5;
    if (x < 0) {
        x = 0;
    }
}
void moveCarRight(int& x) {
    x += 5;
    if (x > windowWidth - 50) {
        x = windowWidth - 50;
    }
}

void drawCar(int x, int y) {
    setcolor(WHITE);
    rectangle(x, y, x + 50, y + 80);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 25, y + 40, WHITE);

    setcolor(WHITE);
    rectangle(x, y + 5, x - 7, y + 25);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x - 3, y + 15, WHITE);

    setcolor(WHITE);
    rectangle(x + 50, y + 5, x + 57, y + 25);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x - 3, y + 15, WHITE);

    setcolor(WHITE);
    rectangle(x + 50, y + 55, x + 57, y + 75);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x - 3, y + 15, WHITE);

    setcolor(WHITE);
    rectangle(x, y + 55, x - 7, y + 75);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x - 3, y + 15, WHITE);
}

void drawBackground(int roadY) {
    setfillstyle(WIDE_DOT_FILL, GREEN);  // трава
    bar(0, 0, (windowWidth - roadWidth) / 2, windowHeight);
    bar((windowWidth + roadWidth) / 2, 0, windowWidth, windowHeight); 

    setfillstyle(SOLID_FILL, RGB(128, 128, 128));  //дорога

    int numStripes = (windowHeight / 60) + 2;
    int startY = roadY % 60;
    for (int i = 0; i < numStripes; i++) {
        int y = startY + (i * 60);
        bar((windowWidth - roadWidth) / 2 + roadWidth / 2 - 10, y, \
       (windowWidth - roadWidth) / 2 + roadWidth / 2 + 10, y + 30);
    }
}

int main() {
    initwindow(windowWidth, windowHeight, "Racing Game", true);  
    setbkcolor(BLACK);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(windowWidth / 2 - 240, windowHeight / 4, \
   "I Need To Stop ");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(windowWidth / 2 - 300, windowHeight / 4 + 50, \
   "But I Have No Breaks");

    // start
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    int buttonX = windowWidth / 2 - 60;
    int buttonY = windowHeight / 2;
    int buttonWidth = 100;
    int buttonHeight = 50;
    rectangle(buttonX, buttonY, buttonX + buttonWidth + 40, \
   buttonY + buttonHeight);
    outtextxy(buttonX + 10, buttonY + 10, "START");

    //сложн
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int easyButtonX = windowWidth / 2 - 170;
    int easyButtonY = windowHeight / 2 + 80;
    int easyButtonWidth = 87;
    int easyButtonHeight = 50;
    rectangle(easyButtonX, easyButtonY, \
    easyButtonX + easyButtonWidth, easyButtonY + easyButtonHeight);
    outtextxy(easyButtonX + 10, easyButtonY + 10, "EASY");

    int mediumButtonX = windowWidth / 2 - 50;
    int mediumButtonY = windowHeight / 2 + 80;
    int mediumButtonWidth = 120;
    int mediumButtonHeight = 50;
    rectangle(mediumButtonX, mediumButtonY, \
    mediumButtonX + mediumButtonWidth, \
    mediumButtonY + mediumButtonHeight);
    
    outtextxy(mediumButtonX + 10, mediumButtonY + 10, "MEDIUM");

    int hardButtonX = windowWidth / 2 + 100;
    int hardButtonY = windowHeight / 2 + 80;
    int hardButtonWidth = 87;
    int hardButtonHeight = 50;
    rectangle(hardButtonX, hardButtonY, hardButtonX + hardButtonWidth, \
    hardButtonY + hardButtonHeight);
    outtextxy(hardButtonX + 10, hardButtonY + 10, "HARD");

    // ожид клик
    int mouseX, mouseY;
    int selectedButton = -1;
    int difficulty = 1;
    while (1) {
        delay(100);
        if (ismouseclick(WM_LBUTTONDOWN)) {
            mouseX = mousex();
            mouseY = mousey();
            if (mouseX >= buttonX && mouseX <= buttonX + buttonWidth\
               && mouseY >= buttonY && mouseY <= buttonY + buttonHeight) {
                if (selectedButton != -1) {
                    break;
                }
            }
            if (mouseX >= easyButtonX && mouseX <= easyButtonX + \
               easyButtonWidth && mouseY >= easyButtonY && mouseY \
            <= easyButtonY + easyButtonHeight) {
               
                selectedButton = 1;
                difficulty = 1;
            }
            if (mouseX >= mediumButtonX && mouseX <= mediumButtonX + \
               mediumButtonWidth && mouseY >= mediumButtonY && mouseY <= \
            mediumButtonY + mediumButtonHeight) {
               
                selectedButton = 2;
                difficulty = 2;
            }
            if (mouseX >= hardButtonX && mouseX <= hardButtonX + \
               hardButtonWidth && mouseY >= hardButtonY && mouseY <= \
            hardButtonY + hardButtonHeight) {
               
                selectedButton = 3;
                difficulty = 3;
            }
        }
        
        // смена цвета
        setcolor(WHITE);
        if (selectedButton == 1) {
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(easyButtonX + 1, easyButtonY + 1, WHITE);
        }
        else {
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(easyButtonX + 1, easyButtonY + 1, WHITE);
        }
        rectangle(easyButtonX, easyButtonY, easyButtonX +\
        easyButtonWidth,easyButtonY + easyButtonHeight);
        outtextxy(easyButtonX + 10, easyButtonY + 10, "EASY");

        if (selectedButton == 2) {
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(mediumButtonX + 1, mediumButtonY + 1, WHITE);
        }
        else {
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(mediumButtonX + 1, mediumButtonY + 1, WHITE);
        }
        rectangle(mediumButtonX, mediumButtonY, mediumButtonX + \
        mediumButtonWidth, mediumButtonY + mediumButtonHeight);
        outtextxy(mediumButtonX + 10, mediumButtonY + 10, "MEDIUM");

        if (selectedButton == 3) {
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(hardButtonX + 1, hardButtonY + 1, WHITE);
        }
        else {
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(hardButtonX + 1, hardButtonY + 1, WHITE);
        }
        rectangle(hardButtonX, hardButtonY, hardButtonX + hardButtonWidth, hardButtonY + hardButtonHeight);
        outtextxy(hardButtonX + 10, hardButtonY + 10, "HARD");
    }

    int roadY = 0;
    int roadOffset = 0;

    int playerCarX = windowWidth / 2;
    int playerCarY = windowHeight - 100;

    int opponentCarX = (windowWidth - roadWidth - 50) / 2 + 10 + rand() % (roadWidth - 50);
    int opponentCarY = 0;
    int opponentCarSpeed = rand() % 10 + 1;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    int score = 0;
    int loopDelay = 20;
    if (difficulty == 2) {
        loopDelay = 10;
    }
    else if (difficulty == 3) {
        loopDelay = 1;
    }

    while (1) {
        cleardevice(); 
       
        roadY += roadSpeed;
        if (roadY >= 60) {
            roadY -= 60;
            roadOffset++;
        }

        opponentCarY += opponentCarSpeed;
        if (opponentCarY > windowHeight) {
            opponentCarY = 0;
            opponentCarX = (windowWidth - roadWidth) / 2 + 10 + rand() % (roadWidth - 50);
            opponentCarSpeed = rand() % 10 + 1;

            score++;
        }

        if (playerCarX < (windowWidth - roadWidth) / 2 || playerCarX + 50 > (windowWidth + roadWidth) / 2 ||
            (playerCarY < opponentCarY + 80 && playerCarY + 80 > opponentCarY &&
            playerCarX < opponentCarX + 50 && playerCarX + 50 > opponentCarX)) {
            setcolor(WHITE);
            outtextxy(windowWidth / 2 - 50, windowHeight / 2, "GAME OVER");
            string scoreText = "Final Score: " + to_string(score);
            outtextxy(windowWidth / 2 - 85, windowHeight / 2 + 50, scoreText.c_str());
            swapbuffers();  
            break;
        }

        drawBackground(roadY);

        drawCar(playerCarX, playerCarY);
        drawCar(opponentCarX, opponentCarY);

        setcolor(WHITE);
        outtextxy(10, 10, ("SCORE: " + to_string(score)).c_str());

        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x = mousex();
            int y = mousey();

            if (x < playerCarX) {
                moveCarLeft(playerCarX);
            }
            else if (x > playerCarX + 50) {
                moveCarRight(playerCarX);
            }
        }

        delay(loopDelay);
        swapbuffers();  
    }

    getch();
    closegraph();
    return 0;
}