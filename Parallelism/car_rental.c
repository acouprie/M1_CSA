/* 
Clients:
- Premium members are blocked when no employees are available
- Regular members are blocked when there is no regular employees available
- Premium members are unblocked when when a counter is freed
- Regular members are unblocked when there is a regular employee freed and
when a no premium member is waiting

Employee:
- Premium employees are blocked when there is no premium client waiting
- Regular employees are blocked when there is no client
- Premium employee are unblocked when there is a premium client arriving
- Regular employee are blocked when there is a client
*/

Monitor RentalCar {
    public:
    void goToCounter(bool isPremium);
    void serveClient(bool isPremiumEmployee);
    private:
    // States Variables
    bool employeeBusy[NB_EMPLOYEES];
    bool employeeStatus[NB_EMPLOYEES];
    //Conditions
    premiumClientQueue;
    regularClientQueue;
    premiumEmployeeQueue;
    regularEmployeeQUeue;
}

process Client(bool isPremium) {
    Monitor.goToCounter(isPremium);
}

process Employee(bool isPremiumEmployee) {
    while(1) {
        RentalCar.serveClient(isPremiumEmployee);
    }
}

// to be improve
// no need of employeeBusy
// Premium client check first for premium employee
void goToCounter(bool isPremium) {
    if(isPremium) {
        if (i = checkForFreeEmployee() == 0) {
            proviledgeClientQueue.Wait();
            i = checkForFreeEmployee();
        }
        employeeBusy[i] = true;
        if(premiumEmployeeQueue.size() != 0) {
            priviledgeQueue.signal();
        } else {
            normalEmployeeQueue.signal();
        }
    }
    // TODO else
}