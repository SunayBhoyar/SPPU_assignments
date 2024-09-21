# <-------------------------------------------------------->
# Created by -  Sunay Bhoyar 
# Roll No. - 21110
# Course - SE (sem 3) DSL CE (SPPU 2019)
# <-------------------------------------------------------->

#all functions included below
# <-------------------------------------------------------->

# this function deletes the multiple elements 
def rep_eli (a):
    temp_list=[]
    for j in range(len(a)):
        if (a[j] not in temp_list):        
            temp_list.append(a[j])
    return temp_list

# this function return the union of the two lists
def union(s1,s2):
    temp_list =s1+s2
    return(rep_eli(temp_list))

# this function return the intersection of the two lists
def intersection(s1,s2):
    temp_list1 =[]
    for k in range(len(s1)):
        if(s1[k] in s2):
            temp_list1.append(s1[k])
    return temp_list1

# this function return the Symmetric diffrence  of the two lists
def symdiffrence (s1,s2):
    list1 = union(s1,s2)
    list2 = intersection(s1, s2)
    list3 =[]
    for k in range(len(list1)):
        if(list1[k] not in list2):
            list3.append(list1[k])
    return list3

# this function return the Diffrence  of the two lists    
def diffrence (s1,s2):
    list1 = intersection(s1, s2)
    list2 =[]
    for k in range(len(s1)):
        if(s1[k] not in list1):
            list2.append(s1[k])
    return list2

# <-------------------------------------------------------->
#the main logic starts here , the code is menu driven below 
while(1>0):
    print("=================================================================")            
    print("Enter the option number from given below options \n1) Enter the roll numbers of students\n2) Show the set of students in class and each sport \n3) Get the required students as per given 4 cases\n0) Enter 0 to exit \n ")    
    menu = int(input())

    if(menu == 0 ):
        break

# <-------------------------------------------------------->
    elif(menu == 1):
        print("Enter roll number of all students in the class - ")
        all_students = []
        all_students.append([])
        while(1>0):
                temp = int(input())
                if(temp==0):
                    break
                else:
                    all_students[0].append(temp) 
        ALL = rep_eli(all_students[0])            
    
        #entering cricketers   
        print("enter the students roll no plying cricket \n type 0 when one subject students number are finished\n")
        all_students.append([])
        while(1>0):
                temp = int(input())
                if(temp==0):
                    break
                else:
                    all_students[1].append(temp)
        A = rep_eli(all_students[1])
        #entering footballers      
        
                 
        print("enter the students roll no plying football \n type 0 when one subject students number are finished\n")
        all_students.append([])
        while(1>0):
                temp = int(input())
                if(temp==0):
                    break
                else:
                    all_students[2].append(temp)
        B = rep_eli(all_students[2])     
        #entering badmintioners   
        
              
        print("enter the students roll no plying badminton \n type 0 when one subject students number are finished\n")
        all_students.append([])
        while(1>0):
                temp = int(input())
                if(temp==0):
                    break
                else:
                    all_students[3].append(temp)                          
        C = rep_eli(all_students[3])


# <-------------------------------------------------------->
# this option shows the individual sets
    elif(menu == 2):
        #to view the sets 
        print("the set of all students in class -",ALL)           
        print("the set of players in cricket -",A)
        print("the set of players in football -",B)
        print("the set of players in badminton -",C)

     
# <-------------------------------------------------------->   
# this option shows the given question constraints
    if(menu == 3):        
        #to view the given requiremnets
        print("students who play both cricket and badminton -- ",intersection(A,C))
        print("students who play either cricket or badminton but not both --",symdiffrence(A,C))
        print("Number of students who play neither cricket nor badminton--",union(diffrence(B,union(A,C)),ALL),"  So number of students = ",union(diffrence(B,union(A,C)),ALL))
        print("Number of students who play cricket and football but not badminton--",diffrence(union(A,B),C)  , "  So number of students = ",len(diffrence(union(A,B),C)))
    