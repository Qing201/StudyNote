```py
import cv2 as cv

image = cv.imread('path')

blur_image = cv.GaussianBlur(img, (a,b), cv.BORDER_DEFAULT)      # Blur the image
cv.imshow('Title', blur_image)

cv.Canny()              # 提取纹路
cv.dilate
cv.erode
cv.resize
```
