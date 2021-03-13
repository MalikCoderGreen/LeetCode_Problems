/*
468. Validate IP Address

Given a string IP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. 
For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses but "192.168.01.1", "192.168.1.00" and "192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
  - 1 <= xi.length <= 4
  - xi is a hexadecimal string which may contain digits, lower-case English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
  - Leading zeros are allowed in xi.

Input: IP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Input: IP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.

Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334:"
Output: "Neither"
*/

class Solution {
public:
    string validIPAddress(string IP) {
        // Cases for empty string and an address greater than-
        // the maximum length for IPv6.
        if(IP.length() == 0 || IP.length() > 39) return "Neither";
        
        if(IP[IP.length()-1] == '.' || IP[IP.length()-1] == ':')
            return "Neither";
        
        // Check for protocol notation.
        int i = 0;
        while(IP[i] != '.' && IP[i] != ':') i++;
        
        // IPv4 check.
        if(IP[i] == '.'){  
            std::string tmp = ""; // String to obtain x_i sequence.
            int k = 0, l = 0;
            int dots = 0; // IPv4 should have 3 dots.
            
            // Loop to check each indvidual number sequence.
            while(k < IP.length()){
                
                tmp = "";
                while(IP[l] != '.' && l != IP.length()){
                    if(!isdigit(IP[l])) 
                        return "Neither";
                    
                    tmp += IP[l];
                    l++;
                }
                
                // Move l to beginning of next x_i sequence.
                dots++;
                
                // Check for back-to-back dots '..'.
                if(l < IP.length()-1 && IP[l+1] == '.') return "Neither";
                l++;
                   
                // Check for leading 0s. 
                if(tmp.length() > 1 && tmp[0] == '0') return "Neither";
                
                // Convert string to int for range check below (0 <= x_i <= 255).
                int x = std::stoi(tmp);
                if(x < 0 || x > 255) return "Neither";
                         
                k = l;
            }  
    
            if(dots - 1 == 3) return "IPv4";   
        }
        
        // IPv6 check.
        else if(IP[i] == ':'){
            int k = 0, l = 0;
            int colons = 0; // IPv_6 should have 7 colons.
            std::string tmp = "";
            
            // Check each x_i sequence for IPv6.
            while(k < IP.length()){
                
                tmp = "";   
                while(IP[l] != ':' && l != IP.length()){
                    // IPv6 violation: special chars i.e '@', '#'..
                    if(!isdigit(IP[l]) && !isalpha(IP[l]))      
                        return "Neither";     
                    
                    // Check chars are between A and F with ascii values.
                     if(isalpha(IP[l]) && int(toupper(IP[l])) > 70)   
                         return "Neither";
                     
                    tmp += IP[l];
                    l++;     
                }
                
                // IPv6 x_i length violation.
                if(tmp.length() > 4 || tmp.length() < 1)      
                   return "Neither"; 
                 
                colons++;
                l++;
                k = l;
            }
            if(colons - 1 == 7) return "IPv6";
        }
      
        return "Neither";
    }
};
