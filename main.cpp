#include "node.h"

class F1_Simulator
{   Node *head;// init to nullptr
    vector <Node*> car_list; 
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
    //first calculate distance traveled based on velocity
    int car_distance(float v) {
        
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
    // Create the initial list of cars and give them positions at the start grid, strore in a vector
    void create_initial_list(){
        for(int i =0; i<CARS;i++) {
            Node * car = new Node;
            car->car_num=i;
            car->position = 0;
            car_list.push_back(car);
        }
    }
    void print_list() {
        for(const auto &car : car_list) {
            cout<<car->car_num<<" "<<car->position<<endl;
        }
    }
    //Calculate position along the straight line, imagining distance to be infinite
    
    
    bool compare_by_position(const Node &a , const Node &b) {
        return a.position< b.position;
    }
    
    // Sort the list of nodes based on position
    void sort_based_on_position() {
        for(int i =0; i<CARS; i++) {
            car_list[i]->position = calculate_position(car_list[i]);
        }
        sort(car_list.begin(), car_list.end(), compare_by_position);
        print_list();


    }
};