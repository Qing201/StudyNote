# OpenCV

```py
import cv2 as cv

img = cv.imread('path')

cv.waitKey()            # set key to exit
```

## Edit Image (Basic)

```
cropped = img[:,:]

cv.resize(img)

cv.getRotationMatrix2D()

cv.flip()
```

## Edit Image (Adv)
```py
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)          # Color


blur_image = cv.GaussianBlur(img, (a,b), cv.BORDER_DEFAULT)      # Blur the image
cv.imshow('Title', blur_image)

cv.Canny()              # 提取纹路
cv.dilate
cv.erode()

contours, hierarchies = cv.findContours(img, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)

ret, thresh = cv. threshold (gray, 125, 255, CV.THRESH_BINARY)   
```


