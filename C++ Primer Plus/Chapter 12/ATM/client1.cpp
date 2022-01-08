/* An ATM Simulation program, simulate a queue of bank customers
   waiting for their turn at the teller machine for a specified number
   of hours entered by the user, post results at the end of the simulation */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "atm.hpp"
#undef  DEBUG
#define DEBUG(elem)

int main() {
    using ATM::readValue;
    using ATM::MIN_PER_HR;
    std::srand(std::time(0));   // call rand seeder once

    // Read User Input
    double max_qsize, sim_hours, avg_cus_ph;
    readValue("Enter maximum size of queue: ", max_qsize);
    readValue("Enter the number of simulation hours: ", sim_hours);
    readValue("Enter the average number of customer per hour: ", avg_cus_ph);

    ATM::Queue line(max_qsize);
    unsigned long totalMins = sim_hours * MIN_PER_HR;
    double mins_per_customer = MIN_PER_HR / double(avg_cus_ph);
    DEBUG(mins_per_customer);

    ATM::Customer newCustomer;
    unsigned accepted = 0, served = 0, turnaways = 0, cumulative_q_size = 0,
             current_wait_time = 0, cumulative_wait_time = 0;
    // Simulate a minute of time for every cycle of loop
    for (int i = 0; i < totalMins; i++) {
        // For every min,
        // Check if a new customer has arrived
        if (ATM::checkCustomer(mins_per_customer)) {
            if (line.isfull()) turnaways++;
            else {
                accepted++;
                newCustomer.set(i);
                line.enqueue(newCustomer);
            }
        }
        // Check if counter is empty and can process another customer
        if (current_wait_time <= 0) {
            if (line.isempty()) continue;
            served++;
            line.dequeue(newCustomer);
            current_wait_time += newCustomer.getProcesstime();
            cumulative_wait_time += i - newCustomer.getArrival();   // (time right now) - (time joined)
        }
        current_wait_time--;
        cumulative_q_size += line.len();
    }

    // Print the results
    double avg_wait = cumulative_wait_time / float(served);
    std::cout.precision(3);
    std::cout << "\nCustomers Accepted: " << accepted
              << "\nCustomers Served  : " << served
              << "\nCustomers Rejected: " << turnaways
              << "\nAverage Queue Size: " << cumulative_q_size / float(totalMins) << " customers"
              << "\nAverage Wait Time : " << avg_wait << " min/customer"
              << "\nAverage Number of Customers \n"
              << "for a waiting time of 1 min: " << avg_cus_ph / float(avg_wait)
              << '\n';

    return 0;
}

