"""
In a team setting, one member has generated a time-series dataset, and another has labeled certain events using regular expressions. Your task is to merge the datasets, identify the event frequency by hour, and visualize it using a bar chart.␍Write code to:
- Merge the datasets on timestamp
- Extract the hour from the timestamp
- Count and plot the number of events per hour
"""
import pandas as pd
from matplotlib import pyplot as plt

time_series_df = pd.read_csv("/content/final_time_series.csv")
labeled_events_df = pd.read_csv("/content/final_labeled_events.csv")


time_series_df["timestamp"] = pd.to_datetime(time_series_df["timestamp"])
labeled_events_df["timestamp"] = pd.to_datetime(labeled_events_df["timestamp"])


# merge the dataset
merged_df = pd.merge(time_series_df, labeled_events_df, on="timestamp", how="inner")
# print(merged_df)

# get the hour form the timestamp
# timestamp_series = merged_df["timestamp"].astype(str).str.split(" ", expand=True)
# hours = timestamp_series[1].str.split(":", expand=True)[0]
# print(f"All the hours are\n\n{hours}")

merged_df["hours"] = merged_df["timestamp"].dt.hour
print(merged_df)

# count
events_per_hour = merged_df["hours"].value_counts().sort_index()
print(events_per_hour)

# plot the number of events per hour
plt.figure(figsize=(10, 5))
events_per_hour.plot(kind='bar', color='mediumseagreen')
plt.title("Event Frequency by Hour")
plt.xlabel("Hour of Day")
plt.ylabel("Number of Events")
plt.xticks(rotation=0)
plt.grid(axis='y')
plt.tight_layout()
plt.show()
