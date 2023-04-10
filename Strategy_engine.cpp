#include "node.h"
#include "race_engine.h"
#include "tire.h"
#include <limits>
class F1_Strategist
{   
    list<Node> car_list; 
   public:
   F1_Strategist() {
        for(int i =1; i<=CARS;i++) {
            Node car;
            car.car_num=i;
            car.position = 0;
            car.delta_next =0;
            car.delta_prev =0;
            car.lap_num =0;
            car_list.push_back(car);
            
        }
    }
    void print_list() {
        for(auto car : car_list) {
            cout<<"position: "<<car.position<<" "<<"car number: "<<car.car_num<<endl;
        }
    }

   //get the car's position from race engine
    list<Node> get_attributes_from_track(RaceEngine re) {
        car_list = {re.GetGridOrder().begin(), re.GetGridOrder().end()};
        print_list();
        return car_list;
    }

    //k tires and n laps , here one stint = all laps driven without pitting
    float min_time_for_one_stint(Tire t, int n) {
        float tot_time =0;
        for (int j =0; j<n;j++) {          
            tot_time += pow(t.get_d(),j)*t.get_min_time();
        }
        //cout<<"total time after "<<n<<" laps is"<<tot_time<<" "<<t.TireToString()<<endl;
        return tot_time;
    }
 
    float choose_tire(int n) {
        vector<Tire> tires = {Tire(Soft), Tire(Medium), Tire(Hard)};
        float min_time = numeric_limits<float>::max();
        for(auto i:tires) {
            min_time = min(min_time, min_time_for_one_stint(i,n));
   
        }
        return min_time;
    }

    //Assuming there is only one car in the track
    float min_time_over_n_laps(int n) {
        float p = 30; // pit-stop time
        vector <float> dp;//best tire strategy for every lap
        dp.push_back(choose_tire(0));//best time on lap 0-> use soft-> 20
        
        for(int i=1;i<n;i++) {
            float min_dp = numeric_limits<float>::max();
            for(int j =0;j<i;j++) {
                cout<<"dp[j]"<<dp[j]<<endl;
                cout<<"choose_tire[i-j]"<<(choose_tire(i-j)+p)<<endl;
                cout<<"min dp"<<min_dp<<endl;
                min_dp = min(min_dp, dp[j]+choose_tire(i-j) + p);//choose a tire for jth lap and choose different tire for i-j laps                
            }
            cout<<"MIN DP for "<<i<<"th lap "<<min_dp<<" "<<endl;
            dp.push_back(min_dp);
        }
        return dp.back()-p;
    }

 

};
int main() {
    F1_Strategist strat;
    float min_race_time = strat.min_time_over_n_laps(LAPS);
    cout<<"Minimum race time for "<<LAPS<<" laps"<<min_race_time<<endl;
    return 0;
}