#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "ZombieGraph.h"

using namespace std;

int main(int argc, char* argv[]){
    ZombieGraph maps;
    fstream Citymap = argv[1];
    int z = 0;
    string data;
    vector<string> cities;
    if(Citymap.good()){
        while(getline(Citymap, data)){
            if(z==0){
                int x = 0;
                string minidata;
                while(getline(data, minidata, ',')){
                    if(x != 0){
                        maps.addVertex(minidata);
                        cities.push_back(minidata);
                    }
                    x++;
                }
            z++;
            }
            else{
                int y = 0;
                string minidata2;
                int currentWeight;
                string currentCity;
                int i = 0;
                while(getline(data, minidata2, ',')){
                    if(y = 0){
                        currentCity = minidata2;
                    }
                    y++;
                    else{
                        int miniweight = atoi(minidata2.c_str()));
                        maps.addEdge(currentCity, cities[i], miniweight);
                        i++;
                    }
                }
            }
        }
    }
    Citymap.close();

    maps.printCities();

    return 0;
}
