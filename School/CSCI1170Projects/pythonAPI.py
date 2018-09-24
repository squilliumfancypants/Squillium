from urllib import request, urlopen, URLError


def main():
    
    response=requests.get("http://api.open-notify.org/iss-now.json")
    print(response.status_code)
main()
                          
                          
