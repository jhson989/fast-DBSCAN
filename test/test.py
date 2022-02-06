import fastDBSCAN
import random
from PIL import Image
import numpy as np


NUM_POINTS = 10000
W, H = 800, 600


def points_to_image(points, name="a.png"):
    data = np.zeros((H, W), dtype=np.uint8)

    for point in points:
        data[round(point[0])][round(point[1])] = 255

    img = Image.fromarray(data)
    img.save(name)

if __name__ == "__main__":

    points = []
    for i in range(NUM_POINTS):
        points.append([random.uniform(0, H-1), random.uniform(0, W-1)])

    points_to_image(points, "example.png")
    points = fastDBSCAN.run(points)
    points_to_image(points, "result.png")
    
