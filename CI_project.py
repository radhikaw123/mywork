#Computational Intelligence project based on
#Code 1:
from google.colab import files
uploaded = files.upload()
#Code 2:
# Step 2: Load the Data
import pandas as pd

# Read CSV file (assuming the column names align with 'label' and 'message' based on typical spam datasets)
file_path = list(uploaded.keys())[0]  # This is 'spam.csv'
data = pd.read_csv(file_path, encoding='latin-1')  # 'latin-1' encoding handles non-UTF-8 characters

# Preview the data structure
print(data.head())

# Clean up data - assuming 'label' and 'message' columns
# Adjust column names if needed after inspecting the file structure
data = data[['v1', 'v2']]
data.columns = ['label', 'message']  # Rename for clarity

# Step 3: Encode the labels ('ham' -> 0, 'spam' -> 1)
data['label'] = data['label'].map({'ham': 0, 'spam': 1})

# Step 4: Split the Data
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(data['message'], data['label'], test_size=0.2, random_state=42)

# Step 5: Vectorize the Text Data
from sklearn.feature_extraction.text import CountVectorizer

vectorizer = CountVectorizer(stop_words='english')
X_train_vect = vectorizer.fit_transform(X_train)
X_test_vect = vectorizer.transform(X_test)

# Step 6: Train the Multinomial Naive Bayes Model
from sklearn.naive_bayes import MultinomialNB

nb_model = MultinomialNB()
nb_model.fit(X_train_vect, y_train)

# Step 7: Evaluate the Model
from sklearn.metrics import accuracy_score, classification_report

y_pred = nb_model.predict(X_test_vect)
print("Accuracy:", accuracy_score(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))

# Step 8: Test with User Input Messages
new_messages = []
print("Enter messages to classify (type 'exit' to finish):")
while True:
    user_input = input("Message: ")
    if user_input.lower() == 'exit':
        break
    new_messages.append(user_input)

# Transform and predict on the user input messages
if new_messages:
    new_messages_vect = vectorizer.transform(new_messages)
    predictions = nb_model.predict(new_messages_vect)
    for message, label in zip(new_messages, predictions):
        print(f"Message: '{message}' -> {'Spam' if label == 1 else 'Ham'}")


