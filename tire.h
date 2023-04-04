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
    int min_time; //minimum time taken on fresh tires
    int d;//deg_factor
    public:
    Tire(Tire_type tin) {
        if (tin ==Soft) {
            t = Soft;
            min_time = 20;
            d = 1.5;
        }
        if (tin==Medium) {
            t= Medium;
            min_time = 30;
            d = 1.3;
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
};
