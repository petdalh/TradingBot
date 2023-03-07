import pandas as pd
from alpha_vantage.timeseries import TimeSeries
from datetime import datetime, timedelta

# Define the API key for Alpha Vantage (replace with your own API key)
api_key = 'PPT97RG4TLBXIFY9'

# Define the ticker symbol for the stock you want to download
ticker = 'AAPL'

# Define the time interval for the intraday data
interval = '5min'

# Initialize the Alpha Vantage API client
ts = TimeSeries(key=api_key, output_format='pandas')

# Calculate the start and end dates for the last 24 hours
end_date = datetime.now().strftime('%Y-%m-%d')
start_date = (datetime.now() - timedelta(hours=24)).strftime('%Y-%m-%d')

# Download the intraday data from Alpha Vantage
df, meta_data = ts.get_intraday(symbol=ticker, interval=interval, outputsize='full')

# Filter the intraday data to the last 24 hours
df = df.loc[start_date:end_date]

# Write the intraday data to a text file
with open('data/AAPL.txt', 'w') as file:
    for index, row in df.iterrows():
        file.write('{} {} {} {} {}\n'.format(index, row['1. open'], row['2. high'], row['3. low'], row['4. close'], row['5. volume']))



