import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt

# Input data files are available in the "../input/" directory.

from subprocess import check_output
print(check_output(["ls", "../input"]).decode("utf8"))

# Any results you write to the current directory are saved as output.

df=pd.read_csv('../input/Wine.csv',header=None)
df.head(2)

df.columns = [  'SID'
                 ,'LLC_7'
             	,'LLC_8'
             	,'LLC_10'
             	,'LLC_11'
             	,'LLC_13'
             	,'LLC_17'
             	,'LLC_18'
             	,'LwC_1'
             	,'LwC_2'
             	,'ILC_1'
                ]

df.head(2)

import seaborn as sns
corr = df[df.columns].corr()
sns.heatmap(corr, cmap="YlGnBu", annot = True)

X= df.drop(['SID'], axis=1)

X.head()

Y=df.iloc[:,:1]
Y.head(2)

from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.3, random_state=0)

print(X_train.shape)
print(X_test.shape)

from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import AdaBoostClassifier
models = []

models.append(("Naive Bayes:",GaussianNB()))
models.append(("K-Nearest Neighbour:",KNeighborsClassifier(n_neighbors=3)))
models.append(("AdaBoostClassifier:",AdaBoostClassifier()))

print('Models appended...')

results = []
names = []
for name,model in models:
    kfold = KFold(n_splits=10, random_state=0)
    cv_result = cross_val_score(model,X_train,Y_train.values.ravel(), cv = kfold,scoring = "accuracy")
    names.append(name)
    results.append(cv_result)
for i in range(len(names)):
    print(names[i],results[i].mean()*100)