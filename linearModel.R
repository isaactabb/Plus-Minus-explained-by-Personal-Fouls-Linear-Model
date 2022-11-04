# LinearModel.R
# The purpose of this file is to run the linear model and create necessary .csv files for main.cpp functionality.
# Note: This file does not print anything from the model.

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

# create new dataframe with just personal fouls
x.new.df <- data.frame(PF = dat$PF)

# create coefs data frame
coefs <- data.frame(coef = mod$coefficients)

# create final data frame with predicted and observed values
full.new.df <- data.frame(PRED = c(predict(mod, x.new.df)), OBS = dat$PM)

# write out all information to csvs, saved in repo
write.csv(full.new.df, file="../gameLogsObsPredic.csv")
write.csv(coefs, file="../modCoefs.csv")
