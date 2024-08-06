import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.metrics import mean_squared_error, r2_score
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


X_train, X_test, y_train, y_test = train_test_split(X_encoded, y, test_size=0.2, random_state = 42)


model = LinearRegression()
model.fit(X_train, y_train)

y_pred = model.predict(X_test)

mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

end_time = time.time()
training_time = end_time - start_time

print(f'Mean Squared Error: {mse}')
print(f'R^2 Score: {r2}')
print(f'Training Time: {training_time} seconds')

sample_data = data.sample(n=5)
sample_X = sample_data[selected_columns]

sample_X_encoded = column_transformer.transform(sample_X)

sample_y_pred = model.predict(sample_X_encoded)

print(f'Sample Data:\n{sample_data}')
print(f'Actual Values:\n{sample_data["G3"].values}')
print(f'Predicted Values:\n{sample_y_pred}')

feature_names = column_transformer.get_feature_names_out()

coefficients = model.coef_
intercept = model.intercept_

print(f'Intercept: {intercept}')
for name, coef in zip(feature_names, coefficients):
    print(f'Feature: {name}, Coefficient: {coef}')
