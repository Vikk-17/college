"""
Write a Python program using Pandas to read a CSV file containing daily temperature data. Analyze and plot the monthly average temperatures using time series techniques.
Data Columns: Date, Temperature(°C)
Convert the date column to datetime format
Resample the data monthly.
Plot the results using matplotlib.
"""
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = {
    "date": pd.date_range(start="08/04/2025", periods=100, freq="D"),
    "celcius": np.random.randint(low=10, high=40, size=100)
}

df = pd.DataFrame(data=data)
df["date"] = pd.to_datetime(df["date"])
print(df)
df = df.resample(rule="ME", on="date").mean()
print(df)
df.plot(figsize=(10, 5), title='Time Series Data')
plt.show()
