# plotGraphs
# This program is called by main.cpp as a means of plotting the predicted and observed
# data computed by the linear model in R.
# This file takes in one command line argument, the file holding the predicted and observed values.
# The file creates the graph and saves it in the repo.

import matplotlib.pyplot as plt
import sys
import pandas as pd
import random as rand

# sources:
# https://towardsdatascience.com/how-to-read-csv-file-using-pandas-ab1f5e7e7b58
# https://sparkbyexamples.com/pandas/conver-pandas-column-to-list/#:~:text=tolist()%20you%20can%20convert,the%20column%20values%20to%20list.

# read the data in using command lines
data = pd.read_csv(sys.argv[1], usecols=['PRED', 'OBS'])

# read in data for predicted vals
# read in data for observed values
predictedValsAll = data['PRED'].values.tolist()
observedValsAll = data['OBS'].values.tolist()

# for the purpose of simplifying the output graph, we will choose a random 6 obs for the graph
predictedValsLimited = []
observedValsLimited = []
for x in range(0,6):
    # random index generation
    index = rand.randint(0, len(predictedValsAll)-1)
    # put random indexes in limited lists
    predictedValsLimited.append(predictedValsAll[index])
    del(predictedValsAll[index])
    observedValsLimited.append(observedValsAll[index])
    del(observedValsAll[index])

# create the x axis for the predicted and observed, have them be offset
predictedX = range(-2, 16, 3)
observedX = range(-1, 17, 3)

# create plot
ax = plt.subplot(111)

# plot the predicted values bars
ax.bar(predictedX, predictedValsLimited, width=1, color='r', align='center')
# plot the observed values bars
ax.bar(observedX, observedValsLimited, width=1, color='g', align='center')

# put labels on plot
plt.gcf().canvas.manager.set_window_title('Predicted vs. Observed Bar Graph')
plt.title('Predicted vs. Observed Values for Plus Minus Explained By Personal Fouls')
plt.ylabel('Plus Minus Score (Predicted in red, Observed in green)')
# save plot to repo
plt.savefig('../PlusMinusAssistModel.png')
plt.show()



