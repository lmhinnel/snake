#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <chrono>
#include <Windows.h>

using namespace std;
using namespace std::chrono;

int point = 0, socabe = 0, socalon = 0, countbf = 0;
int xsf, ysf, xbf, ybf;
char m4p[30][30];

struct Cat
{
    vector<pair<int, int>>pos;
    char inp = 'a';
    Cat()
    {
        for (int i = 0; i < 3; i++)
        {
            pos.push_back(make_pair(15, 15 + i));
            m4p[15][15 + i] = 'x';
        }
    }
};
//
//struct Objects {
//    pair<int, int> smallFish;
//    pair<int, int> bigFish;
//    int score = -10;
//
//    Objects() {
//        spawn(smallFish, 'f');
//    }
//
//    void spawn(pair<int, int>& p, char c) {
//        if (c == 'f') score += 10;
//        if (c == 'F') score += 40;
//        int x = rand() % 30, y = rand() % 30;;
//        while (1) {
//            if (m4p[x][y] == ' ') {
//                p = make_pair(x, y);
//                m4p[x][y] = c;
//                break;
//            }
//            x = rand() % 30;
//            y = rand() % 30;
//        }
//    }
//
//};
void spawnFish();
void drawMap();
void moveFunct(Cat& a, bool& endGame);

int main()
{
    bool endGame = 0;
    srand(time(NULL));
    Cat a;
    double startTime = GetTickCount();
    double currentTime;
    while (!endGame)
    {
        currentTime = GetTickCount();
        if (_kbhit())
        {
            a.inp = _getche();
        }

        spawnFish();
        if (currentTime - startTime >= 250.0f)
        {
            startTime = GetTickCount();
            moveFunct(a, endGame);
            drawMap();
        }
    }

    return 0;
}

void drawMap()
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            cout << "|" << m4p[i][j];

        }
        cout << "|" << endl;
    }
    cout << "______________________________" << endl;
    cout << point;
}

void moveFunct(Cat& a, bool& endGame)
{
    switch (a.inp)
    {
    case 'a':
        if (a.pos[0].second == 0)
        {
            endGame = true;
            break;
        }
        else
        {
            m4p[a.pos[0].first][a.pos[0].second - 1] = 'x';
            a.pos.insert(a.pos.begin(), make_pair(a.pos[0].first, a.pos[0].second - 1));
            if (a.pos[0].first == xsf && a.pos[0].second == ysf)
            {
                point += 10;
                countbf ++;
                socabe--;
                m4p[xsf][ysf] = 'x';
                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = 'x';

            }
            else
            {
                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = ' ';
                a.pos.pop_back();
            }
        }
        break;

    case 'd':
        if (a.pos[0].second == 29)
        {
            endGame = true;
            break;
        }
        else
        {
            m4p[a.pos[0].first][a.pos[0].second + 1] = 'x';
            a.pos.insert(a.pos.begin(), make_pair(a.pos[0].first, a.pos[0].second + 1));
            if (a.pos[0].first == xsf && a.pos[0].second == ysf)
            {
                socabe--;
                point += 10;
                countbf ++;
                m4p[xsf][ysf] = 'x';
                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = 'x';
            }
            else
            {
                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = ' ';
                a.pos.pop_back();
            }
//            if (a.pos[0].first == xbf && a.pos[0].second == ybf)
//            {
//                socalon--;
//                point += 50;
//                m4p[xbf][ybf] = ' ';
//            m4p[xbf + 1][ybf] = ' ';
//            m4p[xbf][ybf + 1] = ' ';
//            m4p[xbf + 1][ybf + 1] = ' ';
//                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = 'x';
//            }
//            else
//            {
//                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = ' ';
//                a.pos.pop_back();
//            }

        }
        break;

    case 's':
        if (a.pos[0].first == 29)
        {
            endGame = true;
            break;
        }
        else
        {
            m4p[a.pos[0].first + 1][a.pos[0].second] = 'x';
            a.pos.insert(a.pos.begin(), make_pair(a.pos[0].first + 1, a.pos[0].second));
            if (a.pos[0].first == xsf && a.pos[0].second == ysf)
            {
                socabe--;
                point += 10;
                countbf ++;
                m4p[xsf][ysf] = 'x';
                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = 'x';

            }
            else
            {
                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = ' ';

                a.pos.pop_back();
            }
        }
        break;

    case 'w':
        if (a.pos[0].first == 0)
        {
            endGame = true;
            break;
        }
        else
        {
            m4p[a.pos[0].first - 1][a.pos[0].second] = 'x';
            a.pos.insert(a.pos.begin(), make_pair(a.pos[0].first - 1, a.pos[0].second));
            if (a.pos[0].first == xsf && a.pos[0].second == ysf)
            {
                socabe--;
                point += 10;
                countbf ++;
                m4p[xsf][ysf] = 'x';
                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = 'x';
            }
            else
            {
                m4p[a.pos[a.pos.size() - 1].first][a.pos[a.pos.size() - 1].second] = ' ';
                a.pos.pop_back();
            }

        }
        break;
    }
}
void spawnFish ()
{

    if (socabe == 0)
    {
        while(1)
        {
            xsf = rand() % 30;
            ysf = rand() % 30;
            if (m4p[xsf][ysf] != 'x') break;
        }
        socabe++;
        m4p[xsf][ysf] = 'f';

    }
    if (countbf % 5 == 0 && socalon == 0 && point > 40)
    {
        while(1)
        {
            xbf = rand() % 30;
            ybf = rand() % 30;
            if (m4p[xbf][ybf] != 'x' && m4p[xbf + 1][ybf] != 'x' && m4p[xbf][ybf + 1] != 'x' && m4p[xbf + 1][ybf + 1] != 'x') break;
        }
        socalon++;
        {
            m4p[xbf][ybf] = 'F';
            m4p[xbf + 1][ybf] = 'F';
            m4p[xbf][ybf + 1] = 'F';
            m4p[xbf + 1][ybf + 1] = 'F';
        }
    }
}
