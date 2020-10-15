import pandas as pd
import matplotlib.pyplot as plt


file_name = "https://covid.ourworldindata.org/data/ecdc/full_data.csv"
df = pd.read_csv(file_name)
#df = pd.read_csv(file_name, index_col = ["location","date","total_cases"])
df
print(df.describe())
country_req = df.loc[df["location"]=="Vietnam"]
dates = country_req["date"]
country=df.loc[df["location"]=="Vietnam"]
#deaths=country["total_cases"]

fig, ax = plt.subplots()
country.plot(x='date',y='total_cases',  ax=ax)
#ax.legend(["Covid cases"])
plt.yscale('log')
plt.show()