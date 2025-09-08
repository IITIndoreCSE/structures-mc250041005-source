#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define the Sensor struct to hold sensor data
struct Sensor {
    int id;
    double temperature;
    double voltage;
    char status[20];  // assuming status is a string of max 20 characters
};

// Function to print sensor information in the exact format
void print_sensor(int index, int id, double temperature, double voltage, const char* status) {
    // Print exactly like your desired format
    cout << "Sensor[" << index << "]: id=" << id
         << ", temperature=" << temperature
         << ", voltage=" << voltage
         << ", status=" << status << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    int num_sensors;
    input >> num_sensors;

    const int MAX_SENSORS = 10;

    // Create an array of Sensor objects (only allocate space for up to MAX_SENSORS)
    Sensor sensors[MAX_SENSORS];

    // Read sensor data from the file
    for (int i = 0; i < num_sensors; i++) {
        input >> sensors[i].id;
        input >> sensors[i].temperature;
        input >> sensors[i].voltage;
        input >> sensors[i].status;
    }

    // Use a pointer to iterate over the sensors and print their data
    Sensor* sensor_ptr = sensors;
    for (int i = 0; i < num_sensors; i++) {
        print_sensor(i, sensor_ptr->id, sensor_ptr->temperature, sensor_ptr->voltage, sensor_ptr->status);
        sensor_ptr++;  // Move the pointer to the next Sensor
    }

    return 0;
}

