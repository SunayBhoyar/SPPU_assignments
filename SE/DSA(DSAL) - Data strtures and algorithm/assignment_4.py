# <-------------------------------------------------------->
# Created by -  Sunay Bhoyar 
# Roll No. - 21110
# Course - SE (sem 3) DSL CE (SPPU 2019)
# <-------------------------------------------------------->

#all function are declared below 
# <-------------------------------------------------------->
class operations:

     # this is the constructor for the class
    def __init__(self,data):
        self.lis = data
    
    # this function is used get the list as return
    def getlist(self):
        return self.lis
    
    # this is swap items from list function
    def swap(self,giv_list ,pos1,pos2):
        giv_list[pos1],giv_list[pos2] = giv_list[pos2],giv_list[pos1]
        return giv_list
    
    # this is a simple sort function just to avoid any built in function 
    def Insertion_Sort (self,MyList):
        for i in range(len(MyList)-1):   
            if (MyList[i]>MyList[i+1]):
                MyList = self.swap(MyList,i,i+1)
                for j in range(i):
                    if(MyList[i-j-1]>MyList[i-j]):
                        MyList = self.swap(MyList,i-j,i-j-1)
                    else:
                        break    
                    j+=1                   
        return MyList
        
    # <-------------------------------------------------------->
    def linear_search (self):                                                                     # Linear search code here
        temp = int(input("Enter the roll  number you want to search\n"))  
        for i in range(len(self.lis)):
            if (temp == self.lis[i]):
                return "ELEMENT FOUND \nLocation - "+str(i)+"\n"
                break
        return "ELEMENT NOT IN LIST"
    
        
    # <-------------------------------------------------------->
    def sentinel_search(self):                                                                    # Sentinal search code here
        temp = int(input("Enter the roll  number you want to search\n")) 
        storage = self.lis[len(self.lis)-1]
        self.lis[len(self.lis)-1] = temp
        i = 0 
        while (self.lis[i] != temp):
            i+=1 
        self.lis[len(self.lis)-1] = storage 
        if(i < (len(self.lis) - 1)) or (temp == self.lis[len(self.lis) - 1]):
            return "ELEMENT FOUND \nLocation - "+str(i)+"\n"
        return "ELEMENT NOT IN LIST"    
    
    # <-------------------------------------------------------->
    def binary_search(self):                                                                     # Binary search code here
        key = int(input("Enter the roll  number you want to search\n")) 
        print("!! The list of roll numbers is being sorted !!") 
        temp_list = self.Insertion_Sort(self.lis)
        S = 0
        E = len(temp_list) -1
        while (S<=E):
            M = ( S + E ) // 2
            if (temp_list[M] == key):
                return "ELEMENT FOUND \nLocation - "+str(M)+"\n(When the list is sorted)\n"
            elif (temp_list[M] < key):
                S =  M + 1
            else :
                E = M
        return "ELEMENT NOT IN LIST"  
    
    # <-------------------------------------------------------->
    def fibo_search (self):                                                                     # Fibonacci search code here
        key = int(input("Enter the roll  number you want to search\n")) 
        print("!! The list of roll numbers is being sorted !!")
        data = self.Insertion_Sort(self.lis)
        off = -1 

        fm = 1
        fm1 = 1
        fm2 = 0

        n = len(data)

        while(fm < n ):
            fm2 = fm1 
            fm1 = fm 
            fm = fm1 + fm2

        while(fm > 1):
            i = min(off+ fm2 , n - 1)
            if(data[i]<key):
                fm = fm1 
                fm1 = fm2 
                fm2 = fm - fm1 
                off = i 
            elif(data[i]>key):
                fm = fm2 
                fm1 = fm1 - fm2 
                fm2 = fm2 - fm1 
            else :
                return i 
        if(data[n-1] == key )   :
            return n-1 
        else :
            return -1                      


# <-------------------------------------------------------->           
# main logic start here , the code is menu driven   

while (1>0):
    print("========================================================")
    menu = int(input("Enter the menu option you want to select\n1)Enter the data\n0)Exit\n"))
    
    if(menu== 0):
        break


    elif (menu == 1):        

        # the roll numbers are entered below 
        data1 = operations(list(map(int,input("Enter the roll numbers space separated\n").split())))      

        # the menu below is to use the searching algorithnms on the lists
        while(1>0):
            print("========================================================")
            menu1=int(input("\nEnter the menu choice you want to check \n1)Linear Search\n2)Sentinel Search\n3)Binary Search\n4)Fibonachi Search\n0)Return to main menu / Re-enter the data\n"))
            if(menu1 == 0):
                break
            elif(menu1==1):    
                print(data1.linear_search())
            elif(menu1 ==2):    
                print(data1.sentinel_search())  
            elif(menu1 ==3):    
                print(data1.binary_search()) 
            elif(menu1 ==4):    
                print(data1.fibo_search()) 
            else :
                print("Enter valid input")
    else :
        print("Enter valid input")    
                            

        
    