#include "train.h"
#include "railwayStation.h"

#include <vector>

using std::vector;

int main(){

    const int NUMB_TRAINS = 3;

    vector <Train> train(NUMB_TRAINS);

    for(int i = 0; i < train.size(); i++)
        train[i].start();

    return 0;
}