# DeepDrive
The Repository contains all the files and descriptive Jupyter notebooks for my implementation of a Deep Neural Network based Car Prototype.
The ultimate and prime objective of this Project is to create a pool of DeepCars which will learn together and drive autonomously without human intervention.
The Project consists of several phases of operation, given its scale:-


   ### Phase I - (Completed)
     This phase involves building a simple bot based on heuristics that can navigate in any environment without collision. It was based on      Arduino and Ultrasonic Sensors. The basic Obstacle detection and avoiding algorithm makes it possible.
     
   ### Phase II -(Completed)
     This phase is quite identical to phase I except for the fact that all the same is implemented on Raspberry Pi. The interfacing with        Raspberry Pi gave quite a few advantages with the computation power.
     
   ### Phase III -(Completed)
     This phase involved 5 ultrasonic Sensors interfaced with Raspberry Pi. But, the twist was that i used a Multi Layer Perceptron Model        to train the car from the data learnt by manually driving the car using a bluetooth module and simultaneous logging the data to an SD      card. This was a tedious task but it was quite interseting.
     We used Tensorflow as a framework to train the network on Google Colaboratory as we get free K80 GPU. 
     
   ### Phase IV -(Ongoing) 
     This is the current ongoing phase where alongwith the five sensors and a Pi Camera to get realtime visual feed. This has added a new        dimension to my project. Now, we are trying to manually collect a dataset through a small robotic environment like a roadway, for our      bot to learn. Then, the plan is to annotate the images and place it in the VOC PASCAL dataset. The next plan is to add a few conv          layers and a fully connected layer and retrain the network for our purposes.
     This suits our purpose as our model can now easily label our custom objects like traffic sign,road edges and other obstacles. Also, a      parallel script calculates the objects marking the distance of each object that has been observed.
     Now, the second stage of this phase is to collect video data + ultrasonic sensor data + my instructions on a file for the final model      to train. This model's objective is to learn a complex function to maneuver the bot autonomously.
     
     
     
## Important Links and Thanks to resources
1) PASCAL VOC DATASET   :-  http://host.robots.ox.ac.uk/pascal/VOC/voc2012/
2) SINGLE SHOT MULTIBOX DETECTOR  :- https://arxiv.org/abs/1512.02325

     
    
