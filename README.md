# NBA Plus Minus Explained By Personal Fouls: A Linear Model
### Isaac Tabb

Languages used: C++, Python, R


### Applications Needed
You will need to have R downloaded on your machine to run this program.

### Summary
The purpose of this program is to test the accuracy of a linear model which predicts NBA player's Plus Minus (PM) rating explained by Personal Fouls (PF).
The program utilizes data extracted from Basketball Reference. The data is from NBA games which occurred on October 19, 2022. The data is read in the C++ program and stored as a vector of PlayerStats objects. The data is then cleaned so that it only stores Name, Plus Minus, and Personal Fouls. The data is then written to a .csv file which is passed to R. The R program creates the Plus Minus explained by Personal Fouls linear model using the cleaned data. Once the R file has run and created necessary .csvs in the repository, the C++ file then calls the plotGraphs.py file which graphs predicted vs. observed plus minus values. This graph provides a visualization of how accurate the model is. 

The correlation coefficient for the model was -.21667, a weak to slightly moderate correlation. In the context of the data, this coefficient shows that on average, a player with a large number of personal fouls will have a lower plus minus score.

Note: Clearly, as with many sports models, this linear model violates independence of cases. Plus minus is a player statistic which can often depend on a player's teammates. Thus, this violation was unavoidable. 

This program is user interactive. When the user runs the program, they are prompted with two choices. The first choice is to run the linear model, which calls linearModelPrint.R and prints all necessary information about the model. The second choice is to predict using the model, where the user can enter personal fouls and get a predicted plus minus rating. All user input is validated.

### Future Work
In the future, I would like to expand this program to allow the user to choose which statistics that they would like to create a linear model for.
The user could get an overview of what NBA stats are in the dataset and choose one to be the response variable and one or more to be the explanatory variable(s). The program would then run a linear model on the chosen variables and print out how accurate the model is. 

### Citations
#### Data Extracted From
NBA Games Played on October 19, 2022 | Basketball-Reference.com. https://www.basketball-reference.com/boxscores/?month=10&amp;day=19&amp;year=2022. 
#### Used in R Code
user320602. “Calling R Script from within C-Code.” Stack Overflow, 1 July 1957, https://stackoverflow.com/questions/2669598/calling-r-script-from-within-c-code. 
#### Used in Python Code
How to Read CSV File into Python Using Pandas. https://towardsdatascience.com/how-to-read-csv-file-using-pandas-ab1f5e7e7b58. 

Nnk. “How to Convert Pandas Column to List.” Spark by {Examples}, 27 Jan. 2022, https://sparkbyexamples.com/pandas/conver-pandas-column-to-list/. 







