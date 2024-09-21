# <-------------------------------------------------------->
# Created by -  Sunay Bhoyar 
# Roll No. - 21110
# Course - SE (sem 3) DSL CE (SPPU 2019)
# <-------------------------------------------------------->


# all the function are included below 
# <-------------------------------------------------------->
class operations:
    # this is the constructor for the class
    def __init__(self, string):
        self.string = string
    
    # this function is used to get the longest stream from the given string
    def longest_stream(self):
        space_positions =[0]
        lenghts = []
        result =set()
        temp = self.string + " "
        for i in range(len(temp)):
            if(temp[i] == " "):
                space_positions.append(i+1)
        for i in range(len(space_positions)-1):
            lenghts.append(space_positions[i+1]-space_positions[i]-1)      
        max_val = max(lenghts)         
        for i in range(len(lenghts)):
            if(max_val==lenghts[i]):
                result.add(temp[space_positions[i]:space_positions[i+1]-1])
        return result        
            
    # this function is used to the occurance of a particualr charecter      
    def frequency(self):    
        check = str(input("Enter the character whose occurrence you want to check"))
        count = 0
        for i in self.string:
            if(i == check):
                count += 1
        return count
    
    # this function is used to check if the given string is a pallindrome
    def palligcheck(self):
        for i in range(len(self.string)):
            if(self.string[i]==self.string[len(self.string)-i-1]):
                continue
            else :
                return "no it is palindrome" 
        return "yes it is palindrome"
    
    # this function is used to the occurance of a particualr substring first time
    def substringer(self):
        stri = input("Enter the substring you want to check")
        for i in range(len(self.string)-len(stri)+1):
            if (self.string[i:i+len(stri)]==stri):
                return "Yes the substring is present in the main string which is at location  "+str(i)
        return "No the substring does not exist in the main string"
    
    # this function is used to the get the dictionary of the list of elements 
    def frequency_all(self):
        temp = self.string + " "
        all_words = []
        all_freq = []
        count = 0
        for i in range(len(temp)):
            if (temp[i]!=" "):
                count +=1
            else :
                if (temp[i-count:i] not in all_words):
                    all_words.append(temp[i-count:i])
                    all_freq.append([temp[i-count:i],1])
                    count = 0
                else:
                    for j in range(len(all_freq)):
                        if(all_freq[j][0]==temp[i-count:i]):
                            all_freq[j][1]+=1
                            count =0
                            break                                                  
        return all_freq

# <-------------------------------------------------------->
# main logic start here , the code is menu driven        
while (1>0):
    print("========================================================")
    menu = int(input("Enter the menu option you want to select\n1)Enter the data\n0)Exit\n"))
    # <-------------------------------------------------------->
    if(menu== 0):
        break
    # <-------------------------------------------------------->
    elif (menu == 1):        
        print("Enter the main string\n")
        s1 = operations(str(input()))
        while(1>0):
            print("========================================================")
            menu1=int(input("\nEnter the menu choice you want to check \n1)Get the longest word/words\n2)Get frequency of particular character\n3)Check if the given string is a palindrome\n4)Check if a substring is present of not\n5)Get Frequency off all words in string\n0)Return to main menu / Change the string\n"))
            print("========================================================")

            # <--------------------------------------------------------> here are the all calls to the functions

            if(menu1 == 0):
                break
            elif(menu1==1):    
                print(s1.longest_stream())
            elif(menu1 ==2):    
                print(s1.frequency())
            elif (menu1 == 3):    
                print(s1.palligcheck())
            elif(menu1 == 4):    
                print(s1.substringer())
            elif(menu1 == 5):    
                print(s1.frequency_all())
            else:
                print("Enter a valid option")    

            # <-------------------------------------------------------->
    else:
        print("Enter valid input")    