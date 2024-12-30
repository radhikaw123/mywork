# mywork
This repository contains codes of different algorithms based on recursive or iterative methods and codes based on greedy method, dynamic programming
# CI_project
CI_project is the file based on the computational intelligence project
This project uses the Multinomial Naive Bayes algorithm to build a Spam Message Classifier. The classifier determines whether a given message is "Spam" (unwanted) or "Spam" (legitimate).
Steps Involved:
Data Upload and Preprocessing: The dataset (spam.csv) is uploaded and loaded into a pandas DataFrame.
Unnecessary columns are removed, and the data is cleaned to include only labels (ham/spam) and messages.
Labels are encoded numerically: 0 for "ham" and 1 for "spam."
Splitting the Data: The dataset is split into training (80%) and testing (20%) sets using train_test_split.
Text Vectorization: Messages are transformed into numerical features using CountVectorizer, which converts text into a matrix of token counts while ignoring stop words.
Model Training: A Multinomial Naive Bayes model is trained on the vectorized training data.
Model Evaluation: The trained model is evaluated on the test set, and metrics like accuracy and a classification report are displayed.
Real-Time Message Classification: The user can input custom messages to classify as "Spam" or "Ham."
Input messages are vectorized and predicted using the trained model.
Key Features:
A Simple yet effective approach for spam detection.
User-friendly, with support for real-time message classification.
Uses widely adopted libraries like pandas and scikit-learn.
This project demonstrates the application of machine learning in text classification and can serve as a foundational tool for more advanced spam detection systems.

# Clonal Selection algorithm
This project uses the Clonal Selection Algorithm (CSA) to optimize 
f(x)=a⋅x+b, finding 𝑥
x closest to a target value. The algorithm evolves solutions through selection, cloning, mutation, and replacement over multiple generations, returning the best solution with minimal error. It showcases computational intelligence for tasks like parameter tuning and resource allocation.
# damage classification
This code implements a structural damage classification system inspired by the human immune system. Users input features and labels (0 for no damage, 1 for damage), which are normalized and split into training and testing sets. Random vectors, called antibodies, are generated as initial classifiers. During training, the system identifies antibodies with high affinity to damaged samples using Euclidean distance and evolves them by cloning and mutation to improve classification performance. The trained antibodies are then used to classify test samples based on their affinity. Finally, the model's performance is evaluated using accuracy and a confusion matrix, showcasing its ability to detect structural damage effectively.







