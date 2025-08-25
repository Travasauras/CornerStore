# CornerStore

For the final project in my introductory c++ course, I was tasked with writing a program that could read in a text file, organize the text file by mapping out the contents of it then return the organized count of items that appear in the txt file. When testing the program, I felt it needed a something to handle if the user used upper or lower cased letters in any part of the word since the return of a specific search in the list was dependent on the case it is written in the txt file, so I added a function that would allow the user to write their search in any case form they wanted while still returning the item searched for as long as it was spelled the same.  It also needed a way to validate user input for the program menu, which I included.  The program used OOP with functions for pulling from the list defined in the "GroceryItem" class then called in the "main" file. 

In the end the program worked as requested with a few extra functions that weren't requested but made the program handle potential operator errors. 

I felt I predicted potential user errors pretty well in the sense that when a user searches for "apples" that it would not return anything on the list even though "Apples" appears several times.  Writing a funtion that handles this potential problem was a bit of a challenge because I still wanted the return to represent the case sensitivity found in the TXT file regardless of what case was input by the user. 

I think maybe the Menu could have used a bit of work to appear a little more flashy and fun but at the end of the day having a program that worked as needed was my priority. 

Reading in txt files and organizing them is clearly something that will be transferrable to any projects or course work I will come across in the future. Also input validation.

Using seperate classes with extensive code commenting will help keep my code maintainable. Plenty of whitespace kept it readable, and adaptable.
