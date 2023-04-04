#include "node.h"
#include "race_engine.h"
#include "tire.h"
#include <limits>
class F1_Strategist
{   
    list<Node*> car_list; 
   F1_Strategist() {
        for(int i =0; i<CARS;i++) {
            Node * car = new Node;
            car->car_num=i;
            car->position = 0;
            car->delta_next =0;
            car->delta_prev =0;
            car->lap_num =0;
            car_list.push_back(car);
            
        }
   }
    Car_sensor* thread_read_file(int thread_id, string file_name)
    {
        // open the file to read it
        cout<<" Reading file with sensor inputs from my F1 car" <<endl;
        string line, value;
        float var1 , var2 , var3, var4;
        ifstream inputFile(file_name);
        Car_sensor *car_sensor;       
        while (getline(inputFile, line)) {
            cout <<line<<endl;
            stringstream ss(line);
            var1 = stod(value);
            getline(ss, value, ',');
            var2 = stod(value);
            getline(ss, value, ',');
            var3 = stod(value);
            getline(ss, value, ',');
            var4 = stod(value);
            car_sensor = new Car_sensor(var1, var2, var3, var4);
        }
        inputFile.close();
        return car_sensor;
    }
    void print_list() {
        for(const auto &car : car_list) {
            cout<<car->car_num<<" "<<car->position<<endl;
        }
    }
   //get the car's position from race engine
    list<Node*> get_attributes_from_track(RaceEngine re) {
        car_list = {re.GetGridOrder().begin(), re.GetGridOrder().end()};
        print_list();
        return car_list;
    }

    //k tires and nth stint
    float min_time_for_n_stints(Tire t, int n){
        int tot_time =0;
        for (int j =0; j<n;j++) {
            tot_time += pow(t.get_d(),j)*t.get_min_time();
        }
        return tot_time;
    }
    float choose_tire(int n) {
        vector<Tire> tires = {Tire(Soft), Tire(Medium), Tire(Hard)};
        float min_time = numeric_limits<float>::max();
        for(auto i:tires) {
            min_time = min(min_time, min_time_for_n_stints(i,n));
        }
        return min_time;
    }
    //Assuming there is only one car in the track
    float min_time_over_n_laps(Node * car, int n) {
        int p = 30; // pit-stop time
        vector <float> dp;//best tire strategy for every lap
        dp.push_back(0);//dp[0] = 0
        for(int i=1;i<n;i++) {
            float min_dp = numeric_limits<float>::max();
            for (int j=0;j<i;j++) {
                min_dp = min(min_dp, dp[j]+ choose_tire(i-j) + p);
            }
            dp.push_back(min_dp);
        }
        return dp.back()-p;
    }
};