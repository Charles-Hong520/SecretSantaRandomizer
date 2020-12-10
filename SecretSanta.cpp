#include <iostream>
#include <random>
#include <vector>
#include <fstream>

using namespace std;

void printSenderToReceiver(const vector<string>&);
void randomNumList(vector<unsigned>&);
void posNumToName(const vector<unsigned>&, vector<string>&);
void selectionSort(vector<unsigned>&, vector<unsigned>&);

int main() {
    cout << "Thanks for using Secret Santa Random gifting generator!" << endl;

    vector<string> nameList;
    ifstream inFS;
    inFS.open("participants.txt");
    if(!inFS.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string name = "";
    while(getline(inFS, name)) {
        nameList.push_back(name);
    }

    vector<unsigned> numList(nameList.size());

    randomNumList(numList);

    posNumToName(numList, nameList);

    printSenderToReceiver(nameList);


    inFS.close();
    return 0;
}

void randomNumList(vector<unsigned>& v) {
    random_device rd;
    unsigned random;
    vector<unsigned> randomInts;

    for(unsigned i = 0; i < v.size(); i++) {
        randomInts.push_back(rd());
        v.at(i) = i;
    } //created list of random unsigned, now need to sort them

    selectionSort(randomInts, v);
}

void posNumToName(const vector<unsigned>& num, vector<string>& name) {
    vector<string> tempName;
    for(unsigned i = 0; i < num.size(); i++) {
        tempName.push_back((name.at(num.at(i))));
    }
    name = tempName;
}

void printSenderToReceiver(const vector<string>& name) {
    cout << "The list will be different every time you execute './a.out' "<< endl << endl;
    for(unsigned i = 0; i + 1 < name.size(); i++) {
        cout << name.at(i) << " ---> " << name.at(i+1) << endl << endl;
    }
    cout << name.back() << " ---> " << name.at(0) << endl << endl;
}

void selectionSort(vector<unsigned>& v, vector<unsigned>& index)
{
    unsigned i, j, min_idx, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < v.size()-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < v.size(); j++) {
        if (v.at(j) < v.at(min_idx))
            min_idx = j;
        }
        // Swap the found minimum element with the first element
        temp = v.at(i);
        v.at(i) = v.at(min_idx);
        v.at(min_idx) = temp;

        temp = index.at(i);
        index.at(i) = index.at(min_idx);
        index.at(min_idx) = temp;
    }
}
