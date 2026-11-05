#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int length_Square = 10;
const int graphSpace = length_Square * 4;
char graph[graphSpace][graphSpace];

int origin_x = graphSpace / 2;
int origin_y = graphSpace / 2;

void clear_graph() {
    for (int i = 0; i < graphSpace; i++)
        for (int j = 0; j < graphSpace; j++)
            graph[i][j] = ' ';
}

void draw_pixel(int x, int y) {
    int gx = origin_x + x;
    int gy = origin_y - y; // invertir eje Y

    if (gx >= 0 && gx < graphSpace && gy >= 0 && gy < graphSpace)
        graph[gy][gx] = '#';
}

void create_image() {
    for (int i = 0; i < graphSpace; i++) {
        for (int j = 0; j < graphSpace; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}

void rotation_2d(int& x, int& y, float theta) {
    float rad = theta * M_PI / 180.0;
    int new_x = round(x * cos(rad) - y * sin(rad));
    int new_y = round(x * sin(rad) + y * cos(rad));
    x = new_x;
    y = new_y;
}

int main() {
    int square[4][2] = {
        {-length_Square, -length_Square},
        { length_Square, -length_Square},
        { length_Square,  length_Square},
        {-length_Square,  length_Square}
    };

    for (int theta = 0; theta <= 360; theta += 15) {
        clear_graph();

        for (int i = 0; i < 4; i++) {
            int x = square[i][0];
            int y = square[i][1];
            rotation_2d(x, y, theta);
            draw_pixel(x, y);
        }

        create_image();
        cout << "\n\n";
    }

    return 0;
}
