# mywork
This repository contains codes of different algorithms based on recursive or iterative methods and codes based on greedy method ,dynamic programming

CI_project is the file based on computational intelligence project
This project uses the Multinomial Naive Bayes algorithm to build a Spam Message Classifier. The classifier determines whether a given message is "Spam" (unwanted) or "Ham" (legitimate).

Steps Involved:
Data Upload and Preprocessing:

The dataset (spam.csv) is uploaded and loaded into a pandas DataFrame.
Unnecessary columns are removed, and the data is cleaned to include only label (ham/spam) and message.
Labels are encoded numerically: 0 for "ham" and 1 for "spam."
Splitting the Data:

The dataset is split into training (80%) and testing (20%) sets using train_test_split.
Text Vectorization:

Messages are transformed into numerical features using CountVectorizer, which converts text into a matrix of token counts, while ignoring stop words.
Model Training:

A Multinomial Naive Bayes model is trained on the vectorized training data.
Model Evaluation:

The trained model is evaluated on the test set, and metrics like accuracy and a classification report are displayed.
Real-Time Message Classification:

The user can input custom messages to classify as "Spam" or "Ham."
Input messages are vectorized and predicted using the trained model.
Key Features:
Simple yet effective approach for spam detection.
User-friendly, with support for real-time message classification.
Uses widely adopted libraries like pandas and scikit-learn.
This project demonstrates the application of machine learning in text classification and can serve as a foundational tool for more advanced spam detection systems.
