/* 
   5. The Bank of Heather has performed a study showing that ATM customers won’t
   wait more than one minute in line. Using the simulation from Listing 12.10, find a
   value for number of customers per hour that leads to an average wait time of one
   minute. (Use at least a 100-hour trial period.)
*/

/* NOTE: I have no idea if this works the way the question intended. This program was supposed
   to be the direct answer to the question given, but maybe this is a bit (a lot) over-engineered.
   A maybe accurate extension is already given as the last result in the client1.cpp file */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "atm.hpp"

int main() {
    using ATM::readValue;
    std::srand(std::time(0));
    unsigned max_q_len, sim_hours, customer_patience;
    readValue("Enter max queue length: ", max_q_len);
    readValue("Enter simulation hours: ", sim_hours);
    readValue("Enter max customer wait time: ", customer_patience);

    ATM::Queue line(max_q_len);
    unsigned totalMins = ATM::MIN_PER_HR * sim_hours;

    ATM::Customer newCustomer;
    unsigned served = 0, current_wait_time = 0, running_wait_time = 0;
    for (int time = 0; time < totalMins; time++) {
        // Accept customer if the running customer waiting time is
        // less equal to customer_patience (in mins) (here in question = 1), i.e,
        // customer returns if cumulative customer waiting time is > 1
        if (running_wait_time <= customer_patience && !line.isfull()) {
                newCustomer.set(time, 30);  // can take from 1-30 mins time
                line.enqueue(newCustomer);
                running_wait_time += newCustomer.getProcesstime();
        }
        // Check if the counter is ready to process next customer
        if (current_wait_time <= 0) {
            if (line.isempty()) continue;
            served++;
            line.dequeue(newCustomer);
            current_wait_time = newCustomer.getProcesstime();
        }
        current_wait_time--;
        running_wait_time--;
    }

    // print results
    std::cout.precision(3);
    std::cout << "\nCustomers per hour that lead to an\naverage "
              << customer_patience << " min wait time: " 
              << served / double(sim_hours) << " customers/hour"
              << "\nServed: " << served
              << '\n';

    return 0;
}

