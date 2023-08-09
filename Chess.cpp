#include <iostream>

using namespace std;

struct Piece
{
    int x;
    int y;
    bool Alive;

    Piece()
    {
        Alive = false;
    }
    virtual string Draw()
    {
        return " ";
    }
    virtual bool Move(int Cx, int Cy)
    {
        return false;
    }

    friend void Update();
};

struct Rook : public Piece
{
    Rook()
    {
        Alive = true;
    }
    string Draw()
    {
        return "|";
    }
    bool Move(int Cx, int Cy)
    {
        return false;
    }
};

struct Knight : public Piece
{

public:

    Knight()
    {
        Alive = true;
    }
    string Draw()
    {
        return "?";
    }
    bool Move(int Cx, int Cy)
    {
        return false;
    }
};

struct Bishop : public Piece
{

public:

    Bishop()
    {
        Alive = true;
    }
    string Draw()
    {
        return "i";
    }
    bool Move(int Cx, int Cy)
    {
        return false;
    }
};

struct King : public Piece
{

public:

    King()
    {
        Alive = true;
    }
    string Draw()
    {
        return "+";
    }
    bool Move(int Cx, int Cy)
    {
        return false;
    }
};

struct Queen : public Piece
{

public:

    Queen()
    {
        Alive = true;
    }
    string Draw()
    {
        return "*";
    }
    bool Move(int Cx, int Cy)
    {
        return false;
    }
};

struct Pawn : public Piece
{

public:

    Pawn()
    {
        Alive = true;
    }
    string Draw()
    {
        return "P";
    }
    bool Move(int Cx, int Cy)
    {
        return false;
    }
};

int main()
{

}