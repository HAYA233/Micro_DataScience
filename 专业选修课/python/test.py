import pandas as pd
path = "/Users/shaobaihao/Desktop/Python/titanic_train.csv"
df = pd.read_csv(path, index_col=0, header=0)
print(df)
