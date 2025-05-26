class Solution {
public:
   // This function checks if it is possible to complete a circuit given the amount of gas at each station and the cost to get to the next station.
// The input is two vectors, gas and cost, representing the amount of gas at each station and the cost to get to the next station, respectively.
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // Initialize variables.
    int n = cost.size();  // Number of stations.
    int curr_gas=0;  // Gas in the tank at the current station.
    int total_gas=0;  // Total amount of gas at all stations.
    int total_cost=0;  // Total cost to get to all stations.
    int starting_point=0;  // Starting station for the circuit.

    // Iterate through each station.
    for(int i=0; i<n; i++){
        // Update total gas and cost.
        total_gas += gas[i];
        total_cost += cost[i];

        // Update current gas in tank.
        curr_gas += gas[i]-cost[i];

        // If there is not enough gas to reach the next station, update the starting point and reset the current gas.
        if(curr_gas<0){
            starting_point=i+1;
            curr_gas=0;
        }
    }

    // Return -1 if it is not possible to complete the circuit, otherwise return the starting point.
    return total_gas<total_cost? -1:starting_point;
}

};