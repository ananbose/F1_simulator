#pragma once

// Tire with performance
enum Tire_type {
    Soft, 
    Medium, 
    Hard,
};

class Tire {
    static const int tire_count=3;
    enum Tire_type t;//type of tire
    float min_time; //minimum time taken on fresh tires
    float d;//deg_factor
    public:
    Tire(Tire_type tin) {
        if (tin ==Soft) {
            t = Soft;
            min_time = 20;
            d = 1.45;
        }
        if (tin==Medium) {
            t= Medium;
            min_time = 30;
            d = 1.32;
        }
        if (tin==Hard) {
            t = Hard;
            min_time = 40;
            d=1.1;
        }
    }
    //Getter functions
    int get_min_time() const {
        return min_time;
    }

    float get_d() const {
        return d;
    }

    string TireToString()
    {
        Tire_type type = t;
        switch (type)
        {
            case Soft:
                return "Soft";
            case Medium:
                return "Medium";
            case Hard:
                return "Hard";
            default:
                return "Unknown";
        }
    }

};
