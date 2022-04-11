#include <iostream>
#include <vector>

void max_min_fairness(int available, std::vector<float> requests){

    std::vector<float> output(requests.size(), 0);
    float equal_contribution = available / requests.size();

    for (int i = 0; i < requests.size(); i++){

        if(requests[i] <= equal_contribution){
            output[i] = requests[i];
        }

        else{

            for (int j = 0; j < i; j++){
                available = available - output[j];
            }

            equal_contribution = available / i;

            for (int k = 0; k < i; k++){
                output[k+i] = equal_contribution;
            }

            break;

        }
    }

    for (float l: output){
        std::cout << l << std::endl;
    }
}

int main(){

    //set up values 
    int available = 16;
    std::vector<float> requests = {2, 4, 6, 7};

    std:cout << "we should have 2, 4, 5, 5" << std::endl;
    max_min_fairness(available, requests);
    std::cout << std::endl;

}