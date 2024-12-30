import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, confusion_matrix

# Data Preparation Function
def prepare_data(data):
    """
    Prepares data for classification by normalizing features and splitting into train and test sets.

    Parameters:
    data (numpy array): Structured array with feature data and labels.

    Returns:
    X_train, X_test, y_train, y_test (arrays): Split and normalized data for training and testing.
    """
    # Separate features and labels
    X = data[:, :-1]
    y = data[:, -1]
    # Normalize features
    X = (X - X.mean(axis=0)) / X.std(axis=0)
    # Split into train and test sets
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)
    return X_train, X_test, y_train, y_test

# Affinity Calculation Function
def calculate_affinity(vector1, vector2):
    """
    Calculates affinity between two vectors, representing the similarity between an antibody and an antigen.

    Parameters:
    vector1 (numpy array): The first vector.
    vector2 (numpy array): The second vector.

    Returns:
    float: Affinity score (higher means more similar).
    """
    distance = np.linalg.norm(vector1 - vector2)
    return 1 / (1 + distance)

# Antibody Generation Function
def generate_antibodies(num_antibodies, feature_dim):
    """
    Generates a population of antibodies with random feature vectors.

    Parameters:
    num_antibodies (int): Number of antibodies to generate.
    feature_dim (int): Number of features (dimension of each antibody).

    Returns:
    numpy array: Array of generated antibodies.
    """
    return np.random.rand(num_antibodies, feature_dim)

# Cloning and Mutating Antibodies Function
def clone_and_mutate(antibodies, mutation_rate=0.1):
    """
    Clones antibodies and applies mutation to simulate immune adaptation.

    Parameters:
    antibodies (numpy array): Array of antibodies.
    mutation_rate (float): Rate at which mutations occur.

    Returns:
    numpy array: Array of cloned and mutated antibodies.
    """
    clones = antibodies.copy()
    mutation = np.random.randn(*clones.shape) * mutation_rate
    return clones + mutation

# Training Antibodies for Damage Classification
def train_and_classify(X_train, y_train, antibodies, threshold=0.7):
    """
    Trains antibodies and uses them for classification.

    Parameters:
    X_train (numpy array): Training data features.
    y_train (numpy array): Training data labels.
    antibodies (numpy array): Antibody population.
    threshold (float): Affinity threshold for classification.

    Returns:
    list: List of trained antibodies that classify as damaged.
    """
    trained_antibodies = []
    for x, label in zip(X_train, y_train):
        for antibody in antibodies:
            affinity = calculate_affinity(x, antibody)
            if affinity > threshold and label == 1:  # 1 indicates damage
                trained_antibodies.append(antibody)
    return np.array(trained_antibodies)

# Testing the Model
def test_model(X_test, trained_antibodies, threshold=0.7):
    """
    Tests the model by classifying test data based on trained antibodies.

    Parameters:
    X_test (numpy array): Test data features.
    trained_antibodies (numpy array): Trained antibodies for damage.
    threshold (float): Affinity threshold for classification.

    Returns:
    numpy array: Predicted labels for test data.
    """
    predictions = []
    if len(trained_antibodies) == 0:
        print("Warning: No trained antibodies available for testing. All predictions will be set to no damage (0).")
        return np.zeros(len(X_test))  # Default to no damage if no antibodies were trained

    for x in X_test:
        max_affinity = max(calculate_affinity(x, antibody) for antibody in trained_antibodies)
        predictions.append(1 if max_affinity > threshold else 0)
    return np.array(predictions)

# Main Function to Run the Complete Process
def main():
    """
    Executes the training and testing pipeline for structure damage classification
    based on user input data.
    """
    # Get user input for dataset
    num_samples = int(input("Enter the number of samples in the dataset: "))
    num_features = int(input("Enter the number of features (not including the label): "))

    data = []

    print("Enter each sample's feature values followed by the label (0 for no damage, 1 for damage).")

    for i in range(num_samples):
        print(f"\nSample {i+1}:")
        sample = []
        for j in range(num_features):
            feature_value = float(input(f"  Enter feature {j+1}: "))
            sample.append(feature_value)
        label = int(input("  Enter label (0 for no damage, 1 for damage): "))
        sample.append(label)
        data.append(sample)

    # Convert data to numpy array
    data = np.array(data)

    # Prepare data
    X_train, X_test, y_train, y_test = prepare_data(data)

    # Generate initial antibodies
    antibodies = generate_antibodies(num_antibodies=50, feature_dim=X_train.shape[1])

    # Train antibodies for damage classification
    trained_antibodies = train_and_classify(X_train, y_train, antibodies)

    # Test the model
    predictions = test_model(X_test, trained_antibodies)

    # Evaluate performance
    print("\nModel Evaluation:")
    print("Accuracy:", accuracy_score(y_test, predictions))
    print("Confusion Matrix:\n", confusion_matrix(y_test, predictions))

# Run the main function
main()
