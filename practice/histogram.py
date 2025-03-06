import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import norm

# ---------------------------
# 1. Input Your Data
# ---------------------------
# Provided count data for 50 runs (R values)
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

# Create a DataFrame to display the table
df = pd.DataFrame({
    'Run': np.arange(1, N + 1),
    'R': R,
    'R - Mean': deviation,
    'Normalized (R - Mean)/σ': norm_dev
})

print("Data Table:")
print(df)

# ---------------------------
# 3. Plotting
# ---------------------------
fig, axs = plt.subplots(1, 2, figsize=(14, 6))

# --- Plot 1: Histogram of Normalized Deviations with Normal Curve Overlay ---
ax1 = axs[0]
# Plot histogram for normalized deviations
counts, bins, patches = ax1.hist(norm_dev, bins=10, alpha=0.6, color='green', edgecolor='black')

# Generate x-values for the normal curve
x = np.linspace(min(norm_dev) - 1, max(norm_dev) + 1, 100)
# Compute the standard normal probability density function values
y = norm.pdf(x, 0, 1)
# Scale the normal curve to match the histogram (total count * bin width)
bin_width = bins[1] - bins[0]
y_scaled = y * N * bin_width

# Overlay the normal curve on the histogram
ax1.plot(x, y_scaled, 'r-', linewidth=2)
ax1.set_title('Histogram of Normalized Deviations')
ax1.set_xlabel('Normalized (R - Mean)/σ')
ax1.set_ylabel('Frequency')

# --- Plot 2: Scatter Plot of Raw Counts ---
ax2 = axs[1]
ax2.scatter(np.arange(1, N + 1), R, color='blue')
ax2.plot(np.arange(1, N + 1), R, linestyle='--', color='gray', alpha=0.7)
ax2.set_title('Scatter Plot of Raw Counts (R)')
ax2.set_xlabel('Run Number')
ax2.set_ylabel('Counts (R)')

plt.tight_layout()
plt.show()
