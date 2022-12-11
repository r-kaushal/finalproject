#include "auto_v.h"



auto_v::auto_v() {
        this->numPassengers=0;
        this->safetyScore=0;
        this->avgAge=0;
}
auto_v::auto_v(int n, double s) {
    this->numPassengers = n;
    this->safetyScore = s;
}

void auto_v::setPassengers(int n) {
    this->numPassengers = n;
}
void auto_v::setAvgWeight(double x) {
    this->weight = x;
}
void auto_v::setEmergency(){
    this->emergencyObjective = true;
}
void auto_v::setScore(double s) {
    this->safetyScore = s;
}
void auto_v::setAge(double a) {
   this->avgAge = a;
}
void auto_v::setName(std::string s) {
   this->name = s;
}
int auto_v::getPassengers() {
    return this->numPassengers;
}
double auto_v::getScore() {
    return this->safetyScore;
}
double auto_v::getAvgWeight() {
    return this->weight;
}
std::string auto_v::getName() {
   return this->name;
}
double auto_v::getAge() {
    return this->avgAge;
}
void auto_v::printInfo() {
    std::cout << "passengers:" << this->getPassengers() << "safety score:" << this->getScore() << "\n";

}

void auto_v::braceForImpact(){
    cout << this->getName() << " is preparing for impact. Passengers have been alerted. ";
}


Json::Value auto_v::dump2JSON() {

    Json::Value result {};
    if(this->numPassengers!=0)
        result["Number of Passengers"] = this->numPassengers;
    if(this->safetyScore!=0.0)
        result["Safety Score"] = this->safetyScore;
    if(this->avgAge!=0.0)
        result["Average Age of Passengers"] = this->avgAge;
    if(this->name!="")
        result["Name"] = this->name;

        result["Emergency Objective"] = this->emergencyObjective;
        result["Weight"] = this->getAvgWeight();
    // Json::Value jv_result;
    // if(this->owner.name!=""){
    // jv_result = (this->owner).dump2JSON();
    // result["Owner"] = jv_result;
    // }
    
    // jv_result = (this->location).dump2JSON();
    // result["Location"] = jv_result;

    // std::cout << jv_result.toStyledString() << std::endl;

    return result;
}



void auto_v:: JSON2Object(Json::Value jsonVal){
    this->setPassengers((jsonVal["Number of Passengers"].asInt()));
    this->setScore((jsonVal["Safety Score"].asDouble()));
    this->setAge((jsonVal["Average Age of Passengers"].asDouble()));
    this->setName(jsonVal["Name"].asString());
    if(jsonVal["Emergency Objective"].asString()=="true"){
    this->setEmergency();

    this->setAvgWeight(jsonVal["Weight"].asDouble());
    }
  

}

string auto_v::chooseCrash(auto_v av1, auto_v av2)
{
    double score1 = 0.0;
    double score2 = 0.0;

    score1 += av1.getScore();
    score2 += av2.getScore();

    score1 += (av1.getPassengers() * 20);
    score2 += (av2.getPassengers() * 20);

    score1 += (10000.0/av1.getAvgWeight());
    score2 += (10000.0/av2.getAvgWeight());

    score1 += (100 - av1.getAge());
    score2 += (100 - av2.getAge());

    if(av1.emergencyObjective == true)
    score1+=100;

    if(av2.emergencyObjective == true)
    score2+=100;

    

    if (score1 < score2) {
        return av1.getName();
    }

    return av2.getName();
    
}

