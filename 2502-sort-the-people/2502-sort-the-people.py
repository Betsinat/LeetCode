class Solution(object):
    def sortPeople(self, names, heights):
       pair = zip(names,heights)
       res = sorted(pair , key =lambda x: x[1] ,reverse = True)
       return [names for names ,heights in res ]
        