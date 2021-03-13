/*
451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

*/
class Solution {
    // Function to sort hashmap by values (FROM GEEKSFORGEEKS). 
    public static HashMap<Character, Integer> sortByValue(HashMap<Character, Integer> hm) 
    { 
        // Create a list from elements of HashMap. 
        List<Map.Entry<Character, Integer> > list = 
               new LinkedList<Map.Entry<Character, Integer> >(hm.entrySet()); 
  
        // Sort the list.
        Collections.sort(list, new Comparator<Map.Entry<Character, Integer> >() { 
            public int compare(Map.Entry<Character, Integer> o1,  
                               Map.Entry<Character, Integer> o2) 
            { 
                return (o1.getValue()).compareTo(o2.getValue()); 
            } 
        }); 
          
        // put data from sorted list to hashmap  
        HashMap<Character, Integer> temp = new LinkedHashMap<Character, Integer>(); 
        for (Map.Entry<Character, Integer> aa : list) { 
            temp.put(aa.getKey(), aa.getValue()); 
        } 
        return temp; 
    }
    
    // *** (MY CODE).
    public String frequencySort(String s) {
        
        if(s.length() == 0 || s.length() == 1) return s;
        // Map characters to their frequency in string.
        HashMap<Character,Integer> freq = new HashMap<Character,Integer>();
        
        // Add characters to hashmap.
        for(int i = 0; i < s.length(); i++){
            
            if(freq.containsKey(s.charAt(i)))
                freq.put(s.charAt(i), freq.get(s.charAt(i)) + 1);
    
            else
                freq.put(s.charAt(i), 1);    
        }
        
        // Sort characters by value (frequency).
        Map<Character,Integer> freq2 = sortByValue(freq); 
        int k = 0;
        String freqS = "";
        // Loop through and append characters to string.
        for(Map.Entry<Character,Integer> val: freq2.entrySet()){
            System.out.println(val.getValue() + " " + val.getKey());
            while(k < val.getValue()){ 
            freqS += val.getKey();
            k++;
            }
            k = 0;
        }
        // Reverse string since frequency order is reversed.
        StringBuffer ans = new StringBuffer(freqS);
        return ans.reverse().toString();
        
    }
}
