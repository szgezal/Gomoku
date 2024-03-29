#include "tile.hpp"
using namespace genv;

Tile::Tile(Gamemaster* _parent, int _x, int _y, int _size_x, int _size_y, std::string _state, int _i, int _j):
           Widget(     _parent,     _x,     _y,     _size_x,     _size_y),      state(_state)
{
    std::vector<int> v;
    v.push_back(_i);
    v.push_back(_j);
    index = v;
}

void Tile::draw() {
    if (state == "") {
        gout << color(0, 0, 0) << move_to(x, y) << box(size_x, size_y);
        gout << color(255, 255, 255) << move_to(x + 1, y + 1) << box(size_x - 2, size_y - 2);
    } else if (state == "x") {
        gout << color(0, 0, 0) << move_to(x, y) << box(size_x, size_y);
        gout << color(255, 255, 255) << move_to(x + 1, y + 1) << box(size_x - 2, size_y - 2);
        gout << color(255, 0, 0) << move_to(x + 2, y + 2) << line_to(x + size_x - 3, y + size_y - 3)
                                 << move_to(x + size_x - 2, y + 2) << line_to(x + 2, y + size_y - 3);
        gout << color(255, 0, 0) << move_to(x + 2, y + 3) << line_to(x + size_x - 4, y + size_y - 3)
                                 << move_to(x + size_x - 3, y + 2) << line_to(x + 2, y + size_y - 4);
        gout << color(255, 0, 0) << move_to(x + 3, y + 2) << line_to(x + size_x - 4, y + size_y - 3)
                                 << move_to(x + size_x - 2, y + 3) << line_to(x + 3, y + size_y - 3);
    } else if (state == "o") {
        gout << color(0, 0, 0) << move_to(x, y) << box(size_x, size_y);
        gout << color(255, 255, 255) << move_to(x + 1, y + 1) << box(size_x - 2, size_y - 2);
        for (int i = -size_y/2; i < size_y/2; i++)
            for (int j = -size_x/2; j < size_x/2; j++)
                if (i*i + j*j <= (size_x/2 - 1)*(size_x/2 - 1))
                    gout << color(0, 0, 255) << move_to(x + j + size_x/2, y + i + size_y/2) << dot;
        for (int i = -size_y/2; i < size_y/2; i++)
            for (int j = -size_x/2; j < size_x/2; j++)
                if (i*i + j*j <= (size_x/2 - 5)*(size_x/2 - 5))
                    gout << color(255, 255, 255) << move_to(x + j + size_x/2, y + i + size_y/2) << dot;

    }
}

void Tile::handle(genv::event, Widget *) {}

void Tile::onClick(std::string player) {
    if (state == "" && player == "x")
        state = "x";
    else if (state == "" && player == "o")
        state = "o";
}

std::string Tile::getState() {
    return state;
}

void Tile::setState(std::string s) {
    state = s;
}

std::vector<int> Tile::getCenterKoord() {
    std::vector<int> v;
    v.push_back(x + size_x/2);
    v.push_back(y + size_y/2);
    return v;
}

std::vector<int> Tile::getIndex() {
    return index;
}
