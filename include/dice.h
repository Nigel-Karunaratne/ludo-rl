#pragma once

#include <random>

class Dice
{
private:
    int face_number;
    std::random_device device;
    std::mt19937 generator;
    std::uniform_int_distribution<std::mt19937::result_type> distribution;
public:
    Dice();
    ~Dice();

    int RollDice();
    int GetCurrentFace() { return face_number; }
};

Dice::Dice() : device(), generator(device()), distribution(1,6)
{
}

Dice::~Dice()
{
}

inline int Dice::RollDice()
{
    face_number = distribution(generator);
}
