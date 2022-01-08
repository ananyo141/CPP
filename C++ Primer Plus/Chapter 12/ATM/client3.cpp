/* 6. The Bank of Heather would like to know what would happen if it added a second
   ATM. Modify the simulation in this chapter so that it has two queues.Assume that
   a customer will join the first queue if it has fewer people in it than the second
   queue and that the customer will join the second queue otherwise.Again, find a
   value for number of customers per hour that leads to an average wait time of one
   minute. (Note:This is a nonlinear problem in that doubling the number of ATMs
   doesn’t double the number of customers who can be handled per hour with a one-
   minute wait maximum.) */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "atm.hpp"

int main() {
    using ATM::readValue;
    std::srand(std::time(0));
    unsigned maxQLen1, maxQLen2, avg_cus_ph, sim_hours;
    readValue("Enter queue 1 max: ", maxQLen1);
    readValue("Enter queue 2 max: ", maxQLen2);
    readValue("Enter number of simulation hours: ", sim_hours);
    readValue("Enter average customers per hour: ", avg_cus_ph);

    ATM::Customer newCustomer;
    ATM::Queue line1(maxQLen1), line2(maxQLen2);

    unsigned long totalMins = ATM::MIN_PER_HR * sim_hours;
    double min_per_customer = ATM::MIN_PER_HR / double(avg_cus_ph);

    unsigned turnaways = 0, accepted = 0, served = 0,
             current_wait_time = 0, cumulative_wait_time = 0;

    for (unsigned long i = 0; i < totalMins; i++) {
        if (ATM::checkCustomer(min_per_customer)) {
            if (line1.isfull() && line2.isfull()) turnaways++;
            else {
                accepted++;
                newCustomer.set(i);
                if (line1.len() <= line2.len() && !line1.isfull())
                    line1.enqueue(newCustomer);
                else
                    line2.enqueue(newCustomer);
            }
        }
        if (current_wait_time <= 0) {
            if (line1.isempty() && line2.isempty())
                continue;
            served++;
            if (line1.len() >= line2.len() && !line1.isempty())
                line1.dequeue(newCustomer);
            else
                line2.dequeue(newCustomer);
            current_wait_time += newCustomer.getProcesstime();
            cumulative_wait_time += i - newCustomer.getArrival();
        }
        current_wait_time--;
    }
    // Print the results
    double avg_wait = cumulative_wait_time / float(served);
    std::cout.precision(3);
    std::cout << "\nCustomers Accepted: " << accepted
              << "\nCustomers Served  : " << served
              << "\nCustomers Rejected: " << turnaways
              << "\nAverage Wait Time : " << avg_wait << " min/customer"
              << "\nAverage Number of Customers \n"
              << "for a waiting time of 1 min: " << avg_cus_ph / float(avg_wait)
              << '\n';

    return 0;
}

