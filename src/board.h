#pragma once

#include <map>
#include <vector>

#include "playercolors.h"

#include <iostream>

enum BoardSpaceType
{
    SPACE_NORMAL,
    SPACE_START,
    SPACE_STAGE_ENTRANCE,
    SPACE_STAGE, //the goal
    SPACE_HOME,
    SPACE_NULL = -1
};

class BoardSpace
{
    friend class Board; //outside of the grid creating spaces, these spaces are immutable
private:
    int xPos;
    int yPos;
    BoardSpaceType type;
    PlayerColors color;
public:
    BoardSpace() {};
    BoardSpace(int xPos, int yPos) : xPos(xPos), yPos(yPos), type(BoardSpaceType::SPACE_NORMAL), color(PlayerColors::PLAYER_NONE) {};
    BoardSpace(int xPos, int yPos, BoardSpaceType type, PlayerColors color) : xPos(xPos), yPos(yPos), type(type), color(color) {};

    inline const BoardSpaceType& GetBoardSpaceType() { return type; };
    inline const PlayerColors& GetColor() { return color; };
    inline const int& GetXPos() { return xPos; }
    inline const int& GetYPos() { return yPos; }
};

class Board
{
private:
    const int mainXPos[40] = {4,4,4,4,4,3,2,1,0,0,0,1,2,3,4,4,4,4,4,5,6,6,6,6,6,7,8,9,10,10,10,9,8,7,6,6,6,6,6,5};
    const int mainYPos[40] = {10,9,8,7,6,6,6,6,6,5,4,4,4,4,4,3,2,1,0,0,0,1,2,3,4,4,4,4,4,5,6,6,6,6,6,7,8,9,10,10};

    //moving forward --> increasing the index this piece is in regarding this vector.
    std::vector<BoardSpace> boardSpaces;

    std::vector<BoardSpace> blueHomeSpaces;
    std::vector<BoardSpace> redHomeSpaces;
    std::vector<BoardSpace> greenHomeSpaces;
    std::vector<BoardSpace> yellowHomeSpaces;

    std::vector<int> bluePieces;
    std::vector<int> redPieces;
    std::vector<int> greenPieces;
    std::vector<int> yellowPieces;
public:
    Board();
    ~Board();

    bool IsSpaceThroughGoalValid(int currentPosition, int numberOfSpaces, PlayerColors color);
    bool IsSpaceThroughGoalValid(int currentPosition, PlayerColors color);
    BoardSpace GetSpaceThroughGoal(int currentPosition, int numberOfSpaces, PlayerColors color);
};

Board::Board()
{
    boardSpaces.reserve(40);
    for (int i = 0; i < 40; i++)
    {
        // if i = 0, 10, 20, 30 space is a start
        // if i = 9, 19, 29, 39 space is a stage start
        BoardSpace space;
        if (i % 10 == 0)
        {
            // START SPACE
            space = BoardSpace(mainXPos[i], mainYPos[i], BoardSpaceType::SPACE_START, (PlayerColors)(i/10));
        }
        else if ((i + 1) % 10 == 0)
        {
            // STAGE ENTRANCE SPACE
            space = BoardSpace(mainXPos[i], mainYPos[i], BoardSpaceType::SPACE_STAGE_ENTRANCE,
            (PlayerColors)(i == 39 ? 0 : i+1/10));
        }
        else
        {
            // NORMAL SPACE
            space = BoardSpace(mainXPos[i], mainYPos[i]);
        }
        boardSpaces.emplace_back(space);
    }

    //Set up home spaces
    blueHomeSpaces = {
        BoardSpace(1,8,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_BLUE),
        BoardSpace(2,8,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_BLUE),
        BoardSpace(1,9,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_BLUE),
        BoardSpace(2,9,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_BLUE)
    };
    redHomeSpaces = {
        BoardSpace(1,1,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_RED),
        BoardSpace(2,1,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_RED),
        BoardSpace(1,2,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_RED),
        BoardSpace(2,2,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_RED)
    };
    greenHomeSpaces = {
        BoardSpace(8,1,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_GREEN),
        BoardSpace(9,1,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_GREEN),
        BoardSpace(8,2,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_GREEN),
        BoardSpace(9,2,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_GREEN)
    };
    yellowHomeSpaces = {
        BoardSpace(8,8,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_YELLOW),
        BoardSpace(9,8,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_YELLOW),
        BoardSpace(8,9,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_YELLOW),
        BoardSpace(9,9,BoardSpaceType::SPACE_HOME,PlayerColors::PLAYER_YELLOW)
    };
}

Board::~Board()
{
}

