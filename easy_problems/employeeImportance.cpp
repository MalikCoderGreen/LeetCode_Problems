/*
690. Employee Importance

You are given a data structure of employee information, which includes the employee's unique id, 
their importance value and their direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. 
They have importance value 15, 10 and 5, respectively. 
Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. 
Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, 
you need to return the total importance value of this employee and all their subordinates.

Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11

Explanation:
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. 
They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // 'workerToImp' will map ids to importance and 'workerToSubs' will map-
        // ids to subordinates list.
        map<int, int> workerToImp;
        map<int, vector<int>> workerToSubs;
        
        // Worker's importances will be added while using a queue to process workers-
        // if they are subordinates of other workers that lead back up to the root.
        // (root being 'id' from function param)
        queue<int> q;
        
        // Loop through 'employees' and populate both maps.
        for(Employee* w: employees){
            // Insert ids and map them to their importances.
            workerToImp.insert({w->id, w->importance});
            
            // We only want to add values to this map if a worker has subordinates.
            if(w->subordinates.size() > 0)
                workerToSubs.insert({w->id, w->subordinates});
        }
        
        // Push the root id given from problem.
        q.push(id);
        // Check the subordinates of the worker who is at the front of the queue and add them. 
        // Continue loop unitl no employees left to process.
        int totalVal = 0;
        while(!q.empty()){
            totalVal += workerToImp[q.front()];
            for(int i: workerToSubs[q.front()])
                q.push(i);
            
            q.pop();
        }

        return totalVal;
        
    }
};
