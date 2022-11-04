# M3OEP-itabb
Isaac Tabb | CS120 | M3 OEP

Languages used: C++, Python, R


### Applications Needed
You will need to have R downloaded on your machine to run this program.

### Summary
The purpose of this program is to test the accuracy of a linear model which predicts NBA player's Plus Minus (PM) rating explained by Personal Fouls (PF).
The program utilizes data extracted from Basketball Reference. The data is read in the C++ program and stored as a vector of PlayerStats objects. 
The data is cleaned so that it only stores Name, Plus Minus, and Personal Fouls. The data is then written to a .csv file which is passed to R. The R
program creates the Plus Minus explained by Personal Fouls linear model using the cleaned data. Once the R file has run and created necessary .csvs in the repo, the C++ file then calls the plotGraphs.py
file which graphs predicted vs. observed Plus Minus values. This graphs provides a visualization of how accurate the model is.

When the user runs the program, they are prompted with two choices. The first choice is to run the linear model, which calls linearModelPrint.R and prints all
necessary information about the model. The second choice is to predict using the model, where the user can enter personal fouls and get a predicted plus minus
rating. All user input is validated.

Module 3 Concepts used:
* Command Line Arguments (C++ -> Python, C++ -> R)
* Using System( ) to make a terminal call
* Graphing in Python (matplotlib)

### Known Bugs At Time of Submission
There are no known bugs at the time of submission.

### Future Work
If I had more time to expand this program, I would allow the user to choose which two statistics they would like to create a linear model for.
The user could get an overview of what NBA stats are in the dataset and choose one to be the response variable and one to be the explanatory variable.
The program would then run a linear model on those two variables and print out how accurate the model is. 

If I did this, I could also allow for the user to create a multiple linear model with more than one explanatory variable.

### Citations
#### Data Extracted From
https://www.basketball-reference.com/boxscores/?month=10&day=19&year=2022
#### Used in R Code
https://stackoverflow.com/questions/2669598/calling-r-script-from-within-c-code
#### Used in Python Code
https://towardsdatascience.com/how-to-read-csv-file-using-pandas-ab1f5e7e7b58


https://sparkbyexamples.com/pandas/conver-pandas-column-to-list/#:~:text=tolist()%20you%20can%20convert,the%20column%20values%20to%20list

### Grade Earned
For main program complexity and usability, I believe that I earned 40 out of 40 points. My program is complex and utilizes multiple concepts from Module 3 (CLI args, System( ), Matplotlib). My project is also interactive as it allows the user to predict using the model. My program validates all of the user's input.

For use of other programming languages, I believe that I earned 40 points by using both R and Python. I used R to create the linear model and create a .csv with predicted and observed values. I used Python to graph the predicted vs. observed values using matplotlib. This graph gives a visualization of how accurate the model is.

For Command Line Arguments, I had two calls. I passed files into R and into Python, so I would say that I earned 4 points here.

I also presented a demo in class so I earned 5 more points through that.

In total, I would say that my grade earned is around 89 points.