inline bool Board::IsSpaceThroughGoalValid(int currentPosition, int numberOfSpaces, PlayerColors color)
{
    int offset = 0;
    switch (color)
    {
    case PlayerColors::PLAYER_BLUE:
        offset = 0;
        break;
    case PlayerColors::PLAYER_RED:
        offset = 10;
        break;
    case PlayerColors::PLAYER_GREEN:
        offset = 20;
        break;
    case PlayerColors::PLAYER_YELLOW:
        offset = 30;
        break;
    case PlayerColors::PLAYER_NONE:
        std::cerr << "ERROR in Board::IsSpaceThroughGoalValid, received PlayerColors::PLAYER_NONE" << std::endl;
        break;
    }
    
    //if true, we need to check for being in the goal
    if (currentPosition + numberOfSpaces - offset > 39)
    {
        int posInGoal = 39 - (currentPosition + numberOfSpaces - offset);
        return posInGoal < 4; //REVIEW - bounds are correct?
    }
    else
        return true; //TODO - what if the space below this is occupied? by your piece? by another?
}

inline bool Board::IsSpaceThroughGoalValid(int currentPosition, PlayerColors color)
{
    return IsSpaceThroughGoalValid(currentPosition,0,color);
}

BoardSpace Board::GetSpaceThroughGoal(int currentPosition, int numberOfSpaces, PlayerColors color)
{
    switch (color)
    {
    case PlayerColors::PLAYER_BLUE:
    {
        // currpos+numofspaces > 39, we go into goal. Else, look along the path
        if(currentPosition + numberOfSpaces > 39)
        {
            int posInGoal = 39 - (currentPosition + numberOfSpaces);
            if (posInGoal > 3)
                return BoardSpace(-1,-1,BoardSpaceType::SPACE_NULL,PlayerColors::PLAYER_NONE); //TODO - split into 2 functions, one for isValid and one for GetSpace?
            else
                return blueHomeSpaces[posInGoal];
        }
        else
            return boardSpaces[currentPosition + numberOfSpaces];
    }

    case PlayerColors::PLAYER_RED:
    {
        // (currpos-10)+numofspaces > 39
        if((currentPosition-10) + numberOfSpaces > 39)
        {
            int posInGoal = 39 - (currentPosition + numberOfSpaces-10);
            if (posInGoal > 3)
                return BoardSpace(-1,-1,BoardSpaceType::SPACE_NULL,PlayerColors::PLAYER_NONE); //TODO - split into 2 functions, one for isValid and one for GetSpace?
            else
                return blueHomeSpaces[posInGoal];
        }
        else
            return boardSpaces[(currentPosition + numberOfSpaces) % 40];
    }
    case PlayerColors::PLAYER_GREEN:
    {
        // (currpos-20)+numofspaces > 39
        if((currentPosition-20) + numberOfSpaces > 39)
        {
            int posInGoal = 39 - (currentPosition + numberOfSpaces-20);
            if (posInGoal > 3)
                return BoardSpace(-1,-1,BoardSpaceType::SPACE_NULL,PlayerColors::PLAYER_NONE); //TODO - split into 2 functions, one for isValid and one for GetSpace?
            else
                return blueHomeSpaces[posInGoal];
        }
        else
            return boardSpaces[(currentPosition + numberOfSpaces) % 40];
    }
    case PlayerColors::PLAYER_YELLOW:
    {
        // (currpos-30)+numofspaces > 39
        if((currentPosition-30) + numberOfSpaces > 39)
        {
            int posInGoal = 39 - (currentPosition + numberOfSpaces-30);
            if (posInGoal > 3)
                return BoardSpace(-1,-1,BoardSpaceType::SPACE_NULL,PlayerColors::PLAYER_NONE); //TODO - split into 2 functions, one for isValid and one for GetSpace?
            else
                return blueHomeSpaces[posInGoal];
        }
        else
            return boardSpaces[(currentPosition + numberOfSpaces) % 40];
    }
    
    default:
        std::cerr << "cannot get position information of a null color player" << std::endl;
        break;
    }
    return BoardSpace(-1,-1,BoardSpaceType::SPACE_NULL,PlayerColors::PLAYER_NONE);
}

/*



find all valid moves, given a dice roll D

home --> none!
normal, start --> board.GetSpace(D).isoccupied OR board.GetSpaceThroughGoal(D,color).isoccupied
goalentrance, goal --> board.GetSpaceThroughGoal(D,color)


TO Move a piece a certain amount:
    get ALL BoardSpaces that the piece would move on, store in stack/queue
    while stack/queue != empty, pop a piece and update move to that code
    once stack/queue is empty, move state is over.

*/
