#include <iostream>

using namespace std;

struct Piece
{
    int x;
    int y;
    bool Alive;
    int ID;

    Piece()
    {
        Alive = false;
        ID = 0;
    }
    virtual string Draw()
    {
        return " ";
    }
    virtual bool Move(int Cx, int Cy)
    {
        return false;
    }
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

class Chess
{
    private:
        Rook *rooks;
        Knight* knights;
        Bishop* bishops;
        Queen* queen;
        King* king;
        Pawn* pawns;
        Piece*** board;

    public:
        Chess()
        {
            // Initializing the Board:
            board = new Piece **[8];
            for (int i = 0; i < 8; i++)
            {
                board[i] = new Piece *[8];
                for (int j = 0; j < 8; j++)
                {
                    board[i][j] = new Piece;
                }
            }

            // Initializing Pieces:
            rooks = new Rook[4];
            knights = new Knight[4];
            bishops = new Bishop[4];
            queen = new Queen[2];
            king = new King[2];
            pawns = new Pawn[16];

            // Assigning Player Identity to the Pieces:

            // Player 1:
            rooks[0].ID = 1;
            knights[0].ID = 1;
            bishops[0].ID = 1;
            queen[0].ID = 1;
            king[0].ID = 1;
            bishops[1].ID = 1;
            knights[1].ID = 1;
            rooks[1].ID = 1;

            pawns[0].ID = 1;
            pawns[1].ID = 1;
            pawns[2].ID = 1;
            pawns[3].ID = 1;
            pawns[4].ID = 1;
            pawns[5].ID = 1;
            pawns[6].ID = 1;
            pawns[7].ID = 1;

            // Player 2:
            rooks[2].ID = 2;
            knights[2].ID = 2;
            bishops[2].ID = 2;
            queen[1].ID = 2;
            king[1].ID = 2;
            bishops[3].ID = 2;
            knights[3].ID = 2;
            rooks[3].ID = 2;

            pawns[8].ID = 2;
            pawns[9].ID = 2;
            pawns[10].ID = 2;
            pawns[11].ID = 2;
            pawns[12].ID = 2;
            pawns[13].ID = 2;
            pawns[14].ID = 2;
            pawns[15].ID = 2;

            // Starting Positions of Pieces:
            board[0][0] = rooks + 0;
            board[0][1] = knights + 0;
            board[0][2] = bishops + 0;
            board[0][3] = queen + 0;
            board[0][4] = king + 0;
            board[0][5] = bishops + 1;
            board[0][6] = knights + 1;
            board[0][7] = rooks + 1;

            board[1][0] = pawns + 0;
            board[1][1] = pawns + 1;
            board[1][2] = pawns + 2;
            board[1][3] = pawns + 3;
            board[1][4] = pawns + 4;
            board[1][5] = pawns + 5;
            board[1][6] = pawns + 6;
            board[1][7] = pawns + 7;

            board[6][0] = pawns + 8;
            board[6][1] = pawns + 9;
            board[6][2] = pawns + 10;
            board[6][3] = pawns + 11;
            board[6][4] = pawns + 12;
            board[6][5] = pawns + 13;
            board[6][6] = pawns + 14;
            board[6][7] = pawns + 15;

            board[7][0] = rooks + 2;
            board[7][1] = knights + 2;
            board[7][2] = bishops + 2;
            board[7][3] = queen + 1;
            board[7][4] = king + 1;
            board[7][5] = bishops + 3;
            board[7][6] = knights + 3;
            board[7][7] = rooks + 3;
        }
        void DrawBoard()
        {
            cout
                << "-----1---------2---------3---------4---------5---------6---------7---------8-----\n"
                << "|#########|         |#########|         |#########|         |#########|         |\n"
                << "1    " << board[0][0]->Draw() << "    |" << "    " << board[0][1]->Draw() << "    |" << "    " << board[0][2]->Draw() << "    |" << "    " << board[0][3]->Draw() << "    |" << "    " << board[0][4]->Draw() << "    |" << "    " << board[0][5]->Draw() << "    |" << "    " << board[0][6]->Draw() << "    |" << "    " << board[0][7]->Draw() << "    |\n"
                << "|#########|         |#########|         |#########|         |#########|         |\n"
                << "---------------------------------------------------------------------------------\n"
                << "|         |#########|         |#########|         |#########|         |#########|\n"
                << "2    " << board[1][0]->Draw() << "    |" << "    " << board[1][1]->Draw() << "    |" << "    " << board[1][2]->Draw() << "    |" << "    " << board[1][3]->Draw() << "    |" << "    " << board[1][4]->Draw() << "    |" << "    " << board[1][5]->Draw() << "    |" << "    " << board[1][6]->Draw() << "    |" << "    " << board[1][7]->Draw() << "    |\n"
                << "|         |#########|         |#########|         |#########|         |#########|\n"
                << "---------------------------------------------------------------------------------\n"
                << "|#########|         |#########|         |#########|         |#########|         |\n"
                << "3    " << board[2][0]->Draw() << "    |" << "    " << board[2][1]->Draw() << "    |" << "    " << board[2][2]->Draw() << "    |" << "    " << board[2][3]->Draw() << "    |" << "    " << board[2][4]->Draw() << "    |" << "    " << board[2][5]->Draw() << "    |" << "    " << board[2][6]->Draw() << "    |" << "    " << board[2][7]->Draw() << "    |\n"
                << "|#########|         |#########|         |#########|         |#########|         |\n"
                << "---------------------------------------------------------------------------------\n"
                << "|         |#########|         |#########|         |#########|         |#########|\n"
                << "4    " << board[3][0]->Draw() << "    |" << "    " << board[3][1]->Draw() << "    |" << "    " << board[3][2]->Draw() << "    |" << "    " << board[3][3]->Draw() << "    |" << "    " << board[3][4]->Draw() << "    |" << "    " << board[3][5]->Draw() << "    |" << "    " << board[3][6]->Draw() << "    |" << "    " << board[3][7]->Draw() << "    |\n"
                << "|         |#########|         |#########|         |#########|         |#########|\n"
                << "---------------------------------------------------------------------------------\n"
                << "|#########|         |#########|         |#########|         |#########|         |\n"
                << "5    " << board[4][0]->Draw() << "    |" << "    " << board[4][1]->Draw() << "    |" << "    " << board[4][2]->Draw() << "    |" << "    " << board[4][3]->Draw() << "    |" << "    " << board[4][4]->Draw() << "    |" << "    " << board[4][5]->Draw() << "    |" << "    " << board[4][6]->Draw() << "    |" << "    " << board[4][7]->Draw() << "    |\n"
                << "|#########|         |#########|         |#########|         |#########|         |\n"
                << "---------------------------------------------------------------------------------\n"
                << "|         |#########|         |#########|         |#########|         |#########|\n"
                << "6    " << board[5][0]->Draw() << "    |" << "    " << board[5][1]->Draw() << "    |" << "    " << board[5][2]->Draw() << "    |" << "    " << board[5][3]->Draw() << "    |" << "    " << board[5][4]->Draw() << "    |" << "    " << board[5][5]->Draw() << "    |" << "    " << board[5][6]->Draw() << "    |" << "    " << board[5][7]->Draw() << "    |\n"
                << "|         |#########|         |#########|         |#########|         |#########|\n"
                << "---------------------------------------------------------------------------------\n"
                << "|#########|         |#########|         |#########|         |#########|         |\n"
                << "7    " << board[6][0]->Draw() << "    |" << "    " << board[6][1]->Draw() << "    |" << "    " << board[6][2]->Draw() << "    |" << "    " << board[6][3]->Draw() << "    |" << "    " << board[6][4]->Draw() << "    |" << "    " << board[6][5]->Draw() << "    |" << "    " << board[6][6]->Draw() << "    |" << "    " << board[6][7]->Draw() << "    |\n"
                << "|#########|         |#########|         |#########|         |#########|         |\n"
                << "---------------------------------------------------------------------------------\n"
                << "|         |#########|         |#########|         |#########|         |#########|\n"
                << "8    " << board[7][0]->Draw() << "    |" << "    " << board[7][1]->Draw() << "    |" << "    " << board[7][2]->Draw() << "    |" << "    " << board[7][3]->Draw() << "    |" << "    " << board[7][4]->Draw() << "    |" << "    " << board[7][5]->Draw() << "    |" << "    " << board[7][6]->Draw() << "    |" << "    " << board[7][7]->Draw() << "    |\n"
                << "|         |#########|         |#########|         |#########|         |#########|\n"
                << "---------------------------------------------------------------------------------\n";
        }
};

int main()
{
    Chess chess;
    chess.DrawBoard();
    system("PAUSE");
}