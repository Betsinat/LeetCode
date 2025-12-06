class Solution(object):
    def interpret(self, command): 
        interpreted =""
        for i in range(len(command)):
            if command[i] == "G":
                interpreted +=(command[i])
            elif command[i]=="(" and command[i+1] == ")":
                interpreted +=("o")
                i += 2
            elif command[i] =="(" and command[i+1] == "a":
                interpreted +=("al")
                i += 4
        return interpreted

        
        



     
        