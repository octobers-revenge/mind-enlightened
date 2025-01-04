import pandas as pd
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
import numpy as np
import time

start_time = time.time()

data = pd.read_csv('student-mat.csv', delimiter=';')

y = data['G3']
selected_columns = ['G1', 'G2', 'studytime', 'failures', 'absences', 'internet']
X = data[selected_columns]



categorical_columns = ['internet']

#onehot encoding
column_transformer = ColumnTransformer(
    transformers=[
        ('cat', OneHotEncoder(drop='first'), categorical_columns)
    ],
    remainder='passthrough' 
)

X_encoded = column_transformer.fit_transform(X)

X_b = np.c_[np.ones((X_encoded.shape[0], 1)), X_encoded] #adding a column of ones for the intercept
w = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)

feature_names = ['Intercept'] + list(column_transformer.get_feature_names_out())


print("Coefficients:")
for name, coef in zip(feature_names, w):
    print(f"{name}: {coef}")

end_time = time.time()
print(f"time taken: {end_time - start_time} seconds")
y_pred = X_b.dot(w)


mse = np.mean((y - y_pred) ** 2)
print(f"Mean Squared Error: {mse}")


sst = np.sum((y - np.mean(y)) ** 2)  
sse = np.sum((y - y_pred) ** 2)  
r2 = 1 - (sse / sst)
print(f"R² Score: {r2}")