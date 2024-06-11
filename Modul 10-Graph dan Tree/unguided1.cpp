#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int numNodes;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    vector<vector<int>> distanceMatrix(numNodes, vector<int>(numNodes));

    // Masukkan nama nodes
    for (int i = 0; i < numNodes; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Masukkan jarak antar node
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (i == j) {
                distanceMatrix[i][j] = 0;
            } else {
                cout << "Silakan masukkan bobot antar simpul " << nodes[i] << "-->" << nodes[j] << ": ";
                cin >> distanceMatrix[i][j];
            }
        }
    }

    // Print jarak matriks
    cout << "\n      "; 
    for (const auto& node : nodes) {
        cout << setw(6) << node; 
    }
    cout << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << setw(6) << nodes[i]; 
        for (int j = 0; j < numNodes; ++j) {
            cout << setw(6) << distanceMatrix[i][j]; 
        }
        cout << endl;
    }

    return 0;
}