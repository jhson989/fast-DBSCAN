#include "fastDBSCAN.hpp"


void DBSCAN_sequential(double* data, int* data_label, size_t num_data, double eps, double min_samples) {
    
    std::vector<int> neighbor(num_data);

    int label = 1;
    for (size_t idx=0; idx<num_data; idx++) {
        
        if (data_label[idx] == UNCHECKED) {
            
            std::queue<int> group;
            group.push(idx);
            data_label[idx] = CHECKING;
            size_t num = 0;

            while (group.size() != 0) {
                int now = group.front();
                group.pop();

                for (size_t target=0; target<num_data; target++) {
                    if (data_label[target]==UNCHECKED) {
                        if (check_length(data[2*now+1], data[2*now], data[2*target+1], data[2*target], eps)) {
                            group.push(target);
                            data_label[target] = CHECKING;
                            neighbor[num]=target;
                            num++;
                        }
                    }
                }
            }
            
            
            if (num>=min_samples){
                for (size_t i=0; i<num; i++)
                    data_label[neighbor[i]] = label;
                data_label[idx] = label;
                label++;
            } else {
                for (size_t i=0; i<num; i++)
                    data_label[neighbor[i]] = NOT_INCLUDED;
                data_label[idx] = NOT_INCLUDED;
            }
        }
    }
}