#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int numResistors{0};
    double voltage{0.0};
    string type="";
    double totalResistance{0.0};

    cout << "Enter circuit type (S for series, P for parallel)";
    cin >> type;
    cout << "Enter # of resistors: ";
    cin >> numResistors;
    cout << "\nEnter Voltage: ";
    cin >> voltage;

    vector<double> resistors(numResistors);
    for(int i=0; i<numResistors; ++i) {
        cout << "Enter resistance of R " <<  i + 1 << " in ohms : ";
        cin >> resistors[i];
    }
    if(type == "S" || type == "s") {
        for (double r : resistors) totalResistance += r;
        double current = voltage / totalResistance;
    }


    else if (type == "P" || type == "p") {
        double invR = 0.0;
        for (double r : resistors) invR += 1.0 / r;
        totalResistance = 1.0 / invR;
        double totalCurrent = voltage / totalResistance;
        
        cout << "\nTotal Resistance: " << totalResistance << " Ω" << endl;
        cout << "Total Current: " << totalCurrent << " A\n";
        
        for (int i = 0; i < numResistors; ++i) {
            double iBranch = voltage / resistors[i];
            cout << "Current through R" << i + 1 << ": " << iBranch << " A" << endl;
        }
    } else {
        cout << "Invalid circuit type selected." << endl;
    }

    return 0;
}
