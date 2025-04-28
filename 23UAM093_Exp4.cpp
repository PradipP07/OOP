#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    string make;
    string model;
    int year;
    bool isRented;
    double dailyRentalRate;

public:
    Vehicle(string vehicleID, string make, string model, int year, double dailyRentalRate)
        : vehicleID(vehicleID), make(make), model(model), year(year), isRented(false), dailyRentalRate(dailyRentalRate) {}

    virtual ~Vehicle() {}

    string getVehicleID() const { return vehicleID; }
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    bool getIsRented() const { return isRented; }
    double getDailyRentalRate() const { return dailyRentalRate; }

    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }

    virtual double calculateRentalCost(int days) = 0;

    virtual void displayDetails() const = 0;
};

class Car : public Vehicle {
private:
    int numberOfDoors;
    string fuelType;

public:
    Car(string vehicleID, string make, string model, int year, double dailyRentalRate, int numberOfDoors, string fuelType)
        : Vehicle(vehicleID, make, model, year, dailyRentalRate), numberOfDoors(numberOfDoors), fuelType(fuelType) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days;
    }

    void displayDetails() const override {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
        cout << "Number of Doors: " << numberOfDoors << ", Fuel Type: " << fuelType << endl;
        cout << "Rental Rate: $" << dailyRentalRate << " per day" << endl;
        cout << "Rental Status: " << (isRented ? "Rented" : "Available") << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    string engineType;
    bool hasSidecar;

public:
    Motorcycle(string vehicleID, string make, string model, int year, double dailyRentalRate, string engineType, bool hasSidecar)
        : Vehicle(vehicleID, make, model, year, dailyRentalRate), engineType(engineType), hasSidecar(hasSidecar) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (hasSidecar ? 20 * days : 0);
    }

    void displayDetails() const override {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
        cout << "Engine Type: " << engineType << ", Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
        cout << "Rental Rate: $" << dailyRentalRate << " per day" << endl;
        cout << "Rental Status: " << (isRented ? "Rented" : "Available") << endl;
    }
};

class Truck : public Vehicle {
private:
    double cargoCapacity;
    int numberOfAxles;

public:
    Truck(string vehicleID, string make, string model, int year, double dailyRentalRate, double cargoCapacity, int numberOfAxles)
        : Vehicle(vehicleID, make, model, year, dailyRentalRate), cargoCapacity(cargoCapacity), numberOfAxles(numberOfAxles) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (cargoCapacity * 10 * days);
    }

    void displayDetails() const override {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
        cout << "Cargo Capacity: " << cargoCapacity << " cubic meters, Number of Axles: " << numberOfAxles << endl;
        cout << "Rental Rate: $" << dailyRentalRate << " per day" << endl;
        cout << "Rental Status: " << (isRented ? "Rented" : "Available") << endl;
    }
};

class RentalSystem {
private:
    vector<Vehicle*> vehicles;

public:
    ~RentalSystem() {
        for (auto  vehicle : vehicles) {
            delete vehicle;
        }
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAvailableVehicles() {
        for (auto vehicle : vehicles) {
            if (!vehicle->getIsRented()) {
                vehicle->displayDetails();
                cout << endl;
            }
        }
    }

    Vehicle* findVehicle(string vehicleID) {
        for (auto vehicle : vehicles) {
            if (vehicle->getVehicleID() == vehicleID) {
                return vehicle;
            }
        }
        return nullptr;
    }

    void rentVehicle(string vehicleID, int days) {
        Vehicle* vehicle = findVehicle(vehicleID);
        if (vehicle && !vehicle->getIsRented()) {
            vehicle->rentVehicle();
            double cost = vehicle->calculateRentalCost(days);
            cout << "Rental Cost: $" << cost << endl;
        } else {
            cout << "Vehicle not available or already rented." << endl;
        }
    }

    void returnVehicle(string vehicleID) {
        Vehicle* vehicle = findVehicle(vehicleID);
        if (vehicle && vehicle->getIsRented()) {
            vehicle->returnVehicle();
            cout << "Vehicle returned successfully." << endl;
        } else {
            cout << "Vehicle not found or not rented." << endl;
        }
    }
};

int main() {
    RentalSystem rentalSystem;

    Car* car = new Car("CAR123", "Toyota", "Camry", 2020, 50, 4, "Gasoline");
    Motorcycle* motorcycle = new Motorcycle("MOTO456", "Harley-Davidson", "Sportster", 2021, 40, "V-Twin", true);
    Truck* truck = new Truck("TRUCK789", "Ford", "F-150", 2019, 80, 20.0, 4);

    rentalSystem.addVehicle(car);
    rentalSystem.addVehicle(motorcycle);
    rentalSystem.addVehicle(truck);

    int choice;
    string vehicleID;
    int days;

    do {
        cout << "1. Display Available Vehicles" << endl;
        cout << "2. Rent a Vehicle" << endl;
        cout << "3. Return a Vehicle" << endl;
        cout << "4. Find Vehicle and Display Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rentalSystem.displayAvailableVehicles();
                break;
            case 2:
                cout << "Enter Vehicle ID: ";
                cin >> vehicleID;
                cout << "Enter number of days: ";
                cin >> days;
                rentalSystem.rentVehicle(vehicleID, days);
                break;
            case 3:
                cout << "Enter Vehicle ID: ";
                cin >> vehicleID;
                rentalSystem.returnVehicle(vehicleID);
                break;
            case 4:
                cout << "Enter Vehicle ID: ";
                cin >> vehicleID;
                Vehicle* vehicle = rentalSystem.findVehicle(vehicleID);
                if (vehicle) {
                    vehicle->displayDetails();
                } else {
                    cout << "Vehicle not found." << endl;
                }
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
