"""
Write a Python script to perform data transformation using Pandas.
- Given a dataset with columns: Name, Salary, Department,
- create a pivot table showing the average salary per department.
- Also, normalize the salary values between 0 and 1 using MinMaxScaler from sklearn.preprocessing.
"""


import pandas as pd
import numpy as np
from sklearn.preprocessing import MinMaxScaler
from faker import Faker
import random


fake = Faker()
departments = ['HR', 'Finance', 'Engineering', 'Marketing', 'Sales', 'IT', 'Customer Support']
data = {
    "name": [fake.name() for _ in range(500)],
    "salary": [round(np.random.uniform(low = 30000, high = 150000), 2) for _ in range(500)],
    "department": [random.choice(departments) for _ in range(500)]
}
df = pd.DataFrame(data=data)

pivot_table = df.pivot_table(values="salary", index="department", aggfunc="mean")
print(pivot_table)

scaler = MinMaxScaler()
df["salary"] = scaler.fit_transform(df[["salary"]])
print(df)
