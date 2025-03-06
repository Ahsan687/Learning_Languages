import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import norm
import xlsxwriter

# ---------------------------
# 1. Input Your Data
# ---------------------------
R = np.array([
    402, 520, 518, 489, 507, 507, 479, 513, 477, 449,
    406, 527, 520, 512, 530, 492, 501, 506, 530, 530,
    522, 536, 407, 502, 510, 519, 509, 501, 534, 523,
    508, 561, 500, 517, 514, 542, 575, 489, 477, 524,
    474, 527, 453, 532, 509, 537, 541, 529, 548, 527
])
N = len(R)

# ---------------------------
# 2. Statistical Calculations
# ---------------------------
mean_R = np.mean(R)
std_R = np.std(R, ddof=1)  # Sample standard deviation

# Compute deviations and normalized deviations
deviation = R - mean_R
norm_dev = deviation / std_R

# Create a DataFrame for the data table
df = pd.DataFrame({
    'Run': np.arange(1, N + 1),
    'R': R,
    'R - Mean': deviation,
    'Normalized (R - Mean)/σ': norm_dev
})

# ---------------------------
# 3. Generate and Save Plots as Images
# ---------------------------

# Plot 1: Histogram of Normalized Deviations with Normal Curve Overlay
fig, ax1 = plt.subplots(figsize=(6, 4))
counts, bins, patches = ax1.hist(norm_dev, bins=10, alpha=0.6, color='green', edgecolor='black')
x = np.linspace(min(norm_dev) - 1, max(norm_dev) + 1, 100)
y = norm.pdf(x, 0, 1)
bin_width = bins[1] - bins[0]
y_scaled = y * N * bin_width  # Scale to match histogram
ax1.plot(x, y_scaled, 'r-', linewidth=2)
ax1.set_title('Histogram of Normalized Deviations')
ax1.set_xlabel('Normalized (R - Mean)/σ')
ax1.set_ylabel('Frequency')
plt.tight_layout()
plt.savefig("histogram.png")
plt.close()

# Plot 2: Scatter Plot of Raw Counts
fig, ax2 = plt.subplots(figsize=(6, 4))
ax2.scatter(np.arange(1, N + 1), R, color='blue')
ax2.plot(np.arange(1, N + 1), R, linestyle='--', color='gray', alpha=0.7)
ax2.set_title('Scatter Plot of Raw Counts (R)')
ax2.set_xlabel('Run Number')
ax2.set_ylabel('Counts (R)')
plt.tight_layout()
plt.savefig("scatter.png")
plt.close()

# ---------------------------
# 4. Create Excel File and Insert Data & Charts
# ---------------------------
# Create a new Excel workbook
workbook = xlsxwriter.Workbook('nuclear_counting.xlsx')

# Create a worksheet for the data table
worksheet_data = workbook.add_worksheet("Data")

# Write the header row
headers = list(df.columns)
for col, header in enumerate(headers):
    worksheet_data.write(0, col, header)

# Write the data rows
for row in range(len(df)):
    for col, header in enumerate(headers):
        worksheet_data.write(row + 1, col, df.iloc[row][header])

# Create a worksheet for the charts
worksheet_charts = workbook.add_worksheet("Charts")

# Insert the histogram image
worksheet_charts.insert_image('B2', 'histogram.png')

# Insert the scatter plot image below the histogram
worksheet_charts.insert_image('B20', 'scatter.png')

# Close the workbook to write the file
workbook.close()

print("Excel file 'nuclear_counting.xlsx' has been created with the data and graphs.")
