class Solution(object):
    def interpret(self, command): 
        interpreted =""
        i = 0
        n = len(command)
        while i < n:
            if command[i] == "G":
                interpreted += "G"
            elif command[i:i+2] == "()":
                interpreted += "o"
            elif command[i:i+4] =="(al)":
                interpreted += "al"
            i+=1
        return interpreted
                
        
        
        



     
        