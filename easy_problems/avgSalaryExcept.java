/*

1491. Average Salary Excluding the Minimum and Maximum Salary

Given an array of unique integers salary where salary[i] is the salary of the employee i.
Return the average salary of employees excluding the minimum and maximum salary.

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500

*/
class Solution {
    public double average(int[] salary) {
        // Sort the array.
        Arrays.sort(salary);
        double average = 0;
        // Start from the second element and accumulate until-
        // the second to last element.
        for(int i = 1; i < salary.length - 1; i++)
            average += salary[i];
        
        // Divide by the number of elements inbetween the first and last.  
        return average /= salary.length - 2;
    }
}
