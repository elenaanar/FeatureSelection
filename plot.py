import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

def load_data(file_path):
    """
    Load the data from a CSV file without a header.
    Assumes the first column is the class label and the rest are features.
    """
    data = pd.read_csv(file_path, header=None, delim_whitespace=True)
    return data

def plot_data(data, feature_indices):
    """
    Plot the data points based on the specified feature indices.
    Colors the points based on class.
    """
    class_column = 0  # Class column is always the first column
    features = data.columns[1:]  # Exclude the class column

    print("Class column:", class_column)
    print("Feature columns:", features)
    print("Feature indices to plot:", feature_indices)

    if len(feature_indices) == 2:
        plt.figure(figsize=(10, 6))
        sns.scatterplot(x=data.iloc[:, feature_indices[0]], 
                        y=data.iloc[:, feature_indices[1]], 
                        hue=data[class_column], 
                        palette={1: 'blue', 2: 'red'},
                        style=data[class_column],
                        markers={1: 'o', 2: 's'})
        plt.xlabel(features[feature_indices[0] - 1])
        plt.ylabel(features[feature_indices[1] - 1])
        plt.title('2D Feature Plot')
        plt.show()

    elif len(feature_indices) == 3:
        fig = plt.figure(figsize=(10, 6))
        ax = fig.add_subplot(111, projection='3d')
        ax.scatter(data.iloc[:, feature_indices[0]], 
                   data.iloc[:, feature_indices[1]], 
                   data.iloc[:, feature_indices[2]], 
                   c=data[class_column].map({1: 'blue', 2: 'red'}))
        ax.set_xlabel(features[feature_indices[0] - 1])
        ax.set_ylabel(features[feature_indices[1] - 1])
        ax.set_zlabel(features[feature_indices[2] - 1])
        plt.title('3D Feature Plot')
        plt.show()

def main():
    data_paths = {
        "1": "data/small-test-dataset.txt",
        "2": "data/large-test-dataset.txt",
        "3": "data/small14.txt",
        "4": "data/large14.txt"
    }

    print("Choose a dataset to plot:")
    print("1. Plot small general dataset")
    print("2. Plot large general dataset")
    print("3. Plot small personal dataset")
    print("4. Plot large personal dataset")

    choice = input("Enter your choice (1-4): ")
    if choice not in data_paths:
        print("Invalid choice.")
        return

    file_path = data_paths[choice]
    data = load_data(file_path)

    # Print data for debugging
    print("Data loaded:")
    print(data.head())

    # Step 2: Ask if the user would like to plot 2 or 3 features
    plot_type = input("Would you like to plot 2 or 3 features? (Enter 2 or 3): ")
    if plot_type not in ['2', '3']:
        print("Invalid input. Please enter 2 or 3.")
        return

    # Step 3: Ask which features to plot
    num_features = int(plot_type)
    feature_indices = []
    for i in range(num_features):
        feature_index = int(input(f"Enter the index of feature {i+1} to plot (1-based index): "))
        feature_indices.append(feature_index)

    # Step 4: Plot the data
    plot_data(data, feature_indices)

if __name__ == "__main__":
    main()
