#include <iostream>
#include <Windows.h>
void gotoxy(int x, int y){
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
const int WIDTH = 15;
const int HEIGHT = 12;
const int MAX_LEN_SNAKE = (WIDTH - 3) * (HEIGHT - 2);

const int UP = 0;
const int DOWN = 1;
const int LEFT =  2;
const int RIGHT = 3;

int snake_dir = UP;

bool isRunning = true;

char map[] = 
"###############\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"###############\n";
//12 15
char snake = 'O';

int snake_x [MAX_LEN_SNAKE] = {0};
int snake_y [MAX_LEN_SNAKE] = {0};
int snake_len = 1;
int food_x = 1+(rand() % (WIDTH - 3));
int food_y = 1+(rand() % (HEIGHT - 2));
char food = '*';
int main(){
    snake_x[0] = WIDTH / 2;
    snake_y[0] = HEIGHT / 2;
    double time = clock();
    while (isRunning) {
        if (GetKeyState('A') & 0x8000)
            if(snake_dir != RIGHT){
            snake_dir = LEFT;
            }
        if (GetKeyState('D') & 0x8000)
            if(snake_dir != LEFT){
            snake_dir = RIGHT;
            }
        if (GetKeyState('W') & 0x8000)
            if(snake_dir != DOWN){
                snake_dir = UP;
            }
        if (GetKeyState('S') & 0x8000)
            if(snake_dir != UP){
            snake_dir = DOWN;
            }
        if ((clock() - time) / CLOCKS_PER_SEC >=0.3){
                time = clock();
                if (snake_x[0] == food_x && snake_y == food_y){
                    ++snake_len;
                    int food_x = 1+(rand() % (WIDTH - 3));
                    int food_y = 1+(rand() % (HEIGHT - 2));
            for (int i = snake_len -2; i >= 0; --i){
                snake_x[i+1] = snake_x [i];
                snake_y[i+1] = snake_y [i];} 
            if(snake_dir == UP)
                --snake_y[0];
            if(snake_dir == DOWN)
                ++snake_y[0];
            if(snake_dir == RIGHT)
                ++snake_x[0];
            if(snake_dir == LEFT)
                --snake_x[0];
            if (snake_x[0] == 0 || snake_y[0] = 0 || snake_x[0] == HEIGHT - 1)
                isRunning = false;
            for(int i = 1; i < snake_len; ++i){
                isRunning=false;
                i = snake_len;}

            gotoxy(int 0, int 0);
            std::cout<<"Length: " << snake_len<< std::endl;
            map[food_y * WIDTH + food_x] = food;
            for (int i = 0; i < snake_len; i++){
                map [snake_y[i] * WIDTH + snake_x[i]] = snake; }

            std::cout << map;
            for (int i = 0; i < snake_len; i++){
                map [snake_y[i] * WIDTH + snake_x[i]] = ' ';}

        }                                                       
    }
    gotoxy(1, HEIGHT / 2);
    std::cout << "Your score is: " << snake_len;   
    gotoxy(WIDTH, HEIGHT);  
}
