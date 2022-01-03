import requests

def download(web):
    webdd = requests.get(str(web))
    data = webdd.json()
    return data

web = 'https://randomuser.me/api/?result=1'

d = download(web)

print(d)
