class Sports:
    _cricket = []
    _badminton = []
    _football = []
    _student = []
    _cricketAndBadminton = []
    _cORbNotboth = []
    _c = []
    _d = []
        
    def setter(self,val,ch):
        if(ch == 'B'):
            self._badminton.append(val)
        elif(ch == 'C'):
            self._cricket.append(val)
        else:
            self._football.append(val)
    
    def _unionFinder(self,lis1,lis2):
        answer = list(lis1)
        for i in lis2:
            if i not in answer:
                    answer.append(i)
        return answer

    def _intersectionFinder(self, lis1,lis2):
        answer = []
        for i in lis1:
            if i in lis2:
                answer.append(i)
        return answer

    def _differenceFinder(self,lis1,lis2):
        answer = []
        for i in lis1:
            if i not in lis2:
                answer.append(i)
        return answer
    
    def solve(self):
        self._student = self._football
        for i in self._badminton:
            if i not in self._student:
                self._student.append(i)
        for i in self._cricket:
            if i not in self._student:
                self._student.append(i)
        
        self._cricketAndBadminton = self._intersectionFinder(self._cricket,self._badminton)
        cricketORbadminton = self._unionFinder(self._cricket,self._badminton)
        self._cORbNotboth = self._differenceFinder(cricketORbadminton,self._cricketAndBadminton)
        self._c = self._differenceFinder(self._student,self._unionFinder(self._cricket,self._badminton))
        self._d = self._differenceFinder(self._intersectionFinder(self._cricket,self._football),self._badminton)
    
    def getter(self):
        self.solve()
        return self._cricketAndBadminton, self._cORbNotboth,len(self._c),len(self._d)

sp = Sports()
n = int(input('Total Football players : '))
for i in range(0,n):
    sp.setter(int(input()),'F')

m = int(input('Total Badminton players : '))
for i in range(0,m):
    sp.setter(int(input()),'B')

o = int(input('Total Cricket players : '))
for i in range(0,o):
    sp.setter(int(input()),'C')

sp.solve()
a,b,c,d = sp.getter()
print('Cricket And Badminton ',a)
print('Cricket OR Badminton but not both : ',b)
print('Number of students who play neither cricket nor badminton : ', c)
print('Number of students who play cricket and football but not badminton : ',d)
    



        
        
