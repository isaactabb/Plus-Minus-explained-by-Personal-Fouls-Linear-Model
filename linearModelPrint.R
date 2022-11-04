# linearModelPrint.R
# The purpose of this file is to run the linear model and print the necessary information from the model.
# This file is used in main.cpp when the user prompts to run the model.
# Note: This file is different from linearModel.R. It does not write to any .csv files, it only prints model info.

# reads in arguments
args <- commandArgs(trailingOnly = TRUE)

# check that length of args is 1
if (length(args) != 1) {
  print("Invalid number of arguments")
  quit()
}

# read the csv file
dat <- read.csv(args[1])

# create mod of plusminus explained by personal fouls
mod <- lm(PM~PF, data=dat)

# print the model coefficients
print('Model Coefficients')
print(mod)

# print the correlation coefficient
print('Correlation Coefficient for PlusMinus & Personal Fouls')
print(cor(dat$PM, dat$PF))

