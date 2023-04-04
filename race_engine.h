// Copyright 2023 Aaramse Project

#pragma once

#include <list>

#include "node.h"

class RaceEngine
{
    public:
    std::list<Node> GetGridOrder() const;
    void tick() const;
};