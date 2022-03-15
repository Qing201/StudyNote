

## Docker

Shell command note: [link](../../Terminal/Terminal_Note.md)

```bash
docker run -v $PWD/week_1:/source -it klavins/520w20:cpp bash

docker run -v /Users/qingchuanhou/Documents/GitHub/EEP_520-Assigments:/source -it klavins/520w20:cpp bash

docker run -v /Users/qingchuanhou/Documents/GitHub/EEP_520_Winter2022:/source -it klavins/520w20:cpp bash

# Final Project
docker run -p80:80 -p8765:8765 -v /Users/qingchuanhou/Documents/GitHub/EEP_520-Assigments/Final_Project:/source -it klavins/enviro:v1.6 bash
```