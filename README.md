# mywork
This repository contains codes of different algorithms based on recursive or iterative methods and codes based on greedy method, dynamic programming
# CI_project
CI_project is the file based on the computational intelligence project
This project uses the Multinomial Naive Bayes algorithm to build a Spam Message Classifier. The classifier determines whether a given message is "Spam" (unwanted) or "Spam" (legitimate).

Steps Involved:
Data Upload and Preprocessing:

The dataset (spam.csv) is uploaded and loaded into a pandas DataFrame.
Unnecessary columns are removed, and the data is cleaned to include only labels (ham/spam) and messages.
Labels are encoded numerically: 0 for "ham" and 1 for "spam."
Splitting the Data:

The dataset is split into training (80%) and testing (20%) sets using train_test_split.
Text Vectorization:

Messages are transformed into numerical features using CountVectorizer, which converts text into a matrix of token counts while ignoring stop words.
Model Training:

A Multinomial Naive Bayes model is trained on the vectorized training data.
Model Evaluation:

The trained model is evaluated on the test set, and metrics like accuracy and a classification report are displayed.
Real-Time Message Classification:

The user can input custom messages to classify as "Spam" or "Ham."
Input messages are vectorized and predicted using the trained model.
Key Features:
A Simple yet effective approach for spam detection.
User-friendly, with support for real-time message classification.
Uses widely adopted libraries like pandas and scikit-learn.
This project demonstrates the application of machine learning in text classification and can serve as a foundational tool for more advanced spam detection systems.

# Clonal Selection algorithm
This uses the Clonal Selection Algorithm (CSA), inspired by the biological immune system, to optimize a mathematical function.
𝑓(𝑥)=𝑎⋅𝑥+𝑏
f(x)=a⋅x+b. The goal is to find the value of x that makes 𝑓(𝑥)
f(x) as close as possible to a user-defined target.
The algorithm evolves a population of candidate solutions (antibodies) through:
Selection: Choosing the best-performing antibodies (solutions).
Cloning: Duplicating the selected antibodies.
Mutation: Slightly modifying clones to explore new solutions.
Replacement: Substituting the worst-performing antibodies with better clones.
The process repeats for a user-defined number of generations, and the solution with the best fitness (minimum error) is returned. This approach demonstrates a computational intelligence  applicable to real-world problems like parameter tuning and resource allocation.
# damage classification
This code implements a structural damage classification system inspired by the biological immune system. It begins with user-input data, where each sample includes feature values and a label (0 for no damage, 1 for damage). The data is normalized and split into training and testing sets. A population of random feature vectors, referred to as antibodies, is generated to act as initial classifiers. The system calculates the affinity between an antibody and a data sample using Euclidean distance, with higher affinity indicating greater similarity. During the training phase, antibodies that exhibit high affinity for samples labeled as damaged (1) are selected and stored as trained antibodies. The testing phase uses these trained antibodies to classify test samples by determining their affinity to each antibody, with predictions based on a defined threshold. If no antibodies are trained, the system defaults to predicting no damage for all test samples.
Finally, the model is evaluated using metrics like accuracy and a confusion matrix, providing insights into its performance. This approach mimics the immune system by evolving antibodies to classify structural damage effectively, allowing users to interactively train and test the model with their custom dataset.

