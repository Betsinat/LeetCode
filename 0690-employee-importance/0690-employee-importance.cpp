class Solution {
public:
    int getImportance(vector<Employee*> employees, int targetId) {
        // First create a quick lookup map for employees
        unordered_map<int, Employee*> employeeMap;
        for(Employee* emp : employees) {
            employeeMap[emp->id] = emp;
        }
        
        // Now calculate the total importance recursively
        return calculateTotalImportance(employeeMap, targetId);
    }   
private:
    int calculateTotalImportance(unordered_map<int, Employee*>& empMap, int currentId) {
        // Get the current employee's record
        Employee* current = empMap[currentId];
        // Start with the employee's own importance value
        int totalImportance = current->importance;
        // Add importance of all direct reports
        for(int subordinateId : current->subordinates) {
            totalImportance += calculateTotalImportance(empMap, subordinateId);
        }
        return totalImportance;
    }
};