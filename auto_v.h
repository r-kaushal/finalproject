#ifndef AUTO_V_H
#define AUTO_V_H

#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>
class auto_v {
    private:
    protected:
    public:
        int numPassengers;
        double safetyScore;
        double avgAge;
        double weight;
        std::string name;        
      
        bool emergencyObjective = false;

        

        auto_v();
        auto_v(int, double);
        void setAvgWeight(double x);
        void setPassengers(int n);
        void setName(std::string s);
        void braceForImpact();
        void setScore(double s);
        void setEmergency();
        void setAge(double a);
        int getPassengers();
        double getAvgWeight();
        double getScore();
        std::string getName();
        double getAge();
        void printInfo();
        Json::Value dump2JSON();
        void JSON2Object(Json::Value); 
        string chooseCrash(auto_v av1, auto_v av2);

};
#endif