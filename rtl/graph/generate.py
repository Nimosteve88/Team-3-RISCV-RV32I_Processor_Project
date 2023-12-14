import pandas as pd
import matplotlib.pyplot as plt
import os

def plot_and_save_graph(csv_file, output_dir="output", title="Graph", x_label="X-axis", y_label="Y-axis"):
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)

    # Read CSV file into a DataFrame
    df = pd.read_csv(csv_file)

    # Assuming the first column is x and the second column is y
    x_data = df.iloc[:, 0]
    y_data = df.iloc[:, 1]
    file_name = os.path.splitext(os.path.basename(csv_file))[0]
    # Plot the graph
    plt.plot(x_data, y_data)
    plt.title(file_name)
    plt.xlabel(x_label)
    plt.ylabel(y_label)

    # Save the graph as an image in the output directory
    file_name = os.path.splitext(os.path.basename(csv_file))[0] + "_graph.png"
    output_path = os.path.join(output_dir, file_name)
    plt.savefig(output_path)

    # Close the current plot to start a new one for the next CSV file
    plt.close()

# Example usage with multiple CSV files
csv_files = ['cache_gaussian.csv', 'cache_noisy.csv', 'cache_sine.csv', 'cache_triangle.csv', 'pipelined_gaussian.csv', 'pipelined_noisy.csv', 'pipelined_sine.csv', 'pipelined_triangle.csv', 'single_gaussian.csv', 'single_noisy.csv', 'single_sine.csv', 'single_triangle.csv']

for csv_file in csv_files:
    plot_and_save_graph(csv_file)