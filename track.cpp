// Copyright 2023 Aaramse Project

#include "track.h"

#include <algorithm>
#include <unordered_set>

constexpr auto kNodesPerKm = 1000;
constexpr int kDefaultPitLength = 0.5 * kNodesPerKm; // 500m
constexpr auto kDefaultSpeedMetersPerSec = 72;
 
Track::Track(int km_distance, Timestamp pit_loss_time)
    : _current_time(0), _pit_loss_time(pit_loss_time)
{
    _num_track_nodes = km_distance * kNodesPerKm;
    _pit_start_idx = _num_track_nodes - kDefaultPitLength;
}

void Track::QueueToGrid(std::shared_ptr<Car> car)
{
    // Starting grid begins at the final node before the finish line, with the
    // car starting P1. The car starting P1 should be queued first.
    auto grid_pos = _grid.size();
    _track_pos_lookup.insert(car, CarStatus(_num_track_nodes - grid_pos - 1, 0));
    _grid.push_back(car);
}

void Track::Tick()
{
    std::unordered_map<TrackPos, std::shared_ptr<Car>> queued_moves;
    std::unordered_set<TrackPos> reserved;

    struct
    {
        bool operator()(std::shared_ptr<Car> a, std::shared_ptr<Car> b)
        {
            return _track_pos_lookup.at(a).grid_pos < _track_pos_lookup.at(b).grid_pos;
        } sortByGridOrder;
    }

    std::sort(_grid.begin(), _grid.end(), sortByGridOrder);

    for (auto car: _grid)
    {
        auto current_status = _track_pos_lookup.at(car);
        auto next_pos_unmodified = current_status.track_pos + car->velocity;
        
        auto next_track_pos = next_pos_unmodified % _num_track_nodes;
        while (reserved.contains(next_track_pos)) {
            next_track_pos--;
            if (next_track_pos < 0) {
                next_track_pos = _num_track_nodes - 1;
            }
        }
        // Advance to next lap if we've rolled over track positions.
        auto next_lap_num = (next_track_pos > current_status.track_pos) ? current_status.lap_num : current_status.lap_num + 1;
        auto new_status = CarStatus(current_status.grid_pos, next_track_pos, next_lap_num);
    }

    struct
    {
        bool operator()(std::shared_ptr<Car> a, std::shared_ptr<Car> b)
        {
            return _track_pos_lookup.at(a).lap_num > _track_pos_lookup.at(b).lap_num ||
            _track_pos_lookup.at(a).track_pos > _track_pos_lookup.at(b).track_pos;
        } sortByNewGridOrder;
    }

    _current_time++;
}