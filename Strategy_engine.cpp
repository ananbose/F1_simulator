#include "node.h"
#include "race_engine.h"
class F1_Strategist
{   
    list<Node*> car_list; 
    /*vector<float> car_position(float v, float a, int t, int r)
    {

        float theta = (v * t + (0.5) * a * (t ^ 2)) / r;
        float x = r * cos(theta);
        float y = r * sin(theta);
        position.push_back(x);
        position.push_back(y);
        return position;
    }
    */
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
    //make a decision to pit or not for the selected car
    bool pit_stop_decision(Node * car) {
       //lets say i was the only car on the track
        
    }
};