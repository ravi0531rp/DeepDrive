import numpy as np
import cv2
 
def find_marker(image):
    # convert the image to grayscale and blur to detect edges
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (5, 5), 0)
    edged = cv2.Canny(gray, 35, 125)
 
    # find the contours in the edged image
 
    (cnts, _) = cv2.findContours(edged.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    c = max(cnts, key = cv2.contourArea)
 
    return cv2.minAreaRect(c)
 
def distance_to_camera(knownWidth, focalLength, perWidth):
    # compute and return the distance from the image to the camera
    return (knownWidth * focalLength) / perWidth
 
# initialize the known distance from the camera to the object
KNOWN_DISTANCE = 20.0
 
# initialize the known object width, which in this case, the piece of
# paper is 21 cm wide
KNOWN_WIDTH = 21.0
 
# initialize the list of images that we'll be using
#(the first image is the one we know the distance from camera.)
IMAGE_PATHS = ["D1e.jpg", "D-1e.jpg", "D2e.jpg"]
# load the image that contains an object that is KNOWN TO BE from our camera
image = cv2.imread(IMAGE_PATHS[0])
marker = find_marker(image)
print marker[1][0]
focalLength = (marker[1][0] * KNOWN_DISTANCE) / KNOWN_WIDTH
print focalLength
 
# loop over the images
for imagePath in IMAGE_PATHS:
    # compute the distance to the paper from the camera
    image = cv2.imread(imagePath)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    marker = find_marker(image)
    CM = distance_to_camera(KNOWN_WIDTH, focalLength, marker[1][0])
 
    # draw a circle around the image and display it which is also circle
    circles = cv2.HoughCircles(gray, cv2.cv.CV_HOUGH_GRADIENT, 1.2, 100)
    # ensure at least some circles were found
    if circles is not None:
        #convert the (x, y) coordinates and radius of the circles to integers
        circles = np.round(circles[0, :]).astype("int")
 
    # loop over the (x, y) coordinates and radius of the circles
        for (x, y, r) in circles:
            cv2.circle(image, (x, y), r, (0, 0, 0), 5)
 
    cv2.putText(image, "%.2fcm" % CM ,
        (image.shape[1] - 350, image.shape[0] - 15), cv2.FONT_HERSHEY_SIMPLEX,
        2.0, (255,0,0), 3)
    cv2.imshow("image", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
