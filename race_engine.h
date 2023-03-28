// Copyright 2023 Aaramse Project

#pragma once

#include <list>

#include "node.h"

using Timestamp = int;

class RaceEngine
{
    public:
    RaceEngine();
    std::list<Node> GetGridOrder() const;
    void tick() const;

    private:
    Timestamp current_time;

    std::vector<std::shared_ptr<Entry>> entry_list;
};