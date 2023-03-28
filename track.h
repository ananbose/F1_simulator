// Copyright 2023 Aaramse Project

#pragma once

#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>

#include "node.h"

using Timestamp = int;

struct TrackNode
{
    bool is_start;
    bool is_pit_entry;
    std::shared_ptr<Car> car;
};

struct CarStatus
{
    int grid_pos;
    int track_pos;  // Index of TrackNode
    bool in_pit;
    Timestamp pit_time_out; // Applicable when in_pit = true;

    CarStatus(int _grid_pos, int _track_pos)
        : grid_pos(_grid_pos), track_pos(_track_pos)
    {
    }

};

class Track
{
    public:
    Track(int km_distance, Timestamp pit_loss_time);

    void QueueToGrid(std::shared_ptr<Car> car);

    void Tick();

    private:
    Timestamp _current_time;
    Timestamp _pit_loss_time;
    std::vector<TrackNode> _track_nodes;

    std::queue<CarInPit> _pit_lane;

    std::unordered_map<std::shared_ptr<Car>, CarPosition> _grid_lookup;
};