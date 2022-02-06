import fastDBSCAN
import random
from PIL import Image
import numpy as np



W, H = 800, 600

def points_to_image(points, name="a.png"):
    data = np.zeros((H, W), dtype=np.uint8)

    for point in points:
        data[round(point[0])][round(point[1])] = 255

    img = Image.fromarray(data)
    img.save(name)

def make_example(points):

    NUM_CENTORS = 100 + random.randint(0, 10)

    num_points = 0
    for i in range(NUM_CENTORS):
        num_point = random.randint(W*H*0.001, W*H*0.01)

        if random.randint(0, 100) < 90:
            xs = np.random.normal(loc=random.uniform(0, W-1), scale=random.randint(W/100, W/20), size=num_point)
            ys = np.random.normal(loc=random.uniform(0, H-1), scale=random.randint(W/100, H/20), size=num_point)
        else:
            xs = np.random.normal(loc=random.uniform(0, W-1), scale=random.randint(W/4, W/2), size=num_point)
            ys = np.random.normal(loc=random.uniform(0, H-1), scale=random.randint(H/4, H/2), size=num_point)

        for x,y in zip(xs, ys):
            if 0<=x and x<W-1 and 0<=y and y<H-1:
                points.append([y, x])
                num_points = num_points + 1

        if num_points > W*H*0.1:
            break





if __name__ == "__main__":

    points = []
    make_example(points)
    
    points_to_image(points, "example.png")
    points = fastDBSCAN.run(points)
    points_to_image(points, "result.png")
    
