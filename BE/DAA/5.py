# <-------------------------------------------------------->
# Created by -  Sunay Bhoyar 
# Roll No. - 21110
# Course - SE (sem 3) DSL CE (SPPU 2019)
# <-------------------------------------------------------->

#all function are declared below 
class operations :  
    # this is the basic object creator function
    def __init__(self,data):
        self.lis = data
        
        
    #<------------------------------------------>    
    
    # this is main quick sort function
    def quick_sort (self,arr,low,high):
        if(len(arr) == 1):
            return arr
        if(low<high):
            piv = self.piv_shift(arr,low,high)  
            self.quick_sort(arr,low,piv -1)
            self.quick_sort(arr,piv+1,high)                   
        return arr                                     

    #<------------------------------------------>   
    
        
    # this is pivot shifter function
    def piv_shift (self,arr,low,high):
        i = low - 1
        pivot = arr[high]
        for j in range(low,high):
            if(arr[j] <= pivot): 
                i  = i + 1
                arr[i] , arr[j] = arr[j] , arr[i]
        arr[i+1] , arr[high] = arr[high] , arr[i+1]
        return i + 1    

    #<------------------------------------------>   
    
    
# run this code to test check              
# print(quick_sort([5,6,5,4,9,7,5,1,3,6,10,9,7], 0,13 ))            
     
     
     
#<------------------------------------------>        
while (1>0):
    print("========================================================")
    menu = int(input("Enter the menu option you want to select\n1)Enter the data\n0)Exit\n"))
    obj = operations([])
    if(menu== 0):
        print("Thanks for operations using the software")
        print("========================================================")
        break
    elif (menu == 1):        
        data1 = list(map(int,input("Enter the students percentage space separated\n").split()))    
        while(1>0):
            print("========================================================")
            menu1=int(input("\nEnter the menu choice you want to check \n1)Quick Sort\n2)0)Return to main menu / Re-enter the data\n"))
            if(menu1 == 0):
                break
            elif(menu1==1):    
                print(obj.quick_sort(data1,0,len(data1)))
            elif(menu1==2):    
                tempLis = obj.quick_sort(data1,0,len(data1))
                tempLis = tempLis[::-1]
                print(tempLis[0:5])
            else :
                print("Enter valid input")
    else :
        print("Enter valid input")            