#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


void readData(const string &filename, vector<double> &angleset, vector<double> &liftset) {
    double angle;
    double lift;

    ifstream inFS;
    inFS.open(filename);

    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    while (inFS >> angle >> lift) {
        angleset.push_back(angle);
        liftset.push_back(lift);
    }

}



double interpolation(double inputangle, const vector<double> &angleset, const vector<double> &liftset) {
    
    double a;
    double c;

    double alift;
    double clift;

   // double maximum;
   // double minimum;

    double result;
    

    if (inputangle < angleset.at(0) || inputangle > angleset.at(angleset.size()-1)) {
        return 0.0;
    }

    for (unsigned int i = 0; i < angleset.size(); ++i) {
        if (inputangle == angleset.at(i)) {
            result = liftset.at(i);
            return result;
        }
        else {
            result = 0;
        }
    }
    

    for (unsigned int i = 0; i + 1 < angleset.size(); ++i) {
        if (angleset.at(i) < inputangle && angleset.at(i+1) > inputangle) {
            a = angleset.at(i+1);
            c = angleset.at(i);
            alift = liftset.at(i+1);
            clift = liftset.at(i);

            cout << a << inputangle << c << endl;

            cout << alift << clift << endl;

            double temp = (inputangle - a)/(c - a);

            result = alift + ( temp *(clift - alift));
           // result = result + alift;
           // result = alift + (inputangle - a);
           // result = result / ((c - a)*(clift - alift));

           // return result;
           cout << result;
        }
    }

    return result;

}

bool isOrdered(const vector<double> &angleset) {

    if (angleset.size() == 0 || angleset.size() == 1) {
        return true;
    }

    else {
        for (unsigned int i = 0; i + 1 < angleset.size(); ++i) {
            if (angleset.at(i) > angleset.at(i+1)) {
            return false;
            }
        }
    }

    return true;
}

void reorder(vector<double> &angleset, vector<double> &liftset) {
    double tempangle;
    double templift;

    if (angleset.size() > 1) {

        for (unsigned int i = 0; i + 1 < angleset.size(); ++i) {

            int indexSmallest = i;

            for (unsigned int j = i + 1; j < angleset.size(); ++j) {
                
                if (angleset.at(j) < angleset.at(indexSmallest)) {
                    indexSmallest = j;
                }
                
            }
            tempangle = angleset.at(i);
            angleset.at(i) = angleset.at(indexSmallest); 
            angleset.at(indexSmallest) = tempangle;

            templift = liftset.at(i);
            liftset.at(i) = liftset.at(indexSmallest);
            liftset.at(indexSmallest) = templift;
        }
    }

}

int main (int argc, char* argv[]) {

    ifstream inFS;
    string filename;

    vector <double> angleset;
    vector <double> liftset;
    string response;
    //double userangle;
    //string
    double inputangle;

    filename = argv[1];

    readData(filename, angleset, liftset);
    cout << isOrdered(angleset);

    if (!isOrdered(angleset)) {
        reorder(angleset, liftset);
    }

    cout << "Enter a flight-path angle:" << endl;
    cin >> inputangle;


    cout << interpolation(inputangle, angleset, liftset);
    
    cout << "Enter another flight-path angle?" << endl;
    cin >> response;

    if (response == "Yes") {
        inputangle = 0;
        cin >> inputangle;
        cout << interpolation(inputangle, angleset, liftset);
    }



}
